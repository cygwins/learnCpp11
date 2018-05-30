/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 8
* Due date : May 30, 2018
*
******/
#ifndef FRIEND_H_
#define FRIEND_H_
#include <iostream>
#include <sstream>
#include <string>

class Friend {
public:
    // constructor
    Friend(const size_t i = 0,
           const std::string &n = "???",
           const int mon = 0,
           const int day = 0,
           const char sex = '?',
           const bool pet = false,
           const double pwr = 0.0);

    // setters and getters
    void setId(const size_t);
    size_t getId() const;
    void setName(const std::string&);
    std::string getName() const;
    void setBirthMonth(const int);
    std::string getBirthMonth() const;
    void setBirthDay(const int);
    int getBirthDay() const;
    void setGender(const char);
    char getGender() const;
    void setHasPet(const bool);
    bool getHasPet() const;
    void setPower(const double);
    double getPower() const;
    std::string str() const; // output everything

private:
    size_t id;
    std::string name;
    int birthMonth, birthDay;
    char gender;
    bool hasPet;
    double power;
};
#endif
