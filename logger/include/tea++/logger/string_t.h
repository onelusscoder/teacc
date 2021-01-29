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
        bool end();
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
    explicit  string_t(std::string d_):_d(std::move(d_)) {};
    explicit string_t(std::string &&d_): _d(std::move(d_)){};
    explicit string_t(const char *d_) : _d(d_) {};
    
    ~string_t() { _d.clear(); }
    
    
    template<typename T> string_t& operator +=(const T& d_)
    {
        std::ostringstream out;
        out.precision(_precision);
        out << d_;
        _d.append(out.str());
        return *this;
    }
    
    
};

}

//#endif //TEACC_STRING_T_H
