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
#include <fstream>
#include <cstdlib> // exit status
#include <string>
#include "FriendBook.h"

void demoIn(); // demo sequential in file stream
void demoOut(); // demo sequential out file stream
void demoDataType(); // demo different data types in binary file
void testInteract(std::ofstream &f); // copy all terminal input into out file

int main() {
    demoIn();
    demoOut();
    demoDataType();
    return 0;
}

void demoIn() { // demo sequential in file stream
    std::ifstream in("in.txt", std::ios::in); // sequential file stream
    if(!in) { // operator! overloaded
        std::cerr << "Fail to open file 'in.txt'." << std::endl;
        exit(EXIT_FAILURE); // need to #include <cstdlib>
    }
    char c = 'X';
    std::cout << "get=" << in.tellg() << ", c=" << c << std::endl; // 0, X
    in >> c;
    std::cout << "get=" << in.tellg() << ", c=" << c << std::endl; // 1, a
    in.seekg(3L, std::ios::cur); // std::ios::beg by default
    std::cout << "get=" << in.tellg() << ", c=" << c << std::endl; // 4, a
    in >> c;
    std::cout << "get=" << in.tellg() << ", c=" << c << std::endl; // 5, e
}

void demoOut() { // demo sequential out file stream
    std::ofstream out("out.txt", std::ios::ate); // std::ios::out by default
    // std::ios::ate move to the end of file, can write anywhere in the file
    if(!out) {
        std::cerr << "Fail to open file 'out.txt'." << std::endl;
        exit(EXIT_FAILURE);
    }
    out.seekp(0L, std::ios::beg);
    std::cout << "put=" << out.tellp() << std::endl; // 0
    out << "12345";
    std::cout << "put=" << out.tellp() << std::endl; // 5
    out.seekp(1L, std::ios::beg);
    std::cout << "put=" << out.tellp() << std::endl; // 1
    out << "abc"; // 1abc5
    std::cout << "put=" << out.tellp() << std::endl; // 4
    // out.close(); // no need to call this since C++11
}

void demoDataType() { // demo different data types in binary file
    // std::fstream f("friend.dat", std::ios::in | std::ios::out | std::ios::binary);
    // int i = 5;
    // f.write(reinterpret_cast<const char*>(&i), sizeof(int));
    // f.close();
    FriendBook best("friend.dat");
    best.interactive();
}
