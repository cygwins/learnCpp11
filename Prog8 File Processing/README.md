## Assignment 8 - File Processing

#### Objective
This program demonstrates file input/output processing.

#### Introduction
In this project, I demonstrate sequential access and random access file processing. Setting the flag of file while opening to `std::ios::in` allows the file stream to read from file. Setting the flag to `std::ios::ate` allows appending after the content in that file while still having access to previous content, but the file position pointer only moves to end when opening the file, not every time before writing as if what `std::ios::app` does; it does not discard the content already in that file as `std::ios::out`.

File streaming in and out are just like regular stream operator. In `demoIn` and `demoOut`, with the overloaded `<<` or `>> ` we can easily write to or read from a file. The `tellp` and `tellg` functions help us show the put pointer and get pointer position.

In `demoDataType` I showed how random access works in file. The key lines are:

```cpp
book.seekp(0L, std::ios::beg);
book.write(reinterpret_cast<char*>(&f), sizeof(Friend));
```

`seekp` and `seekg` change the position of putter and getter to desired place, the `beg` flag dictate how the position is calculated. After getting the pointer to correct places, `write` and `read` with the `reinterpret_cast<char*>` treats all types of data as if they are `char`, and with the help of `sizeof` they could be handle correctly.

#### Overview of Key Elements
- Reading, writing, updating using file stream.
- I/O formatted and unformatted at least 5 different data types.
  In `demoDataType` I showed how to read/write different data types including `int`, `bool` (formatted in literal), `char`, `std::string`, `double` (formatted in scientific notation), and custom defined class `Friend`, in binary mode.

#### Testing
Tested compilation used the compiler “clang++”:

```
clang++ -std=c++11 *.cpp
```

To test all the read/write/update, we interactively entering choices of operation within a loop.

#### Output Demo
![demo](https://github.com/cygwins/learnCpp11/blob/master/Prog8%20File%20Processing/demo.png?raw=true "demo")

#### Summary
File streaming and formatting are important for handling data continuously over a period of time without letting them vanish in cache after powering off the computer. While C++ does not format the file, we have to find a way to retrieve data that could vary in length of appearance in a reliable method. Random access and binary file I/O make it easy to do so if pointers are handled correctly, by fixing the place each data is taking up.

#### Project Files and Subdirectories
- fileDemo.cpp (demo driver program)
- Friend.h (header file for data type class `Friend`) 
- Friend.cpp (source file for data type class `Friend`)
- FriendBook.h (header file for file handling class `FriendBook`) 
- FriendBook.cpp (source file for file handling class `FriendBook`)
- in.txt (input file for sequential access file demo) 
- out.txt (output file for sequential access file demo)
- friend.dat (storage file for both input and output for random access file demo) 
- report_project08_Cheng.docx (this report file)

#### Input Files
- friend.dat
- in.txt

#### Output Files
- friend.dat
- out.txt
