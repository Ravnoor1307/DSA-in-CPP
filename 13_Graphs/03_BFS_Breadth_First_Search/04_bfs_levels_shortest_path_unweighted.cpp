/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_bfs_levels_shortest_path_unweighted.cpp
│
│ REAL-WORLD SCENARIO:
│ Unweighted city map me har road ka cost 1 step hai. BFS wave level-wise chalta hai, isliye kisi city par pehli baar pahunchna shortest distance hota hai.
│
│ ASCII VISUAL / QUEUE STATE:
│ Graph:
│          0
│        /   \
│       1     2
│       |     |
│       3     4
│        \   /
│          5
│
│ Distances from 0:
│ dist[0]=0
│ dist[1]=1, dist[2]=1
│ dist[3]=2, dist[4]=2
│ dist[5]=3
│
│ Proof intuition:
│ BFS first processes all distance d nodes,
│ then discovers distance d+1 nodes.
│ So first time reached = shortest in unweighted graph.

│
│ STEP-BY-STEP DRY RUN:
│ q=[0], dist=[0,-1,-1,-1,-1,-1]
│ pop0 -> set dist1=1, dist2=1
│ pop1 -> set dist3=2
│ pop2 -> set dist4=2
│ pop3 -> set dist5=3
│ pop4 sees5 already has dist3, no update.

│
│ COMPLEXITY CALCULATION:
│ Each vertex distance assigned once -> V assignments.
│ Each adjacency entry scanned once -> 2E checks.
│ Total = O(V+E).
│ Space = dist V + queue V -> O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> sampleGraph() {
    int V = 6;
    vector<vector<int>> adj(V);
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);
    return adj;
}

void printQueue(queue<int> q) {
    cout << "Queue: [";
    bool first = true;
    while (!q.empty()) {
        if (!first) cout << ", ";
        cout << q.front();
        q.pop();
        first = false;
    }
    cout << "]\n";
}

void printVectorLine(const vector<int>& a, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < (int)a.size(); i++) cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    cout << "]\n";
}
vector<int> shortestUnweighted(const vector<vector<int>>& adj, int source) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1; // Pehli baar reach = shortest level.
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> adj = sampleGraph();
    vector<int> dist = shortestUnweighted(adj, 0);
    printVectorLine(dist, "Distance from 0");
    return 0;
}

/*
OUTPUT:
Distance from 0: [0, 1, 1, 2, 2, 3]
*/

