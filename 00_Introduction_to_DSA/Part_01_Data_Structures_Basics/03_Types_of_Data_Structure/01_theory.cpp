/*
═══════════════════════════════════════════════
 TYPES OF DATA STRUCTURE
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a city. Some collections are a straight line — the queue of
 people at an ATM, or a stack of plates in a restaurant kitchen. Others
 are branching — a family tree, or the road map of a metro network. A
 single box of tools can hold all of them because each is a different
 "shape" of organizing things. Data structures are exactly the same:
 some arrange data in a straight line (linear), some in branches
 (non-linear), and some are the tiny built-in building blocks
 (primitive). Knowing the shape tells you which one suits which problem.

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: Data structures are classified by how elements relate to
   each other and whether the language provides them natively:
     1. PRIMITIVE  : built into the language, directly supported by the
                     hardware (int, char, float, double, bool, void).
     2. NON-PRIMITIVE : built by combining primitives:
           • LINEAR    : elements in a sequence, each has a predecessor &
                         successor (except ends) — array, linked list,
                         stack, queue.
           • NON-LINEAR: elements linked in a hierarchy or network —
                         tree, graph.
 - key points / properties:
   • PRIMITIVE = single value, fixed size, hardware-level speed.
   • LINEAR = one-to-one relationship; can be traversed in one pass.
   • Stack is LIFO (Last In First Out); Queue is FIFO (First In First
     Out) — both are linear but with different access rules.
   • Tree = one-to-many (each parent may have many children);
     Graph = many-to-many (arbitrary connections).
   • A linked list grows/shrinks at runtime; an array has fixed size
     (unless dynamic like vector).
 - classification tree:

                        DATA STRUCTURES
                       /              \
                PRIMITIVE            NON-PRIMITIVE
        (int,float,char,double,    /            \
          bool,void)             LINEAR        NON-LINEAR
                                 /  |  \        /       \
                            Array Stack Queue  Tree    Graph
                               + Linked List

 - when to use:
   • Primitive → when you need a single number/letter/flag.
   • Array/Vector → fixed or sequential data, fast index access.
   • Linked List → frequent insertion/deletion anywhere.
   • Stack → undo, function calls, bracket matching.
   • Queue → printing jobs, ticket counters, BFS.
   • Tree → file systems, folders, BST searching.
   • Graph → networks, maps, social connections.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Show primitive types (int, float, char) as single variables.
         WHY: This establishes the atomic bricks every bigger structure
         is made of, and that they are hardware-supported (fast).
 Step 2: Demonstrate a linear array by iterating and printing it.
         WHY: An array shows the classic one-to-one sequence — each
         element knows only its neighbour indexes.
 Step 3: Demonstrate a linked list by linking 3 nodes with pointers and
         walking them with a pointer loop.
         WHY: A linked list is linear BUT stored in scattered memory
         chunks joined by pointers — proving "linear" means logical
         order, not physical adjacency.
 Step 4: Demonstrate a binary tree by pointing a root at two leaves.
         WHY: A tree shows one-to-many branching — the defining feature
         of non-linear structures.
 Step 5: Print all three, labelled LINEAR vs NON-LINEAR.
         WHY: Labelling fixes the classification in memory — same "print"
         operation, but the internal organization differs.

 VISUAL WALKTHROUGH: (three shapes in memory)

   PRIMITIVE (single cells)                 LINEAR — array (adjacent cells)
   ┌──────┐  ┌──────┐  ┌──────┐             ┌───┬───┬───┬───┬───┐
   │ int  │  │float │  │ char │             │ 1 │ 2 │ 3 │ 4 │ 5 │
   │ 42   │  │ 3.14 │  │ 'A'  │             └───┴───┴───┴───┴───┘
   └──────┘  └──────┘  └──────┘              contiguous memory

   LINEAR — linked list (scattered cells + pointers)
   ┌────┐   ┌────┐   ┌────┐
   │10│→───→│20│→───→│30│→null
   └────┘   └────┘   └────┘
    head                 (tail ends in null)

   NON-LINEAR — binary tree (branching)
         ┌──────┐
         │  1   │ root
         └──┬───┘
        ┌───┴───┐
      ┌─┴─┐   ┌─┴─┐
      │ 2 │   │ 3 │   left child, right child
      └───┘   └───┘

 DRY RUN: (full trace of the demo below)
   PRIMITIVE part:
     x=42, f=3.14, c='A' → prints "PRIMITIVE: int=42 float=3.14 char=A"

   ARRAY part (n = 5):
     i=0 → print 1     i=1 → print 2     i=2 → print 3
     i=3 → print 4     i=4 → print 5
     Output: "LINEAR array: 1, 2, 3, 4, 5"

   LINKED LIST part (3 nodes a→b→c):
     p=&a → print 10, p=&b → print 20, p=&c → print 30, p=nullptr → stop
     Output: "LINEAR linked list: 10 -> 20 -> 30"

   TREE part (root 1, left 2, right 3):
     Output: "NON-LINEAR tree: root=1 left=2 right=3"

 TIME COMPLEXITY CALCULATION:
   - Primitive prints          → 3 constant steps
   - Array print loop runs n times, each iteration 1 print + 1 compare  → n steps
   - Linked list walk: k nodes (here 3) → 1 step per node             → k steps
   - Tree print: fixed 2 level lookups (left, right)                  → 2 steps
   - For a general input the dominating term is the linear traversal
     of n elements; the demo's list/tree parts are small constants.
   - Total ≈ n + k + constant (k grows with nodes too)
 → Time Complexity = O(n)   (traversing each element once, no nesting)

 SPACE COMPLEXITY CALCULATION:
   - Array stores n integers                         → n units
   - Linked list stores k nodes (data + 1 pointer)   → k units
   - Tree stores m nodes (data + 2 pointers)         → m units
   - Pointer/loop variables                          → constant few units
   - Each structure uses exactly the cells it needs; no extra copies.
   - Total = n + k + m + constant
 → Space Complexity = O(n + k + m)   (proportional to the data stored)

 APPROACH COMPARISON: (Linear vs Non-Linear)
 ┌───────────────────┬────────────────────────────┬────────────────────────────┐
 │ Aspect            │ LINEAR                     │ NON-LINEAR                 │
 ├───────────────────┼────────────────────────────┼────────────────────────────┤
 │ Relationship      │ One-to-one (sequence)      │ One-to-many / many-to-many │
 │ Examples          │ array, linked list, stack, │ tree, graph                │
 │ Traversal         │ One straight pass          │ Multiple paths/branches    │
 │ Memory layout     │ Usually contiguous or      │ Nodes reference children / │
 │                   │ pointer-chained            │ neighbours                 │
 │ Best for          │ Sequences, queues, LIFO    │ Hierarchy, networks, maps  │
 │ Demo here         │ array + linked list        │ binary tree                │
 └───────────────────┴────────────────────────────┴────────────────────────────┘
*/

#include <iostream>
using namespace std;

// non-linear data structure: binary tree node (ek parent, 2 children)
struct Node {
    int data;
    Node* left;    // left child ko point karta hai
    Node* right;   // right child ko point karta hai
};

// linear data structure: singly linked list node (next pointer)
struct LLNode {
    int data;
    LLNode* next;  // agla element point karta hai
};

int main() {
    // PRIMITIVE data types — hardware directly support karta hai
    int x = 42;
    float f = 3.14f;
    char ch = 'A';
    cout << "PRIMITIVE: int=" << x << " float=" << f << " char=" << ch << "\n";

    // LINEAR — array: contiguous memory, index se access
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "LINEAR array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << (i < 4 ? ", " : "");   // last element ke baad comma nahi
    }
    cout << "\n";

    // LINEAR — linked list: 3 nodes pointer se aapas me judte hain
    LLNode a{10, nullptr};
    LLNode b{20, nullptr};
    LLNode c{30, nullptr};
    a.next = &b;   // a ke baad b aayega
    b.next = &c;   // b ke baad c aayega
    cout << "LINEAR linked list: ";
    for (LLNode* p = &a; p != nullptr; p = p->next) {
        cout << p->data << (p->next ? " -> " : "");   // pointer se element nikalna
    }
    cout << "\n";

    // NON-LINEAR — binary tree: root ke 2 children
    Node n2{2, nullptr, nullptr};
    Node n3{3, nullptr, nullptr};
    Node root{1, &n2, &n3};   // root 1, left = 2, right = 3
    cout << "NON-LINEAR tree: root=" << root.data
         << " left=" << root.left->data
         << " right=" << root.right->data << "\n";

    return 0;
}