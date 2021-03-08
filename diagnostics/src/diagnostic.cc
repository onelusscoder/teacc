#include <tea++/diagnostics/diagnostic.h>



namespace tea::diagnostics
{
    rem::code_t diagnostic::run()
    {
        std::cout << "diagnostic '" << _name << "'\nbegin\n-----------------------------------------------------\n";
        for (auto tst : _tests)
        {
            if (tst.second.selected)
            {
                std::cout << "    test '" << tst.second.name << "':\n";
                std::cout << "........" << rem::code(tst.second.run()) << "\n";
            }
        }
        std::cout << "diagnostic '" << _name << "'";
        std::cout << "\n-----------------------------------------------------\ndone\n";

        return rem::done;
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