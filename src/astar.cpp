#include "graph.h"
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

//Euclidean distance function to calculate heuristic
double calculateHeuristic(int node, int goal, const vector<pair<int, int>>& coordinates) {
    auto [x1, y1] = coordinates[node];
    auto [x2, y2] = coordinates[goal];
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

//A* Algorithm Implementation
void Graph::astar(int start, int goal, const vector<pair<int, int>>& coordinates) const {
    vector<double> gCost(numNodes, numeric_limits<double>::infinity());
    vector<double> fCost(numNodes, numeric_limits<double>::infinity());
    vector<int> cameFrom(numNodes, -1);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> openSet;

    gCost[start] = 0;
    fCost[start] = calculateHeuristic(start, goal, coordinates);
    openSet.emplace(fCost[start], start);

    //Creates JSON object
    json jsonOutput;
    jsonOutput["algorithm"] = "A* Algorithm";
    jsonOutput["startNode"] = start;
    jsonOutput["goalNode"] = goal;
    jsonOutput["path"] = json::array();

    cout << "A* Pathfinding from node " << start << " to node " << goal << ":\n";

    bool pathFound = false; // Track if a path to the goal is found

    while (!openSet.empty()) {
        int current = openSet.top().second;
        openSet.pop();

        if (current == goal) {
            //Reconstructs path
            pathFound = true;
            vector<int> path;
            for (int node = goal; node != -1; node = cameFrom[node]) {
                path.push_back(node);
            }
            reverse(path.begin(), path.end());

            cout << "Path found: ";
            for (int node : path) {
                cout << node << " ";
                jsonOutput["path"].push_back(node);
            }
            cout << "\n";
            break;
        }

        //Explores neighbors
        for (const auto& [neighbor, weight] : adjList[current]) {
            double tentativeGCost = gCost[current] + weight;
            if (tentativeGCost < gCost[neighbor]) {
                cameFrom[neighbor] = current;
                gCost[neighbor] = tentativeGCost;
                fCost[neighbor] = gCost[neighbor] + calculateHeuristic(neighbor, goal, coordinates);
                openSet.emplace(fCost[neighbor], neighbor);
            }
        }
    }

    if (!pathFound) {
        cout << "No path found from node " << start << " to node " << goal << ".\n";
        jsonOutput["path"] = "No path found";
    }

    //Writes JSON output to file
    ofstream outFile("astar_output.json");
    if (outFile.is_open()) {
        outFile << jsonOutput.dump(4); // Pretty print
        outFile.close();
        cout << "A* results saved to astar_output.json\n";
    }
}