/*
═══════════════════════════════════════════════
 CIRCULAR LINKED LIST — last node links back to head
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A music playlist on REPEAT: after the last song plays, the player loops
 back to the first — there is no "end" and no "start". Round-robin CPU
 scheduling does the same: processes sit in a ring and the scheduler always
 moves to the NEXT one, forever. A boardroom with one token passed left:
 everyone's turn comes again after the cycle completes. That's a circular
 linked list — the last node's `next` points back at `head` instead of
 nullptr, forming an endless ring.

 📖 THEORY: (pure English, beginner-level)
 - CIRCULAR SLL: struct Node { int data; Node* next; }; last->next == head.
 - ADVANTAGES:
     * No nullptr end — a traversal naturally wraps around.
     * O(1) reach to both ends from ANY node (keep walking).
     * Perfect model for loops: round-robin, playlist loop, Josephus.
 - TRAVERSAL: CANNOT use `while (t != nullptr)` — it runs forever.
   Use a DO-WHILE that stops when we return to START (the head).
     Node* t = head;
     do { use t; t = t->next; } while (t != head);
   Empty list (head == nullptr) must be checked separately to avoid the do
   while running on null.
 - INSERT AT HEAD in a circular list is trickier: the OLD tail's next must
   point to the NEW head. So either walk to find the tail (O(n)) or keep a
   tail pointer (O(1)). With tail pointer: newLast->next = tail->next; then
   UPDATE tail->next = newLast; head = tail->next.
 - INSERT AFTER / DELETE follow SLL rules but the wrap link persists.
 - DELETE: bypass like SLL; if deleting head, also fix the tail's link.
 - Representation keeps NO nullptr inside the ring (only possibly head==nullptr
   for an empty list).

  ASCII — a circular list of 3 nodes (10 → 20 → 30 → back to 10)
        ┌─────────────────────────────┐
        ▼                             │
    [10|●] ──▶ [20|●] ──▶ [30|●] ─────┘
     head                     (tail.next → head)

  ASCII — traversal with do-while stops when t returns to head
   start head=10 → 10 → 20 → 30 → (10 == head) STOP
   prints: 10, 20, 30 — exactly one full round, no infinite loop.

  WHEN TO USE:
  - Round-robin / fair scheduling among a fixed set.
  - Playlist loop, media rotating, carousel UI.
  - Any "keep cycling forever" simulation; Josephus-style counting game.
  - Order-statistics where wrap-around access is natural.
  - Avoid if you actually need "end of list" semantics — you'd fight the
    design. Much of the time a plain SLL/DLL is simpler.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Traverse with do-while, conditioning on `t != start`.
        WHY: `while (t) t = t->next` never terminates because next never
        becomes null; the way back to the start IS the stopping signal.
 Step 2: Guard empty list BEFORE the do-while in traversal/insert.
        WHY: do-while executes at least once — on a null head you'd
        dereference nullptr; check head == nullptr first.
 Step 3: Insert at head with a tail pointer = 2 pointer edits (new->next =
        tail->next; tail->next = new) + move head.
        WHY: tail keeps the wrap link; updating tail->next is what glues the
        ring, and head simply moves to the newest node.
 Step 4: Deleting head requires knowing the current tail to re-link it.
        WHY: the tail's next must be redirected to the new head, otherwise
        the ring breaks (tail would still point at the deleted node).
 Step 5: Search/delete operate as SLL but return-to-start is the exit.
        WHY: same node visiting logic; only the terminator changes.

 VISUAL WALKTHROUGH: build 5 → 10 → 15 circular, then insertHead(1), deleteNode(10)
   build:   5→10→15→(back to 5)
   insertHead(1): 1→5→10→15→(1)     (tail 15 now points to 1)
   deleteNode(10): 1→5→15→(1)
   full round traversal prints: 1 5 15

 DRY RUN: (demo prints)
   build 5 10 15 circular
   traverse full round: 5 -> 10 -> 15 (one lap)
   insertHead(1) → lap: 1 -> 5 -> 10 -> 15
   deleteNode(10) → lap: 1 -> 5 -> 15
   search(15) = found index 2 ; search(99) = -1 (not found)

 TIME COMPLEXITY CALCULATION:
 - build/append (with tail): link edits near-constant → O(1) per node,
   O(n) for n nodes total.
 - insertHead with tail pointer: 2-3 pointer edits → O(1).
 - insertHead WITHOUT tail (walk to find tail): O(n).
 - deleteNode/insertAt/search: may visit up to n nodes → O(n).
 - full traversal: exactly n nodes in one lap → O(n).
 → With a tail pointer, front ops are O(1); search/delete are O(n) worst.

 SPACE COMPLEXITY CALCULATION:
 - n nodes each holding data + next → O(n) total.
 - Traversal/search/insert use only local pointers → auxiliary O(1).
 - A circular list stores NO extra data vs an SLL (same 1 pointer).
 → Space = O(n) for the ring, O(1) auxiliary per operation.

 APPROACH COMPARISON:
 ┌──────────────────────┬─────────────────────────┬──────────────────────────────┐
 │ Aspect               │ Singly linked list      │ Circular linked list         │
 ├──────────────────────┼─────────────────────────┼──────────────────────────────┤
 │ End marker           │ last->next == nullptr   │ last->next == head           │
 │ Traversal stop       │ t == nullptr            │ t == start (do-while)        │
 │ Wrap-around          │ manual re-walk          │ natural (loops)              │
 │ Round-robin ideology │ no                      │ yes (endless next)           │
 │ Tail ops (no tail ptr)│ insert tail O(n) walk  │ same                         │
 │ Best for             │ linear data, end-aware  │ looping schedules / records  │
 └──────────────────────┴─────────────────────────┴──────────────────────────────┘
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// CircularList with tail pointer (tail->next == head always)
class CircularList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // append at the back of the ring (O(1) with tail)
    void append(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = tail = n;
            n->next = n;           // ek-node ring khud se close
            return;
        }
        n->next = tail->next;      // naya node head ko point kare
        tail->next = n;            // purana tail ab naye ko jode
        tail = n;                  // tail update
    }

    // insert at head — tail->next bhi update karna hai (O(1) with tail)
    void insertHead(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = tail = n;
            n->next = n;
            return;
        }
        n->next = head;
        tail->next = n;            // ring ki defining feature — tail closes to head
        head = n;
    }

    // delete FIRST node with data == k (search + re-link ring)
    void deleteNode(int k) {
if (!head) return;
        Node* cur = head;
        Node* prev = tail;
        do {
            if (cur->data == k) {
                if (cur == head) {
                    if (head == tail) {          // single-node ring
                        delete head;
                        head = tail = nullptr;
                        return;
                    }
                    head = cur->next;
                }
                prev->next = cur->next;          // ring me se nikal do
                if (cur == tail) tail = prev;    // tail delete hua to update
                delete cur;
                break;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != head);                   // pura ek round
    }

    // print exactly one lap
    void printLap() {
        if (!head) { cout << "(empty)" << endl; return; }
        Node* t = head;
        do {
            cout << t->data; if (t->next != head) cout << " -> ";
            t = t->next;
        } while (t != head);                     // wapas head par ruko
        cout << " (wraps to head)" << endl;
    }

    // search with wrap-around; return 0-based index or -1
    int search(int k) {
        if (!head) return -1;
        int idx = 0;
        Node* t = head;
        do {
            if (t->data == k) return idx;
            t = t->next;
            idx++;
        } while (t != head);
        return -1;
    }

    ~CircularList() {
        if (!head) return;
        Node* t = head;
        do {
            Node* nxt = t->next;
            delete t;
            t = nxt;
        } while (t != head);                     // ring hi tod ke free karo
    }
};

int main() {
    cout << "===== build: append 5,10,15 (circular) =====" << endl;
    CircularList c;
    c.append(5);
    c.append(10);
    c.append(15);
    c.printLap();                     // 5 -> 10 -> 15 (wraps to head)

    cout << "===== insertHead(1) =====" << endl;
    c.insertHead(1);
    c.printLap();                     // 1 -> 5 -> 10 -> 15

    cout << "===== deleteNode(10) =====" << endl;
    c.deleteNode(10);
    c.printLap();                     // 1 -> 5 -> 15

    cout << "===== search =====" << endl;
    cout << "index of 15 = " << c.search(15) << endl;    // 2
    cout << "index of 99 = " << c.search(99) << endl;    // -1

    cout << "===== destructor frees ring =====" << endl;
    return 0;
}
