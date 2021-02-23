//
// Created by bretzel on 20-04-17.
//

#include <tea++/utils/string_t.h>


namespace tea::utils
{

    using std::string;

    string string_t::_default_token_separators = "\\%(){}[]`$#@!;,~?^&<>=+-*/:.";

    string  string_t::__nullstr__ = "";

    std::ostream& operator<<(std::ostream& in, const string_t& _s)
    {
        in << _s();
        return in;
    }

    string_t::string_t()
    {
        // _D has been instanciated here as well...
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = _D.cend();
    }

    string_t::string_t(const char* a_str)
    {
        //SOut << __PRETTY_FUNCTION__ << ":[\"" << a_str << "\"]:\n";
        _D = a_str;
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = _D.cend();
    }

    string_t::string_t(std::string&& a_str)
    {
        std::swap(_D, a_str);
        a_str.clear();
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = _D.cend();

    }

    string_t::string_t(const string& a_str)
    {
        //ffnl << a_str << "\n";
        _D = a_str;
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = _D.cend();

    }

    string_t::string_t(const string_t& Str)
    {
        //ffnl << Str._str << "\n";
        _D = Str._D;
        _Cursor = Str._Cursor;
    }

    string_t::string_t(string_t&& Str) noexcept
    {
        //ffnl << Str._str << "\n";
        std::swap(_D, Str._D);
        _Cursor = std::move(Str._Cursor);
    }

    string_t::~string_t()
    {
        //ffnl << _str << "\n";
        _D.clear();
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = _D.cend();

    }



    //string_t& string_t::operator=(const string_t& a_str)
    //{
    //    //ffnl << a_str._str << "\n";
    //    _D = a_str._D;
    //    _ArgPosition = a_str._ArgPosition;
    //    _Precision = a_str._Precision;
    //    return *this;
    //}

    string_t& string_t::operator=(string_t&& a_str) noexcept
    {
        //ffnl << a_str._str << "\n";
        std::swap(_D, a_str._D);
        _arg_position = 0;
        _Cursor = std::move(a_str._Cursor);
        return *this;
    }

    bool string_t::operator==(const string_t& a_str) const
    {

        return _D == a_str._D;

    }

    string_t& string_t::operator=(string&& a_str)
    {
        //ffnl << a_str << "\n";
        swap(_D, a_str);
        _arg_position = 0;
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = --_D.end();

        return *this;
    }

    string_t& string_t::operator<<(char c)
    {
        if (scan_arg() == std::string::npos)
        {
            _D += c;
            return *this;
        }
        return format<char>(c);
    }

    string_t& string_t::operator=(const char* a_str)
    {
        if (a_str)
            _D = a_str;
        else
            _D = "";
        _arg_position = 0;
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = _D.end();

        return *this;
    }

    string_t& string_t::operator<<(const string& a_str)
    {
        //_scan_next_Arg();
        if (scan_arg() == std::string::npos)
        {
            _D += a_str;
            return *this;
        }
        return format<const std::string&>(a_str);
    }

    string_t::list_t string_t::to_stdlist(int argc, char** argv)
    {
        list_t args;
        for (int x = 0; x < argc; x++)
        {
            args.push_back(argv[x]);

        }
        return args;
    }

    string_t& string_t::operator<<(const string_t& a_str)
    {
        //_scan_next_Arg();
        if (scan_arg() == std::string::npos)
        {
            std::ostringstream os;
            os << a_str();
            _D += os.str();
            return *this;
        }
        return format<const std::string&>(a_str());
    }

    string_t& string_t::operator<<(const char* a_str)
    {
        //_scan_next_Arg();
        if (scan_arg() == std::string::npos)
        {
            std::ostringstream os;
            os.precision(_decimal_precision);
            os << a_str;
            _D += os.str();
            return *this;
        }
        return format<const char*>(a_str);
    }

    string_t& string_t::operator+=(const string_t& a_atr)
    {
        _D += a_atr._D;
        return *this;
    }
    string_t& string_t::operator+=(const string& a_atr)
    {
        _D += a_atr;
        return *this;

    }

    string_t& string_t::operator+=(char c)
    {
        _D += c;
        return *this;
    }

    string_t& string_t::operator+(char c)
    {
        _D += c;
        return *this;
    }

    string_t& string_t::operator+(const string_t& a_atr)
    {
        _D += a_atr._D;
        return *this;
    }
    string_t& string_t::operator+(const string& a_atr)
    {
        _D += a_atr;
        return *this;
    }

    string_t& string_t::operator>>(string& _Arg)
    {
        _Arg = _D;
        return *this;
    }

    std::string string_t::make_str(const char* B, const char* E)
    {
        std::string Str;
        const char* C = B;
        if ((!B) || (!E) || (!*B) || (!*E))
            return Str;
        while (C <= E)
            Str += *C++;

        return Str;
    }

    void string_t::clear()
    {
        _D.clear();
        _arg_position = (string::size_type)0;
        _Cursor.B = _Cursor.C = _D.cbegin();
        _Cursor.E = _D.end();

    }

    std::string string_t::datetime(const std::string& str_fmt)
    {
        time_t rawtime;
        struct tm* timeinfo;
        char tmb[180];
        std::time(&rawtime);
        timeinfo = std::localtime(&rawtime);
        std::strftime(tmb, 60, str_fmt.c_str(), timeinfo);
        std::string _s = tmb;
        return tmb;
    }

    string::size_type string_t::scan_arg()
    {
        _arg_position = _D.find('%', 0);
        return _arg_position;
    }

    void string_t::put_arg(const string& aStr)
    {
        if (scan_arg() == std::string::npos)
        {
            _D.append(aStr);
            return;
        }

        format<const string&>(aStr);
    }

    // Ce qui fait royalement chier avec les iterateurs des stl, M'est que depuis L'iterateur, comment on accede � son conteneur ???????
    bool string_t::skip_ws(string::iterator& pos)
    {
        if (_Cursor.C == _Cursor.E)
            return false;

        if (pos == _D.end()) // aucun moyen de savoir si L'it�rateur en est un de notre conteneur "_str" !!
            return false;
        while (isspace(*pos))
            ++pos;
        return true;
    }

    // Ce qui fait royalement chier avec les iterateurs des stl, M'est que depuis L'iterateur, comment on accede � son conteneur ???????
    bool string_t::skip_ws(const char* pos)
    {
        if (!pos)
            return false;
        while (pos && (*pos && isspace(*pos)))
            ++pos;
        return true;
    }

    string string_t::word::operator()()
    {
        string _s;
        if (B == E)
            _s.insert(_s.begin(), B, E + 1);
        else
            _s.insert(_s.begin(), B, E + 1);

        return _s;
    }

    std::string string_t::word::operator*()
    {
        string _s;
        if (B == E)
            _s.insert(_s.begin(), B, E + 1);
        else
            _s.insert(_s.begin(), B, E + 1);
        return _s;
    }

    std::string string_t::word::mark()
    {
        string_t str;
        std::string::const_iterator start = B - position;

        int l = 1;
        std::string::const_iterator cc = B;
        // localiser le debut de la ligne;
        while (*cc && (cc > start) && (*cc != '\n') && (*cc != '\r'))
            --cc;
        // debut de la ligne ou de la source:
        if (cc >= start)
        {
            if ((*cc == '\n') || (*cc == '\r'))
                ++cc;
            while ((cc != SE) && (*cc != '\n') && (*cc != '\r'))
                str += *cc++;
        }
        string_t tstr;

        tstr << str << '\n';
        for (int x = 1; x < C; x++)
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
        string_t str = "(%d,%d)";
        str << L << C;
        return str();
    }

    string::const_iterator string_t::scan_to(string::const_iterator start, char c) const
    {
        string::const_iterator p = start;
        ++p;
        while ((p != _D.end()) && (*p != c))
            ++p;
        return p;
    }

    const char* string_t::scan_to(const char* start, char c) const
    {
        const char* p = start;
        if (!p)
            return nullptr;
        ++p;
        while (p && (*p != c))
            ++p;
        return p;
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
    std::size_t string_t::words(string_t::word::list_t& wcollection, const std::string& a_delimiters, bool keep_as_word) const
    {

        string_t::BCE Crs = string_t::BCE(_D);
        if (_D.empty())
        {
            std::cout << " --> Contents is Empty!";
            return (std::size_t)0;
        }
        Crs.Reset(_D);
        std::string token_separators = a_delimiters.empty() ? string_t::_default_token_separators : a_delimiters;
        if (!Crs.Skip())
        {
            //std::cout << " --> Contents Skip is false? (internal?)...\n";
            return (std::size_t)0;
        }
        word w;
        Crs >> w;

        while (!Crs.End())
        {
            if (!wcollection.empty());
            std::string::const_iterator cc = Crs.C;
            if (token_separators.find(*Crs.C) != string::npos)
            {
                cc = Crs.C;
                if (cc > w.B)
                {
                    --cc;
                    wcollection.push_back({ w.B, cc, Crs.E, w.L, w.C, w.position });

                    Crs >> w;
                    cc = Crs.C;
                }

                // '//' as one token instead of having two consecutive '/'
                if ((*Crs.C == '/') && (*(Crs.C + 1) == '/'))
                    ++Crs;

                if (keep_as_word)
                {
                    wcollection.push_back({ w.B, Crs.C, Crs.E, w.L, w.C, w.position });
                }
                ++Crs;
                //std::cout << "        Iterator eos: " << _Cursor.End() << "\n";
                if (!Crs.End())
                    Crs >> w;
                else
                {
                    return wcollection.size();
                }

            }
            else if ((*Crs.C == '\'') || (*Crs.C == '"'))
            { // Quoted litteral string...
                Crs >> w;
                if (keep_as_word)
                {
                    // Create the three parts of the quoted string: (") + (litteral) + (") ( or ' )
                    // So, we save the Word coords anyway.
                    wcollection.push_back({ w.B, w.B, Crs.E, w.L, w.C, w.position });
                }

                string::const_iterator p = scan_to(w.B + (keep_as_word ? 0 : 1), *Crs.C); // w.B is the starting position, _Cursor.M is the quote delim.
                while (Crs.C < p)
                    ++Crs; // compute white spaces!!!

                if (keep_as_word)
                {
                    // then push the litteral that is inside the quotes.
                    wcollection.push_back({ w.B + 1, p - 1, Crs.E, w.L, w.C, w.position });
                    //++_Cursor; // _Cursor now on the closing quote
                    Crs >> w; // Litteral is done, update w.
                    wcollection.push_back({ w.B, p, Crs.E, w.L, w.C, w.position });
                }
                else
                {
                    // Push the entire quote delims surrounding the litteral as the Word.
                    wcollection.push_back({ w.B, Crs.C, Crs.E, w.L, w.C, w.position });
                }
                if (++Crs)
                    Crs >> w;
                else
                    return wcollection.size();

            }
            else
            {
                cc = Crs.C;
                ++cc;
                if (cc == Crs.E)
                {
                    ++Crs.C;
                    break;
                }
                if (isspace(*cc))
                {
                    if (w.B < cc)
                    {
                        wcollection.push_back({ w.B, cc - 1, Crs.E, w.L, w.C, w.position });
                        ++Crs;
                    }

                    if (Crs.Skip())
                    {
                        Crs >> w;
                        continue;
                    }
                    return wcollection.size();
                }
                if (!Crs.End())
                    ++Crs; // advance offset to the next separator/white space.
            }
        }
        if (Crs.C > w.B)
            wcollection.push_back({ w.B, Crs.C - 1, Crs.E, w.L, w.C, w.position });

        return wcollection.size();
    }


    int string_t::filter(const string_t::list_t& a_exp)
    {
        if (!a_exp.size())
            return 0;
        auto i = a_exp.cbegin();

        // array::front is the Init of the match at the beginning of this string.
        // if ...front() is Empty, then there is no required match at the beginning of this string
        // so proceed to the next substring to find.
        // if the last is not Empty, then match the last substring.
        std::string::size_type pos = 0;
        if (!(*i).empty())
        {
            pos = _D.find((*i));
            if (pos != 0) // no match
                return false;
        }
        else;
        ++i;
        auto end = a_exp.cend();
        --end;
        if (!(*i).empty())
        {
            while (i < end)
            {
                if ((*i).empty())
                {
                    ++i;
                    continue;
                }
                pos = _D.find((*i), pos);
                if (pos != std::string::npos)
                {
                    ++pos;
                    ++i;
                    continue;
                }
                return false;
            }
        }
        if (!(*end).empty())
        {
            std::size_t sz = (*end).size();
            pos = _D.find((*end), pos);
            if (pos != std::string::npos)
            {
                if ((pos + sz) != _D.size())
                    return false;
            }
        }
        return true;
    }

    std::string string_t::SizeF(uint64_t sz)
    {
        float fsize = (float)sz;
        string_t us = "";
        int currentunit = 0;
        string_t units[] = { "B", "kb", "mb", "gb", "tb" };
        int unitssize = sizeof(units) / sizeof(units[0]);

        while (fsize > 1024.0 && currentunit < unitssize - 1)
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
    std::string string_t::extract_surrounded(const std::string& first_lhs, const std::string& first_rhs)
    {
        std::size_t lhs_pos = _D.find(first_lhs);
        if (lhs_pos == std::string::npos)
            return "";
        std::size_t rhs_pos = _D.find(first_rhs);
        if (rhs_pos == std::string::npos)
            return "";

        return _D.substr(lhs_pos, rhs_pos - lhs_pos);
    }

    /*!
     * @brief Try to extract the "template" type from the \c func_desc that normally shall be given by __PRETTY_FUNCTION__ at the call Location.
     *
     * template parameter assumed to be "T" ...for now.
     *
     * @param func_desc
     *
     * @note This function has no control of the proper format and (function) prototype data.
     * @return the resulting type text
     */
    std::string string_t::type_of(string&& func_desc)// , const std::string& _T) -> _T is the class to search.
    {
        string_t text = std::move(func_desc);
        string_t::word::list_t w;

        std::size_t count = text.words(w);
        for (auto s : w)
        {
            std::cout << s();
        }
        std::cout << '\n';
        return "finish to implement, please\n";
    }



    void string_t::process_arg(string_t::lambda_fn_t Fn)
    {
        format_t fmt = { _D };

        std::string::iterator c = _D.begin() + _arg_position;
        std::string::iterator n, beg, l;
        beg = n = c;
        ++c;
        // %[flag] :

        switch (*c)
        {
            case '-':
            case '+':
            case '#':
            case '0':fmt.F = *c++;
                break;
            default:
                //++M;
                break;
        }

        n = c;
        // %[width]:
        while ((n != _D.end()) && isdigit(*n))
            ++n;
        l = n;
        --n;
        if (n >= c)
        {
            int t = 0;
            while (n >= c)
                fmt.W = fmt.W + (*(n--) - static_cast<uint64_t>('0')) * pow(10, t++);
        }
        else
            fmt.W = 0;
        c = l;

        if (*c == '.')
        {
            fmt.R = fmt.P;
            ++c;
            n = c;
            while ((n != _D.end()) && isdigit(*n))
                ++n;
            l = n;
            --n;
            int t = 0;
            fmt.R = 0;
            while (n >= c)
                fmt.R = fmt.R + (*(n--) - static_cast<uint64_t>('0')) * pow(10, t++);
            c = l;
        }
        else
            fmt.R = fmt.P;

        //[.precision]
        n = c;
        //% ([Length]) [specifier]
        switch (*c)
        {
            case 'b':fmt.S = *c++;
                break;
            case 'd': // Decimale ou entier
            case 'i':fmt.S = *c++;
                break;
            case 'x':
            case 'X':fmt.S = *c++;
                break;
            case 'f':
            case 'F':
            case 'g':
            case 'G':fmt.S = *c++;
                break;
            case 's':fmt.S = *c++;
        }

        fmt.delta = c - beg;
        //std::string ff(_D, _ArgPosition, fmt.Delta);
        _D.erase(_arg_position, fmt.delta);
        _D.insert(_arg_position, Fn(fmt));
        _arg_position = 0;
    }

    std::string string_t::format_t::operator()()
    {
        std::ostringstream str;
        str << "\nFlag    :" << F << "\n";
        str << "Width     :" << (int)W << "\n";
        str << "Precision :" << (int)P << "\n";
        str << "delta     :" << (int)delta << "\n";
        str << "spec      :" << (char)S << "\n";
        return str.str();
    }

    string_t::BCE::BCE(const std::string& Str)
    {
        B = C = Str.cbegin();
        E = Str.cend();
    }

    bool string_t::BCE::Skip()
    {
        if (End())
            return false;

        while (isspace(*C))
        {
            switch (*C)
            {
                case 10:
                {
                    if ((++C) >= E)
                        return false;
                    if (*C == 13)
                        ++C;
                    ++L;
                    Col = 1;
                }
                break;
                case 13:
                {
                    if ((++C) >= E)
                        return false;
                    if (*C == 10)
                        ++C;
                    ++L;
                    Col = 1;
                }
                break;
                case '\t':++C;
                    ++Col;
                    break;
                default:++C;
                    ++Col;
                    break;
            }
        }
        return C < E;
    }

    bool string_t::BCE::End()
    {
        return C >= E;
    }

    bool string_t::BCE::operator++()
    {
        if (C >= E)
            return false;
        ++C;
        ++Col;
        if (C >= E)
            return false;
        return Skip();
    }

    bool string_t::BCE::operator++(int)
    {
        if (C >= E)
            return false;
        ++C;
        ++Col;
        if (C >= E)
            return false;
        return Skip();
    }

    string_t::BCE& string_t::BCE::operator>>(string_t::word& w)
    {
        w.B = C;
        w.L = L;
        w.C = Col;
        w.position = I = (uint64_t)(C - B);
        return *this;
    }

}
