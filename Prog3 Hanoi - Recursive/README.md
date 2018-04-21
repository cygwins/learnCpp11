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
array of ptr   |`*head[]`
set function   |set `diskNum`
get function   |get `diskNum`
display func   |show disks layout
recursive func |`solve`
duplicated id  |<sup>1</sup>
id visibility  |<sup>2</sup>

#### File list

Hanoi.h : class header

Hanoi.cpp : class implementation

testHanoi.cpp : drive program

README.md : this report

demo.png : output demo

#### Output demonstration

![demo]()

#### Note

To halt the recursive function at the place error occurs, this program adopt the method that passing the success code through the hierarchy. This could be rewrite with `try`-`catch` block, and program could halt directly without tracing along the recursive call all the way back to top.


