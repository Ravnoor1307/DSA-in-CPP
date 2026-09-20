/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_cycle_directed_kahns_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Course scheduling me jis course ka indegree 0 hai, wo pehle complete ho sakta hai. Agar cycle hai, kuch courses ka indegree kabhi 0 nahi hota.
│
│ ASCII VISUAL / STATE:
│ Kahn algorithm preview:
│ indegree[v] = prerequisites count.
│ Queue me all indegree 0 courses.
│ Pop course, reduce neighbors indegree.
│ If processed count < V, cycle exists.
│
│ Cycle graph:
│ 0 -> 1 -> 2 -> 0, and 3 isolated
│ indegree = [1,1,1,0]
│ q=[3]
│ process3, q=[]
│ processed=1, V=4
│ processed < V -> cycle
│
│ DAG ordering example:
│ 0 -> 1 -> 2
│ indegree [0,1,1]
│ order 0,1,2 possible.

│
│ STEP-BY-STEP DRY RUN:
│ Build indegree:
│ edge0->1: indeg1++
│ edge1->2: indeg2++
│ edge2->0: indeg0++
│ queue starts with only 3.
│ After processing 3, no edge reduced.
│ Nodes0,1,2 remain locked by cycle.

│
│ COMPLEXITY CALCULATION:
│ Build indegree scans all edges -> O(E).
│ Queue processes each vertex at most once -> O(V).
│ For popped vertices, outgoing edges scanned once total -> O(E).
│ Time = O(V+E).
│ Space = indegree O(V) + queue O(V) = O(V).

│ APPROACH COMPARISON TABLE:
│ | Graph type | Method | Real-world analogy | Key check | Time | Space |
│ | Undirected | DFS parent | road round trip | visited neighbor != parent | O(V+E) | O(V) |
│ | Undirected | BFS parent | patrol queue | visited neighbor != parent | O(V+E) | O(V) |
│ | Directed | DFS colors | current prerequisite chain | edge to GRAY | O(V+E) | O(V) |
│ | Directed | Kahn | course indegree unlock | processed < V | O(V+E) | O(V) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

bool hasCycleKahn(const vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) indegree[v]++; // Prerequisite count.
    }

    queue<int> q;
    for (int i = 0; i < V; i++) if (indegree[i] == 0) q.push(i);

    int processed = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        processed++;
        cout << "Take course " << u << "\n";
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    cout << "processed = " << processed << " out of " << V << "\n";
    return processed < V;
}

int main() {
    vector<vector<int>> adj(4);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    cout << "Cycle by Kahn? " << (hasCycleKahn(adj) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Take course 3
processed = 1 out of 4
Cycle by Kahn? YES
*/

