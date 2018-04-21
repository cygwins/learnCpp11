#ifndef HANOI_H_
#define HANOI_H_

class Hanoi {
public:
    Hanoi(int n = 3);
    void setDiskNum(int);
    int getDiskNum();
    void display(); // print all disks
    void init(); // initialize
    void guide(); // print step-by-step guide to solve the puzzle

private:
    // solve: move top height disks at initial peg to goal peg
    int solve(int pegInit, int pegGoal, int height);

    // move single top disk from initial peg to goal peg
    int move(int pegInit, int pegGoal);

    // speak out the move()
    void verbose(int pegInit, int pegGoal);

    int diskNum; // total disk number
    int disk[3][42]; // disks on three pegs
    int *head[3]; // point to top of each peg
    int *from, *to; // for moving disk
    int step; // record steps to finish
    const char peg[3] = {'A', 'B', 'C'}; // peg name
};
#endif
