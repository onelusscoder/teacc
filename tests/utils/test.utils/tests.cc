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
    //rep::diagnostic(SRC_LOCATION), rep::noop;
    DIAGNOSTIC, rep::ok;

    rep::clear([](rep& r) {std::cout << r() << '\n'; });
    return rep::ok;
}
