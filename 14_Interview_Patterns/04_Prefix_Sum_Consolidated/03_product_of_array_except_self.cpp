/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_product_of_array_except_self.cpp
│
│ REAL-WORLD SCENARIO:
│ Factory line me each station ko apne alawa baaki stations ka product chahiye. Left side products and right side products multiply karo.
│
│ VISUAL / PATTERN STATE:
│ nums = [1,2,3,4]
│
│ Left products excluding self:
│ left:  [1,1,2,6]
│        index2 ke left product = 1*2 = 2
│
│ Right products excluding self:
│ right: [24,12,4,1]
│        index2 ke right product = 4
│
│ answer[i] = left[i] * right[i]
│ answer = [24,12,8,6]
│
│ Space optimized:
│ answer first stores left products.
│ Then right product variable from right side multiply.

│
│ STEP-BY-STEP DRY RUN:
│ First pass:
│ ans[0]=1, left=1
│ after nums0, left=1
│ ans[1]=1, left=2
│ ans[2]=2, left=6
│ ans[3]=6, left=24
│
│ Right pass multiplies by right running product.

│
│ COMPLEXITY CALCULATION:
│ First pass n iterations.
│ Second pass n iterations.
│ Total = 2n -> O(n).
│ Output array required O(n).
│ Extra space excluding output = one right variable -> O(1).

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

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    int left = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= right; // left product already stored, right product now multiply.
        right *= nums[i];
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    for (int x : ans) cout << x << ' ';
    cout << "\n";
    return 0;
}

/*
OUTPUT:
24 12 8 6
*/

