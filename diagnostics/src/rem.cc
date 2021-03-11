#include <tea++/diagnostics/rem.h>
#include <array>

namespace tea::diagnostics{

CLASSNAME_IMPL(rem)
rem::section_t rem::s_sections = {
    {"main", rem::list_t()}
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


   std::string rem::operator()()
    {
        _text.clear();
        while (!_vdata.empty())
        {
            _text += _vdata.top();
            _vdata.pop();
        }
        return _text;
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
        rem::s_sections[key].push_back({t_, c_,prefix});
        return rem::s_sections[key].back();
    }

    std::string rem::code(int c_)
    {
        std::array<std::string_view, 7> _ =
        {
            "ok",
            "success",
            "fail",
            "accepted",
            "rejected",
            "pass",
            "done"
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


    /*!
        @brief Clears the named stack of remarks.

        @note This version clears the entire stacks collection.
        @author &copy; 2021, Serge Lussier(aka bretzel,bretzelus, lordvorace, oldlonesomecoder, levieuxkroutonkikode), lussier.serge@gmail.com
    */
    std::size_t rem::clear(std::string_view key, std::function<void(std::string_view, rem&)> f)
    {
        std::size_t sz = 0;
        for (auto k : rem::s_sections)
        {
            for(auto item: k.second)
            {
                if (f)
                    f(k.first, item);
            }
            k.second.clear();
        }
        rem::s_sections.clear();
        return std::size_t();
    }

}
