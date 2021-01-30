//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_EXPECT_H
//#define TEACC_EXPECT_H


#pragma once

#include <any>

#include <cstdint>
#include <string>


namespace teacc
{


template<typename T> class expect
{
    bool good = false;
    std::any _d;
    
public:
    expect() = default;
    expect(T d_) : _d(std::move(d_)){ good = true;}
    expect(expect&& ) noexcept = default;
    
    
    
    ~expect() { _d.reset(); }
    
    expect& operator=(expect&&) noexcept = default;
    expect& operator=(T& d_) { _d = d_; good = true; return *this; }
    expect& operator=(T&& d_) { _d = std::move(d_); good = true; return *this; }
    expect& operator=(bool good_) { good = good_; return *this; }
    
    
    // ---- T must be constructible:
    T operator()(){ if(!good) return T(); else  return _d; }
    T operator*(){  if(!good) return T(); else  return _d; }
    // -------------------------------
    
    explicit operator bool() { return good; }
    
};

}
//#endif //TEACC_EXPECT_H
