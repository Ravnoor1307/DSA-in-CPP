/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_stl_max_priority_queue.cpp
│
│ REAL-WORLD SCENARIO:
│ Board exam result portal par highest marks top pe chahiye. STL `priority_queue<int>` default max priority queue hota hai.
│
│ VISUAL / DRY RUN:
│ STL max priority_queue:
│ priority_queue<int> pq;
│
│ Push sequence: 50,30,70,20
│ Logical max heap:
│        70
│       /  \
│     30    50
│    /
│   20
│
│ top() -> 70
│ pop() removes 70
│ next top -> 50
│
│ Visual states by top:
│ push50 -> top50
│ push30 -> top50
│ push70 -> top70
│ push20 -> top70

│
│ COMPLEXITY CALCULATION:
│ push: heap insert = O(log n) because value may bubble-up height log n.
│ pop: root remove + heapify-down = O(log n).
│ top: root read = O(1).
│ empty/size: direct metadata = O(1).
│ Space: stores n elements = O(n).

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <iomanip>
using namespace std;

void printPQ(priority_queue<int> pq) {
    cout << "Priority order: ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << "\n";
}

int main() {
    priority_queue<int> pq; // Default max heap.
    for (int x : {50, 30, 70, 20}) {
        pq.push(x);
        cout << "push " << x << " -> top = " << pq.top() << "\n";
    }
    printPQ(pq);
    pq.pop(); // highest priority remove.
    cout << "After one pop, top = " << pq.top() << "\n";
    return 0;
}

/*
OUTPUT:
push 50 -> top = 50
push 30 -> top = 50
push 70 -> top = 70
push 20 -> top = 70
Priority order: 70 50 30 20
After one pop, top = 50
*/

