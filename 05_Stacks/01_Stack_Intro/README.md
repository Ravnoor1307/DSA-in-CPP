# 01_Stack_Intro — LIFO Concept, Operations, Overflow/Underflow

## Summary
- Stack = one-ended structure open only at the TOP; LIFO ordering.
- Core ops: push, pop, peek/top, isEmpty, size — all O(1).
- Overflow = push into a full fixed-capacity stack; Underflow = pop/peek on an empty stack. Both need guards.
- Used in undo/redo, recursive calls, bracket matching, backtracking, browser back.

## What You Learn
- Why LIFO matters and when a stack is the right structure.
- The five primitive operations and the top pointer/index idea.
- Overflow/underflow guards on an array-backed stack.
- Reading a stack top-down (pop order) vs bottom-up.

## Files
- `01_theory.cpp` — English doc block + ArrayStack demo: push/pop/peek with size, then a capacity-3 overflow + underflow run matching the DRY RUN.
- `task.cpp` — 5 tasks EASY→HARD: middle of stack, reverse digits, bracket count check, undo simulation, next-greater (monotonic stack).

## Key Complexity Ideas
| Operation | Time | Notes |
|---|---|---|
| push | O(1) | write at top index |
| pop | O(1) | read + decrement |
| peek | O(1) | read top |
| isEmpty/size | O(1) | compare/counter |
| dynamic resize | O(n) amortized O(1) | copy on growth |
| space | O(n) | data + O(1) top pointer |

## Must-Remember Patterns
```cpp
// array stack push/pop with guards
void push(int v) { if (top == cap) return; arr[top++] = v; }
int pop()        { if (top == 0) return -1; return arr[--top]; }
// peek keeps top unchanged
int peek()       { return arr[top - 1]; }
```

## Completion Checklist
- [x] Real-world scenario (dinner plates / undo / Pringles can)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (push/pop states, top/bottom)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory