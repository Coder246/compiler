//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H


#include <string>
#include "TokenType.h"

class Token {
public:
    Token(TokenType type, std::string value, int line, int pos);
    TokenType getType();
    std::string toString();
    std::string TokenTypeToString(TokenType type);


private:
    TokenType type;
    std::string value;
    int line,pos;
public:
    const std::string &getValue() const;

    int getLine() const;

    int getPos() const;

    void setType(TokenType type);


};


#endif //COMPILER_TOKEN_H
