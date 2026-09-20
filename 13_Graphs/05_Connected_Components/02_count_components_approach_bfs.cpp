/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_count_components_approach_bfs.cpp
│
│ REAL-WORLD SCENARIO:
│ City islands ko boat BFS se explore karo. Har unvisited island group milte hi component count badhao aur queue se poora group mark karo.
│
│ ASCII VISUAL / COMPONENT STATE:
│ Graph:
│ 0 -- 1 -- 2      3 -- 4      5 -- 6
│
│ BFS launch rule:
│ for each vertex i:
│   if unvisited[i]:
│       components++
│       BFS(i)
│
│ Queue states for component1:
│ q=[0]
│ pop0 push1 -> [1]
│ pop1 push2 -> [2]
│ pop2 -> []

│
│ STEP-BY-STEP DRY RUN:
│ i=0 unvisited -> components=1, BFS marks 0,1,2.
│ i=1,2 skip.
│ i=3 unvisited -> components=2, BFS marks 3,4.
│ i=5 unvisited -> components=3, BFS marks 5,6.

│
│ COMPLEXITY CALCULATION:
│ Outer loop V checks.
│ Across all BFS calls, each vertex pushed and popped once -> 2V.
│ Each undirected edge checked from both sides -> 2E.
│ Total = V + 2V + 2E = O(V+E).
│ Space = visited V + queue V worst = O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> disconnectedGraph() {
    vector<vector<int>> adj(7);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0, 1);
    add(1, 2);
    add(3, 4);
    add(5, 6);
    return adj;
}
int countComponentsBFS(const vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> visited(V, 0);
    int components = 0;

    for (int s = 0; s < V; s++) {
        if (visited[s]) continue;
        components++;
        cout << "BFS component " << components << ": ";
        queue<int> q;
        q.push(s);
        visited[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << ' ';
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v); // Same component ke neighbor queue me.
                }
            }
        }
        cout << "\n";
    }
    return components;
}

int main() {
    vector<vector<int>> adj = disconnectedGraph();
    cout << "Total components = " << countComponentsBFS(adj) << "\n";
    return 0;
}

/*
OUTPUT:
BFS component 1: 0 1 2
BFS component 2: 3 4
BFS component 3: 5 6
Total components = 3
*/

