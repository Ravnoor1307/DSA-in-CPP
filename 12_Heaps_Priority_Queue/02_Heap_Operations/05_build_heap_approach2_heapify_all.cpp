/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_build_heap_approach2_heapify_all.cpp
│
│ REAL-WORLD SCENARIO:
│ Warehouse me boxes already shelves par pade hain. Har box ko naya insert karne ke bajay, bottom se managers ko fix karte jao; leaves already valid heaps hote hain.
│
│ VISUAL / DRY RUN:
│ Input array as complete tree:
│        4
│       / \
│     10   3
│    / \
│   5   1
│ Array: [4,10,3,5,1]
│
│ Start from last non-leaf = n/2 - 1 = 1
│ i=1: node10 children 5,1 -> already OK
│ i=0: node4 children 10,3 -> swap with10
│        10
│       /  \
│      4    3
│     / \
│    5   1
│ heapify index1: node4 child5 -> swap
│        10
│       /  \
│      5    3
│     / \
│    4   1
│ Final: [10,5,3,4,1]

│
│ COMPLEXITY CALCULATION:
│ Why O(n), not O(n log n)?
│ Leaves count about n/2, work 0.
│ Height1 nodes about n/4, work 1.
│ Height2 nodes about n/8, work 2.
│ Total work = n/4*1 + n/8*2 + n/16*3 + ...
│ = n * (1/4 + 2/8 + 3/16 + ...)
│ This infinite series is less than 1.
│ Total <= n constant factor -> O(n).
│
│ Space = O(1) extra for in-place heapify.

│ APPROACH COMPARISON TABLE:
│ | Build method | Real-world analogy | Work calculation | Time | Space |
│ | n inserts | one-by-one registration | n * log n | O(n log n) | O(n) |
│ | bottom-up heapify | repair managers from bottom | n/4*1+n/8*2+... | O(n) | O(1) extra |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

void printHeap(const vector<int>& heap) {
    cout << "Array: [";
    for (int i = 0; i < (int)heap.size(); i++) {
        cout << heap[i] << (i + 1 == (int)heap.size() ? "" : ", ");
    }
    cout << "]\n";
}

void printTreeShape4(const vector<int>& h) {
    cout << "Tree view (first levels):\n";
    if (h.size() > 0) cout << "        " << h[0] << "\n";
    if (h.size() > 1) cout << "      /    \\\n";
    if (h.size() > 2) cout << "    " << h[1] << "      " << h[2] << "\n";
    else if (h.size() > 1) cout << "    " << h[1] << "\n";
    if (h.size() > 3) cout << "   /\n  " << h[3] << "\n";
}
void heapifyDown(vector<int>& a, int n, int i) {
    while (true) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int largest = i;
        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;
        if (largest == i) break;
        swap(a[i], a[largest]); // Bottom-up repair: bada child parent banega.
        i = largest;
    }
}

void buildHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << "Heapify index " << i << "\n";
        heapifyDown(a, n, i);
        printHeap(a);
    }
}

int main() {
    vector<int> a = {4, 10, 3, 5, 1};
    cout << "Before buildHeap: "; printHeap(a);
    buildHeap(a);
    cout << "After buildHeap: "; printHeap(a);
    return 0;
}

/*
OUTPUT:
Before buildHeap: Array: [4, 10, 3, 5, 1]
Heapify index 1
Array: [4, 10, 3, 5, 1]
Heapify index 0
Array: [10, 5, 3, 4, 1]
After buildHeap: Array: [10, 5, 3, 4, 1]
*/

