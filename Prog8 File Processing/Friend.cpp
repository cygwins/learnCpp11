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
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Friend.h"

Friend::Friend(const size_t i,
    const std::string &n,
    const int mon,
    const int day,
    const char sex,
    const bool pet,
    const double pwr) :
    id(i),
    name(n),
    birthMonth(mon),
    birthDay(day),
    gender(sex),
    hasPet(pet),
    power(pwr) { }

void Friend::setId(const size_t i) { id = i; }

size_t Friend::getId() const { return id; }

void Friend::setName(const std::string &n) { name = n; }

std::string Friend::getName() const { return name; }

void Friend::setBirthMonth(const int mon) { birthMonth = mon; }

std::string Friend::getBirthMonth() const {
    switch(birthMonth) {
        case 1: return "Jan";
        case 2: return "Feb";
        case 3: return "Mar";
        case 4: return "Apr";
        case 5: return "May";
        case 6: return "Jun";
        case 7: return "Jul";
        case 8: return "Aug";
        case 9: return "Sep";
        case 10: return "Oct";
        case 11: return "Nov";
        case 12: return "Dec";
        default: return "???";
    }
}

void Friend::setBirthDay(const int day) { birthDay = day; }

int Friend::getBirthDay() const { return (birthDay > 0 && birthDay < 100) ? birthDay : 0; }

void Friend::setGender(const char sex) { gender = sex; }

char Friend::getGender() const { return gender; }

void Friend::setHasPet(const bool pet) { hasPet = pet; }

bool Friend::getHasPet() const { return hasPet; }

void Friend::setPower(const double pwr) { power = pwr; }

double Friend::getPower() const { return power; }

std::string Friend::str() const {
    std::ostringstream s;
    s << std::left
      << std::setw(3) << "#"
      << std::setw(15) << "Name"
      << std::setw(7) << "Gender"
      << std::setw(10) << "Birthday"
      << std::setw(10) << "Pet"
      << std::setw(10) << "Power" << std::endl;
    s << std::setw(3) << id
      << std::setw(15) << name
      << std::setw(7) << gender
      << std::setw(5) << getBirthMonth() << std::setw(5) << birthDay
      << std::setw(10) << std::boolalpha << hasPet << std::noboolalpha
      << std::setw(11) << std::scientific << std::setprecision(2)
                       << std::right << power << std::endl;
    return s.str();
}
