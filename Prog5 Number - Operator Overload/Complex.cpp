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
#include "Complex.h"

std::ostream& operator<<(std::ostream &os, const Complex &c) {
    os << "( " << c.real << " + " << c.imag << "i )";
    return os;
}

std::istream& operator>>(std::istream &is, Complex &c) {
    is >> c.real >> c.imag;
    return is;
}

Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(const Complex &a, const Complex &b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator*(const Complex &a, const Complex &b) {
    return Complex(a.real * b.real - a.imag * b.imag,
                 a.imag * b.real + a.real * b.imag);
}

Complex operator/(const Complex &a, const Complex &b) {
    double r = b.real * b.real + b.imag * b.imag; // length of b
    if(!r) { return Complex(0, 0); } // this is how we handle divided by 0
    return Complex((a.real * b.real + a.imag * b.imag) / r,
                 (a.imag * b.real - a.real * b.imag) / r);
}
