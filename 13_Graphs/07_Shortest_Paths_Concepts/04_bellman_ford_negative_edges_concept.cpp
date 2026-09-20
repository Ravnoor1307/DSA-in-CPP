/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_bellman_ford_negative_edges_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Some routes me cashback/discount negative cost jaisa ho sakta hai. Dijkstra negative edges handle nahi karta, Bellman-Ford repeated relaxation se negative edges and negative cycles detect karta hai.
│
│ ASCII VISUAL / DISTANCE STATE:
│ Directed weighted graph:
│ 0 --4--> 1
│ 0 --5--> 2
│ 1 --(-2)--> 2
│ 2 --3--> 3
│
│ Shortest from 0:
│ dist0=0
│ dist1=4
│ dist2=min(5, 4 + -2 = 2) -> 2
│ dist3=2+3=5
│
│ Bellman-Ford idea:
│ Repeat V-1 times:
│   for each edge u->v weight w:
│       if dist[u] + w < dist[v], update
│
│ Why V-1?
│ Shortest simple path can have at most V-1 edges.
│ Extra improvement on Vth round means negative cycle.

│
│ STEP-BY-STEP DRY RUN:
│ Initial dist: [0,INF,INF,INF]
│ Round 1:
│ edge0->1: dist1=4
│ edge0->2: dist2=5
│ edge1->2: dist2=2
│ edge2->3: dist3=5
│ Round 2 and 3 no changes.
│ Negative cycle check round: no improvement.

│
│ COMPLEXITY CALCULATION:
│ V vertices, E directed edges.
│ Outer relaxation runs V-1 rounds.
│ Each round scans E edges.
│ Work = (V-1)*E = VE - E -> O(VE).
│ Negative cycle check scans E once more -> O(E), total still O(VE).
│ Space = dist array O(V) + edge list O(E).

│ APPROACH COMPARISON TABLE:
│ | Shortest path | Graph type | Real-world analogy | Time | Space |
│ | BFS | unweighted | equal-cost roads | O(V+E) | O(V) |
│ | Dijkstra + PQ | non-negative weights | Google Maps time route | O((V+E)logV) | O(V+E) |
│ | Bellman-Ford | negative weights allowed | discount edges | O(VE) | O(V+E) |
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

struct Edge {
    int u, v, w;
};

int main() {
    int V = 4;
    vector<Edge> edges = {{0,1,4}, {0,2,5}, {1,2,-2}, {2,3,3}};
    const int INF_LOCAL = 1000000000;
    vector<int> dist(V, INF_LOCAL);
    dist[0] = 0;

    for (int round = 1; round <= V - 1; round++) {
        bool changed = false;
        cout << "Round " << round << "\n";
        for (auto e : edges) {
            if (dist[e.u] != INF_LOCAL && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w; // Negative edge bhi relax ho sakta hai.
                changed = true;
                cout << "  update dist[" << e.v << "] = " << dist[e.v] << "\n";
            }
        }
        if (!changed) break;
    }

    bool negativeCycle = false;
    for (auto e : edges) {
        if (dist[e.u] != INF_LOCAL && dist[e.u] + e.w < dist[e.v]) negativeCycle = true;
    }

    cout << "Final distances: ";
    for (int x : dist) cout << x << ' ';
    cout << "\nNegative cycle? " << (negativeCycle ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Round 1
  update dist[1] = 4
  update dist[2] = 5
  update dist[2] = 2
  update dist[3] = 5
Round 2
Final distances: 0 4 2 5
Negative cycle? NO
*/

