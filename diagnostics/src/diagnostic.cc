#include <tea++/diagnostics/diagnostic.h>



namespace tea::diagnostics
{
    diagnostic& diagnostic::declare_tests(test::collection&& col_)
    {
        _tests = std::move(col_);
        return *this;
    }

    rem::code_t diagnostic::run()
    {
        std::string_view str = "diagnostic";
        rem::new_section(str.data());

        MDebugPF(str), "begin\n-----------------------------------------------------\n";

        MDebugF(str), "diagnostic '",  _name,  "'\nbegin\n-----------------------------------------------------\n";
        for (auto tst : _tests)
        {
            if (tst.selected)
            {
                MDebugF(str), "    test '",  tst.name,  "':\n";
                MDebugF(str), "........" , 
                    rem::code(
                        tst.run()
                    ) , 
                    "\n";
            }
        }
        MDebugF(str), "diagnostic '", _name , "'";
        MDebugF(str), "\n-----------------------------------------------------\ndone\n";

        rem::clear(str, [](std::string_view v, rem& r) {
            std::cout << r();
        });
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