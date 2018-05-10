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
#include <cmath> // for sqrt()

class FracN { // fraction number
public:
    friend std::ostream& operator<<(std::ostream&, const FracN&);
    friend std::istream& operator>>(std::istream&, FracN&);
    friend FracN operator+(const FracN&, const FracN&);
    friend FracN operator-(const FracN&, const FracN&);
    friend FracN operator*(const FracN&, const FracN&);
    friend FracN operator/(const FracN&, const FracN&);
    FracN(const int n, const int d) : num(n), denom(d) { simplify(); }
    FracN(const int n) : FracN(n, 1) { }
    FracN() : FracN(0, 1) { }
    operator int() { return num / denom; } // will truncate
private:
    int num; // numerator
    int denom; // denominator
    void simplify();
};

class CplxN { // complex number
public:
    friend std::ostream& operator<<(std::ostream&, const CplxN&);
    friend std::istream& operator>>(std::istream&, CplxN&);
    friend CplxN operator+(const CplxN&, const CplxN&);
    friend CplxN operator-(const CplxN&, const CplxN&);
    friend CplxN operator*(const CplxN&, const CplxN&);
    friend CplxN operator/(const CplxN&, const CplxN&);
    CplxN(const double r, const double i) : real(r), imag(i) { }
    CplxN(const double r) : CplxN(r, 0) { }
    CplxN() : CplxN(0, 0) { }
    operator int() { return sqrt(real*real + imag*imag); } // truncated length of complex vector
private:
    double real;
    double imag;
};

class Mod7N { // modulo 7 number
public:
    friend std::ostream& operator<<(std::ostream&, const Mod7N&);
    friend std::istream& operator>>(std::istream&, Mod7N&);
    friend Mod7N operator+(const Mod7N&, const Mod7N&);
    friend Mod7N operator-(const Mod7N&, const Mod7N&);
    friend Mod7N operator*(const Mod7N&, const Mod7N&);
    friend Mod7N operator/(const Mod7N&, const Mod7N&);
    Mod7N(const int i) : r((i % 7 + 7) % 7) { } // +7 to turn negative to positive
    Mod7N() : Mod7N(0) { }
    operator int() { return r; }
    static constexpr int inv[7] = {0, 1, 4, 5, 2, 3, 6}; // modulo inverse
private:
    int r; // can only be one of {0, 1, 2, 3, 4, 5, 6}
};
#endif
