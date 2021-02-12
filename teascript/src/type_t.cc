#include <tea++/teascript/type_t.h>
#include <map>

namespace teacc::teascript
{
    std::string teacc::teascript::type_t::name(type_t::type t)
    {
        std::map<type_t::type, const char*> _ = {
            {null_t         ,"null"},
            {number_t       ,"number"},
            {text_t         ,"text"},
            {voidptr_t      ,"voidptr"},
            {any_t          ,"any"},
            {leaf_t         ,"leaf"},
            {sign_t         ,"sign"},
            {i8             ,"i8"},
            {i16            ,"i16"},
            {i32            ,"i32"},
            {i64            ,"i64"},
            {u8             ,"u8"},
            {u16            ,"u16"},
            {u32            ,"u32"},
            {u64            ,"u64"},
            {float_t        ,"float"},
            {var_t          ,"var"},
            {bloc_t         ,"bloc"},
            {filo_t         ,"stack"},
            {keyword_t      ,"keyword"},
            {unary_t        ,"unary"},
            {prefix_t       ,"prefix"},
            {postfix_t      ,"postfix"},
            {operator_t     ,"operator"},
            {binary_t       ,"binary"},
            {function_t     ,"function"},
            {function_ptr_t ,"function_ptr"},
            {object_t       ,"object"},
            {pointer_t      ,"pointer"},
            {typeid_t       ,"typeid"},
            {identifier     ,"identifier"},
            {ref            ,"ref"},
            {punctuation    ,"punctuation"},
            {assign         ,"assign"},
            {boolean        ,"boolean"},
            {hex_t          ,"hex_t"},
            {open_pair      ,"open_pair"},
            {close_pair     ,"close_pair"},
            {static_t       ,"static_t"},
            {f32            ,"f32"},
            {f64            ,"f64"},
            {f128           ,"f128"},
            {octal_t        ,"octal"},
            {bin            ,"bin"}
        };
        std::string str;

        if (t > bin)
        {
            str += "*.*";
            return str;
        }

        type tbm = t;
        int  a, c, b;

        for (const auto& t_name : _)
        {
            if (!tbm)
                break;
            if (t_name.first & tbm)
            {
                str += t_name.second;
                tbm &= ~t_name.first;  // Remove the Bit from the "Sem" field.
                if (tbm)
                    str += '|';
            }
        }
        if (str.empty())
            str += "null";
        return str;
    }


    type_t::type type_t::encode(const std::string& type_str)
    {
        std::map<const char*, type_t::type> _ =
        {
            {"null"          ,null_t         },
            {"number"        ,number_t       },
            {"text"          ,text_t         },
            {"voidptr"       ,voidptr_t      },
            {"any"           ,any_t          },
            {"leaf"          ,leaf_t         },
            {"sign"          ,sign_t         },
            {"i8"            ,i8             },
            {"i16"           ,i16            },
            {"i32"           ,i32            },
            {"i64"           ,i64            },
            {"u8"            ,u8             },
            {"u16"           ,u16            },
            {"u32"           ,u32            },
            {"u64"           ,u64            },
            {"float"         ,float_t        },
            {"var"           ,var_t          },
            {"bloc"          ,bloc_t         },
            {"stack"         ,filo_t         },
            {"keyword"       ,keyword_t      },
            {"unary"         ,unary_t        },
            {"prefix"        ,prefix_t       },
            {"postfix"       ,postfix_t      },
            {"operator"      ,operator_t     },
            {"binary"        ,binary_t       },
            {"function"      ,function_t     },
            {"function_ptr"  ,function_ptr_t },
            {"object"        ,object_t       },
            {"pointer"       ,pointer_t      },
            {"typeid"        ,typeid_t       },
            {"identifier"    ,identifier     },
            {"ref"           ,ref            },
            {"punctuation"   ,punctuation    },
            {"assign"        ,assign         },
            {"boolean"       ,boolean        },
            {"hex_t"         ,hex_t          },
            {"open_pair"     ,open_pair      },
            {"close_pair"    ,close_pair     },
            {"static_t"      ,static_t       },
            {"f32"           ,f32            },
            {"f64"           ,f64            },
            {"f128"          ,f128           },
            {"octal"         ,octal_t        },
            {"bin"           ,bin            }
        };
        
        type types = 0;
        string_t::word::collection w;
        string_t str;
        str += type_str;
        std::size_t s = str.words(w, "/", false);

        for (auto i : w) types |= _[i().c_str()];
        
        return types;
    }
}
