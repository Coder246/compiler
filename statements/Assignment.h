//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_ASSIGNMENT_H
#define COMPILER_ASSIGNMENT_H


#include "../expressions/Variable.h"
#include "../expressions/Expression.h"
#include "Statement.h"

class Assignment: public Statement {
private:
    Variable *variable;
    Expression *expression;

    std::string getType() override;
};


#endif //COMPILER_ASSIGNMENT_H
