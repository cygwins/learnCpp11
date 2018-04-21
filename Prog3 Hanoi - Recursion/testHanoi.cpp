/******
*
* Author: Yuge, Cheng. AKA: Andy
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 3
* Due date : April 25, 2018
*
******/
#include <iostream>
#include "Hanoi.h"

int main() {
    Hanoi puzzle;
    int n;
    while(std::cout << "Input disk number (1~42, 0 to quit):" << std::endl,
          std::cin >> n && n) {
        puzzle.setDiskNum(n);
        puzzle.guide();
    }
    return 0;
}
