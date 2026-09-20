/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_backtracking_vs_recursion_vs_dp.cpp
│
│ REAL-WORLD SCENARIO:
│ Problem-solving family me recursion basic calling tool hai, backtracking choices with undo hai, and DP repeated states ko memory se optimize karta hai.
│
│ ASCII VISUAL / DECISION STATE:
│ Recursion:
│ function calls itself.
│ Example: factorial, tree DFS.
│
│ Backtracking:
│ recursion + state + undo.
│ Example: subsets, permutations, N-Queens.
│
│ DP:
│ recursion/tabulation + memory for overlapping states.
│ Example: fibonacci, climbing stairs, knapsack.
│
│ Decision:
│ Need all valid possibilities? -> Backtracking
│ Need count/min/max with repeated states? -> DP
│ Simple divide problem? -> Recursion

│
│ STEP-BY-STEP DRY RUN:
│ Subsets has no repeated state focus; output all choices -> backtracking.
│ Fibonacci repeats fib(3), fib(2) etc -> DP memoization.
│ Factorial has no branching repeated state -> simple recursion.

│
│ COMPLEXITY CALCULATION:
│ Recursion complexity depends on recurrence.
│ Backtracking often exponential because choice tree explored.
│ DP reduces overlapping recursion states: if states count S and transition cost T, time O(S*T).
│ Space O(S) for memo/table.

│ APPROACH COMPARISON TABLE:
│ | Technique | Analogy | Signal | Time style | Space |
│ | Recursion | folder inside folder | natural subproblem | recurrence based | call stack |
│ | Backtracking | maze choices undo | all solutions | exponential tree | depth + output |
│ | DP | notebook memory | repeated states | states * transition | table/memo |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    cout << "Recursion = self call\n";
    cout << "Backtracking = choose, explore, undo\n";
    cout << "DP = recursion/iteration with memory for repeated states\n";
    return 0;
}

/*
OUTPUT:
Recursion = self call
Backtracking = choose, explore, undo
DP = recursion/iteration with memory for repeated states
*/

