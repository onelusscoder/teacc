#include "tests.h"


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
    
    return 0;
}

tea::rep::code_t tests::rep()
{
    using tea::rep;
    rep::debug(), rep::noop;

    rep::clear();
    return rep::ok;
}
