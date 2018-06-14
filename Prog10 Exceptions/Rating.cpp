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
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
#include "Rating.h"
#include "MyException.h"

int Rating::getAge() {
    std::cout << "Please input your birthday (format: yyyy mm dd):" << std::endl;
    int year, month, day;
    std::cin >> year >> month >> day; 
    if(!std::cin) {
        std::cin.clear(); // clear first, ready for next input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // crucial
        // however, EOF cannot be dumped from the stream.
        throw MyException("Bad input format!");
    }
    if(month < 1 || month > 12 || day < 1 || day > 31) {
        throw "Wrong date!";
    }
    std::time_t t = std::time(0);   // get time now
    std::tm *now = std::localtime(&t);
    if(now->tm_year + 1900 == year && now->tm_mon + 1 == month && now->tm_mday == day)
        throw MyException(); // Easter egg
    return now->tm_year + 1900 - year
        - ((now->tm_mon + 1 < month || (now->tm_mon + 1 == month && now->tm_mday < day)) ? 1 : 0);
}

void Rating::suggest() {
    int age, maxAge = 100, maxTry = 15, attempt = 0;
    bool error;
    do {
        ++attempt;
        if(attempt > maxTry) {
            std::cout.clear();
            std::cout << "You've reach the maximum attempt. See you next time." << std::endl;
            std::cout << "\"EOF is forever, don't play with that.\"" << std::endl;
            std::cout << "           --- Sir Winston Leonard Spencer-Churchill" << std::endl;
            exit(EXIT_FAILURE);
        }
        error = false;
        try {
            age = getAge();
            if(age > maxAge) throw maxAge;
            if(age < 0) throw false;
        } catch (const std::exception& ex) {
            std::cout << "Standard exception: " << ex.what() << std::endl;
            error = true;
        } catch (const std::string &ex) {
            std::cout << "Old standard exception: " << ex << std::endl;
            error = true;
        } catch (const char* s) {
            std::cout << s << std::endl;
            error = true;
        } catch (const int i) {
            std::cout << "Please look for help of somebody under " << i << std::endl;
            error = true;
        } catch (const bool b) {
            std::cout << "That's not possible." << std::endl;
            error = true;
        } catch (...) { // catch everything!
            std::cout << "what?" << std::endl;
            throw; // left un-catched intendedly to terminate the method
        }
    } while(error);
    std::string US = "E (Everyone)", EU = "PEGI 3";
    if(age > 9) US += ", E10+ (Everyone 10+)";
    if(age > 12) US += ", T (Teen)";
    if(age > 16) US += ", M (Mature 17+)";
    if(age > 17) US += ", AO (Adults Only 18+)";
    if(age > 6) EU += ", PEGI 7";
    if(age > 11) EU += ", PEGI 12";
    if(age > 15) EU += ", PEGI 15";
    if(age > 17) EU += ", PEGI 18";
    std::cout << "You could enjoy games with following ratings:" << std::endl;
    std::cout << US << " (ESRB rating system)" << std::endl;
    std::cout << EU << " (PEGI rating system)" << std::endl;
}
