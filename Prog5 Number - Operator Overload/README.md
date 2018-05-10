## Assignment 5 - Operator Overload

#### Program Description

This program implement three class `FracN` (fraction numbers), `CplxN` (complex numbers), and `Mod7N` (modulo 7 numbers). 

They all share the overloaded arithmetic operators (`+`, `-`, `*`, and `/`) according to the calculation rules, and the stream operators (`>>` and `<<`) for input and output.

They all have a conversion (cast) operator `int()`. `FracN` will return the truncated integer of that fraction number, `CplxN` will return the truncated length of the vector on complex plane representing that complex number, and `Mod7N` will return the modulo numer itself as an integer.


#### Output Demonstration
```cpp                                                                                  
FracN fa(4, 12), fb(3, 6);
cout << fa << " + " << fb << " = " << fa + fb << endl;
Mod7N ma(3), mb(5);
cout << ma << " / " << mb << " = " << ma / mb << endl;
CplxN ca(3, 4), cb(0, 1);
cout << ca << " * " << cb << " = " << ca * cb << endl;
cout << "|" << ca << "| = " << int(ca) << endl;
```
output:

![demo](https://github.com/cygwins/learnCpp11/blob/master/Prog5%20Number%20-%20Operator%20Overload/demo.png?raw=true)