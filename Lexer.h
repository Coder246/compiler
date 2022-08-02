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
    void printTokens(std::ostream &out);

    private:
        std::vector<Token> tokens;
        std::stack<Token> braceStack;
        int counter = 0;
        int length = 0;
        char nextChar();
        void next();
        void addToken(TokenType type, std::string value);
        std::string getUntil(char end, bool LFStop = false);
        void checkBraceStack(char brace, bool isLeft, TokenType tokenType, TokenType correspondingToken);
        std::string source;
        int pos = 0;
        int line = 1;
        void skipLine();

    char currentChar();
};


#endif //COMPILER_LEXER_H
