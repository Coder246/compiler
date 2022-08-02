//
// Created by tim on 02.08.22.
//

#include "Keyword.h"

Keyword::Keyword(std::string value) {
    this->value = value;
}

std::string Keyword::getValue() {
    return value;
}

std::string Keyword::toString() {
    return "Keyword: " + value;
}
