/*
═══════════════════════════════════════════════
 TASK SET — IDENTIFY THE PATTERN
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: In the interview room you must name the
    pattern the moment you read the question — before writing any code.
    A detective-style keyword scan saves your time and guides your
    approach for the rest of the interview.

 🧠 HOW TO SOLVE: Download the question, scan it for signal keywords,
    and map each keyword family to its pattern: sorted/pair -> two
    pointers, contiguous -> sliding window, top-k -> heap, all
    combinations -> backtracking, overlapping/repeated states -> DP.

 MODES/TOPICS COVERED:
   1. Write a table of the 10 patterns
   2. Write each pattern's key signal
   3. Map 5 sample questions to their patterns
   4. Build a decision flowchart in comments
   5. Write greedy vs DP identification rules
═══════════════════════════════════════════════
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string identify(string q) {
    transform(q.begin(), q.end(), q.begin(), ::tolower);
    if (q.find("kth") != string::npos || q.find("top") != string::npos) return "Heap";
    if (q.find("substring") != string::npos || q.find("subarray") != string::npos) return "Sliding Window/Prefix Sum";
    if (q.find("interval") != string::npos || q.find("meeting") != string::npos) return "Merge Intervals";
    if (q.find("all") != string::npos) return "Backtracking";
    return "Analyze brute force first";
}

int main() {
    cout << identify("top k frequent elements") << "\n";
    cout << identify("minimum window substring") << "\n";
    return 0;
}

/*
OUTPUT:
Heap
Sliding Window/Prefix Sum
*/
