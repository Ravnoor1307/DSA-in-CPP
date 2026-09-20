/*
REAL-WORLD SCENARIO:
Hospital emergency priority desk implement karna hai jahan highest criticality patient fastest access ho.

TASKS easy -> hard:
1. `peek()` implement karo.
2. `heapifyUp()` implement karo.
3. `insert(x)` implement karo.
4. `heapifyDown()` implement karo.
5. `extractMax()` implement karo.
6. `buildHeap()` bottom-up implement karo.
7. Print array state after every operation.

HINTS:
- insert -> push_back + heapifyUp(last index)
- extract -> save root, root=last, pop_back, heapifyDown(0)
- last non-leaf = n/2 - 1

STARTER CODE:
class MaxHeap { vector<int> heap; // fill methods here };

SOLUTIONS below.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

class MaxHeap {
    vector<int> heap;
    void heapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] >= heap[i]) break;
            swap(heap[p], heap[i]); // Bada element upar bubble-up.
            i = p;
        }
    }
    void heapifyDown(int i) {
        while (true) {
            int l = 2*i+1, r = 2*i+2, largest = i;
            if (l < (int)heap.size() && heap[l] > heap[largest]) largest = l;
            if (r < (int)heap.size() && heap[r] > heap[largest]) largest = r;
            if (largest == i) break;
            swap(heap[i], heap[largest]); // Chhota root neeche sink-down.
            i = largest;
        }
    }
public:
    void insert(int x) { heap.push_back(x); heapifyUp(heap.size()-1); }
    int peek() const { if (heap.empty()) throw runtime_error("empty"); return heap[0]; }
    int extractMax() {
        if (heap.empty()) throw runtime_error("empty");
        int ans = heap[0]; heap[0] = heap.back(); heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return ans;
    }
    void print() const {
        cout << "[";
        for (int i=0;i<(int)heap.size();i++) cout << heap[i] << (i+1==(int)heap.size()?"":", ");
        cout << "]\n";
    }
};

int main() {
    MaxHeap h;
    for (int x : {50, 30, 70, 80}) { h.insert(x); h.print(); }
    cout << "peek=" << h.peek() << "\n";
    cout << "extract=" << h.extractMax() << "\n";
    h.print();
    return 0;
}

/*
OUTPUT:
[50]
[50, 30]
[70, 30, 50]
[80, 70, 50, 30]
peek=80
extract=80
[70, 30, 50]
*/
