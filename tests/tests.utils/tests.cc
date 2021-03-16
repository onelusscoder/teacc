
#include <tea++/utils/string_t.h>
#include <tea++/diagnostics/diagnostic.h>


auto main() -> int {
    using tea::diagnostics::rem;
    tea::diagnostics::diagnostic dng{ "utils::string_t" };

//! @todo ---------- Remove rem::push usage into the test execution for messaging. must implement independant diagnostic messaging.
    dng.declare_tests( 
    {
        {
            "string_t::words",
            true,
            []() -> rem::code_t {
                MDebugF("diagnostic"), "in " , "string_t::words ...\n";
                return rem::rejected;
            }
        },
        {
            "string_t::binary",
            true,
            []() -> rem::code_t {
                MDebugF("diagnostic"), "in " , "string_t::binary ...\n";
                return rem::rejected;
            }
        }
        });
    dng.run();
    
    return 0;
}
