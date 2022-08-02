//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#include <vector>
#include <stack>
#include "Token.h"

class Lexer {
public:
    void lex(const std::string &input);
    std::vector<Token> getTokens();
    void printTokens();

    private:
        std::vector<Token> tokens;
        std::stack<Token> braceStack;
        int counter = 0;
        int length = 0;
        char nextChar();
        bool next();
        void addToken(TokenType type, std::string value);
        std::string moveCursorToChar(char end, bool LFStop = false);
        std::string moveCursorToNextString(std::string endString, bool LFStop = false);
        void checkBraceStack(char brace, bool isLeft, TokenType tokenType, TokenType correspondingToken);
        std::string source;
        int pos = 0;
        int line = 1;
        void skipLine();
        bool charIsDigit(char c);
        bool charIsAlpha(char c);

    char currentChar();

    bool charIsAlphaNumeric(char i);
};


#endif //COMPILER_LEXER_H
