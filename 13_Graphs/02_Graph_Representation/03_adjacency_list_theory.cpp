/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_adjacency_list_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Social media me har user ki apni friend list hoti hai. Sab possible users ke liye huge table rakhne ke bajay, actual friends ki list store karo.
│
│ ASCII VISUAL / GRAPH STATE:
│ Graph:
│ 0 -- 1
│ |    |
│ 2 -- 3
│
│ Adjacency List:
│ 0: 1, 2
│ 1: 0, 3
│ 2: 0, 3
│ 3: 1, 2
│
│ vector<vector<int>> adj;
│ adj[0] = {1,2}
│ adj[1] = {0,3}
│
│ Sparse graph me efficient:
│ V = 1000 users, E = 5 friendships
│ Matrix cells = 1000*1000 = 1,000,000
│ List storage approx V + 2E = 1000 + 10

│
│ STEP-BY-STEP DRY RUN:
│ Add undirected edge (0,1):
│ adj[0].push_back(1)
│ adj[1].push_back(0)
│
│ Neighbor iteration for node 0:
│ only adj[0] length = degree(0) scan hota hai.

│
│ COMPLEXITY CALCULATION:
│ Adjacency list vector has V lists.
│ Undirected graph stores each edge twice -> 2E neighbor entries.
│ Space = O(V + 2E) = O(V+E).
│ Add edge push operations constant amortized -> O(1).
│ Iterate neighbors of u -> O(degree(u)).

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
    int V = 4;
    vector<vector<int>> adj(V);
    vector<pair<int,int>> edges = {{0,1}, {0,2}, {1,3}, {2,3}};
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first); // Friendship two-way hai.
    }

    cout << "Adjacency list:\n";
    for (int u = 0; u < V; u++) {
        cout << u << ": ";
        for (int v : adj[u]) cout << v << ' ';
        cout << "\n";
    }
    return 0;
}

/*
OUTPUT:
Adjacency list:
0: 1 2
1: 0 3
2: 0 3
3: 1 2
*/

