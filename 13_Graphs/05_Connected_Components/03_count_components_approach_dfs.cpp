/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_count_components_approach_dfs.cpp
│
│ REAL-WORLD SCENARIO:
│ Friend circle me ek person se recursively friends ke friends tak jao. DFS poora connected group mark kar dega; har new unvisited launch new component hai.
│
│ ASCII VISUAL / COMPONENT STATE:
│ Graph:
│ 0 -- 1 -- 2      3 -- 4      5 -- 6
│
│ DFS component trace:
│ dfs(0) -> dfs(1) -> dfs(2) -> return
│ dfs(3) -> dfs(4) -> return
│ dfs(5) -> dfs(6) -> return
│
│ Components = 3

│
│ STEP-BY-STEP DRY RUN:
│ Outer loop finds s=0 unvisited -> component1.
│ DFS marks 0,1,2.
│ Then s=3 unvisited -> component2.
│ Then s=5 unvisited -> component3.

│
│ COMPLEXITY CALCULATION:
│ Each vertex receives dfs call once -> V.
│ Each adjacency entry scanned once -> 2E for undirected.
│ Outer loop V checks.
│ Total = O(V+E).
│ Space = visited O(V) + recursion stack O(V) worst -> O(V).

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
void dfs(int u, const vector<vector<int>>& adj, vector<int>& visited) {
    visited[u] = 1;
    cout << u << ' ';
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited); // Same island/friend circle deep explore.
    }
}

int countComponentsDFS(const vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0);
    int components = 0;
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i]) {
            components++;
            cout << "DFS component " << components << ": ";
            dfs(i, adj, visited);
            cout << "\n";
        }
    }
    return components;
}

int main() {
    vector<vector<int>> adj = disconnectedGraph();
    cout << "Total components = " << countComponentsDFS(adj) << "\n";
    return 0;
}

/*
OUTPUT:
DFS component 1: 0 1 2
DFS component 2: 3 4
DFS component 3: 5 6
Total components = 3
*/

