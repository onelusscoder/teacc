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
        rep::list_t list = rep::_sections[section_name_];


    }
}
