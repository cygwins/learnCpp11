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
    book.open(bookName, std::ios::in | std::ios::out | std::ios::binary); // ate does not work
    std::cout << !book << std::endl;
    if(!book) {
        std::cerr << "Fail to open file '" << bookName << "'." << std::endl;
        exit(EXIT_FAILURE); // need to #include <cstdlib>
    }
}

FriendBook::~FriendBook() {
    book.close();
}

void FriendBook::input(Friend &f) {
    std::string n;
    std::cout << "Name: ";
    std::cin >> n;
    f.setName(n);
    int mon, day;
    std::cout << "Birth Month: ";
    std::cin >> mon;
    f.setBirthMonth(mon);
    std::cout << "Birth Day: ";
    std::cin >> day;
    f.setBirthDay(day);
    char sex;
    std::cout << "Gender (1 char): ";
    std::cin >> sex;
    f.setGender(sex);
    char pet;
    std::cout << "Has a pet? (Y/N): ";
    std::cin >> pet;
    f.setHasPet(pet == 'Y' || pet == 'y' ? true : false);
    double pwr;
    std::cout << "Power: ";
    std::cin >> pwr;
    f.setPower(pwr);
    book.clear();
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
    book.clear(); // write may fail if badbit/failbit set
    size_t friendId = getFriendId("Enter new friend ID number"); // id to create
    std::cout << "g=" << book.tellg() << std::endl;
    book.seekg((friendId - 1) * sizeof(Friend), std::ios::beg); // file get-pointer to correct position
    std::cout << "g=" << book.tellg() << std::endl;
    Friend f;
    book.read(reinterpret_cast<char*>(&f), sizeof(Friend)); // check if id exist
    std::cout << "g=" << book.tellg() << std::endl;
    if(f.getId() == 0) { // create only if not exist before
        f.setId(friendId);
        input(f);// input
        // write
        std::cout << "p=" << book.tellp() << std::endl;
        book.seekp((friendId - 1) * sizeof(Friend), std::ios::beg);
        std::cout << "p=" << book.tellp() << std::endl;
        book.write(reinterpret_cast<char*>(&f), sizeof(Friend));
        std::cout << "p=" << book.tellp() << std::endl;
        showFriend(std::cout, friendId);
    }
    else {
        std::cerr << "#" << friendId << " friend already exist." << std::endl;
    }
}

void FriendBook::updateFriend() {
    book.clear();
    size_t friendId = getFriendId("Enter friend ID number to update");
    book.seekg((friendId - 1) * sizeof(Friend), std::ios::beg);
    Friend f;
    book.read(reinterpret_cast<char*>(&f), sizeof(Friend)); // check if id exist
    if(f.getId() != 0) { // update only if exist before
        showFriend(std::cout, friendId);
        input(f);
        book.seekp((friendId - 1) * sizeof(Friend), std::ios::beg);
        book.write(reinterpret_cast<char*>(&f), sizeof(Friend));
        showFriend(std::cout, friendId);
    }
    else {
        std::cerr << "#" << friendId << " friend does not exist." << std::endl;
    }
}

void FriendBook::deleteFriend() {
    book.clear();
    size_t friendId = getFriendId("Enter friend ID number to delete");
    book.seekg((friendId - 1) * sizeof(Friend), std::ios::beg);
    Friend f;
    book.read(reinterpret_cast<char*>(&f), sizeof(Friend)); // check if id exist
    if(f.getId() != 0) { // update only if exist before
        std::cout << f.getName() << " deleted." << std::endl;
        // input
        f.setId(0);
        book.seekp((friendId - 1) * sizeof(Friend), std::ios::beg);
        book.write(reinterpret_cast<char*>(&f), sizeof(Friend));
    }
    else {
        std::cerr << "#" << friendId << " friend does not exist." << std::endl;
    }
}

void FriendBook::showFriend(std::ostream &os, size_t friendId) {
    if(!friendId) { friendId = getFriendId("Enter friend ID number"); } // id to show
    book.seekg((friendId - 1) * sizeof(Friend), std::ios::beg); // file get-pointer to correct position
    Friend f;
    book.read(reinterpret_cast<char*>(&f), sizeof(Friend)); // check if id exist
    if(f.getId() != 0) {
        os << f.str();
    }
    else {
        std::cerr << "#" << friendId << " friend does not exist." << std::endl;
    }
}

size_t FriendBook::getFriendId(const char *const prompt) {
    int friendId;
    do {
        std::cout << prompt << " (1 ~ 100): ";
        std::cin >> friendId;
    } while(friendId < 1 || friendId > 100);
    return friendId;
}

void FriendBook::interactive() {
    int choice;
    while( (choice = enterChoice()) != END ) {
        switch(choice) {
            case SHOW:
                showFriend(std::cout);
                break;
            case NEW:
                newFriend();
                break;
            case UPDATE:
                updateFriend();
                break;
            case DELETE:
                deleteFriend();
                break;
            default:
                std::cerr << "Incorrect choice." << std::endl;
                break;
        }
    }
}
