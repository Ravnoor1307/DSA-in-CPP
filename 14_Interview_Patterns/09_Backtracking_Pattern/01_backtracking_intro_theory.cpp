/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_backtracking_intro_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Maze me route dhoondhte waqt ek choice lo, explore karo, dead-end aaye to undo/backtrack karke next choice try karo. Backtracking = recursion with undo.
│
│ ASCII VISUAL / DECISION STATE:
│ 3-step mantra:
│ CHOOSE -> EXPLORE -> UNDO
│
│ Maze decision tree:
│ Start
│ ├─ go Right
│ │  ├─ go Down -> dead end ↩ undo
│ │  └─ go Right -> exit
│ └─ go Down
│    └─ blocked ↩ undo
│
│ Recursion connect:
│ Subsets/permutations me choices recursively try hote hain.
│ Backtracking formalizes undo step so state clean rahe.

│
│ STEP-BY-STEP DRY RUN:
│ Example path vector []
│ choose 1 -> [1]
│ explore deeper
│ undo 1 -> []
│ choose 2 -> [2]
│ explore deeper
│ undo 2 -> []

│
│ COMPLEXITY CALCULATION:
│ If each level has b choices and depth d, nodes about b^d.
│ Backtracking often exponential because all combinations explored.
│ Space = recursion depth O(d) plus output size.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    cout << "Backtracking mantra: CHOOSE -> EXPLORE -> UNDO\n";
    cout << "Use when all combinations/permutations/valid boards are needed.\n";
    cout << "Maze analogy: dead end? undo and try next path.\n";
    return 0;
}

/*
OUTPUT:
Backtracking mantra: CHOOSE -> EXPLORE -> UNDO
Use when all combinations/permutations/valid boards are needed.
Maze analogy: dead end? undo and try next path.
*/

