/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_cycle_why_detect_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Operating system me processes ek dusre ka resource wait kar rahe hon to deadlock cycle ban sakta hai. Course prerequisites me A needs B and B needs A ho to course kabhi complete nahi hoga.
│
│ ASCII VISUAL / STATE:
│ Deadlock graph:
│ ProcessA waits for ResourceB
│ ProcessB waits for ResourceA
│
│ A ----> B
│ ^      |
│ |      v
│ D <---- C
│ Cycle means loop.
│
│ Course prerequisite invalid:
│ Math -> Physics
│ Physics -> Engineering
│ Engineering -> Math
│
│ Agar cycle hai, valid ordering impossible.

│
│ STEP-BY-STEP DRY RUN:
│ Directed cycle path:
│ 0 -> 1 -> 2 -> 0
│ Start at 0.
│ Go to 1.
│ Go to 2.
│ Neighbor 0 is already in current recursion path.
│ Cycle detected.

│
│ COMPLEXITY CALCULATION:
│ Cycle detection algorithms traverse graph.
│ With adjacency list:
│ each vertex visited O(1) times -> O(V).
│ each edge scanned once or twice depending directed/undirected -> O(E).
│ Time = O(V+E).
│ Space = visited/color/parent O(V) + recursion/queue O(V) = O(V).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout << "Cycle detection tells if graph has a loop.\n";
    cout << "Real-world: deadlock or impossible course prerequisites.\n";
    cout << "Directed cycle example: 0 -> 1 -> 2 -> 0\n";
    return 0;
}

/*
OUTPUT:
Cycle detection tells if graph has a loop.
Real-world: deadlock or impossible course prerequisites.
Directed cycle example: 0 -> 1 -> 2 -> 0
*/

