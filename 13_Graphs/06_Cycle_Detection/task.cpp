/*
REAL-WORLD SCENARIO:
Course prerequisite system me impossible cycle detect karna hai.

TASKS easy -> hard:
1. Undirected cycle detection DFS parent se implement karo.
2. Undirected cycle detection BFS parent se implement karo.
3. Directed cycle detection colors se implement karo.
4. Kahn indegree processed-count concept implement karo.
5. Disconnected graph handle karo.
6. Deadlock/courses analogy comments me explain karo.

HINTS:
- Undirected: visited neighbor != parent => cycle.
- Directed: GRAY node par edge => cycle.
- Kahn: processed count < V => cycle.

STARTER CODE:
bool dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& vis);

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
using namespace std;

bool dfsUndirected(int u, int parent, const vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfsUndirected(v, u, adj, vis)) return true;
        } else if (v != parent) {
            return true; // Parent ke alawa visited neighbor round route hai.
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj(3);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(1,2); add(2,0);
    vector<int> vis(3, 0);
    cout << "cycle=" << (dfsUndirected(0, -1, adj, vis) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
cycle=YES
*/
