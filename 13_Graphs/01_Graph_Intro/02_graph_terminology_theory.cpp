/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_graph_terminology_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Social media network me users vertices hain, follow/friend links edges hain, neighbors direct friends hain, path mutual connection chain hai, cycle closed friend circle hai.
│
│ ASCII VISUAL / GRAPH STATE:
│ Complete terminology visual:
│
│        (0)------(1)
│         | \      |
│         |  \     |
│        (2)------(3)----(4)
│
│ Vertex: 0,1,2,3,4
│ Edge: (0,1), (0,2), (0,3), (1,3), (2,3), (3,4)
│ Neighbor of 3: 0,1,2,4
│ Degree of 3: 4
│ Path 0 to 4: 0 -> 3 -> 4
│ Cycle: 0 -> 1 -> 3 -> 0
│ Connected graph: every vertex reachable from every other vertex
│
│ Directed edge example: Instagram A -> B means A follows B.
│ Weighted edge example: Map road Ludhiana--Delhi weight=distance/time.

│
│ STEP-BY-STEP DRY RUN:
│ Build degree array initially [0,0,0,0,0].
│ Edge (0,1): degree0++, degree1++ -> [1,1,0,0,0]
│ Edge (0,2): -> [2,1,1,0,0]
│ Edge (0,3): -> [3,1,1,1,0]
│ Edge (1,3): -> [3,2,1,2,0]
│ Edge (2,3): -> [3,2,2,3,0]
│ Edge (3,4): -> [3,2,2,4,1]

│
│ COMPLEXITY CALCULATION:
│ Degree calculation for undirected graph:
│ Each edge touches exactly 2 endpoints.
│ For E edges, updates = 2E.
│ Time = O(E).
│ Degree array has V integers -> O(V) space.
│ Edge list stores E pairs -> O(E) space.

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
    int V = 5;
    vector<pair<int,int>> edges = {{0,1}, {0,2}, {0,3}, {1,3}, {2,3}, {3,4}};
    vector<int> degree(V, 0);

    for (auto e : edges) {
        degree[e.first]++;   // Undirected edge dono endpoints ka degree badhata hai.
        degree[e.second]++;
    }

    cout << "Vertex terms demo\n";
    for (int i = 0; i < V; i++) {
        cout << "degree(" << i << ") = " << degree[i] << "\n";
    }
    cout << "Path example 0 -> 3 -> 4\n";
    cout << "Cycle example 0 -> 1 -> 3 -> 0\n";
    return 0;
}

/*
OUTPUT:
Vertex terms demo
degree(0) = 3
degree(1) = 2
degree(2) = 2
degree(3) = 4
degree(4) = 1
Path example 0 -> 3 -> 4
Cycle example 0 -> 1 -> 3 -> 0
*/

