//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_DIAGNOSTIC_H
//#define TEACC_DIAGNOSTIC_H


#pragma once


#include <tea++/utils/expect.h>
#include <string_view>
#include <map>


namespace teacc::diagnostic
{
    using T = uint32_t;
    //...
    T constexpr accepted    = 0;
    T constexpr success     = 1;
    T constexpr ok          = 2;
    T constexpr failed      = 4;
    T constexpr implement   = 5;
    T constexpr error       = 6;
    T constexpr warning     = 7;
    T constexpr fatal       = 8;
    T constexpr info        = 9;
    T constexpr __usr1__        = 10;
    
    
    //...
    
    
    struct code
    {
        T _d=0;
        
        code() = default;
        code(T d_) : _d(d_) {};
        virtual ~code() = default;
        
        std::string text() const;
        static std::size_t append(T cc, std::string txt_);
        static std::size_t append(std::map<T,std::string_view>&& m_);
        static std::size_t init();
        
        
        
    };
}

//#endif //TEACC_DIAGNOSTIC_H
