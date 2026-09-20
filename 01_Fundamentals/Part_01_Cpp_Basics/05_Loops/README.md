# Loops (for, while, do-while, break/continue)

Loops repeat a block of code until a condition is met. Three varieties exist: `for` (known count), `while` (unknown count, pre-test), and `do-while` (at-least-once, post-test). `break` exits a loop early; `continue` skips to the next iteration. Every repetitive task — printing tables, traversing lists, counting occurrences — is built on loops.

**Real-world analogy:** An elevator moving from floor 2 to floor 7. It repeats "go up one floor" (loop body) and checks "is this floor 7?" (condition) after each move. If the alarm sounds, it immediately stops (break). If the elevator is maintenance-only on even floors, it checks the floor number and skips to the next odd floor (continue).

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + compile-ready demo: while reverse, for sum 1..n, do-while menu, break/continue, infinite loop edge case |
| `task.cpp` | 5 practice tasks (digit sum, reverse, multiplication table, prime check, Fibonacci) with hints and solutions |
| `README.md` | This file — summary, cheat sheet, complexity, common mistakes, interview Q&A |

## Cheat Sheet / Syntax Table

```cpp
// for — known iteration count
for (int i = 0; i < n; i++) {
    // body runs exactly n times
}

// while — condition-driven
while (condition) {
    // body may run 0 or more times
}

// do-while — runs at least once
do {
    // always executes once
} while (condition);

// break — exit innermost loop immediately
for (int i = 0; i < 100; i++) {
    if (i == 5) break;      // stops when i==5; body ran 5 times
}

// continue — skip rest of this iteration, go to next
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) continue;  // even numbers skipped
    cout << i << " ";            // prints: 1 3 5 7 9
}

// infinite loop — always guard with break or exit condition
while (true) {
    // ... must have a break somewhere or program hangs
}
```

## Comparison Table

| Feature | `for` | `while` | `do-while` |
|---------|-------|---------|------------|
| Runs if condition false initially | No | No | **Yes (at least once)** |
| Init + update syntax inside loop header | Yes | No (separate lines) | No |
| Best for | Known count, arrays | Event-driven, unknown count | Menus, retry prompts |
| Equivalent to | `i=0; while(i<n){...i++;}` | Same structure | Same + body executes once first |

## Complexity

| Loop Type | Time | Space |
|-----------|------|-------|
| Sum 1..n (`for`) | O(n) — body executes n times, each O(1) | O(1) |
| Reverse digits (`while`) | O(d) where d = number of digits | O(1) |
| Fibonacci first n terms | O(n) | O(1) |
| Prime check (sqrt optimization) | O(√n) — loop runs up to √n | O(1) |
| Menu (`do-while`, K selections) | O(K) | O(1) |

**Derivation for sum 1..n:** the for loop body executes exactly `n` times (i goes from 1 to n). Each iteration does one addition and one increment → O(1) per iteration. Total: `n × O(1) = O(n)`.

## Common Mistakes

1. **Off-by-one errors:** `for(i=1; i<=n)` runs n times; `for(i=0; i<n)` also runs n times — but `for(i=0; i<=n)` runs n+1 times. Know your bounds.
2. **Infinite loops:** forgetting to update the counter or never reaching the exit condition (e.g. `while(n != 0)` but n never changes).
3. **Integer overflow in Fibonacci:** Fibonacci(>93) overflows `long long`. Always mention this edge case.
4. **`break` vs `continue` confusion:** `break` exits the loop entirely; `continue` only skips to the next iteration.
5. **Using `do-while` when body shouldn't run once:** e.g. empty list traversal — `while` is correct.
6. **Missing `cin >>` inside the loop body** causes infinite loops (input buffer never updates).
7. **Floating-point loop counters accumulate drift** — use integer counters for exact control.

## Interview Q&A

**Q1: When would you choose `while` over `for`?**
A: When the number of iterations is not known in advance and depends on a runtime condition (e.g., "keep reading until user types 'quit'"). Use `for` when the count is fixed at the start (`for (int i = 0; i < n; i++)`).

**Q2: What is a do-while loop's unique guarantee?**
A: The body executes **at least once** before the condition is checked. This makes it ideal for menu systems and "prompt until valid input" patterns where you must display the menu / ask the question at least once.

**Q3: How do you prevent infinite loops in interviews?**
A: Always ensure (1) the loop variable is initialized correctly, (2) it is updated in every iteration, and (3) the termination condition is eventually met. When reading input in a loop, always have a clear exit value and ensure it's reachable.