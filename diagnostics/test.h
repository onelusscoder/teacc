#pragma once
#include <tea++/diagnostics/diagnostic.h>

/*


struct rtf_base : public xio{
    using dictionary_t = std::map<std::string, rtf_base*>;
private:
    std::string _id;

public:

    rtf_base() : xio(){}
    rtf_base(xio* a_parent, const std::string& a_id) : xio(a_parent, 0, 0), _id(a_id) {}
    ~rtf_base() override;

    std::string& name() { return _id; }
    virtual alu operator()(const alu::list_t& args) = 0;


};


        /// @brief  runtime struct::function call.
template<typename C, typename R, typename ...A> class rt_function : public rtf_base {

    C* rt_obj = nullptr;

    using rt_fn_t = R(C::*)(A...);
    rt_fn_t rt_fn = nullptr;

public:
    rt_function() = default;
    rt_function(xio* a_parent, const std::string& a_name, C& rt_inst, rt_fn_t a_fn) : rtf_base(a_parent, a_name), rt_obj(&rt_inst), rt_fn(a_fn) {}
    ~rt_function() override = default;
    
        @brief rt calls interpreter script source function.
    
    R operator()(const A& ...args) {
        auto param = [](auto a) {
            //                logdebugpfn << " a= '" << logger::Yellow << a << ":\n";
            return alu(a);
        };
        alu::list_t params = { param(args)... };
        // alu a = call_script_function(_name, params);
        // return a.value<R>();
        return R();
    }

    template <std::size_t ... Is> alu accumulate(alu::list_t const& params, std::index_sequence<Is...> const&) {
        return (rt_obj->*rt_fn)(params[Is].value<A>()...);
    }

    alu operator()(const alu::list_t& params) override {
        //          logdebug << " xio_stack::rt_function(const alu::list_t&):  " << Ends;
        for (auto a : params) {
            //              logdebug << "arg: [" << logger::Yellow << a() << logger::Reset << "]\n";
        }
        return accumulate(params, std::index_sequence_for<A...>{});
    }

    template <std::size_t ... Is> alu accumulate(alu::list_t& params, std::index_sequence<Is...> const&) {
        return (rt_obj->*rt_fn)(params[Is].value<A>()...);
    }


};


//template<typename

class i_object : public bloc {
    using list_t = std::vector<i_object*>;
    rtf_base::dictionary_t rt_functions;
public:
    i_object() = default;
    explicit i_object(xio* a_parent, token_t* a_token = nullptr, alu* a_alu = nullptr);

    ~i_object() override;

    template<typename C, typename R, typename ...A> rtf_base* bind(const std::string& a_id, C& rt_instance, R(C::* rt_fn)(A...)) {
        //rt_function<C, R, A...>* inst = new rt_function<C, R, A...>(this, a_id, rt_instance, rt_fn);
        auto* inst = new rt_function<C, R, A...>(this, a_id, rt_instance, rt_fn);
        rt_functions[a_id] = inst;
        return inst;
    }

    rtf_base& operator[](const std::string f_id) {
        return *rt_functions[f_id];
    }

    virtual alu jsr_rtf(const std::string& a_id, const alu::list_t& args);

};


}



*/
namespace teacc::diagnostic
{

    struct non_obj {};
    struct test_base
    {
        virtual diagnostic::code operator()() = 0;
        virtual ~test_base();

        using list_t = std::vector<test_base*>;
    };




    template<typename class_t, typename ...args_t> class test_t : public test_base
    {
        class_t* _obj_ = nullptr;
    public:
        using code(class_t::* test_fn_ptr)(args_t...);
        virtual diagnostic::code operator()()
        {

        }
        diagnostic::code operator()(args_t...args)
        {
            if (test_fn)
                return (_obj_->*test_fn)(...args);
        }

        diagnostic::code set(class_t& obj_, test_fn_ptr tfn)
        {
            test_fn = tfn;
            return diagnostic::accepted;
        }

    private:
        test_fn_ptr test_fn = nullptr;
    };

}

