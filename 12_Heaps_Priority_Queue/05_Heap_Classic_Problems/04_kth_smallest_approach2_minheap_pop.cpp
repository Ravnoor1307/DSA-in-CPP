/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_kth_smallest_approach2_minheap_pop.cpp
│
│ REAL-WORLD SCENARIO:
│ Warehouse me sabse light boxes ascending order me nikalne hain. Saare boxes min heap me daalo; k-1 boxes pop karo, next top kth smallest hai.
│
│ VISUAL / DRY RUN:
│ Input [7,10,4,3,20,15], k=3
│
│ Build min heap of all elements:
│ top order would be: 3,4,7,10,15,20
│
│ Pop k-1 = 2 items:
│ pop1 -> 3 removed
│ pop2 -> 4 removed
│ top -> 7
│
│ answer = 7
│
│ Comparison with max heap of size k:
│ max heap size k uses O(k) memory.
│ min heap all uses O(n) memory but easy if many sorted pops needed.

│
│ COMPLEXITY CALCULATION:
│ Build min heap from range uses make_heap internally -> O(n).
│ Pop happens k-1 times.
│ Each pop costs O(log n) because heap size up to n.
│ Total time = O(n + k log n).
│ Space = O(n) for heap storing all elements.

│ APPROACH COMPARISON TABLE:
│ | kth smallest method | Real-world analogy | Work | Time | Space |
│ | Max heap size k | keep lowest k bills only | n * log k | O(n log k) | O(k) |
│ | Min heap all + pop | put all boxes, remove k-1 lightest | n + k log n | O(n + k log n) | O(n) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
using namespace std;

void printVector(const vector<int>& a) {
    cout << "[";
    for (int i = 0; i < (int)a.size(); i++) cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    cout << "]";
}

template <typename PQ>
void printHeapCopy(PQ pq, const string& label) {
    cout << label << ": [";
    bool first = true;
    while (!pq.empty()) {
        if (!first) cout << ", ";
        cout << pq.top();
        pq.pop();
        first = false;
    }
    cout << "]\n";
}
int kthSmallestMinHeapPop(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(a.begin(), a.end());
    for (int count = 1; count < k; count++) {
        cout << "pop " << minHeap.top() << "\n";
        minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> a = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int ans = kthSmallestMinHeapPop(a, k);
    cout << k << "rd smallest = " << ans << "\n";
    return 0;
}

/*
OUTPUT:
pop 3
pop 4
3rd smallest = 7
*/

