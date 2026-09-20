# 03_Stack_Class_STL — Custom Stack Class vs std::stack

## Summary
- Custom class: private buffer + `top`, public push/pop/topOf/empty/size; dynamic growth on overflow; underflow returns sentinel.
- std::stack: container adapter over deque (default) or vector/list; all ops O(1); pop() returns void — read top() first.
- Custom class teaches invariants/encapsulation; STL is the production-ready tool.

## What You Learn
- Encapsulation: why `top` stays private and every access goes through the API.
- Dynamic growth (double + copy) and its amortized O(1) push.
- How std::stack adapts an underlying container (back = top).
- Parallel-minima trick for O(1) min(), a classic interview variant.

## Files
- `01_theory.cpp` — English doc block + MyStack (grows 2→4) demo and std::stack usage incl. copy.
- `task.cpp` — 5 tasks EASY→HARD: custom size after pops, backing-store question, STL reverse, stack-to-stack transfer, min-stack.

## Key Complexity Ideas
| Op | Custom (amortized) | std::stack |
|---|---|---|
| push | O(1) (grow rare) | O(1) |
| pop | O(1) | O(1) (void) |
| top | O(1) | O(1) |
| size/empty | O(1) | O(1) |
| min-stack | O(1) extra per op | — (custom only) |

## Must-Remember Patterns
```cpp
// custom grow-on-full
if (top == cap) { cap *= 2; copy into new buffer; }
// STL pop loses value — read first
int v = st.top(); st.pop();
// min-stack: store running min next to each element
mn[top] = (top==0 ? v : min(v, mn[top-1]));
```

## Completion Checklist
- [x] Real-world scenario (wrap raw array vs use STL)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (adapter layering, growth)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory