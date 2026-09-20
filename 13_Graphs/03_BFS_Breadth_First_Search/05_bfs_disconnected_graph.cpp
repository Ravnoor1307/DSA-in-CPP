/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_bfs_disconnected_graph.cpp
│
│ REAL-WORLD SCENARIO:
│ Social media me alag-alag friend circles ho sakte hain. Sirf ek source se BFS karoge to doosra circle miss ho jayega, isliye har unvisited node se BFS launch karo.
│
│ ASCII VISUAL / QUEUE STATE:
│ Disconnected graph:
│ Component 1: 0 -- 1 -- 2
│ Component 2: 3 -- 4
│ Component 3: 5 alone
│
│ All-components BFS:
│ visited initially [0,0,0,0,0,0]
│ i=0 unvisited -> BFS component 1: 0 1 2
│ i=1,2 already visited
│ i=3 unvisited -> BFS component 2: 3 4
│ i=5 unvisited -> BFS component 3: 5

│
│ STEP-BY-STEP DRY RUN:
│ Outer loop checks every vertex once.
│ BFS from 0 marks 0,1,2.
│ BFS from 3 marks 3,4.
│ BFS from 5 marks 5.
│ components count = 3.

│
│ COMPLEXITY CALCULATION:
│ Outer loop V checks.
│ Across all BFS launches, every vertex pushed/popped once -> O(V).
│ Every edge scanned twice for undirected -> O(E).
│ Total = O(V+E).
│ Space visited + queue = O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    auto addEdge = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0,1);
    addEdge(1,2);
    addEdge(3,4);

    vector<int> visited(V, 0);
    int components = 0;
    for (int s = 0; s < V; s++) {
        if (visited[s]) continue;
        components++;
        cout << "Component " << components << ": ";
        queue<int> q;
        q.push(s);
        visited[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << ' ';
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        cout << "\n";
    }
    cout << "Total components = " << components << "\n";
    return 0;
}

/*
OUTPUT:
Component 1: 0 1 2
Component 2: 3 4
Component 3: 5
Total components = 3
*/

