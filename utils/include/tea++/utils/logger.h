#pragma once

#include <tea++/utils/text.h>
#include <tea++/utils/rep.h>

namespace tea
{

    struct TEAUTILS logger
    {
        std::string str; ///< rendering output cummulated text
        rep::type_t type = rep::debug_type; ///< default log entry type is debug...
        logger() = default;
        ~logger();

        logger& operator << (colors fg_);
        logger& operator << (const std::string& d_);

        template<typename T> logger& operator << (T& d_)
        {
            std::ostringstream os;
            os << d_;
            str += os.str();
            return *this;
        }

    };

}



