#pragma once

#include <tea++/teascript/type_t.h>




namespace teacc::teascript
{
    /*!
        @brief token data informations class type.

        @author &copy; 2021, Serge Lussier (aka oldlonesomecoder; bretzel; bretzelus), lussier.serge@gmail.com.
     */
    struct TEASCRIPT token_t
    {
        // memory types data 
        mnemonic::type m = mnemonic::type::noop;
        type_t::type   t = 0L;
        type_t::type   s = 0L;
        delta::T       d = 0;
        //-----------------------------------------

        using list = std::vector<token_t>; ///< location in memory where token_t stream are put;
        using iterator = token_t::list::iterator; ///< alias.


        //Location Data:
        struct TEASCRIPT  location_t
        {        
            const char* begin = nullptr;
            const char* end   = nullptr;
            int        l      = -1; ///< line number
            int        c      = -1; ///< Column number
            int64_t    i      = -1; ///< Absolute offset from the beginning of the Source Text.
            uint8_t    ln     = -1; ///< Absolute offset index of the end of token.
            std::string operator()();
            std::string text();
            //std::string position();

        }_location;

        //flags:
        struct TEASCRIPT flags_t
        {
            int8_t v : 1; ///< Pre-parsed as a value ArgToken;
            int8_t s : 1; ///< Post parsed as assignable
            int8_t m : 1; ///< Virtual multiplication operator. (...4ac...)
        }   _flags = { 0, 0, 0 };

        static token_t _token_null;

        token_t() = default;
        ~token_t() = default;

        token_t(mnemonic::type code_, type_t::type type_, type_t::type sem_grp_, delta::T delta_, lexem::type lexem_, int8_t value_flag_);
        token_t(mnemonic::type code_, type_t::type type_, type_t::type sem_grp_, delta::T delta_, token_t::location_t location_, token_t::flags_t flags_);
        token_t(const token_t& token_) = default;
        token_t(token_t&& token_) = default;
    
        token_t& operator=(token_t&& token_) noexcept = default;
        token_t& operator=(const token_t& token_) = default;
        token_t operator[](mnemonic::type m_);

        std::string mark();

        explicit operator bool() const
        {
            return _location.begin != nullptr;
        }

        bool operator||(type_t::type sem_) const
        {
            return s || sem_;
        }

        [[nodiscard]] std::string text()
        {
            return _location();

        }

        [[nodiscard]] std::string sem_types();
        [[nodiscard]] std::string type_name();
        [[nodiscard]] std::string details(bool mark_ = false);

        static token_t scan(const char* c_);

        [[nodiscard]] bool is_binary() const
        {
            return s & type_t::binary_t;
        }

        [[nodiscard]] bool is_unary() const
        {
            return s & type_t::unary_t;
        }

        [[nodiscard]] bool is_identifier() const
        {
            return s & type_t::identifier;
        }
        [[nodiscard]] bool IsLeaf() const
        {
            return s & type_t::leaf_t;
        }
        [[nodiscard]] bool is_operator() const
        {
            return s & type_t::operator_t;
        }
        [[nodiscard]] bool isclosing_pair() const
        {
            return s & type_t::close_pair;
        }
        [[nodiscard]] bool is_punctuation() const
        {
            return s & type_t::punctuation;
        }
        [[nodiscard]] bool is_number() const
        {
            return s & type_t::number_t;
        }
        [[nodiscard]] bool is_hex() const
        {
            return s & type_t::hex_t;
        }
        [[nodiscard]] bool is_prefix() const
        {
            return s & type_t::prefix_t;
        }
        [[nodiscard]] bool is_postfix() const
        {
            return s & type_t::postfix_t;
        }
        [[nodiscard]] bool is_instruction() const
        {
            return !(s & (type_t::operator_t | type_t::leaf_t));
        }

    };



}