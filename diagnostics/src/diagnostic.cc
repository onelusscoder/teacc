//
// Created by lsc on 21-01-29.
//

#include <tea++/diagnostics/diagnostic.h>




namespace teacc::diagnostic
{

static std::map<T,std::string_view> _dictionary;


std::string code::text() const
{
    return std::string(_dictionary[_d]);
}


std::size_t code::append(T cc, std::string txt_)
{
    _dictionary[cc] = txt_;
    return _dictionary.size();
}

/*!
 * @brief
 *
 * @note (https://stackoverflow.com/questions/3005269/how-can-i-concatenate-two-c-maps)
 *
 * If you just want to merge them but in case of collisions keep the elements from map1, then just reverse the maps:

std::swap(map1, map2);
map1.insert(map2.begin(), map2.end());
This of course assumes that after the merge, you're only interested in the result and lo longer in the old collections.
 Since C++17 std::map provides a merge() member function, so you can simply call map1.merge(map2);.
 
 * @return std::size_t count of items in the dictionary.
 */
 
std::size_t code::init()
{
    if(!_dictionary.empty()) return _dictionary.size();
    _dictionary = {
        {diagnostic::accepted, "accepted"},
        {diagnostic::failed,   "failed"},
        {diagnostic::implement, "implement"},
        {diagnostic::ok,       "ok"},
        {diagnostic::success,  "success"},
        {diagnostic::error,  "error"},
        {diagnostic::warning,  "warning"},
        {diagnostic::fatal,  "fatal"},
        {diagnostic::info,  "info"},
    };
    return _dictionary.size();
}
std::size_t code::append(std::map<T, std::string_view> &&m_)
{
    _dictionary.merge(std::move(m_));
    return _dictionary.size();
}

}
