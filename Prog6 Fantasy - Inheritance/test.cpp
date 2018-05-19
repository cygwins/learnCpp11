/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 6
* Due date : May 16, 2018
*
******/
#include <iostream>
#include <string>
#include "Unit.h"
#include "Dragon.h"
#include "Undead.h"
#include "UndeadDragon.h"

using std::cout;
using std::endl;

int main() {
    Dragon d("Drogo");
    Unit* u = &d;
    u->move();
    u->attack();
    u = new UndeadDragon;
    u->move();
    u->attack();
    delete(u);
    return 0;
}
