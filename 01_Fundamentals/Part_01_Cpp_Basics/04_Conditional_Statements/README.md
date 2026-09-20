# Conditional Statements (if, else if, else, switch)

Conditional statements let a program take different paths based on conditions. `if/else if/else` handles range-based checks; `switch` handles exact-value jumps efficiently. Every real program — from grade calculators to traffic lights — depends on these decisions.

**Real-world analogy:** A traffic light controller. "If emergency vehicle approaching → open lane; else if rush hour → extend green time; else → normal cycle." The program checks conditions top-down and acts on the FIRST true one, exactly like an `if/else if` chain.

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + compile-ready demo: grade calculator with validation, nested if, switch menu, fall-through edge case |
| `task.cpp` | 5 practice tasks (largest of 3, leap year, electricity bill, switch calculator, triangle validator) with hints and solutions |
| `README.md` | This file — summary, cheat sheet, complexity, common mistakes, interview Q&A |

## Cheat Sheet / Syntax Table

```cpp
// Simple if
if (marks >= 90) {
    cout << "A+";        // runs when condition true
}

// Two-way
if (age >= 18) {
    cout << "Adult";
} else {
    cout << "Minor";
}

// Multi-way (check top-to-bottom, first match wins)
if (marks >= 90) grade = 'A';
else if (marks >= 80) grade = 'B';
else if (marks >= 70) grade = 'C';
else grade = 'F';

// Nested if (layer validation)
if (n > 0) {
    if (n % 2 == 0) cout << "positive even";
}

// switch (exact value match)
switch (choice) {
    case 1: cout << "Chai";  break;
    case 2: cout << "Coffee"; break;
    default: cout << "Invalid"; break;
}
// Without break → fall-through into next case!

// Ternary (mini if-else returning a value)
string status = (age >= 18) ? "Adult" : "Minor";
```

## Complexity

| Operation | Time | Space |
|-----------|------|-------|
| if / else if chain (K branches) | O(K) worst case, K constant | O(1) |
| switch (jump-table optimized) | O(1) typically | O(1) |
| Nested if (fixed depth) | O(1) | O(1) |

**Derivation:** an `if/else if` chain evaluates at most one condition per branch; with K constant branches this is O(K) = O(1). A `switch` on integer constants is often compiled to an O(1) jump table.

## Common Mistakes

1. **`=` instead of `==` inside conditions:** silently always-true; use `==`.
2. **Wrong condition order:** putting `marks >= 90` AFTER `marks >= 80` makes 'A' unreachable. Check most-specific/highest first.
3. **Skipping input validation:** `marks = -5` yields grade 'F' (wrong meaning). Validate before computing.
4. **Forgetting `break` in switch:** causes fall-through — multiple cases run. Rare cases need deliberate empty-fall-through.
5. **Comparing ranges in switch:** `switch` only does equality on constants; ranges like `>= 70` need if/else.
6. **Floating-point == comparisons:** `if (price == 0.1 * 10)` may be false. Use epsilon `abs(x-y) < 1e-9`.
7. **Deeply nested conditions kill readability:** consider switch or early-return statements.

## Interview Q&A

**Q1: When would you choose `switch` over `if/else if`?**
A: When matching an integral/enum/char expression against a fixed set of constants (menus, days, error codes). `switch` is more readable, and compilers can optimize it to O(1) jump tables. Ranges and complex logical conditions require `if/else if`.

**Q2: What happens if you omit `break` in a switch case?**
A: Fall-through: control continues executing the next case's statements until a `break` (or switch end). It can be used deliberately to share code between cases, but usually causes subtle bugs.

**Q3: Why is validation important before grading logic?**
A: Without checking `marks < 0 || marks > 100`, impossible inputs silently reach misleading outputs (e.g., `-5` graded 'F'). Validation prevents nonsense data from corrupting business logic — the core of robust software.