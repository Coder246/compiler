//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include <string>

class Expression {
private:
    virtual std::string getType() = 0;

};
#endif //COMPILER_EXPRESSION_H
