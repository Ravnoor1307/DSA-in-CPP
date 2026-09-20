/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_jump_game_approach1_bruteforce.cpp
│
│ REAL-WORLD SCENARIO:
│ Game board me har index se nums[i] steps tak jump kar sakte ho. Brute DP style check karta hai ki each position kisi previous reachable position se reachable hai ya nahi.
│
│ ASCII VISUAL / DECISION STATE:
│ nums = [2,3,1,1,4]
│
│ reachable initially:
│ index0 true
│
│ For each i, scan previous j:
│ i=1: j=0, 0+2>=1 -> reachable
│ i=2: j=0, 0+2>=2 -> reachable
│ i=3: j=1, 1+3>=3 -> reachable
│ i=4: j=1, 1+3>=4 -> reachable
│
│ reachable [T,T,T,T,T] -> can reach end.

│
│ STEP-BY-STEP DRY RUN:
│ Nested loops:
│ for i from1 to n-1:
│   for j from0 to i-1:
│      if reachable[j] and j+nums[j]>=i, mark reachable[i].

│
│ COMPLEXITY CALCULATION:
│ For i=1 checks 1 previous.
│ i=2 checks up to 2.
│ ... i=n-1 checks up to n-1.
│ Total = 1+2+...+(n-1)=n(n-1)/2 -> O(n²).
│ Space reachable array n -> O(n).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

bool canJumpBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> reachable(n, 0);
    reachable[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (reachable[j] && j + nums[j] >= i) {
                reachable[i] = 1;
                cout << "index " << i << " reachable from " << j << "\n";
                break;
            }
        }
    }
    return reachable[n-1];
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << "Can jump? " << (canJumpBrute(nums) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
index 1 reachable from 0
index 2 reachable from 0
index 3 reachable from 1
index 4 reachable from 1
Can jump? YES
*/

