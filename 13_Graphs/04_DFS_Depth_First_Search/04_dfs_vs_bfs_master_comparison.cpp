/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_dfs_vs_bfs_master_comparison.cpp
│
│ REAL-WORLD SCENARIO:
│ Maze, maps, and social networks me traversal choose karna route strategy choose karne jaisa hai: BFS nearest-first, DFS depth-first/backtracking.
│
│ ASCII VISUAL / STACK-RECURSION STATE:
│ Decision flowchart:
│
│ Need shortest path in unweighted graph?
│   YES -> BFS
│   NO  -> next question
│
│ Need explore all paths/backtracking/cycle/topological style?
│   YES -> DFS often easier
│   NO  -> either BFS/DFS for traversal/components
│
│ BFS visual:
│ level0 -> level1 -> level2
│ Uses queue FIFO.
│
│ DFS visual:
│ one branch down -> backtrack -> next branch
│ Uses recursion/stack.

│
│ STEP-BY-STEP DRY RUN:
│ Same graph:
│ BFS from0: 0 1 2 3 4 5
│ DFS from0: 0 1 3 5 4 2
│
│ BFS pehle distance1 nodes 1,2 process karta hai.
│ DFS neighbor1 ke through deep node5 tak pahunch jata hai before node2.

│
│ COMPLEXITY CALCULATION:
│ With adjacency list, both BFS and DFS:
│ vertex visit = V
│ edge scan = 2E undirected
│ Time = O(V+E)
│
│ BFS space = queue O(V) + visited O(V)
│ DFS space = recursion/stack O(V) + visited O(V)
│ Both = O(V) worst.

│ APPROACH COMPARISON TABLE:
│ | Need | Choose | Reason | Time | Space |
│ | Shortest unweighted | BFS | levels = distance | O(V+E) | O(V) |
│ | Backtracking/deep route | DFS | one branch deep | O(V+E) | O(V) |
│ | Connected components | Either | launch from unvisited | O(V+E) | O(V) |
│ | Flood fill | DFS/BFS | grid traversal | O(R*C) | O(R*C) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(18) << "Feature" << setw(22) << "BFS" << "DFS\n";
    cout << string(75, '-') << "\n";
    cout << left << setw(18) << "Data structure" << setw(22) << "Queue" << "Stack/Recursion\n";
    cout << left << setw(18) << "Style" << setw(22) << "Level-wise" << "Depth-wise\n";
    cout << left << setw(18) << "Unweighted SP" << setw(22) << "Best" << "Not guaranteed\n";
    cout << left << setw(18) << "Cycle detect" << setw(22) << "Possible" << "Very common\n";
    cout << left << setw(18) << "Grid spread" << setw(22) << "Rotten oranges" << "Flood fill\n";
    cout << "Use BFS for nearest/levels; use DFS for deep exploration/backtracking.\n";
    return 0;
}

/*
OUTPUT:
Feature           BFS                   DFS
---------------------------------------------------------------------------
Data structure    Queue                 Stack/Recursion
Style             Level-wise            Depth-wise
Unweighted SP     Best                  Not guaranteed
Cycle detect      Possible              Very common
Grid spread       Rotten oranges        Flood fill
Use BFS for nearest/levels; use DFS for deep exploration/backtracking.
*/

