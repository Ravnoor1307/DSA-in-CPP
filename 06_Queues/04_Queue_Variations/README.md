# 04_Queue_Variations — Deque, Priority Queue, STL Containers

## Summary
- Deque = double-ended queue: push/pop at BOTH ends; circular-array impl with two wrap-around indices; both ends O(1).
- Priority queue hands out largest (max-heap) or smallest (min-heap) first, not oldest.
- Heap impl in array: push = append + bubble up; pop = swap root w/ last + bubble down; both O(log n). top O(1).
- Unsorted array PQ: push O(1), pop O(n). Sorted array PQ: pop O(1), push O(n). Heap balances at O(log n).
- STL: `queue` (FIFO), `deque` (double-ended), `priority_queue` (max-heap default; `greater<int>` for min).

## What You Learn
- Circular-deque index algebra: `front=(front-1+cap)%cap`, `back=(back-1+cap)%cap`.
- Heap-as-array indexing (children 2i+1/2i+2) and root↔leaf bubble paths → O(log n).
- Priority-queue design space: 3 impls, pick trade-offs.
- STL adapter selection per problem.

## Files
- `01_theory.cpp` — English doc block + demos: circular deque (both-end ops with dump), min-heap priority_queue, STL queue + max priority_queue.
- `task.cpp` — 6 tasks EASY→HARD: deque both-ends, max-PQ pop order, min-heap k-smallest, sliding window via deque, sort-by-heap, heap height.

## Key Complexity Ideas
| Structure | push | pop/top | best for |
|---|---|---|---|
| deque (circular array) | O(1) end | O(1) end | both-end access |
| PQ unsorted array | O(1) | O(n) | rare pops |
| PQ sorted array | O(n) | O(1) | rare pushes |
| PQ binary heap | O(log n) | O(log n) | balanced ops |
| STL priority_queue | O(log n) | O(log n) | production |

## Must-Remember Patterns
```cpp
// circular-deque moves
push_front: f = (f - 1 + cap) % cap;  a[f] = v;
pop_back :  b = (b - 1 + cap) % cap;  v = a[b];
// min-heap STL
priority_queue<int, vector<int>, greater<int>> pq;
// heap array math
child = 2*i + 1;  parent = (i - 1) / 2;
```

## Completion Checklist
- [x] Real-world scenario (ER: walk-in front, VIP severity)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (deque ends, heap tree)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O (incl. log proof)
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory