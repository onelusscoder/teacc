//
// Created by lsc on 21-01-29.
//


#include <tea++/utils/colors.h>

std::string& operator<<(std::string &s, teacc::color::name c)
{
    std::ostringstream os;
    os <<  "\033[38;5" << static_cast<int>(c) << "m";
    s += os.str();
    return s;
}

