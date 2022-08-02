//
// Created by tim on 02.08.22.
//

#include "Token.h"

Token::Token(TokenType type, std::string value, int line, int pos) {
    this->type = type;
    this->value = value;
    this->line = line;
    this->pos = pos;
}

TokenType Token::getType() {
    return this->type;
}

const std::string &Token::getValue() const {
    return value;
}

int Token::getLine() const {
    return line;
}

int Token::getPos() const {
    return pos;
}

std::string Token::toString() {
    return "Token(" + std::to_string(line) + ":" + std::to_string(pos) + ") " + TokenTypeToString(type) + ": " + value;
}

std::string Token::TokenTypeToString(TokenType type) {
switch (type) {
    case TOKEN_LEFT_BRACKET:
        return "TOKEN_LEFT_BRACKET";
    case TOKEN_RIGHT_BRACKET:
        return "TOKEN_RIGHT_BRACKET";
    case TOKEN_LEFT_CURLY:
        return "TOKEN_LEFT_CURLY";
    case TOKEN_RIGHT_CURLY:
        return "TOKEN_RIGHT_CURLY";
    case TOKEN_LEFT_SQUARE_BRACKET:
        return "TOKEN_LEFT_SQUARE_BRACKET";
    case TOKEN_RIGHT_SQUARE_BRACKET:
        return "TOKEN_RIGHT_SQUARE_BRACKET";
    case TOKEN_COMMA:
        return "TOKEN_COMMA";
    case TOKEN_DOT:
        return "TOKEN_DOT";
    case TOKEN_SEMICOLON:
        return "TOKEN_SEMICOLON";
    case TOKEN_COLON:
        return "TOKEN_COLON";
    case TOKEN_QUESTION_MARK:
        return "TOKEN_QUESTION_MARK";
    case TOKEN_PLUS:
        return "TOKEN_PLUS";
    case TOKEN_MINUS:
        return "TOKEN_MINUS";
    case TOKEN_STAR:
        return "TOKEN_STAR";
    case TOKEN_SLASH:
        return "TOKEN_SLASH";
    case TOKEN_MODULO:
        return "TOKEN_MODULO";
    case TOKEN_GREATER_THAN:
        return "TOKEN_GREATER_THAN";
    case TOKEN_LESS_THAN:
        return "TOKEN_LESS_THAN";
    case TOKEN_SET:
        return "TOKEN_SET";
    case TOKEN_EQUAL:
        return "TOKEN_EQUAL";
    case TOKEN_NOT_EQUAL:
        return "TOKEN_NOT_EQUAL";
    case TOKEN_LESS_THAN_EQUAL:
        return "TOKEN_LESS_THAN_EQUAL";
    case TOKEN_GREATER_THAN_EQUAL:
        return "TOKEN_GREATER_THAN_EQUAL";
    case TOKEN_PLUS_EQUAL:
        return "TOKEN_PLUS_EQUAL";
    case TOKEN_MINUS_EQUAL:
        return "TOKEN_MINUS_EQUAL";
    case TOKEN_STAR_EQUAL:
        return "TOKEN_STAR_EQUAL";
    case TOKEN_SLASH_EQUAL:
        return "TOKEN_SLASH_EQUAL";
    case TOKEN_MODULO_EQUAL:
        return "TOKEN_MODULO_EQUAL";
    case TOKEN_SHIFT_LEFT:
        return "TOKEN_SHIFT_LEFT";
    case TOKEN_SHIFT_RIGHT:
        return "TOKEN_SHIFT_RIGHT";
    case TOKEN_SHIFT_LEFT_EQUAL:
        return "TOKEN_SHIFT_LEFT_EQUAL";
    case TOKEN_SHIFT_RIGHT_EQUAL:
        return "TOKEN_SHIFT_RIGHT_EQUAL";
    case TOKEN_BITWISE_OR_EQUAL:
        return "TOKEN_BITWISE_OR_EQUAL";
    case TOKEN_BITWISE_AND_EQUAL:
        return "TOKEN_BITWISE_AND_EQUAL";
    case TOKEN_BITWISE_XOR_EQUAL:
        return "TOKEN_BITWISE_XOR_EQUAL";
    case TOKEN_PLUS_PLUS:
        return "TOKEN_PLUS_PLUS";
    case TOKEN_MINUS_MINUS:
        return "TOKEN_MINUS_MINUS";
    case TOKEN_AND:
        return "TOKEN_AND";
    case TOKEN_OR:
        return "TOKEN_OR";
    case TOKEN_STRING:
        return "TOKEN_STRING";
    case TOKEN_CHAR:
        return "TOKEN_CHAR";
    case TOKEN_IDENTIFIER:
        return "TOKEN_IDENTIFIER";
    case TOKEN_BITWISE_NOT:
        return "TOKEN_BITWISE_NOT";
    case TOKEN_BITWISE_OR:
        return "TOKEN_BITWISE_OR";
    case TOKEN_BITWISE_AND:
        return "TOKEN_BITWISE_AND";
    case TOKEN_BITWISE_XOR:
        return "TOKEN_BITWISE_XOR";
    case TOKEN_NUMBER:
        return "TOKEN_NUMBER";
    case TOKEN_KEYWORD:
        return "TOKEN_KEYWORD";

    default:
        return "UNKNOWN";



};
}
