# 01_Linked_List_Intro — Why Linked List, Node Structure, Creation, Memory Layout

## Summary
- A linked list is a chain of self-referential nodes: each node holds `data` plus a `next` pointer to the next node.
- Nodes live on the **heap** (scattered addresses) and are reached only by walking from `head`.
- Arrays give O(1) random access but fixed size; linked lists give dynamic growth and O(1) front insert/delete but O(n) access.

## What You Learn
- Why linked lists exist (vs arrays) and when to prefer each.
- The self-referential `struct Node { int data; Node* next; };`.
- Creating nodes with `new`, linking them, and the meaning of `head` / `nullptr` as end marker.
- Heap vs stack layout: heap nodes are NOT contiguous, array elements ARE.

## Files
- `01_theory.cpp` — English doc block + runnable demos (create 3-node chain, sum, print, layout comparison).
- `task.cpp` — 5 tasks EASY→HARD (build, count, max, array-vs-list match, safe destroy).

## Key Complexity Ideas
| Operation | Time | Space |
|---|---|---|
| Node creation (1 node) | O(1) | O(1) |
| Full traversal / sum / print | O(n) | O(1) aux |
| Array access `arr[i]` | O(1) | — |
| List access i-th node | O(n) | O(1) aux |

## Must-Remember Patterns
```cpp
struct Node { int data; Node* next; };        // self-referential
Node* head = new Node(10);                     // first node
head->next = new Node(20);                     // link next
// traversal
while (head) { /* use head->data */ head = head->next; }
// safe destroy
while (head) { Node* nxt = head->next; delete head; head = nxt; }
```

## Completion Checklist
- [x] Real-world scenario (treasure-hunt clue cards)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (chain + memory layout)
- [x] Dry run states
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory