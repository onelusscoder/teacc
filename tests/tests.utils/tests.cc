#include "tests.h"
#include <tea++/utils/string_t.h>

namespace tea 
{
    using diagnostics::rem;

    test::test(const std::string& name_) : diagnostics::test(name_)
    {}

    test::~test()
    {
        ;
    }

    rem::code_t test::run()
    {
        utils::string_t str;
        str << "Salutation, bienvenu dans le tea++ framework!\n";
        str << "Vous êtes en ce moment dans le programme de tests\nde la librairie tea++.diagnostics(.Debug).dll\n";
        str << "C'est tout pour le moment...\n";

        std::cout << name() << ":\n" << str();
        return rem::pass;
    }
}



auto main() -> int {
    
    tea::test test("tea++.utils.string_t:");
    return static_cast<int>(test.run());
}