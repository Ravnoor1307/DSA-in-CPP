/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_subarray_sum_equals_k_hashmap.cpp
│
│ REAL-WORLD SCENARIO:
│ Bank transactions stream me kitne contiguous periods ka total exactly k hai? Prefix balance and old balances frequency hashmap se count milta hai.
│
│ VISUAL / PATTERN STATE:
│ nums = [1,2,3], k=3
│
│ prefix sum table:
│ i | num | sum | need=sum-k | freq before | count
│ 0 | 1   | 1   | -2         | 0           | 0
│ 1 | 2   | 3   | 0          | 1           | 1  subarray [1,2]
│ 2 | 3   | 6   | 3          | 1           | 2  subarray [3]
│
│ freq initially {0:1} means empty prefix.

│
│ STEP-BY-STEP DRY RUN:
│ running sum = 0, count = 0.
│ For each x:
│   sum += x
│   need = sum - k
│   count += freq[need]
│   freq[sum]++

│
│ COMPLEXITY CALCULATION:
│ Loop runs n times.
│ Each iteration does constant hashmap average operations: lookup need and update sum.
│ Time = O(n) average.
│ Space stores up to n+1 prefix sums -> O(n).

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

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    freq[0] = 1;
    int sum = 0, count = 0;
    for (int x : nums) {
        sum += x;
        int need = sum - k;
        if (freq.count(need)) count += freq[need];
        freq[sum]++; // Current prefix future subarrays ke liye store.
        cout << "x=" << x << " sum=" << sum << " need=" << need << " count=" << count << "\n";
    }
    return count;
}

int main() {
    vector<int> nums = {1,2,3};
    cout << "Subarrays sum k = " << subarraySum(nums, 3) << "\n";
    return 0;
}

/*
OUTPUT:
x=1 sum=1 need=-2 count=0
x=2 sum=3 need=0 count=1
x=3 sum=6 need=3 count=2
Subarrays sum k = 2
*/

