
#include <tea++/utils/string_t.h>
#include <tea++/diagnostics/diagnostic.h>


auto main() -> int {
    using tea::diagnostics::rem;
    tea::diagnostics::diagnostic dng{ "utils::string_t" };


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
    }).run();
    
    return 0;
}
