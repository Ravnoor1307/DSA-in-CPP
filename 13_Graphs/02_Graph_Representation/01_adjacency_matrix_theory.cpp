/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_adjacency_matrix_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Maps me agar instantly check karna ho ki Ludhiana se Delhi direct road hai ya nahi, adjacency matrix direct lookup table deta hai.
│
│ ASCII VISUAL / GRAPH STATE:
│ Graph:
│ 0 -- 1
│ |  /
│ | /
│ 2
│
│ 2D matrix journey connect:
│ matrix[i][j] = 1 means edge i -> j exists
│ matrix[i][j] = 0 means no direct edge
│
│ Undirected adjacency matrix:
│      0 1 2
│  0 [0 1 1]
│  1 [1 0 1]
│  2 [1 1 0]
│
│ Symmetric because road two-way:
│ matrix[0][1] = matrix[1][0] = 1

│
│ STEP-BY-STEP DRY RUN:
│ Add edge (0,1): matrix[0][1]=1 and matrix[1][0]=1.
│ Add edge (0,2): matrix[0][2]=1 and matrix[2][0]=1.
│ Add edge (1,2): matrix[1][2]=1 and matrix[2][1]=1.
│ Edge check 0-2: directly read matrix[0][2] = 1.

│
│ COMPLEXITY CALCULATION:
│ Matrix has V rows and V columns.
│ Cells = V * V = V².
│ Space = O(V²).
│ Edge check matrix[u][v] reads one cell -> O(1).
│ Iterating neighbors of u scans entire row of V cells -> O(V).

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

int main() {
    int V = 3;
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    vector<pair<int,int>> edges = {{0,1}, {0,2}, {1,2}};
    for (auto e : edges) {
        matrix[e.first][e.second] = 1;
        matrix[e.second][e.first] = 1; // Undirected graph me reverse bhi mark hota hai.
    }

    cout << "Adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) cout << matrix[i][j] << ' ';
        cout << "\n";
    }
    cout << "Edge 0-2? " << (matrix[0][2] ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
Adjacency matrix:
0 1 1
1 0 1
1 1 0
Edge 0-2? YES
*/

