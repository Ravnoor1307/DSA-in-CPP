/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_dijkstras_implementation_pq.cpp
│
│ REAL-WORLD SCENARIO:
│ Google Maps shortest time route compute karna hai. Har step par currently shortest known city priority queue se nikalo and roads relax karo.
│
│ ASCII VISUAL / DISTANCE STATE:
│ Weighted graph:
│       2        7
│  0 ------ 1 ------- 3
│   \       |         /
│    \4     |1       /1
│     \     |       /
│       2 ------- 4
│            3
│
│ Edges:
│ 0-1(2), 0-2(4), 1-2(1), 1-3(7), 2-4(3), 3-4(1)
│
│ Dist states:
│ init: [0,INF,INF,INF,INF]
│ pop0: [0,2,4,INF,INF]
│ pop1: [0,2,3,9,INF]
│ pop2: [0,2,3,9,6]
│ pop4: [0,2,3,7,6]
│ pop3: final [0,2,3,7,6]

│
│ STEP-BY-STEP DRY RUN:
│ pq start (0,0)
│ pop (0,0), relax 1 and 2.
│ pop (2,1), relax 2 better and 3.
│ pop (3,2), relax 4.
│ old (4,2) skipped because dist2 already 3.
│ pop (6,4), relax 3 better 7.
│ pop (7,3), done.

│
│ COMPLEXITY CALCULATION:
│ Adjacency list stores V lists and 2E weighted entries -> O(V+E) space.
│ Every relaxation can push into priority queue -> at most O(E) pushes.
│ Each push/pop costs O(log V) because heap size bounded by O(E), and logE <= log(V²)=2logV for simple graphs.
│ Total time = O((V+E) log V).
│ Space = dist O(V) + pq O(E) + adj O(V+E) = O(V+E).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int V, const vector<vector<pair<int,int>>>& adj, int source) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int d = top.first, u = top.second;
        if (d != dist[u]) continue; // Purani stale entry skip.
        cout << "Pop node " << u << " dist " << d << "\n";

        for (auto edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; // Relaxation: better route mil gaya.
                cout << "  update dist[" << v << "] = " << dist[v] << "\n";
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);
    auto add = [&](int u, int v, int w) { adj[u].push_back({v,w}); adj[v].push_back({u,w}); };
    add(0,1,2); add(0,2,4); add(1,2,1); add(1,3,7); add(2,4,3); add(3,4,1);
    vector<int> dist = dijkstra(V, adj, 0);
    cout << "Final distances: ";
    for (int x : dist) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Pop node 0 dist 0
  update dist[1] = 2
  update dist[2] = 4
Pop node 1 dist 2
  update dist[2] = 3
  update dist[3] = 9
Pop node 2 dist 3
  update dist[4] = 6
Pop node 4 dist 6
  update dist[3] = 7
Pop node 3 dist 7
Final distances: 0 2 3 7 6
*/

