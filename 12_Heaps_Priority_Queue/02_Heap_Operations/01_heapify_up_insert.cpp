/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_heapify_up_insert.cpp
│
│ REAL-WORLD SCENARIO:
│ Exam topper board me naya student marks ke saath last position pe add hota hai. Agar uske marks parent se zyada hain, wo upar bubble-up hota hai until correct rank.
│
│ VISUAL / DRY RUN:
│ Starting heap after inserting 50, 30, 70:
│        70
│       /  \
│     30    50
│ Array: [70, 30, 50]
│
│ Insert 80:
│ Step 1: append at last index 3
│        70
│       /  \
│     30    50
│    /
│   80
│ Array: [70,30,50,80]
│
│ Step 2: compare child index3=80 with parent index1=30 -> swap
│        70
│       /  \
│     80    50
│    /
│   30
│ Array: [70,80,50,30]
│
│ Step 3: compare child index1=80 with parent index0=70 -> swap
│        80
│       /  \
│     70    50
│    /
│   30
│ Array: [80,70,50,30]

│
│ COMPLEXITY CALCULATION:
│ Insert append = O(1).
│ Heapify-up moves one level each swap.
│ Complete tree height h:
│ n / 2^k = 1 -> n = 2^k -> k = log₂n.
│ Max swaps = h = log₂n.
│ Time = O(log n).
│ Space = O(1) extra, vector stores heap O(n).

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
    heap.push_back(value); // Naya element last open complete-tree slot me jata hai.
    int child = (int)heap.size() - 1;
    cout << "Append " << value << " at index " << child << "\n";
    printHeap(heap);

    while (child > 0) {
        int parent = (child - 1) / 2;
        cout << "Compare child " << heap[child] << " with parent " << heap[parent] << "\n";
        if (heap[parent] >= heap[child]) break;
        swap(heap[parent], heap[child]); // Bada priority element upar jaata hai.
        child = parent;
        printHeap(heap);
    }
}

int main() {
    vector<int> heap = {70, 30, 50};
    cout << "Before insert:\n";
    printHeap(heap);
    insertMaxHeap(heap, 80);
    cout << "After insert:\n";
    printHeap(heap);
    printTreeShape4(heap);
    return 0;
}

/*
OUTPUT:
Before insert:
Array: [70, 30, 50]
Append 80 at index 3
Array: [70, 30, 50, 80]
Compare child 80 with parent 30
Array: [70, 80, 50, 30]
Compare child 80 with parent 70
Array: [80, 70, 50, 30]
After insert:
Array: [80, 70, 50, 30]
Tree view (first levels):
        80
      /    \
    70      50
   /
  30
*/

