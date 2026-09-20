# 03_SLL_Class_Implementation — Wrapper Class, Destructor, Length, Nth-from-End

## Summary
- Wrap the raw linked list inside a class so head is private and cleanup is automatic.
- The destructor frees every node (save next → delete → advance), preventing leaks.
- "k-th node from the end" solved two ways: length-based vs the two-pointer (gap) trick.
- Slow/fast pointer idea introduced here also powers middle, cycle detection, palindrome.

## What You Learn
- Constructor (head = nullptr) and why objects start empty.
- Destructor loop and the classic "save next before delete" bug.
- Counting via cached `size` field vs O(n) walk — the tradeoff.
- Nth-from-end via length (≤ 2n work) vs two-pointer gap (single pass).
- Class vs raw-function tradeoff; RAII-style cleanup.

## Files
- `01_theory.cpp` — English doc block + class demo (pushFront, print, size, nthFromEnd) + auto destructor.
- `task.cpp` — 5 tasks EASY→HARD: mini class, middle via slow/fast, Floyd cycle, nth-from-end, leak-free destroy.

## Key Complexity Ideas
| Operation | Time | Aux space | Notes |
|---|---|---|---|
| pushFront | O(1) | O(1) | pointer writes |
| size (uncached) | O(n) | O(1) | walk |
| size (cached) | O(1) | O(1) | mutation bookkeeping |
| nth-from-end (length) | O(n) | O(1) | ≤ 2n steps |
| nth-from-end (2-pointer) | O(n) | O(1) | single pass, k-gap |
| middle (slow/fast) | O(n) | O(1) | fast runs 2x |
| destructor | O(n) | O(1) | n deletes |

## Must-Remember Patterns
```cpp
~LinkedList() {                          // destructor - leak-free cleanup
    while (head) { Node* nxt = head->next; delete head; head = nxt; }
}
// nth from end (gap method)
slow = head; fast = head;
for (i = 0; i < k; i++) fast = fast->next;     // k gap
while (fast) { slow = slow->next; fast = fast->next; } // slow = answer
// middle
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
```

## Completion Checklist
- [x] Real-world scenario (facility-manager wraps light bulbs)
- [x] English theory doc block, Hinglish inline comments
- [x] ASCII visual walkthroughs (gap method + destructor)
- [x] Dry run states (matches program output exactly)
- [x] Complexity derived step-by-step before Big-O
- [x] Compile-ready C++ (`g++ -std=c++17 -Wall`)
- [x] No bare `O(?)`, no `TASK SET` in theory