# 02 — Complexity of an Algorithm (Time + Space vs input size n)

- Complexity measures how the resources (TIME and SPACE) of an algorithm grow as the input size n grows — not exact seconds or bytes.
- **Time complexity** = number of basic operations as a function of n. **Space complexity** = amount of memory used as a function of n.
- The same problem can have many correct algorithms with very different complexities — the one you pick depends on the input constraint.
- Complexity depends on n: doubling n can keep time constant (O(1)), double it (O(n)), or quadruple it (O(n²)).
- To decide between two solutions, compare their growth classes for big n — constants only matter for tiny inputs.

**Real-world analogy:** Adding 1,000,000 package distances by walking the sheet line by line (loop, O(n)) vs calculating N×(N+1)/2 on a calculator (formula, O(1)). Both give the same answer; one scales, the other doesn't.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Definition of time + space complexity, how they depend on n, and a working demo comparing `sumLoop` (O(n)) vs `sumFormula` (O(1)) with operation counters and `chrono` timing at n = 10,000,000. |
| `task.cpp` | 6 problems (EASY → HARD): verify f(n) = 3n+4, loop vs formula at 10⁷, output-cost analysis, count-evens two ways, O(n) vs O(1) memory, and prefix-sums (O(n) time+space builder). Full solutions inside. |
| `README.md` | Summary, cheat-sheet, complexity table, common mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
// TIME — count operations, not seconds
long long sumLoop(int n) {          // f(n) = 3n + 3  → O(n)
    long long s = 0;
    for (int i = 1; i <= n; i++) s += i;
    return s;
}
long long fastSum(long long n) {    // f(n) = 3 (fixed) → O(1)
    return n * (n + 1) / 2;
}
```

**Key formulas (MANDATORY for every derivation):**

```
Loop body 1..n                  → total ops = n × O(1)         = O(n)
Two sequential loops            → n + n = 2n                  = O(n)   (ADD)
Two nested loops                → n × n = n²                  = O(n²)  (MULTIPLY)
Sum 1..n            = n(n+1)/2   → used for triangle loops     = O(n²)
Sum 1..(n-1)        = n(n-1)/2   → inner loop for(j<i)          = O(n²)
Halving loop        n/2^k = 1    → k = log₂n                   = O(log n)
```

**Reduction rules:** keep only the largest term, drop the multiplier:
`3n² + 5n + 100 → 3n² → O(n²)`.

## Complexity comparison (both solutions solve "sum 1..n")

| Solution | Exact ops f(n) | Time class | Space class | n=10⁷ operations |
|----------|----------------|------------|-------------|------------------|
| `sumLoop` | 3n + 3 | O(n) | O(1) | ≈ 30,000,000 |
| `sumFormula` | 3 | O(1) | O(1) | 3 |
| `arrSum` (array sum) | 3n + 4 | O(n) | O(1) | ≈ 30,000,000 |
| `evensLoop` | ≈ 3n | O(n) | O(1) | ≈ 3,000,000 |
| `evensFormula` | 1 | O(1) | O(1) | 1 |
| Prefix-sum build | n | O(n) | O(n) | 10,000,000 |
| Prefix-sum query | 2 | O(1) | — | 2 |

## ⚠️ Common mistakes

- **Complexity = seconds.** It never is — it is the *rate of growth* of operations/memory with n.
- **Keeping low-order terms.** `O(n² + n)` is sloppy; write `O(n²)` — at n = 10⁶ the n² term owns 99.9999% of the work.
- **Forgetting space is a separate axis.** A fast O(n) algorithm can still crash on memory if it allocates an O(n²) table.
- **`int` overflow in the "clever" formula.** `n*(n+1)/2` overflows int near n ≈ 65,535; the loop version never does — use `long long`.
- **Testing only tiny n.** At n = 10 even O(n²) looks fine; the class only reveals itself at n = 10⁶.
- **Ignoring the constants when I/O dominates.** Two O(n) solutions can differ 10× if one prints n lines and the other prints 1.

## Interview Q&A

- **Q: What is complexity of an algorithm?** A: How time and memory grow as a function of input size n — written as a growth class like O(n), O(n²).
- **Q: Time complexity vs space complexity?** A: Time = count of basic operations; Space = memory used (often measured as auxiliary memory beyond the input).
- **Q: Which is better, O(1) or O(n)?** A: For big n, O(1) always — but check constants and overflow; an O(1) formula can still lose to a simple loop on tiny inputs or wrap an int.
- **Q: Two different algorithms give the same answer — how do I choose?** A: Derive each one's time AND space class, then match against the problem constraint (e.g., n ≤ 10⁶ allows O(n log n), not O(n²)).
- **Q: Why does output size count in complexity?** A: Output (like n printed lines) is work too — an O(n) algorithm that prints n values has at least O(n) unavoidable time.

## Constraint → safe complexity

| n up to | Safe complexity |
|---------|-----------------|
| 10–20 | O(2ⁿ), O(n!) |
| 500 | O(n³) |
| 5,000 | O(n²) |
| 10⁶ | O(n log n) |
| 10⁸ | O(n) |

> An O(n) basic operation is roughly 10⁻⁸–10⁻⁹ s, so 10⁸ ops ≈ under a second — count ops before you code.