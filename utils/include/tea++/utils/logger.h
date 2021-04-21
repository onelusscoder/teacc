#pragma once

#include <tea++/utils/text.h>
#include <tea++/utils/rep.h>
#include <thread>
#include <mutex>
#include <map>

namespace tea
{

    class TEAUTILS logger
    {
        utils::string_t _text; ///< rendered output accumulated text
        rep::type_t     _type = rep::debug_type; ///< default log entry type is debug...
    public:
        logger() = default;
        logger(std::string_view ctx_name);
        ~logger();

        logger& operator << (text::color fg_);
        logger& operator << (const std::string& d_);
    public:
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
    private:
        struct context_t
        {
            using list_t = std::map<std::string, context_t>;
            std::ostream*       file_ptr = nullptr;
            std::string         filename;
            logger::format_t    format = logger::format_t::ansi;
            //...
        };
    public:
        logger& operator << (rep::type_t);
        logger& operator << (rep::code_t);

        template<typename T> logger& operator << (T& d_)
        {
            std::ostringstream os;
            os << d_;
            _text += os.str();
            return *this;
        }

        logger& operator << (logger::object_t);

    private:
        static context_t::list_t  contexts;
        static context_t*         m_current_context;

    };


}


#define Log     tea::logger
#define LogF    tea::logger << tea::logger::object_t::header << tea::logger::object_t::fn
#define LogFn   tea::logger << tea::logger::object_t::header << tea::logger::object_t::ffn
#define LogLFn  tea::logger << tea::logger::object_t::header << tea::logger::object_t::ffn << tea::logger::object_t::line
