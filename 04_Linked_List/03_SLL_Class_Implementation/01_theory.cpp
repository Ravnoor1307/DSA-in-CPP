/*
═══════════════════════════════════════════════
 SLL CLASS IMPLEMENTATION — wrapper, destructor, length, nth-from-end
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Raw pointers everywhere invite chaos — forget one free and you leak, delete
 one node twice and you crash. So companies wrap the chain inside a MANAGER
 class, exactly like a building's facility team: you never touch individual
 light bulbs (nodes) yourself; you tell the MANAGER "turn on / off / count".
 The manager hides the plumbing (head pointer, loops, deletes) behind clean
 methods. Same inside C++: a Linked List CLASS owns the head, exposes
 pushFront/size/search, and — the crucial part — a DESTRUCTOR that frees the
 ENTIRE chain automatically when the list dies, so nobody leaks. This topic
 also shows the classic question: "find the k-th node from the END" — the
 naive way counts length first; the clever way uses two pointers at a gap.

 📖 THEORY: (pure English, beginner-level)
 - WHY A WRAPPER CLASS:
     * Encapsulate `Node* head` + all operations in one object.
     * Guarantee initialization (constructor sets head = nullptr).
     * Guarantee cleanup (destructor frees EVERY node).
     * Allow holding extra metadata (size, tail) — but careful: maintaining
       size costs one update per mutation, trading O(1) time for bookkeeping.
 - DESTRUCTOR `~LinkedList()`:
     walks the chain, saving next before each delete, so all n nodes free.
     WITHOUT it every `LinkedList L;` at scope end leaks its whole chain.
 - LENGTH COUNT: iterate to count nodes → O(n).
 - NTH FROM END (k-th from end, 1-based):
     Method A — length m: find length m, then walk (m - k) steps from head.
       m + (m-k) ≤ 2m work → O(m), O(1) space.
     Method B — two-pointer gap k: move `fast` k steps ahead, then walk
       BOTH pointers until fast hits nullptr; `slow` is now k from the end.
       exactly m moves total → O(m), O(1) space. NO length precomputation.

  ASCII — nth-from-end by two-pointer gap (k = 2, 1-based → 2nd from end)
   list:    head → [1] → [2] → [3] → [4] → [5] → nullptr
   step 0:  slow=1, fast moves 2 ahead → fast=3
            slow ─►    fast ─────────►
   move together:
            slow=2 fast=4    slow=3 fast=5    slow=4 fast=nullptr ✔
            2nd from end = 4

  ASCII — destructor freeing the chain
   before: head → [1|→] → [2|→] → [3|→null]
   loop:   save nxt → delete head → head = nxt
           (head=1)       (head=2)      (head=3)      head=nullptr
   result: all nodes freed, no dangling pointer, no leak.

  WHEN TO USE A CLASS (avoid raw-loop bugs):
  - You write more than a throwaway demo → encapsulation pays off.
  - You need automatic cleanup on scope exit → destructor + RAII.
  - You want to offer a clean API (addFront, back, size, empty).
  - For CP one-offs a struct + free functions is fine and lighter.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Constructor sets head = nullptr, maybe tail = nullptr, size = 0.
        WHY: an object must never start life pointing at garbage; empty list
        is the only valid starting state.
 Step 2: Destructor frees every node in a loop, saving next first.
        WHY: `delete head` only frees ONE node; without saving head->next you
        lose the address of everything after it (classic leak/dangle bug).
 Step 3: size() walks and counts if we do NOT maintain a field.
        WHY: a cached size field gives O(1) size() but every mutation must
        ++/-- it; a walk keeps mutations simple but size() becomes O(n).
 Step 4: nthFromEnd two-pointer: gap fast by k first, then advance together.
        WHY: the gap stays exactly k, so when fast lands on nullptr, slow is
        exactly the k-th node from the end — no length precompute needed.
 Step 5: Validate k (must be ≥ 1 and ≤ length) before dereferencing.
        WHY: k too big would make fast run past nullptr → crash.

 VISUAL WALKTHROUGH: pushFront 5,10,15 → list = 15 → 10 → 5
   pushFront(5):  head → [5]
   pushFront(10): head → [10] → [5]
   pushFront(15): head → [15] → [10] → [5]
   size() = 3, nthFromEnd(1) = 5, nthFromEnd(3) = 15, nthFromEnd(4) = -1

 DRY RUN: (demo output, exact)
   after pushFront 5,10,15 → print: 15 -> 10 -> 5 ; size = 3
   1st from end = 5   2nd = 10   3rd = 15   4th = -1 (k invalid)
   destructor runs at main end → frees 15,10,5 in that order.

 TIME COMPLEXITY CALCULATION:
 - pushFront: 2 pointer writes → O(1).
 - print/size (uncached walk): n nodes → O(n).
 - nthFromEnd Method B: fast runs k then both run (m-k) → total m moves.
   constant work per move → O(m), m = list length.
 - nthFromEnd Method A: length walk m + second walk m-k ≤ 2m → O(m).
 - destructor: n deletes, each O(1) → O(n).
 - Cached size: size() O(1) but each pushFront/delete adds O(1) work.
 → Forward ops O(1); any full walk (print, size, nth-from-end) O(n);
   all auxiliary O(1).

 SPACE COMPLEXITY CALCULATION:
 - Class holds a few pointers + optionally size int → O(1) overhead.
 - The chain itself is n heap nodes → O(n) data.
 - nthFromEnd uses only 2 extra pointers, no array → auxiliary O(1).
 - destructor uses 1 temporary pointer → O(1).
 → Space = O(1) auxiliary for every op; O(n) for the stored list.

 APPROACH COMPARISON:
 ┌──────────────────────┬──────────────┬──────────────┬─────────────────────┐
 │ Aspect               │ Raw funcs    │ Class wrapper│ nthFromEnd style    │
 ├──────────────────────┼──────────────┼──────────────┼─────────────────────┤
 │ Cleanup              │ manual       │ destructor   │ n/a                 │
 │ Encapsulation        │ none         │ private head │ n/a                 │
 │ nth-from-end         │ —            │ —            │ length vs 2-pointer │
 │ length method cost   │ —            │ —            │ ≤ 2n, O(1) sp       │
 │ 2-pointer cost       │ —            │ —            │ n, O(1) sp, no pre. │
 │ size() cached        │ walk O(n)    │ field O(1)   │ (bookkeeping O(1))  │
 └──────────────────────┴──────────────┴──────────────┴─────────────────────┘
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// LinkedList: class wrapper — head ko andar chhupa ke rakho
class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }     // constructor: empty list se shuru

    ~LinkedList() {                       // destructor: poori chain free
        while (head) {
            Node* nxt = head->next;       // pehle next save karo
            delete head;                  // tab delete karo
            head = nxt;                   // aage badho
        }
    }

    void pushFront(int v) {
        Node* n = new Node(v);
        n->next = head;
        head = n;
    }

    void print() {
        Node* t = head;
        while (t) { cout << t->data; if (t->next) cout << " -> "; t = t->next; }
        cout << endl;
    }

    int size() {                          // walk karke ginti karo
        int c = 0;
        for (Node* t = head; t; t = t->next) c++;
        return c;
    }

    // 1-based nth from end; -1 agar k invalid
    int nthFromEnd(int k) {
        Node* slow = head;
        Node* fast = head;
        for (int i = 0; i < k; i++) {     // fast ko k aage le jao
            if (!fast) return -1;          // list itni lambi nahi
            fast = fast->next;
        }
        while (fast) {                     // dono ko saath chalte raho
            slow = slow->next;
            fast = fast->next;
        }
        return slow ? slow->data : -1;     // jab fast null, slow = nth-from-end
    }
};

int main() {
    cout << "===== build: pushFront 5,10,15 =====" << endl;
    LinkedList L;
    L.pushFront(5);
    L.pushFront(10);
    L.pushFront(15);
    L.print();                            // 15 -> 10 -> 5
    cout << "size = " << L.size() << endl;

    cout << "===== nth from end =====" << endl;
    cout << "1st from end = " << L.nthFromEnd(1) << endl;   // 5
    cout << "2nd from end = " << L.nthFromEnd(2) << endl;   // 10
    cout << "3rd from end = " << L.nthFromEnd(3) << endl;   // 15
    cout << "4th from end = " << L.nthFromEnd(4) << endl;   // -1 (invalid)

    cout << "===== destructor runs at end of main (auto cleanup) =====" << endl;
    return 0;
}
