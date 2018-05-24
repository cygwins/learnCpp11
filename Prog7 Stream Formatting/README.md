## Assignment 7 - Stream Formatting

#### Objective

This program demonstrates stream formatting.

#### Introduction

Stream formatting deals with how we interact with input and output method, including formatting `int`, `string`, and any other data type that can be expressed.

#### Overview of Key Elements

- Integer formatting

 Stream can be set to display integer in different base (oct, hex, dec), with descriptive base information toggled on and off, and in different alignment.

- Float formatting

  Float numbers and double numbers could be formatted in different display type (scientific, fixed), and in designed precision.

- String stream

 `istringstream` and `ostringstream` let us manipulate string in a stream manner. We can extract data from an `istringstream` like we do with `cin`, and `ostringstream`is helpful especially when we want to build the string gradually without printing it out at once.

#### Testing

Tested compilation used the compiler “clang++”:

```bash
clang++ -std=c++11 formatDemo.cpp -o demo.exe
```


#### Summary

With the help of library `<sstream>` and `iomanip` we can achieve the above formatting functions.

#### Project Files and Subdirectories

- formatDemo.cpp (demo program)
- report\_project07\_Cheng.docx (this report file)

#### Input Files
(Not applicable)

#### Output Files
(Not applicable)
