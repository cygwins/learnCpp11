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
#include "Dragon.h"

Dragon::Dragon(const std::string &s) : Unit(s) {
    std::cout << name << " hatched." << std::endl;
}

Dragon::Dragon() : Dragon("Dragonling") {
    std::cout << name << " hatched with extra care." << std::endl;
}

Dragon::~Dragon() {
    std::cout << name << " died." << std::endl;
}

void Dragon::move() const {
    std::cout << name << " flied." << std::endl;
}

void Dragon::attack() const {
    std::cout << name << " breathed flame." << std::endl;
}
