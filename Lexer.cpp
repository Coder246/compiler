//
// Created by tim on 02.08.22.
//

#include <string>
#include <iostream>
#include "Lexer.h"

void Lexer::lex(const std::string &input) {
    this->length = input.length();
    this->source = input;

    while (this->counter < this->length) {
        char c = this->nextToken();
        if (c == ' ' || c == '\n' || c == '\t') {
            this->next();
        } else if (c == '{') {
            this->checkBraceStack(c, true, TokenType::TOKEN_LEFT_CURLY, TokenType::TOKEN_RIGHT_CURLY);
            this->addToken(TokenType::TOKEN_LEFT_CURLY, "{");
            this->next();
        } else if (c == '}') {
            this->checkBraceStack(c, false, TokenType::TOKEN_RIGHT_CURLY, TokenType::TOKEN_LEFT_CURLY);
            this->addToken(TokenType::TOKEN_RIGHT_CURLY, "}");
            this->next();
        } else if (c == '(') {
            this->checkBraceStack(c, true, TokenType::TOKEN_LEFT_BRACKET, TokenType::TOKEN_RIGHT_BRACKET);
            this->addToken(TokenType::TOKEN_LEFT_BRACKET, "(");
            this->next();

        } else if (c == ')') {
            this->checkBraceStack(c, false, TokenType::TOKEN_RIGHT_BRACKET, TokenType::TOKEN_LEFT_BRACKET);
            this->addToken(TokenType::TOKEN_RIGHT_BRACKET, ")");
            this->next();

        } else if (c == '[') {
            this->checkBraceStack(c, true, TokenType::TOKEN_LEFT_SQUARE_BRACKET, TokenType::TOKEN_RIGHT_SQUARE_BRACKET);
            this->addToken(TokenType::TOKEN_LEFT_SQUARE_BRACKET, "[");
            this->next();

        } else if (c == ']') {
            this->checkBraceStack(c, false, TokenType::TOKEN_RIGHT_SQUARE_BRACKET, TokenType::TOKEN_LEFT_SQUARE_BRACKET);
            this->addToken(TokenType::TOKEN_RIGHT_SQUARE_BRACKET, "[");
            this->next();

        }else {
            this->next();

        }

    }

    if(!this->braceStack.empty()) {
        std::cout << "ERROR: Unclosed braces" << std::endl;
        exit(EXIT_FAILURE);
    }

}




std::vector<Token> Lexer::getTokens() {
    return this->tokens;
}

void Lexer::printTokens() {

}

void Lexer::printTokens(std::ostream &out) {

}

char Lexer::nextToken() {
    char c = this->source[this->counter];
    return c;
}

void Lexer::next() {
    this->counter++;

    if(this->source[this->counter] == '\n') {
        this->line++;
        this->pos = 0;
    }else{
        this->pos++;
    }

}

void Lexer::addToken(TokenType type, std::string value) {
    this->tokens.push_back(Token(type, value));

}

std::string Lexer::getUntil(char end, bool LFStop) {
    std::string result = "";
    while (this->source[this->counter] != end) {
        result += this->source[this->counter];
        this->next();
        if (LFStop && this->source[this->counter] == '\n') {
            break;
        }
    }
    return result;
}

void Lexer::checkBraceStack(char brace, bool isLeft, TokenType tokenType, TokenType correspondingToken) {
    if (isLeft) {
        this->braceStack.push(Token(tokenType, &""[brace]));
    } else {
        if (this->braceStack.size() == 0) {
            std::cout << "ERROR: Unexpected '" << brace << "' at " << this->line << ":" << this->pos <<std::endl;
            exit(EXIT_FAILURE);
        } else {
            //check if the last token is a left curly
            if (this->braceStack.top().getType() == correspondingToken) {
                this->braceStack.pop();
            } else {
                std::cout << "ERROR: Unexpected '" << brace << "' at " << this->line << ":" << this->pos <<std::endl;
                exit(EXIT_FAILURE);
            }

        }
    }

}

