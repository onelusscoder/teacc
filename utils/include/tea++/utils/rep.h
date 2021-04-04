#pragma once


#include <tea++/utils/string_t.h>
#include <stack>
#include <vector>
#include <unordered_map>
#include <array>
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
        using section_t = std::unordered_map<std::string, rep::list_t>;
        using    type_t = uint8_t;
        using    code_t = uint32_t;

        // -----------------------------------------------------------
        static constexpr type_t error_type      = 1;
        static constexpr type_t warning_type    = 2;
        static constexpr type_t fatal_type      = 3;
        static constexpr type_t info_type       = 4;
        static constexpr type_t message_type    = 5;
        static constexpr type_t debug_type      = 6;
        static constexpr type_t syntax_type     = 7;
        static constexpr type_t diagnostic_type = 8;
        static constexpr type_t expected_type   = 9;
        static constexpr type_t unexpected_type = 10;
        static constexpr type_t exception_type  = 11;
 
        //...
        // -----------------------------------------------------------
        static constexpr code_t passed = 1;
        static constexpr code_t failed = 2;
        static constexpr code_t success= 3;
        static constexpr code_t e_o_f  = 4;  ///< (un|expected) end of file
        static constexpr code_t e_o_s  = 5;  ///< (un|expected) end of {string|stream|statement|sentence}
        static constexpr code_t ok     = 6;
        static constexpr code_t noop   = 7;

        //...
        // -----------------------------------------------------------

    private:
        std::vector<std::string> _d;
        rep::code_t             _code = 0;
        rep::type_t             _type = 0;
        static rep::section_t   _sections;
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

        static rep& diagnostic(std::string header_);

        static rep& error(std::string_view section_name_);
        static rep& error();

        static std::string str(rep::type_t);
        static std::string str(rep::code_t);

        static std::string location_data(std::array<const char*,3> header_);
        rep& operator,(rep::code_t);
        rep& operator,(rep::type_t);

        template<typename T> rep& operator,(const T& v)
        {
            std::ostringstream os;
            os << v;
            _d.push_back(os.str());
            return *this;
        }

        static void clear(std::function<void(rep&)> f_ = nullptr);

        std::string operator()();
    };

}



#define SRC_LOCATION tea::rep::location_data({__FILE__, __FUNCTION__, (tea::utils::string_t() << __LINE__).c_str()})
#define DIAGNOSTIC tea::rep::diagnostic(SRC_LOCATION)

