/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 10
* Due date : Jun 13, 2018
*
******/
#ifndef RATING_H_
#define RATING_H_
#include <exception>

class Rating {
public:
    Rating() = default;
    static int getAge();
    static void suggest();
};
#endif
