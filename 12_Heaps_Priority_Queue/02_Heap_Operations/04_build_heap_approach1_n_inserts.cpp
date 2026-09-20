/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_build_heap_approach1_n_inserts.cpp
│
│ REAL-WORLD SCENARIO:
│ Naye employees ek-ek karke priority desk pe register ho rahe hain. Har insert ke baad employee apni priority ke according upar bubble-up karta hai.
│
│ VISUAL / DRY RUN:
│ Input: [4,10,3,5,1]
│ Insert one by one:
│ insert4  -> [4]
│ insert10 -> [10,4]
│ insert3  -> [10,4,3]
│ insert5  -> [10,5,3,4]
│ insert1  -> [10,5,3,4,1]
│
│ Tree final:
│        10
│       /  \
│      5    3
│     / \
│    4   1

│
│ COMPLEXITY CALCULATION:
│ For each of n elements, insert may bubble-up height log n.
│ Total = n inserts * log n swaps/comparisons.
│ Time = O(n log n).
│
│ More exact: insert costs log1 + log2 + ... + logn <= n logn.
│ Space = O(n) for heap array, O(1) extra.

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
void insertMaxHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    int child = heap.size() - 1;
    while (child > 0) {
        int parent = (child - 1) / 2;
        if (heap[parent] >= heap[child]) break;
        swap(heap[parent], heap[child]);
        child = parent;
    }
}

vector<int> buildByInserts(const vector<int>& arr) {
    vector<int> heap;
    for (int x : arr) {
        insertMaxHeap(heap, x);
        cout << "After inserting " << x << " -> "; printHeap(heap);
    }
    return heap;
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    vector<int> heap = buildByInserts(arr);
    cout << "Final max heap: "; printHeap(heap);
    return 0;
}

/*
OUTPUT:
After inserting 4 -> Array: [4]
After inserting 10 -> Array: [10, 4]
After inserting 3 -> Array: [10, 4, 3]
After inserting 5 -> Array: [10, 5, 3, 4]
After inserting 1 -> Array: [10, 5, 3, 4, 1]
Final max heap: Array: [10, 5, 3, 4, 1]
*/

