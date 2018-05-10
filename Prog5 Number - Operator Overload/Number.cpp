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
#include "Number.h"

std::ostream& operator<<(std::ostream &os, const FracN &f) {
    os << "( " << f.num << " / " << f.denom << " )";
    return os;
}

std::ostream& operator<<(std::ostream &os, const CplxN &c) {
    os << "( " << c.real << " + " << c.imag << "i )";
    return os;
}

std::ostream& operator<<(std::ostream &os, const Mod7N &m) {
    os << m.r << " (mod 7)";
    return os;
}

std::istream& operator>>(std::istream &is, FracN &f) {
    is >> f.num >> f.denom;
    f.simplify();
    return is;
}

std::istream& operator>>(std::istream &is, CplxN &c) {
    is >> c.real >> c.imag;
    return is;
}

std::istream& operator>>(std::istream &is, Mod7N &m) {
    is >> m.r;
    m.r %= 7; m.r += 7; m.r %= 7;
    return is;
}

FracN operator+(const FracN &a, const FracN &b) {
    return FracN(a.num * b.denom + a.denom * b.num,
                 a.denom * b.denom);
}

CplxN operator+(const CplxN &a, const CplxN &b) {
    return CplxN(a.real + b.real, a.imag + b.imag);
}

Mod7N operator+(const Mod7N &a, const Mod7N &b) {
    return Mod7N(a.r + b.r);
}

FracN operator-(const FracN &a, const FracN &b) {
    return FracN(a.num * b.denom - a.denom * b.num,
                 a.denom * b.denom);
}

CplxN operator-(const CplxN &a, const CplxN &b) {
    return CplxN(a.real - b.real, a.imag - b.imag);
}

Mod7N operator-(const Mod7N &a, const Mod7N &b) {
    return Mod7N(a.r - b.r);
}

FracN operator*(const FracN &a, const FracN &b) {
    return FracN(a.num * b.num, a.denom * b.denom);
}

CplxN operator*(const CplxN &a, const CplxN &b) {
    return CplxN(a.real * b.real - a.imag * b.imag,
                 a.imag * b.real + a.real * b.imag);
}

Mod7N operator*(const Mod7N &a, const Mod7N &b) {
    return Mod7N(a.r * b.r);
}

FracN operator/(const FracN &a, const FracN &b) {
    return FracN(a.num * b.denom, a.denom * b.num);
}

CplxN operator/(const CplxN &a, const CplxN &b) {
    double r = b.real * b.real + b.imag * b.imag; // length of b
    return CplxN((a.real * b.real + a.imag * b.imag) / r,
                 (a.imag * b.real - a.real * b.imag) / r);
}

constexpr int Mod7N::inv[]; // redeclare to link

Mod7N operator/(const Mod7N &a, const Mod7N &b) {
    int i = Mod7N::inv[b.r]; // inverse of b: 1/b
    return Mod7N(a.r * i); // a/0 gives 0
}

int gcd(int a, int b) { return b == 0 ? abs(a) : gcd(abs(b), abs(a) % abs(b)); }

void FracN::simplify() {
    int d = gcd(this->num, this->denom);
    if(this->denom < 0) { d *= -1; }
    this->num /= d;
    this->denom /= d;
}

