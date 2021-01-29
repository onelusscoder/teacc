//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_STRING_T_H
//#define TEACC_STRING_T_H

// Code template modified by oldlonesomecoder.
#pragma once

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>
#include <string>


#include <functional>

namespace teacc
{


class string_t
{
    std::string        _d;
    static std::string _null;
    uint8_t            _precision = 4;
    std::string::size_type  _arg_pos = 0; // Initialize Argument index position...
    static  std::string     _default_separators;
    
    //char* __buff = nullptr;  -- disabled : maybe used to replace std::string _d; Thus, to manage an internal private buffer...
    
   
    // %[flags][width][.precision][Length]specifier
    struct format_t
    {
        uint8_t f = 0; // Flag ( - + . # 0 )
        uint8_t w = 0; // Width ( Length )
        uint8_t r = 0; // Custom flag set if this format requier floating point spec.
        uint8_t p = 6; // Precision (Same as  default).
        uint8_t l = 0; // Length modifier ( L,ll,h,hh )
        std::size_t delta = 0; // format length.
        std::size_t pos = 0; //
        char s = 0; // Effective data t
        //char    _format[20]; // Unused yet.
        const char *c = nullptr;
        
        format_t(std::string &str) : c(str.c_str())
        {}
        std::string operator()() const;
        
    };
    using lambda_fn_t = std::function<std::string(const string_t::format_t&)>;
    
    


public:
    
    using collection    = std::vector<std::string>;
    using iterator      = collection::iterator;
    using citerator     = collection::const_iterator;
    
    struct word
    {
        std::string::const_iterator b;
        std::string::const_iterator e;
        std::string::const_iterator se;
        
        std::string operator()();
        std::string operator*();
        
        using collection = std::vector<string_t::word>;
        using iterator = collection::iterator;
        std::string mark();
        
        int l = 1;
        int c= 1;
        uint64_t pos = 0;
        void operator++();
        void operator++(int);
        
        std::string location();
    };
    
    struct bce
    {
        std::string::const_iterator b;
        std::string::const_iterator c;
        std::string::const_iterator e; /// ...
        
        int line = 1;
        int col = 1;
        uint64_t i = 0;
        
        bce() = default;
        ~bce() = default;
        
        bce(const std::string &str);
        bool skip();
        bool end() const;
        bool operator++();
        bool operator++(int);
        void reset(const std::string &_str)
        {
            c = b = _str.cbegin();
            line = col = 1;
            i = 0;
            e = _str.cend();
        }
        bce &operator>>(string_t::word &w);
        //BCE& operator = (const Word& w);
        
    };
    
    
public:
    
    string_t() = default;
    string_t(const string_t &d_): _d(d_._d) {  }
    string_t(string_t &&d_) noexcept = default;
    
    string_t(std::string &&d_): _d(std::move(d_)){};
    string_t(const char *d_) : _d(d_) {};
    
    ~string_t() { _d.clear(); }
    
    
    template<typename T> string_t& operator +=(const T& d_)
    {
        std::ostringstream out;
        out.precision(_precision);
        out << d_;
        _d.append(out.str());
        return *this;
    }
    
    template<typename T> string_t &operator>>(T &_arg)
    {
        
        if constexpr (std::is_same<T, uint64_t &>::value || std::is_same<T, uint16_t &>::value || std::is_same<T, uint32_t &>::value || std::is_same<T, uint64_t &>::value || std::is_same<T, uint8_t &>::value || std::is_same<T, uint16_t &>::value || std::is_same<T, uint32_t &>::value || std::is_same<T, uint64_t &>::value)
        {
            std::string::size_type pos;
            if(((pos = _d.find("0x")) != std::string::npos) || ((pos = _d.find("0x")) != std::string::npos))
            {
                if(_d[pos] == '0')
                {
                    ++pos;
                    if((_d[pos] == 'x') || (_d[pos] == 'x'))
                    {
                        ++pos;
                        std::istringstream i(_d.c_str() + pos);
                        i >> std::hex >> _arg;
                        return *this;
                    }
                }
            }
        }
        std::istringstream in(_d); //  when string was derived from std::string ... oops!  std::istringstream in(*this);
        in.precision(_precision);
        in >> _arg;
        return *this;
    }

    void clear() { _d.clear(); }
#pragma region implicit_operators
    string_t &operator=(const string_t &) = default;
    string_t &operator=(std::string &&d_)   { _d = std::move(d_); return *this;}
    string_t &operator=(string_t &&) noexcept = default;
    string_t &operator=(const char *d_)     { _d = d_; return *this; }
    
    string_t &operator+=(const string_t &d_){ _d += d_._d; return *this; }
    string_t &operator+=(const std::string &d_) { _d = d_; return *this;}
    string_t &operator+=(char c) { _d += c; return *this; };
    
    std::string operator+(const string_t &d_) { return _d + d_._d; }
    std::string operator+(const std::string &d_) { return _d + d_;};
    std::string operator+(char c) { return _d + c;};
    template<typename T> string_t operator+(const T &d_)
    {
        std::ostringstream os;
        os.precision(_precision);
        os << _d;
        os << d_;
        //string_t s((std::string)os.str());
        return string_t(os.str());
    }
    
    template<typename T> string_t &operator=(const T &_a)
    {
        std::ostringstream os;
        os.precision(_precision);
        os << _a;
        clear();
        _d = os.str();
        return *this;
    }
    
    
    bool operator==(const string_t &d_) const
    { return d_._d == _d; }
    bool operator==(const std::string &d_) const
    { return _d == d_;}
    bool operator==(char d_) const
    { std::string s; s += d_; return _d == s; }
    
    bool empty() const
    { return _d.empty(); }
    operator bool() const
    { return !_d.empty(); }
    operator std::string()
    { return _d; }
    std::string &str()
    { return _d; }
    std::string operator()() const
    { return _d; }
#pragma endregion implicit_operators
   
    // -- on peut maintenant commencer nos routines de manipulations et de traitements....
    static std::size_t argv(string_t::collection& list,int argc, char** argsv);
    std::string::const_iterator scan_to(std::string::const_iterator start, char c) const;
    const char *scan_to(const char *start, char c) const;
//    bool skip_ws(std::string::iterator &pos);
//    static bool skip_ws(const char *pos);
//    string_t &operator>>(std::string &_arg);
//    static std::string make_str(const char *b_, const char *e_);
   
    string_t &operator<<(const string_t &d_);
    string_t &operator<<(const char *d_);
    string_t &operator<<(const std::string &d_);
    string_t &operator<<(char c);
    
    std::string extract_surround(const std::string &first_lhs, const std::string &first_rhs);
       /*!
     * @brief "Stringify" Bytes into binary representation.
     * @tparam T  Argument of type T
     * @param __arg Argument Value.
     * @param padd Padding value (number of padding with 0's to fill the numeric base size in digits)
     * @param f  Number of contiguous bits to group.
     * @return std::string
     */
    template<typename T> static std::string to_binary(T __arg, bool padd = false, int f = 128)
    {
        uint8_t seq;
        int nbytes = sizeof(T);
        
        uint8_t tableau[sizeof(T)];
        memcpy(tableau, (uint8_t *) &__arg, nbytes);
        std::string stream = "";
        int s = 0;
        //bool discard = false;
        for(int x = 1; x <= nbytes; x++)
        {
            seq = tableau[nbytes - x];
            if((x == 1 && !padd && !seq) || (stream.empty() && !padd && !seq))
                continue;
            for(int y = 7; y >= 0; y--)
            { // est-ce que le bit #y est à 1 ?
                if(s >= f)
                {
                    stream += ' ';
                    s = 0;
                }
                ++s;
                uint8_t b = 1 << y;
                if(b & seq)
                    stream += '1';
                else
                    stream += '0';
            }
        }
        /*tableau.Clear();*/
        return stream;
    }
    
    string_t &oct(uint64_t __arg)
    {
        
        std::ostringstream os;
        os << std::oct << __arg;
        if(scan_arg() == std::string::npos)
        {
            _d.append(os.str());
            return *this;
        }
        
        return format<std::string > (os.str());
    }
    
    size_t Length() const
    { return _d.size(); }
    char &operator[](size_t p)
    { return _d[p]; }
    //bool empty() { return _str.Empty(); }
    
    static std::string DefaultSeparators()
    { return string_t::_default_separators; }
    static std::string Separators()
    { return string_t::_default_separators; }
    
    
    std::size_t words(string_t::word::collection &wcollection, const std::string &a_delimiters = "", bool keep_as_word = true) const;
    
    template<typename T> string_t& arg(T _arg)
    {
        if(scan_arg() == std::string::npos)
        {
            std::ostringstream os;
            os << std::oct << _arg;
            _d.append(os.str());
            return *this;
        }
        
        return format<T > (_arg);
    }
    
    
    int filter(const string_t::collection &coll_);
    
    template<typename T> std::string expand(const T &cnt)
    {
        string_t ss;
        
        int x = cnt.size();
        for(auto item : cnt)
        {
            ss << item;
            if(x-- > 1)
                ss << ',';
        }
        return ss();
    }
    
    static std::string upper(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::toupper(c);
        });
        
        return s;
    }
    
    
    const char* c_str() { return _d.c_str(); }
    static std::string lower(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        
        return s;
    }
    
    static std::string size_f(uint64_t sz);

private:
    std::string::size_type scan_arg() {    return _arg_pos = _d.find('%', 0); }
    void put_arg(const std::string &d_);

    template<typename T> string_t& format(const T &_argv)
    {
        format_t fmt = {_d};
        char buf[256];
        std::memset(buf, 0, 200);
        //LFnl << "\n";
    
    
        std::string::iterator c = _d.begin() + _arg_pos;
        std::string::iterator n, beg, l;
        beg = n = c;
        ++c;
        // %[flag] :
    
        switch(*c)
        {
            case '-':
            case '+':
            case '#':
            case '0':fmt.f = *c++;
                break;
            default:
                //++M;
                break;
        }
    
        n = c;
        // %[width]:
        while((n != _d.end()) && isdigit(*n))
            ++n;
        l = n;
        --n;
        if(n >= c)
        {
            int t = 0;
            while(n >= c)
                fmt.w = fmt.w + (*(n--) - static_cast<uint64_t>('0')) * pow(10, t++);
        }
        else
            fmt.w = 0;
        c = l;
    
        if(*c == '.')
        {
            fmt.r = fmt.p;
            ++c;
            n = c;
            while((n != _d.end()) && isdigit(*n))
                ++n;
            l = n;
            --n;
            int t = 0;
            fmt.r = 0;
            while(n >= c)
                fmt.r = fmt.r + (*(n--) - static_cast<uint64_t>('0')) * pow(10, t++);
            c = l;
        }
        else
            fmt.r = fmt.p;
    
        //[.precision]
        n = c;
        //% ([Length]) [specifier]
        
        switch(*c)
        {
            case 'b':
            {
                if constexpr (!std::is_same<T, const std::string &>::value)
                {
                    std::string BinaryStr;
                    bool pad = fmt.f == '0';
                    BinaryStr = string_t::to_binary<T>(_argv, pad, fmt.w <= 128 ? fmt.w : 128); // limit grouping digits to 128 ...
    
                    //std::sprintf(buf, "%s", BinaryStr.c_str());
                    fmt.delta = (c + 1) - beg;
                    _d.erase(_arg_pos, fmt.delta);
                    _d.insert(_arg_pos, BinaryStr.c_str(), BinaryStr.length());
                    _arg_pos = 0;
                    return *this;
                }
                break;
            }
            
            case 'd': // Decimale ou entier
            case 'i':fmt.s = *c++;
                break;
            case 'x':
            case 'X':fmt.s = *c++;
                break;
            case 'f':
            case 'F':
            case 'g':
            case 'G':fmt.s = *c++;
                break;
            case 's':
            case 'c':fmt.s = *c++;
                break;
            default:
                break;
        }
    
        fmt.delta = c - beg;
        std::string ff(_d, _arg_pos, fmt.delta);
    
        // -- Clang-tidy:error: cannot pass object of non-trivial type 'const std::__cxx11::basic_string<char>' through variadic function
        //
        if constexpr (std::is_same<T, const std::string &>::value)
            std::snprintf(buf, 199, ff.c_str(), _argv.c_str());
        else
            std::sprintf(buf, ff.c_str(), _argv);
    
        _d.erase(_arg_pos, fmt.delta);
        _d.insert(_arg_pos, buf, std::strlen(buf));
        _arg_pos = 0;
        return *this;
    }
};


}

//#endif //TEACC_STRING_T_H
