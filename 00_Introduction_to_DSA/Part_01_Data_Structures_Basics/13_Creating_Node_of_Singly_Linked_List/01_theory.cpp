/*
═══════════════════════════════════════════════
 CREATING A NODE (SINGLY LINKED LIST)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are standing in a treasure hunt. Each clue card tells you
 where the next clue is hidden. You follow clue after clue until you
 reach the final treasure. A linked list works exactly the same way —
 each "node" holds some data AND a pointer to the next node. You start
 at the first node and follow the chain until the end. Unlike an array
 where all elements sit next to each other in memory, nodes can be
 scattered anywhere, connected only by these pointers.

 📖 THEORY:
 - A Node is the basic building block of a linked list.
 - It contains two parts:
     1. DATA    → the actual value (int, float, string, etc.)
     2. NEXT    → a pointer to the next node in the list
 - In a singly linked list, each node points forward only (one direction).
 - The last node's next pointer is set to NULL (nullptr) to mark the end.
 - The "head" pointer holds the address of the first node in the list.
 - If head is NULL, the list is empty.

 ASCII DIAGRAM:

  HEAD
   │
   ▼
 ┌──────┬──────┐    ┌──────┬──────┐    ┌──────┬──────┐
 │  10  │  ──────►  │  20  │  ──────►  │  30  │ NULL │
 └──────┴──────┘    └──────┴──────┘    └──────┴──────┘
   Node 1             Node 2             Node 3
   [data|next]        [data|next]        [data|next]

 - When to use:
   • When you need frequent insertions/deletions (no shifting needed)
   • When you don't know the size in advance
   • When random access by index is NOT required

 🧠 LOGIC — STEP BY STEP:

 Step 1: Define the node structure using "struct Node".
   WHY: We need a blueprint that tells the compiler what a node looks
   like. Each node must have a data field and a next pointer.

 Step 2: Write a helper function createNode() that allocates a new node.
   WHY: Instead of writing "new Node" everywhere, a helper function
   keeps code clean and handles allocation + initialization in one place.

 Step 3: Allocate memory for each node and assign data values.
   WHY: Without dynamic allocation (new), nodes would be destroyed when
   the function ends. new/delete gives us control over node lifetime.

 Step 4: Link nodes by setting each node's next pointer to the next node.
   WHY: A single node is useless on its own. We connect them by making
   each node's next point to the address of the next node in sequence.

 Step 5: Traverse from head and print data at each node.
   WHY: Verification. Start at head, follow next pointers until NULL,
   printing data at each step to confirm the list is built correctly.

 VISUAL WALKTHROUGH:

  State 0: head = NULL (empty list)
  ┌──────┐
  │ NULL │  ← head
  └──────┘

  State 1: node1 created with data = 10
  ┌──────────┬──────┐
  │ 10       │ NULL │  ← node1
  └──────────┴──────┘
  head → node1

  State 2: node2 created with data = 20
  ┌──────────┬──────┐    ┌──────────┬──────┐
  │ 10       │  ──────►  │ 20       │ NULL │  ← node2
  └──────────┴──────┘    └──────────┴──────┘
  head → node1 → node2

  State 3: node3 created with data = 30, all linked
  ┌──────────┬──────┐    ┌──────────┬──────┐    ┌──────────┬──────┐
  │ 10       │  ──────►  │ 20       │  ──────►  │ 30       │ NULL │
  └──────────┴──────┘    └──────────┴──────┘    └──────────┴──────┘
  head → node1 → node2 → node3

 DRY RUN:
  Line | Action                        | State
  ─────┼───────────────────────────────┼──────────────────────────
   30  | Node* node1 = createNode(10)  | node1: [10 | NULL]
   31  | Node* node2 = createNode(20)  | node2: [20 | NULL]
   32  | Node* node3 = createNode(30)  | node3: [30 | NULL]
   36  | node1->next = node2           | node1 -> node2
   37  | node2->next = node3           | node2 -> node3
   40  | Traverse: print 10 -> 20 -> 30| List verified!
   44  | Single node created: 99       | single: [99 | NULL]
   47  | Delete node1, node2, node3    | Memory freed

 TIME COMPLEXITY CALCULATION:
 - createNode(): Allocates 1 node, assigns data and next = constant work
     1 allocation + 2 assignments = 3 operations = O(1)
 - Linking: Setting 1 next pointer = O(1) per link
 - Traversal: Visiting each node once = n nodes x O(1) per visit = n operations
 → Time Complexity = O(n) for traversal, O(1) for single node creation

 SPACE COMPLEXITY CALCULATION:
 - Each node stores: 1 int + 1 pointer = constant space per node
 - For n nodes: n x constant space
 → Space Complexity = O(n)

 APPROACH COMPARISON:
 ┌─────────────────────┬──────────────────┬──────────────────────┐
 │   Property          │  Linked List     │     Array            │
 ├─────────────────────┼──────────────────┼──────────────────────┤
 │ Insert at start     │ O(1)             │ O(n) — shift all     │
 │ Insert at end       │ O(n)* / O(1)**   │ O(1) amortized       │
 │ Access by index     │ O(n) — traverse  │ O(1) — direct        │
 │ Memory usage        │ Extra for ptrs   │ Contiguous, no ptrs  │
 │ Size flexibility    │ Dynamic          │ Fixed (static array) │
 └─────────────────────┴──────────────────┴──────────────────────┘
  * O(n) without tail pointer   ** O(1) with tail pointer
═══════════════════════════════════════════════
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    cout << "=== Creating a Node - Singly Linked List ===" << endl;
    cout << endl;

    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);

    cout << "Nodes created:" << endl;
    cout << "node1 -> data = " << node1->data
         << ", next = " << node1->next << endl;
    cout << "node2 -> data = " << node2->data
         << ", next = " << node2->next << endl;
    cout << "node3 -> data = " << node3->data
         << ", next = " << node3->next << endl;
    cout << endl;

    node1->next = node2;
    node2->next = node3;

    cout << "After linking:" << endl;
    cout << "node1->next = " << node1->next << endl;
    cout << "node2->next = " << node2->next << endl;
    cout << "node3->next = " << node3->next << " (NULL)" << endl;
    cout << endl;

    cout << "Linked List: ";
    printList(node1);

    cout << "\n--- Edge Case: Single Node ---" << endl;
    Node* single = createNode(99);
    cout << "Single Node List: ";
    printList(single);

    cout << "\n--- Edge Case: Empty List ---" << endl;
    Node* empty = nullptr;
    cout << "Empty List: ";
    printList(empty);

    delete node1;
    delete node2;
    delete node3;
    delete single;

    cout << "\nAll nodes deleted. Program ends." << endl;
    return 0;
}
