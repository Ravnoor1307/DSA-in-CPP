/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_find_duplicate_number.cpp
│
│ REAL-WORLD SCENARIO:
│ Array values next pointers ki tarah behave kar sakti hain. nums[i] = next index maan lo; duplicate value cycle entry ban jata hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ nums = [1,3,4,2,2]
│ index: 0 1 2 3 4
│ value: 1 3 4 2 2
│
│ Implicit linked list:
│ 0 -> 1 -> 3 -> 2 -> 4
│                ^    |
│                |____|
│
│ Cycle entry = 2 = duplicate.
│
│ Phase 1: slow/fast meet inside cycle.
│ Phase 2: one pointer start at nums[0], both move 1 step.
│ Meeting point = duplicate.

│
│ STEP-BY-STEP DRY RUN:
│ Phase1:
│ slow=nums[0]=1, fast=nums[nums[0]]=3
│ slow=nums[1]=3, fast=nums[nums[3]]=4
│ slow=nums[3]=2, fast=nums[nums[4]]=4
│ slow=nums[2]=4, fast=nums[nums[4]]=4 meet
│
│ Phase2:
│ finder=0, slow=4
│ finder=1, slow=2
│ finder=3, slow=4
│ finder=2, slow=2 meet duplicate=2

│
│ COMPLEXITY CALCULATION:
│ Floyd pointer movement follows implicit linked list.
│ Phase1 at most O(n) moves.
│ Phase2 at most O(n) moves.
│ Total = O(n).
│ No modification and only pointers -> O(1) space.

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

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
        cout << "phase1 slow=" << slow << " fast=" << fast << "\n";
    } while (slow != fast);

    int finder = nums[0];
    while (finder != slow) {
        finder = nums[finder];
        slow = nums[slow];
        cout << "phase2 finder=" << finder << " slow=" << slow << "\n";
    }
    return finder;
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << "Duplicate = " << findDuplicate(nums) << "\n";
    return 0;
}

/*
OUTPUT:
phase1 slow=3 fast=2
phase1 slow=2 fast=2
Duplicate = 2
*/

