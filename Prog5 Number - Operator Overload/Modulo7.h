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
#ifndef MODULO_H_
#define MODULO_H_
#include <iostream>

class Modulo7 { // modulo 7 number
public:
    friend std::ostream& operator<<(std::ostream&, const Modulo7&);
    friend std::istream& operator>>(std::istream&, Modulo7&);
    friend Modulo7 operator+(const Modulo7&, const Modulo7&);
    friend Modulo7 operator-(const Modulo7&, const Modulo7&);
    friend Modulo7 operator*(const Modulo7&, const Modulo7&);
    friend Modulo7 operator/(const Modulo7&, const Modulo7&);
    Modulo7(const int i) : r((i % 7 + 7) % 7) { } // +7 to turn negative to positive
    Modulo7() : Modulo7(0) { }
    operator int() { return r; }
    static constexpr int inv[7] = {0, 1, 4, 5, 2, 3, 6}; // modulo inverse
private:
    int r; // can only be one of {0, 1, 2, 3, 4, 5, 6}
};
#endif
