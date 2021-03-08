#include "tests.h"
#include <tea++/utils/string_t.h>
#include <tea++/diagnostics/diagnostic.h>


auto main() -> int {
    using tea::diagnostics::rem;
    tea::diagnostics::diagnostic dng{ "utils::string_t" };

    dng << {
        "string_t::words",
            true,
            []() -> rem::code_t {
            // ...
            return rem::rejected;
        }
    };
    
    return 0;
}
