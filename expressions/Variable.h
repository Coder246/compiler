//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_VARIABLE_H
#define COMPILER_VARIABLE_H


#include "Expression.h"
#include "Expression.h"

class Variable: public Expression {

private:
    std::string getType() override;

};


#endif //COMPILER_VARIABLE_H
