#include "graph.h"
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

//Implements BFS traversal
void Graph::bfs(int start) const {
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    //Creates JSON object
    json jsonOutput;
    jsonOutput["algorithm"] = "BFS";
    jsonOutput["startNode"] = start;
    jsonOutput["traversalOrder"] = vector<int>();

    cout << "BFS traversal starting from node " << start << ":\n";

    bool hasTraversal = false; // Track if we visit any node

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        hasTraversal = true;

        //Explores neighbors
        for (const auto& [neighbor, _] : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }

        jsonOutput["traversalOrder"].push_back(node);
    }

    if (!hasTraversal) {
        cout << "No path found from node " << start << ".\n";
        jsonOutput["traversalOrder"] = "No path found";
    } else {
        cout << "\n";
    }

    //Writes JSON output to file
    ofstream outFile("bfs_output.json");
    if (outFile.is_open()) {
        outFile << jsonOutput.dump(4); // Pretty print
        outFile.close();
        cout << "BFS results saved to bfs_output.json\n";
    }
}
