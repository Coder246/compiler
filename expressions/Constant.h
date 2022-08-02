//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_CONSTANT_H
#define COMPILER_CONSTANT_H


#include "Expression.h"

class Constant: public Expression {

public:
    int getValue() const;

    void setValue(int value);

public:
    explicit Constant(int value);

private:
    int value;
};


#endif //COMPILER_CONSTANT_H
