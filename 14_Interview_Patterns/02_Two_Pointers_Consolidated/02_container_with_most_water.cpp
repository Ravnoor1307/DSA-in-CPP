/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_container_with_most_water.cpp
│
│ REAL-WORLD SCENARIO:
│ Water tank banane ke liye two walls choose karni hain. Width farthest ends se max hoti hai, but height smaller wall decide karti hai. Isliye smaller pointer move karte hain.
│
│ VISUAL / PATTERN STATE:
│ Heights:
│ index:   0 1 2 3 4 5 6 7 8
│ height: [1,8,6,2,5,4,8,3,7]
│
│ Water area = min(height[l], height[r]) * (r-l)
│
│ Start:
│ l=0 h=1, r=8 h=7, width=8, area=8
│ Smaller wall left hai, l++.
│
│ Why smaller move?
│ Current water height smaller wall se limited hai.
│ Larger wall move karne se width kam hogi aur height limit same/smaller reh sakti hai.
│ Better chance only smaller wall replace karne me hai.

│
│ STEP-BY-STEP DRY RUN:
│ l0,r8 area8 best8 -> move l
│ l1,r8 min(8,7)*7=49 best49 -> move r
│ l1,r7 min(8,3)*6=18 -> move r
│ l1,r6 min(8,8)*5=40 -> move r
│ ... best remains49.

│
│ COMPLEXITY CALCULATION:
│ l starts 0 and only increases.
│ r starts n-1 and only decreases.
│ Total pointer moves at most n-1.
│ Each step constant area calculation.
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

int maxArea(vector<int>& height) {
    int l = 0, r = (int)height.size() - 1, best = 0;
    while (l < r) {
        int width = r - l;
        int area = min(height[l], height[r]) * width;
        cout << "l=" << l << " r=" << r << " area=" << area << "\n";
        best = max(best, area);
        if (height[l] < height[r]) l++; // Smaller wall replace karne se chance improve.
        else r--;
    }
    return best;
}

int main() {
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << "Max water = " << maxArea(h) << "\n";
    return 0;
}

/*
OUTPUT:
l=0 r=8 area=8
l=1 r=8 area=49
l=1 r=7 area=18
l=1 r=6 area=40
l=1 r=5 area=16
l=1 r=4 area=15
l=1 r=3 area=4
l=1 r=2 area=6
Max water = 49
*/

