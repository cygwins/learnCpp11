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
#ifndef UNDEAD_H_
#define UNDEAD_H_
#include "Unit.h"

class Undead : virtual public Unit {
public:
    Undead(const std::string &); // initiate name
    Undead();
    virtual ~Undead();
    virtual void move() const;
    virtual void attack() const;
};
#endif
