#pragma once

#include <tea++/diagnostics/diagnostic.h>

namespace tea
{

    struct test : diagnostics::test
    {
        test(const std::string& name_);
        test() = default;
        ~test() override;

        diagnostics::rem::code_t run() override;

    };

}
