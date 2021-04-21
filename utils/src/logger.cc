#include <tea++/utils/logger.h>

namespace tea
{
    logger::logger(std::string_view ctx_name)
    {

    }
    logger::~logger()
    {
        str.clear();
    }

    /// <summary>
    /// @todo hold text format config...
    /// </summary>
    /// <param name="fg_"></param>
    /// <returns>self instance reference</returns>
    logger& logger::operator<<(text::color fg_)
    {
        
        str += text::ansi(fg_);
        return *this;
    }

    logger& logger::operator<<(const std::string& d_)
    {
        str += d_;
        return *this;
    }

    logger& logger::operator<<(rep::type_t t_)
    {
        str += rep::str(t_);
        return *this;
    }

    logger& logger::operator<<(rep::code_t c_)
    {
        str += rep::str(c_);
        return *this;
    }

    logger& logger::operator<<(logger::object_t o_)
    {
        switch (o_)//...
        {
            case logger::end:

        }
        return *this;
    }

   
}