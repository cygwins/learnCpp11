/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 4
* Due date : May 2, 2018
*
******/

#include <iostream>
#include <vector>
#include <string>
#include "Train.h"

int main() {
    Goods ore("Copper", 25, 13.2);
    Cabin SpaceX; // they rent a cabin
    SpaceX.addGoods(ore).addGoods(Goods("Tin", 38, 11.8));

    // this team is out for an away game
    std::vector<Person> Huskey{Person("Wilson"),
                               Person("Brew"),
                               Person("Brady")};
    Cabin WA(Huskey), spare;
    Person *mech = new Person("Jerry", Title("Mechanic"));
    Train myTrain("Hope");
    myTrain.addCrew(*mech).append(SpaceX).prepend(WA).append(spare).show(std::cout);
    delete mech;
    return 0;
}
