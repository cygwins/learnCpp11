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
#ifndef FRIENDBOOK_H_
#define FRIENDBOOK_H_
#include <iostream>
#include <fstream>
#include <string>
#include "Friend.h"

class FriendBook {
public:
    FriendBook(const std::string &bookName = "myFriends.dat");
    ~FriendBook();
    int enterChoice();
    void interactive();
    void newFriend();
    void updateFriend();
    void deleteFriend();
    void showFriend(std::ostream&, size_t = 0);
    size_t getFriendId(const char *const);
    enum Choices { SHOW = 1, NEW = 2, UPDATE = 3, DELETE = 4, END = 5};
private:
    std::string bookName;
    std::fstream book;
    void input(Friend&);
};
#endif
