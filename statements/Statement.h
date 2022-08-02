//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_STATEMENT_H
#define COMPILER_STATEMENT_H


#include <string>

class Statement {
public:
    virtual std::string getType() = 0;
};


#endif //COMPILER_STATEMENT_H
