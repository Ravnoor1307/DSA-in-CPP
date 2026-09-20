# 02_Queue_Implementation_Array — Naive, Wasted Space, Circular Queue

## Summary
- Naive array queue: `front` drifts forward, `rear` hits cap → "full" while cells 0..front-1 are empty (wasted space).
- Circular queue (ring buffer): both indices wrap with `(i+1)%cap` → every cell reused.
- Empty check `front==rear`; full check `(rear+1)%cap==front` — one slot reserved so empty stays unambiguous.
- count = `(rear-front+cap)%cap` (handles wrapped negative difference).

## What You Learn
- Why the naive queue's premature overflow happens and how modulo fixes it.
- The +1 slot sacrifice and the exact full-condition formula.
- Wrapping arithmetic for front/rear and count.
- Alternative full-check via a separate `size` counter.

## Files
- `01_theory.cpp` — English doc block + three demos: naive (deq+size), wasted-space (enq 6 rejected after draining), circular (wrap, full, drain) — output matches DRY RUN.
- `task.cpp` — 5 tasks EASY→HARD: count formula, full check, advance front, rotate on ring, build-your-own circular queue.

## Key Complexity Ideas
| Operation | Naive | Circular |
|---|---|---|
| enqueue | O(1) (false-full bug) | O(1) wrap |
| dequeue | O(1) | O(1) wrap |
| empty/full | rear==cap / rear-front | front==rear / (rear+1)%cap |
| count | rear-front | (rear-front+cap)%cap |

## Must-Remember Patterns
```cpp
// circular enqueue
if ((r + 1) % cap == f) return;     // full
a[r] = v;  r = (r + 1) % cap;
// dequeue
if (f == r) return -1;              // empty
v = a[f];  f = (f + 1) % cap;
// count on ring (works after wrap)
(r - f + cap) % cap;
```

## Completion Checklist
- [x] Real-world scenario (token counter / ring reuse)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (drift, wrap, full vs empty)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory