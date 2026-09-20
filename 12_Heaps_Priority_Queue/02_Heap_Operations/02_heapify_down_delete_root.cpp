/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_heapify_down_delete_root.cpp
│
│ REAL-WORLD SCENARIO:
│ Hospital me most critical patient treat hote hi queue se remove hota hai. Last patient ko temporarily front desk pe bitha dete hain, phir priority compare karke neeche sink-down karte hain.
│
│ VISUAL / DRY RUN:
│ Initial max heap:
│        70
│       /  \
│     50    60
│    /  \
│   20  30
│ Array: [70,50,60,20,30]
│
│ Extract root 70:
│ 1. Move last 30 to root, remove last slot
│        30
│       /  \
│     50    60
│    /
│   20
│ Array: [30,50,60,20]
│
│ 2. Compare children 50 and 60; largest child=60
│ 3. Swap 30 with 60
│        60
│       /  \
│     50    30
│    /
│   20
│ Array: [60,50,30,20]

│
│ COMPLEXITY CALCULATION:
│ Remove root uses last move = O(1).
│ Heapify-down swaps along one root-to-leaf path.
│ Complete tree height:
│ n / 2^k = 1 -> n = 2^k -> k = log₂n.
│ Time = O(log n).
│ Space = O(1) extra.

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
void heapifyDown(vector<int>& heap, int i) {
    int n = heap.size();
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;

        if (largest == i) break;
        cout << "Swap " << heap[i] << " with larger child " << heap[largest] << "\n";
        swap(heap[i], heap[largest]); // Root se chhota value neeche sink karta hai.
        i = largest;
        printHeap(heap);
    }
}

int extractMax(vector<int>& heap) {
    if (heap.empty()) throw runtime_error("heap empty");
    int ans = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    cout << "Root removed, last moved to root:\n";
    printHeap(heap);
    if (!heap.empty()) heapifyDown(heap, 0);
    return ans;
}

int main() {
    vector<int> heap = {70, 50, 60, 20, 30};
    cout << "Before extract:\n";
    printHeap(heap);
    int removed = extractMax(heap);
    cout << "Extracted max = " << removed << "\n";
    cout << "After extract:\n";
    printHeap(heap);
    return 0;
}

/*
OUTPUT:
Before extract:
Array: [70, 50, 60, 20, 30]
Root removed, last moved to root:
Array: [30, 50, 60, 20]
Swap 30 with larger child 60
Array: [60, 50, 30, 20]
Extracted max = 70
After extract:
Array: [60, 50, 30, 20]
*/

