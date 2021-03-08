#include <tea++/diagnostics/diagnostic.h>



namespace tea::diagnostics
{
    rem::code_t diagnostic::run()
    {
        for (auto tst : _tests)
        {
            if (tst.second.selected)
                tst.second.run();

        }
        return rem::fail;
    }
    test::~test()
    {
        name.clear();
    }
    rem::code_t test::run()
    {
        if (fn)
            return fn();
        return rem::rejected;
    }
}