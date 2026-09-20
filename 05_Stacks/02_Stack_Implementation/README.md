# 02_Stack_Implementation — Array vs Linked List vs Two-Stacks-One-Array

## Summary
- Array stack: `top` counts elements; push/pop O(1) contiguous; needs overflow/underflow guards.
- Linked-list stack: HEAD is the top; push_front/pop_front O(1); unbounded; costs 1 pointer per node.
- Two stacks in one array: grow from opposite ends, share the middle; only check `top1 > top2` before pushing.
- Choose array for cache-friendly bounded work; list for unbounded growth or when resizing is costly.

## What You Learn
- `top`-as-count array impl and why `arr[top-1]` is the top.
- Linked stack = head-as-top trick (no traversal needed for push/pop).
- Two-stack share array with the cross-check (off-by-one trap here: guard is `top1 > top2`).
- Memory overhead trade-off of the pointer per list node.

## Files
- `01_theory.cpp` — English doc block + three demos: array stack (size/pop/top), linked stack, and a cap-6 two-stacks run (fills then rejects push1 → FULL).
- `task.cpp` — 5 tasks EASY→HARD: array pop order, linked-list pop count, linked middle, two-stack mirror fill, memory overhead ratio.

## Key Complexity Ideas
| Operation | Array | Linked list |
|---|---|---|
| push | O(1) | O(1) front |
| pop | O(1) | O(1) front |
| peek | O(1) | O(1) |
| empty | O(1) | O(1) |
| resize | O(n) amort. O(1) | never needed |
| space | O(cap) | O(n), 2x byte cost (int+ptr) |

## Must-Remember Patterns
```cpp
// array stack, top as count
arr[top++] = v;            // push  (guard top<cap)
v = arr[--top];            // pop   (guard top>0)
// linked stack, head is top
n->next = head; head = n;  // push
t = head; head = head->next; delete t;  // pop
// two stacks, opposite ends, cross-check
if (top1 > top2) return false;   // no free slot
arr[top1++] = v;                 // stack 1
arr[top2--] = v;                 // stack 2
```

## Completion Checklist
- [x] Real-world scenario (undo history as array vs list)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (3 layouts + traversal)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory