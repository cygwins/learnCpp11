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
#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>

class Fraction { // fraction number
public:
    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
    Fraction(const int n, const int d) : num(n), denom(d) { simplify(); }
    Fraction(const int n) : Fraction(n, 1) { }
    Fraction() : Fraction(0, 1) { }
    operator int() { return num / denom; } // will truncate
private:
    int num; // numerator
    int denom; // denominator
    void simplify(); // eliminate common divider of numerator and denominator
};
#endif
