/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_trapping_rainwater_two_ptr_recap.cpp
│
│ REAL-WORLD SCENARIO:
│ City road ke bars/buildings ke beech rainwater store hota hai. Left max and right max boundaries decide karte hain kitna water trap hoga.
│
│ VISUAL / PATTERN STATE:
│ height = [0,1,0,2,1,0,1,3,2,1,2,1]
│
│ Two pointer idea:
│ left=0, right=n-1
│ leftMax, rightMax maintain karo.
│ Jis side ka height smaller, us side ka water decide ho sakta hai.
│
│ Visual:
│ left boundary  |__water__| right boundary
│ water at i = min(leftMax, rightMax) - height[i]

│
│ STEP-BY-STEP DRY RUN:
│ Move left while height[left] < height[right].
│ update leftMax.
│ if height[left] < leftMax, trapped += leftMax-height[left].
│ Similarly for right side.
│ For sample answer = 6.

│
│ COMPLEXITY CALCULATION:
│ left moves forward at most n times.
│ right moves backward at most n times.
│ Total moves <= n.
│ Each step constant comparisons/additions.
│ Time = O(n).
│ Space = O(1).

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

int trap(vector<int>& height) {
    int l = 0, r = (int)height.size() - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (l < r) {
        if (height[l] < height[r]) {
            leftMax = max(leftMax, height[l]);
            water += leftMax - height[l]; // Left side boundary final hai.
            l++;
        } else {
            rightMax = max(rightMax, height[r]);
            water += rightMax - height[r];
            r--;
        }
    }
    return water;
}

int main() {
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water = " << trap(h) << "\n";
    return 0;
}

/*
OUTPUT:
Trapped water = 6
*/

