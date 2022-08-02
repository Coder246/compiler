//
// Created by tim on 02.08.22.
//

#include "Constant.h"

Constant::Constant(int value) : value(value) {

}

int Constant::getValue() const {
    return value;
}

void Constant::setValue(int value) {
    Constant::value = value;
}

std::string Constant::getType() {
    return "Constant";
}
