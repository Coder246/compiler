//
// Created by tim on 02.08.22.
//

#include <iostream>
#include "Parser.h"
#include "expressions/Condition.h"
#include "expressions/Constant.h"

void Parser::parse(std::vector<Token> tokens) {

    this->tokens = tokens;

    while(this->tokens.size()>this->counter) {
        Token token = this->tokens.at(this->counter);

        if(token.getType() == TokenType::TOKEN_KEYWORD) {

            if(token.getValue() == "if") {
                this->IFStatementParser(token);
            }


        }else{
            std::cout << "Error: " << token.getValue() << " is not a statement " << token.getLine() << ":" << token.getPos() << std::endl;
        }


        this->counter++;
    }


}

void Parser::IFStatementParser(Token iftoken) {
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
    //TODO parse code
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

Token Parser::getCurrentToken() {
    return this->tokens.at(this->counter);
}
