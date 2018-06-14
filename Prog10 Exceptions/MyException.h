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
#ifndef MYEXCEPTION_H_
#define MYEXCEPTION_H_
#include <stdexcept>
#include <string>

class MyException : public std::runtime_error {
public:
    MyException();
    MyException(std::string);
};
#endif
