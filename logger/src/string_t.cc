//
// Created by lsc on 21-01-29.
//

#include <tea++/logger/string_t.h>


namespace teacc
{

std::string string_t::_null;
std::string string_t::_default_separators = "\\%(){}[]`$#@!;,~?^&<>=+-*/:.";

std::string string_t::format_t::operator()() const
{
    std::ostringstream out;
    out << "\nFlag    :" << f << "\n";
    out << "Width     :" << (int) w << "\n";
    out << "Precision :" << (int) p << "\n";
    out << "delta     :" << (int) delta << "\n";
    out << "spec      :" << (char) s << "\n";
    return out.str();
}

std::string string_t::word::operator()()
{
    std::string _s;
    if(b == e)
        _s.insert(_s.begin(), b, e + 1);
    else
        _s.insert(_s.begin(), b, e + 1);
    
    return _s;
}


std::string string_t::word::operator*()
{
    std::string _s;
    if(b == e)
        _s.insert(_s.begin(), b, e + 1);
    else
        _s.insert(_s.begin(), b, e + 1);
    return _s;
}


std::string string_t::word::mark()
{
    string_t str;
    std::string::const_iterator start = b - pos;
    
    int line = 1;
    std::string::const_iterator cc = b;
    // localiser le debut de la ligne;
    while(*cc && (cc > start) && (*cc != '\n') && (*cc != '\r'))
        --cc;
    // debut de la ligne ou de la source:
    if(cc >= start)
    {
        if((*cc == '\n') || (*cc == '\r'))
            ++cc;
        while((cc != se) && (*cc != '\n') && (*cc != '\r'))
            str += *cc++;
    }
    string_t tstr;
    
    tstr << str << '\n';
    for(int x = 1; x < C; x++)
        tstr << ' ';
    tstr << '^';
    return tstr();
}


void string_t::word::operator++()
{

}


void string_t::word::operator++(int)
{

}


std::string string_t::word::location()
{
    return "";
}
}