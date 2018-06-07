## Assignment 9 - Standard Template Library

#### Objective
This program demonstrates containers, iterators, functions, and algorithms defined in the Standard Template Library (STL).

####Introduction
This program implements an algorithm to find the shortest path between two given vertices in a graph, using Dijkstra’s algorithm. The key to implement this algorithm `shortest_dist` is by using the container adaptor `queue` (First In First Out, FIFO) in the library to manage discovered but unvisited nodes. Each node in the queue are processed by recalculate the distance from starting vertex to its adjacent nodes. When the queue is empty, this algorithm ends and shortest distance with traceable path is given (could be not reachable). The function will print out path if the default parameter `showPath` is set to `true`.

```cpp
int shortest_dist(int start, int end, bool showPath = false);
```

The graph is represented in adjacency list. First two integers V and E, representing the total number of vertices and edges, then followed with E lines each with three integers V1, V2, and D, representing the edge from V1 to V2 with D distance. Note the vertex is 0-based.

Now take this graph as an example:

![demo](https://github.com/cygwins/learnCpp11/blob/master/Prog9%20Dijkstra%20-%20STL/Fig-11.jpg?raw=true "demo")

We can see the shortest path from 0 to 8 is 0 – 1 – 2 – 8 with total distance of 14, and the shortest distance from 3 to 5 is 11 via 2, despite that they are connected with an edge of 14.

#### Overview of Key Elements
- 5 (or more) STL functions:
  
  `std::map::size()`  
  `std::queue::empty()`  
  `std::queue::push()`  
  `std::queue::pop()`  
  `std::set::insert()`  
  `std::set::find()`  
  `std::set::end()`  

  To check if one element is presence in a set, we use the `find` function. If element not found, the function will return a iterator one pass the end of the set.

#### Testing
Tested compilation used the compiler “clang++”:

```bash
clang++ -std=c++11 main.cpp Graph.cpp -o main.exe
```

The tested graph is stored in file _in.txt_

#### Summary
Standard Template Library greatly helps C++ programmers to focus more on the program rather than data structure maintaining and general algorithm handling. Many sequential containers and associated containers implement generic algorithms like `sort` and so on. Mastering STL will make a C++ programmer more skillful and capable to tackle hard problems.

#### Project Files and Subdirectories
- main.cpp (testing program)
- Graph.h (header file for class `Graph`) 
- Graph.cpp (source file for base class `Graph`)
- in.txt (txt file to store the graph) 
- report\_project09\_Cheng.docx (this report file)

#### Input Files
- in.txt

#### Output Files
(Not applicable)
