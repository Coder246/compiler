//
// Created by tim on 02.08.22.
//

#include <iostream>
#include "Parser.h"
#include "expressions/Condition.h"
#include "expressions/Constant.h"
#include "Keywords.h"
#include "statements/IFStatement.h"

void Parser::parse(std::vector<Token> tokens) {

    this->tokens = tokens;

    while(this->tokens.size()>this->counter) {
        Token token = this->tokens.at(this->counter);

        IFStatement * top = static_cast<IFStatement *>(this->parseToken(token));
        top->getIfBody().at(0)->getType();

        this->counter++;
    }


}


//todo be less restrictive and parse expression universally
Statement * Parser::IFStatementParser(Token iftoken) {
    std::cout << "IFStatementParser" << std::endl;
    next();
    if(this->getCurrentToken().getType()!=TokenType::TOKEN_LEFT_BRACKET) std::cout << "Error: ( expected at " << getCurrentToken().getLine() << ":" << getCurrentToken().getPos() << std::endl;
    next();
    Condition* condition = this->parseCondition(this->getCurrentToken());
    next();
    if(this->getCurrentToken().getType()!=TokenType::TOKEN_RIGHT_BRACKET) std::cout << "Error: ) expected at " << getCurrentToken().getLine() << ":" << getCurrentToken().getPos() << std::endl;
    next();
    if(this->getCurrentToken().getType()!=TokenType::TOKEN_LEFT_CURLY) std::cout << "Error: { expected at " << getCurrentToken().getLine() << ":" << getCurrentToken().getPos() << std::endl;
    next();
    currentDepth++;
    std::vector<Statement*> ifBody = parseUntilCurlyBracket(this->getCurrentToken(),currentDepth);
    currentDepth--;
    if(this->getCurrentToken().getType()!=TokenType::TOKEN_RIGHT_CURLY) std::cout << "Error: } expected at " << getCurrentToken().getLine() << ":" << getCurrentToken().getPos() << std::endl;
    next();
    if(this->getCurrentToken().getValue()==KEYWORD_ELSE.getValue()) {
        std::cout << "ELSE detected" << std::endl;
        next();
        if(this->getCurrentToken().getType()!=TokenType::TOKEN_LEFT_CURLY) std::cout << "Error: { expected at " << getCurrentToken().getLine() << ":" << getCurrentToken().getPos() << std::endl;
        next();
        currentDepth++;
        std::vector<Statement *> elseBody = parseUntilCurlyBracket(this->getCurrentToken(),currentDepth);
        currentDepth--;
        if(this->getCurrentToken().getType()!=TokenType::TOKEN_RIGHT_CURLY) std::cout << "Error: } expected at " << getCurrentToken().getLine() << ":" << getCurrentToken().getPos() << std::endl;
        next();
        return new IFStatement(condition,ifBody, elseBody);
    }else{
        std::vector<Statement *> elseBody;
        return new IFStatement(condition,ifBody, elseBody);
    }

}

Condition *Parser::parseCondition(Token token) {

    //TODO implement variable stack
    //todo implement nested expressions


    Expression * leftExpression = nullptr;
    Expression * rightExpression = nullptr;
    Operation operation;

    if(token.getType() == TokenType::TOKEN_NUMBER) {
        leftExpression = new Constant(std::stoi(token.getValue()));
    }else{
        std::cout << "Error: " << token.getType() << " is not implemented yet " << token.getLine() << ":" << token.getPos() << std::endl;
        return nullptr;

    }

    next();

    switch (getCurrentToken().getType()) {
        case TOKEN_EQUAL:
            operation = Operation::EQUAL;
            break;
        case TOKEN_NOT_EQUAL:
            operation = Operation::NOT_EQUAL;
            break;
        case TOKEN_LESS_THAN:
            operation = Operation::LESS;
            break;
        case TOKEN_LESS_THAN_EQUAL:
            operation = Operation::LESS_OR_EQUAL;
            break;
        case TOKEN_GREATER_THAN:
            operation = Operation::GREATER;
            break;
        case TOKEN_GREATER_THAN_EQUAL:
            operation = Operation::GREATER_OR_EQUAL;
            break;
        default:
            std::cout << "Error: expected operation at " << getCurrentToken().getLine() << ":" << getCurrentToken().getPos() << std::endl;
            return nullptr;
            break;
    }
    next();

    if(token.getType() == TokenType::TOKEN_NUMBER) {
        rightExpression = new Constant(std::stoi(token.getValue()));
    }else{
        std::cout << "Error: " << token.getType() << " is not implemented yet " << token.getLine() << ":" << token.getPos() << std::endl;
        return nullptr;

    }

    return new Condition(leftExpression,rightExpression,operation);
}

void Parser::next() {
    this->counter++;
}

Statement * Parser::parseToken(Token token) {
    if(token.getType() == TokenType::TOKEN_KEYWORD) {

        if(token.getValue() == "if") {
           return this->IFStatementParser(token);
        }else{
            std::cout << "Error: " << token.getValue() << " is not implemented " << token.getLine() << ":" << token.getPos() << std::endl;
            next();

            return nullptr;
        }


    }else{
        std::cout << "Error: " << token.getValue() << " is not a statement " << token.getLine() << ":" << token.getPos() << std::endl;
        next();
        return nullptr;
    }

}

Token Parser::getCurrentToken() {
    //if counter is bigger than tokens size, return empty token
    if(this->counter>=this->tokens.size())
        return Token(TokenType::TOKEN_EOF,"",0,0);

    return this->tokens.at(this->counter);
}

std::vector<Statement*> Parser::parseUntilCurlyBracket(Token startToken,int endDepth) {
    std::vector<Statement*> statements;
    Token token = startToken;
    while(token.getType()!=TokenType::TOKEN_RIGHT_CURLY || currentDepth>endDepth) {
        Statement * statement = this->parseToken(token);
        statements.push_back(statement);
        token = this->getCurrentToken();


    }
    return statements;
}
