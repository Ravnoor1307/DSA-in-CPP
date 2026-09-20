/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_shortest_path_unweighted_bfs.cpp
│
│ REAL-WORLD SCENARIO:
│ Unweighted city map me har road equal cost 1 hai. BFS source se level-wise chalta hai, aur parent array se actual shortest route reconstruct ho jata hai.
│
│ ASCII VISUAL / DISTANCE STATE:
│ Graph:
│          0
│        /   \
│       1     2
│       |     |
│       3     4
│        \   /
│          5
│
│ BFS from 0:
│ dist = [0,1,1,2,2,3]
│ parent possible:
│ parent[0]=-1
│ parent[1]=0, parent[2]=0
│ parent[3]=1, parent[4]=2
│ parent[5]=3
│
│ Reconstruct path 0 to 5:
│ 5 -> parent3 -> parent1 -> parent0 -> -1
│ reverse = 0 -> 1 -> 3 -> 5

│
│ STEP-BY-STEP DRY RUN:
│ q=[0]
│ pop0: set dist1=1 parent1=0, dist2=1 parent2=0
│ pop1: set dist3=2 parent3=1
│ pop2: set dist4=2 parent4=2
│ pop3: set dist5=3 parent5=3
│ pop4: 5 already discovered, no change

│
│ COMPLEXITY CALCULATION:
│ BFS visits each vertex once -> V.
│ Every undirected edge scanned twice -> 2E.
│ parent update happens once per vertex except source -> V-1.
│ Total = O(V+E).
│ Space = dist O(V) + parent O(V) + queue O(V) = O(V).

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

vector<vector<int>> sampleGraph() {
    vector<vector<int>> adj(6);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(0,2); add(1,3); add(2,4); add(3,5); add(4,5);
    return adj;
}

vector<int> reconstructPath(int target, const vector<int>& parent) {
    vector<int> path;
    for (int cur = target; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<vector<int>> adj = sampleGraph();
    int V = adj.size(), source = 0, target = 5;
    vector<int> dist(V, -1), parent(V, -1);
    queue<int> q;
    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1; // Pehli baar reach = shortest distance.
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << "Distance to " << target << " = " << dist[target] << "\n";
    vector<int> path = reconstructPath(target, parent);
    cout << "Path: ";
    for (int x : path) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Distance to 5 = 3
Path: 0 1 3 5
*/

