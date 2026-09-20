/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_two_sum_approach2_hashmap.cpp
│
│ REAL-WORLD SCENARIO:
│ Budget shopping me current item ke saath required complement instantly previous bills map me dhundho. Ye interview #1 hashing pattern hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Map value -> index store karta hai.
│ 2. Har arr[i] ke liye complement = target - arr[i].
│ 3. Agar complement map me hai, answer found.
│ 4. Otherwise current value map me store karo.
│ 5. One pass me pair mil jata hai.
│
│ ASCII VISUAL / HASH STATE:
│ arr=[2,7,11,15], target=9
│
│ i=0, x=2, complement=7
│ map: {} -> 7 absent -> store 2:0
│
│ i=1, x=7, complement=2
│ map: {2:0} -> 2 present -> answer (0,1)
│
│ Visual: current + complement = target
│
│ DRY RUN:
│ Step 1: x=2, need7, map empty, store 2->0.
│ Step 2: x=7, need2, map has 2 at index0, return 0,1.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Loop visits n elements once.
│ - Each find/insert average O(1) due hash table.
│ - Total average = n * O(1).
│ -> Average Time Complexity = O(n).
│ - Worst collisions can make map ops O(n), but expected average is O(1).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Map can store up to n previous elements.
│ -> Space Complexity = O(n).
│ APPROACH COMPARISON TABLE:
│ Brute force = try every item pair, O(n²) time/O(1) space.
│ Hashmap = remember previous prices and find complement, O(n) average time/O(n) space.
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

pair<int,int> twoSumHash(const vector<int>& arr, int target) {
    unordered_map<int, int> indexOf;
    for (int i = 0; i < (int)arr.size(); i++) {
        int x = arr[i];
        int need = target - x;
        cout << "i=" << i << ", x=" << x << ", need=" << need << "\n";
        if (indexOf.count(need)) return {indexOf[need], i};
        indexOf[x] = i;
        cout << "store " << x << " -> " << i << "\n";
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {2,7,11,15};
    pair<int,int> ans = twoSumHash(arr, 9);
    cout << "indices = " << ans.first << ", " << ans.second << "\n";
    return 0;
}

/*
OUTPUT:
i=0, x=2, need=7
store 2 -> 0
i=1, x=7, need=2
indices = 0, 1
*/

