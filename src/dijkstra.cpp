#include "graph.h"
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

//Implements Dijkstra's algorithm
void Graph::dijkstra(int source) const {
    vector<int> dist(numNodes, numeric_limits<int>::max());
    dist[source] = 0;

    //Min-heap priority queue
    //pair(distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, source);

    //Creates JSON object
    json jsonOutput;
    jsonOutput["algorithm"] = "Dijkstra's Algorithm";
    jsonOutput["startNode"] = source;
    jsonOutput["distances"] = json::object();

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        //If current distance is outdated, skip it
        if (currentDist > dist[currentNode]) continue;

        for (const auto& [neighbor, weight] : adjList[currentNode]) {
            int newDist = currentDist + weight;

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.emplace(newDist, neighbor);
            }
        }
    }

    //Outputs shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == numeric_limits<int>::max())
            cout << "Infinity";
        else
            cout << dist[i];
        cout << "\n";

        jsonOutput["distances"]["Node " + to_string(i)] =
            dist[i] == numeric_limits<int>::max() ? "Infinity" : std::to_string(dist[i]);
    }

    //Writes JSON output to file
    ofstream outFile("dijkstra_output.json");
    if (outFile.is_open()) {
        outFile << jsonOutput.dump(4); // Pretty print
        outFile.close();
        cout << "\nDijkstra's results saved to dijkstra_output.json\n";
    }
}
