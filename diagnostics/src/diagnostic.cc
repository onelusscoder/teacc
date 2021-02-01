//
// Created by lsc on 21-01-29.
//
#include <tea++/utils/string_t.h>

#include <tea++/diagnostics/diagnostic.h>




namespace teacc::diagnostic
{

static std::map<code,std::string_view> _dictionary;




std::size_t object::append(code cc, std::string_view &&txt)
{
    _dictionary[cc] = txt;
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
 
std::size_t object::init()
{
    if(!_dictionary.empty()) return _dictionary.size();
    // testing std::map::merge:
    std::map<code,std::string_view> _ = {
        {diagnostic::accepted   , "accepted"},
        {diagnostic::failed     , "failed"},
        {diagnostic::implement  , "implement"},
        {diagnostic::ok         , "ok"},
        {diagnostic::success    , "success"},
        {diagnostic::error      , "error"},
        {diagnostic::warning    , "warning"},
        {diagnostic::fatal      , "fatal"},
        {diagnostic::info       , "info"},
        {diagnostic::debug      , "debug"},
        {diagnostic::application, "application"},
    };
    
    
    object::append(_);
    return _dictionary.size();
}
std::size_t object::append(std::map<code, std::string_view> m_)
{
    _dictionary.merge(m_);
    return _dictionary.size();
}
object &object::push(object::vlist& l)
{
    l.push(object());
    return l.top();
}

object &object::operator|(code c)
{
    text += _dictionary[c];
    return *this;
}


object &object::operator|(const char *txt)
{
    text += txt;
    return *this;
}


object &object::operator|(std::string txt)
{
    text += txt;
    return *this;
}


object &object::operator|(string_t txt)
{
    text += txt.c_str();
    return *this;
}


void object::clear(object::vlist &list, const std::function<void(diagnostic::object &)>& lambda_fn)
{
    if(list.empty()) return;
    do{
      if(lambda_fn)
          lambda_fn(list.top());
      list.pop();
    }while(!list.empty());
}


/*!
 * @brief Constructs the instance of object with file, line# and function name as the header informations.
 * @param c_ diagnostic mnemonic code.
 * @param file_name source file normally given by the macro __FILE__ if using this constructors from the corresponding macro.
 * @param line_ line# given by the __LINE__ macro if using this constructors from the corresponding macro.
 * @param fn_name  function name given by __FUNCTION__ macro if using this constructors from the corresponding macro.
 */
object::object(code c_, const char *file_name, int line_, const char *fn_name)
{
    if(file_name)
    {
        text +=  color::ansi(color::White);
        text +=  file_name;
        text +=  color::ansi(color::Blue);
        text += "::";
    }
    if(line_)
    {
        std::ostringstream os;
        os << line_;
        text += os.str();
        text += ':';
    }
    if(fn_name)
    {
        text << color::ansi(color::Yellow) << fn_name;
        text << ':';
    }
    
    text += _dictionary[c_];
    text += " - ";
    
}

}
