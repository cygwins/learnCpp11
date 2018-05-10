## Assignment 5 - Operator Overload

#### Program Description

This program implement three class `Fraction` (fraction numbers), `Complex` (complex numbers), and `Modulo7` (modulo 7 numbers). 

They all share the overloaded arithmetic operators (`+`, `-`, `*`, and `/`) according to the calculation rules, and the stream operators (`>>` and `<<`) for input and output.

They all have a conversion (cast) operator `int()`. `Fraction` will return the truncated integer of that fraction number, `Complex` will return the truncated length of the vector on complex plane representing that complex number, and `Modulo7` will return the modulo numer itself as an integer.


#### Output Demonstration
```cpp                                                                                  
Fraction fa(4, 12), fb(3, 6);
cout << fa << " + " << fb << " = " << fa + fb << endl;
Modulo7 ma(3), mb(5);
cout << ma << " / " << mb << " = " << ma / mb << endl;
Complex ca(3, 4), cb(0, 1);
cout << ca << " * " << cb << " = " << ca * cb << endl;
cout << "|" << ca << "| = " << int(ca) << endl;
```
output:

![demo](https://github.com/cygwins/learnCpp11/blob/master/Prog5%20Number%20-%20Operator%20Overload/demo.png?raw=true)
