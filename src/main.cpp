#include "graph.h"

using namespace std;

int main() {
    //creates a graph with 5 nodes
    Graph g(5);

    //adds some edges
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 8);
    g.addEdge(4, 0, 7);
    g.addEdge(4, 2, 6);

    //node coordinates for heuristic calculation
    vector<pair<int, int>> coordinates = {
        {0, 0}, {1, 0}, {1, 1}, {2, 1}, {3, 1}
    };

    //displays the graph
    cout << "Initial Graph:\n";
    g.displayGraph();

    //removes an edge
    g.removeEdge(0, 2);

    //displays the graph
    cout << "\nAfter removing edge 2 -> 3:\n";
    g.displayGraph();

    //runs Dijkstra's Algorithm
    cout << "\nRunning Dijkstra's Algorithm from node 0:\n";
    g.dijkstra(0);

    //runs BFS
    cout << "\nRunning BFS starting from node 0:\n";
    g.bfs(0);

    //runs astar
    cout << "\nRunning A* Algorithm from node 0 to node 4:\n";
    g.astar(0, 4, coordinates);

    return 0;
}