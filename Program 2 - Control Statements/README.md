## Assignment 2 - Control Statements

#### Program Discription

This program applies various C++ control statements by implementing a class `Bucket`, whose instances can hold a certain amount of water and can add to/substract from that amount. The class has a member function which allows user enter an interactive mode to manipulate on the object.

#### Checklist

Specification  |Implementation 
---------------|---------------
class          |`Bucket`
constructor(s) |`default` and init with volume
attribute 1    |`volume`
attribute 2    |`water`
attribute 3    |`color`
set function   |`paint` (sets `color`)
get function   |each attr has getter
display func   |`show`
`for`-loop     |in `replenish` & `empty`
`while`-loop   |in `manip`
`continue`     |in `while`-loop in `manip`
`if`-`else`    |validation in `fill` & `pour`
`switch`       |handle command in `manip`

#### File list

Bucket.h : class header

Bucket.cpp : class implementation

testBucket.cpp : drive program

README.md : this report

demo.png : output demo 

#### Output demonstration

![alt text](https://github.com/cygwins/learnCpp11/blob/master/Program%202%20-%20Control%20Statements/demo.png "demo")
