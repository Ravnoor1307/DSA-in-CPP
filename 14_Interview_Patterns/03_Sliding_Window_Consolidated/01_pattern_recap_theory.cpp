/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_pattern_recap_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ CCTV camera ka frame road ke contiguous part par slide hota hai. Fixed window me size constant hai; variable window me condition ke hisaab se expand/shrink hota hai.
│
│ VISUAL / PATTERN STATE:
│ Fixed window:
│ array [2,1,5,1,3,2], k=3
│ [2,1,5] -> sum8
│   [1,5,1] -> sum7
│     [5,1,3] -> sum9
│       [1,3,2] -> sum6
│
│ Variable window:
│ longest substring with at most K distinct
│ expand right while valid/improving
│ shrink left while invalid
│
│ Signal words:
│ contiguous, subarray, substring, longest, shortest, at most K.

│
│ STEP-BY-STEP DRY RUN:
│ Fixed: add new right, remove old left.
│ Variable: maintain hashmap/frequency.
│ If condition breaks, move left until valid.

│
│ COMPLEXITY CALCULATION:
│ Sliding window pointers left and right each move from 0 to n-1 once.
│ Total moves <= 2n.
│ Hash map operations average O(1).
│ Time = O(n), Space = O(k/charset) depending problem.

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
    cout << "Sliding Window variants:\n";
    cout << "Fixed size: window length k constant\n";
    cout << "Variable size: expand right, shrink left by condition\n";
    cout << "Signal: contiguous subarray/substring\n";
    return 0;
}

/*
OUTPUT:
Sliding Window variants:
Fixed size: window length k constant
Variable size: expand right, shrink left by condition
Signal: contiguous subarray/substring
*/

