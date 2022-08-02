//
// Created by tim on 02.08.22.
//

#include "Condition.h"

Condition::Condition(Expression *left, Expression *right, Operation operation) : left(left), right(right),
                                                                                 operation(operation) {}

Expression *Condition::getLeft() const {
    return left;
}

void Condition::setLeft(Expression *left) {
    Condition::left = left;
}

Expression *Condition::getRight() const {
    return right;
}

void Condition::setRight(Expression *right) {
    Condition::right = right;
}

Operation Condition::getOperation() const {
    return operation;
}

void Condition::setOperation(Operation operation) {
    Condition::operation = operation;
}
