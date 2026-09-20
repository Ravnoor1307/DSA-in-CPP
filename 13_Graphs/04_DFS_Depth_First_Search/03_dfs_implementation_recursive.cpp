/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_dfs_implementation_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Recursion journey ka real power graph DFS me dikhta hai: call stack ek route hold karta hai, dead-end pe automatically backtrack ho jata hai.
│
│ ASCII VISUAL / STACK-RECURSION STATE:
│ Same 6-vertex graph:
│          0
│        /   \
│       1     2
│       |     |
│       3     4
│        \   /
│          5
│
│ Recursive DFS order from 0:
│ 0 -> 1 -> 3 -> 5 -> 4 -> 2
│
│ Call stack live states:
│ [dfs(0)]
│ [dfs(0), dfs(1)]
│ [dfs(0), dfs(1), dfs(3)]
│ [dfs(0), dfs(1), dfs(3), dfs(5)]
│ [dfs(0), dfs(1), dfs(3), dfs(5), dfs(4)]
│ [dfs(0), dfs(1), dfs(3), dfs(5), dfs(4), dfs(2)]
│ then returns one-by-one.

│
│ STEP-BY-STEP DRY RUN:
│ dfs(0): visit0, neighbor1 unvisited -> dfs(1)
│ dfs(1): visit1, neighbor3 unvisited -> dfs(3)
│ dfs(3): visit3, neighbor5 unvisited -> dfs(5)
│ dfs(5): visit5, neighbor4 unvisited -> dfs(4)
│ dfs(4): visit4, neighbor2 unvisited -> dfs(2)
│ dfs(2): all neighbors visited, return.

│
│ COMPLEXITY CALCULATION:
│ Every vertex enters dfs once -> V calls.
│ In each call, adjacency list scanned; total adjacency entries = 2E.
│ Time = O(V+E).
│ Recursion stack depth can be V in chain graph.
│ Space = visited O(V) + call stack O(V) + output O(V) = O(V).

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
void dfs(int u, const vector<vector<int>>& adj, vector<int>& visited, vector<int>& order) {
    visited[u] = 1;
    order.push_back(u); // Process on entry = preorder DFS.
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, order); // Recursion ek branch deep explore karta hai.
        }
    }
}

int main() {
    vector<vector<int>> adj = sampleGraph();
    vector<int> visited(6, 0), order;
    dfs(0, adj, visited, order);
    printOrder(order, "DFS recursive order");
    return 0;
}

/*
OUTPUT:
DFS recursive order: 0 1 3 5 4 2
*/

