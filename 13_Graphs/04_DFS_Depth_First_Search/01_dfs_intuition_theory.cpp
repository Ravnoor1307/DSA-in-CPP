/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_dfs_intuition_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Maze solve karte time ek rasta pakdo, gehraai tak jao, dead-end aaye to wapas aao aur next rasta try karo. DFS exactly ye depth-first exploration hai.
│
│ ASCII VISUAL / STACK-RECURSION STATE:
│ BFS ripple vs DFS maze:
│
│ Graph:
│          0
│        /   \
│       1     2
│       |     |
│       3     4
│        \   /
│          5
│
│ BFS from 0 (level-wise):
│ 0 1 2 3 4 5
│
│ DFS from 0 (depth-wise):
│ 0 1 3 5 4 2
│
│ DFS feeling:
│ Start 0 -> choose 1 -> choose 3 -> choose 5 -> choose 4 -> choose 2
│ Then backtrack as all neighbors visited.

│
│ STEP-BY-STEP DRY RUN:
│ Call path:
│ dfs(0)
│   dfs(1)
│     dfs(3)
│       dfs(5)
│         dfs(4)
│           dfs(2)
│           return
│         return
│       return
│     return
│   return

│
│ COMPLEXITY CALCULATION:
│ Each vertex visited once -> V visits.
│ Each undirected edge checked from both endpoints -> 2E checks.
│ Total = V + 2E -> O(V+E).
│ Recursion stack can go as deep as V in worst chain -> O(V).
│ visited array O(V).

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

vector<vector<int>> sampleGraph() {
    vector<vector<int>> adj(6);
    auto add = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(2, 4);
    add(3, 5);
    add(4, 5);
    return adj;
}

void printOrder(const vector<int>& order, const string& label) {
    cout << label << ": ";
    for (int x : order) cout << x << ' ';
    cout << "\n";
}
int main() {
    cout << "DFS intuition = maze solving/backtracking\n";
    cout << "BFS: ripple level by level\n";
    cout << "DFS: one path deep, then backtrack\n";
    cout << "Sample DFS order from 0: 0 1 3 5 4 2\n";
    return 0;
}

/*
OUTPUT:
DFS intuition = maze solving/backtracking
BFS: ripple level by level
DFS: one path deep, then backtrack
Sample DFS order from 0: 0 1 3 5 4 2
*/

