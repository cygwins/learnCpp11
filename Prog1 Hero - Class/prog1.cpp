/******
*
* Author: Yuge, Cheng. AKA: Andy
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 1
* Due date : April 11, 2018
* Discription :
*     This program implements a class "Hero", 
*     with constructors to the class, 
*     an attribute "name", and member functions
*     to set, get, and display the attribute.
*     Together with a driver program with examples
*     on to instantiate and use the class "Hero".
* Compiler : clang++ -std=c++11 prog1.cpp -o prog1.exe
*
******/
#include <iostream>
#include "Hero.h"
using namespace std;

int main() {
    string name = "Achilles"; // will be override by user input
    Hero myHero(name);
    cout << "I have a hero." << endl;
    myHero.displayName();

    Hero yourHero;
    cout << "Please input your hero name:" << endl;
    getline(cin, name);
    if(yourHero.setName(name) == 0) { // name successfully set
        cout << "Your hero now has a name: " << yourHero.getName() << endl;
    }
    return 0;
}
