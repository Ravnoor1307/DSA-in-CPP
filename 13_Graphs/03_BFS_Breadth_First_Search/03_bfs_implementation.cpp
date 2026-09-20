/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_bfs_implementation.cpp
│
│ REAL-WORLD SCENARIO:
│ Computer network broadcast me source computer se signal level-by-level spread hota hai. Queue and visited array ka har step trace karke BFS samjho.
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
│ Adjacency list:
│ 0: 1 2
│ 1: 0 3
│ 2: 0 4
│ 3: 1 5
│ 4: 2 5
│ 5: 3 4
│
│ Queue full trace:
│ start q=[0], visited=[1,0,0,0,0,0]
│ pop0 -> push1 push2 -> q=[1,2]
│ pop1 -> push3       -> q=[2,3]
│ pop2 -> push4       -> q=[3,4]
│ pop3 -> push5       -> q=[4,5]
│ pop4 -> 5 visited   -> q=[5]
│ pop5 -> done        -> q=[]

│
│ STEP-BY-STEP DRY RUN:
│ Output order initially empty [].
│ pop0 -> order [0]
│ pop1 -> order [0,1]
│ pop2 -> order [0,1,2]
│ pop3 -> order [0,1,2,3]
│ pop4 -> order [0,1,2,3,4]
│ pop5 -> order [0,1,2,3,4,5]

│
│ COMPLEXITY CALCULATION:
│ Each vertex marked once, pushed once, popped once -> 3V constant operations.
│ Each undirected edge checked twice in adjacency list -> 2E checks.
│ Total = 3V + 2E -> O(V+E).
│ Space: visited V + queue at most V + output V -> O(V).

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
vector<int> bfs(const vector<vector<int>>& adj, int source) {
    vector<int> visited(adj.size(), 0), order;
    queue<int> q;
    visited[source] = 1;
    q.push(source);
    cout << "Initial "; printQueue(q);
    printVectorLine(visited, "Visited");

    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        cout << "Pop " << node << "\n";

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                visited[nbr] = 1;
                q.push(nbr);
                cout << "  push neighbor " << nbr << "\n";
            }
        }
        printQueue(q);
        printVectorLine(visited, "Visited");
    }
    return order;
}

int main() {
    vector<vector<int>> adj = sampleGraph();
    vector<int> order = bfs(adj, 0);
    printVectorLine(order, "BFS order");
    return 0;
}

/*
OUTPUT:
Initial Queue: [0]
Visited: [1, 0, 0, 0, 0, 0]
Pop 0
  push neighbor 1
  push neighbor 2
Queue: [1, 2]
Visited: [1, 1, 1, 0, 0, 0]
Pop 1
  push neighbor 3
Queue: [2, 3]
Visited: [1, 1, 1, 1, 0, 0]
Pop 2
  push neighbor 4
Queue: [3, 4]
Visited: [1, 1, 1, 1, 1, 0]
Pop 3
  push neighbor 5
Queue: [4, 5]
Visited: [1, 1, 1, 1, 1, 1]
Pop 4
Queue: [5]
Visited: [1, 1, 1, 1, 1, 1]
Pop 5
Queue: []
Visited: [1, 1, 1, 1, 1, 1]
BFS order: [0, 1, 2, 3, 4, 5]
*/

