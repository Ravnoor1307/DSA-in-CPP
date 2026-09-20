/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_heap_as_class_implementation.cpp
│
│ REAL-WORLD SCENARIO:
│ Priority helpdesk ko reusable class banana hai: new ticket insert, highest ticket peek, highest ticket extract, and current size. Internally vector complete tree maintain karega.
│
│ VISUAL / DRY RUN:
│ MaxHeap class state:
│ vector<int> heap;
│
│ Operations:
│ insert(x)     -> append + heapifyUp
│ extractMax()  -> root remove + last root + heapifyDown
│ peek()        -> heap[0]
│ size()        -> heap.size()
│
│ Example flow:
│ insert50 -> [50]
│ insert30 -> [50,30]
│ insert70 -> [70,30,50]
│ insert80 -> [80,70,50,30]
│ peek     -> 80
│ extract  -> 80 removed, heap [70,30,50]

│
│ COMPLEXITY CALCULATION:
│ insert: at most height swaps -> O(log n).
│ extractMax: at most height swaps -> O(log n).
│ peek: direct root read -> O(1).
│ size: vector size read -> O(1).
│
│ height proof:
│ n / 2^k = 1 -> n = 2^k -> k = log₂n.
│ Complete tree height O(log n).
│ Storage: vector with n elements -> O(n), operation extra space O(1).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int child) {
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (heap[parent] >= heap[child]) break;
            swap(heap[parent], heap[child]);
            child = parent;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1, right = 2 * i + 2;
            int largest = i;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);       // Complete tree ka next left-filled slot.
        heapifyUp(heap.size() - 1);  // Heap property repair upward.
    }

    int extractMax() {
        if (heap.empty()) throw runtime_error("heap empty");
        int ans = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return ans;
    }

    int peek() const {
        if (heap.empty()) throw runtime_error("heap empty");
        return heap[0];
    }

    int size() const { return heap.size(); }

    void print() const {
        cout << "Array: [";
        for (int i = 0; i < (int)heap.size(); i++) {
            cout << heap[i] << (i + 1 == (int)heap.size() ? "" : ", ");
        }
        cout << "]\n";
    }
};

int main() {
    MaxHeap pq;
    for (int x : {50, 30, 70, 80}) {
        pq.insert(x);
        cout << "After insert " << x << ": "; pq.print();
    }
    cout << "peek = " << pq.peek() << "\n";
    cout << "size = " << pq.size() << "\n";
    cout << "extractMax = " << pq.extractMax() << "\n";
    cout << "After extract: "; pq.print();
    return 0;
}

/*
OUTPUT:
After insert 50: Array: [50]
After insert 30: Array: [50, 30]
After insert 70: Array: [70, 30, 50]
After insert 80: Array: [80, 70, 50, 30]
peek = 80
size = 4
extractMax = 80
After extract: Array: [70, 30, 50]
*/

