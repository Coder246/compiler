//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_IFSTATEMENT_H
#define COMPILER_IFSTATEMENT_H


#include <vector>
#include "../expressions/Expression.h"
#include "../expressions/Condition.h"
#include "Statement.h"

class IFStatement: public Statement {

public:
    IFStatement(Condition *condition, std::vector<Statement*> ifBody, std::vector<Statement *> elseBody);

private:
    Condition *condition;
    std::vector<Statement*> ifBody;
    std::vector<Statement*> elseBody;

public:
    const std::vector<Statement *> &getIfBody() const;

    const std::vector<Statement *> &getElseBody() const;

private:
    std::string getType() override;


};


#endif //COMPILER_IFSTATEMENT_H
