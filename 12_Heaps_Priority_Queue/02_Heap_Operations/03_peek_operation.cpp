/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_peek_operation.cpp
│
│ REAL-WORLD SCENARIO:
│ Triage board pe sabse critical patient front display par fixed slot me hota hai. Sirf dekhna ho, remove nahi karna, to root/arr[0] read karo.
│
│ VISUAL / DRY RUN:
│ Max heap:
│        90
│       /  \
│     70    80
│ Array: [90,70,80]
│
│ peek() -> arr[0] -> 90
│
│ Before -> [90,70,80]
│ After  -> [90,70,80]
│ No structure change.

│
│ COMPLEXITY CALCULATION:
│ Direct array access arr[0].
│ Operations: index calculation 0 + memory read = constant.
│ Time = O(1).
│ Space = O(1).

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
int peekMax(const vector<int>& heap) {
    if (heap.empty()) throw runtime_error("heap empty");
    return heap[0]; // Root always highest priority in max heap.
}

int main() {
    vector<int> heap = {90, 70, 80, 20, 30};
    cout << "Before peek: "; printHeap(heap);
    cout << "peekMax = " << peekMax(heap) << "\n";
    cout << "After peek: "; printHeap(heap);
    return 0;
}

/*
OUTPUT:
Before peek: Array: [90, 70, 80, 20, 30]
peekMax = 90
After peek: Array: [90, 70, 80, 20, 30]
*/

