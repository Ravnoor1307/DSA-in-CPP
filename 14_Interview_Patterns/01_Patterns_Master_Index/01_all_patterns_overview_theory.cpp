/*
═══════════════════════════════════════════════
 ALL DSA PATTERNS — MASTER OVERVIEW
 ⏱️ TIME COMPLEXITY: fixed 10-row reference table = O(1); space O(1)
 for the constant-size table data.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Before an interview you need a decision sheet, just like an airport
 dashboard. Every incoming flight (problem statement) carries a small
 signal — "sorted pair", "longest substring", "cycle". The dashboard
 shows exactly which runway (pattern) handles that signal. This master
 index is that decision map: read the problem, match the keyword, and
 jump to the correct pattern folder.

 📖 THEORY:
 - This file is the master index listing the 10 core interview patterns.
 - Each pattern row stores: pattern name, trigger signal, prerequisite
   skill, and a ready-to-use template.
 - MEGA TABLE of the 10 patterns:
   1. Two Pointers       -> sorted pair / opposite ends / linked list cycle
   2. Sliding Window     -> contiguous subarray / substring
   3. Prefix Sum         -> subarray sum / range query
   4. Fast-Slow          -> cycle / middle / duplicate as linked list
   5. Merge Intervals    -> overlapping meetings / timelines
   6. Cyclic Sort        -> numbers 1..n, correct seat index
   7. Top K Elements     -> kth / top-k / frequent / closest
   8. Backtracking       -> all combinations / permutations / choices
   9. Greedy             -> local best choice with proof
   10. DP                -> overlapping subproblems + optimal substructure
 - Journey links:
   Arrays -> two pointers, sliding window, prefix sum
   Linked List -> fast-slow
   Heap -> top-k
   Recursion -> backtracking and DP
   Graphs -> BFS/DFS decision thinking

 ASCII SIGNAL-TO-PATTERN MAP:
   "sorted array pair"        -> two pointers
   "longest substring"        -> sliding window
   "range sum many queries"   -> prefix sum
   "cycle"                    -> fast-slow / graph cycle
   "top k"                    -> heap
   "all ways"                 -> backtracking / DP

 🧠 LOGIC — STEP BY STEP:
 Step 1: Read the problem statement and extract its signal keyword.
    WHY: The signal word is the strongest hint — "sorted pair" means two
    pointers, "longest substring" means sliding window.
 Step 2: Look the signal up in the keyword map above.
    WHY: A fixed decision map turns guesswork into a quick lookup.
 Step 3: Pick that pattern's learned prerequisite and template.
    WHY: The template gives an immediate skeleton (e.g. l=0, r=n-1 for
    two pointers, heap size k for top-k).
 Step 4: Print the constant 10-row reference table.
    WHY: The purpose of this overview file is a fast visual recap.

 DRY RUN:
   Keyword mapping:
   "sorted array pair"        -> two pointers
   "longest substring"        -> sliding window
   "range sum many queries"   -> prefix sum
   "cycle"                    -> fast-slow / graph cycle
   "top k"                    -> heap
   "all ways"                 -> backtracking / DP
   Table printed: exactly 10 fixed rows, one per pattern.

 FLOW OF EXECUTION:
   read problem -> extract signal keyword -> map to pattern
   -> pick template -> print 10-row reference table -> stop

 TIME COMPLEXITY CALCULATION:
 - The only loop prints the fixed table: 10 rows regardless of input n.
 - 10 is a constant; it does not grow with input size n.
 -> Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - Only the fixed 10-pattern table data is stored.
 -> Space Complexity = O(1)
═══════════════════════════════════════════════
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

struct PatternRow {
    string pattern, signal, learned, templ;
};

int main() {
    vector<PatternRow> rows = {
        {"Two Pointers", "sorted pair / ends", "Arrays", "l=0,r=n-1"},
        {"Sliding Window", "contiguous subarray", "Arrays/Strings", "expand right, shrink left"},
        {"Prefix Sum", "range/subarray sum", "Arrays+Hashing", "prefix += a[i]"},
        {"Fast-Slow", "cycle/middle", "Linked List", "slow+=1, fast+=2"},
        {"Merge Intervals", "overlap timeline", "New", "sort by start"},
        {"Cyclic Sort", "1..n seat", "New", "swap to nums[i]-1"},
        {"Top K Heap", "kth/top/frequent", "Heaps", "heap size k"},
        {"Backtracking", "all combinations", "Recursion", "choose-explore-undo"},
        {"Greedy", "local best", "New", "sort + choose"},
        {"DP", "overlap + optimal", "Recursion", "memo/tabulate"}
    };
    cout << left << setw(18) << "Pattern" << setw(24) << "Signal" << setw(18) << "Learned" << "Template\n";
    cout << string(90, '-') << "\n";
    for (const auto& row : rows) {
        cout << left << setw(18) << row.pattern << setw(24) << row.signal << setw(18) << row.learned << row.templ << "\n";
    }
    return 0;
}

/*
OUTPUT:
Pattern           Signal                  Learned           Template
------------------------------------------------------------------------------------------
Two Pointers      sorted pair / ends       Arrays            l=0,r=n-1
Sliding Window    contiguous subarray      Arrays/Strings    expand right, shrink left
Prefix Sum        range/subarray sum       Arrays+Hashing    prefix += a[i]
Fast-Slow         cycle/middle             Linked List       slow+=1, fast+=2
Merge Intervals   overlap timeline         New               sort by start
Cyclic Sort       1..n seat                New               swap to nums[i]-1
Top K Heap        kth/top/frequent         Heaps             heap size k
Backtracking      all combinations         Recursion         choose-explore-undo
Greedy            local best               New               sort + choose
DP                overlap + optimal        Recursion         memo/tabulate
*/

