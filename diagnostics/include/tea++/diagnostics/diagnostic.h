//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_DIAGNOSTIC_H
//#define TEACC_DIAGNOSTIC_H


#pragma once


#include <tea++/utils/colors.h>
#include <string_view>
#include <map>
#include <stack>
#include <tea++/diagnostics/ll.h>

namespace teacc::diagnostic
{
    using code = uint32_t;
    //using type = uint8_t;
    //...
    code constexpr accepted     = 0;
    code constexpr success      = 1;
    code constexpr ok           = 2;
    code constexpr failed       = 4;
    code constexpr implement    = 5;
    code constexpr error        = 6;
    code constexpr warning      = 7;
    code constexpr fatal        = 8;
    code constexpr info         = 9;
    code constexpr debug        = 10;
    code constexpr application  = 11;
    code constexpr end_of_file  = 12;
     //...
    code constexpr diagnostic12_ = 13;
    
    /*!
    *   @brief Diagnostic Object. 
    * 
    *   The static part of this class is to hold the application-wide stack of classesz of messages and errors descriptions.
    *   An instance of Object can be used to transport messages and diagnostic tests actions through the tests application.
    *      => One object instance:: one test delegate.
    *   Can also be embedded into a library during its development or attached to for general purpose (chronologic/horodated) messaging/errors/logger events.
    * 
    *   @author &copy& 2021, Serge Lussier (oldlonesomecoder/bretzelus/bretzel), lussier.serge@gmail.com
    */
    struct DIAGNOSTICS object
    {
        code _d = 0;
        code _t = 0;
        using vlist = std::stack<object>;
        string_t text;
        
        object() = default;
        object(code d_) : _d(d_) {};
        object(code c_, const char* file_name=nullptr, int line_=0, const char* fn_name=nullptr);
        virtual ~object() = default;
        virtual diagnostic::code operator()();
        
        static std::size_t append(code cc, std::string_view&& txt);
        static std::size_t append(std::map<code,std::string_view> txt);
        static std::size_t init();
        
        static object& push(object::vlist&);
        
        object&  operator|(code);
        object&  operator|(const char*);
        object&  operator|(std::string);
        object&  operator|(string_t);
        
        static void clear(object::vlist& list, const std::function<void(diagnostic::object&)>& lamda_fn);
        
    };


}

#define debuglfn teacc::diagnostic::object(teacc::diagnostic::debug, __FILE__, __LINE__, __FUNCTION__)



//#endif //TEACC_DIAGNOSTIC_H
