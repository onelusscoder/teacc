#include <tea++/utils/rep.h>

namespace tea
{

    rep::section_t  rep::_sections = {
        {"main", rep::list_t()}
    };


    rep::rep(rep::type_t type_, rep::code_t code_):
        _code(code_), _type(type_)
    {
    }


    rep::~rep()
    {
        if (!_d.empty())
        {
            while (!_d.empty()) _d.pop();
        }
    }

    rep& rep::debug(std::string_view section_name_)
    {
        rep::list_t& list = rep::_sections[section_name_];
        list.push_back(rep{});
        rep& r = list.back();
        r._type = rep::debug_type;
        return list.back();
    }

    rep& rep::debug()
    {
        rep::list_t& list = rep::_sections["main"];
        list.push_back({});
        rep& r = list.back();
        r._type = rep::debug_type;
        return list.back();
    }

    rep& rep::error(std::string_view section_name_)
    {
        rep::list_t& list = rep::_sections[section_name_];
        list.push_back(rep{});
        rep& r = list.back();
        r._type = rep::error_type;
        return r;
    }

    rep& rep::error()
    {
        rep::list_t& list = rep::_sections["main"];
        list.push_back({});
        return list.back();
    }


    std::string rep::str(rep::type_t t_)
    {
        std::vector<std::string> _ = {
            {"error"},
            {"warning"},
            {"fatal"},
            {"info"},
            {"message"},
            {"debug"},
            {"syntax"},
            {"diagnostic"},
            {"expected"},
            {"unexpected"},
            {"exception"}
        };
        return _[t_-1];
    }


    std::string rep::str(rep::code_t c_)
    {
        std::vector<std::string> _ = {
            {"passed"   },
            {"failed"   },
            {"success"  },
            {"end of file"},
            {"end of stream"},
            {"ok"}
        };
        return _[c_];
    }



}
