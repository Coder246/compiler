//
// Created by tim on 02.08.22.
//

#include "Token.h"

Token::Token(TokenType type, std::string value) {
    this->type = type;
    this->value = value;
}

TokenType Token::getType() {
    return this->type;
}
