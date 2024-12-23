#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>
#include <string>
#include <iostream>

//graph with adjacency list class
class Graph {
public:
    //constructor
    //initializes graph
    Graph(int nodes = 0);

    //functions for the graph
    void addEdge(int from, int to, int weight = 1); //adds edge
    void removeEdge(int from, int to); //removes edge
    void displayGraph() const; //prints graph

    //algorithm functions
    void dijkstra(int source) const;
    void bfs(int start) const;
    void astar(int start, int goal, const std::vector<std::pair<int, int>>& coordinates) const;

private:
    int numNodes;
    std::vector<std::vector<std::pair<int, int>>> adjList; //adjacency list
};

#endif