/*
REAL-WORLD SCENARIO:
Interview warm-up: sorted arrays, bars, triplets, rainwater, and linked-list race track.

TASKS easy -> hard:
1. Two pointer variants comments me explain karo.
2. Container with most water solve karo.
3. 3Sum brute force likho.
4. 3Sum sort + two pointers likho.
5. Trapping rainwater two pointer solve karo.
6. Linked list cycle fast-slow detect karo.
7. Har solution ka pointer state dry run comments me likho.

HINTS:
- Sorted pair: sum small -> left++, sum big -> right--.
- 3Sum: fix i, run two-sum on right side.
- Cycle: slow one step, fast two steps.

STARTER CODE:
int l = 0, r = n - 1;

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> h) {
    int l=0, r=(int)h.size()-1, best=0;
    while (l<r) {
        best = max(best, min(h[l], h[r]) * (r-l));
        if (h[l] < h[r]) l++; else r--;
    }
    return best;
}

int main() {
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << "max water=" << maxArea(h) << "\n";
    return 0;
}

/*
OUTPUT:
max water=49
*/
