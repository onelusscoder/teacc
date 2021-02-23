#include <tea++/diagnostics/rem.h>
#include <array>

namespace tea::diagnostics{

CLASSNAME_IMPL(rem)
rem::section_t rem::s_sections = {
    {"main", std::stack<rem>()}
};


}

namespace tea::diagnostics
{


    rem::rem(rem::type_t t, rem::code_t c, std::string_view prefix)
    {
        _type = t;
        _code = c;
        _vdata.push(prefix.data());
    }

    rem::rem(rem&& r) noexcept
    {
        _code = r._code;
        _type = r._type;
        _vdata = std::move(r._vdata);

    }

    rem::~rem()
    {
        while (!_vdata.empty()) _vdata.pop();
        _text.clear();
    }


    /*!
        @brief create a new section/stack.
    */

    rem::code_t rem::new_section(const std::string& name)
    {
        (void)rem::s_sections[name]; // Créer une instance std::stack par défaut...
        return rem::accepted;
    }


    /*!
        @brief creates and returns a pre-defined rem instance into the named stack/section.
    */
    rem& rem::push(std::string_view key, rem::type_t t_, rem::code_t c_, std::string_view prefix)
    {
        rem::s_sections[key].push({t_, c_,prefix});
        return rem::s_sections[key].top();
    }

    std::string rem::code(int c_)
    {
        std::array<std::string_view, 6> _ =
        {
            "ok",
            "success",
            "fail",
            "accepted",
            "rejected",
            "pass"
        };
        return _[c_].data();
    }

    std::string rem::type(int t_)
    {
        std::array<std::string_view, 7> _ =
        {
            "error",
            "fatal",
            "warning",
            "message",
            "information",
            "comm",
            "debug"
        };
        return _[t_].data(); return std::string();
    }

    std::size_t rem::clear(std::string_view key, std::function<void(std::string_view, rem&)> f)
    {
        std::size_t sz = 0;
        for (auto k : rem::s_sections)
        {
            while(!k.second.empty())
            {
                if (f)
                    f(k.first, k.second.top());
                
                k.second.pop();
            }
        }
        rem::s_sections.clear();
        return std::size_t();
    }

}
