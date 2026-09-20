/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_cycle_undirected_bfs.cpp
│
│ REAL-WORLD SCENARIO:
│ Police road patrol BFS se round road detect karta hai. Queue me node ke saath parent rakho; visited neighbor parent nahi hua to cycle.
│
│ ASCII VISUAL / STATE:
│ Undirected graph:
│       0
│      / \
│     1---2
│
│ BFS parent tracking:
│ q=[(0,-1)]
│ pop0 -> push(1,0), push(2,0)
│ pop1 -> neighbor0 parent, ignore; neighbor2 already visited and not parent -> cycle
│
│ Queue state:
│ [(0,-1)] -> [(1,0),(2,0)] -> cycle while processing 1

│
│ STEP-BY-STEP DRY RUN:
│ visited after source0: [1,0,0]
│ push1 and push2: [1,1,1]
│ processing1 sees2 visited, 2 != parent0.
│ Cycle found.

│
│ COMPLEXITY CALCULATION:
│ Across all BFS components, every vertex queued once -> O(V).
│ Every undirected edge checked twice -> O(E).
│ Time = O(V+E).
│ Queue O(V), visited O(V) -> O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool hasCycleUndirectedBFS(const vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0);
    for (int start = 0; start < (int)adj.size(); start++) {
        if (visited[start]) continue;
        queue<pair<int,int>> q;
        q.push({start, -1});
        visited[start] = 1;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int u = cur.first, parent = cur.second;
            cout << "Pop node " << u << " parent " << parent << "\n";
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push({v, u});
                } else if (v != parent) {
                    cout << "Visited neighbor " << v << " not parent -> cycle\n";
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj(3);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(1,2); add(2,0);
    cout << "Cycle? " << (hasCycleUndirectedBFS(adj) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Pop node 0 parent -1
Pop node 1 parent 0
Visited neighbor 2 not parent -> cycle
Cycle? YES
*/

