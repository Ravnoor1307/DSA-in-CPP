/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_group_elements_by_frequency.cpp
│
│ REAL-WORLD SCENARIO:
│ Voting result board me elements ko unki frequency ke group me display karna hai: highest vote wale pehle. Hash map count karta hai, sorting display order set karti hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Frequency map banao.
│ 2. Map pairs ko vector me convert karo.
│ 3. Sort by frequency descending.
│ 4. Tie ke liye value ascending rakho for deterministic output.
│ 5. Print element repeated frequency times ya group summary.
│
│ ASCII VISUAL / PREFIX-WINDOW STATE:
│ arr=[4,4,4,2,2,1,3,3]
│ freq:
│ 4:3
│ 2:2
│ 3:2
│ 1:1
│
│ grouped by frequency:
│ freq3: 4
│ freq2: 2,3
│ freq1: 1
│
│ DRY RUN:
│ count pass builds map.
│ pairs: (4,3),(2,2),(1,1),(3,2)
│ sort -> (4,3),(2,2),(3,2),(1,1)
│ print groups.
│
│ FLOW OF EXECUTION:
│ input array -> prefix/frequency/window/hash state -> detect/update answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - Frequency build scans n elements, average O(1) update each -> O(n).
│ - Suppose d distinct elements.
│ - Sorting d pairs costs O(d log d).
│ - Log proof: d/2^k=1 -> k=log₂d.
│ -> Total Time Complexity = O(n + d log d).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map and vector store d pairs.
│ -> Space Complexity = O(d), d<=n.
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
    vector<int> arr = {4,4,4,2,2,1,3,3};
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    vector<pair<int,int>> items(freq.begin(), freq.end());
    sort(items.begin(), items.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    cout << "Elements by frequency: ";
    for (auto p : items) cout << p.first << "(" << p.second << ") ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Elements by frequency: 4(3) 2(2) 3(2) 1(1)
*/

