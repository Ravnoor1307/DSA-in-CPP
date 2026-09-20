# 12 — Self-Referential Structure

- A **self-referential structure** is a struct whose member is a **pointer to its own type** — `struct Node { int data; Node* next; }` — where `next` stores the *address* of another, identical Node.
- The pointer is **always a fixed 8 bytes** (64-bit), no matter what it points to, which is exactly why `sizeof(Node)` stays finite and chains can grow indefinitely.
- A value member of its own type (`Node next;`) is a **compile error** — computing the size would recurse forever (size = 4 + size of itself...).
- It is the **foundation of every linked data structure**: singly list (1 pointer), doubly list (2 pointers), binary tree (2 child pointers), graph/trie (many pointers).
- Real-world analogy: a **clue card that holds the hiding spot of the next clue card** — each card references another card of the same kind, forming an endless chain.
- Files in this folder:
  | File | Purpose |
  |---|---|
  | `01_theory.cpp` | Theory + demo: prove fixed sizeof, build a 3-node chain with self-referential links, traverse to NULL |
  | `task.cpp` | 6 tasks (EASY→HARD): one node, 3-node chain, build-from-array, count, middle node, Nth-from-end |
  | `README.md` | This cheat sheet |
- Cheat sheet / key snippets:

  ```cpp
  struct Node { int data; Node* next; };   // self-reference via pointer
  Node* p = new Node;  p->data = 42;  p->next = NULL;   // always init next!
  head->next = second;                    // one write = one link
  for (Node* t = head; t; t = t->next)    // walk the chain
      cout << t->data << " ";
  // middle: slow = slow->next; fast = fast->next->next;
  ```

- Complexity comparison table:

  | Operation | Derivation | Result |
  |---|---|---|
  | Create one node | 1 allocation + constant writes | O(1) |
  | Link a->next = b | 1 pointer write | O(1) |
  | Follow temp->next | 1 read + 1 write | O(1) |
  | Walk n nodes | n hops × constant work = c×n | **O(n)** |
  | Middle node | slow travels n/2, fast n steps | **O(n)** |
  | Nth from end | k lead hops + (n−k) paired hops = n | **O(n)** |
  | Total memory | n × sizeof(Node) = n × 16 | **O(n)** |
  | Auxiliary space | 1–2 helper pointers, constant | **O(1)** |

  Sizes: `Node` 16 B · `DNode` 24 B · `TreeNode` 24 B — pointer is always 8 B.

- ⚠️ Common mistakes:
  1. **Writing `Node next;` (by value)** — infinite size recursion, compile error. Always `Node* next;`.
  2. **Not initialising `next`** — `new` leaves garbage; following it crashes. Set `next = NULL` at creation.
  3. **Dereferencing without NULL check** — `cur->next->data` when `cur->next` is NULL → crash; always test `cur->next != NULL`.
  4. **Forgetting `delete`** — every `new` must pair with a `delete`, or memory leaks.
  5. **Member order affecting padding** — 4+8=12 fits in 16, but rearranging members can waste extra bytes.
- Interview Q&A:
  - **Q: Why is `Node next;` a compile error but `Node* next;` is fine?** A: A value member forces sizeof(Node) to contain itself (4 + sizeof(Node) + ...), infinite recursion; a pointer is always a fixed 8-byte address, so the size stays finite.
  - **Q: What makes a structure "self-referential"?** A: It has a member that is a pointer to the same struct type — `Node* next;` inside `struct Node`.
  - **Q: How deep can self-referential chains go?** A: As deep as memory allows, because each link stores only an address; there is no copying or nesting of whole objects.
  - **Q: What real structures are built on this idea?** A: Redirect chains, linked list insertions, tree ancestors — everything where one record must point to another record of the same kind.
  - **Q: Why is linking two nodes O(1)?** A: Because it is a single pointer write (`a->next = b`) regardless of chain length, exactly the property that gives linked-list inserts their O(1) edge over arrays.