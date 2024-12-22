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

    //removes an edge and display again
    g.removeEdge(2, 3);
    cout << "\nAfter removing edge 2 -> 3:\n";
    g.displayGraph();

    return 0;
}