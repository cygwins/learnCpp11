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
#include <stdexcept>
#include <string>
#include "MyException.h"

MyException::MyException() : std::runtime_error{"Mysterious error"} { }

MyException::MyException(std::string s) : std::runtime_error{s} { }

