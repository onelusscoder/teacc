

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
    };


}
