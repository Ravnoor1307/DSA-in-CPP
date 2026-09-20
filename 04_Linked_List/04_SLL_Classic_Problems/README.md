# 04_SLL_Classic_Problems — Reverse, Middle, Cycle (Floyd), Palindrome

## Summary
- Four classic interview problems solved with the pointer techniques learned so far.
- Reverse: iterative 3-pointer (O(1) space) vs recursive (O(n) stack).
- Middle & cycle: the slow/fast tortoise-hare idea — O(n) time, O(1) space.
- Floyd cycle math also finds the cycle START node and lets us REMOVE the cycle.
- Palindrome: O(n) space stack vs O(1)-space reverse-second-half.

## What You Learn
- Iterative reverse (prev/curr/next chain flip) and its recursive twin.
- Slow/fast pointer for middle, cycle detection, and cycle-start derivation.
- Removing a cycle by walking to the node just before the start.
- Palindrome check with only the second half reversed.

## Files
- `01_theory.cpp` — English doc block + demos: reverse (both), middle, cycle detection/start/remove, palindrome.
- `task.cpp` — 5 tasks EASY→HARD: reverse, middle, cycle length, remove cycle, split into halves.

## Key Complexity Ideas
| Problem | Solution A | Solution B | Winner |
|---|---|---|---|
| Reverse | iterative O(n)/O(1) | recursive O(n)/O(n) | iterative |
| Middle | length + walk ≤2n | slow/fast O(n)/O(1) | slow/fast |
| Cycle detect | visited set O(n)/O(n) | floyd O(n)/O(1) | floyd |
| Cycle start | hash of addresses | floyd math O(n)/O(1) | floyd |
| Palindrome | stack O(n)/O(n) | reverse-half O(n)/O(1) | reverse-half |

## Must-Remember Patterns
```cpp
// reverse (iterative)
Node *prev=null, *curr=head;
while (curr) { Node *nxt=curr->next; curr->next=prev; prev=curr; curr=nxt; }
head = prev;
// middle / cycle
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
// cycle start: after meet, put slow=head, advance both 1 step till they meet
```

## Completion Checklist
- [x] Real-world scenario (train, roundabout, radar palindrome)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (reverse + floyd steps)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory