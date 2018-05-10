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
using std::cin;
using std::cout;
using std::endl;

int main() {
    FracN fa(4, 12), fb(3, 6);
    cout << fa << " + " << fb << " = " << fa + fb << endl;
    Mod7N ma(3), mb(5);
    cout << ma << " / " << mb << " = " << ma / mb << endl;
    CplxN ca(3, 4), cb(0, 1);
    cout << ca << " * " << cb << " = " << ca * cb << endl;
    cout << "|" << ca << "| = " << int(ca) << endl; 
    return 0;
}
