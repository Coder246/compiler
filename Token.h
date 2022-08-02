//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H


#include <string>
#include "TokenType.h"

class Token {
public:
    Token(TokenType type, std::string value);
    TokenType getType();

private:
    TokenType type;
    std::string value;



};


#endif //COMPILER_TOKEN_H
