# Math for Complexity

Logarithms, exponential growth, and closed-form series formulas are the hidden engine behind every Big-O analysis. Halving a problem (binary search) is O(log n). Summing 1..n with a loop is O(n), but the formula n(n+1)/2 is O(1). And 2^n grows so violently that any algorithm enumerating all subsets dies above n ≈ 25. Mastering these "math moves" converts slow loops into constant-time answers and tells you at a glance whether an approach will scale.

Real-world analogy: halving your laundry pile (log — fast) versus a chain letter that doubles daily (exponential — out of control in 3 weeks). The same numbers that decide your laundry plan decide your algorithm's fate.

## Files and purpose
- `01_theory.cpp` — pure theory + demo code: log2 doubling table vs halving loops, digits via loop vs log10, 2^n explosion with overflow guard, sum/sum-of-squares/geometric formulas vs loops (all verified EQUAL).
- `task.cpp` — 5 tasks EASY → HARD with full solved solutions and step-by-step derivations.
- `README.md` — this cheat sheet.

## Cheat sheet
- Halving count: 2^k = n → k = log2(n). A halving loop runs O(log n) times.
- Digits: digits(n) = floor(log10(n)) + 1 (loop division also O(log n) rounds).
- Sum 1..n: n(n+1)/2 → O(1) vs loop O(n).
- Sum of squares: n(n+1)(2n+1)/6 → O(1) vs loop O(n).
- Geometric: 1 + 2 + 4 + ... + 2^(k-1) = 2^k − 1 (last term 1024=2^10 → 2^11−1=2047).
- Log properties: log(a·b) = log a + log b; log(2^k) = k·log 2; log change of base = constant factor (ignored in Big-O).
- long long safe range: 2^0..2^62; guard exponents above (we demo n ≤ 30).

## Complexity table
| Operation | Loop version | Math version |
|---|---|---|
| count halvings 2×2×...= n | O(log2 n) | O(1) with log2 |
| count digits of n | O(log10 n) | O(1) with log10 |
| sum 1..n | O(n) | O(1) formula |
| sum of squares 1..n | O(n) | O(1) formula |
| 1+2+4+..+2^(k-1) | O(k) additions | O(1) formula |

## ⚠️ Common mistakes
- Forgetting n = 0: one digit, and log10(0) is undefined — always special-case.
- Using loop sums in interviews when a closed form exists — the O(n) may TLE for n = 10^18.
- Forgetting the "+1" in digits formula (log10(1000)=3 but it has 4 digits).
- Assuming 2^n is fine for large n: overflow long long past ~2^63, terabytes of time at n = 50.
- Confusing log-loop count: doubling 1→n prints floor(log2 n)+1 values.

## Interview Q&A
- Q: How many times can you halve 2^30 before reaching 1? A: 30 times → O(log n).
- Q: Is sum 1..n loop acceptable for n=10^9? A: No, use n(n+1)/2 → O(1).
- Q: Why is log(a·b) = log a + log b useful? A: It turns multiplicative build-up into additive log growth — the exact reason products blow up.
- Q: When is 2^n acceptable? A: Practically never past n ≈ 25; exponential search only for tiny inputs.