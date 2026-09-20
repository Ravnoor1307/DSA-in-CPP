/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_pq_vs_queue_vs_stack.cpp
│
│ REAL-WORLD SCENARIO:
│ Cafe, browser back button, and hospital triage teen alag worlds hain. Queue FIFO, stack LIFO, priority queue priority-first follow karta hai.
│
│ VISUAL / DRY RUN:
│ Data pushed: 10, 20, 30
│
│ Stack (LIFO):
│ push10 push20 push30
│ top -> 30, then20, then10
│ Real-world: plates stack / browser back
│
│ Queue (FIFO):
│ push10 push20 push30
│ front -> 10, then20, then30
│ Real-world: ticket line
│
│ Priority Queue:
│ push10 push20 push30
│ top -> 30, then20, then10 for max priority
│ Real-world: hospital emergency / CPU scheduling

│
│ COMPLEXITY CALCULATION:
│ stack push/pop/top use one end -> O(1).
│ queue push/pop/front use ends -> O(1).
│ priority_queue push/pop maintain heap -> O(log n).
│ priority_queue top reads root -> O(1).
│
│ Space for all structures with n items -> O(n).

│ APPROACH COMPARISON TABLE:
│ | Structure | Real-world analogy | Removal rule | push | remove | peek |
│ | Stack | plates/browser back | LIFO | O(1) | O(1) | O(1) |
│ | Queue | ticket line | FIFO | O(1) | O(1) | O(1) |
│ | Priority Queue | hospital triage | priority first | O(log n) | O(log n) | O(1) |
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

int main() {
    stack<int> st;
    queue<int> qu;
    priority_queue<int> pq;

    for (int x : {10, 20, 30}) {
        st.push(x);
        qu.push(x);
        pq.push(x);
    }

    cout << "Stack LIFO order: ";
    while (!st.empty()) { cout << st.top() << ' '; st.pop(); }
    cout << "\n";

    cout << "Queue FIFO order: ";
    while (!qu.empty()) { cout << qu.front() << ' '; qu.pop(); }
    cout << "\n";

    cout << "Priority queue order: ";
    while (!pq.empty()) { cout << pq.top() << ' '; pq.pop(); }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Stack LIFO order: 30 20 10
Queue FIFO order: 10 20 30
Priority queue order: 30 20 10
*/

