/*
═══════════════════════════════════════════════
 LINKED LIST — INTRO
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
Picture a goods train: the engine is hooked to coach 1, coach 1 to coach 2,
and so on. Anyone can add a new coach at the back or in the middle by simply
changing a couple of couplers — nobody has to move from their seat. If you
stand on the engine (the HEAD), you can walk the whole train by stepping from
coach to coach, one at a time. Compare this with the fixed cinema row from the
previous topic: there, a middle insertion forced every person to the right to
shuffle one seat over — that shuffle was the array's O(n) flyback.

 📖 THEORY:
 - A linked list is a sequence of NODES where every node holds DATA and a NEXT
   pointer that stores the ADDRESS of the following node.
 - The FIRST node is special and is called the HEAD. It is the only node we
   remember directly; the rest are found by following next pointers.
 - The LAST node's next pointer stores NULL — the official "list ends here"
   marker. NULL is our left-stop sign.
 - The nodes live in SCATTERED heap memory, so no contiguous block is needed
   and the list can grow or shrink at runtime (DYNAMIC SIZE).
 - There is NO random access: to reach node k you must physically walk k hops.
 - There is NO wastage: we allocate exactly as many nodes as we store.

 ASCII — anatomy of one node:
 ┌───────────┬───────────┐
 │ data      │ next      │
 │ 10        │  (address)│────►  points to the next Node
 └───────────┴───────────┘

 ASCII — a 3-node list, head → node1 → node2 → node3 → NULL:
 head
  │
  ▼
 ┌─────────┬─────────┐    ┌─────────┬─────────┐    ┌─────────┬────────┐
 │ data=10 │ next────┼───►│ data=20 │ next────┼───►│ data=30 │  NULL  │
 └─────────┴─────────┘    └─────────┴─────────┘    └─────────┴────────┘
   node1                     node2                   node3 (tail)

 ✅ When to use a linked list:
 - The size is unknown at compile time and keeps changing.
 - Frequent insert/delete happens in the MIDDLE of the collection.
 - You can accept O(n) searching instead of O(1) random access.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Define the node type: struct Node { int data; Node* next; }.
         WHY: next must be a pointer to the SAME struct type so every node can
         point to the following node of the same kind (self-referential — the
         very next topic).
 Step 2: Allocate the first node with new and store its data.
         Set its next = NULL first. WHY: it is the tail for now, and an
         unset pointer holds garbage that we must never follow.
 Step 3: Set head = that node. WHY: head is our only handle on the whole list;
         if we lose it, the list is unreachable and its memory leaks forever.
 Step 4: Allocate the second node, then do head->next = second.
         WHY: this single assignment is the COUPLER — one arrow from node1 to
         node2, exactly like hooking the train coaches.
 Step 5: Repeat for node3 with second->next = third.
 Step 6: TRAVERSE with a helper pointer: while (temp != NULL) print
         temp->data, then temp = temp->next. WHY: each hop advances one node;
         when temp becomes NULL we have stepped past the tail and must stop.

 VISUAL WALKTHROUGH (building the demo list, state by state):
 Empty world : head = NULL
 After node1 : head = [10 | NULL]
 After node2 : head = [10 | ───► [20 | NULL]]
 After node3 : head = [10 | ───► [20 | ───► [30 | NULL]]

 Traversal, hop by hop:
     temp = head    → print 10 → temp = node2
     temp = node2   → print 20 → temp = node3
     temp = node3   → print 30 → temp = NULL
     temp == NULL   → loop stops, no crash ✅

 DRY RUN (exact trace of the demo code below):
   Node* head = NULL;
   head = new Node;  head->data = 10;  head->next = NULL;   → [10|NULL]
   Node* second = new Node;  second->data = 20;  second->next = NULL;
   head->next = second;      // node1's coupler now reaches node2
   Node* third = new Node;   third->data = 30;   third->next = NULL;
   second->next = third;     // node2's coupler now reaches node3
   // traversal
   Node* temp = head;
   iter 1 : temp != NULL → print 10 → temp = head->next = second
   iter 2 : temp != NULL → print 20 → temp = second->next = third
   iter 3 : temp != NULL → print 30 → temp = third->next = NULL
   iter 4 : temp == NULL → exit
   Output : 10 -> 20 -> 30 -> NULL ✅

 TIME COMPLEXITY CALCULATION:
 - Creating one node: new performs 1 allocation and a few assignments — a
   CONSTANT number of operations that never depends on list size, f(n) = c,
   so → O(1).
 - Linking two nodes: exactly 1 pointer assignment → O(1).
 - Traversing n nodes: the while body runs n times and each iteration does
   constant work, so f(n) = c×n, coefficient and constant dropped → O(n).
 - Reaching the k-th node: k pointer hops → O(k), worst case k = n → O(n).
   → Time Complexity = O(1) per node creation/link, O(n) for traversal/search
     and random access.

 SPACE COMPLEXITY CALCULATION:
 - n nodes, each occupying sizeof(data) + sizeof(pointer) = 4 + 8 = 12 bytes,
   padded to 16, so TOTAL = n × 16 bytes, linear in n → O(n).
 - Traversal uses exactly ONE extra pointer regardless of list length → O(1).
 - Unlike an array there is no capacity reservation, so auxiliary wait is nil.
   → Space Complexity = O(n) total, O(1) auxiliary.

 ═══════════ APPROACH COMPARISON ═══════════
 ┌────────────────────────┬─────────────────────────────┬──────────────────────────────┐
 │ Criterion              │ ARRAY                       │ SINGLY LINKED LIST           │
 ├────────────────────────┼─────────────────────────────┼──────────────────────────────┤
 │ random access arr[i]   │ O(1) direct ✅              │ O(n) must walk ❌            │
 │ insert at known spot   │ O(n) shifts ❌              │ O(1) pointer swap ✅         │
 │ delete at known spot   │ O(n) shifts ❌              │ O(1) pointer swap ✅         │
 │ size at runtime        │ fixed ❌                    │ grows freely ✅              │
 │ memory per element     │ n×4 bytes (int) ✅          │ n×16 bytes ❌ (75% overhead) │
 │ memory wastage         │ capacity − used ❌          │ none (grow as needed) ✅     │
 │ memory must be         │ one contiguous block ❌     │ scattered blocks fine ✅     │
 │ cache friendly         │ yes ✅                      │ no ❌                        │
 └────────────────────────┴─────────────────────────────┴──────────────────────────────┘
*/
#include <iostream>
using namespace std;

// Node = data + next pointer (self-referential struct)
struct Node {
    int data;
    Node* next;
};

int main() {
    // 3 nodes banao aur link karo — train ki tarah coach jodo
    Node* head = new Node;          // pehla coach
    head->data = 10;
    head->next = NULL;              // abhi aakhri hai

    Node* second = new Node;        // doosra coach
    second->data = 20;
    second->next = NULL;
    head->next = second;            // coupler: node1 ──► node2

    Node* third = new Node;         // teesra coach
    third->data = 30;
    third->next = NULL;
    second->next = third;           // coupler: node2 ──► node3

    // traversal — head se shuru, NULL tak
    cout << "List: ";
    Node* temp = head;
    while (temp != NULL) {          // jab tak node milta hai
        cout << temp->data << " -> ";
        temp = temp->next;          // agle node pe chalo
    }
    cout << "NULL" << endl;

    // edge case: khali list — head NULL, traversal safe
    Node* emptyList = NULL;
    if (emptyList == NULL)
        cout << "Empty list → kuch print nahi hoga, crash bhi nahi ✅" << endl;

    // heap cleanup — har new ka ek delete
    delete third;
    delete second;
    delete head;
    return 0;
}