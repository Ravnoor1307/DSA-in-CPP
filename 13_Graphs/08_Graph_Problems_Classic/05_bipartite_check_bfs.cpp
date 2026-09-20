/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_bipartite_check_bfs.cpp
│
│ REAL-WORLD SCENARIO:
│ Students ko two teams me baantna hai such that friends/opponents same team me na aaye. Graph bipartite hai agar every edge ke endpoints different colors le sakte hain.
│
│ ASCII VISUAL / GRAPH-GRID STATE:
│ Graph even cycle:
│ 0 ----- 1
│ |       |
│ 3 ----- 2
│
│ 2-coloring:
│ color0 = 0
│ neighbors 1,3 = 1
│ neighbor of1: 2 = 0
│ edge2-3 has colors 0 and1 OK
│
│ If any edge u-v has color[u] == color[v], graph not bipartite.

│
│ STEP-BY-STEP DRY RUN:
│ queue [0], color=[0,-1,-1,-1]
│ pop0 -> color1=1, color3=1
│ pop1 -> color2=0
│ pop3 sees2 color0, different from3 color1 OK
│ pop2 done.
│ Bipartite YES.

│
│ COMPLEXITY CALCULATION:
│ BFS over all components.
│ Each vertex colored once -> O(V).
│ Each undirected edge checked twice -> O(E).
│ Time = O(V+E).
│ color O(V) + queue O(V) -> O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool isBipartite(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);
    for (int s = 0; s < V; s++) {
        if (color[s] != -1) continue;
        queue<int> q;
        q.push(s);
        color[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u]; // Neighbor opposite team/color.
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    cout << "Colors: ";
    for (int c : color) cout << c << ' ';
    cout << "\n";
    return true;
}

int main() {
    vector<vector<int>> graph(4);
    auto add = [&](int u, int v) { graph[u].push_back(v); graph[v].push_back(u); };
    add(0,1); add(1,2); add(2,3); add(3,0);
    cout << "Bipartite? " << (isBipartite(graph) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Colors: 0 1 0 1
Bipartite? YES
*/

