#pragma once


#include <tea++/utils/string_t.h>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string_view>


namespace tea
{
    /*!
        @brief `rep`orting type and code of messages amalgam.

        @author &copy; 2021, Serge Lussier (aka bretzel,bretzelus,lordvorace,oldlonesomecoder), lussier.serge@gmail.com
    */
    class TEAUTILS rep
    {
    public:
        using list_t = std::vector<rep>;
        using section_t = std::unordered_map<std::string_view, rep::list_t>;
        using    type_t = uint8_t;
        using    code_t = uint32_t;

        // -----------------------------------------------------------
        static constexpr type_t error_type   = 1;
        static constexpr type_t warning_type = 2;
        static constexpr type_t fatal_type   = 3;
        static constexpr type_t info_type    = 4;
        static constexpr type_t message_type = 5;
        static constexpr type_t debug_type   = 6;
        //...
        // -----------------------------------------------------------

    private:
        std::stack<std::string> _d;
        rep::code_t     _code = 0;
        rep::type_t     _type = 0;
        static rep::section_t  _sections;
    public:

        rep() = default;
        rep(rep&&) noexcept = default;
        rep(const rep&) = default;
        rep(rep::type_t type_, rep::code_t code_);

        ~rep();

        rep& operator = (rep&&) noexcept = default;
        rep& operator = (const rep&) = default;

        static rep& debug(std::string_view section_name_);
        static rep& debug();

    };

}