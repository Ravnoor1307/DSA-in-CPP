# 06_Circular_Linked_List — Last Node Links Back to Head

## Summary
- In a circular SLL the last node's `next` points back to `head` — no nullptr end.
- Traversal MUST use a do-while that stops when it returns to the start; `while (t)` would loop forever.
- With a tail pointer, insert-at-head is O(1); the ring-glue edit is `tail->next = newHead`.
- Model for round-robin scheduling, playlists on repeat, and the Josephus problem.

## What You Learn
- Ring structure and why `last->next == head` defines it.
- do-while traversal + empty-head guard.
- Insert head / delete node while keeping the wrap link intact.
- Josephus (k-th elimination around a ring) as a practical application.

## Files
- `01_theory.cpp` — English doc block + CircularList class demo (append, insertHead, deleteNode, search, one-lap print).
- `task.cpp` — 5 tasks EASY→HARD: count, max, k-jumps, delete-node, Josephus survivor.

## Key Complexity Ideas
| Operation | Time | Aux space | Notes |
|---|---|---|---|
| append (w/ tail) | O(1) | O(1) | loop-close update |
| insert head (w/ tail) | O(1) | O(1) | tail->next re-glue |
| insert head (no tail) | O(n) | O(1) | find tail first |
| delete / search | O(n) | O(1) | wrap to start |
| full lap traversal | O(n) | O(1) | do-while |
| Josephus | O(n·k) | O(n) | n eliminations × k steps |

## Must-Remember Patterns
```cpp
// traversal — CRITICAL: do-while, not while
Node* t = head;
do { /* use t */ t = t->next; } while (t != head);
// insert head with tail pointer
n->next = head;  tail->next = n;  head = n;
// single node ring
head->next == head;
```

## Completion Checklist
- [x] Real-world scenario (playlist repeat / round-robin)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (ring + one-lap traversal)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory