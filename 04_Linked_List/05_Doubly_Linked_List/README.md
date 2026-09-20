# 05_Doubly_Linked_List — prev Pointer, Insert/Delete, Two-Way Traversal

## Summary
- Every node carries BOTH `prev` and `next` pointers → instant backward movement.
- Insert/delete on a KNOWN node is O(1): 4 pointer updates + guards, no search.
- With a tail pointer, delete-tail and append become O(1) too.
- Same time as SLL for everything, at the cost of 1 extra pointer (~8 bytes) per node.

## What You Learn
- DLLNode struct with prev+next, head AND tail pointers.
- pushBack (O(1) with tail), insertAfter (guarded 4-pointer splice).
- deleteNode with head/tail guard cases.
- Forward and backward traversal, and reversing a DLL by swapping prev/next.

## Files
- `01_theory.cpp` — English doc block + DLL class demo (pushBack, insertAfter, deleteNode, both walks).
- `task.cpp` — 5 tasks EASY→HARD: pushFront, append, deleteTail O(1), insertAt, reverse-by-swap.

## Key Complexity Ideas
| Operation | Time | Aux space | Notes |
|---|---|---|---|
| pushFront / pushBack (w/ tail) | O(1) | O(1) | pointer writes |
| insertAfter(known node) | O(1) | O(1) | 4 updates + guards |
| deleteNode(known node) | O(1) | O(1) | 4 updates + free |
| delete value / nth (must find) | O(n) | O(1) | walk then O(1) |
| traverse fwd / back | O(n) | O(1) | prev/tail mirror |
| reverse DLL (swap ptrs) | O(n) | O(1) | swap prev/next each |

## Must-Remember Patterns
```cpp
// insert after p — set new node's pointers first, then neighbors
n->prev = p;  n->next = p->next;
if (p->next) p->next->prev = n;
p->next = n;
// delete p — skip from both sides
if (p->prev) p->prev->next = p->next;
if (p->next) p->next->prev = p->prev;
delete p;
```

## Completion Checklist
- [x] Real-world scenario (two-way road / music-player history)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (node + splice steps)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory