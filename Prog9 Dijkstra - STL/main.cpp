/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 9
* Due date : Jun 06, 2018
*
******/
#include <iostream>
#include <fstream>
#include "Graph.h"

int main() {
    std::ifstream in("in.txt", std::ios::in);
    Graph G{in};
    std::cout << G.show();
    std::cout << "shortest distance between 3 and 5 is:" << std::endl;
    std::cout << G.shortest_dist(3, 5) << std::endl;
    std::cout << "shortest path (and distance) from 0 to 8 is:" << std::endl;
    std::cout << G.shortest_dist(0, 8, true) << std::endl;
    return 0;
}
