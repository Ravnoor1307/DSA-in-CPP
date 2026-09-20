/*
REAL-WORLD SCENARIO:
Meeting room, railway platform, game jump, and candy distribution greedy practice.

TASKS easy -> hard:
1. Greedy proof checklist likho.
2. Activity selection implement karo.
3. Min platforms implement karo.
4. Jump game O(n²) brute implement karo.
5. Jump game O(n) greedy implement karo.
6. Candy distribution two-pass solve karo.
7. Har problem ka local choice explain karo.

HINTS:
- Activity: earliest end.
- Platform: arrivals/departures sorted.
- Jump: farthest reach.
- Candy: left-to-right then right-to-left.

STARTER CODE:
int farthest = 0;

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int> nums) {
    int farthest = 0;
    for (int i=0;i<(int)nums.size();i++) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

int main() {
    cout << (canJump({2,3,1,1,4}) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
YES
*/
