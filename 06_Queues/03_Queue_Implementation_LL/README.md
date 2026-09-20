# 03_Queue_Implementation_LL — Linked-List Queue

## Summary
- Linked queue: HEAD = front (dequeue), TAIL = rear (enqueue). Both pointers held → both ops O(1).
- enqueue: `tail->next = node; tail = node`. dequeue: `head = head->next; reset tail if now empty`.
- No fixed capacity (heap nodes); costs 1 pointer per element, scattered allocations → worse cache than array.
- Dangling-tail trap: when the dequeue empties the queue, tail must be reset to null.

## What You Learn
- Why the tail pointer is essential (enqueue without it is O(n)).
- The two-pointer invariant (head & tail) and single-node edge case.
- Empty-queue reset of tail on the last dequeue (avoids use-after-free).
- List-vs-array trade-offs: flexibility vs cache/pointer overhead.

## Files
- `01_theory.cpp` — English doc block + LLQueue demo (enq 10,20,30, deq 10, enq 40, drain, underflow) — matches DRY RUN.
- `task.cpp` — 5 tasks EASY→HARD: sized enqueue, interleave, drain order, copy-to-B, rotate-front-to-back.

## Key Complexity Ideas
| Operation | With tail | Without tail |
|---|---|---|
| enqueue | O(1) | O(n) (walk to last) |
| dequeue | O(1) | O(1) |
| front/size/empty | O(1) | O(1) |
| space | O(n) (+1 ptr/node) | same |

## Must-Remember Patterns
```cpp
// enqueue at tail
if (!tail) { head = tail = n; } else { tail->next = n; tail = n; }
// dequeue from head
Node* old = head; head = head->next;
if (!head) tail = nullptr;       // IMPORTANT reset
```

## Completion Checklist
- [x] Real-world scenario (sticky-note task chain)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (front/rear ends, single-node, drain)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory