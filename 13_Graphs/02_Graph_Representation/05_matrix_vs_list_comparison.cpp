/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_matrix_vs_list_comparison.cpp
│
│ REAL-WORLD SCENARIO:
│ City map storage choose karna parking style choose karne jaisa hai: every possible slot reserve karna matrix hai, sirf real roads list karna adjacency list hai.
│
│ ASCII VISUAL / GRAPH STATE:
│ Same graph:
│ 0 -- 1 -- 3
│ |
│ 2
│
│ Matrix:
│      0 1 2 3
│  0 [0 1 1 0]
│  1 [1 0 0 1]
│  2 [1 0 0 0]
│  3 [0 1 0 0]
│ Edge check 0-2 -> direct matrix[0][2]
│ Neighbor iteration 0 -> scan full row length V
│
│ List:
│ 0: 1,2
│ 1: 0,3
│ 2: 0
│ 3: 1
│ Edge check 0-2 -> scan adj[0]
│ Neighbor iteration 0 -> only degree(0)=2 items

│
│ STEP-BY-STEP DRY RUN:
│ If V=4 and E=3:
│ Matrix cells = V² = 16.
│ List entries = V lists + 2E = 4 + 6 = 10 conceptual slots.
│ For huge sparse graph, list saves memory.

│
│ COMPLEXITY CALCULATION:
│ Matrix edge check: 1 cell read -> O(1).
│ Matrix neighbor iteration: scan V cells -> O(V).
│ Matrix space: V*V -> O(V²).
│
│ List edge check: scan adj[u] length degree(u) -> O(degree(u)).
│ List neighbor iteration: exactly degree(u) entries -> O(degree(u)).
│ List space: V lists + E directed entries or 2E undirected -> O(V+E).

│ APPROACH COMPARISON TABLE:
│ | Representation | Analogy | Space | Edge check | Iterate neighbors | Best use |
│ | Matrix | all possible road slots | O(V²) | O(1) | O(V) | dense graphs |
│ | List | each city road list | O(V+E) | O(degree) | O(degree) | sparse graphs |
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
    cout << left << setw(18) << "Feature" << setw(22) << "Adj Matrix" << "Adj List\n";
    cout << string(70, '-') << "\n";
    cout << left << setw(18) << "Space" << setw(22) << "O(V^2)" << "O(V+E)\n";
    cout << left << setw(18) << "Edge check" << setw(22) << "O(1)" << "O(degree)\n";
    cout << left << setw(18) << "Neighbors" << setw(22) << "O(V)" << "O(degree)\n";
    cout << left << setw(18) << "Best for" << setw(22) << "dense graph" << "sparse graph\n";
    cout << "Real-world: matrix reserves all possible roads, list stores actual roads.\n";
    return 0;
}

/*
OUTPUT:
Feature           Adj Matrix            Adj List
----------------------------------------------------------------------
Space             O(V^2)                O(V+E)
Edge check        O(1)                  O(degree)
Neighbors         O(V)                  O(degree)
Best for          dense graph           sparse graph
Real-world: matrix reserves all possible roads, list stores actual roads.
*/

