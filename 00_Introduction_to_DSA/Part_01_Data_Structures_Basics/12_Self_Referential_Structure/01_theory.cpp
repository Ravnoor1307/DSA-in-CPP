/*
═══════════════════════════════════════════════
 SELF-REFERENTIAL STRUCTURE
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
Picture a treasure hunt: each clue card carries a message and the hiding spot
of the next clue card. A card therefore contains a reference to ANOTHER card
of the same kind — a fingerprint of the chain. Same story with a garland of
beads: every bead "knows" the bead that lies ahead, each bead pointing to its
own kind. Whatever the chain grows by, the card or bead only ever holds a
long SLIP OF PAPER (an address), never the whole next object inside itself.

 📖 THEORY:
 - A SELF-REFERENTIAL STRUCTURE is a struct whose MEMBER is a POINTER to a
   struct OF THE SAME TYPE.
   struct Node { int data; Node* next; };
   The "Node* next" member makes Node refer to itself.
 - The pointer stores an ADDRESS of another node, not a copy. Node (a value
   object) can therefore contain as many node-addresses as we like.
 - A pointer of any type has a FIXED size — 8 bytes on 64-bit. This is the
   secret that keeps sizeof(Node) finite.
 - The chain idea this enables is the foundation of ALL linked structures:
   linked list (1 pointer), doubly linked list (2 pointers), binary tree
   (2 child pointers), graph / trie (many pointers).
 - A self-referential needed by VALUE (Node next;) is impossible: the
   compiler would run an infinite size computation and refuse.

 ASCII — the struct and its object in memory:
 struct Node {              ┌────────────────────────────┐
     int data;              │  data: 4 bytes             │
     Node* next;   ───────► │  next: 8 bytes (address)   │  ≈ 16 B with padding
 };                          └────────────────────────────┘

 One node holding the address of the next node:
 ┌───────────┬───────────┐
 │ data = 10 │ next •─────┼────► (address of the other Node)
 └───────────┴───────────┘
   Node is pointing to its OWN TYPE — self-referential.

 ASCII — a mini chain built from self-referential nodes:
 head
  │
  ▼
 ┌─────┬─────┐    ┌─────┬─────┐    ┌─────┬─────┐
 │ 10  │ •───┼───►│ 20  │ •───┼───►│ 30  │NULL │
 └─────┴─────┘    └─────┴─────┘    └─────┴─────┘

 ✅ When to use:
 - Whenever the collection must grow node-by-node at runtime (list / tree /
   graph): the pointer member IS the "glue" between pieces.
 - Whenever a node must point to neighbours of the same category.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Define the struct with the pointer member:
         struct Node { int data; Node* next; }.
         WHY: the member has the SAME type, so each node can point to the
         following node of its own kind — this is the self-reference.
 Step 2: Allocate a node with new. Set data AND next = NULL.
         WHY: new does not clean memory; next holds garbage. Following
         garbage crashes, so we plant the "chain ends here" sign.
 Step 3: Create the second node and set p1->next = p2.
         WHY: this one write creates the actual link — p1 now "points at"
         another Node. p1 is self-referential IN ACTION.
 Step 4: Create the third node, link p2->next = p3.
         WHY: chain is now 3 self-referential objects firmly joined.
 Step 5: Traverse with a helper: while (temp != NULL) read temp->data and
         advance temp = temp->next.
         WHY: each temp->next is ITSELF a Node*, so the helper hops legally
         from one same-kind object to the next.

 VISUAL WALKTHROUGH:
 Step 2 : head = [10 | NULL]
 Step 3 : head = [10 | •] ──► [20 | NULL]
 Step 4 : head = [10 | •] ──► [20 | •] ──► [30 | NULL]
 Step 5 : temp → 10 → 20 → 30 → NULL → stop. Traversal clean ✅

 DRY RUN (exact trace of the demo code below):
   Node* head = new Node;              // Node#1 on the heap
   head->data = 10; head->next = NULL; // [10|NULL]
   Node* second = new Node;            // Node#2
   second->data = 20; second->next = NULL;
   head->next = second;                // Node#1 now points to Node#2
   Node* third = new Node;             // Node#3
   third->data = 30; third->next = NULL;
   second->next = third;               // Node#2 now points to Node#3
   // traversal
   temp = head   → print 10 → temp = head->next = second
   temp = second → print 20 → temp = second->next = third
   temp = third  → print 30 → temp = third->next = NULL
   temp == NULL  → loop exits
   Output : 10 20 30  ✅ from head to NULL — all self-referential links

 TIME COMPLEXITY CALCULATION:
 - sizeof(Node) is computed once at COMPILE TIME — runtime cost 0 → not a
   running-time function of n at all.
 - Creating one node: 1 allocation + constant field assignments → f(n) = c
   → O(1).
 - Linking two nodes (a->next = b): exactly 1 write → O(1).
 - Following one pointer (temp = temp->next): 1 read + 1 write → O(1).
 - Traversing a chain of n nodes: n hops × constant work → f(n) = c×n, drop
   coefficient → O(n).
   → Time Complexity = O(1) per node creation/link, O(n) to walk the chain.

 SPACE COMPLEXITY CALCULATION:
 - sizeof(Node) = sizeof(int) + sizeof(Node*) = 4 + 8 = 12, padded to 16.
   n nodes → n × 16 bytes, linear in n → TOTAL O(n).
 - One helper pointer for traversal, constant size regardless of n → O(1).
 - Crucially, the self-reference stores only the ADDRESS, so each node adds
   a fixed 16 bytes — no infinite nesting, no duplication.
   → Space Complexity = O(n) total, O(1) auxiliary.

 ═══════════ APPROACH COMPARISON ═══════════
 ┌─────────────────────────┬────────────────────────────────────┬──────────────────────────────┐
 │ Criterion               │ NORMAL STRUCT (no self ptr)        │ SELF-REFERENTIAL STRUCT      │
 ├─────────────────────────┼────────────────────────────────────┼──────────────────────────────┤
 │ what it holds           │ only value members                 │ value + pointer to own type  │
 │ chain building          │ cannot point to "next" of its kind │ CAN — next IS a Node*       │
 │ member Node next (value)│ fine in flat structs               │ ❌ infinite size → error     │
 │ size of member          │ object copy is whole struct        │ pointer fixed at 8 B        │
 │ living next object      │ N/A                                │ stored elsewhere; we hold   │
 │                         │                                    │ its ADDRESS only             │
 │ builds linked list/tree │ no                                 │ YES — the whole foundation  │
 └─────────────────────────┴────────────────────────────────────┴──────────────────────────────┘
*/
#include <iostream>
using namespace std;

// self-referential struct: Node ke andar Node* — khud ko refer kar raha hai
struct Node {
    int data;
    Node* next;
};

int main() {
    cout << "sizeof(Node) = " << sizeof(Node) << " bytes"
         << " = sizeof(int) " << sizeof(int)
         << " + sizeof(Node*) " << sizeof(Node*) << " + padding" << endl;

    // node 1 banao — data + next dono set
    Node* head = new Node;
    head->data = 10;
    head->next = NULL;

    // node 2 banao aur link karo
    Node* second = new Node;
    second->data = 20;
    second->next = NULL;
    head->next = second;            // self-reference: head ab second ko point karta hai

    // node 3 banao aur link karo
    Node* third = new Node;
    third->data = 30;
    third->next = NULL;
    second->next = third;

    // poora chain traverse karo — self-referential links follow hote hue
    cout << "Chain: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;          // har next ek Node* — agle same-type node ka address
    }
    cout << "NULL" << endl;

    // heap cleanup — har new ka delete
    delete third;
    delete second;
    delete head;
    return 0;
}