/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_heap_sort_concept_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Class me tallest students ko height order me line lagani hai. Max heap banake tallest ko root pe lao, usko last position pe fix karo, remaining students par repeat karo.
│
│ VISUAL / DRY RUN:
│ Heap sort concept:
│ 1. Build max heap.
│ 2. Root is maximum.
│ 3. Swap root with last active element.
│ 4. Reduce heap size by 1: last position sorted zone ban gayi.
│ 5. Heapify root again.
│ 6. Repeat until heap size 1.
│
│ Visual:
│ Unsorted array: [4,10,3,5,1]
│ Build heap:     [10,5,3,4,1]
│
│ Active heap | Sorted zone
│ [10,5,3,4,1] | []
│ [5,4,3,1]    | [10]
│ [4,1,3]      | [5,10]
│ [3,1]        | [4,5,10]
│ [1]          | [3,4,5,10]

│
│ COMPLEXITY CALCULATION:
│ Build max heap bottom-up = O(n).
│ Then n-1 extractions.
│ Each extraction heapify-down height log n.
│ Total extraction work = (n-1) log n.
│ Time = O(n + n log n) = O(n log n).
│
│ In-place sorting uses array itself.
│ Extra variables few -> O(1) extra space.

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
int main() {
    vector<int> a = {4, 10, 3, 5, 1};
    cout << "Input: "; printArray(a); cout << "\n";
    buildMaxHeap(a);
    cout << "After build max heap: "; printArray(a); cout << "\n";
    cout << "Concept: repeatedly move root max to last active index.\n";
    return 0;
}

/*
OUTPUT:
Input: [4, 10, 3, 5, 1]
After build max heap: [10, 5, 3, 4, 1]
Concept: repeatedly move root max to last active index.
*/

