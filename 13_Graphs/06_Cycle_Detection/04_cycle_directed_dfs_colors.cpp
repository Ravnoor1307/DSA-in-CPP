/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_cycle_directed_dfs_colors.cpp
│
│ REAL-WORLD SCENARIO:
│ Directed prerequisites me recursion path important hai. WHITE unvisited, GRAY currently processing, BLACK finished. GRAY node par wapas edge cycle prove karti hai.
│
│ ASCII VISUAL / STATE:
│ 3-color states:
│ WHITE = 0 = not visited
│ GRAY  = 1 = in current recursion stack
│ BLACK = 2 = fully processed
│
│ Directed graph:
│ 0 -> 1 -> 2
│ ^         |
│ |_________|
│ 2 -> 0 back edge to GRAY node
│
│ Color visual:
│ start colors [W,W,W,W]
│ enter0 [G,W,W,W]
│ enter1 [G,G,W,W]
│ enter2 [G,G,G,W]
│ edge2->0 sees GRAY -> cycle

│
│ STEP-BY-STEP DRY RUN:
│ dfs(0): color0=GRAY
│ dfs(1): color1=GRAY
│ dfs(2): color2=GRAY
│ neighbor0 color=GRAY, current path has 0.
│ Return true.

│
│ COMPLEXITY CALCULATION:
│ Each vertex changes WHITE->GRAY->BLACK once -> O(V).
│ Each directed edge scanned once -> O(E).
│ Time = O(V+E).
│ color array O(V), recursion stack O(V) -> O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool dfsColor(int u, const vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1; // GRAY: current recursion path me hai.
    cout << "Enter " << u << " -> GRAY\n";
    for (int v : adj[u]) {
        if (color[v] == 1) {
            cout << "Edge " << u << "->" << v << " hits GRAY -> cycle\n";
            return true;
        }
        if (color[v] == 0 && dfsColor(v, adj, color)) return true;
    }
    color[u] = 2; // BLACK: is node ki processing complete.
    cout << "Exit " << u << " -> BLACK\n";
    return false;
}

bool hasDirectedCycle(const vector<vector<int>>& adj) {
    vector<int> color(adj.size(), 0);
    for (int i = 0; i < (int)adj.size(); i++) {
        if (color[i] == 0 && dfsColor(i, adj, color)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> adj(4);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    cout << "Directed cycle? " << (hasDirectedCycle(adj) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Enter 0 -> GRAY
Enter 1 -> GRAY
Enter 2 -> GRAY
Edge 2->0 hits GRAY -> cycle
Directed cycle? YES
*/

