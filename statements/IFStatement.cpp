//
// Created by tim on 02.08.22.
//

#include "IFStatement.h"

IFStatement::IFStatement(Condition *condition, std::vector<Statement *> ifBody, std::vector<Statement *> elseBody) {
    this->condition = condition;
    this->ifBody = ifBody;
    this->elseBody = elseBody;

}

const std::vector<Statement *> &IFStatement::getIfBody() const {
    return ifBody;
}

const std::vector<Statement *> &IFStatement::getElseBody() const {
    return elseBody;
}

std::string IFStatement::getType() {
    return "IF";
}
