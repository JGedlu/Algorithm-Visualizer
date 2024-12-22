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

    //displays the graph
    cout << "Initial Graph:\n";
    g.displayGraph();

    //runs Dijkstra's Algorithm
    cout << "\nRunning Dijkstra's Algorithm from node 0:\n";
    g.dijkstra(0);

    return 0;
}