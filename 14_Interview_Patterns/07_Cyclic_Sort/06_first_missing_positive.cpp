/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_first_missing_positive.cpp
│
│ REAL-WORLD SCENARIO:
│ Positive roll numbers me smallest missing positive find karna hai. Useful numbers sirf 1..n hain; unhe correct seats par place karo.
│
│ ASCII VISUAL / PATTERN STATE:
│ nums = [3,4,-1,1]
│ n=4, useful values 1..4 only
│
│ value3 belongs index2 -> swap [ -1,4,3,1]
│ value-1 ignore
│ value4 belongs index3 -> swap [-1,1,3,4]
│ value1 belongs index0 -> swap [1,-1,3,4]
│
│ Scan:
│ index0 has1 OK
│ index1 should have2 but has-1 -> answer 2

│
│ STEP-BY-STEP DRY RUN:
│ While nums[i] in [1,n] and not at correct index:
│ swap nums[i] with nums[nums[i]-1].
│ Then first index i with nums[i] != i+1 gives answer i+1.
│ If all seats correct, answer n+1.

│
│ COMPLEXITY CALCULATION:
│ Each swap places one valid positive in correct seat.
│ Swaps <= n.
│ Scan n.
│ Time = O(n).
│ Space = O(1).

│ APPROACH COMPARISON TABLE:
│ | Cyclic problem | Seat rule | Signal | Time | Space |
│ | Sort 1..n | x -> x-1 | all values 1..n | O(n) | O(1) |
│ | Missing number 0..n | x -> x | one missing | O(n) | O(1) |
│ | Duplicates | x -> x-1 with duplicate guard | repeated values | O(n) | O(1) |
│ | Disappeared | mismatch seats | missing multiple | O(n) | O(1) |
│ | First missing positive | only 1..n useful | negatives/large values | O(n) | O(1) |
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

int firstMissingPositive(vector<int> nums) {
    int n = nums.size();
    int i = 0;
    while (i < n) {
        int x = nums[i];
        int correct = x - 1;
        if (x >= 1 && x <= n && nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
    }
    for (int idx = 0; idx < n; idx++) if (nums[idx] != idx + 1) return idx + 1;
    return n + 1;
}

int main() {
    vector<int> nums = {3,4,-1,1};
    cout << "First missing positive = " << firstMissingPositive(nums) << "\n";
    return 0;
}

/*
OUTPUT:
First missing positive = 2
*/

