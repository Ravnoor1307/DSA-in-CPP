/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_bfs_intuition_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Paani me stone pheko to waves level-by-level failti hain. WhatsApp forward bhi pehle direct friends, phir friends-of-friends tak pahuncha hai. BFS wahi ripple pattern hai.
│
│ ASCII VISUAL / QUEUE STATE:
│ Ripple in water:
│ level 0: source stone point
│ level 1: nearest circle
│ level 2: next circle
│ level 3: next circle
│
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
│ Level 0 -> 0
│ Level 1 -> 1,2
│ Level 2 -> 3,4
│ Level 3 -> 5
│
│ Queue FIFO ensures old level nodes process before newer level nodes.

│
│ STEP-BY-STEP DRY RUN:
│ Start at 0.
│ Visit 0, enqueue neighbors 1,2.
│ Process 1 before 3 because 1 entered queue earlier.
│ Process 2 before 4 because 2 entered queue earlier.
│ Result level-wise order: 0 1 2 3 4 5.

│
│ COMPLEXITY CALCULATION:
│ BFS with adjacency list:
│ Each vertex enters queue once -> V pushes and V pops = 2V operations.
│ Each undirected edge appears in two lists, scanned twice -> 2E neighbor checks.
│ Total = 2V + 2E -> O(V+E).
│ Space = visited V + queue up to V -> O(V).

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
int main() {
    cout << "BFS intuition = ripple/wave level-by-level traversal\n";
    cout << "Graph levels from source 0:\n";
    cout << "Level 0: 0\n";
    cout << "Level 1: 1 2\n";
    cout << "Level 2: 3 4\n";
    cout << "Level 3: 5\n";
    cout << "Queue is needed because FIFO preserves level order.\n";
    return 0;
}

/*
OUTPUT:
BFS intuition = ripple/wave level-by-level traversal
Graph levels from source 0:
Level 0: 0
Level 1: 1 2
Level 2: 3 4
Level 3: 5
Queue is needed because FIFO preserves level order.
*/

