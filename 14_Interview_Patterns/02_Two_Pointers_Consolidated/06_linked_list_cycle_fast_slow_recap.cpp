/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_linked_list_cycle_fast_slow_recap.cpp
│
│ REAL-WORLD SCENARIO:
│ Race track circular ho to fast runner slow runner ko eventually pakad lega. Linked list cycle detection me fast pointer 2 steps and slow pointer 1 step chalta hai.
│
│ VISUAL / PATTERN STATE:
│ Linked list with cycle:
│ 1 -> 2 -> 3 -> 4 -> 5
│           ^         |
│           |_________|
│
│ slow moves 1, fast moves 2.
│ If no cycle, fast reaches NULL.
│ If cycle, fast catches slow.
│
│ Gap proof:
│ Inside cycle, fast gains 1 node per iteration on slow.
│ If cycle length C, gap reduces modulo C each step.
│ Max C steps me gap 0 -> pointers meet.

│
│ STEP-BY-STEP DRY RUN:
│ start slow=1, fast=1
│ step1 slow=2, fast=3
│ step2 slow=3, fast=5
│ step3 slow=4, fast=4 -> meet -> cycle.

│
│ COMPLEXITY CALCULATION:
│ In no cycle list, fast moves two steps and reaches null after about n/2 iterations.
│ In cycle, entry path <= n and meet within cycle length <= n.
│ Total iterations <= O(n).
│ Space = two pointers only -> O(1).

│ APPROACH COMPARISON TABLE:
│ | Two pointer variant | Analogy | Use | Time | Space |
│ | Opposite ends | two gates close in | sorted pair/container | O(n) | O(1) |
│ | Same direction | fast scans slow writes | remove/partition | O(n) | O(1) |
│ | Fast-slow | race track | cycle/middle | O(n) | O(1) |
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        cout << "slow=" << slow->data << " fast=" << fast->data << "\n";
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    a->next=b; b->next=c; c->next=d; d->next=e; e->next=c;
    cout << "Cycle? " << (hasCycle(a) ? "YES" : "NO") << "\n";
    e->next = nullptr;
    delete a; delete b; delete c; delete d; delete e;
    return 0;
}

/*
OUTPUT:
slow=2 fast=3
slow=3 fast=5
slow=4 fast=4
Cycle? YES
*/

