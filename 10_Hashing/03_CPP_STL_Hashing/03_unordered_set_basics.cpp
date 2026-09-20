/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_unordered_set_basics.cpp
│
│ REAL-WORLD SCENARIO:
│ Exam hall entry list me roll number ek hi baar allowed hai. `unordered_set` sirf unique keys store karta hai; duplicates auto-remove ho jaate hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. `unordered_set<T>` only keys store karta hai.
│ 2. Duplicate insert ignored hota hai.
│ 3. `count(x)` 1 if present, 0 if absent.
│ 4. `find(x)` presence check ke liye use hota hai.
│ 5. Average insert/search/delete O(1).
│
│ ASCII VISUAL / HASH STATE:
│ Insert sequence: 5, 2, 5, 7, 2
│
│ Set visual unique keys:
│ {2,5,7}
│
│ duplicates:
│ second 5 ignored
│ second 2 ignored
│
│ DRY RUN:
│ insert5 -> set {5}
│ insert2 -> {5,2}
│ insert5 -> duplicate ignored
│ insert7 -> {5,2,7}
│ count5 -> 1
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Each insert/search average hash + constant bucket check.
│ -> Average Time Complexity = O(1).
│ - Printing all unique elements visits d elements.
│ -> Iteration Time Complexity = O(d), d distinct count.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stores only d distinct keys.
│ -> Space Complexity = O(d).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    unordered_set<int> seen;
    for (int x : {5, 2, 5, 7, 2}) seen.insert(x);
    vector<int> sorted(seen.begin(), seen.end());
    sort(sorted.begin(), sorted.end());
    cout << "Unique keys: ";
    for (int x : sorted) cout << x << " ";
    cout << "\ncount(5) = " << seen.count(5) << "\n";
    return 0;
}

/*
OUTPUT:
Unique keys: 2 5 7
count(5) = 1
*/

