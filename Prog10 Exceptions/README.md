## Project 10 Report
#### Objective
This program demonstrates exception handling.

#### Introduction
In `Rating` class, the static function `suggest` will give suggestion according to the age of the user and the rating system of gaming. The user age is calculated with user input and current system time.

Programs do not always act as expected, especially for those handle user input. With the try-catch block, we can handle the exception that occurs within the block, without terminating the program. We define a customized exception class `MyException` inheriting from `runtime_error`.
One try block can be followed by multiple catch blocks. They catch by the type of exception, acting similar to function overloading. At last, `catch(…)` will catch everything. In the catch block, `throw` will re-throw the caught exception again, passing on to the function called chain.
`cin` handling is always necessary, resetting the stream state after `badbit` or `failbit` is set, and dumping (ignoring) all the content that are already in the stream.

#### Overview of Key Elements
- try
- catch
- throw

#### Testing
Tested compilation used the compiler “clang++”:

```bash
clang++ -std=c++11 test.cpp MyException.cpp Rating.cpp -o test.exe
```

#### Project Files and Subdirectories
- test.cpp (testing program)
- MyException.h (header file for class ` MyException `) 
- MyException.cpp (source file for base class ` MyException `)
- Rating.h (header file for class `Rating`) 
- Rating.cpp (source file for base class `Rating`)
- report\_project10\_Cheng.docx (this report file)

#### Input Files
(Not applicable)

#### Output Files
(Not applicable)
