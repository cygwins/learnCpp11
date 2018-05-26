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
#include <cstdlib>
#include <string>
#include "FriendBook.h"

FriendBook::FriendBook(const std::string &name) : bookName(name) {
    book.open(bookName, std::ios::in | std::ios::ate | std::ios::binary );
    if(!book) {
        std::cerr << "Fail to open file '" << bookName << "'." << std::endl;
        exit(EXIT_FAILURE); // need to #include <cstdlib>
    }
}

FriendBook::~FriendBook() {
    book.close();
}

int FriendBook::enterChoice() {
    std::cout << "Please enter choice:" << std::endl
              << "1 - show a friend in book" << std::endl
              << "2 - create a new friend" << std::endl
              << "3 - update a friend in book" << std::endl
              << "4 - delete a friend in book" << std::endl
              << "5 - quit interactive mode" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
}

void FriendBook::newFriend() {
}

void FriendBook::updateFriend() {
}

void FriendBook::deleteFriend() {
}

void FriendBook::showFriend(std::ostream, const Friend&) {
}

size_t FriendBook::getFriendId(const char *const) {
    return 0;
}
