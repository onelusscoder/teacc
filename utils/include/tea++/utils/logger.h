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

        logger& operator << (text::color fg_);
        logger& operator << (const std::string& d_);


        enum object_t : uint8_t
        {
            begin,
            fn,
            ffn,
            line,
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

        struct header_data
        {
            std::string title;
            std::string time_text;
            std::string function_data;
            //...
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
 
    };


}


#define Log     tea::logger
#define LogF    tea::logger << tea::logger::object_t::header << tea::logger::object_t::fn
#define LogFn   tea::logger << tea::logger::object_t::header << tea::logger::object_t::ffn
#define LogLFn  tea::logger << tea::logger::object_t::header << tea::logger::object_t::ffn << tea::logger::object_t::line
