/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_dfs_algorithm_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ File explorer me ek folder open karke uske andar ke subfolders me deeply jaate ho; finish hone par parent folder pe backtrack karte ho. DFS recursion isi call stack se hota hai.
│
│ ASCII VISUAL / STACK-RECURSION STATE:
│ DFS recursive algorithm:
│
│ dfs(node):
│     visited[node] = true
│     process node
│     for neighbor in adj[node]:
│         if not visited[neighbor]:
│             dfs(neighbor)
│
│ BFS queue ↔ DFS recursion:
│ BFS uses explicit queue for level order.
│ DFS uses call stack for depth order.
│
│ Recursion stack visual:
│ push dfs(0)
│ push dfs(1)
│ push dfs(3)
│ push dfs(5)
│ push dfs(4)
│ push dfs(2)
│ pop  dfs(2), dfs(4), dfs(5), dfs(3), dfs(1), dfs(0)

│
│ STEP-BY-STEP DRY RUN:
│ visited initially [0,0,0,0,0,0]
│ dfs0 -> [1,0,0,0,0,0]
│ dfs1 -> [1,1,0,0,0,0]
│ dfs3 -> [1,1,0,1,0,0]
│ dfs5 -> [1,1,0,1,0,1]
│ dfs4 -> [1,1,0,1,1,1]
│ dfs2 -> [1,1,1,1,1,1]

│
│ COMPLEXITY CALCULATION:
│ dfs called exactly once per vertex because visited blocks repeat calls.
│ Loop over adjacency lists scans total 2E entries for undirected graph.
│ Time = O(V+E).
│ Space = visited O(V) + recursion stack O(V) worst -> O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<vector<int>> sampleGraph() {
    vector<vector<int>> adj(6);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(2, 4);
    add(3, 5);
    add(4, 5);
    return adj;
}

void printOrder(const vector<int>& order, const string& label) {
    cout << label << ": ";
    for (int x : order) cout << x << ' ';
    cout << "\n";
}
void dfsAlgo(int u, const vector<vector<int>>& adj, vector<int>& visited) {
    visited[u] = 1; // Node ko mark karte hi cycle/revisit se bach gaye.
    cout << "Enter " << u << "\n";
    for (int v : adj[u]) {
        if (!visited[v]) dfsAlgo(v, adj, visited);
    }
    cout << "Exit " << u << "\n"; // Backtracking point.
}

int main() {
    vector<vector<int>> adj = sampleGraph();
    vector<int> visited(adj.size(), 0);
    dfsAlgo(0, adj, visited);
    return 0;
}

/*
OUTPUT:
Enter 0
Enter 1
Enter 3
Enter 5
Enter 4
Enter 2
Exit 2
Exit 4
Exit 5
Exit 3
Exit 1
Exit 0
*/

