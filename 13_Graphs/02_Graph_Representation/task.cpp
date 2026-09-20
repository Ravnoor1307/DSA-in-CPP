/*
REAL-WORLD SCENARIO:
City road network ko two formats me store karna hai: matrix and list.

TASKS easy -> hard:
1. Adjacency matrix banao for V=4.
2. addEdge matrix version likho.
3. hasEdge matrix O(1) function likho.
4. Adjacency list banao using vector<vector<int>>.
5. Directed and undirected addEdge flag implement karo.
6. Weighted graph using vector<vector<pair<int,int>>> banao.
7. Matrix vs list comparison comments me likho.

HINTS:
- Matrix space V*V hota hai.
- List space V+E hota hai.
- Undirected graph me both u->v and v->u add karo.

STARTER CODE:
vector<vector<int>> matrix(V, vector<int>(V, 0));
vector<vector<int>> adj(V);

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
using namespace std;

void addMatrixEdge(vector<vector<int>>& mat, int u, int v) {
    mat[u][v] = 1;
    mat[v][u] = 1; // Undirected road dono taraf.
}

void addListEdge(vector<vector<int>>& adj, int u, int v, bool directed = false) {
    adj[u].push_back(v);
    if (!directed) adj[v].push_back(u);
}

int main() {
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    vector<vector<int>> adj(V);
    addMatrixEdge(matrix, 0, 1);
    addMatrixEdge(matrix, 0, 2);
    addListEdge(adj, 0, 1);
    addListEdge(adj, 0, 2);

    cout << "matrix edge 0-2 = " << matrix[0][2] << "\n";
    cout << "adj[0]: ";
    for (int v : adj[0]) cout << v << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
matrix edge 0-2 = 1
adj[0]: 1 2
*/
