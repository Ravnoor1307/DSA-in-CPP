/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_components_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Social media me alag-alag friend circles ho sakte hain. Ek circle ke log ek dusre tak reach kar sakte hain, par doosre circle se disconnected hote hain.
│
│ ASCII VISUAL / COMPONENT STATE:
│ Disconnected graph islands:
│
│ Friend circle 1: 0 -- 1 -- 2
│
│ Friend circle 2: 3 -- 4
│
│ Friend circle 3: 5 -- 6
│
│ Connected component = maximum group jahan nodes ek dusre tak path se reachable hain.
│
│ Graph components count = 3
│ Component sizes: 3, 2, 2

│
│ STEP-BY-STEP DRY RUN:
│ Start visited [0,0,0,0,0,0,0]
│ vertex0 unvisited -> explore 0,1,2 -> component1
│ vertex1,2 visited skip
│ vertex3 unvisited -> explore 3,4 -> component2
│ vertex5 unvisited -> explore 5,6 -> component3

│
│ COMPLEXITY CALCULATION:
│ To find components, outer loop V vertices.
│ Each BFS/DFS across all launches visits each vertex once -> V.
│ Each undirected edge scanned twice -> 2E.
│ Total = O(V+E).
│ Space = visited O(V) + queue/stack/recursion O(V) = O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> disconnectedGraph() {
    vector<vector<int>> adj(7);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0, 1);
    add(1, 2);
    add(3, 4);
    add(5, 6);
    return adj;
}
int main() {
    cout << "Connected components = separate friend circles/islands\n";
    cout << "Component 1: 0 1 2\n";
    cout << "Component 2: 3 4\n";
    cout << "Component 3: 5 6\n";
    cout << "Total components = 3\n";
    return 0;
}

/*
OUTPUT:
Connected components = separate friend circles/islands
Component 1: 0 1 2
Component 2: 3 4
Component 3: 5 6
Total components = 3
*/

