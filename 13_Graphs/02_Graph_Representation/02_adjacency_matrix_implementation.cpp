/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_adjacency_matrix_implementation.cpp
│
│ REAL-WORLD SCENARIO:
│ Flight booking app me direct flight check karna hai: source and destination ka matrix cell read karo. Direct lookup fast, but sparse network me memory waste ho sakti hai.
│
│ ASCII VISUAL / GRAPH STATE:
│ V = 5 cities, E = 4 roads
│
│ Matrix size = 5 x 5 = 25 cells
│ Actual roads only 4, undirected marks 8 cells
│ Baaki many 0s -> sparse graph waste.
│
│ Matrix visual:
│      0 1 2 3 4
│  0 [0 1 1 0 0]
│  1 [1 0 0 1 0]
│  2 [1 0 0 0 1]
│  3 [0 1 0 0 0]
│  4 [0 0 1 0 0]
│
│ Edge check 1-3: matrix[1][3] -> YES
│ Edge check 3-4: matrix[3][4] -> NO

│
│ STEP-BY-STEP DRY RUN:
│ addEdge(0,1): set two cells.
│ addEdge(0,2): set two cells.
│ addEdge(1,3): set two cells.
│ addEdge(2,4): set two cells.
│ Then edge checks are one direct array lookup each.

│
│ COMPLEXITY CALCULATION:
│ Constructor initializes V*V cells -> O(V²).
│ addEdge updates 2 cells for undirected -> O(1).
│ hasEdge reads 1 cell -> O(1).
│ print scans V*V cells -> O(V²).
│ Space = V*V integers -> O(V²).

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

class GraphMatrix {
    int V;
    vector<vector<int>> mat;
public:
    GraphMatrix(int vertices) : V(vertices), mat(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int u, int v, bool directed = false) {
        mat[u][v] = 1;
        if (!directed) mat[v][u] = 1; // Undirected me dono direction store.
    }

    bool hasEdge(int u, int v) const {
        return mat[u][v] == 1; // Direct lookup O(1).
    }

    void print() const {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) cout << mat[i][j] << ' ';
            cout << "\n";
        }
    }
};

int main() {
    GraphMatrix g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.print();
    cout << "Edge 1-3? " << (g.hasEdge(1,3) ? "YES" : "NO") << "\n";
    cout << "Edge 3-4? " << (g.hasEdge(3,4) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 0
0 0 1 0 0
Edge 1-3? YES
Edge 3-4? NO
*/

