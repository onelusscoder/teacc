#include <tea++/utils/logger.h>

namespace tea
{
    logger::~logger()
    {
        str.clear();
    }

    logger& logger::operator<<(text::color fg_)
    {
        /// <summary>
        /// @todo hold text format config...
        /// </summary>
        /// <param name="fg_"></param>
        /// <returns>self instance reference</returns>
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
        //...
        return *this;
    }

    rep::code_t logger::th_context_t::clear()
    {
        //...
        return rep::ok;
    }

}