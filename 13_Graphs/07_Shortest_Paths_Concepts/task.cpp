/*
REAL-WORLD SCENARIO:
Google Maps mini route planner build karna hai: unweighted route, weighted time route, and negative discount edge concept.

TASKS easy -> hard:
1. BFS shortest path unweighted implement karo.
2. parent array fill karo.
3. Path reconstruct and print karo.
4. Weighted graph pair<neighbor,weight> se represent karo.
5. Dijkstra using min priority_queue implement karo.
6. Stale priority queue entry skip karo.
7. Bellman-Ford relaxation concept implement karo.

HINTS:
- BFS distance starts with -1.
- Dijkstra pq pair is {dist,node}.
- Bellman-Ford runs V-1 rounds.

STARTER CODE:
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> bfsDist(const vector<vector<int>>& adj, int src) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    dist[src] = 0; q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> adj(4);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(1,2); add(0,3);
    vector<int> dist = bfsDist(adj, 0);
    cout << "dist to 2=" << dist[2] << "\n";
    return 0;
}

/*
OUTPUT:
dist to 2=2
*/
