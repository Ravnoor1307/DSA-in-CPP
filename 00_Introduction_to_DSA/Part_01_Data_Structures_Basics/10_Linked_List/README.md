# 10 — Linked List — Intro

- A linked list is a chain of **nodes**, each holding **data** and a **next pointer** to the following node; the list is reached only through its **head**, and the last node's next is **NULL**.
- Because nodes live in scattered heap memory, the list **grows and shrinks at runtime**, needs no contiguous block, and wastes no reserved slots.
- Inserting/deleting at a **known position is O(1)** (a couple of pointer swaps), but there is **no random access** — reaching node k costs k hops, O(n).
- It is the direct answer to almost every array drawback: fixed size, costly middle insert/delete, memory wastage, and contiguous-memory requirement.
- Real-world analogy: a **goods train** — the engine (head) starts the chain, and each coach's coupler (next) leads to the next coach; add a coach by changing two couplers, nobody moves.
- Files in this folder:
  | File | Purpose |
  |---|---|
  | `01_theory.cpp` | Theory + demo: build a 3-node list, link them, traverse and print, empty-list edge case |
  | `task.cpp` | 6 tasks (EASY→HARD): single node, print, count, search, insert-at-front, build-from-array |
  | `README.md` | This cheat sheet |
- Cheat sheet / key snippets:

  ```cpp
  struct Node { int data; Node* next; };          // self-referential node
  Node* head = new Node;  head->data = 10;  head->next = NULL;
  head->next = second;                            // link: first → second
  for (Node* t = head; t != NULL; t = t->next)    // traversal loop
      cout << t->data << " ";
  Node* naya = new Node;  naya->next = head;  head = naya;  // insert at front
  ```

- Complexity comparison table:

  | Operation | Derivation | Array | Linked List |
  |---|---|---|---|
  | Access node k | k pointer hops = f(k) | O(1) | **O(n)** |
  | Insert at known spot | 2 pointer assignments | O(n) shifts | **O(1)** |
  | Delete at known spot | 1 pointer reassignment | O(n) shifts | **O(1)** |
  | Traversal | n iterations × 1 hop | O(n) | **O(n)** |
  | Memory per element | int=4 vs ptr+int≈16 | **4 B** | 16 B |
  | Space total | capacity×4 vs n×16 | O(capacity) | O(n) |
  | Auxiliary space | 1 temp pointer, constant | O(1) | **O(1)** |

- ⚠️ Common mistakes:
  1. **Never initializing `next`** — `new Node` gives garbage in next; following it crashes. Always set `next = NULL` (or `nullptr`).
  2. **Insert-at-front order reversed** — `head = naya` before `naya->next = head` loses the whole list (or makes a self-loop).
  3. **Losing head** — once head is gone, the entire list is unreachable (memory leak).
  4. **Forgetting NULL checks** — dereferencing `cur->next` when it is NULL crashes; always check before walking.
  5. **Thinking the list is "array without problems"** — access is O(n), memory is ~4× and non-cache-friendly.
- Interview Q&A:
  - **Q: Why is insert-at-front O(1) in a linked list?** A: Two assignments — `naya->next = head` and `head = naya` — regardless of length; no shifting, no capacity check.
  - **Q: Why does the linked list solve the array's insertion problem?** A: The array must shift (n−p) elements to keep contiguity; the list just repoints two pointers because nodes are already separate objects.
  - **Q: What does `temp = temp->next` actually do?** A: It reads the current node's next pointer (the following node's address) and moves the helper to it; when next is NULL the walk is over.
  - **Q: How much memory does one node cost?** A: `sizeof(int) + sizeof(Node*) = 4 + 8 = 12`, padded to 16 bytes — 75% of it is pointer overhead.
  - **Q: When should you still prefer an array?** A: When random access, cache locality, and memory compactness matter more than mid-list insert/delete.