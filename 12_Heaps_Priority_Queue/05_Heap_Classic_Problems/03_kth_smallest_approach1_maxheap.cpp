/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_kth_smallest_approach1_maxheap.cpp
│
│ REAL-WORLD SCENARIO:
│ Lowest k electricity bills track karne hain. Max heap of size k rakho; agar new bill current largest survivor se chhota hai, replace karo.
│
│ VISUAL / DRY RUN:
│ kth smallest ke liye MAX heap size k:
│ Input [7,10,4,3,20,15], k=3
│
│ 7 -> [7]
│ 10 -> [10,7]
│ 4 -> [10,7,4]
│ 3 -> push, size>3, pop largest10 -> survivors [7,4,3]
│ 20 -> push, pop20 -> unchanged [7,4,3]
│ 15 -> push, pop15 -> unchanged [7,4,3]
│
│ Heap top is largest among smallest 3 = 7
│ answer = 3rd smallest = 7

│
│ COMPLEXITY CALCULATION:
│ n elements processed.
│ Heap size at most k+1.
│ Each push/pop O(log k).
│ Total = n * O(log k) -> O(n log k).
│ Space = O(k).

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
int kthSmallestMaxHeap(const vector<int>& a, int k) {
    priority_queue<int> maxHeap;
    for (int x : a) {
        maxHeap.push(x);
        if ((int)maxHeap.size() > k) maxHeap.pop(); // Largest survivor remove, smallest k bachte hain.
        printHeapCopy(maxHeap, "smallest-k survivors maxHeap order");
    }
    return maxHeap.top();
}

int main() {
    vector<int> a = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << k << "rd smallest = " << kthSmallestMaxHeap(a, k) << "\n";
    return 0;
}

/*
OUTPUT:
smallest-k survivors maxHeap order: [7]
smallest-k survivors maxHeap order: [10, 7]
smallest-k survivors maxHeap order: [10, 7, 4]
smallest-k survivors maxHeap order: [7, 4, 3]
smallest-k survivors maxHeap order: [7, 4, 3]
smallest-k survivors maxHeap order: [7, 4, 3]
3rd smallest = 7
*/

