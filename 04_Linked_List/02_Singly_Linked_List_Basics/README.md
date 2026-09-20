# 02_Singly_Linked_List_Basics — Traverse, Insert, Delete, Search

## Summary
- Singly linked list core operations on top of the self-referential Node.
- Front insert/delete are O(1); anything needing a walk (tail/position) is O(n).
- The one golden rule of splicing: update the NEW node's `next` BEFORE overwriting the previous node's `next`.

## What You Learn
- Traversal (iterative) and why it is O(n).
- Insert at head (O(1)), insert at tail (O(n) without a tail pointer), insert at position (splice order!).
- Delete at head (O(1)), delete at position / tail (bypass + free).
- Search with early exit.

## Files
- `01_theory.cpp` — English doc block + demos covering every operation with DRY RUN matching the output.
- `task.cpp` — 5 tasks EASY→HARD: push-front, append-tail, delete-all-matching, sorted-insert, middle-insert-if-even.

## Key Complexity Ideas
| Operation | Time | Aux space | Notes |
|---|---|---|---|
| Traverse | O(n) | O(1) | walk till nullptr |
| Insert head | O(1) | O(1) | 2 pointer writes |
| Insert tail | O(n) | O(1) | walk + attach |
| Insert position | O(n) | O(1) | splice order matters |
| Delete head | O(1) | O(1) | move head + free |
| Delete position | O(n) | O(1) | bypass + free |
| Search | O(n) | O(1) | early exit |

## Must-Remember Patterns
```cpp
// insert head
newNode->next = head;  head = newNode;
// insert after prev — ORDER MATTERS
newNode->next = prev->next;  prev->next = newNode;
// delete after prev
Node* target = prev->next;  prev->next = target->next;  delete target;
// traversal
while (t) { /* use t->data */ t = t->next; }
```

## Completion Checklist
- [x] Real-world scenario (warehouse parcel tags)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (insert/delete steps)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory