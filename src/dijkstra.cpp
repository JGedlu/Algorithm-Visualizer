#include "graph.h"
#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

//implements Dijkstra's algorithm
void Graph::dijkstra(int source) const {
    vector<int> dist(numNodes, numeric_limits<int>::max()); // Distance vector
    dist[source] = 0;

    //min-heap priority queue
    //pair(distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        //if current distance is outdated, skip it
        if (currentDist > dist[currentNode]) continue;

        //explores neighbors
        for (const auto& [neighbor, weight] : adjList[currentNode]) {
            int newDist = currentDist + weight;

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.emplace(newDist, neighbor);
            }
        }
    }

    //outputs shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == numeric_limits<int>::max())
            cout << "Infinity";
        else
            cout << dist[i];
        cout << "\n";
    }
}
