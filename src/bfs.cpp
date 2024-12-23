#include "graph.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

//implements BFS traversal
void Graph::bfs(int start) const {
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from node " << start << ":\n";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        //explores neighbors
        for (const auto& [neighbor, _] : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << "\n";
}
