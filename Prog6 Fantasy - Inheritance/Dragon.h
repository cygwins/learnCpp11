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
#ifndef DRAGON_H_
#define DRAGON_H_
#include "Unit.h"

class Dragon : virtual public Unit {
public:
    Dragon(const std::string &); // initiate name
    Dragon();
    virtual ~Dragon();
    virtual void move() const;
    virtual void attack() const;
};
#endif
