/*
REAL-WORLD SCENARIO:
Graph classic interview practice lab: infection, courses, paint, regions, teams, and word game.

TASKS easy -> hard:
1. Rotten oranges multi-source BFS solve karo.
2. Course schedule using Kahn algorithm solve karo.
3. Flood fill DFS/BFS implement karo.
4. Surrounded regions boundary DFS trick implement karo.
5. Bipartite BFS 2-coloring implement karo.
6. Word ladder BFS concept implement karo.
7. Har problem ka grid/queue/color state comments me draw karo.

HINTS:
- Rotten: all sources push at time 0.
- Course: indegree array use karo.
- Bipartite: color[v] = 1 - color[u].
- Word ladder: one character replace and dictionary lookup.

STARTER CODE:
queue<pair<int,int>> q;
vector<int> color(V, -1);

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bipartite(const vector<vector<int>>& g) {
    vector<int> color(g.size(), -1);
    for (int s = 0; s < (int)g.size(); s++) {
        if (color[s] != -1) continue;
        queue<int> q; q.push(s); color[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) { color[v] = 1 - color[u]; q.push(v); }
                else if (color[v] == color[u]) return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> g(4);
    auto add = [&](int u, int v) { g[u].push_back(v); g[v].push_back(u); };
    add(0,1); add(1,2); add(2,3); add(3,0);
    cout << "bipartite=" << (bipartite(g) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
bipartite=YES
*/
