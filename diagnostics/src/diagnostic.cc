#include <tea++/diagnostics/diagnostic.h>



namespace tea::diagnostics
{
    rem::code_t diagnostic::run()
    {
        for (auto tst : _tests)
        {
            if (tst.second->_selected)
                tst.second->run();

        }
        return rem::fail;
    }
    test::~test()
    {
        _name.clear();
    }
}