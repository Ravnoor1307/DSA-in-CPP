/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_cyclic_sort_implementation.cpp
│
│ REAL-WORLD SCENARIO:
│ Roll numbers 1..n ko seats par arrange karo. Agar nums[i] apni seat par nahi hai, usko correctIndex par swap karo; warna i++.
│
│ ASCII VISUAL / PATTERN STATE:
│ nums = [3,1,5,4,2]
│
│ i=0, nums[0]=3, correct=2 -> swap index0,2
│ [5,1,3,4,2]
│ i=0, nums[0]=5, correct=4 -> swap
│ [2,1,3,4,5]
│ i=0, nums[0]=2, correct=1 -> swap
│ [1,2,3,4,5]
│ i=0 correct -> i=1
│ all correct.

│
│ STEP-BY-STEP DRY RUN:
│ correctIndex = nums[i] - 1.
│ If nums[i] != nums[correctIndex], swap.
│ Else current seat correct, move i.

│
│ COMPLEXITY CALCULATION:
│ Every swap places one number to correct seat.
│ Max swaps <= n-1.
│ i increments at most n times.
│ Total O(n).
│ Space O(1).

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

void cyclicSort(vector<int>& nums) {
    int i = 0;
    while (i < (int)nums.size()) {
        int correct = nums[i] - 1;
        if (nums[i] != nums[correct]) {
            cout << "swap index " << i << " and " << correct << "\n";
            swap(nums[i], nums[correct]);
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> nums = {3,1,5,4,2};
    cyclicSort(nums);
    for (int x : nums) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
swap index 0 and 2
swap index 0 and 4
swap index 0 and 1
1 2 3 4 5
*/

