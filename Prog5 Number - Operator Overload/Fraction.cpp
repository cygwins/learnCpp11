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
#include "Fraction.h"

std::ostream& operator<<(std::ostream &os, const Fraction &f) {
    os << "( " << f.num << " / " << f.denom << " )";
    return os;
}

std::istream& operator>>(std::istream &is, Fraction &f) {
    is >> f.num >> f.denom;
    f.simplify();
    return is;
}

Fraction operator+(const Fraction &a, const Fraction &b) {
    return Fraction(a.num * b.denom + a.denom * b.num,
                 a.denom * b.denom);
}

Fraction operator-(const Fraction &a, const Fraction &b) {
    return Fraction(a.num * b.denom - a.denom * b.num,
                 a.denom * b.denom);
}

Fraction operator*(const Fraction &a, const Fraction &b) {
    return Fraction(a.num * b.num, a.denom * b.denom);
}

Fraction operator/(const Fraction &a, const Fraction &b) {
    return Fraction(a.num * b.denom, a.denom * b.num);
}

int gcd(int a, int b) { return b == 0 ? abs(a) : gcd(abs(b), abs(a) % abs(b)); }

void Fraction::simplify() { // eliminate common divider of numerator and denominator
    int d = gcd(this->num, this->denom);
    if(this->denom < 0) { d *= -1; }
    this->num /= d;
    this->denom /= d;
}

