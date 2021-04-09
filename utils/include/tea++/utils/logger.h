#pragma once

#include <tea++/utils/text.h>
#include <tea++/utils/rep.h>
#include <thread>
#include <mutex>

namespace tea
{

    struct TEAUTILS logger
    {
        utils::string_t str; ///< rendered output accumulated text
        rep::type_t type = rep::debug_type; ///< default log entry type is debug...
        logger() = default;
        ~logger();

        logger& operator << (colors fg_);
        logger& operator << (const std::string& d_);


        enum object_t : uint8_t
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
            // ...
            none
        };

        logger& operator << (rep::type_t);
        logger& operator << (rep::code_t);

        template<typename T> logger& operator << (T& d_)
        {
            std::ostringstream os;
            os << d_;
            str += os.str();
            return *this;
        }

        logger& operator << (logger::object_t);
    private:
        /// <summary>
        /// Protect config data in multitrhead:
        /// </summary>
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



