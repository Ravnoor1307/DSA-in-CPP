# 11 — Doubly Linked List — Intro

- A doubly linked list (DLL) node carries **prev** (left neighbour) + **data** + **next** (right neighbour); the first node's prev is NULL and last node's next is NULL.
- Because both chains are wired, you can traverse **forward from head** and **backward from tail** — impossible in a singly list.
- The big win: given a node's pointer, **deleting it or inserting before it is O(1)** via `node->prev`, whereas a singly list must rescan from head (O(n)).
- Access is **still O(n)** — the DLL buys direction and easy back-neighbour access, not faster random access.
- Real-world analogy: a **music player with Next AND Previous buttons** — jumping back is instant; also browser Back/Forward, Word Undo/Redo, two-way train.
- Files in this folder:
  | File | Purpose |
  |---|---|
  | `01_theory.cpp` | Theory + demo: build a 3-node DLL, traverse forward & backward, empty-list edge case |
  | `task.cpp` | 6 tasks (EASY→HARD): node helper, build 3-node DLL, backward print, count, insert-at-front, build from array |
  | `README.md` | This cheat sheet |
- Cheat sheet / key snippets:

  ```cpp
  struct Node { Node* prev; int data; Node* next; };
  a->next = b;  b->prev = a;                     // ALWAYS both arrows
  for (Node* t = head; t; t = t->next) ...       // forward
  for (Node* t = tail; t; t = t->prev) ...       // backward
  Node* naya = newNode(val);
  naya->next = head;  if (head) head->prev = naya;  head = naya;  // insert front
  ```

- Complexity comparison table:

  | Operation | Derivation | Singly | Doubly |
  |---|---|---|---|
  | Forward traversal | n iterations | O(n) | O(n) |
  | Backward traversal | n prev hops | **impossible** | **O(n)** |
  | Delete a given node | node->prev gives left neighbour instantly | O(n) rescan | **O(1)** |
  | Insert before node | 4 pointer updates + new | O(n) rescan | **O(1)** |
  | Insert at head | new + 2-3 writes | O(1) | O(1) |
  | Space per node | prev(8)+data(4)+next(8)=20→24 B | 16 B | **24 B** |
  | Total space | n × sizeof(Node) | O(n) | O(n) |
  | Auxiliary space | 1 temp pointer | O(1) | **O(1)** |

- ⚠️ Common mistakes:
  1. **Updating only one chain** — on delete/link you must fix BOTH `prev->next` and `next->prev`, else one direction breaks.
  2. **Wrong pointer order on insert-front** — link the new node to old head BEFORE reassigning `head`, otherwise the old list is lost.
  3. **Forgetting NULL on head/tail operations** — single node, head insert into empty list, tail delete all need `if (head == NULL)` guards.
  4. **Expecting faster access** — access is still O(n); DLL only adds bidirectional movement.
  5. **Using DLL when only forward is needed** — every node wastes 8 bytes on prev; a singly list is 33% cheaper.
- Interview Q&A:
  - **Q: Why is deleting a *given* node O(1) in a DLL but O(n) in a singly list?** A: The DLL stores each node's left neighbour in prev, so `del->prev->next = del->next` is one write; a singly list has no backward pointer and must rescan from head to find who points to del.
  - **Q: What are head and tail conditions in a DLL?** A: `head->prev == NULL` and `tail->next == NULL`; a single node is both, with both pointers NULL.
  - **Q: Does a DLL make `arr[k]`-style access faster?** A: No — reaching node k still needs k hops O(n); the only O(1) gains are for operations near a node you already hold.
  - **Q: Memory cost vs singly?** A: 24 B vs 16 B per node — extra 8 bytes purely for prev (83% of the node is pointer overhead).
  - **Q: Real systems using DLL?** A: `std::list`, browser history, Undo/Redo stacks, and LRU caches (DLL + hash map gives O(1) everything).