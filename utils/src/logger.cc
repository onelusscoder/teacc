#include <tea++/utils/logger.h>

namespace tea
{



    logger::context_t::list_t logger::contexts = {
        {"main", {nullptr,"",logger::format_t::ansi}}
    };

    logger::logger(std::string_view ctx_name)
    {

    }
    logger::~logger()
    {
        _text.clear();
    }

    /// <summary>
    /// @todo hold text format config...
    /// </summary>
    /// <param name="fg_"></param>
    /// <returns>self instance reference</returns>
    logger& logger::operator<<(text::color fg_)
    {
        
        _text += text::ansi(fg_);
        return *this;
    }

    logger& logger::operator<<(const std::string& d_)
    {
        _text += d_;
        return *this;
    }

    logger& logger::operator<<(rep::type_t t_)
    {
        _text += rep::str(t_);
        return *this;
    }

    logger& logger::operator<<(rep::code_t c_)
    {
        _text += rep::str(c_);
        return *this;
    }

    logger& logger::operator<<(logger::object_t o_)
    {
        //switch (o_)//...
        //{
        //    case logger::end:

        //}
        return *this;
    }

   
}