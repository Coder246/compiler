//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_CONDITION_H
#define COMPILER_CONDITION_H

#include "Expression.h"

enum Operation {
    GREATER,
    LESS,
    EQUAL,
    NOT_EQUAL,
    GREATER_OR_EQUAL,
    LESS_OR_EQUAL,

};

class Condition: public Expression {
public:
    Condition(Expression *left, Expression *right, Operation operation);

    Expression *getLeft() const;

    void setLeft(Expression *left);

    Expression *getRight() const;

    void setRight(Expression *right);

    Operation getOperation() const;

    void setOperation(Operation operation);

private:
    Expression *left;
    Expression *right;
    Operation operation;

    std::string getType() override;

};


#endif //COMPILER_CONDITION_H
