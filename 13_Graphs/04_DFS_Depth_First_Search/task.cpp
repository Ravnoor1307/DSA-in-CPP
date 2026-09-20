/*
REAL-WORLD SCENARIO:
Maze route explorer banana hai jo ek path deeply explore kare aur dead-end par backtrack kare.

TASKS easy -> hard:
1. Recursive DFS implement karo.
2. Same graph par DFS order print karo.
3. Call stack comments me draw karo.
4. Iterative DFS using stack implement karo.
5. BFS vs DFS table comments me likho.
6. Flood fill on 2D grid implement karo.
7. Disconnected graph ke all nodes DFS se visit karo.

HINTS:
- visited array zaruri hai.
- Recursive DFS natural stack use karta hai.
- Iterative DFS me stack<int> use karo.

STARTER CODE:
void dfs(int u, vector<vector<int>>& adj, vector<int>& visited) { }

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<int>& visited) {
    visited[u] = 1;
    cout << u << ' ';
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited); // Deep branch explore.
    }
}

int main() {
    vector<vector<int>> adj(6);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(0,2); add(1,3); add(2,4); add(3,5); add(4,5);
    vector<int> visited(6, 0);
    cout << "DFS: ";
    dfs(0, adj, visited);
    cout << "\n";
    return 0;
}

/*
OUTPUT:
DFS: 0 1 3 5 4 2
*/
