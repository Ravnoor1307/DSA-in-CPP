/*
═══════════════════════════════════════════════
 LINKED LIST INTRO — why, node structure, node creation, memory layout
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a treasure hunt. The leader never hands you the WHOLE map; instead
 she gives you ONE clue card: "start here". On that card is written a small
 message AND the location of the NEXT clue card. You follow card 1 → find
 card 2 → follow it → find card 3, and so on until the last card says
 "treasure found". The cards are scattered anywhere in the city — but the
 chain never breaks because each card remembers where the next one lives.
 That is EXACTLY a linked list: every node stores its data PLUS the address
 of the next node, and the whole collection works even though the nodes are
 scattered all over heap memory.

 📖 THEORY: (pure English, beginner-level)
 - LINKED LIST = a chain of NODES. Each NODE has two parts:
     (1) DATA  — whatever we store (int, string, object, ...)
     (2) NEXT  — a POINTER to the next node in the chain
 - SELF-REFERENTIAL STRUCT: the struct contains a pointer to its OWN type.
     struct Node { int data; Node* next; };
   This is what lets us build a variable-length chain.
 - HEAD: a pointer to the very first node. If the list is empty, head = nullptr.
 - TAIL: the last node (its next = nullptr) — marks the end of the list.
 - WHY DOES THIS MATTER vs ARRAY:
     * Array  = contiguous memory, fixed size at declaration.
     * Linked = scattered heap nodes, grows/shrinks dynamically.
     * Array  = O(1) random access via base + i*size.
     * Linked = must WALK from head every time → O(n) access.
     * Array  = insert/delete in the middle shifts all elements (O(n) anyway).
     * Linked = insert/delete is just pointer surgery (O(1) after we already
       have the position; finding that position is the O(n) part).
 - Node creation on the heap: `Node* p = new Node;` — memory lives until
   `delete p;`. On older/CP programs `malloc` is also used, but new is
   type-safe and calls constructors (overkill here, still preferred in C++).

  ASCII — a singly linked list of 3 nodes:
       head
        │
        ▼
    ┌──────┬─────┐       ┌──────┬─────┐       ┌──────┬─────┐
    │ data │ next│──────▶│ data │ next│──────▶│ data │ next│────▶ nullptr
    │  =10 │   ● │       │  =20 │   ● │       │  =30 │  ✗  │
    └──────┴─────┘       └──────┴─────┘       └──────┴─────┘
       node1               node2               node3 (tail)

  Memory layout — nodes scattered on the HEAP, linked by addresses:
     heap:   node1 @ 0x100 ──▶ node2 @ 0x2A4 ──▶ node3 @ 0x1E8 ──▶ nullptr
   (addresses are arbitrary — heap allocations are not contiguous!)

  Array vs Linked List at a glance:
      feature        | array           | linked list
     ────────────────┼─────────────────┼─────────────────────────
      memory         | contiguous      | scattered (heap)
      size           | fixed           | dynamic (grows/shrinks)
      access i-th    | O(1)            | O(n) walk
      insert head    | O(n) shift      | O(1) pointer swap
      extra storage  | none            | 1 pointer per node (+prev in DLL)

  WHEN TO USE A LINKED LIST:
  - Many insert/delete operations at the FRONT or MIDDLE, few random reads.
  - The number of elements is unknown at compile time / changes a lot.
  - Implementing stacks, queues, adjacency lists, LRU caches.
  - Do NOT use it when random access + cache-friendliness matter more.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Define the self-referential Node struct.
        WHY: `Node* next` lets one node point at another node of the same type,
        which is the whole idea of a chain.
 Step 2: Create each node on the HEAP with `new Node`.
        WHY: heap memory survives the function; local stack variables die when
        the function returns. The chain must outlive main's individual steps.
 Step 3: Link by assigning next pointers — order matters (node1→node2→node3).
        WHY: if you overwrite a next pointer before saving the old target you
        silently LOSE the rest of the chain.
 Step 4: Set the last node's next = nullptr.
        WHY: nullptr is the universal "end of list" marker; loops read it to stop.
 Step 5: Keep a head pointer; pass it everywhere OR use a wrapper struct/class.
        WHY: every traversal starts at head — without it the whole chain is
        unreachable and leaks.

 VISUAL WALKTHROUGH: building the 3-node chain step by step
   after node1:  head → [10|→nullptr]
   after node2:  head → [10|→] → [20|→nullptr]
   after node3:  head → [10|→] → [20|→] → [30|→nullptr]

 DRY RUN: (the demo program below, line by line)
   create3(): n1=10, n2=20, n3=30 — 3 heap nodes linked one after another
   printList: Start at head → visit n1(10) → n2(20) → n3(30) → nullptr, stop.
       In array terms the visited order is {10, 20, 30}.
   nodeSum:  10 + 20 + 30 = 60 (each node visited exactly once, n = 3)
   showLayout: prints actual heap addresses of the 3 nodes → they are NOT
       consecutive (unlike &arr[0], &arr[1] which differ by exactly 4 bytes).

 TIME COMPLEXITY CALCULATION:
 - buildList of n nodes: each node creation = 1 heap new + a few
   assignments = constant work; done n times.
 - print/traverse: n nodes visited once, 1 print each.
 - sum: n nodes visited once, 1 addition each.
 - random access arr[i]: base + i*size = single arithmetic jump (array only).
 → Time Complexity = O(n) per full pass (create/traverse/sum for n nodes);
   single node creation = O(1); array i-th access = O(1) vs list O(n).

 SPACE COMPLEXITY CALCULATION:
 - Each node stores data + 1 pointer → constant bytes per node.
 - n nodes total → total heap usage grows linearly with n.
 - No extra helper data structure used in these demos → auxiliary O(1).
 → Space Complexity = O(n) for the list itself, O(1) auxiliary.

 APPROACH COMPARISON:
 ┌──────────────────┬──────────────────────┬─────────────────────────────┐
 │ Aspect           │ Array                │ Linked List                 │
 ├──────────────────┼──────────────────────┼─────────────────────────────┤
 │ Memory           │ contiguous block     │ scattered heap nodes        │
 │ Size             │ fixed at compile time│ grows/shrinks dynamically   │
 │ Access i-th      │ O(1) (base+offset)   │ O(n) (walk from head)       │
 │ Insert at head   │ O(n) shift all right │ O(1) repoint head           │
 │ Delete at head   │ O(n) shift all left  │ O(1) head = head->next      │
 │ Extra memory     │ none                 │ 1 pointer / node (DLL: 2)   │
 │ Cache friendly   │ yes (contiguous)     │ no (scattered)              │
 │ Best for         │ fast reads, fixed size│ frequent front/mid insert  │
 └──────────────────┴──────────────────────┴─────────────────────────────┘
 */
#include <iostream>
using namespace std;

// self-referential Node struct: data + pointer to next Node of the SAME type
struct Node {
    int data;
    Node* next;

    Node(int val) {   // constructor: node ready with data, next = nullptr
        data = val;
        next = nullptr;
    }
};

// build a fixed 3-node chain on the heap
Node* create3() {
    Node* a = new Node(10);      // 3 alag heap node create kiye
    Node* b = new Node(20);
    Node* c = new Node(30);
    a->next = b;                 // a me b ka address, b me c ka, c me null
    b->next = c;
    return a;                    // head return kiya, poori chain iske saath
}

// print the whole list: head se start, nullptr tak
void printList(Node* head) {
    Node* t = head;
    while (t != nullptr) {       // end marker par ruk jaao
        cout << t->data;
        if (t->next) cout << " -> ";
        t = t->next;             // aage badho
    }
    cout << " -> nullptr" << endl;
}

// sum every node's data
int nodeSum(Node* head) {
    int s = 0;
    Node* t = head;
    while (t != nullptr) {
        s += t->data;
        t = t->next;
    }
    return s;
}

// show that heap nodes are NOT contiguous, array elements ARE
void showLayout(Node* head) {
    Node* t = head;
    int arr[3] = {10, 20, 30};
    cout << "  heap node addresses : ";
    while (t) {
        cout << t << "  ";
        t = t->next;
    }
    cout << endl << "  array addresses(4-byte gap) : ";
    for (int i = 0; i < 3; i++) cout << &arr[i] << "  ";
    cout << endl;
}

int main() {
    cout << "===== DEMO 1: create 3-node chain =====" << endl;
    Node* head = create3();
    cout << "List : ";
    printList(head);

    cout << "===== DEMO 2: sum of all nodes =====" << endl;
    cout << "Sum of node data = " << nodeSum(head) << endl;

    cout << "===== DEMO 3: layout (heap vs array) =====" << endl;
    showLayout(head);

    // cleanup: poori chain free karo taaki memory leak na ho
    Node* t = head;
    while (t) {
        Node* nxt = t->next;     // delete se pehle next save karo
        delete t;
        t = nxt;
    }
    return 0;
}
