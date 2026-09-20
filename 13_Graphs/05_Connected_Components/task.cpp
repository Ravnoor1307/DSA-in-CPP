/*
REAL-WORLD SCENARIO:
Friend circles and map islands count karne ka practice lab.

TASKS easy -> hard:
1. Disconnected graph create karo.
2. BFS se components count karo.
3. DFS se components count karo.
4. 4x4 grid me islands count karo.
5. Max area island find karo.
6. Har component ke nodes print karo.
7. Complexity calculation comments me likho.

HINTS:
- Har unvisited vertex se traversal launch karo.
- Grid me 4 directions arrays use karo.
- visited matrix land ko dobara count hone se bachati hai.

STARTER CODE:
int components = 0;
for each node if unvisited launch BFS or DFS.

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countComponents(const vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    int comp = 0;
    for (int s = 0; s < (int)adj.size(); s++) {
        if (vis[s]) continue;
        comp++;
        queue<int> q;
        q.push(s); vis[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) if (!vis[v]) { vis[v] = 1; q.push(v); }
        }
    }
    return comp;
}

int main() {
    vector<vector<int>> adj(5);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(3,4);
    cout << "components=" << countComponents(adj) << "\n";
    return 0;
}

/*
OUTPUT:
components=3
*/
