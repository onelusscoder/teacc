//
// Created by lsc on 21-01-29.
//


#include <tea++/utils/colors.h>

std::string teacc::color::ansi(teacc::color::name c)
{
    string_t str;
    str = "\033[38;5;%d";
    str << static_cast<uint8_t>(c);
    str += "m";
    
    return str();
}
