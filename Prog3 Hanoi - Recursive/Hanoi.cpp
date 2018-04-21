#include <iostream>
#include "Hanoi.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

Hanoi::Hanoi(int n) : diskNum(n) {
    init();
}

void Hanoi::setDiskNum(int n) {
    if(n < 0 || n > 42) {
        cout << "Invalid input! Disk number set to 3" << endl;
        n = 3;
    }
    diskNum = n;
    init(); // initialize when setting
}
void Hanoi::init() {
    // init pointer to peg top
    head[0] = disk[0] + diskNum; // equivalently &disk[0][0] + ..
    head[1] = disk[1];
    head[2] = disk[2];
    // init all disk to 0
    for(auto &p : disk) { // p is reference to peg array
        for(auto &d : p) { // d is ref to disk
            d = 0;
        }
    }
    // init all disks on peg A
    for(int i = 0; i < diskNum; ++i) {
        disk[0][i] = diskNum - i;
    }
    step = 0;
}

void Hanoi::display() {
    for(int p = 0; p < 3; ++p) {
        cout << "peg " << peg[p] << ":";
        for(int d = 0; disk[p][d]; ++d) {
            cout << " "<< disk[p][d];
        }
        cout << endl;
    }
}

int Hanoi::solve(int pegInit, int pegGoal, int height) {
    // solve: move top height disks at initial peg to goal peg
	if(height == 1) { // trivia case: moving only top disk
		return move(pegInit, pegGoal);
    }
	else {
        int pegOther = 3 - pegInit - pegGoal; // spare peg, 0 + 1 + 2 = 3
		if(solve(pegInit, pegOther, height - 1) == -1) { // move upper tower besides base
            return -1; // pass on failure
        }
		if(solve(pegInit, pegGoal, 1) == -1) { // move the base to goal
            return -1; // pass on failure
        }
		if(solve(pegOther, pegGoal, height - 1) == -1) { // move upper back
            return -1;
        } // could be rewrite with try-catch block
	}
    return 0;
}

int Hanoi::move(int pegInit, int pegGoal) {
    // move single top disk from initial peg to goal peg
    if(head[pegInit] == disk[pegInit] || *(head[pegInit] - 1) == 0) {
        cerr << "No disk to move on peg " << peg[pegInit] << endl;
        return -1;
    }
    // shout what to do first
    display();
    verbose(pegInit, pegGoal);
    from = --head[pegInit]; // head always point to next available top space
    to = head[pegGoal]++; // on top of top disk
    *to = *from;
    *from = 0;
    ++step;
    // wait for next move
    cout << "Press Enter to advance.." << endl;
    cin.get();
    return 0;
}

void Hanoi::verbose(int pegInit, int pegGoal) {
    // speak out the move()
    int d = *(head[pegInit] - 1);
    cout << "Move disk " << d << " from peg " << peg[pegInit]
         << " to peg " << peg[pegGoal] << endl;
}

void Hanoi::guide() {
    cin.get(); // flush previous input
    if(solve(0,2,diskNum) == -1) {
        cout << "Sorry! Let's start from beginning.." << endl;
    }
    else {
        display();
        cout << "Congratulations!" << endl
             << "You have solved the Tower of Hanoi puzzle" << endl
             << "with " << diskNum << " disk" << (diskNum > 1 ? "s":"")
             << " in " << step << " step" << (step > 1 ? "s":"") << "!" << endl;
    }
    init(); // clean up after
}
