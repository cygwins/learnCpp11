/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 6
* Due date : May 16, 2018
*
******/
#include <iostream>
#include "Unit.h"

Unit::Unit(const std::string &s) : name(s) {
    std::cout << name << " constructed." << std::endl;
}

Unit::Unit() : Unit("Token unit") {
    std::cout << name << " constructed by default." << std::endl;
}

Unit::~Unit() {
    std::cout << name << " destructed." << std::endl;
}

void Unit::move() const {
    std::cout << name << " moved." << std::endl;
}
