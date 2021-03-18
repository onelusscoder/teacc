

/*!
    License: BSD 2 Light.
    @author &copy; 2021, Serge Lussier (aka bretzel, Bretzelus, oldlonesomecoder, lordvorace), lussier.serge@gmail.com
*/
#pragma once


#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <tea++/diagnostics/rem.h>
#include <cmath>
#include <functional>
#include <memory>
#include <string_view>

namespace tea::diagnostics{


    class diagnostic;

    struct DIAGNOSTICS test
    {
        using lambda_fn_t = std::function <rem::code_t()>;

        std::string name;
        bool        selected = false;
        lambda_fn_t fn = nullptr;

        test() = default;
        test(test&&) noexcept = default;
        test(const test&) = default;
        test(const std::string& name_, bool selected_, test::lambda_fn_t fn_) : name(name_), selected(selected_), fn(fn_) {}
        virtual ~test();

        using collection = std::vector<test>;

        test& operator = (test&&) noexcept = default;
        test& operator = (const test&) noexcept = default;
        template<typename T> static rem::code_t eq(const T& lhs, const T& rhs)
        {
            if (lhs == rhs) return rem::pass;
            //...
            return rem::fail;
        }

        template<typename T> static rem::code_t neq(const T& lhs, const T& rhs)
        {
            if (lhs != rhs) return rem::pass;
            //...
            return rem::fail;
        }

        static rem::code_t not_null(void* v)
        {
            if (v != nullptr) return rem::pass;
            //...
            return rem::fail;
        }
        rem::code_t run();
    };


    class DIAGNOSTICS diagnostic
    {
        std::string _name;
        test::collection _tests;

    public:
        diagnostic() = default;
        diagnostic(const std::string& n_) : _name(n_) {}

        diagnostic& operator << (test&& test_)
        {
            _tests.emplace_back(std::move(test_));
            return *this;
        }

        diagnostic& declare_tests (test::collection col_);
        diagnostic& operator += (test&& test_)
        {
            _tests.emplace_back(std::move(test_));
            return *this;
        }

        virtual ~diagnostic() = default;
        virtual rem::code_t run();
    };



}



