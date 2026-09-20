/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_count_distinct_elements_approach2_set.cpp
│
│ REAL-WORLD SCENARIO:
│ Unique entry gate par duplicate roll numbers automatically ignore ho jaate hain. Hash set se distinct elements count karna direct hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. unordered_set<int> create karo.
│ 2. Har array element set me insert karo.
│ 3. Duplicates automatically ignored.
│ 4. Set size = distinct count.
│ 5. Average O(n) solution.
│
│ ASCII VISUAL / HASH STATE:
│ arr=[4,2,4,3,2]
│ insert 4 -> {4}
│ insert 2 -> {4,2}
│ insert 4 -> duplicate ignored
│ insert 3 -> {4,2,3}
│ insert 2 -> duplicate ignored
│ distinct=3
│
│ DRY RUN:
│ process 5 elements.
│ set final unique keys 2,3,4.
│ size=3.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Loop visits n elements.
│ - Each unordered_set insert average O(1).
│ - Total average = n*O(1).
│ -> Average Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Set stores d distinct elements, d<=n.
│ -> Space Complexity = O(d), worst O(n).
│ APPROACH COMPARISON TABLE:
│ Sorting = arrange roll numbers together, O(n log n) time/O(n) copy.
│ Hash set = unique entry gate, O(n) average time/O(n) space.
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
    vector<int> arr = {4,2,4,3,2};
    unordered_set<int> st;
    for (int x : arr) st.insert(x);
    cout << "Distinct count set = " << st.size() << "\n";
    cout << "Comparison: sort O(n log n), hash set O(n) average.\n";
    return 0;
}

/*
OUTPUT:
Distinct count set = 3
Comparison: sort O(n log n), hash set O(n) average.
*/

