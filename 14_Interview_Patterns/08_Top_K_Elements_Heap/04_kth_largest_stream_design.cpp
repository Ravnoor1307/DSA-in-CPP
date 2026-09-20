/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_kth_largest_stream_design.cpp
│
│ REAL-WORLD SCENARIO:
│ Live leaderboard stream me har naye score ke baad kth largest score chahiye. Min heap size k continuously top-k scores maintain karta hai.
│
│ ASCII VISUAL / PATTERN STATE:
│ k=3, initial nums=[4,5,8,2]
│ min heap size3 after initial:
│ [4,5,8] -> kth largest = 4
│
│ add 3 -> heap [4,5,8], kth=4
│ add 5 -> heap [5,5,8], kth=5
│ add 10 -> heap [5,8,10], kth=5
│ add 9 -> heap [8,9,10], kth=8
│ add 4 -> heap [8,9,10], kth=8

│
│ STEP-BY-STEP DRY RUN:
│ add(val):
│ push val
│ if size > k, pop smallest
│ return heap.top()
│
│ heap.top is kth largest because k largest scores survive and smallest among them is kth.

│
│ COMPLEXITY CALCULATION:
│ Constructor processes n initial values.
│ Each add uses push O(log k), possible pop O(log k).
│ Constructor time O(n log k).
│ Per add time O(log k).
│ Space = O(k).

│ APPROACH COMPARISON TABLE:
│ | Top-K problem | Heap rule | Analogy | Time | Space |
│ | kth largest | min heap size k | top-k survivor club | O(n log k) | O(k) |
│ | k closest | max heap size k | closest rider shortlist | O(n log k) | O(k) |
│ | frequent words | hashmap + heap | trending words board | O(n + m log m) | O(m) |
│ | kth stream | persistent min heap k | live leaderboard | O(log k)/add | O(k) |
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

class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int kValue, vector<int>& nums) : k(kValue) {
        for (int x : nums) add(x);
    }

    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > k) minHeap.pop(); // Smallest top-k survivor remove.
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4,5,8,2};
    KthLargest kth(3, nums);
    for (int x : {3,5,10,9,4}) cout << "add " << x << " -> kth " << kth.add(x) << "\n";
    return 0;
}

/*
OUTPUT:
add 3 -> kth 4
add 5 -> kth 5
add 10 -> kth 5
add 9 -> kth 8
add 4 -> kth 8
*/

