//
// Created by tim on 03.08.22.
//

#ifndef COMPILER_TERM_H
#define COMPILER_TERM_H


#include "Expression.h"

class Term: public Expression {
    std::string getType() override;
};


#endif //COMPILER_TERM_H
