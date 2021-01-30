//
// Created by lsc on 21-01-29.
//

#include <tea++/diagnostics/application.h>

namespace teacc::diagnostics
{


application::application(int argc, char** argv)
{
    string_t::collection args;
    string_t::argv(args, argc, argv);
    
}
application::status application::run()
{
    diagnostic::object::vlist l;
    diagnostic::object::push(l) | "testing object::push and clear";
    
    diagnostic::object::clear(l, [](diagnostic::object& o) -> void {
        std::cout << ">" << o.text.c_str() << '\n';
    });
    
    
    std::cout << debuglfn.text() << '\n';
    
    return diagnostic::implement;
}

}
