

#pragma once

#include <tea++/teascript/lexer/lexer.h>


namespace teacc::teascript
{



bool lexer::cursor_t::operator++()
{
    return false;
}

bool lexer::cursor_t::operator++(int)
{
    return false;
}

bool lexer::cursor_t::skipws()
{
    return false;
}

bool lexer::cursor_t::eof(const char* p) const
{
    return false;
}

long lexer::cursor_t::index() const
{
    return 0;
}

std::string lexer::cursor_t::scantoeol()
{
    return std::string();
}

std::string lexer::cursor_t::line() const
{
    return std::string();
}

std::string lexer::cursor_t::mark() const
{
    return std::string();
}

std::string lexer::cursor_t::location() const
{
    return std::string();
}

diagnostic::code lexer::cursor_t::scanto(const char* substr_)
{
    return diagnostic::code();
}

expect<diagnostic::code> lexer::cursor_t::scanstring()
{
    return expect<diagnostic::code>();
}

lexer::num_scanner_t::num_scanner_t(const char* _c, const char* _eos)
{
}

bool lexer::num_scanner_t::operator++(int)
{
    return false;
}

lexer::num_scanner_t::operator bool() const
{
    return false;
}

type_t::type lexer::num_scanner_t::operator()() const
{
    return type_t::type();
}

lexer::result lexer::exec()
{
    return lexer::result();
}

lexer::result lexer::operator()()
{
    return lexer::result();
}

void lexer::flush(std::function<void(token_t)> f_)
{
}

lexer::result lexer::push(token_t& token_)
{
    return lexer::result();
}

lexer::scanner lexer::get_scanner(token_t& t_)
{
    return scanner();
}

lexer::cursor_t::cursor_t(const char* source_)
{
}

void lexer::insert_multiply(token_t&)
{
}

}