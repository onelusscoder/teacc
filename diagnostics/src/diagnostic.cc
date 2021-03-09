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
        rem::new_section("diagnostic");

        MDebugPF(str), "begin\n-----------------------------------------------------\n";

        std::cout << "diagnostic '" << _name << "'\nbegin\n-----------------------------------------------------\n";
        for (auto tst : _tests)
        {
            if (tst.selected)
            {
                std::cout << "    test '" << tst.name << "':\n";
                std::cout << "........" << rem::code(tst.run()) << "\n";
            }
        }
        std::cout << "diagnostic '" << _name << "'";
        std::cout << "\n-----------------------------------------------------\ndone\n";

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