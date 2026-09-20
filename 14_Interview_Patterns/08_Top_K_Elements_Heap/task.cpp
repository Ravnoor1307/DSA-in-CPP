/*
REAL-WORLD SCENARIO:
Live leaderboard and nearest delivery rider shortlist maintain karna hai.

TASKS easy -> hard:
1. kth largest using min heap size k implement karo.
2. k closest points using max heap size k implement karo.
3. top k frequent words using hashmap + heap implement karo.
4. kth largest stream class design karo.
5. Comparator tie-break comments me explain karo.

HINTS:
- heap size > k -> pop worst survivor.
- distance square enough hai.
- stream class stores heap as member.

STARTER CODE:
priority_queue<int, vector<int>, greater<int>> minHeap;

SOLUTIONS below.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int kthLargest(vector<int> nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : nums) {
        pq.push(x);
        if ((int)pq.size() > k) pq.pop();
    }
    return pq.top();
}

int main() {
    cout << kthLargest({3,2,1,5,6,4}, 2) << "\n";
    return 0;
}

/*
OUTPUT:
5
*/
