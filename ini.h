#pragma once
//#ifndef INI_H_INCLUDED
//    #define INI_H_INCLUDED

#include <ios>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <string_view>

// A VERY rudimentary ini lexer.

enum class ini_token_type {
    Eof,
    Section,
    KeyValue,
};

struct ini_token {
    ini_token_type Type;

    std::string_view Key;
    std::string_view Value;
};

template <typename ItT>
inline ItT TrimLeft(ItT Begin,ItT End){
    auto IsSpace = [](auto c){
        return '\0' <= c && c <= ' ';
    };

    return std::find_if_not(Begin,End,IsSpace);
}

template <typename ItT>
inline ItT TrimRight(ItT Begin,ItT End){
    return TrimLeft(std::make_reverse_iterator(End),std::make_reverse_iterator(Begin)).base();
}

template <typename ItT>
inline std::basic_string_view<typename ItT::value_type> StringView(ItT Begin,ItT End){
    return {&*Begin,static_cast<std::size_t>(End-Begin)};
}

class ini_lexer {
public:
    explicit ini_lexer(const char* Filename);

    ini_token Next();

    std::string Name() const;

    void Error(const char* Message) const;

private:
    std::ifstream File;
    std::string Line;

    std::intmax_t LineNum;

    const char* Filename;
};

//#endif // INI_H_INCLUDED
