#include "tests.h"

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
    using tea::rep;
    DIAGNOSTIC;
    rep::debug(), "testing and checking output formats...";
    rep::clear([](rep& r) {
        std::cout << r() << '\n'; 
    });
    return rep::ok;
}
