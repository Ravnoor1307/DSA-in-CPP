/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_running_median_concept.cpp
│
│ REAL-WORLD SCENARIO:
│ Live marks stream aa rahi hai aur har new mark ke baad median chahiye. Do heaps stream ko lower half and upper half me balance karte hain.
│
│ VISUAL / DRY RUN:
│ Two-heap trick:
│ lower half = max heap
│ upper half = min heap
│
│ Invariant:
│ max(lower) <= min(upper)
│ size difference <= 1
│
│ Stream: 5,15,1,3
│
│ add5:
│ lower [5], upper [] -> median 5
│
│ add15:
│ lower [5], upper [15] -> median (5+15)/2 = 10
│
│ add1:
│ lower [5,1], upper [15] -> median 5
│
│ add3:
│ lower [3,1], upper [5,15] -> median (3+5)/2 = 4

│
│ COMPLEXITY CALCULATION:
│ For each incoming value:
│ one push O(log n), possible rebalance pop+push O(log n).
│ Per element = O(log n).
│ For n stream elements total = O(n log n).
│ Median query reads heap tops -> O(1).
│ Space stores all stream values across two heaps -> O(n).

│ APPROACH COMPARISON TABLE:
│ | Problem pattern | Heap idea | Real-world analogy | Time | Space |
│ | kth largest | min heap size k | top-k survivor club | O(n log k) | O(k) |
│ | kth smallest | max heap size k | lowest-k bill club | O(n log k) | O(k) |
│ | top k frequent | hashmap + heap | trending topics | O(n + m log m) | O(m) |
│ | merge k sorted | min heap of heads | merge school lists | O(N log k) | O(k) |
│ | running median | max+min heap | balance two halves | O(log n)/add | O(n) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
using namespace std;

void printVector(const vector<int>& a) {
    cout << "[";
    for (int i = 0; i < (int)a.size(); i++) cout << a[i] << (i + 1 == (int)a.size() ? "" : ", ");
    cout << "]";
}

template <typename PQ>
void printHeapCopy(PQ pq, const string& label) {
    cout << label << ": [";
    bool first = true;
    while (!pq.empty()) {
        if (!first) cout << ", ";
        cout << pq.top();
        pq.pop();
        first = false;
    }
    cout << "]\n";
}
class RunningMedian {
    priority_queue<int> lower; // Max heap: lower half ka biggest top.
    priority_queue<int, vector<int>, greater<int>> upper; // Min heap: upper half ka smallest top.

public:
    void addNum(int x) {
        if (lower.empty() || x <= lower.top()) lower.push(x);
        else upper.push(x);

        // Balance sizes so difference at most 1.
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double median() const {
        if (lower.size() == upper.size()) return (lower.top() + upper.top()) / 2.0;
        return lower.top();
    }

    void printState() const {
        printHeapCopy(lower, "lower maxHeap order");
        printHeapCopy(upper, "upper minHeap order");
    }
};

int main() {
    RunningMedian rm;
    for (int x : {5, 15, 1, 3}) {
        cout << "add " << x << "\n";
        rm.addNum(x);
        rm.printState();
        cout << "median = " << rm.median() << "\n";
    }
    return 0;
}

/*
OUTPUT:
add 5
lower maxHeap order: [5]
upper minHeap order: []
median = 5
add 15
lower maxHeap order: [5]
upper minHeap order: [15]
median = 10
add 1
lower maxHeap order: [5, 1]
upper minHeap order: [15]
median = 5
add 3
lower maxHeap order: [3, 1]
upper minHeap order: [5, 15]
median = 4
*/

