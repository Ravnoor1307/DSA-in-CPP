/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_jump_game_approach2_greedy.cpp
│
│ REAL-WORLD SCENARIO:
│ Game board me farthest reachable checkpoint maintain karo. Agar current index farthest se aage hai, stuck. Otherwise farthest update karte jao.
│
│ ASCII VISUAL / DECISION STATE:
│ nums = [2,3,1,1,4]
│
│ farthest=0
│ i=0 reachable, farthest=max(0,0+2)=2
│ i=1 reachable, farthest=max(2,1+3)=4
│ i=2 reachable, farthest=max(4,2+1)=4
│ i=3 reachable, farthest=4
│ i=4 reachable end
│
│ Answer YES
│
│ Greedy choice:
│ At each reachable index, keep best farthest reach seen so far.

│
│ STEP-BY-STEP DRY RUN:
│ If i > farthest at any time, no previous jump can reach i.
│ If farthest >= n-1, end reachable.

│
│ COMPLEXITY CALCULATION:
│ Single loop n indices.
│ Each index constant max/comparison.
│ Time = O(n).
│ Space = O(1).

│ APPROACH COMPARISON TABLE:
│ | Jump approach | Analogy | Work calculation | Time | Space |
│ | Brute DP scan | check every previous tile | 1+2+...+n | O(n²) | O(n) |
│ | Greedy reach | farthest checkpoint | n single scan | O(n) | O(1) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]); // Best reach so far.
        cout << "i=" << i << " farthest=" << farthest << "\n";
    }
    return true;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << "Can jump? " << (canJump(nums) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
i=0 farthest=2
i=1 farthest=4
i=2 farthest=4
i=3 farthest=4
i=4 farthest=8
Can jump? YES
*/

