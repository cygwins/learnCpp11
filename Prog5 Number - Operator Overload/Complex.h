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
#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
#include <cmath> // for sqrt()

class Complex { // complex number
public:
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);
    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);
    Complex(const double r, const double i) : real(r), imag(i) { }
    Complex(const double r) : Complex(r, 0) { }
    Complex() : Complex(0, 0) { }
    operator int() { return sqrt(real*real + imag*imag); } // truncated length of complex vector
private:
    double real;
    double imag;
};
#endif
