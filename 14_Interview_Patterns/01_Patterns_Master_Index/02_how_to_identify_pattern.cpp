/*
═══════════════════════════════════════════════
 HOW TO IDENTIFY A PATTERN
 ⏱️ TIME COMPLEXITY: fixed cheat-sheet of keywords = O(1); generalized to
 m keywords over string length L = O(m*L). Space O(1).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 The moment an interview question appears, you must catch its keywords
 like a detective. Just as traffic police decide the route the moment
 they see a signal, keywords decide the pattern. "Longest substring"
 flashes "sliding window", "kth largest" flashes "heap", "cycle"
 flashes "fast-slow". This decision flowchart is the detective's
 handbook for interviews.

 📖 THEORY:
 - Pattern identification is a keyword-to-pattern mapping problem.
 - Decision flowchart:
   Is input sorted or pair/sum from both ends?          -> Two Pointers
   Is it contiguous subarray/substring?                 -> Sliding Window
   Many range sum queries or subarray sum equals k?     -> Prefix Sum + HashMap
   Linked list cycle/middle or array-as-next-pointer?   -> Fast-Slow Pointers
   Intervals/meetings/timeline overlap?                 -> Merge Intervals
   Array has numbers 1..n, missing/duplicate?           -> Cyclic Sort
   kth / top-k / closest / frequent?                    -> Heap
   All combinations/permutations/subsets?               -> Backtracking
   Local best with proof, scheduling/min jumps?         -> Greedy
   Repeated recursion states, min/max ways?             -> DP
 - The program lowercases the question and runs simple keyword
   substring checks against this fixed rule set.

 DECISION FLOWCHART:
      input sorted / pair from ends ? ──> Two Pointers
      contiguous subarray / substring ? ──> Sliding Window
      range sum equals k ? ──> Prefix Sum + HashMap
      cycle / middle ? ──> Fast-Slow Pointers
      intervals / meetings overlap ? ──> Merge Intervals
      numbers 1..n, missing / duplicate ? ──> Cyclic Sort
      kth / top-k / closest / frequent ? ──> Heap
      all combinations / subsets ? ──> Backtracking
      local best with proof / scheduling ? ──> Greedy
      repeated states / min / max ways ? ──> DP

 🧠 LOGIC — STEP BY STEP:
 Step 1: Lowercase the whole question.
    WHY: Keyword search must be case-insensitive so "Top K" matches "top k".
 Step 2: Check the "sorted / pair" keywords first.
    WHY: Sorted inputs or pair-sums from both ends are the classic two
    pointer trigger.
 Step 3: Check "substring / subarray", "range sum", "cycle / middle",
    "interval / meeting", "1 to n / missing / duplicate".
    WHY: Each family of trigger words maps to exactly one pattern branch.
 Step 4: Check "top k / kth / frequent", "all / permutation".
    WHY: These signal heap and backtracking respectively.
 Step 5: Check "minimum / maximum / ways".
    WHY: Optimization requests are greedy or DP — prove greedy first,
    else fall back to DP.
 Step 6: If nothing matches, start with brute force.
    WHY: Brute force exposes the input size and structure, which then
    reveals the right pattern.

 DRY RUN:
   "Find kth largest element"                    -> Top K Heap
   "Longest substring with k distinct chars"     -> Sliding Window / Prefix Sum
   "Merge overlapping meeting intervals"         -> Merge Intervals
   "Generate all permutations"                   -> Backtracking
   "minimum coins"                               -> Greedy or DP (prove greedy first)

 FLOW OF EXECUTION:
   read question -> lowercase -> keyword checks in fixed order
   -> return matched pattern -> print result

 TIME COMPLEXITY CALCULATION:
 - identifyPattern checks a fixed list of ~10 keyword conditions.
 - Number of patterns/keywords is constant for this demo.
 - Each find() scans the question string, but the rule set is bounded.
 -> Time Complexity = O(1) for the fixed interview cheat sheet;
    O(m*L) if generalized to m keywords against string length L.

 SPACE COMPLEXITY CALCULATION:
 - Only a fixed set of rules and the input string are stored.
 -> Space Complexity = O(1) fixed rules.

 APPROACH COMPARISON TABLE:
 | Signal           | Pattern            | Real-world analogy        | Template             |
 | sorted pair      | two pointers       | two guards from gates     | l/r move             |
 | contiguous       | sliding window     | camera frame              | expand/shrink        |
 | top-k            | heap               | priority shortlist         | heap size k          |
 | all choices      | backtracking       | maze choices              | choose-explore-undo  |
 | repeated states  | DP                 | notebook memory           | memo/tabulate        |
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

string identifyPattern(const string& question) {
    string q = question;
    transform(q.begin(), q.end(), q.begin(), ::tolower);
    if (q.find("sorted") != string::npos || q.find("pair") != string::npos) return "Two Pointers";
    if (q.find("substring") != string::npos || q.find("subarray") != string::npos) return "Sliding Window / Prefix Sum";
    if (q.find("range sum") != string::npos) return "Prefix Sum";
    if (q.find("cycle") != string::npos || q.find("middle") != string::npos) return "Fast-Slow / DFS depending structure";
    if (q.find("interval") != string::npos || q.find("meeting") != string::npos) return "Merge Intervals";
    if (q.find("1 to n") != string::npos || q.find("missing") != string::npos || q.find("duplicate") != string::npos) return "Cyclic Sort / Fast-Slow";
    if (q.find("top k") != string::npos || q.find("kth") != string::npos || q.find("frequent") != string::npos) return "Top K Heap";
    if (q.find("all") != string::npos || q.find("permutation") != string::npos) return "Backtracking";
    if (q.find("minimum") != string::npos || q.find("maximum") != string::npos || q.find("ways") != string::npos) return "Greedy or DP: prove greedy, else DP";
    return "Start with brute force, then search pattern signals";
}

int main() {
    vector<string> questions = {
        "Find kth largest element",
        "Longest substring with k distinct characters",
        "Merge overlapping meeting intervals",
        "Generate all permutations"
    };
    for (const string& q : questions) {
        cout << q << " -> " << identifyPattern(q) << "\n";
    }
    return 0;
}

/*
OUTPUT:
Find kth largest element -> Top K Heap
Longest substring with k distinct characters -> Sliding Window / Prefix Sum
Merge overlapping meeting intervals -> Merge Intervals
Generate all permutations -> Backtracking
*/

