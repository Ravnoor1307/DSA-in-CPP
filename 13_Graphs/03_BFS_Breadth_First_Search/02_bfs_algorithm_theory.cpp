/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_bfs_algorithm_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ WhatsApp forward ko repeat message loop se bachana hai. Isliye queue ke saath visited array maintain karte hain: jo user receive kar chuka, use dobara enqueue nahi karte.
│
│ ASCII VISUAL / QUEUE STATE:
│ BFS flowchart:
│
│ start source s
│ visited[s] = true
│ q.push(s)
│
│ while queue not empty:
│     node = q.front(); q.pop()
│     process node
│     for neighbor in adj[node]:
│         if not visited[neighbor]:
│             visited[neighbor] = true
│             q.push(neighbor)
│
│ Queue visual:
│ q=[0]
│ pop0 push1,2 -> q=[1,2]
│ pop1 push3   -> q=[2,3]
│ pop2 push4   -> q=[3,4]
│ pop3 push5   -> q=[4,5]
│ pop4 skip5   -> q=[5]
│ pop5         -> q=[]

│
│ STEP-BY-STEP DRY RUN:
│ visited before start: [0,0,0,0,0,0]
│ mark source0:         [1,0,0,0,0,0]
│ after neighbors 1,2:  [1,1,1,0,0,0]
│ after node1 pushes3:  [1,1,1,1,0,0]
│ after node2 pushes4:  [1,1,1,1,1,0]
│ after node3 pushes5:  [1,1,1,1,1,1]

│
│ COMPLEXITY CALCULATION:
│ Why queue?
│ FIFO means first discovered level nodes process before next level nodes.
│ Vertex processing count = V.
│ Neighbor scans over all lists = 2E undirected.
│ Time = O(V+E).
│ Space = visited O(V) + queue O(V) = O(V).

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
void bfsAlgorithm(const vector<vector<int>>& adj, int source) {
    vector<int> visited(adj.size(), 0);
    queue<int> q;

    visited[source] = 1; // Source ko dobara enqueue hone se bachate hain.
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Process " << node << "\n";

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                visited[nbr] = 1;
                q.push(nbr); // Neighbor next wave/level me jayega.
            }
        }
    }
}

int main() {
    vector<vector<int>> adj = sampleGraph();
    bfsAlgorithm(adj, 0);
    return 0;
}

/*
OUTPUT:
Process 0
Process 1
Process 2
Process 3
Process 4
Process 5
*/

