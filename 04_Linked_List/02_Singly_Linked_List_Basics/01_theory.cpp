/*
═══════════════════════════════════════════════
 SINGLY LINKED LIST BASICS — traverse, insert, delete, search
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A warehouse stores parcels as a chain of address tags. You only know where
 the FIRST parcel is (head). To read any parcel you must follow the tags one
 by one — you cannot jump straight to the 5th parcel. When a new parcel
 arrives at the front, you just rewrite 2 tags (O(1)); but when one arrives
 at the very END, you must walk the whole chain to find the last tag (O(n)).
 If a parcel is damaged, you redirect the previous tag to skip over it and
 throw the damaged one away. Every operation in this topic is exactly one of
 those tag edits: TRAVERSE, INSERT (head/tail/position), DELETE
 (head/tail/position), and SEARCH.

 📖 THEORY: (pure English, beginner-level)
 - TRAVERSE: walk from head, one node at a time, stop at nullptr.
     O(n): we touch n nodes for a list of length n.
 - INSERT AT HEAD: 2 pointer operations.
     newNode->next = head;  head = newNode;      → O(1)
 - INSERT AT TAIL (no tail pointer): walk to last node, attach.
     ... walk n-1 links, then last->next = newNode → O(n)
 - INSERT AT POSITION p: walk to (p-1)th node `prev`, then splice.
     newNode->next = prev->next;  prev->next = newNode;
     ORDER MATTERS: set newNode->next BEFORE you overwrite prev->next,
     otherwise you drop the rest of the chain.        → O(n) worst (walk)
 - DELETE AT HEAD: head = head->next; delete the old head. → O(1)
 - DELETE AT TAIL: walk to second-last, free last.    → O(n)
 - DELETE AT POSITION p: walk to prev (p-1), bypass the target:
     Node* target = prev->next;  prev->next = target->next;  delete target;
     MUST save target first — after bypass you lose the address. → O(n) walk
 - SEARCH for value v: compare each node from head.    → O(n) worst

  ASCII — insert at head:
   before:   head → [5|→] → [7|→] → [9|→null]
   after :   head → [1|→] → [5|→] → [7|→] → [9|→null]
              (newNode=1, sets its next=head, head=1)

  ASCII — insert after prev (position 2 with 0-based)
   ... [5|→] → [7|→] → [9|→null]          (prev = node 7)
   step1  newNode(6)->next = prev->next    → 6 points to 9
   step2  prev->next = newNode             → 7 points to 6
   result: ... [5|→] → [7|→] → [6|→] → [9|→null]

  ASCII — delete at position (delete node after prev)
   ... [5|→] → [7|→] → [6|→] → [9|→null]
   target = prev->next            (6)
   prev->next = target->next      (7 skips to 9)
   delete target
   result: ... [5|→] → [7|→] → [9|→null]

  WHEN TO USE / MISTAKES:
  - Front heavy workload → SLL shines (insert/delete head O(1)).
  - Random access + back traversal needed → array / DLL instead.
  - Top mistakes: 1) forget `temp = temp->next` → infinite loop.
                  2) wrong insert order at position → chain loss.
                  3) delete without saving next → dangling / double free.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Insert at head: new node's next MUST be set to the current head
        BEFORE head is updated.
        WHY: order keeps the original chain reachable during the swap.
 Step 2: Insert at tail: walk until a node whose next == nullptr, then attach.
        WHY: nullptr marks the end; attaching there preserves a single chain.
 Step 3: Insert at position: walk to prev = node before the insertion spot.
        WHY: splicing needs BOTH the node before (prev) and the node after.
 Step 4: Delete at position: walk to prev, save target, then bypass.
        WHY: you must keep target's address to free it; bypass re-links prev
        straight to target's next.
 Step 5: Search: compare while walking; stop early on first match.
        WHY: worst case = key absent (all n nodes); best = key at head (1).
 Step 6: Always check head == nullptr in delete-at-head and empty traversals.
        WHY: dereferencing nullptr crashes; empty list is a valid state.

 VISUAL WALKTHROUGH: building 3 -> 7 -> 8 by insertHead then tail/appends
   insertHead(8): head → [8|→null]
   insertHead(7): head → [7|→] → [8|→null]
   insertHead(3): head → [3|→] → [7|→] → [8|→null]
   insertTail(9): head → [3|→] → [7|→] → [8|→] → [9|→null]
   insertPos(6, 2):  head → [3|→] → [7|→] → [6|→] → [8|→] → [9|→null]
   deletePos(2):     head → [3|→] → [7|→] → [8|→] → [9|→null]
   deleteHead():     head → [7|→] → [8|→] → [9|→null]

 DRY RUN: (demo below, exact prints)
   build(insertHead 5,4,3):  head → [3|→] [4|→] [5|→null]  prints 3 4 5
   insertTail(6):  head → 3 → 4 → 5 → 6   prints 3 4 5 6
   insertAt(9, 2): head → 3 → 4 → 9 → 5 → 6   (9 lands at index 2)
   deleteHead():   head → 4 → 9 → 5 → 6
   deleteAt(1):    head → 4 → 5 → 6          (node 9 removed)
   deleteTail():   head → 4 → 5
   search(5): found at index 1. search(100): -1 (not found).

 TIME COMPLEXITY CALCULATION:
 - traverse: visits each of n nodes exactly once → n steps → O(n).
 - insertHead: 2 pointer writes, independent of n → constant → O(1).
 - insertTail (no tail ptr): walks n-1 links → n steps → O(n).
 - insertAt(p): walks up to p nodes, p ≤ n → at most n → O(n).
 - deleteHead: 2 pointer writes → O(1).
 - deleteAt(p): walks to p, bypass + delete constant → O(n) worst.
 - deleteTail: walks n-1 → O(n).
 - search: best 1, worst n comparisons → O(n).
 → Summary: Front ops O(1), everything requiring a walk is O(n).

 SPACE COMPLEXITY CALCULATION:
 - Each operation mutates existing nodes or adds ONE new node.
 - traverse/search/delete: no helper storage → auxiliary O(1).
 - A list of n nodes itself holds n nodes → O(n) for the data.
 → Space = O(1) auxiliary per op; O(n) total for n-node list.

 APPROACH COMPARISON (todo-style: op vs cost):
 ┌──────────────────┬────────────┬──────────────┬────────────────────────┐
 │ Operation        │ Time       │ Aux space    │ Key detail             │
 ├──────────────────┼────────────┼──────────────┼────────────────────────┤
 │ Traverse         │ O(n)       │ O(1)         │ walk till nullptr      │
 │ Insert head      │ O(1)       │ O(1)         │ 2 pointer writes       │
 │ Insert tail      │ O(n)       │ O(1)         │ walk + attach          │
 │ Insert position  │ O(n)       │ O(1)         │ splice, order matters  │
 │ Delete head      │ O(1)       │ O(1)         │ move head + free       │
 │ Delete position  │ O(n)       │ O(1)         │ bypass + free          │
 │ Delete tail      │ O(n)       │ O(1)         │ second-last walk       │
 │ Search           │ O(n)       │ O(1)         │ early exit on match    │
 └──────────────────┴────────────┴──────────────┴────────────────────────┘
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

void print(Node* head) {
    while (head) { cout << head->data; if (head->next) cout << " -> "; head = head->next; }
    cout << endl;
}

// insert at front (O(1))
void insertHead(Node*& head, int v) {
    Node* n = new Node(v);
    n->next = head;      // naya node purane head ko point kare
    head = n;            // aur head ab naya node ban gaya
}

// insert at back (O(n), no tail pointer)
void insertTail(Node*& head, int v) {
    Node* n = new Node(v);
    if (!head) { head = n; return; }   // empty list ka special case
    Node* t = head;
    while (t->next) t = t->next;       // last node tak chalo
    t->next = n;                       // aur wahan attach kar do
}

// insert at 0-based position (walk to prev, splice — ORDER matters)
void insertAt(Node*& head, int v, int pos) {
    Node* n = new Node(v);
    if (pos <= 0 || !head) { n->next = head; head = n; return; }
    Node* prev = head;
    for (int i = 1; prev->next && i < pos; i++) prev = prev->next;
    n->next = prev->next;   // pehle naya node aage wala pakde
    prev->next = n;         // phir prev ko naya node do (order zaroori!)
}

// delete front (O(1))
void deleteHead(Node*& head) {
    if (!head) return;
    Node* old = head;
    head = head->next;
    delete old;            // purana head free kar diya
}

// delete at 0-based position (bypass + free)
void deleteAt(Node*& head, int pos) {
    if (!head) return;
    if (pos <= 0) { deleteHead(head); return; }
    Node* prev = head;
    for (int i = 1; prev->next && i < pos; i++) prev = prev->next;
    if (!prev->next) return;             // position out of range
    Node* target = prev->next;
    prev->next = target->next;           // prev target ko skip kare
    delete target;                       // aur target free karo
}

// delete back (walk to second-last)
void deleteTail(Node*& head) {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Node* t = head;
    while (t->next->next) t = t->next;   // second-last par ruko
    delete t->next;
    t->next = nullptr;                   // ab last node yehi hai
}

// search value, return 0-based index or -1
int search(Node* head, int v) {
    int idx = 0;
    while (head) {
        if (head->data == v) return idx; // milte hi return
        head = head->next;
        idx++;
    }
    return -1;                           // nahi mila
}

int main() {
    cout << "===== build: insertHead 5,4,3 =====" << endl;
    Node* head = nullptr;
    insertHead(head, 5);
    insertHead(head, 4);
    insertHead(head, 3);   // ab order: 3 4 5
    print(head);

    cout << "===== insertTail(6) =====" << endl;
    insertTail(head, 6);
    print(head);

    cout << "===== insertAt(9, 2) =====" << endl;
    insertAt(head, 9, 2);
    print(head);

    cout << "===== deleteHead() =====" << endl;
    deleteHead(head);
    print(head);

    cout << "===== deleteAt(1) =====" << endl;
    deleteAt(head, 1);
    print(head);

    cout << "===== deleteTail() =====" << endl;
    deleteTail(head);
    print(head);

    cout << "===== search =====" << endl;
    cout << "index of 5 = " << search(head, 5) << endl;
    cout << "index of 100 = " << search(head, 100) << endl;

    // cleanup: poori chain free karo
    while (head) deleteHead(head);
    return 0;
}
