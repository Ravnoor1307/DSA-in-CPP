/*
═══════════════════════════════════════════════
 SLL CLASSIC PROBLEMS — reverse, middle, cycle (Floyd), palindrome
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Four classic interview puzzles on a singly linked list:
 1) REVERSE — a train with coaches facing one way; you want the locomotive
    at the other end. In an SLL you cannot go backwards, so you rebuild the
    chain forwards using three hands (prev/curr/next).
 2) MIDDLE — find the center coach without counting first: a slow walker
    and a runner who moves twice as fast reach the end together while the
    slow walker is exactly at the middle.
 3) CYCLE — a delivery van going around a roundabout forever. Two drivers,
    one twice as fast, MUST meet inside the loop — floyd's tortoise-hare.
 4) PALINDROME — a series of digits mirrored around the middle, like "a
    radar" — compare first↔last, second↔second-last ... either by a stack
    (extra memory) or by reversing the second half (O(1) extra).

 📖 THEORY: (pure English, beginner-level)
 - REVERSE (iterative, 3 pointers):
     prev = null, curr = head;
     loop:  next = curr->next;  curr->next = prev;  prev = curr; curr = next;
     end: head = prev.
     Each link flips exactly once → O(n). Aux O(1).
 - REVERSE (recursive): assume reverse(head->next) returns the reversed
     rest; then head->next->next = head; head->next = null. O(n) time,
     O(n) call stack.
 - MIDDLE (slow/fast): fast moves 2 steps, slow 1 step. When fast hits
     null (even length) or fast->next null (odd), slow is the middle
     (for even: the upper middle). O(n) time, O(1) space.
 - CYCLE (floyd): slow 1 step, fast 2 steps. If they EVER meet before
     fast falls off the list → cycle exists. O(n) time, O(1) space.
   (A visited-pointer SET also works: store visited addresses → O(n) time,
    O(n) space.)
 - CYCLE START NODE (derived): after meeting, distance slow-traveled and
     fast-traveled give 2L = L + k*m  →  the meeting point is the same
     distance from the loop start as head is. Reset one pointer to head,
     advance both 1 step → they meet at the loop start. O(n) total.
 - REMOVE CYCLE: find start node via above, then walk around the loop to
     the node whose next == start, set that next = null.
 - PALINDROME:
     A) STACK: push all, compare popping from top with walking from head.
        O(n) time, O(n) space.
     B) REVERSE-HALF: find middle, reverse the second half, compare halves,
        (then optionally restore). O(n) time, O(1) aux space.

  ASCII — reverse (iterative) on 1→2→3→null
   step   prev   curr     next      action
   init   null   1        2         curr->next = prev  (1→null)
   1      1       2        3         curr->next = prev  (2→1)
   2      2       3        null      curr->next = prev  (3→2)
   3      3       null      --       done: head = prev  (3→2→1)

  ASCII — floyd cycle detection
   list: 1→2→3→4→2 (back edge 4→2)
   step0: slow=1 fast=1
   step1: slow=2 fast=3
   step2: slow=3 fast=5→2
   step3: slow=4 fast=3 ... eventually slow==fast inside loop → cycle.

  WHEN TO USE:
  - Reverse: standard for palindrome-half, add-two-numbers, k-reverse.
  - Slow/fast: middle, cycle, find start, median, delete-nth-from-end.
  - Visited set: simpler to reason but O(n) space — CP may forbid it.
  - Palindrome stack: simplest, memory heavy. Reverse-half: O(1) space.

 🧠 LOGIC — STEP BY STEP:
 Step 1 (reverse): delegate the tail/sub-chain first in recursion.
        WHY: recursive reverse of rest handles everything after head, then
        we only need to attach head at the end of the reversed rest.
 Step 2 (reverse iter): flip curr->next BEFORE advancing curr.
        WHY: after the flip, curr->next no longer points ahead; we must have
        saved it in `next` to continue the walk.
 Step 3 (middle): run fast as the sentinel with BOTH null checks.
        WHY: `fast` may be null on even length and need fast->next guard
        on odd length; missing either check dereferences null.
 Step 4 (cycle): rely on the pigeonhole — fast laps slow inside the loop.
        WHY: inside a cycle, speeds 2 vs 1 close the gap by 1 node each step,
        so they must coincide in at most the cycle length.
 Step 5 (palindrome-half): only reverse the SECOND half, not halves compare.
        WHY: reversing the first half would destroy the head we still need;
        comparing from both ends toward the middle is O(n/2).

 VISUAL WALKTHROUGH:
   reverse: 1→2→3→null  ⇒  3→2→1→null
   middle of 1→2→3→4→5 ⇒ 3 ; middle of 1→2→3→4 ⇒ 3 (upper)
   cycle:   1→2→3→4→2 ⇒ true ; plain 1→2→3→null ⇒ false
   palindrome: 1→2→3→2→1 ⇒ true ; 1→2→3⇒false ; single node ⇒ true.

 DRY RUN: (demo prints)
   list = 1->2->3->4->5
   reverse -> 5->4->3->2->1
   middle = 3 ; list 1->2->3->4 middle = 3 (upper)
   cycle(head) = false ; make 5→3 : cycle(head) = true,
   start node = 3 ; remove cycle → cycle(head) = false
   palindrome(1->2->3->2->1) = true
   palindrome(1->2->3) = false

 TIME COMPLEXITY CALCULATION:
 - reverse(iter): flips n links once each → n O(1) steps → O(n).
 - reverse(rec): T(n) = T(n-1) + O(1) → O(n) time, O(n) stack.
 - middle: fast covers ~n links (2 steps per iteration, n/2 iterations) → O(n).
 - floyd cycle: slow/fast meet within ~(cycle length + approach) ≤ k*n steps
   → O(n). Start node: at most second traversal O(n). Remove: O(n).
   All O(1) aux space.
 - palindrome stack: push n (O(n)) + pop n (O(n)) → O(n), space O(n).
 - palindrome reverse-half: middle O(n) + reverse O(n/2) + compare O(n/2)
   → O(n), space O(1) aux.

 SPACE COMPLEXITY CALCULATION:
 - reverse-iter / middle / floyd / reverse-half: only local pointers → O(1).
 - reverse-rec: recursion depth n → O(n) stack.
 - palindrome-stack / visited-set: stores n pointers/values → O(n).
 → Classic space-efficient versions run in O(1) auxiliary; stack/set variants O(n).

 APPROACH COMPARISON:
 ┌────────────────────────┬──────────────────────┬──────────────────────────┬────────────────────┐
 │ Problem                │ Solution A           │ Solution B               │ Winner             │
 ├────────────────────────┼──────────────────────┼──────────────────────────┼────────────────────┤
 │ Reverse                │ iterative 3-ptr O(n)/O(1)│ recursive O(n)/O(n)   │ iterative (space)  │
 │ Middle                 │ length + walk ≤2n    │ slow/fast O(n)/O(1)      │ slow/fast          │
 │ Cycle detect           │ visited set O(n)/O(n)│ floyd O(n)/O(1)          │ floyd              │
 │ Palindrome             │ stack O(n)/O(n)      │ reverse-half O(n)/O(1)   │ reverse-half       │
 │ Cycle start            │ hash set of addr     │ floyd math O(n)/O(1)     │ floyd              │
 └────────────────────────┴──────────────────────┴──────────────────────────┴────────────────────┘
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// build 1->2->3->4->5 (or 1..n)
Node* build(int n) {
    Node* head = nullptr;
    for (int i = n; i >= 1; i--) { Node* t = new Node(i); t->next = head; head = t; }
    return head;
}
void print(Node* h) {
    while (h) { cout << h->data; if (h->next) cout << " -> "; h = h->next; }
    cout << endl;
}
Node* destroy(Node* head) { while (head) { Node* nxt = head->next; delete head; head = nxt; } return nullptr; }

// --- REVERSE (iterative, 3 pointers) O(n)/O(1) ---
Node* reverseIter(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;   // aage ka save karo
        curr->next = prev;        // link ulta kar do
        prev = curr;              // prev aage badhao
        curr = nxt;               // curr aage badhao
    }
    return prev;                  // naya head = purana tail
}

// --- REVERSE (recursive) O(n)/O(n) stack ---
Node* reverseRec(Node* head) {
    if (!head || !head->next) return head;   // base case: chhoti list ka kaam khatam
    Node* newHead = reverseRec(head->next);  // baaki chain ka reverse
    head->next->next = head;                 // head ko end par laga do
    head->next = nullptr;
    return newHead;
}

// --- MIDDLE via slow/fast (upper middle for even) ---
Node* middle(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;         // slow 1 step
        fast = fast->next->next;   // fast 2 steps
    }
    return slow;
}

// --- Floyd cycle detection ---
bool hasCycle(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;   // mil gaye = loop hai
    }
    return false;
}

// --- find cycle START node (floyd math) ---
Node* cycleStart(Node* head) {
    Node* slow = head, *fast = head;
    bool found = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { found = true; break; }
    }
    if (!found) return nullptr;
    slow = head;                   // ek ko head se chalao
    while (slow != fast) {          // dono 1-1 step, milo start par
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// --- remove cycle: walk to the node just before start, break its link ---
Node* removeCycle(Node* head) {
    Node* start = cycleStart(head);
    if (!start) return head;
    Node* t = start;
    while (t->next != start) t = t->next;   // loop ghoom ke start se pehle wala
    t->next = nullptr;                        // wahi se tod do
    return head;
}

// --- palindrome: reverse second half + compare (O(1) aux) ---
bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* mid = middle(head);        // (upper middle)
    Node* second = reverseIter(mid); // second half reversed
    Node* a = head, *b = second;
    bool ok = true;
    while (a && b) {
        if (a->data != b->data) { ok = false; break; }
        a = a->next;
        b = b->next;
    }
    return ok;
}

int main() {
    cout << "===== REVERSE =====" << endl;
    Node* h = build(5);
    print(h);
    h = reverseIter(h);
    print(h);                       // 5->4->3->2->1
    h = reverseRec(h);
    print(h);                       // wapas 1->2->3->4->5

    cout << "===== MIDDLE =====" << endl;
    cout << "middle of len5 = " << middle(h)->data << endl;  // 3
    Node* hm = build(4);
    cout << "middle of len4 = " << middle(hm)->data << endl; // 3 (upper)

    cout << "===== CYCLE =====" << endl;
    cout << "plain cycle? " << (hasCycle(h) ? "yes" : "no") << endl;   // no
    Node* cyc = build(5);
    Node* t3 = cyc; while (t3->data != 3) t3 = t3->next;   // node 3
    Node* tail = cyc; while (tail->next) tail = tail->next;
    tail->next = t3;                                       // 5 -> 3
    cout << "cycle? " << (hasCycle(cyc) ? "yes" : "no") << endl;       // yes
    cout << "start node = " << cycleStart(cyc)->data << endl;          // 3
    cyc = removeCycle(cyc);
    cout << "after remove, cycle? " << (hasCycle(cyc) ? "yes" : "no") << endl; // no

    cout << "===== PALINDROME =====" << endl;
    Node* pal = build(5);          // 1,2,3,4,5 -> nahi
    cout << "1-2-3-4-5 pal? " << (isPalindrome(pal) ? "yes" : "no") << endl;
    Node* pal2 = new Node(1); pal2->next = new Node(2); pal2->next->next = new Node(3);
    pal2->next->next->next = new Node(2); pal2->next->next->next->next = new Node(1);
    cout << "1-2-3-2-1 pal? " << (isPalindrome(pal2) ? "yes" : "no") << endl;

    // cleanup
    h = destroy(h); hm = destroy(hm); cyc = destroy(cyc); pal = destroy(pal); pal2 = destroy(pal2);
    return 0;
}
