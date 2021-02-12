

/*!
    @author &copy; 2021, Serge Lussier (aka bretzel, bretzelus, onelonesomecoder), lussier.serge@gmail.com
    
    @note this file implements the teascript lexical anaylser.

*/

#pragma once
#include <tea++/teascript/lexer/token_t.h>
#include <tea++/diagnostics/diagnostic.h>
#include <tea++/utils/expect.h>


namespace teacc::diagnostic
{
    code constexpr unexpected_token = 14;
    code constexpr expected_token   = 15;
    code constexpr unterminated_litteral = 16;
    code constexpr unexpected_eof   = 17;


}

namespace teacc::teascript
{

class TEASCRIPT lexer
{


    struct TEASCRIPT config_t
    {
        token_t::list* tokens = nullptr;///< stream of tokens; (Hall be one unique instance for all (sub-)lexer instances (translation-units/files/source-texts).
        const char* source = nullptr;   ///< filename or in-memory source text.
        diagnostic::code st = diagnostic::implement;
    }_config;

    struct cursor_t
    {
        const char* b = nullptr; ///> absolute beginning of the source text.
        const char* e = nullptr; ///> absolute end of the soure text.
        const char* c = nullptr;

        bool operator++();
        bool operator++(int);
        [[maybe_unused]] bool skipws();
        bool eof(const char* p = nullptr) const;
        [[nodiscard]] long index() const;
        int        l = -1;
        int        col = -1;
        void sync();
        std::string scantoeol();
        [[nodiscard]] std::string line() const;
        [[nodiscard]] std::string mark() const;
        [[nodiscard]] std::string location() const;
        bool       _f = false; ///< used as "state machine" for math factor notation syntax style
        diagnostic::code scanto(const char* substr_);
        expect<diagnostic::code> scanstring();

        cursor_t() = default;
        explicit cursor_t(const char* source_);
    }_cursor;



    struct num_scanner_t
    {
        const char* b = nullptr;
        const char* e = nullptr;
        const char* c = nullptr;
        const char* eos = nullptr;
        bool real = false;

        bool literal = true; ///< scan literal digits - do not validate hexadecimal...

        enum numbase
        {
            none,
            bin,
            oct,
            dec,
            hex,/* ..., */ //  fuck!!!
        }num = none;

        num_scanner_t() = default;
        num_scanner_t(const char* _c, const char* _eos);

        ~num_scanner_t() = default;

        //bool operator++();
        bool operator++(int);

        explicit operator bool() const;
        type_t::type operator()() const;
    };

public:

    using result = expect<diagnostic::code>;

    lexer() = default;
    lexer(const lexer&) = default;
    lexer(lexer&&)noexcept = default;

    ~lexer() = default;

    lexer::config_t& config() { return _config; }


    lexer::result exec();
    lexer::result  operator()();


    [[maybe_unused]] [[nodiscard]] bool empty() const { return _config.tokens == nullptr || _config.tokens->empty() || _config.source == nullptr; }
    void flush(std::function<void(token_t)> f_);
private:

    lexer::result push(token_t & token_);


#pragma region scanners

    using scannerfn = lexer::result(lexer::*)(token_t&);
    using input = std::pair<type_t::type, lexer::scannerfn>;
    using scantable = std::vector<lexer::input>;
    using scanner = expect<lexer::scannerfn>;
    static lexer::scantable  _scantable;

    scanner get_scanner(token_t& t_);

    lexer::result input_binary_operator(token_t&);
    lexer::result input_default(token_t&);
    lexer::result input_unary_operator(token_t&);
    lexer::result input_punctuation(token_t&);
    lexer::result input_keyword(token_t&);
    lexer::result input_hex(token_t&);
    lexer::result input_text(token_t&);
    lexer::result scan_number(token_t&);
    lexer::result scan_identifier(token_t&);
    lexer::result scan_factor_notation(token_t&);
    lexer::result scan_sign_prefix(token_t&);
    lexer::result scan_prefix(token_t&);
    lexer::result scan_postfix(token_t&);

#pragma endregion scanners

    void insert_multiply(token_t&);

};

}

