# 23. Algorithm

- An **algorithm** is a finite, ordered, unambiguous step-by-step procedure that takes input, does work, and produces output.
- Five formal properties: **input, output, finiteness, definiteness, effectiveness**.
- The same problem can have many algorithms — e.g. sum of `1..n` by a **loop** (O(n)) or by the **formula** `n*(n+1)/2` (O(1)).
- Write the procedure as **pseudo-code** first, check the 5 properties, then translate into C++.
- Algorithms are measured by **time complexity** and **space complexity**, usually in Big-O notation.

**Real-world analogy:** A tea recipe with clear steps (boil → add leaves → wait → strain → serve) is an algorithm; a vague "make it nice" step is not.

## Files in this folder
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Definition, 5 properties, pseudo-code, flowchart, dry run, complexity derivation + demo |
| `task.cpp` | 6 graded algorithm tasks (factorial, GCD, max, prime, reverse, palindrome) |
| `README.md` | This summary, cheat sheet, common mistakes, interview Q&A |

## Cheat sheet / syntax
```cpp
// loop method            // formula method
int s = 0;                int formula(int n) { return n*(n+1)/2; }
for (int i=1; i<=n; i++) s += i;

// pseudo-code pattern (write this first!)
// 1. input n      2. sum = 0      3. for i=1..n: sum += i      4. output sum
```

## Complexity comparison (sum of 1..n)
| Method | Time | Space | Steps |
|--------|------|-------|-------|
| Loop | O(n) | O(1) | n iterations |
| Formula | O(1) | O(1) | 3 arithmetic ops |

## ⚠️ Common mistakes
- Writing steps that never terminate (missing exit condition) — violates finiteness.
- Ambiguous step like "use the best value" — violates definiteness.
- Integer overflow: `n*(n+1)/2` overflows for huge `n`; prefer `n/2*(n+1)` trick if `n` is even.
- Forgetting edge cases — `0!`, `gcd(a,0)`, empty array, `n<=1` in prime check.
- Naming the function same as a variable (e.g. `int sum` then using `sum` as function).

## Interview Q&A
- **Q1:** Definition of algorithm? — A finite, well-defined, effective sequence of steps turning input into output.
- **Q2:** 5 properties? — Input, output, finiteness, definiteness, effectiveness.
- **Q3:** Pseudo-code vs code? — Pseudo-code is readable plain steps independent of any language; code is the runnable translation.
- **Q4:** Which is better, loop or formula for `1..n`? — Formula (O(1)) for speed, loop (O(n)) when the pattern isn't closed-form.
- **Q5:** Why measure complexity? — To compare algorithms before running them on large inputs.