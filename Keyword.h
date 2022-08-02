//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_KEYWORD_H
#define COMPILER_KEYWORD_H


#include <string>

class Keyword {
public:
    Keyword(std::string value);
    std::string getValue();
    std::string toString();

private:
    std::string value;


};


#endif //COMPILER_KEYWORD_H
