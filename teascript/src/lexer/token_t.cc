#include <tea++/teascript/lexer/token_t.h>



namespace teacc::teascript
{
    token_t token_t::_token_null;

    token_t::token_t(mnemonic::type code_, type_t::type type_, type_t::type sem_grp_, delta::T delta_, lexem::type lexem_, int8_t value_flag_)
    {
    }

    token_t::token_t(mnemonic::type code_, type_t::type type_, type_t::type sem_grp_, delta::T delta_, token_t::location_t location_, token_t::flags_t flags_)
    {
        m = code_;
        t = type_;
        s = sem_grp_;
        d = delta_;
        _location = location_;
        _flags = flags_;

    }


    static token_t::list _teascript_tokens_ref =
    {
        {mnemonic::type::null        ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::null,         1},
        {mnemonic::type::lshift      ,           type_t::binary_t,      0x000c00000,  delta::shift,      lexem::lshift,       1},
        {mnemonic::type::openabs     ,           type_t::open_pair,     0x080c00000,  delta::pair,       lexem::openabs,      1},
        {mnemonic::type::closeabs    ,           type_t::close_pair,    0x080400000,  delta::pair,       lexem::closeabs,     1},
        {mnemonic::type::radical     ,           type_t::binary_t,      0x000c00000,  delta::exponent,   lexem::radical,      1},
        {mnemonic::type::exponent    ,           type_t::binary_t,      0x000c00000,  delta::exponent,   lexem::exponent,     1},
        {mnemonic::type::rshift      ,           type_t::binary_t,      0x000400000,  delta::shift,      lexem::rshift,       1},
        {mnemonic::type::bitxor      ,           type_t::binary_t,      0x000c00000,  delta::bits,       lexem::bitxor,       1},
        {mnemonic::type::decr        ,           type_t::unary_t,       0x000580000,  delta::unary,      lexem::decr,         1},
        {mnemonic::type::incr        ,           type_t::unary_t,       0x000580000,  delta::unary,      lexem::incr,         1},
        {mnemonic::type::assignadd   ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignadd,    1},
        {mnemonic::type::assignsub   ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignsub,    1},
        {mnemonic::type::assignmul   ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignmul,    1},
        {mnemonic::type::assigndiv   ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assigndiv,    1},
        {mnemonic::type::deref       ,           type_t::binary_t,      0x000400000,  delta::product,    lexem::deref,        1},
        {mnemonic::type::ship        ,           type_t::assign,        0x000400000,  delta::less,       lexem::ship,         1},
        {mnemonic::type::assignmod   ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignmod,    1},
        {mnemonic::type::assignand   ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignand,    1},
        {mnemonic::type::assignor    ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignor,     1},
        {mnemonic::type::assignxor   ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignxor,    1},
        {mnemonic::type::assignx1    ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignx1,     1},
        {mnemonic::type::assignlshift,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignlshift, 1},
        {mnemonic::type::assignrshift,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assignrshift, 1},
        {mnemonic::type::leq         ,           type_t::binary_t,      0x200c00000,  delta::less,       lexem::leq,          1},
        {mnemonic::type::geq         ,           type_t::binary_t,      0x200c00000,  delta::less,       lexem::geq,          1},
        {mnemonic::type::eq          ,           type_t::binary_t,      0x200c00000,  delta::less,       lexem::eq,           1},
        {mnemonic::type::neq         ,           type_t::binary_t,      0x200c00000,  delta::less,       lexem::neq,          1},
        {mnemonic::type::neq         ,           type_t::binary_t,      0x200c00000,  delta::less,       "<>",                1},
        {mnemonic::type::add         ,           type_t::binary_t,      0x000c00000,  delta::add,        lexem::add,          1},
        {mnemonic::type::sub         ,           type_t::binary_t,      0x000c00000,  delta::add,        lexem::sub,          1},
        {mnemonic::type::mul         ,           type_t::binary_t,      0x000c00000,  delta::product,    lexem::mul,          1},
        {mnemonic::type::cppcomment  ,           type_t::punctuation,   0x00000,      delta::noop,       lexem::cppcomment,   0},
        {mnemonic::type::modulo      ,           type_t::binary_t,      0x000c00000,  delta::product,    lexem::modulo,       1},
        {mnemonic::type::lt          ,           type_t::binary_t,      0x200c00000,  delta::less,       lexem::lt,           1},
        {mnemonic::type::gt          ,           type_t::binary_t,      0x200c00000,  delta::less,       lexem::gt,           1},
        {mnemonic::type::assign      ,           type_t::assign,        0x100c40000,  delta::assign,     lexem::assign,       1},
        {mnemonic::type::binand      ,           type_t::binary_t,      0x000c00000,  delta::bits,       lexem::binand,       1},
        {mnemonic::type::binor       ,           type_t::binary_t,      0x000c00000,  delta::bits,       lexem::binor,        1},
        {mnemonic::type::x2          ,           type_t::prefix_t,      0x000580000,  delta::prefix,     lexem::x2,           1},
        {mnemonic::type::x1          ,           type_t::prefix_t,      0x000580000,  delta::prefix,     lexem::x1,           1},
        {mnemonic::type::bitnot      ,           type_t::unary_t,       0x000580000,  delta::prefix,     lexem::bitnot,       1},
        {mnemonic::type::booland     ,           type_t::binary_t,      0x200c00000,  delta::land,       lexem::booland,      1},
        {mnemonic::type::boolor      ,           type_t::binary_t,      0x200c00000,  delta::lor,        lexem::boolor,       1},
        {mnemonic::type::openpar     ,           type_t::open_pair,     0x880c00000,  delta::pair,       lexem::openpar,      1},
        {mnemonic::type::closepar    ,           type_t::close_pair,    0x1080400000, delta::pair,       lexem::closepar,     1},
        {mnemonic::type::openindex   ,           type_t::binary_t,      0x2080c00000, delta::pair,       lexem::openindex,    1},
        {mnemonic::type::closeindex  ,           type_t::close_pair,    0x4080400000, delta::pair,       lexem::closeindex,   1},
        {mnemonic::type::openbrace   ,           type_t::binary_t,      0x880c00000,  delta::pair,       lexem::openbrace,    1},
        {mnemonic::type::closebrace  ,           type_t::close_pair,    0x1080400000, delta::pair,       lexem::closebrace,   1},
        {mnemonic::type::open_comment,           type_t::punctuation,   0x00000,      delta::noop,       lexem::open_comment, 0},
        {mnemonic::type::close_comment,          type_t::punctuation,   0x00000,      delta::noop,       lexem::close_comment,0},
        {mnemonic::type::division    ,           type_t::binary_t,      0x000c00000,  delta::product,    lexem::division,     1},
        {mnemonic::type::comma       ,           type_t::binary_t,      0x080c00000,  delta::comma,      lexem::comma,        1},
        {mnemonic::type::scope       ,           type_t::binary_t,      0x080c00000,  delta::scope,      lexem::scope,        1},
        {mnemonic::type::semicolon   ,           type_t::punctuation,   0x080000000,  delta::noop,       lexem::semicolon,    0},
        {mnemonic::type::colon       ,           type_t::binary_t,      0x080c00000,  delta::noop,       lexem::colon,        0},
        {mnemonic::type::range       ,           type_t::binary_t,      0x080c00000,  delta::scope,      lexem::range,        1},
        {mnemonic::type::factorial   ,           type_t::postfix_t,     0x000580000,  delta::unary,      lexem::factorial,    1},
        {mnemonic::type::positive    ,           type_t::prefix_t,      0x000580020,  delta::unary,      lexem::positive,     1},
        {mnemonic::type::negative    ,           type_t::prefix_t,      0x000580020,  delta::unary,      lexem::negative,     1},
        {mnemonic::type::squote      ,           type_t::text_t,        0x000400012,  delta::identifier, lexem::squote,       1},
        {mnemonic::type::dquote      ,           type_t::text_t,        0x000400012,  delta::identifier, lexem::dquote,       1},
        {mnemonic::type::ternary     ,           type_t::keyword_t,     0x000c40000,  delta::unary,      lexem::ternary,      1},
        {mnemonic::type::hash        ,           type_t::prefix_t,      0x000580000,  delta::unary,      lexem::hash,         1},
        {mnemonic::type::dollard     ,           type_t::prefix_t,      0x000580000,  delta::unary,      lexem::dollard,      1},
        {mnemonic::type::dot         ,           type_t::punctuation,   0x080400000,  delta::scope,      lexem::dot,          1},
        {mnemonic::type::k_return    ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_return,     0},
        {mnemonic::type::k_if        ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_if,         0},
        {mnemonic::type::k_pi        ,           type_t::keyword_t,     0x000044011,  delta::identifier, lexem::k_pi,         1},
        {mnemonic::type::k_number    ,           type_t::prefix_t,      0x000540001,  delta::identifier, lexem::k_number,     1},
        {mnemonic::type::k_u8        ,           type_t::prefix_t,      0x000540400,  delta::identifier, lexem::k_u8,         1},
        {mnemonic::type::k_u16       ,           type_t::prefix_t,      0x000540800,  delta::identifier, lexem::k_u16,        1},
        {mnemonic::type::k_u32       ,           type_t::prefix_t,      0x000541000,  delta::identifier, lexem::k_u32,        1},
        {mnemonic::type::k_u64       ,           type_t::prefix_t,      0x000542000,  delta::identifier, lexem::k_u64,        1},
        {mnemonic::type::k_i8        ,           type_t::prefix_t,      0x000540040,  delta::identifier, lexem::k_i8,         1},
        {mnemonic::type::k_i16       ,           type_t::prefix_t,      0x000540080,  delta::identifier, lexem::k_i16,        1},
        {mnemonic::type::k_i32       ,           type_t::prefix_t,      0x000540100,  delta::identifier, lexem::k_i32,        1},
        {mnemonic::type::k_i64       ,           type_t::prefix_t,      0x000540200,  delta::identifier, lexem::k_i64,        1},
        {mnemonic::type::k_real      ,           type_t::prefix_t,      0x000544000,  delta::identifier, lexem::k_real,       1},
        {mnemonic::type::k_string    ,           type_t::prefix_t,      0x000540002,  delta::identifier, lexem::k_string,     1},
        {mnemonic::type::k_then      ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_then,       0},
        {mnemonic::type::k_else      ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_else,       0},
        {mnemonic::type::k_const     ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_const,      0},
        {mnemonic::type::k_include   ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_include,    0},
        {mnemonic::type::k_module    ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_module,     0},
        {mnemonic::type::k_at        ,           type_t::prefix_t,      0x000580000,  delta::unary,      lexem::k_at,         1},
        {mnemonic::type::k_prime     ,           type_t::prefix_t,      0x000580000,  delta::unary,      lexem::k_prime,      1},
        {mnemonic::type::k_do        ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_do,         0},
        {mnemonic::type::k_while     ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_while,      0},
        {mnemonic::type::k_for       ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_for,        0},
        {mnemonic::type::k_until     ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_until,      0},
        {mnemonic::type::k_repeat    ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_repeat,     0},
        {mnemonic::type::k_switch    ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_switch,     0},
        {mnemonic::type::k_case      ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_case,       0},
        {mnemonic::type::k_type      ,           type_t::keyword_t,     0x000040000,  delta::noop,       lexem::k_type,       0},
        {mnemonic::type::k_hex       ,           type_t::hex_t,         0x400440011,  delta::noop,       lexem::k_hex,        1},
        {mnemonic::type::k_HEX       ,           type_t::hex_t,         0x400440011,  delta::noop,       lexem::k_HEX,        1},
        {mnemonic::type::k_cos       ,           type_t::prefix_t,      0x000580000,  delta::unary,      lexem::k_cos,        1},
        {mnemonic::type::k_acos      ,           type_t::prefix_t,      0x0005c0000,  delta::unary,      lexem::k_acos,       1},
        {mnemonic::type::k_tan       ,           type_t::prefix_t,      0x0005c0000,  delta::unary,      lexem::k_tan,        1},
        {mnemonic::type::k_atan      ,           type_t::prefix_t,      0x0005c0000,  delta::unary,      lexem::k_atan,       1},
        {mnemonic::type::k_sin       ,           type_t::prefix_t,      0x0005c0000,  delta::unary,      lexem::k_sin,        1},
        {mnemonic::type::k_asin      ,           type_t::prefix_t,      0x0005c0000,  delta::unary,      lexem::k_asin,       1},
        {mnemonic::type::k_object    ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_object,     0},
        {mnemonic::type::k_static    ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_static,     0},
        {mnemonic::type::k_me        ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_me,         1},
        {mnemonic::type::k_this      ,           type_t::keyword_t,     0x000040000,  delta::identifier, lexem::k_this,       1},
        {mnemonic::type::k_complex   ,           type_t::prefix_t,      0x000580000,  delta::unary,      lexem::k_complex,    1}
};

token_t token_t::operator[](mnemonic::type m_)
{
    token_t token;

    for (auto token : _teascript_tokens_ref)
    {
        if (token.m == m_) return token;
    }
    return token_t::_token_null;
}

std::string token_t::mark()
{
    return std::string();
}

std::string token_t::sem_types()
{
    return std::string();
}

std::string token_t::type_name()
{
    return std::string();
}

std::string token_t::details(bool mark_)
{
    return std::string();
}




std::string token_t::location_t::operator()()
{
    string_t str;
    str += l;
    str += ',';
    str += c;
    return str();
}

std::string token_t::location_t::text()
{
    std::string str;

    if (!begin) return "";
    const char* c = begin;

    while (c <= end) str += c++;

    return str;
}

}