//
// Created by lsc on 21-01-29.
//

#include <tea++/utils/string_t.h>
#include <tea++/utils/expect.h>


namespace teacc
{

std::string string_t::_null;
std::string string_t::_default_separators = "\\%(){}[]`$#@!;,~?^&<>=+-*/:.";


std::size_t string_t::argv(string_t::collection& list, int argc, char **argsv)
{
    for(int c = 0; c<argc; c++)
        list.push_back(argsv[c]);
    return list.size();
}


void string_t::put_arg(const std::string &d_)
{
    if(scan_arg() == std::string::npos)
    {
        _d.append(d_);
        return;
    }
    
    format(d_);
}




string_t &string_t::operator<<(const string_t &d_)
{
    if(scan_arg() == std::string::npos)
    {
        _d += d_;
        return *this;
    }
    return format(d_);
}


string_t &string_t::operator<<(const char *d_)
{
    if(scan_arg() == std::string::npos)
    {
        _d += d_;
        return *this;
    }
    return format(d_);
}


string_t &string_t::operator<<(const std::string &d_)
{
    if(scan_arg() == std::string::npos)
    {
        _d += d_;
        return *this;
    }
    return format(d_);
}

string_t &string_t::operator<<(uint8_t c)
{
    if(scan_arg() == std::string::npos)
    {
        _d += c;
        return *this;
    }
    return format<uint8_t>(c);
}


/*!
    * @brief break/split/tokenize,etc... the content of this string_t into pieces.
    * @param wcollection  OUTPUT reference to the 'Words array' containter, filled by this method.
    * @param a_delimiters Separators in the form of a string of ascii-8 characters.
    * @param keep_as_word if true (or non-zero), the Separators will be put into the list as they appear
    * @return number of "Words/tokens" contained into the wcollection.
    * @notice : After several years of experience and experimentations, I have determined that
    * white-spaces/ctrl or spacing characters are silent and implicit delimiters, in addition to the ones supplied by \c a_delimiters.
    */
std::size_t string_t::words(string_t::word::collection &wcollection, const std::string &a_delimiters, bool keep_as_word) const
{
    auto crs = string_t::bce(_d);
    if(_d.empty())
    {
        std::cout << " --> Contents is Empty!";
        return (std::size_t) 0;
    }
    crs.reset(_d);
    std::string token_separators = a_delimiters.empty() ? string_t::_default_separators : a_delimiters;
    if(!crs.skip())
    {
        //std::cout << " --> Contents Skip is false? (internal?)...\n";
        return (std::size_t) 0;
    }
    word w;
    crs >> w;
    
    while(!crs.end())
    {
        if(!wcollection.empty());
        std::string::const_iterator cc = crs.c;
        if(token_separators.find(*crs.c) != std::string::npos)
        {
            cc = crs.c;
            if(cc > w.b)
            {
                --cc;
                wcollection.push_back({w.b, cc, crs.e, w.l, w.c, w.pos});
            
                crs >> w;
                cc = crs.c;
            }
        
            // '//' as one token instead of having two consecutive '/'
            if((*crs.c == '/') && (*(crs.c + 1) == '/'))
                ++crs;
        
            if(keep_as_word)
            {
                wcollection.push_back({w.b, crs.c, crs.e, w.l, w.c, w.pos});
            }
            ++crs;
            //std::cout << "        iterator eos: " << _cursor.end() << "\n";
            if(!crs.end())
                crs >> w;
            else
            {
                return wcollection.size();
            }
        
        }
        else if((*crs.c == '\'') || (*crs.c == '"'))
        { // Quoted litteral string...
            crs >> w;
            if(keep_as_word)
            {
                // Create the three parts of the quoted string: (") + (litteral) + (") ( or ' )
                // So, we save the Word coords anyway.
                wcollection.push_back({w.b, w.b, crs.e, w.l, w.c, w.pos});
            }
        
            std::string::const_iterator p = scan_to(w.b + (keep_as_word ? 0 : 1), *crs.c); // w.B is the starting position, _Cursor.M is the quote delim.
            while(crs.c < p)
                ++crs; // compute white spaces!!!
        
            if(keep_as_word)
            {
                // then push the litteral that is inside the quotes.
                wcollection.push_back({w.b + 1, p - 1, crs.e, w.l, w.c, w.pos});
                //++_Cursor; // _Cursor now on the closing quote
                crs >> w; // Litteral is done, update w.
                wcollection.push_back({w.b, p, crs.e, w.l, w.c, w.pos});
            }
            else
            {
                // Push the entire quote delims surrounding the litteral as the Word.
                wcollection.push_back({w.b, crs.c, crs.e, w.l, w.c, w.pos});
            }
            if(++crs)
                crs >> w;
            else
                return wcollection.size();
        
        }
        else
        {
            cc = crs.c;
            ++cc;
            if(cc == crs.e)
            {
                ++crs.c;
                break;
            }
            if(isspace(*cc))
            {
                if(w.b < cc)
                {
                    wcollection.push_back({w.b, cc - 1, crs.e, w.l, w.c, w.pos});
                    ++crs;
                }
            
                if(crs.skip())
                {
                    crs >> w;
                    continue;
                }
                return wcollection.size();
            }
            if(!crs.end())
                ++crs; // advance offset to the next separator/white space.
        }
    }
    if(crs.c > w.b)
    {
        wcollection.push_back({w.b, crs.c - 1, crs.e, w.l, w.c, w.pos});
    }
    
    return wcollection.size();
}


int string_t::filter(const string_t::collection &coll_)
{
    if(!coll_.size())
        return 0;
    auto i = coll_.cbegin();
    
    // array::front is the Init of the match at the beginning of this string.
    // if ...front() is Empty, then there is no required match at the beginning of this string
    // so proceed to the next substring to find.
    // if the last is not Empty, then match the last substring.
    std::string::size_type pos = 0;
    if(!(*i).empty())
    {
        pos = _d.find((*i));
        if(pos != 0) // no match
            return false;
    }
    else;
    ++i;
    auto end = coll_.cend();
    --end;
    if(!(*i).empty())
    {
        while(i < end)
        {
            if((*i).empty())
            {
                ++i;
                continue;
            }
            pos = _d.find((*i), pos);
            if(pos != std::string::npos)
            {
                ++pos;
                ++i;
                continue;
            }
            return false;
        }
    }
    if(!(*end).empty())
    {
        std::size_t sz = (*end).size();
        pos = _d.find((*end), pos);
        if(pos != std::string::npos)
        {
            if((pos + sz) != _d.size())
                return false;
        }
    }
    return true;
}


std::string string_t::size_f(uint64_t sz)
{
    float fsize = sz;
    string_t us;
    int currentunit = 0;
    string_t units[] = {"B", "kb", "mb", "gb", "tb"};
    int unitssize = sizeof(units) / sizeof(units[0]);
    
    while(fsize > 1024.0 && currentunit < unitssize - 1)
    {
        fsize /= 1024.0;
        currentunit++;
    }
    
    us = std::fixed;
    us += std::setprecision(2);
    us += fsize;
    us += " ";
    us += units[currentunit];
    
    return us;
}


std::string::const_iterator string_t::scan_to(std::string::const_iterator start, char c) const
{
   std::string::const_iterator p = start;
    ++p;
    while((p != _d.end()) && (*p != c))
        ++p;
    return p;
}


const char *string_t::scan_to(const char *start, char c) const
{
    const char *p = start;
    if(!p)
        return nullptr;
    ++p;
    while(p && (*p != c))
        ++p;
    return p;
}
std::string string_t::extract_surround(const std::string &first_lhs, const std::string &first_rhs)
{
    std::size_t lhs_pos = _d.find(first_lhs);
    if(lhs_pos == std::string::npos)
        return "";
    std::size_t rhs_pos = _d.find(first_rhs);
    if(rhs_pos == std::string::npos)
        return "";
    
    return _d.substr(lhs_pos, rhs_pos - lhs_pos);
}


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
    std::string str;
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
    std::string tstr = str;
    
    tstr  += '\n';
    for(int x = 1; x < c; x++)
        tstr += ' ';
    tstr += '^';
    return tstr;
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


string_t::bce::bce(const std::string &str)
{
    b = c = str.cbegin();
    e = str.cend();
}


bool string_t::bce::skip()
{
   if(end())
        return false;
    
    while(isspace(*c))
    {
        switch(*c)
        {
            case 10:
            {
                if((++c) >= e)
                    return false;
                if(*c == 13)
                    ++c;
                ++line;
                col = 1;
            }
                break;
            case 13:
            {
                if((++c) >= e)
                    return false;
                if(*c == 10)
                    ++c;
                ++line;
                col = 1;
            }
                break;
            
            case '\t':++c;
                ++col;
                break;
                
            default:++c;
                ++col;
                break;
        }
    }
    return c < e;
}


bool string_t::bce::end() const
{
    return c >= e;
}


bool string_t::bce::operator++()
{
    if(c >= e)
        return false;
    ++c;
    ++col;
    if(c >= e)
        return false;
    return skip();
}


bool string_t::bce::operator++(int)
{
    if(c >= e)
        return false;
    ++c;
    ++col;
    if(c >= e)
        return true; // true because col has advanced thus, it was not on eos. Next call to skip() will returns false; (EOF/S)
    return skip();
}


string_t::bce &string_t::bce::operator>>(string_t::word &w)
{
    w.b = c;
    w.l = line;
    w.c = col;
    w.pos = i = (uint64_t) (c - b);

    return *this;
}


}