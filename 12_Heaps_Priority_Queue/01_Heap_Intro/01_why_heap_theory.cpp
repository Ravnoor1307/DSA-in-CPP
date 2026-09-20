/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_why_heap_theory.cpp
│
│ REAL-WORLD SCENARIO:
│ Hospital emergency room me patients arrival order se nahi, criticality priority se treat hote hain. Agar baar-baar sabse critical patient chahiye, normal line slow ho sakti hai; Priority Queue / Heap fast answer deta hai.
│
│ VISUAL NOTES:
│ Problem: baar-baar max element chahiye.
│
│ Unsorted array:
│ [50, 30, 70, 20]
│ max find -> scan all 4
│ next max after insert/delete -> again scan/sort
│
│ Sort each time:
│ [20, 30, 50, 70]  max = 70
│ cost: O(n log n) every rebuild
│
│ Max Heap idea:
│        70
│       /  \
│     50    30
│    /
│   20
│ root arr[0] = biggest priority
│
│ Real-world examples:
│ - Hospital: most critical patient first
│ - Board exam topper list: highest marks first
│ - CPU scheduling: highest priority task first

│
│ DRY RUN / FLOW:
│ Real-world input -> identify priority -> maintain heap property -> answer fast.
│
│ COMPLEXITY CALCULATION:
│ Sort each query:
│ sorting n items -> approximately n log n comparisons.
│ q repeated max queries -> q * n log n.
│
│ Heap:
│ build once O(n), peek each time arr[0] -> 1 operation.
│ insert/extract changes one root-to-leaf path.
│ Balanced complete tree height:
│ n / 2^k = 1 -> n = 2^k -> k = log₂n.
│ insert/extract = O(log n), peek = O(1).
│
│ Space: heap stored in same array/vector of n elements -> O(n).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void printArray(const vector<int>& a) {
    cout << "[";
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    }
    cout << "]";
}

int main() {
    vector<int> priorities = {50, 30, 70, 20};
    vector<int> sorted = priorities;
    sort(sorted.begin(), sorted.end()); // Har baar sorting karna slow ho sakta hai.

    priority_queue<int> maxHeap;
    for (int x : priorities) maxHeap.push(x); // Heap priority maintain karta hai.

    cout << "Priorities: "; printArray(priorities); cout << "\n";
    cout << "After sort, biggest = " << sorted.back() << "\n";
    cout << "Heap top, biggest = " << maxHeap.top() << "\n";
    cout << "Hospital analogy: critical patient " << maxHeap.top() << " treated first.\n";
    return 0;
}

/*
OUTPUT:
Priorities: [50, 30, 70, 20]
After sort, biggest = 70
Heap top, biggest = 70
Hospital analogy: critical patient 70 treated first.
*/

