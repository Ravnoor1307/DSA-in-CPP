/*
═══════════════════════════════════════════════
 DOUBLY LINKED LIST — prev pointer, insert/delete, traverse both ways
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A two-way road. Every intersection sign (node) not only tells you the NEXT
 sign ahead, but also points BACK to the previous one. If you overshoot your
 exit or double back for a missed shop, you can reverse direction instantly —
 no need to drive all the way around town. A music player's forward/back
 arrows and browser history (Back/Forward buttons) work this way: each entry
 knows both its next and its previous entry. That is the doubly linked list:
 every node carries `prev` and `next`, giving O(1) backward movement that a
 singly linked list simply cannot offer.

 📖 THEORY: (pure English, beginner-level)
 - NODE: struct DLLNode { int data; DLLNode* prev; DLLNode* next; };
   Each node holds a BACK pointer (prev) in addition to next.
 - INSERT AT HEAD: 2-4 pointer updates, all constant → O(1).
 - INSERT AT TAIL (with tail pointer): constant → O(1); without tail, walk.
 - INSERT AFTER node p: 4 pointer updates, all constant (find p = O(n)).
     newNode->prev = p; newNode->next = p->next;
     if (p->next) p->next->prev = newNode;   // guard: p may be the tail
     p->next = newNode;
 - DELETE node p: 3-4 pointer updates + free, constant once p is known.
     if (p->prev) p->prev->next = p->next;
     if (p->next) p->next->prev = p->prev;
     delete p;                              // guard both ends
 - DELETE LAST / FIRST are special cases of the guards above → O(1).
 - TRAVERSE with tail pointer lets you go BOTH directions in O(n) each.
 - vs SLL: +1 pointer (~8 bytes) per node, but O(1) tail deletion without
   walking, and easy reverse iteration. Extra memory and complexity.

  ASCII — a doubly linked list (head & tail pointers shown)
   head                   tail
    │                      │
    ▼                      ▼
   null ◀─[10]⇄[20]⇄[30]─▶ null
           ▲   ▲   ▲
          prev next pair per node

  ASCII — insert newNode=25 after node 20:
   before: [10]⇄[20]⇄[30]
   step1:  25->prev=20 ; 25->next=30
   step2:  30->prev=25 ; 20->next=25
   after : [10]⇄[20]⇄[25]⇄[30]

  ASCII — delete node 25:
   step1:  20->next = 25->next (=30)
   step2:  30->prev = 25->prev (=20)
   step3:  delete 25
   after : [10]⇄[20]⇄[30]

  WHEN TO USE DLL:
  - Need O(1) delete of a KNOWN node (LRU cache eviction).
  - Frequent backward traversal (undo/redo, browser history, music playlist).
  - Need O(1) insert both at head AND tail (deque).
  - Avoid when memory is tight or singly-linked suffices — the prev pointer
    is pure overhead if you never walk backward.

 🧠 LOGIC — STEP BY STEP:
 Step 1: When linking newNode between p and p->next, set the NEW node's
        pointers FIRST, then fix the neighbors.
        WHY: the new node's neighbors are still reachable via p and p->next;
        overwriting them early would lose the chain.
 Step 2: Guard every neighbor update with a null check.
        WHY: p->prev may be nullptr for the head and p->next nullptr for the
        tail; dereferencing either crashes.
 Step 3: Deleting keeps the SAME guard idea: update prev's next and next's
        prev independently, then free the node.
        WHY: symmetric to insertion — skip over p from both sides at once.
 Step 4: Use a tail pointer if you need O(1) append and O(1) reverse walk.
        WHY: the last node is otherwise reachable only by a full O(n) walk.
 Step 5: When traversing BACKWARD start from tail and follow prev.
        WHY: prev is the mirror of next; backward walk is the same loop with
        prev and tail in place of next and head.

 VISUAL WALKTHROUGH: build 5,10,15 via pushBack (appends), then insertAfter
   pushBack(5):  head→[5]⇄null (tail=5)
   pushBack(10): head→[5]⇄[10]⇄null
   pushBack(15): head→[5]⇄[10]⇄[15]⇄null
   insertAfter(10,12): → [5]⇄[10]⇄[12]⇄[15]⇄null
   deleteNode(10):     → [5]⇄[12]⇄[15]⇄null
   forward:  5 12 15 ; backward: 15 12 5

 DRY RUN: (demo prints)
   pushBack 5 10 15 → forward: 5 -> 10 -> 15
   insertAfter(10,12) → forward: 5 -> 10 -> 12 -> 15
   deleteNode(10)     → forward: 5 -> 12 -> 15
   backward walk      → 15 -> 12 -> 5
   (head/tail pointers keep insert-back & delete-front O(1)-ish)

 TIME COMPLEXITY CALCULATION:
 - pushBack with tail: 2 pointer writes, tail update → O(1).
 - insertAfter(p,v): p is handed to us; 4 writes + guard checks → O(1).
 - deleteNode(p): p is handed to us; up to 4 writes + free → O(1).
 - deleteNth/value (must FIND p first): walk O(n) then O(1) → O(n).
 - forward/backward traversal: visits n nodes once → O(n) each.
 - search: worst n comparisons → O(n).
 → Core ops on a KNOWN node are O(1); find-first operations are O(n).

 SPACE COMPLEXITY CALCULATION:
 - Every node stores 1 extra pointer (prev) vs SLL → +8 bytes per node.
 - n nodes total → O(n) for the list.
 - All core ops use only local pointers → auxiliary O(1).
 → Space = O(n) total, O(1) auxiliary per op (but ~8 bytes/node more than SLL).

 APPROACH COMPARISON (DLL vs SLL):
 ┌──────────────────────┬───────────────────────────┬───────────────────────────┐
 │ Capability           │ Singly linked list        │ Doubly linked list        │
 ├──────────────────────┼───────────────────────────┼───────────────────────────┤
 │ Backward traversal   │ O(n) (reverse-list trick) │ O(n) direct via prev      │
 │ Delete known node    │ needs prev search O(n)    │ O(1) (have prev pointer)  │
 │ Delete tail (w/ tail)│ O(n) (can't go back)      │ O(1) (tail->prev)         │
 │ Extra memory/node    │ 1 pointer                 │ 2 pointers (+8 bytes)     │
 │ Complexity           │ simpler                   │ slightly more bookkeeping │
 │ Best for             │ simple linear chains      │ LRU, history, deque       │
 └──────────────────────┴───────────────────────────┴───────────────────────────┘
 */
#include <iostream>
using namespace std;

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList with head AND tail pointers
class DLL {
public:
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;

    // append at back: O(1) with tail pointer
    void pushBack(int v) {
        DLLNode* n = new DLLNode(v);
        if (!head) { head = tail = n; return; }
        n->prev = tail;          // naya node tail ke aage
        tail->next = n;          // purane tail ka next naya node
        tail = n;                // tail update
    }

    // insert v after the FIRST node whose data == k; no-op if k missing
    void insertAfter(int k, int v) {
        for (DLLNode* p = head; p; p = p->next) {
            if (p->data == k) {
                DLLNode* n = new DLLNode(v);
                n->prev = p;                       // n ke dono pointer pehle
                n->next = p->next;
                if (p->next) p->next->prev = n;    // next wala guard
                else tail = n;                     // tail par insert hua
                p->next = n;
                return;
            }
        }
    }

    // delete the FIRST node whose data == k; no-op if missing
    void deleteNode(int k) {
        for (DLLNode* p = head; p; p = p->next) {
            if (p->data == k) {
                if (p->prev) p->prev->next = p->next;   // aage ka link
                else head = p->next;                     // head delete hua
                if (p->next) p->next->prev = p->prev;   // piche ka link
                else tail = p->prev;                     // tail delete hua
                delete p;
                return;
            }
        }
    }

    void printForward() {
        for (DLLNode* p = head; p; p = p->next) {
            cout << p->data; if (p->next) cout << " -> ";
        }
        cout << endl;
    }

    void printBackward() {
        for (DLLNode* p = tail; p; p = p->prev) {
            cout << p->data; if (p->prev) cout << " -> ";
        }
        cout << endl;
    }

    ~DLL() {
        while (head) { DLLNode* nxt = head->next; delete head; head = nxt; }
    }
};

int main() {
    cout << "===== build: pushBack 5,10,15 =====" << endl;
    DLL d;
    d.pushBack(5);
    d.pushBack(10);
    d.pushBack(15);
    d.printForward();              // 5 -> 10 -> 15

    cout << "===== insertAfter(10,12) =====" << endl;
    d.insertAfter(10, 12);
    d.printForward();              // 5 -> 10 -> 12 -> 15

    cout << "===== deleteNode(10) =====" << endl;
    d.deleteNode(10);
    d.printForward();              // 5 -> 12 -> 15

    cout << "===== backward walk =====" << endl;
    d.printBackward();             // 15 -> 12 -> 5

    cout << "===== destructor frees all (auto) =====" << endl;
    return 0;
}
