

/*!
    License: BSD 2 Light.
    @author &copy; 2021, Serge Lussier (aka bretzel, Bretzelus, oldlonesomecoder, lordvorace), lussier.serge@gmail.com
*/
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
#include <tea++/diagnostics/rem.h>
#include <cmath>
#include <functional>
#include <memory>
#include <string_view>

namespace tea::diagnostics{

    struct DIAGNOSTICS test
    {

        std::string _name;
        bool _selected = false;
        
   
        test() = default;
        test(const std::string& name_) : _name(name_) {}
        virtual ~test();

        using collection = std::map<std::string_view, test*>;

        template<typename T> static rem::code_t eq(const T& lhs, const T& rhs)
        {
            if (lhs == rhs) return rem::pass;
            //...
            return rem::fail;
        }

        template<typename T> static rem::code_t neq(const T& lhs, const T& rhs)
        {
            if (lhs != rhs) return rem::pass;
            //...
            return rem::fail;
        }

        static rem::code_t not_null(void* v)
        {
            if (v != nullptr) return rem::pass;
            //...
            return rem::fail;
        }


        std::string_view name() { return _name.c_str(); }
        virtual rem::code_t run() = 0;
    };



    class diagnostic;

    class DIAGNOSTICS diagnostic
    {
        std::string _name;
        test::collection _tests;

    public:
        diagnostic() = default;
        diagnostic(const std::string& n_) : _name(n_) {}

        virtual ~diagnostic() = default;
        virtual rem::code_t run();
    };



}



