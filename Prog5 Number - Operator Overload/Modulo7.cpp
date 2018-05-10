/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 5
* Due date : May 9, 2018
*
******/
#include <iostream>
#include "Modulo7.h"

std::ostream& operator<<(std::ostream &os, const Modulo7 &m) {
    os << m.r << " (mod 7)";
    return os;
}

std::istream& operator>>(std::istream &is, Modulo7 &m) {
    is >> m.r;
    m.r %= 7; m.r += 7; m.r %= 7;
    return is;
}

Modulo7 operator+(const Modulo7 &a, const Modulo7 &b) {
    return Modulo7(a.r + b.r);
}

Modulo7 operator-(const Modulo7 &a, const Modulo7 &b) {
    return Modulo7(a.r - b.r);
}

Modulo7 operator*(const Modulo7 &a, const Modulo7 &b) {
    return Modulo7(a.r * b.r);
}

constexpr int Modulo7::inv[]; // redeclare to link

Modulo7 operator/(const Modulo7 &a, const Modulo7 &b) {
    int i = Modulo7::inv[b.r]; // inverse of b: 1/b
    return Modulo7(a.r * i); // a/0 gives 0
}
