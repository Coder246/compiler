//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_IFSTATEMENT_H
#define COMPILER_IFSTATEMENT_H


#include "../expressions/Expression.h"
#include "../expressions/Condition.h"
#include "Statement.h"

class IFStatement: public Statement {

private:
    Condition *condition;
    Statement* *ifBody;
    Expression* *elseBody;

};


#endif //COMPILER_IFSTATEMENT_H
