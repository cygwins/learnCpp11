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
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
// #include <utility> // make_pair
#include <queue>
#include <set>
#include <map>
#include "Graph.h"

std::string Graph::show() {
    std::ostringstream os;
    os << "V: " << V() << std::endl << "E: " << E() << std::endl;
    for(auto &v : vertices) {
        for(auto &d : v.second.adjacent) {
            if(v.first <= d.first) { // [v1 - v2: dist] only showed once
                os << v.first << " - " << d.first << ": " << d.second << std::endl;
            }
        }
    }
    return os.str();
}

Graph::Graph(std::ifstream &in) {
    int V, E;
    in >> V >> E;
    edge = E;
    int v1, v2, d;
    for(int i = 0; i < V; ++i) {
        // vertices.insert(std::make_pair(i, Vertex{i})); // need #include <utility>
        vertices[i] = Vertex{i};
    }
    for(int i = 0; i < E; ++i) {
        in >> v1 >> v2 >> d;
        vertices[v1].adjacent[v2] = d;
        vertices[v2].adjacent[v1] = d;
    }
}

int Graph::shortest_dist(int start, int end, bool showPath) { // Dijkstra's Algorithm
    std::map<int, int> dist; // dist[v] = d(start, v)
    std::map<int, int> prev; // prev[v]: previous node on shortest path from start to v
    std::queue<int> q; // vertices to visit
    std::set<int> visited; // each vertex can only be visited once
    dist[start] = 0;
    q.push(start);
    visited.insert(start);
    while(!q.empty()) {
        int u = q.front();
        for(auto &v : vertices[u].adjacent) {
            if(dist.find(v.first) == dist.end() || dist[v.first] > dist[u] + v.second) {
                // update if v.first is not reached or has a shorter path
                dist[v.first] = dist[u] + v.second;
                prev[v.first] = u;
                // std::cout << "dist[" << v.first << "] = " << dist[v.first] << std::endl;
            }
            if(visited.find(v.first) == visited.end()) { // v.first has not been visited yet
                q.push(v.first);
                visited.insert(v.first); // mark as visited
                // std::cout << v.first << " in queue." << std::endl;
            }
        }
        q.pop();
    }
    if(dist.find(end) != dist.end()) {
        if(showPath) {
            for(int p = end; p != start; p = prev[p]) {
                std::cout << p << " <- ";
            }
            std::cout << start << std::endl;
        }
        return dist[end];
    }
    else { // no path
        if(showPath) {
            std::cout << "No Path!" << std::endl;
        }
        return -1;
    }
}
