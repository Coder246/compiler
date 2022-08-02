//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_RETURN_H
#define COMPILER_RETURN_H


#include "../expressions/Expression.h"
#include "Statement.h"

class Return: public Statement {
private:
    Expression *expression;

    std::string getType() override;

};


#endif //COMPILER_RETURN_H
