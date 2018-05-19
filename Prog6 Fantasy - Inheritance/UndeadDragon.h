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
#ifndef UNDEADDRAGON_H_
#define UNDEADDRAGON_H_
#include "Undead.h"
#include "Dragon.h"

class UndeadDragon : public Dragon, public Undead {
public:
    UndeadDragon(const std::string &); // initiate name
    UndeadDragon();
    ~UndeadDragon();
    void move() const;
    void attack() const;
};
#endif
