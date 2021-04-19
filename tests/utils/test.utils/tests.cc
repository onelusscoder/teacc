#include "tests.h"
#include <tea++/utils/logger.h>

#include <cstdlib>
auto main(int arc, char** argv) -> int
{
    tests test;
    return test.run();
}

tests::tests()
{
}

tests::~tests()
{
}

int tests::run()
{
    rep();
    return 0;
}

tea::rep::code_t tests::rep()
{
    using tea::logger;

    //...
    std::cout << tea::text::ansi(tea::text::color::GreenYellow) << "GreenYellow!\n";
    std::cout << tea::text::ansi(tea::text::color::Aquamarine3) << "Aquamarine3!\n";
    std::cout << tea::text::ansi(tea::text::color::Fuchsia) << "Fuchsia!\n";
    return  tea::rep::ok;

    //using tea::rep;
    //DIAGNOSTIC;
    //rep::debug(), "testing and checking output formats...";
    //rep::clear([](rep& r) {
    //    std::cout << r() << '\n'; 
    //});
    //return rep::ok;
}
