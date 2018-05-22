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
#ifndef UNIT_H_
#define UNIT_H_
#include <string>

class Unit {
public:
    Unit(const std::string &); // initiate name
    Unit();
    virtual ~Unit();
    virtual void move() const = 0; // pure virtual function, must be override
    virtual void attack() const = 0;
protected: // can be accessed by derived class
    const std::string name;
};
#endif
