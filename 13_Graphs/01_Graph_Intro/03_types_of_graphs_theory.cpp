/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_types_of_graphs_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Different real-world networks different graph types banate hain: roads undirected, Instagram follows directed, Google Maps weighted, course prerequisites DAG.
│
│ ASCII VISUAL / GRAPH STATE:
│ VISUAL GRID:
│
│ 1) Undirected:
│    A ----- B       Road is two-way.
│
│ 2) Directed:
│    A ----> B       A follows B, B may not follow A.
│
│ 3) Weighted:
│    A --7km-- B     Edge has cost/time/distance.
│
│ 4) Unweighted:
│    A ----- B       Every edge equal step cost.
│
│ 5) Cyclic:
│    A -> B -> C -> A
│
│ 6) Acyclic/DAG:
│    CourseA -> CourseB -> CourseC, no back dependency.
│
│ 7) Connected:
│    every node reachable.
│
│ 8) Disconnected:
│    (A--B)    (C--D) separate friend circles.

│
│ STEP-BY-STEP DRY RUN:
│ If edges are directed, add only u -> v.
│ If undirected, add both u -> v and v -> u.
│ If weighted, store pair(neighbor, weight).
│ If unweighted, store only neighbor.

│
│ COMPLEXITY CALCULATION:
│ Classification by scanning edge list:
│ For E edges, each edge checked once -> E checks.
│ Time = O(E).
│ Storing adjacency list for V vertices and E edges:
│ Directed list space O(V+E).
│ Undirected list stores each edge twice -> O(V+2E) = O(V+E).

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
    cout << left << setw(15) << "Type" << "Real-world example\n";
    cout << string(55, '-') << "\n";
    cout << left << setw(15) << "Undirected" << "two-way roads\n";
    cout << left << setw(15) << "Directed" << "Instagram follow relation\n";
    cout << left << setw(15) << "Weighted" << "Google Maps distance/time\n";
    cout << left << setw(15) << "Unweighted" << "minimum number of hops\n";
    cout << left << setw(15) << "Cyclic" << "round road route\n";
    cout << left << setw(15) << "DAG" << "course prerequisites\n";
    cout << left << setw(15) << "Disconnected" << "separate friend circles\n";
    return 0;
}

/*
OUTPUT:
Type           Real-world example
-------------------------------------------------------
Undirected     two-way roads
Directed       Instagram follow relation
Weighted       Google Maps distance/time
Unweighted     minimum number of hops
Cyclic         round road route
DAG            course prerequisites
Disconnected   separate friend circles
*/

