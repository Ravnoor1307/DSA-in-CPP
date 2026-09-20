# 01_Queue_Intro — FIFO Concept, Operations, Stack-vs-Queue

## Summary
- Queue = open at TWO ends: FRONT (dequeue) + REAR (enqueue); asymmetric access → FIFO.
- Core ops: enqueue, dequeue, front/peek, isEmpty, size — all O(1).
- Naive array queue drifts front forward and wastes the front cells (fixed by circular buffer in topic 02).
- Stack: push/pop same end → LIFO. Queue: different ends → FIFO.

## What You Learn
- Why different insertion/removal ends literally define FIFO.
- front/rear index bookkeeping and the empty reset (front==rear → empty).
- Overflow (rear==cap) and underflow (empty dequeue) guards.
- Where queues appear: printer jobs, OS scheduling, call centres, requests.

## Files
- `01_theory.cpp` — English doc block + NaiveQueue demo: enqueue 10,20,30, then dequeues down to underflow, matching the DRY RUN.
- `task.cpp` — 5 tasks EASY→HARD: front element, FIFO copy, symmetric enq/deq, double peek, rotate-front-to-back.

## Key Complexity Ideas
| Operation | Time | Notes |
|---|---|---|
| enqueue | O(1) | write at rear++ |
| dequeue | O(1) | read at front++ |
| front/peek | O(1) | index read |
| isEmpty/size | O(1) | compare/count |
| space | O(n) | array cap or n nodes |

## Must-Remember Patterns
```cpp
// array queue with front ≤ rear
arr[rear++] = v;       // enqueue   (guard rear<cap)
v = arr[front++];      // dequeue   (guard front!=rear)
// empty reset both indices
if (front == rear) { front = rear = 0; }
```

## Completion Checklist
- [x] Real-world scenario (railway counter, printer jobs)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (front/rear ends, step states)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory