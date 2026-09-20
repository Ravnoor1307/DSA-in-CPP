/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_kth_largest_approach2_minheap.cpp
│
│ REAL-WORLD SCENARIO:
│ Topper list me sirf top k students survive karne chahiye. Min heap of size k top-k survivors rakhta hai; heap ka smallest survivor kth largest hota hai.
│
│ VISUAL / DRY RUN:
│ TRICK: kth largest ke liye MIN heap? Yes!
│
│ Input [3,2,1,5,6,4], k=2
│ Maintain min heap size 2:
│ 3 -> [3]
│ 2 -> [2,3]
│ 1 -> push [1,2,3], size>2 pop 1 -> [2,3]
│ 5 -> push [2,3,5], pop 2 -> [3,5]
│ 6 -> push [3,5,6], pop 3 -> [5,6]
│ 4 -> push [4,5,6], pop 4 -> [5,6]
│
│ Survivors are top 2 largest: 5 and 6
│ min among survivors = 5 = 2nd largest

│
│ COMPLEXITY CALCULATION:
│ For each of n elements:
│ push costs O(log k) because heap size at most k+1.
│ possible pop costs O(log k).
│ Total <= n * 2logk operations -> O(n log k).
│
│ Space: heap stores at most k elements -> O(k).

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
int kthLargestMinHeap(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int x : a) {
        minHeap.push(x);
        cout << "push " << x << " -> "; printHeapCopy(minHeap, "heap");
        if ((int)minHeap.size() > k) {
            cout << "size > k, pop smallest survivor " << minHeap.top() << "\n";
            minHeap.pop();
        }
        printHeapCopy(minHeap, "top-k survivors");
    }
    return minHeap.top();
}

int main() {
    vector<int> a = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int ans = kthLargestMinHeap(a, k);
    cout << k << "th largest = " << ans << "\n";
    return 0;
}

/*
OUTPUT:
push 3 -> heap: [3]
top-k survivors: [3]
push 2 -> heap: [2, 3]
top-k survivors: [2, 3]
push 1 -> heap: [1, 2, 3]
size > k, pop smallest survivor 1
top-k survivors: [2, 3]
push 5 -> heap: [2, 3, 5]
size > k, pop smallest survivor 2
top-k survivors: [3, 5]
push 6 -> heap: [3, 5, 6]
size > k, pop smallest survivor 3
top-k survivors: [5, 6]
push 4 -> heap: [4, 5, 6]
size > k, pop smallest survivor 4
top-k survivors: [5, 6]
2th largest = 5
*/

