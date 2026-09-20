/*
REAL-WORLD SCENARIO:
WhatsApp message forward network me source user se level-wise spread simulate karna hai.

TASKS easy -> hard:
1. Adjacency list create karo.
2. BFS traversal from source 0 implement karo.
3. Queue state har step print karo.
4. visited array evolution print karo.
5. Unweighted shortest distance array fill karo.
6. Disconnected graph ke all components BFS se count karo.
7. 2D grid BFS implement karo using 4 directions.

HINTS:
- Source ko push karte hi visited mark karo.
- Distance neighbor = distance[current] + 1.
- Disconnected graph ke liye for loop over all vertices.

STARTER CODE:
queue<int> q;
vector<int> visited(V, 0);

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(const vector<vector<int>>& adj, int source) {
    vector<int> visited(adj.size(), 0), order;
    queue<int> q;
    visited[source] = 1;
    q.push(source);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1; // Push time mark avoids duplicate entries.
                q.push(v);
            }
        }
    }
    return order;
}

int main() {
    vector<vector<int>> adj(6);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(0,2); add(1,3); add(2,4); add(3,5); add(4,5);
    vector<int> order = bfs(adj, 0);
    cout << "BFS: ";
    for (int x : order) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
BFS: 0 1 2 3 4 5
*/
