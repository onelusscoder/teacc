
/*!
    License: BSD 2 Light.
    @author &copy; 2021, Serge Lussier (aka bretzel, Bretzelus, oldlonesomecoder, lordvorace), lussier.serge@gmail.com
*/
#pragma once

//#include <tea++/diagnostics/diagnostic.h>
#include <tea++/diagnostics/dll.h>

#include <cstdint>
#include <stack>
#include <map>
#include <string_view>
#include <functional>

namespace tea::diagnostics
{
    class DIAGNOSTICS rem
    {
        REFLECTION_ID

        std::string                 _text;
        std::stack<std::string>     _vdata;

        using stack                 = std::stack<rem>;
        using section_t             = std::map<std::string_view, rem::stack>;

    public:
        using type_t                = uint8_t;
        using code_t                = uint16_t;
    #pragma region datavalue
        static constexpr rem::type_t error        = 1;
        static constexpr rem::type_t fatal        = 2;
        static constexpr rem::type_t warning      = 3;
        static constexpr rem::type_t message      = 4;
        static constexpr rem::type_t information  = 5;
        static constexpr rem::type_t comm         = 6;
        static constexpr rem::type_t debug        = 7;
        // ...

        static constexpr rem::code_t ok           = 0;
        static constexpr rem::code_t success      = 1;
        static constexpr rem::code_t fail         = 2;
        static constexpr rem::code_t accepted     = 3;
        static constexpr rem::code_t rejected     = 4;
        static constexpr rem::code_t pass         = 5;
    #pragma endregion

        rem() = default;
        rem(rem::type_t, rem::code_t, std::string_view prefix);
        rem(const rem&) = default;
        rem(rem&&) noexcept;

        virtual ~rem();


        rem& operator = (rem&&) noexcept = default;
        rem& operator = (const rem&) noexcept = default;

        rem& operator,(rem::code_t c_) { _code = c_; return *this; }
        rem& operator,(const std::string& txt)
        {
            _vdata.push(txt);
            return *this;
        }

        template<typename T> rem& operator,(const T& arg_)
        {
            std::ostringstream input;
            input << arg_;
            _vdata.push(input.str());
            return *this;
        }


        static rem::code_t new_section(const std::string& name);
        static rem& push(std::string_view key, rem::type_t t_, rem::code_t c_, std::string_view prefix="");
        
        static std::string code(int c_);
        static std::string type(int t_);
        static std::size_t clear(std::string_view key, std::function<void(std::string_view, rem&)>);
    private:
        static rem::section_t s_sections;
        rem::type_t _type = 0;
        rem::code_t _code = 0;
    };


}


#define DebugF          tea::diagnostics::rem::push("main",rem::debug, 0,  __FUNCTION__)
#define MDebugF(m)      tea::diagnostics::rem::push((m),   rem::debug, 0,  __FUNCTION__)
#define MessageF        tea::diagnostics::rem::push("main",rem::debug, 0,  __FUNCTION__)
#define MMessageF(m)    tea::diagnostics::rem::push((m),   rem::debug, 0,  __FUNCTION__)
