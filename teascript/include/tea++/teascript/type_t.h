#pragma once


#include <tea++/utils/string_t.h>
#include <tea++/teascript/ll.h>


namespace teacc::teascript
{

    namespace delta
    {

        using T = uint8_t;
        constexpr T scope = 0;
        constexpr T assign_rs = 1;
        constexpr T unary = 2;
        constexpr T prefix = 3;
        constexpr T deref = 4;
        constexpr T pair = 5;
        constexpr T exponent = 6;
        constexpr T product = 7;
        constexpr T bits = 8;
        constexpr T add = 9;
        constexpr T shift = 10;
        constexpr T less = 11;
        constexpr T comp = 12;
        constexpr T land = 13;
        constexpr T lxor = 14;
        constexpr T lor = 15;
        constexpr T boolean = 16;
        constexpr T ternary = 17;
        constexpr T comma = 18;
        constexpr T identifier = 19;
        constexpr T assign = 20; // a + b * c = 0 - 1
        constexpr T noop = 21;
    }

    
    class TEASCRIPT type_t
    {
    public:
        using type                           = uint64_t;
        static constexpr type null_t         = 0x1000000000000000L;
        static constexpr type number_t       = 0x000000001;
        static constexpr type text_t         = 0x000000002;
        static constexpr type voidptr_t      = 0x000000004;
        static constexpr type any_t          = 0x000000008;
        static constexpr type leaf_t         = 0x000000010;
        static constexpr type sign_t         = 0x000000020;
        static constexpr type i8             = 0x000000040;
        static constexpr type i16            = 0x000000080; // 0x7F41
        static constexpr type i32            = 0x000000100;
        static constexpr type i64            = 0x000000200;
        static constexpr type u8             = 0x000000400;
        static constexpr type u16            = 0x000000800;
        static constexpr type u32            = 0x000001000;
        static constexpr type u64            = 0x000002000;
        static constexpr type float_t        = 0x000004000; // real: f32, f64, f128... ^^
        static constexpr type var_t          = 0x000008000; // Ne pas oublier d'ajouter ce type a toutes "variables"
        static constexpr type bloc_t         = 0x000010000;
        static constexpr type filo_t         = 0x000020000;
        static constexpr type keyword_t      = 0x000040000;
        static constexpr type unary_t        = 0x000080000;
        static constexpr type prefix_t       = 0x000100000;
        static constexpr type postfix_t      = 0x000200000;
        static constexpr type operator_t     = 0x000400000;
        static constexpr type binary_t       = 0x000800000;
        static constexpr type function_t     = 0x001000000;
        static constexpr type function_ptr_t = 0x002000000;
        static constexpr type object_t       = 0x004000000;
        static constexpr type pointer_t      = 0x008000000;
        static constexpr type typeid_t       = 0x010000000;
        static constexpr type identifier     = 0x020000000;
        static constexpr type ref            = 0x040000000;
        static constexpr type punctuation    = 0x080000000;
        static constexpr type assign         = 0x100000000;
        static constexpr type boolean        = 0x200000000;
        static constexpr type hex_t          = 0x400000000;
        static constexpr type open_pair      = 0x800000000;
        static constexpr type close_pair     = 0x1000000000;
        static constexpr type static_t       = 0x8000000000; ///< Flag set at the parser phase when applicable.
        static constexpr type f32            = 0x10000000000;
        static constexpr type f64            = 0x20000000000;
        static constexpr type f128           = 0x40000000000;
        static constexpr type octal_t        = 0x80000000000;
        static constexpr type bin            = 0x100000000000;

    };

    class TEASCRIPT mnemonic
    {
    public:
        enum class type : uint8_t
        {
            null = 0,
            lshift,
            radical,
            exponent,
            rshift,
            decr,
            incr,
            assignadd,
            assignsub,
            assignmul,
            assigndiv,
            deref,
            ship,
            assignmod,
            assignand,
            assignor,
            assignxor,
            assignx1,
            assignlshift,
            assignrshift,
            leq,
            geq,
            eq,
            neq,  // != <>
            add,
            sub,
            mul,
            cppcomment,
            modulo,
            lt,
            gt,
            assign,
            binand,
            binor,
            bitxor,
            x1,           // complement a 1
            x2,
            bitnot,          //
            booland,
            boolor,
            openabs,
            closeabs,
            openpar,
            closepar,
            openindex,
            closeindex,
            openbrace,
            closebrace,
            open_comment,
            close_comment,
            division,
            comma,
            scope,
            semicolon,
            colon,
            range,
            factorial,
            positive,
            negative,
            squote, // '
            dquote, // "
            ternary, // ? :
            hash, // #
            dollard,
            dot,
            k_return,
            k_if,
            k_pi,
            k_number,
            k_u8,
            k_u16,
            k_u32,
            k_u64,
            k_i8,
            k_i16,
            k_i32,
            k_i64,
            k_real,
            k_string,
            k_then,
            k_else,
            k_const,
            k_include,
            k_module,
            k_at,
            k_prime,
            k_do,
            k_while,
            k_for,
            k_until,
            k_repeat,
            k_switch,
            k_case,
            k_type,
            k_hex,
            k_HEX,
            k_cos,
            k_acos,
            k_tan,
            k_atan,
            k_sin,
            k_asin,
            k_object,
            k_static,
            k_me,
            noop,
            k_complex,
            k_this
        };
    };


    class lexem
    {
    public:
        using type                                = const char*;
        static constexpr lexem::type null         = "null";
        static constexpr lexem::type lshift       = "<<";
        static constexpr lexem::type radical      = "^/";
        static constexpr lexem::type exponent     = "^";
        static constexpr lexem::type rshift       = ">>";
        static constexpr lexem::type decr         = "--";
        static constexpr lexem::type incr         = "++";
        static constexpr lexem::type assignadd    = "+=";
        static constexpr lexem::type assignsub    = "-=";
        static constexpr lexem::type assignmul    = "*=";
        static constexpr lexem::type assigndiv    = "/=";
        static constexpr lexem::type deref        = "=>";
        static constexpr lexem::type ship         = "<=>";
        static constexpr lexem::type assignmod    = "%=";
        static constexpr lexem::type assignand    = "&=";
        static constexpr lexem::type assignor     = "|=";
        static constexpr lexem::type assignxor    = "><=";
        static constexpr lexem::type assignx1     = "`=";
        static constexpr lexem::type assignlshift = "<<=";
        static constexpr lexem::type assignrshift = ">>=";
        static constexpr lexem::type leq          = "<=";
        static constexpr lexem::type geq          = ">=";
        static constexpr lexem::type eq           = "==";
        static constexpr lexem::type neq          = "!=";  // != <>
        static constexpr lexem::type add          = "+";
        static constexpr lexem::type sub          = "-";
        static constexpr lexem::type mul          = "*";
        static constexpr lexem::type cppcomment   = "//";
        static constexpr lexem::type modulo       = "%";
        static constexpr lexem::type lt           = "<";
        static constexpr lexem::type gt           = ">";
        static constexpr lexem::type assign       = "=";
        static constexpr lexem::type binand       = "&";
        static constexpr lexem::type binor        = "|";
        static constexpr lexem::type bitxor       = "><";
        static constexpr lexem::type x1           = "`";           // complement a 1
        static constexpr lexem::type x2           = "``";
        static constexpr lexem::type bitnot       = "!";         //
        static constexpr lexem::type booland      = "&&";
        static constexpr lexem::type boolor       = "||";
        static constexpr lexem::type openabs      = "[<";
        static constexpr lexem::type closeabs     = ">]";
        static constexpr lexem::type openpar      = "(";
        static constexpr lexem::type closepar     = ")";
        static constexpr lexem::type openindex    = "[";
        static constexpr lexem::type closeindex   = "]";
        static constexpr lexem::type openbrace    = "{";
        static constexpr lexem::type closebrace   = "}";
        static constexpr lexem::type open_comment = "/*";
        static constexpr lexem::type close_comment= "*/";
        static constexpr lexem::type division     = "/";
        static constexpr lexem::type comma        = ",";
        static constexpr lexem::type scope        = "::";
        static constexpr lexem::type semicolon    = ";";
        static constexpr lexem::type colon        = ":";
        static constexpr lexem::type range        = "..";
        static constexpr lexem::type factorial    = "!";
        static constexpr lexem::type positive     = "+";
        static constexpr lexem::type negative     = "-";
        static constexpr lexem::type squote       = "'"; // '
        static constexpr lexem::type dquote       = "\""; // "
        static constexpr lexem::type ternary      = "?"; // ? :
        static constexpr lexem::type hash         = "#"; // #
        static constexpr lexem::type dollard      = "$";
        static constexpr lexem::type dot          = ".";
        static constexpr lexem::type k_return     = "return";
        static constexpr lexem::type k_if         = "if";
        static constexpr lexem::type k_pi         = "pi";
        static constexpr lexem::type k_number     = "number";
        static constexpr lexem::type k_u8         = "u8";
        static constexpr lexem::type k_u16        = "u16";
        static constexpr lexem::type k_u32        = "u32";
        static constexpr lexem::type k_u64        = "u64";
        static constexpr lexem::type k_i8         = "i8";
        static constexpr lexem::type k_i16        = "i16";
        static constexpr lexem::type k_i32        = "i32";
        static constexpr lexem::type k_i64        = "i64";
        static constexpr lexem::type k_real       = "real";
        static constexpr lexem::type k_string     = "string";
        static constexpr lexem::type k_then       = "then";
        static constexpr lexem::type k_else       = "else";
        static constexpr lexem::type k_const      = "const";
        static constexpr lexem::type k_include    = "include";
        static constexpr lexem::type k_module     = "module";
        static constexpr lexem::type k_at         = "@";
        static constexpr lexem::type k_prime      = "~";
        static constexpr lexem::type k_do         = "do";
        static constexpr lexem::type k_while      = "while";
        static constexpr lexem::type k_for        = "for";
        static constexpr lexem::type k_until      = "until";
        static constexpr lexem::type k_repeat     = "repeat";
        static constexpr lexem::type k_switch     = "switch";
        static constexpr lexem::type k_case       = "case";
        static constexpr lexem::type k_type       = "type";
        static constexpr lexem::type k_hex        = "0x";
        static constexpr lexem::type k_HEX        = "0X";
        static constexpr lexem::type k_cos        = "cos";
        static constexpr lexem::type k_acos       = "acos";
        static constexpr lexem::type k_tan        = "tan";
        static constexpr lexem::type k_atan       = "atan";
        static constexpr lexem::type k_sin        = "sin";
        static constexpr lexem::type k_asin       = "asin";
        static constexpr lexem::type k_object     = "object";
        static constexpr lexem::type k_static     = "static";
        static constexpr lexem::type k_me         = "me";
        static constexpr lexem::type noop         = "noop";
        static constexpr lexem::type k_complex      = "^i";
        static constexpr lexem::type k_this       = "this";
    };
}
