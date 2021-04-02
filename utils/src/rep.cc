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

    rep& rep::diagnostic(std::string_view header_)
    {
        rep::list_t& list = rep::_sections["main"];
        list.push_back(rep{});
        rep& r = list.back();
        r._type = rep::diagnostic_type;
        r, header_;
        return r;
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
            {"syntax error"},
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
            {"ok"},
            {"noop"}
        };
        return _[c_];
    }

    std::string_view rep::location_data(std::array<std::string_view,3> data_)
    {
        std::string buffer;
        std::vector<std::string_view> table = {"file:","function:","line:"};
        int i = 0;
        for (auto s : data_)
        {
            if (!data_.empty())
            {
                buffer += table[i];
                buffer += data_[i].data();
                buffer += '\n'; //@ todo : insert format-agnostic end of line here.
            }
        }
        std::string_view sv = buffer.c_str();
        return sv;
    }

    rep& rep::operator,(rep::code_t c_)
    {
        _d.push(rep::str(c_));
        return *this;
    }

    rep& rep::operator,(rep::type_t t_)
    {
        _d.push(rep::str(t_));
        return *this;
    }

    void rep::clear(std::function<void(rep&)> f_)
    {
        for (auto m : rep::_sections)
        {
            if (!m.second.empty())
            {
                for (auto r : m.second)
                {
                    if (f_) 
                        f_(r); 
                }
                m.second.clear();
            }
            
        }
        rep::_sections.clear();
    }

    std::string rep::operator()()
    {
    
        std::string str;
        while (!_d.empty())
        {
            str += _d.top();
            _d.pop();
        }
        return str;
    }



}
