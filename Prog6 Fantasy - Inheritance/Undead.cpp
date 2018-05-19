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
#include "Undead.h"

Undead::Undead(const std::string &s) : Unit(s) {
    std::cout << name << " rised." << std::endl;
}

Undead::Undead() : Undead("Skeleton minion") {
    std::cout << name << " rised from a pile of corpses." << std::endl;
}

Undead::~Undead() {
    std::cout << name << " became inanimated." << std::endl;
}

void Undead::move() const { // overrides Unit::move()
    std::cout << name << " staggered." << std::endl;
}

void Undead::attack() const { // overrides Unit::attack()
    std::cout << name << " attacked." << std::endl;
}
