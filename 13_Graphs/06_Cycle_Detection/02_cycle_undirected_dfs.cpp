/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_cycle_undirected_dfs.cpp
│
│ REAL-WORLD SCENARIO:
│ Undirected road map me round route detect karna hai. DFS me visited neighbor agar immediate parent nahi hai, to alternate path exists, yani cycle.
│
│ ASCII VISUAL / STATE:
│ Undirected graph:
│       0
│      / \
│     1---2
│
│ DFS parent tracking:
│ dfs(0, parent=-1)
│  go 1, parent of1=0
│  from1 go2, parent of2=1
│  from2 neighbor0 visited and 0 != parent(1)
│  cycle found!
│
│ Why parent check?
│ Undirected edge 1--0 naturally back to parent dikhega.
│ Parent edge ko cycle nahi bolna.

│
│ STEP-BY-STEP DRY RUN:
│ visited [0,0,0]
│ dfs0 -> visited [1,0,0]
│ dfs1 -> visited [1,1,0]
│ dfs2 -> visited [1,1,1]
│ neighbor0 already visited and not parent -> return true.

│
│ COMPLEXITY CALCULATION:
│ DFS called once per vertex -> V.
│ Each undirected edge appears twice in adjacency list -> 2E checks.
│ Time = O(V+E).
│ visited O(V), recursion stack O(V) worst -> O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool dfsCycle(int u, int parent, const vector<vector<int>>& adj, vector<int>& visited) {
    visited[u] = 1;
    cout << "Visit " << u << ", parent " << parent << "\n";
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfsCycle(v, u, adj, visited)) return true;
        } else if (v != parent) {
            cout << "Visited neighbor " << v << " is not parent -> cycle\n";
            return true;
        }
    }
    return false;
}

bool hasCycleUndirectedDFS(const vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0);
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i] && dfsCycle(i, -1, adj, visited)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> adj(3);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(1,2); add(2,0);
    cout << "Cycle? " << (hasCycleUndirectedDFS(adj) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Visit 0, parent -1
Visit 1, parent 0
Visit 2, parent 1
Visited neighbor 0 is not parent -> cycle
Cycle? YES
*/

