/*
REAL-WORLD SCENARIO:
Roll number seating system me missing and duplicate seats find karne hain.

TASKS easy -> hard:
1. Cyclic sort implement karo.
2. Missing number 0..n solve karo.
3. All duplicates find karo.
4. Disappeared numbers find karo.
5. First missing positive solve karo.
6. Har swap ka state comments me draw karo.

HINTS:
- 1..n: correct index = value-1.
- 0..n: correct index = value if value<n.
- duplicate guard zaruri hai.

STARTER CODE:
while (i < n) { }

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cyclicSort(vector<int>& nums) {
    int i = 0;
    while (i < (int)nums.size()) {
        int correct = nums[i] - 1;
        if (nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
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
1 2 3 4 5
*/
