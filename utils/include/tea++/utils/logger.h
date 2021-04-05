#pragma once

#include <tea++/utils/text.h>
#include <tea++/utils/rep.h>
#include <thread>
#include <mutex>

namespace tea
{

    struct TEAUTILS logger
    {
        std::string str; ///< rendering output accumulated text
        rep::type_t type = rep::debug_type; ///< default log entry type is debug...
        logger() = default;
        ~logger();

        logger& operator << (colors fg_);
        logger& operator << (const std::string& d_);


        enum class object_t : uint8_t
        {
            begin,
            header,
            code,
            timestamp,
            eol,
            end
        };

        enum class format_t : uint8_t 
        {
            ansi,
            html,
            none
        };

        template<typename T> logger& operator << (T& d_)
        {
            std::ostringstream os;
            os << d_;
            str += os.str();
            return *this;
        }

        logger& operator << (logger::object_t);
    private:
        struct th_context_t
        {
            logger::format_t    format  = logger::format_t::ansi;
            std::string         file_name;
            std::ofstream*      out_ptr = nullptr;
            std::thread::id     th_id;
            std::mutex          mtx;

            rep::code_t clear();

            //...

        };
    };


}



