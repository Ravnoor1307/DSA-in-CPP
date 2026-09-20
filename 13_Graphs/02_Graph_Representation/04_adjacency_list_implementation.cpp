/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_adjacency_list_implementation.cpp
│
│ REAL-WORLD SCENARIO:
│ Network computers me each computer ke connected neighbors list form me store karna standard hai. Directed and undirected dono handle karne ke liye addEdge me flag rakho.
│
│ ASCII VISUAL / GRAPH STATE:
│ Graph standard representation:
│ class GraphList
│   vector<vector<int>> adj
│
│ addEdge(u,v,false):
│   u list me v add
│   v list me u add
│
│ addEdge(u,v,true):
│   only u list me v add
│
│ Undirected example:
│ 0: 1 2
│ 1: 0 3
│ 2: 0
│ 3: 1
│
│ Directed example 0->1, 0->2:
│ 0: 1 2
│ 1:
│ 2:

│
│ STEP-BY-STEP DRY RUN:
│ addEdge(0,1): adj[0]={1}, adj[1]={0}
│ addEdge(0,2): adj[0]={1,2}, adj[2]={0}
│ addEdge(1,3): adj[1]={0,3}, adj[3]={1}
│ Print each vertex list.

│
│ COMPLEXITY CALCULATION:
│ Graph initialization V empty lists -> O(V).
│ For E undirected edges, 2E push operations -> O(E).
│ Total build = O(V+E).
│ Space = V lists + 2E entries -> O(V+E).
│ Edge check by scanning adj[u] costs degree(u) -> O(degree(u)).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <string>
#include <climits>
using namespace std;

class GraphList {
    int V;
    vector<vector<int>> adj;
public:
    GraphList(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);       // u ke neighbor list me v add.
        if (!directed) adj[v].push_back(u); // Undirected me reverse bhi.
    }

    void print() const {
        for (int u = 0; u < V; u++) {
            cout << u << ": ";
            for (int v : adj[u]) cout << v << ' ';
            cout << "\n";
        }
    }
};

int main() {
    GraphList g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    cout << "Undirected adjacency list:\n";
    g.print();
    return 0;
}

/*
OUTPUT:
Undirected adjacency list:
0: 1 2
1: 0 3
2: 0
3: 1
*/

