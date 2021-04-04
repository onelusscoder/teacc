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
        
    }

    rep& rep::debug(std::string_view section_name_)
    {
        rep::list_t& list = rep::_sections[section_name_.data()];
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

    rep& rep::diagnostic(std::string header_)
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
        rep::list_t& list = rep::_sections[section_name_.data()];
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

    std::string rep::location_data(std::array<const char*,3> data_)
    {
        std::string buffer;
        //std::vector<std::string> table = {"file:","function:","line:"};
        int i = 0;
       
        utils::string_t str;
        utils::string_t::word::list_t words;
        if (data_[0])
        {
            str = data_[0];
        #ifdef _WIN32
            auto sz = str.words(words, "\\", true);
        #else
            auto sz = str.words(words, "/", true);
        #endif
            if (sz)
            {
                buffer += "    file:";
                buffer += words.back()();
                buffer += '\n';
            }
        }
        if (data_[1])
        {
            buffer += "function:";
            buffer += data_[1];
            buffer += '\n';
        }
        if (data_[2])
        {
            buffer += "    line:";
            buffer += data_[2];
            buffer += '\n';
        }
        return buffer;
    }


    rep& rep::operator,(rep::code_t c_)
    {
        _d.push_back(rep::str(c_-1));
        return *this;
    }

    rep& rep::operator,(rep::type_t t_)
    {
        _d.push_back(rep::str((rep::type_t)(t_-1)));
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
               // m.second.clear();
            } 
        }
        rep::_sections.clear();
    }

    std::string rep::operator()()
    {
    
        std::string str;
        for(auto s : _d)  str += s;
        _d.clear();
        return str;
    }



}
