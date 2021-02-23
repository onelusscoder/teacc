#pragma once

//
// Created by bretzel on 20-04-17.
//


//#pragma warning(once: 4251)


#ifdef TEAUTILS
# undef TEAUTILS
#endif

#ifdef _WIN32
#   pragma warning(disable : 4996)
#   pragma warning(disable : 4005)
//class __declspec(dllimport) std::thread;
#   define _CRT_SECURE_NO_WARNINGS
#   define _SCL_SECURE_NO_WARNINGS

#   ifdef UTILS_DLL_EXPORT
#       define TEAUTILS __declspec(dllexport)
#       if __GNUC__ >= 4
#           define UTILS __attribute__ ((visibility ("default")))
#           define PRIVATE_LIB  __attribute__ ((visibility ("hidden")))
//#       else
//#           define REM_LIB
//#           define PRIVATE_LIB
#       endif
#   else
#       define TEAUTILS __declspec(dllimport)
#   endif
#   else
#       define TEAUTILS    // Not ms-Windows/MSVC
#endif

// Mandatory. Globally used where it needs to.

//---------------------------------------------

#ifndef REFLECTION_ID
#define REFLECTION_ID \
    public:\
        virtual const char*  class_name() const noexcept; \
    private:\


#define  CLASSNAME_IMPL(CLASS) \
         const char*   CLASS::class_name() const noexcept{ return #CLASS; }
#endif

#ifndef _WIN32
#   define _strdup  strdup

#   include <thread>
#   include <cstdint>

#else
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

