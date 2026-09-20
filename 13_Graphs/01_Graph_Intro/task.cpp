/*
REAL-WORLD SCENARIO:
Google Maps mini network model karna hai: cities vertices, roads edges.

TASKS easy -> hard:
1. 5 city names vector me store karo.
2. Undirected roads edge list me store karo.
3. Har city ka degree calculate karo.
4. Path and cycle comments me draw karo.
5. Directed relation ka example print karo.
6. Weighted edge ka example pair(city, distance) se print karo.
7. Explain karo tree graph ka special case kyun hai.

HINTS:
- Undirected edge (u,v) degree[u]++ and degree[v]++.
- Directed edge u->v me sirf u se v direction hoti hai.
- Tree connected + acyclic hota hai.

STARTER CODE:
vector<pair<int,int>> edges;
vector<int> degree(V, 0);

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> cities = {"Ludhiana", "Delhi", "Chandigarh", "Amritsar", "Jalandhar"};
    vector<pair<int,int>> roads = {{0,2}, {2,1}, {0,3}, {0,4}};
    vector<int> degree(cities.size(), 0);

    for (auto road : roads) {
        degree[road.first]++;   // Undirected road dono cities ko connect karta hai.
        degree[road.second]++;
    }

    for (int i = 0; i < (int)cities.size(); i++) {
        cout << cities[i] << " degree = " << degree[i] << "\n";
    }
    cout << "Tree special graph: connected + no cycle + V-1 edges.\n";
    return 0;
}

/*
OUTPUT:
Ludhiana degree = 3
Delhi degree = 1
Chandigarh degree = 2
Amritsar degree = 1
Jalandhar degree = 1
Tree special graph: connected + no cycle + V-1 edges.
*/
