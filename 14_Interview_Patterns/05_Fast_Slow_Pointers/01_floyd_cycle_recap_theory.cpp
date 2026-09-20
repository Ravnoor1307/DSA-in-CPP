/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_floyd_cycle_recap_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Circular race track par fast runner slow runner ko zaroor pakadta hai. Linked list cycle me fast pointer 2 steps and slow pointer 1 step chalta hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ Floyd cycle detection:
│
│ 1 -> 2 -> 3 -> 4 -> 5
│           ^         |
│           |_________|
│
│ slow = slow->next
│ fast = fast->next->next
│
│ Math proof:
│ Cycle length = C.
│ Inside cycle, har iteration fast slow se 1 extra step gain karta hai.
│ Gap changes: gap, gap-1, gap-2 ... modulo C.
│ Maximum C iterations me gap 0 ho jayega.
│ Therefore meet guaranteed if cycle exists.

│
│ STEP-BY-STEP DRY RUN:
│ Step trace:
│ start slow=1, fast=1
│ step1 slow=2, fast=3
│ step2 slow=3, fast=5
│ step3 slow=4, fast=4 -> meet

│
│ COMPLEXITY CALCULATION:
│ Non-cycle list: fast 2 steps leta hai, about n/2 iterations me null.
│ Cycle list: entry path <= n, then meet within cycle length <= n.
│ Total = O(n).
│ Space = two pointers -> O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    cout << "Floyd = slow 1 step, fast 2 steps\n";
    cout << "Inside cycle fast gains 1 position per iteration.\n";
    cout << "If cycle length C, max C gap changes until meet.\n";
    return 0;
}

/*
OUTPUT:
Floyd = slow 1 step, fast 2 steps
Inside cycle fast gains 1 position per iteration.
If cycle length C, max C gap changes until meet.
*/

