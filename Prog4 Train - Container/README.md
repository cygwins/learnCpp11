## Assignment 4 - Container

#### Program Description
This program implement a container class `Train` consists of crew and `cabin`s which can hold many `Goods` or `Person` with `Title`. Member functions such as `append` and `show` return `*this`, so users can call them in sequence on an object like `trainObj.append(newCab).show(cout)`.

#### Checklist

Specification   |Implementation 
----------------|---------------
5 class         |`Train`, `Cabin`, `Goods`, `Person`, `Title`
container class |`Train`, `Cabin`
explicit creator|✓
destroyers      |~
initiation func |`init()`
default args    |✓
composed class  |`Train`, `Cabin`, `Person`
`*this` pointer |`append()`,`prepend()`
traverse ctainer|`totalValue()`

#### File list

- Train.h : class header
- Train.cpp : class implementation
- testTrain.cpp : drive program
- README.md : this report

#### Note

Compile with flag *VERBOSE* will show when destuctors are called:

```
clang++ -std=c++11 -D VERBOSE testTrain.cpp Train.cpp
```

Since I explicitly defined destructors, other default constructors such as move and copy are deprecated.