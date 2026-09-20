/*
═══════════════════════════════════════════════
 DOUBLY LINKED LIST — INTRO
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
Think of a music player playlist: an ordinary (singly) player only has a
NEXT button, so going back to the previous song means restarting the loop
from the top. A doubly linked list player has BOTH a NEXT and a PREVIOUS
button — jumping back is instant. The same idea powers your browser's
Back/Forward arrows, Word's Undo/Redo, and a train whose engine can lead
from either end.

 📖 THEORY:
 - A doubly linked list (DLL) is a chain of nodes where EVERY node holds
   THREE things: a PREV pointer (address of the node before it), DATA, and a
   NEXT pointer (address of the node after it).
 - The FIRST node's prev is NULL ("nothing behind me") and the LAST node's
   next is NULL ("nothing ahead — I am the tail").
 - Because both directions are wired, you can traverse FORWARD from head and
   BACKWARD from tail — something a singly list can never do.
 - Each node costs one extra pointer compared to a singly list, so memory
   per node grows from ~16 bytes to ~24 bytes.
 - Access is still O(n); the win is DIRECTION, not speed of reaching node k.

 ASCII — one DLL node:
 ┌──────────┬──────────┬──────────┐
 │ prev     │ data     │ next     │
 │ (pichla) │ 20       │ (agla)   │
 └──────────┴──────────┴──────────┘

 ASCII — full 3-node doubly list:
 head                                                          tail
  │                                                             │
  ▼                                                             ▼
 ┌─────────┬─────────┬─────────┐   ┌─────────┬─────────┬─────────┐   ┌─────────┬─────────┬─────────┐
 │ prev    │ data=10 │ next────┼──►│ prev    │ data=20 │ next────┼──►│ prev    │ data=30 │ next    │
 │ NULL    │         │         │   │  (10)   │         │         │   │  (20)   │         │  NULL   │
 └─────────┴─────────┴────┬────┘   └────┬────┴─────────┴─────────┘   └─────────┴─────────┴─────────┘
                          └────────────┘ ◄──────────────────────────┘
        (every prev arrow points ONE step back to the previous node)

 ✅ When to use a doubly linked list:
 - You frequently need to move BACKWARD (playlist, browser history, undo).
 - You must DELETE a node when you only have its POINTER (prev gives the
   previous node instantly, O(1)) — the singly list must rescan from head.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Define the node: struct Node { Node* prev; int data; Node* next; }.
         WHY: two self-referential pointers, one for each neighbour — this is
         a self-referential structure with TWO pointers.
 Step 2: Create the first node; set data, prev = NULL, next = NULL.
         WHY: it is currently both head AND tail, so both ends are empty.
 Step 3: Create the second node; link BOTH sides:
         head->next = second  AND  second->prev = head.
         WHY: one arrow per direction — forward chain and backward chain must
         stay consistent, otherwise traversal in one direction breaks.
 Step 4: Create the third node; second->next = third, third->prev = second.
         WHY: middle node now has alive neighbours on both sides.
 Step 5: FORWARD traversal: helper walks next pointers from head while
         temp != NULL. WHY: head is the left end, next chain goes right.
 Step 6: BACKWARD traversal: helper walks prev pointers from tail while
         temp != NULL. WHY: tail is the right end, prev chain goes left.

 VISUAL WALKTHROUGH (state by state):
 Step 2 :  head = [ NULL | 10 | NULL ]         (single node, tail same)
 Step 3 :  head = [ NULL | 10 | ──► [ | 20 | NULL ]   with ◄── back-arrow
 Step 4 :  head = [NULL|10|─► [10|20|─► [20|30|NULL]   both chains complete

 Forward walk : head → print 10 → print 20 → print 30 → NULL stop
 Backward walk: tail → print 30 → print 20 → print 10 → NULL stop

 DRY RUN (exact trace of the demo code below):
   Node* head = new Node;
   head->data = 10; head->prev = NULL; head->next = NULL;
   Node* second = new Node;
   second->data = 20; second->prev = head; second->next = NULL;
   head->next = second;                    // forward link node1→node2
   Node* third = new Node;
   third->data = 30; third->prev = second; third->next = NULL;
   second->next = third;                   // forward link node2→node3
   Node* tail = third;

   FORWARD:
   temp = head → print 10 → temp = head->next = second
   temp = second → print 20 → temp = second->next = third
   temp = third → print 30 → temp = third->next = NULL → loop ends
   Output : 10  20  30

   BACKWARD:
   temp = tail → print 30 → temp = tail->prev = second
   temp = second → print 20 → temp = second->prev = head
   temp = head → print 10 → temp = head->prev = NULL → loop ends
   Output : 30  20  10  ✅ both directions work correctly

 TIME COMPLEXITY CALCULATION:
 - Creating one node: 1 allocation + constant assignments → f(n) = c → O(1).
 - Linking one node into the chain: 1-2 pointer writes → O(1).
 - Forward traversal of n nodes: loop body = constant work, runs n times,
   so f(n) = c×n, coefficient dropped → O(n).
 - Backward traversal of n nodes: identical argument, n iterations → O(n).
 - Reaching the k-th node: k hops from either end worst case → O(n).
   → Time Complexity = O(1) per node creation/link, O(n) for any traversal,
     O(1) delete/insert BEFORE a known node (prev gives the left neighbour).

 SPACE COMPLEXITY CALCULATION:
 - n nodes × (prev 8B + data 4B + next 8B = 20B, padded to 24B) → TOTAL
   memory = n × 24 bytes, linear in n → O(n).
 - Extra cost vs singly: 8 bytes per node (the prev pointer).
 - Both traversals use exactly ONE helper pointer each → auxiliary O(1).
   → Space Complexity = O(n) total, O(1) auxiliary.

 ═══════════ APPROACH COMPARISON ═══════════
 ┌──────────────────────────┬────────────────────────────┬──────────────────────────────┐
 │ Criterion                │ SINGLY LINKED LIST         │ DOUBLY LINKED LIST           │
 ├──────────────────────────┼────────────────────────────┼──────────────────────────────┤
 │ pointers per node        │ 1 (next) ✅               │ 2 (prev + next) ❌           │
 │ backward traversal       │ impossible ❌             │ O(n) from tail ✅            │
 │ delete a GIVEN node      │ O(n) rescan for prev ❌   │ O(1) via node->prev ✅       │
 │ insert before a node     │ O(n) rescan for prev ❌   │ O(1) via node->prev ✅       │
 │ memory per node          │ 16 B (75% overhead) ✅    │ 24 B (83% overhead) ❌       │
 │ forward traversal        │ O(n) ✅                   │ O(n) ✅                      │
 │ random access            │ O(n)                      │ O(n) (still no win)         │
 │ pointer-update mistakes   │ fewer ⚠️                  │ more (both chains) ⚠️        │
 └──────────────────────────┴────────────────────────────┴──────────────────────────────┘
*/
#include <iostream>
using namespace std;

// DLL node — dono taraf ke padosi ke address
struct Node {
    Node* prev;
    int data;
    Node* next;
};

int main() {
    // node 1 — head aur abhi ke liye tail bhi
    Node* head = new Node;
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;

    // node 2 — dono link jodo (aage + peeche)
    Node* second = new Node;
    second->data = 20;
    second->prev = head;        // peeche wala = head
    second->next = NULL;
    head->next = second;        // aage wala bhi jodo

    // node 3 — tail
    Node* third = new Node;
    third->data = 30;
    third->prev = second;
    third->next = NULL;
    second->next = third;

    Node* tail = third;         // right end ko yaad rakho

    // FORWARD traversal — head se next chalti hui
    cout << "Forward  : NULL <- ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "-> NULL" << endl;

    // BACKWARD traversal — tail se prev chalti hui
    cout << "Backward : ";
    temp = tail;
    while (temp != NULL) {
        cout << temp->data << " <- ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;

    // edge case: khali list — dono directions safely zero hops
    Node* empty = NULL;
    if (empty == NULL)
        cout << "Empty list → forward/backward kuch nahi, crash nahi ✅" << endl;

    // heap cleanup — har node ka delete
    delete third;
    delete second;
    delete head;
    return 0;
}