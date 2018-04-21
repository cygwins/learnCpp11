#ifndef HERO_H_
#define HERO_H_
#include <iostream>
#include <string>
using namespace std;
class Hero {
public:
    Hero() {
        // constructor without parameters
    }
    explicit Hero(string name) : heroName(name) {
        // constructor with one parameter
    }
    string getName() { // return heroName as a string
        return heroName;
    }
    int setName(string name) {
        if(name.empty()) { // check if input is an empty string
            cout << "[  Fail ] Hero name NOT set: Empty input" << endl;
            return -1;
        } else {
            heroName = name;
            cout << "[Success] Hero name set: " << heroName << endl;
            return 0;
        }
    }
    void displayName() {
        cout << "Hero name: " << heroName << endl;
    }

private:
    string heroName = "Unnamed";
};
#endif
