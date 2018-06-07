/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 9
* Due date : Jun 06, 2018
*
******/
#ifndef GRAPH_H_
#define GRAPH_H_
#include <fstream>
#include <string>
#include <map>

class Vertex {
public:
    friend class Graph;
    Vertex() = default;
    Vertex(int i) : id(i) { }
    inline int getId() { return id; }
private:
    int id;
    std::map<int, int> adjacent; // <adj_vertex_id, distance>
};

class Graph {
public:
    Graph() = default;
    Graph(std::ifstream &);
    inline int V() { return vertices.size(); }
    inline int E() { return edge; }
    std::string show();
    int shortest_dist(int start, int end, bool showPath = false);
private:
    int edge; // # of edges
    std::map<int, Vertex> vertices;
};
#endif
