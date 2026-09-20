/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_heap_sort_implementation.cpp
│
│ REAL-WORLD SCENARIO:
│ Prize distribution me highest scorer ko last sorted certificate slot me place karte jao. Heap remaining unsorted students ka max fast deta rahega.
│
│ VISUAL / DRY RUN:
│ Dry run [4,10,3,5,1]:
│
│ Build max heap:
│        10
│       /  \
│      5    3
│     / \
│    4   1
│ Array: [10,5,3,4,1]
│
│ Pass 1: swap root 10 with index4
│ before heapify active [1,5,3,4] | sorted [10]
│ after heapify  active [5,4,3,1] | sorted [10]
│
│ Pass 2: swap root 5 with index3
│ before heapify active [1,4,3] | sorted [5,10]
│ after heapify  active [4,1,3] | sorted [5,10]
│
│ Pass 3: swap root 4 with index2
│ active [3,1] | sorted [4,5,10]
│
│ Pass 4: swap root 3 with index1
│ final [1,3,4,5,10]

│
│ COMPLEXITY CALCULATION:
│ Build heap = O(n).
│ Loop runs n-1 passes.
│ Each pass heapifyDown cost <= log n comparisons/swaps.
│ Total = O(n) + (n-1)*O(log n)
│ = O(n log n).
│
│ Extra space: in-place array + constant variables.
│ Space = O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void printArray(const vector<int>& a) {
    cout << "[";
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    }
    cout << "]";
}

void heapifyDown(vector<int>& a, int n, int i) {
    while (true) {
        int left = 2*i + 1, right = 2*i + 2;
        int largest = i;
        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;
        if (largest == i) break;
        swap(a[i], a[largest]); // Max heap property repair.
        i = largest;
    }
}

void buildMaxHeap(vector<int>& a) {
    for (int i = (int)a.size()/2 - 1; i >= 0; i--) heapifyDown(a, a.size(), i);
}
void printWithZones(const vector<int>& a, int heapSize) {
    cout << "active heap: [";
    for (int i = 0; i < heapSize; i++) cout << a[i] << (i + 1 == heapSize ? "" : ", ");
    cout << "] sorted zone: [";
    for (int i = heapSize; i < (int)a.size(); i++) cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    cout << "]\n";
}

void heapSort(vector<int>& a) {
    int n = a.size();
    buildMaxHeap(a);
    cout << "After buildMaxHeap: "; printArray(a); cout << "\n";
    for (int end = n - 1; end > 0; end--) {
        cout << "Pass: move max " << a[0] << " to index " << end << "\n";
        swap(a[0], a[end]); // Max sorted zone ke front me fix hota hai from right side.
        printWithZones(a, end);
        heapifyDown(a, end, 0);
        printWithZones(a, end);
    }
}

int main() {
    vector<int> a = {4, 10, 3, 5, 1};
    cout << "Input: "; printArray(a); cout << "\n";
    heapSort(a);
    cout << "Sorted: "; printArray(a); cout << "\n";
    return 0;
}

/*
OUTPUT:
Input: [4, 10, 3, 5, 1]
After buildMaxHeap: [10, 5, 3, 4, 1]
Pass: move max 10 to index 4
active heap: [1, 5, 3, 4] sorted zone: [10]
active heap: [5, 4, 3, 1] sorted zone: [10]
Pass: move max 5 to index 3
active heap: [1, 4, 3] sorted zone: [5, 10]
active heap: [4, 1, 3] sorted zone: [5, 10]
Pass: move max 4 to index 2
active heap: [3, 1] sorted zone: [4, 5, 10]
active heap: [3, 1] sorted zone: [4, 5, 10]
Pass: move max 3 to index 1
active heap: [1] sorted zone: [3, 4, 5, 10]
active heap: [1] sorted zone: [3, 4, 5, 10]
Sorted: [1, 3, 4, 5, 10]
*/

