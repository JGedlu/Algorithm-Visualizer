#include "graph.h"
#include <algorithm>

using namespace std;

//constructor
//initializes adjacency list with nodes
Graph::Graph(int nodes) : numNodes(nodes) {
    adjList.resize(numNodes);
}

//adds an edge
void Graph::addEdge(int from, int to, int weight) {
    if (from < 0 || from >= numNodes || to < 0 || to >= numNodes) {
        cerr << "Error: Invalid node index.\n";
        return;
    }
    adjList[from].emplace_back(to, weight);
}

//removes an edge
void Graph::removeEdge(int from, int to) {
    if (from < 0 || from >= numNodes) {
        cerr << "Error: Invalid node index.\n";
        return;
    }
    auto& edges = adjList[from];
    edges.erase(remove_if(edges.begin(), edges.end(),
                               [to](const pair<int, int>& edge) { return edge.first == to; }),
                edges.end());
}

//displays the graph (for debugging)
void Graph::displayGraph() const {
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": ";
        for (const auto& edge : adjList[i]) {
            cout << "(" << edge.first << ", weight: " << edge.second << ") ";
        }
        cout << "\n";
    }
}