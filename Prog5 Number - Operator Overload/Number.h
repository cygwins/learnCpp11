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
#ifndef NUMBER_H_
#define NUMBER_H_
#include <iostream>

class FracN {
public:
    FracN(const int n, const int d) : numerator(n), denominator(d) { }
    FracN(const int n) : numerator(n), denominator(1) { }
    FracN() : FracN(0, 1) { }
private:
    int numerator;
    int denominator;
};

class CplxN {
public:
    CplxN(const double r, const double i) : real(r), imag(i) { }
    CplxN(const double r) : CplxN(r, 0) { }
    CplxN() : CplxN(0, 0) { }
private:
    double real;
    double imag;
};

class Mod7N {
public:
    Mod7N(const int i) : r((i % 7 + 7) % 7) { }
    Mod7N() : Mod7N(0) { }
private:
    int r;
    static constexpr int inv[7] = {0, 1, 4, 5, 2, 3, 6}; // modulo inverse
};
#endif
