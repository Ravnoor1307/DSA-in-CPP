/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_weighted_graph_representation.cpp
│
│ REAL-WORLD SCENARIO:
│ Google Maps me sirf road exists hai ya nahi enough nahi; distance/time/toll bhi chahiye. Weighted adjacency list neighbor ke saath weight store karta hai.
│
│ ASCII VISUAL / GRAPH STATE:
│ Weighted graph:
│ Ludhiana --100km-- Chandigarh
│ Ludhiana --320km-- Delhi
│ Chandigarh --250km-- Delhi
│
│ Representation:
│ vector<vector<pair<int,int>>> adj;
│ pair = {neighbor, weight}
│
│ adj[0] = {(1,100), (2,320)}
│ adj[1] = {(0,100), (2,250)}
│ adj[2] = {(0,320), (1,250)}
│
│ Dijkstra later isi representation ko use karega.

│
│ STEP-BY-STEP DRY RUN:
│ addEdge(0,1,100): adj[0].push_back({1,100}), adj[1].push_back({0,100})
│ addEdge(0,2,320): add both sides
│ Print city -> (neighbor, weight) pairs.

│
│ COMPLEXITY CALCULATION:
│ For V vertices and E undirected weighted edges:
│ adjacency outer vector V lists -> O(V).
│ each edge stored twice as pair(neighbor,weight) -> 2E pairs.
│ Space = O(V+E).
│ Build time = O(E) push operations.
│ Iterating all weighted edges in adjacency list visits 2E pairs -> O(V+E).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <string>
#include <climits>
using namespace std;

int main() {
    int V = 3;
    vector<vector<pair<int,int>>> adj(V);
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Road two-way, weight same.
    };

    addEdge(0, 1, 100);
    addEdge(0, 2, 320);
    addEdge(1, 2, 250);

    for (int u = 0; u < V; u++) {
        cout << u << ": ";
        for (auto edge : adj[u]) {
            cout << "(to " << edge.first << ", wt " << edge.second << ") ";
        }
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
0: (to 1, wt 100) (to 2, wt 320)
1: (to 0, wt 100) (to 2, wt 250)
2: (to 0, wt 320) (to 1, wt 250)
*/

