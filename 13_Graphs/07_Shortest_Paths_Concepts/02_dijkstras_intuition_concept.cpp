/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_dijkstras_intuition_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Google Maps me roads ki distance/time different hoti hai. BFS equal-cost roads ke liye tha; weighted graph me nearest current city choose karne ke liye priority queue chahiye.
│
│ ASCII VISUAL / DISTANCE STATE:
│ Weighted graph:
│       2        7
│  0 ------ 1 ------- 3
│   \       |         /
│    \4     |1       /1
│     \     |       /
│       2 ------- 4
│            3
│
│ BFS problem:
│ BFS edge count minimize karta hai, weight/time nahi.
│ Route 0->2 is 1 edge cost 4.
│ Route 0->1->2 is 2 edges cost 3, better.
│
│ Dijkstra intuition:
│ Maintain dist[] best known time.
│ Priority queue me smallest distance city top pe.
│ Jo current nearest city final hoti hai, uske outgoing roads relax karo.
│
│ Heaps journey connect:
│ priority_queue gives next minimum distance node fast.

│
│ STEP-BY-STEP DRY RUN:
│ Start dist[0]=0, others INF.
│ pq={(0,0)}
│ pop0 -> update1=2, update2=4
│ pq={(2,1),(4,2)}
│ pop1 -> update2=min(4,2+1=3), update3=9
│ pq={(3,2),(4,2 old),(9,3)}
│ pop2 -> update4=6
│ pop4 -> update3=7

│
│ COMPLEXITY CALCULATION:
│ Dijkstra with priority queue:
│ Each edge relaxation may push one pair into pq -> O(E log V).
│ Each vertex/old state pop costs log V; total pushes O(E), pops O(E).
│ Time = O((V+E) log V) commonly written.
│ Space = adjacency O(V+E) + dist O(V) + pq O(E) worst = O(V+E).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int main() {
    cout << "Dijkstra = weighted shortest path without negative weights.\n";
    cout << "BFS chooses by levels; Dijkstra chooses by smallest distance using min priority queue.\n";
    cout << "Priority queue state example: (0,0) -> (2,1),(4,2) -> (3,2),(9,3) ...\n";
    return 0;
}

/*
OUTPUT:
Dijkstra = weighted shortest path without negative weights.
BFS chooses by levels; Dijkstra chooses by smallest distance using min priority queue.
Priority queue state example: (0,0) -> (2,1),(4,2) -> (3,2),(9,3) ...
*/

