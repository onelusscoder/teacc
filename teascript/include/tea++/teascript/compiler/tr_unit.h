#pragma once

// Lexer data, api, and auto-include dependencies.

#include <tea++/teascript/lexer/lexer.h>



namespace teacc::teascript
{



class TEASCRIPT tr_unit
{
    struct TEASCRIPT consig_t
    {
        token_t::list* tokens = nullptr;
        const char* source    = nullptr;
        std::ifstream* file   = nullptr;
        struct state_t
        {
            uint8_t complete    : 1;
            uint8_t error       : 1;
            uint8_t wait_sub_tr : 1;
            // ...
        }_state = { 0,0,0 };
    };



};

}
