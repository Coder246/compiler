//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include <vector>
#include "Token.h"
#include "expressions/Expression.h"
#include "expressions/Condition.h"

class Parser {
public:
    void parse(std::vector<Token> tokens);

private:
   void IFStatementParser(Token token);
   Condition* parseCondition(Token token);
   std::vector<Token> tokens;
   int counter;
   void next();
   Token getCurrentToken();
   Token * currentToken;


};


#endif //COMPILER_PARSER_H
