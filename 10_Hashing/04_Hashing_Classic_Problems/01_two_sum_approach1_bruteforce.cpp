/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_two_sum_approach1_bruteforce.cpp
│
│ REAL-WORLD SCENARIO:
│ Shop me two items ka total budget target ke equal chahiye. Brute force har pair try karta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Outer loop first item choose karta hai.
│ 2. Inner loop second item choose karta hai.
│ 3. Agar arr[i]+arr[j]==target, pair found.
│ 4. No extra memory needed.
│ 5. Simple but O(n²).
│
│ ASCII VISUAL / HASH STATE:
│ arr=[2,7,11,15], target=9
│ Pairs:
│ (2,7)=9 found
│
│ Pair grid:
│ i=0 value2, j=1 value7 -> 2+7=9
│
│ DRY RUN:
│ i=0
│ j=1: 2+7=9 -> found indices 0,1
│ loop stops.
│
│ FLOW OF EXECUTION:
│ input data -> hash map/set operation -> update/check state -> output answer
│
│ COMPLEXITY CALCULATION:
│ - Outer loop can run n times.
│ - Inner loop can run up to n times for each i.
│ - Pair checks about n(n-1)/2.
│ -> Time Complexity = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Only loop variables.
│ -> Extra Space Complexity = O(1).
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

pair<int,int> twoSumBrute(const vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return {i, j};
        }
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {2,7,11,15};
    pair<int,int> ans = twoSumBrute(arr, 9);
    cout << "indices = " << ans.first << ", " << ans.second << "\n";
    return 0;
}

/*
OUTPUT:
indices = 0, 1
*/

