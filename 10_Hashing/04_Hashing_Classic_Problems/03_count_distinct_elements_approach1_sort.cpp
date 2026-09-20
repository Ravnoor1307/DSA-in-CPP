/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_count_distinct_elements_approach1_sort.cpp
│
│ REAL-WORLD SCENARIO:
│ Attendance roll numbers ko sort kar do, duplicates saath-saath aa jayenge. Distinct count sorted array me adjacent comparison se milta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Array copy sort karo.
│ 2. First element distinct count 1.
│ 3. Har next element previous se different ho to count++.
│ 4. Sorting makes duplicates adjacent.
│ 5. Time sorting ki wajah se O(n log n).
│
│ ASCII VISUAL / HASH STATE:
│ arr=[4,2,4,3,2]
│ sorted=[2,2,3,4,4]
│ distinct groups: [2,2], [3], [4,4]
│ count=3
│
│ DRY RUN:
│ sorted array scan:
│ i1 2 same as prev -> no
│ i2 3 diff -> count2
│ i3 4 diff -> count3
│ i4 4 same -> no
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Sorting n items takes O(n log n).
│ - Log derivation: n/2^k=1 -> k=log₂n.
│ - Final scan n-1 comparisons -> O(n).
│ -> Total Time Complexity = O(n log n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Copy sorted vector stores n items.
│ -> Space Complexity = O(n).
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

int countDistinctSort(vector<int> arr) {
    if (arr.empty()) return 0;
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int i = 1; i < (int)arr.size(); i++) if (arr[i] != arr[i-1]) count++;
    return count;
}

int main() {
    vector<int> arr = {4,2,4,3,2};
    cout << "Distinct count sort = " << countDistinctSort(arr) << "\n";
    return 0;
}

/*
OUTPUT:
Distinct count sort = 3
*/

