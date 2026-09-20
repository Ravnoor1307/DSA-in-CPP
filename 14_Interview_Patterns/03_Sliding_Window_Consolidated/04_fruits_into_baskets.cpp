/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_fruits_into_baskets.cpp
│
│ REAL-WORLD SCENARIO:
│ Fruit baskets me at most 2 fruit types aa sakte hain. Contiguous trees se fruits pick karne hain; type count 2 se zyada ho to left side se fruits remove karo.
│
│ VISUAL / PATTERN STATE:
│ fruits = [1,2,1,2,3]
│ At most 2 distinct types.
│
│ Window:
│ [1] distinct1 best1
│ [1,2] distinct2 best2
│ [1,2,1] distinct2 best3
│ [1,2,1,2] distinct2 best4
│ add3 -> [1,2,1,2,3] distinct3 invalid
│ shrink until two types -> [2,3]
│ best = 4
│
│ This is AT MOST K template with K=2.

│
│ STEP-BY-STEP DRY RUN:
│ Use freq map of fruit types.
│ right adds fruit.
│ while freq.size()>2, decrement fruits[left], erase zero, left++.
│ best window length track.

│
│ COMPLEXITY CALCULATION:
│ right moves n, left moves n total.
│ Each update average O(1).
│ Total O(n).
│ Map stores at most 3 types during shrink -> O(1) for K=2.

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

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> freq;
    int left = 0, best = 0;
    for (int right = 0; right < (int)fruits.size(); right++) {
        freq[fruits[right]]++;
        while ((int)freq.size() > 2) {
            int f = fruits[left];
            freq[f]--;
            if (freq[f] == 0) freq.erase(f);
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    vector<int> fruits = {1,2,1,2,3};
    cout << "Max fruits = " << totalFruit(fruits) << "\n";
    return 0;
}

/*
OUTPUT:
Max fruits = 4
*/

