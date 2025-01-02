#include "graph.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    Graph g(15); // Create a graph with 15 nodes

    // Normal case: A connected subgraph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 6);
    g.addEdge(3, 4, 2);

    // Cycle in the graph
    g.addEdge(4, 2, 7); // Back edge creates a cycle: 2 → 3 → 4 → 2

    // Long path
    g.addEdge(4, 5, 3);
    g.addEdge(5, 6, 4);
    g.addEdge(6, 7, 5);
    g.addEdge(7, 8, 6);

    // Disconnected nodes (10, 11, 12)
    g.addEdge(9, 10, 1);

    // Negative weights
    g.addEdge(8, 9, -2); // Invalid for Dijkstra's and A*, but worth testing

    // Cross edges and multiple paths
    g.addEdge(1, 7, 10);
    g.addEdge(7, 3, 8);

    // Nodes with no outgoing edges (13, 14)
    g.addEdge(12, 13, 3);

    // Coordinates for A*
    vector<pair<int, int>> coordinates = {
        {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4},  // Connected component
        {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9},  // Long path
        {10, 10}, {11, 11}, {12, 12}, {13, 13}, {14, 14} // Sparse/disconnected
    };

    cout << "Graph with 15 nodes:\n";
    g.displayGraph();

    // Dijkstra's Algorithm tests
    cout << "\nRunning Dijkstra's Algorithm from node 0:\n";
    g.dijkstra(0);

    cout << "\nRunning Dijkstra's Algorithm from node 7:\n";
    g.dijkstra(7);

    // Breadth-First Search tests
    cout << "\nRunning BFS starting from node 0:\n";
    g.bfs(0);

    cout << "\nRunning BFS starting from node 9 (disconnected component):\n";
    g.bfs(9);

    // A* Algorithm tests
    cout << "\nRunning A* Algorithm from node 0 to node 8:\n";
    g.astar(0, 8, coordinates);

    cout << "\nRunning A* Algorithm from node 0 to node 14 (unreachable):\n";
    g.astar(0, 14, coordinates);

    cout << "\nRunning A* Algorithm from node 4 to node 7 (through long path):\n";
    g.astar(4, 7, coordinates);

    // Edge case: Disconnected nodes
    cout << "\nRunning Dijkstra's Algorithm from node 10 (isolated component):\n";
    g.dijkstra(10);

    return 0;
}
