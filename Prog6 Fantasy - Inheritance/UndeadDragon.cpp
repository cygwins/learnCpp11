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
#include "UndeadDragon.h"

UndeadDragon::UndeadDragon(const std::string &s) : Unit(s) {
    std::cout << name << " reanimated." << std::endl;
}

UndeadDragon::UndeadDragon() : UndeadDragon("Viserion") {
    std::cout << name << " was dragged out from frozen lake." << std::endl;
}

UndeadDragon::~UndeadDragon() {
    std::cout << name << " has fallen." << std::endl;
}

void UndeadDragon::move() const {
    Dragon::move();
}

void UndeadDragon::attack() const {
    std::cout << name << " breathed frost." << std::endl;
}
