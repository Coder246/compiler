//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include <vector>
#include "Token.h"
#include "expressions/Expression.h"
#include "expressions/Condition.h"
#include "statements/Statement.h"

class Parser {
public:
    void parse(std::vector<Token> tokens);

private:
   Statement * IFStatementParser(Token token);
   Condition* parseCondition(Token token);
   std::vector<Token> tokens;
   int counter;
   void next();
   Token getNextToken();
   Token getCurrentToken();
   Token * currentToken;
    std::vector<Statement*> parseUntilCurlyBracket(Token startToken,int endDept);
   int currentDepth;
   Statement * parseToken(Token token);
   Statement * RETURNStatementParser(Token token);

    Expression *parseExpression();

    Expression *parseAddSubExpr();
    Expression *parseMulDivExpr();
    Expression *parsePowExpr();
    Expression *parseAtomExpr();
};


#endif //COMPILER_PARSER_H
