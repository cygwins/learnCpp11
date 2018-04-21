## Assignment 3 - Recursive Function, Pointer, Array

#### Program Discription

This program applies recursive function, pointers and arrays to implement a class `Hanoi`. The class prints out step-by-step guide to solve a [Tower of Hanoi puzzle](https://en.wikipedia.org/wiki/Tower_of_Hanoi).

#### Checklist

Specification  |Implementation 
---------------|---------------
class          |`Hanoi`
constructor    |set disk number
array attr     |`disk[]`
pointer attr   |`*from` & `*to`
array of ptr   |`*head[]`<sup>1</sup>
set function   |set `diskNum`
get function   |get `diskNum`
display func   |show disks layout
recursive func |`solve`
duplicated id  |`init()`<sup>2</sup>
id visibility  |`solve(..)`<sup>2</sup>

1: `*head[]` is an array of pointer, each element pointing to an element of disk[], which is itself an array, so `*head[]` is an array of pointer to array. That pointed array is usually implicitly converted to the pointer to its first element, so `*head[]` is also an array of pointer to pointer.

2: In `init()`, identifier `d` is duplicated in different loop, each not visible to the scope of another. In the recursive function `solve(..)`, all parameters (`pegInit`, `pegGoal`, and `height`) are somehow passed into the next level of this function, inside the inner call, variables with same identifier (name) are created. However, those in the inner scope hide the outer ones, so the variable in caller is not visible in the called function scope.

#### File list

Hanoi.h : class header

Hanoi.cpp : class implementation

testHanoi.cpp : drive program

README.md : this report

demo.png : output demo

#### Output demonstration

![demo](https://github.com/cygwins/learnCpp11/blob/master/Prog3%20Hanoi%20-%20Recursion/demo.png?raw=true "demo")

#### Note

To halt the recursive function at the place error occurs, this program adopt the method that passing the success code through the hierarchy. This could be rewrite with `try`-`catch` block, and program could halt directly without tracing along the recursive call all the way back to top.


