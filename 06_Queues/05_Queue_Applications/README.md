# 05_Queue_Applications — Stack-from-Queues, Binary Generation, First Non-Repeating

## Summary
- Stack from two queues: push O(1), pop drains all-but-last to buffer then swaps (O(n) per pop).
- Binary 1..n: seed `"1"`, each pop prints and enqueues s+"0", s+"1" → breadth-first enumeration.
- First non-repeating: freq table + queue of unrepeated candidates; pop repeat-fronts; answer = front (O(n) amortized, vs naive O(n²)).
- Reverse a queue via a stack: LIFO flip, another classic one-queue/one-stack composition.

## What You Learn
- Building LIFO from FIFO primitives and where the cost lands (push-heavy vs pop-heavy).
- BFS-level enumeration pattern (binary strings, number systems).
- The queue+count invariant for streaming "first non-repeating" queries.
- Paying attention to `cout` argument evaluation order (bite-size pitfall in demos).

## Files
- `01_theory.cpp` — English doc block + demos: two-queue stack (push 1,2,3, pops 3,2,1), binary 1..5, first-non-repeating "aabc". Output exactly matches.
- `task.cpp` — 5 tasks EASY→HARD: peek-top via queues, 3rd binary, pop-cost summing, non-repeating on "abac", reverse-queue with stack.

## Key Complexity Ideas
| Problem | Time | Space | Note |
|---|---|---|---|
| stack-via-queues push | O(1) | O(n) | queue head is stack bottom |
| stack-via-queues pop | O(n) | O(n) | drain size-1 + swap |
| binary 1..n | O(n) string ops | O(n) strings | BFS; string copy → O(n log n) bits |
| first non-repeating | O(n) amort. | O(n)+O(256) | each char enq/popped once |

## Must-Remember Patterns
```cpp
// pop from stack built on queues
while (live.size() > 1) { buf.push(live.front()); live.pop(); }
swap(live, buf);
// binary stream
q.push("1");
for (i<n) { s=q.front(); q.pop(); print s; q.push(s+"0"); q.push(s+"1"); }
// first non-repeating
freq[c]++; if (freq[c]==1) q.push(c);
while (!q.empty() && freq[q.front()] > 1) q.pop();
ans = q.empty() ? -1 : q.front();
```

## Completion Checklist
- [x] Real-world scenario (plugin stack, ticket printer, chat client)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (drain-swap, BFS levels, counts)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory