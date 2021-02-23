

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

namespace tea::diagnostics{

    class DIAGNOSTICS diagnostic
    {
        std::string _name;

    public:
        diagnostic() = default;
        diagnostic(const std::string& n_) : _name(n_) {}

        virtual ~diagnostic() = default;


    };


    class DIAGNOSTICS test  : public  diagnostic
    {

    public:
        test() = default;
        test(const std::string& name_) : diagnostic(name_) {}

        template<typename T> rem::code_t eq(const T& lhs, const T& rhs)
        {
            if (lhs == rhs) return rem::pass;
            //...
            return rem::fail;
        }
    };


}



