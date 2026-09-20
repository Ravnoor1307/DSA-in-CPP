/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_why_graphs_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Tree me parent-child hierarchy fixed hoti hai, but Google Maps ya Instagram me koi bhi kisi se connect ho sakta hai. Is non-hierarchical connection world ke liye graph chahiye.
│
│ ASCII VISUAL / GRAPH STATE:
│ Tree hierarchy:
│          CompanyCEO
│         /        \
│     ManagerA    ManagerB
│       /             \
│   Employee1       Employee2
│ Rule: mostly one parent path.
│
│ Graph network:
│ Ludhiana ---- Delhi
│    |  \        |
│    |   \       |
│ Amritsar ---- Chandigarh
│ Koi bhi city multiple roads se connect ho sakti hai.
│
│ Graph examples:
│ - Google Maps: vertices=cities, edges=roads
│ - Instagram: vertices=users, directed edges=follows
│ - Computer network: vertices=computers, edges=cables/wifi links
│
│ Relationship:
│ Graph ⊃ Tree
│ Tree is connected acyclic graph with V vertices and V-1 edges.

│
│ STEP-BY-STEP DRY RUN:
│ Suppose cities = {0:Ludhiana, 1:Delhi, 2:Chandigarh}
│ roads = {(0,1), (0,2), (1,2)}
│ City 0 is connected to 1 and 2.
│ City 1 also connected to 2.
│ This cannot be forced into single parent-child hierarchy cleanly.

│
│ COMPLEXITY CALCULATION:
│ If V vertices and E edges are printed from edge list:
│ loop over V names -> V operations.
│ loop over E roads -> E operations.
│ Total = V + E -> O(V+E).
│ Space for names V and edges E -> O(V+E).

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
    vector<string> city = {"Ludhiana", "Delhi", "Chandigarh", "Amritsar"};
    vector<pair<int,int>> roads = {{0,1}, {0,2}, {2,3}, {1,2}};

    cout << "Graph = non-hierarchical connection model\n";
    cout << "Cities/Vertices:\n";
    for (int i = 0; i < (int)city.size(); i++) {
        cout << i << " -> " << city[i] << "\n";
    }

    cout << "Roads/Edges:\n";
    for (auto road : roads) {
        cout << city[road.first] << " <-> " << city[road.second] << "\n";
    }

    cout << "Tree is a special graph: connected + no cycle.\n";
    return 0;
}

/*
OUTPUT:
Graph = non-hierarchical connection model
Cities/Vertices:
0 -> Ludhiana
1 -> Delhi
2 -> Chandigarh
3 -> Amritsar
Roads/Edges:
Ludhiana <-> Delhi
Ludhiana <-> Chandigarh
Chandigarh <-> Amritsar
Delhi <-> Chandigarh
Tree is a special graph: connected + no cycle.
*/

