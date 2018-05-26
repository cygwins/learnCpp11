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

size_t Friend::getId() { return id; }

void Friend::setName(const std::string &n) { name = n; }

std::string Friend::getName() { return name; }

void Friend::setBirthMonth(const int mon) { birthMonth = mon; }

std::string Friend::getBirthMonth() {
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

int Friend::getBirthDay() { return (birthDay > 0 && birthDay < 100) ? birthDay : 0; }

void Friend::setGender(const char sex) { gender = sex; }

char Friend::getGender() { return gender; }

void Friend::setHasPet(const bool pet) { hasPet = pet; }

bool Friend::getHasPet() { return hasPet; }

void Friend::setPower(const double pwr) { power = pwr; }

double Friend::getPower() { return power; }
