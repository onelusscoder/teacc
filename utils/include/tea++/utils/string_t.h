#pragma once


#include <tea++/utils/dll.h>

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
#include <functional>


namespace tea::utils
{
    class TEAUTILS string_t
    {
        static std::string __nullstr__;
        std::string _D;///< Private/Encapsulated std::string instance.
        std::string::size_type _arg_position = 0; // Initialize Argument index position...
        static std::string _default_token_separators;
        uint8_t _decimal_precision = 4;
        //char* __buff = nullptr;
    private:
        // %[flags][width][.precision][Length]specifier
        struct TEAUTILS format_t
        {
            uint8_t F = 0; // Flag ( - + . # 0 )
            uint8_t W = 0; // Width ( Length )
            uint8_t R = 0; // Custom flag set if this format requier floating point spec.
            uint8_t P = 6; // Precision (Same as  default).
            uint8_t L = 0; // Length modifier ( L,ll,h,hh )
            std::size_t delta = 0; // Format Length.
            std::size_t position = 0; //
            char S = 0; // Effective data t
            //char    _format[20]; // Unused yet.
            const char* C = nullptr;

            format_t(std::string& Str) : C(Str.c_str())
            {}
            std::string operator()();

        };
        using lambda_fn_t = std::function<std::string(const string_t::format_t& Fmt)>;
    public:

        using list_t = std::vector<std::string>;
        using Iterator = list_t::iterator;
        using CIterator = list_t::const_iterator;

    public:
        struct TEAUTILS word
        {
            std::string::const_iterator B;
            std::string::const_iterator E;
            std::string::const_iterator SE;

            std::string operator()();
            std::string operator*();

            using list_t = std::vector<string_t::word>;
            using iterator_t = list_t::iterator;
            std::string mark();

            int L = 1;
            int C = 1;
            uint64_t position = 0;
            void operator++();
            void operator++(int);

            std::string location();
        };

    private:
        struct TEAUTILS BCE
        {
            std::string::const_iterator B;
            std::string::const_iterator C;
            std::string::const_iterator E; /// ...

            int L = 1;
            int Col = 1;
            uint64_t I = 0;

            BCE() = default;
            ~BCE() = default;

            BCE(const std::string& Str);
            bool Skip();
            bool End();
            bool operator++();
            bool operator++(int);
            void Reset(const std::string& _str)
            {
                C = B = _str.cbegin();
                L = Col = 1;
                I = 0;
                E = _str.cend();
            }
            BCE& operator>>(string_t::word& w);
            //BCE& operator = (const Word& w);

        } _Cursor;

    public:

        string_t();
        string_t(const string_t& Str);
        string_t(string_t&& Str) noexcept;
        string_t(const std::string& aStr);
        string_t(std::string&& aStr);
        string_t(const char* aStr);

        ~string_t();

        string_t& operator=(const string_t&) = default;

        string_t& operator=(std::string && aStr);
        string_t& operator=(string_t && aStr) noexcept;
        string_t& operator=(const char* aStr);

        string_t& operator+=(const string_t & aStr);
        string_t& operator+=(const std::string & aStr);
        string_t& operator+=(char c);

        string_t& operator+(const string_t & aStr);
        string_t& operator+(const std::string & aStr);
        string_t& operator+(char c);

        template<typename T> string_t& operator+=(const T & a)
        {
            std::ostringstream os;
            os.precision(_decimal_precision);
            os << a;
            _D.append(os.str());
            return *this;
        }

        template<typename T> string_t& operator+(const T & a)
        {
            std::ostringstream os;
            os.precision(_decimal_precision);
            os << a;
            _D.append(os.str());
            return *this;
        }

        bool operator==(const string_t & aStr) const;

        bool empty() const
        {
            return _D.empty();
        }
        operator bool() const
        {
            return !_D.empty();
        }
        operator std::string()
        {
            return _D;
        }
        std::string& str()
        {
            return _D;
        }
        std::string operator()() const
        {
            return _D;
        }

        // -- on peut maintenant commencer nos routines de manipulations et de traitements....
        static string_t::list_t to_stdlist(int argc, char** argv);
        string_t& operator<<(const string_t & aStr);
        string_t& operator<<(const char* aStr);
        string_t& operator<<(const std::string & aStr);
        string_t& operator<<(char c);

        bool skip_ws(std::string::iterator & pos);
        static bool skip_ws(const char* pos);
        string_t& operator>>(std::string & _arg);
        static std::string make_str(const char* B, const char* E);
        template<typename T> string_t& operator>>(T & _arg)
        {

 /*           if constexpr (std::is_same<T, uint64_t&>::value || std::is_same<T, uint16_t&>::value || std::is_same<T, uint32_t&>::value || std::is_same<T, uint64_t&>::value || std::is_same<T, uint8_t&>::value || std::is_same<T, uint16_t&>::value || std::is_same<T, uint32_t&>::value || std::is_same<T, uint64_t&>::value)
            {
                std::string::size_type pos;
                if (((pos = _D.find("0x")) != std::string::npos) || ((pos = _D.find("0X")) != std::string::npos))
                {
                    pos += 2;
                    std::istringstream i(_D.c_str() + pos);
                    i >> std::hex >> _arg;
                    return *this;                    
                }
            }*/
            std::istringstream in(_D); //  When string_t was derived from std::string ... Oops!  std::istringstream in(*this);
            if constexpr (
                std::is_same<float,T>::value || std::is_same<double, T>::value || std::is_same<long double, T>::value ||
                std::is_same<int, T>::value || std::is_same<unsigned int, T>::value ||
                std::is_same<int8_t, T>::value || std::is_same<uint8_t, T>::value ||
                std::is_same<int16_t, T>::value || std::is_same<uint16_t, T>::value ||
                std::is_same<int32_t, T>::value || std::is_same<uint32_t, T>::value ||
                std::is_same<int64_t, T>::value || std::is_same<uint64_t, T>::value
                )
            {
                in.precision(_decimal_precision);
                _arg = 0;
            }
            T R;
            in >> R;
            _arg = R;
            return *this;
        }

        char* duplicate()
        {
            return strdup(_D.c_str());
        }


        const char* c_str()
        {
            return _D.c_str();
        }


        void clear();

        //virtual const std::string& tea_id() { return "string_t";}

        static std::string datetime(const std::string & str_fmt);

        template<typename t> string_t& operator=(const t & _a)
        {
            std::ostringstream os;
            os.precision(_decimal_precision);
            os << _a;
            clear();
            _D = os.str();
            return *this;
        }
        std::string extract_surrounded(const std::string & first_lhs, const std::string & first_rhs);
        std::string::const_iterator scan_to(std::string::const_iterator start, char c) const;
        const char* scan_to(const char* start, char c) const;

        //bool test();
        string_t& octal(uint64_t __arg)
        {

            std::ostringstream os;
            os << std::oct << __arg;
            if (scan_arg() == std::string::npos)
            {
                _D.append(os.str());
                return *this;
            }

            return format<std::string >(os.str());
        }

        size_t length() const
        {
            return _D.size();
        }
        char& operator[](size_t p)
        {
            return _D[p];
        }
        //bool empty() { return _str.Empty(); }

        static std::string default_token_separators()
        {
            return string_t::_default_token_separators;
        }
        static std::string token_separators()
        {
            return string_t::_default_token_separators;
        }
        std::size_t words(string_t::word::list_t & wcollection, const std::string & a_delimiters = "", bool keep_as_word = true) const;

        template<typename T> string_t& arg(T _arg)
        {
            if (scan_arg() == std::string::npos)
            {
                std::ostringstream os;
                os << std::oct << _arg;
                _D.append(os.str());
                return *this;
            }

            return format<T >(_arg);
        }
        int filter(const string_t::list_t & a_exp);

        template<typename T> std::string expand(const T & cnt)
        {
            string_t ss;

            int x = cnt.size();
            for (auto item : cnt)
            {
                ss << item;
                if (x-- > 1)
                    ss << ',';
            }
            return ss();
        }

        static std::string upper_case(std::string s)
        {
            std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
                return std::toupper(c);
            });

            return s;
        }
        static std::string lower_case(std::string s)
        {
            std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
                return std::tolower(c);
            });

            return s;
        }

        static std::string SizeF(uint64_t sz);

        template<typename T> string_t& format(const T & _argv);

        template<typename T> string_t& operator<<(const T & Argument)
        {
            if (scan_arg() == std::string::npos)
            {
                std::ostringstream os;
                os << Argument;
                _D += os.str();
                return *this;
            }

            process_arg([Argument](const string_t::format_t& Fmt) -> std::string {
                if (Fmt.S == 'b')
                {
                    bool pad = Fmt.F == '0';
                    ///@todo Still have to resolve T here...
                    if constexpr (
                        (!std::is_same<T, const std::string&>::value) && (!std::is_same<T, const char*>::value)
                        )
                        return string_t::to_binary<T>(Argument, pad, Fmt.W <= 128 ? Fmt.W : 128);
                }
                if constexpr (
                    (std::is_same<T, const std::string&>::value) || (std::is_same<T, const char*>::value)
                    )
                    return Argument;

                std::ostringstream os;
                os << Argument;
                return os.str();
            });
            return *this;
        }

        template<typename T> string_t& hexadecimal(T & v)
        {
            std::stringstream is(_D.c_str() + 2);
            //std::cerr << " this:'" << _D.c_str()+2 << "' -> ";
            is >> std::hex >> v;
            //std::cerr << v << '\n';
            return *this;
        }

        static std::string type_of(std::string && func_desc);


        /*!
         * @brief "Stringify Bytes into binary representation.
         * @tparam T  Argument of type T
         * @param __arg Argument Value.
         * @param padd Apdding value (number of padding 0's to fille the numberic base size in digits)
         * @param f  Number of contiguous bits to group.
         * @return std::string
         */
        template<typename T> static std::string to_binary(T __arg, bool padd = false, int f = 128)
        {
            uint8_t seq;
            int nbytes = sizeof(T);

            uint8_t tableau[sizeof(T)];
            memcpy(tableau, (uint8_t*)&__arg, nbytes);
            std::string stream = "";
            int s = 0;
            //bool discard = false;
            for (int x = 1; x <= nbytes; x++)
            {
                seq = tableau[nbytes - x];
                if ((x == 1 && !padd && !seq) || (stream.empty() && !padd && !seq))
                    continue;
                for (int y = 7; y >= 0; y--)
                { // est-ce que le bit #y est à 1 ?
                    if (s >= f)
                    {
                        stream += ' ';
                        s = 0;
                    }
                    ++s;
                    uint8_t b = 1 << y;
                    if (b & seq)
                        stream += '1';
                    else
                        stream += '0';
                }
            }
            /*tableau.Clear();*/
            return stream;
        }

        std::string::const_iterator begin() { return _D.begin(); }
        std::string::const_iterator end() { return _D.end(); }

    private:
        std::string::size_type scan_arg();
        void process_arg(string_t::lambda_fn_t Fn);

        void put_arg(const std::string & aStr);
        int push_word(word::list_t & strm, word & w, std::string::size_type sz);

    };

    template<typename T> string_t& string_t::format(const T& _argv)
    {
        format_t fmt = { _D };
        char buf[256];
        std::memset(buf, 0, 200);
        //LFnl << "\n";


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
            case 'b':
            {
                if constexpr (!std::is_same<T, const std::string&>::value)
                {
                    std::string BinaryStr;
                    bool pad = fmt.F == '0';
                    BinaryStr = string_t::to_binary<T>(_argv, pad, fmt.W <= 128 ? fmt.W : 128); // Limit grouping digits to 128 ...

                    //std::sprintf(buf, "%s", BinaryStr.c_str());
                    fmt.delta = (c + 1) - beg;
                    _D.erase(_arg_position, fmt.delta);
                    _D.insert(_arg_position, BinaryStr.c_str(), BinaryStr.length());
                    _arg_position = 0;
                    return *this;
                }
                break;
            }

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
            case 's':
            case 'c':fmt.S = *c++;
                break;
            default:
                break;
        }

        fmt.delta = c - beg;
        std::string ff(_D, _arg_position, fmt.delta);

        // -- Clang-tidy:error: cannot pass object of non-trivial type 'const std::__cxx11::basic_string<char>' through variadic function
        //
        if constexpr (std::is_same<T, const std::string&>::value)
            std::snprintf(buf, 199, ff.c_str(), _argv.c_str());
        else
            std::sprintf(buf, ff.c_str(), _argv);

        _D.erase(_arg_position, fmt.delta);
        _D.insert(_arg_position, buf, std::strlen(buf));
        _arg_position = 0;
        return *this;
    };

}



