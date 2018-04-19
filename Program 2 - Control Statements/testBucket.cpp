/******
*
* Author: Yuge, Cheng. AKA: Andy
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 2
* Due date : April 18, 2018
*
******/
#include <iostream>
#include "Bucket.h"
int main() {
    std::cout << "A red bucket of 10 volume is created by default." << std::endl;
    Bucket b(10);
    b.manip();
    return 0;
}
