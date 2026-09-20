/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_pattern_recap_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Road ke dono ends par two traffic police khade hain. Sorted road par left/right se decision le sakte hain; linked list me fast-slow se speed difference ka use hota hai.
│
│ VISUAL / PATTERN STATE:
│ Three variants:
│
│ 1. Opposite ends:
│ sorted [1,2,4,7,11]
│          L        R
│ sum too big -> R--
│ sum too small -> L++
│
│ 2. Same direction:
│ remove duplicates / partition
│ slow writes, fast scans
│
│ 3. Fast-slow:
│ linked list middle/cycle
│ slow 1 step, fast 2 steps
│
│ Pattern signal:
│ sorted, pair target, palindrome, reverse, cycle, middle.

│
│ STEP-BY-STEP DRY RUN:
│ Opposite ends dry run target=9:
│ L=1,R=11 sum12 >9 -> R--
│ L=1,R=7 sum8 <9 -> L++
│ L=2,R=7 sum9 found.

│
│ COMPLEXITY CALCULATION:
│ Opposite-end two pointers:
│ Each step moves L or R once.
│ L can move at most n times, R at most n times.
│ Total moves <= 2n -> O(n).
│ Space = O(1).

└────────────────────────────────────────────────────────────┘
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

int main() {
    cout << "Two pointer variants:\n";
    cout << "1. Opposite ends: sorted pair/palindrome\n";
    cout << "2. Same direction: fast scan + slow write\n";
    cout << "3. Fast-slow: cycle/middle\n";
    return 0;
}

/*
OUTPUT:
Two pointer variants:
1. Opposite ends: sorted pair/palindrome
2. Same direction: fast scan + slow write
3. Fast-slow: cycle/middle
*/

