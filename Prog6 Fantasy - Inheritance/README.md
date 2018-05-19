## Assignment 6 - Inheritance

#### Objective

This program demonstrates class inheritance and function overriding.

#### Introduction

In fantasy, creatures are categorized into different types, some types may overlap with others. The class `Unit` describes all movable being, class `Undead` and `Dragon` are derived from `Unit`, representing two kinds of unit. `UndeadDragon` is a unique type of creature that is `Dragon` and at the same time `Undead`. Each class has its own constructor and destructor explicitly. In the abstract class `Unit`, functions `move()` and `attack()` are virtual, and are override in the derived classes.

Implementation of this structure involves multiple inheritance. `UndeadDragon` derives from both `Undead` and `Dragon`. However, since both `Undead` and `Dragon` are derived from `Unit`, an instance of `UndeadDragon` will call the constructor of `Unit` twice, once by `Undead`, once by `Dragon`. This would lead to chaos, and the program could not compile. In order to keep only one copy of the base class `Unit`, the inheritance of `Undead` and `Dragon` are set to virtual inheritance.

```cpp
class Dragon : virtual public Unit {
```

Both `Undead` and `Dragon` have the override method `move()` and `attack()`. These method are set to pure virtual functions in class `Unit`:

```cpp
virtual void move() const = 0;
```
making `Unit` an abstract class. However, `UndeadDragon` may not know which parent method it should call, so they should be handled correctly. An undead dragon is a dragon, it does not “stagger”, it “flies”, so the `move()` method of `UndeadDragon` call `Dragon::move()`. But an undead dragon does not spit fire, it breathes frost, so we override the `attack()` method.

#### Overview of Key Elements

- 4 classes in total, 3 derived classes, one of which is derived from a derived class.

 ```mermaid
graph BT
UndeadDragon --> Undead
UndeadDragon --> Dragon
Undead --> Unit
Dragon --> Unit
```

- Explicit constructor and destructor in base and derived class, derived class constructor override base class constructor

  Each class has its own constructor, and the destructor of base class are set to virtual to let derived class override them.

 ```cpp
Virtual ~Unit();
```

- Two override member functions, with virtual declaration in base class and implementation in derived class:

 ```cpp
virtual void move();
virtual void attack();
```

-	Abstract class

 As mentioned above with the pure virtual member function, `Unit` is the abstract class.

#### Testing

Tested compilation used the compiler “clang++”:

```bash
clang++ -std=c++11 test.cpp Undead.cpp Dragon.cpp UndeadDragon.cpp -o test.exe
```

To test if the constructors are correctly override, simply declare and define an object of `UndeadDragon` and it will call the constructors of all four defined classes:

```cpp
Unit* u = &d;
u = new UndeadDragon;
```

To test if the virtual member function is override, use the base type pointer to call them:

```cpp
u->move();
u->attack();
```

Finally test the destructor:

```cpp
delete(u);
```

#### Summary

Inheritance and polymorphism are keys to object-oriented programming (OOP). This project demonstrate basic class inheritance technic including inheritance scope (public inheritance) and type (virtual inheritance), virtual functions, pure virtual functions, and override of constructors and destructors. The “diamond shape” inheritance issue is a bit difficult to address but still handled in this project.

#### Project Files and Subdirectories

- test.cpp (testing program)
- Unit.h (header file for base class `Unit`) 
- Unit.cpp (source file for base class `Unit`)
- Undead.h (header file for derived class `Undead`) 
- Undead.cpp (source file for derived class `Undead`)
- Dragon.h (header file for derived class `Dragon`) 
- Dragon.cpp (source file for derived class `Dragon`)
- UndeadDragon.h (header file for further derived class `UndeadDragon`) 
- UndeadDragon.cpp (source file for further derived class `UndeadDragon`)
- report\_project06\_Cheng.docx (this report file)

#### Input Files
(Not applicable)

#### Output Files
(Not applicable)
