

/*!
    License: BSD 2 Light.
    @author &copy; 2021, Serge Lussier (aka bretzel, Bretzelus, oldlonesomecoder, lordvorace), lussier.serge@gmail.com
*/
#pragma once

#include <tea++/diagnostics/dll.h>


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
#include <memory>

namespace tea::diagnostics{

    class DIAGNOSTICS diagnostic
    {
        std::string _name;

    };


    template<typename T> class test  : public  diagnostic
    {
        std::shared_ptr<T> _obj = nullptr;

    public:
        test() = default;
        test(const std::string& name_) : diagnostic(name_) {}

    };


}



