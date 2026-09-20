/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_cyclic_sort_intuition_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Classroom me roll numbers 1 to n hain. Har student ko apni correct seat par bithao: number x ki seat index x-1. Ye cyclic sort hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ SIGNAL:
│ array has numbers 1 to n
│ find missing / duplicate / disappeared
│ O(n) time, O(1) extra expected
│
│ Seat mapping:
│ value 1 -> index 0
│ value 2 -> index 1
│ value 3 -> index 2
│ ...
│ value x -> index x-1
│
│ Example [3,1,5,4,2]
│ index0 has3 but should have1.
│ value3 belongs index2, so swap index0 and index2.

│
│ STEP-BY-STEP DRY RUN:
│ i=0 [3,1,5,4,2], correct index for3 is2 -> swap
│ [5,1,3,4,2], 5 belongs4 -> swap
│ [2,1,3,4,5], 2 belongs1 -> swap
│ [1,2,3,4,5], i++ onward sorted.

│
│ COMPLEXITY CALCULATION:
│ Each swap places at least one number at correct index.
│ Total useful swaps <= n.
│ i moves from 0 to n.
│ Time = O(n).
│ Extra space = O(1).

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
    cout << "Cyclic sort signal: numbers 1 to n and missing/duplicate asked.\n";
    cout << "Seat formula: correctIndex = nums[i] - 1\n";
    cout << "Swap until every number sits on its seat.\n";
    return 0;
}

/*
OUTPUT:
Cyclic sort signal: numbers 1 to n and missing/duplicate asked.
Seat formula: correctIndex = nums[i] - 1
Swap until every number sits on its seat.
*/

