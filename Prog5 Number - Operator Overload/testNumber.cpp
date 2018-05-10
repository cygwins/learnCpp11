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
#include "Complex.h"
#include "Modulo7.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
    Fraction fa(4, 12), fb(3, 6);
    cout << fa << " + " << fb << " = " << fa + fb << endl;
    Modulo7 ma(3), mb(5);
    cout << ma << " / " << mb << " = " << ma / mb << endl;
    Complex ca(3, 4), cb(0, 1);
    cout << ca << " * " << cb << " = " << ca * cb << endl;
    cout << "|" << ca << "| = " << int(ca) << endl; 
    return 0;
}
