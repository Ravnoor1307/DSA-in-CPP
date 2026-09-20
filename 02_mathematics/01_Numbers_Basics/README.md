# Numbers Basics (Digit Operations)

## Summary
1. Digits are peeled off a number with two operations: `n % 10` grabs the last digit, `n / 10` strips it — repeat inside a `while (n > 0)` loop.
2. Count digits two ways: loop (O(log n)) or formula `d = floor(log10(n)) + 1` (O(1)), derived from `10^(d-1) ≤ n < 10^d`.
3. Reverse, sum, palindrome, and Armstrong checks are the *same* digit-consuming loop with a different accumulator each round.
4. Edge cases that always matter: `n = 0` (1 digit), single digits, negative numbers (`abs` them first), and trailing zeros in reverse (100 → 1).
5. Space is O(1) everywhere — only scalar variables, no arrays (except the digit-frequency task's fixed `freq[10]`).

## Real-world analogy
Your parcel's tracking barcode works exactly like this: the machine counts the barcode's digits to reject a smudged label, sums them to verify a check digit, reverses the code to recover a lost order ID, and runs a palindrome/Armstrong check to reject forged coupons.

## Files
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory: concept explainer, ASCII walkthroughs, dry run, derived complexities, approach comparison tables, and a compile-ready demo `main()`. **No tasks.** |
| `task.cpp` | 7 tasks (easy → hard) with hints + starter code in the header block, followed by full solved solutions with Hinglish inline comments. |
| `README.md` | This summary, cheat sheet, complexity tables, common mistakes, and interview Q&A. |

## Cheat sheet (digit extraction formulas)
```
n % 10                → last (units) digit         1234 % 10 = 4
n / 10                → number without last digit  1234 / 10  = 123
count digits          → loop: while(n>0){n/=10;cnt++} OR d = floor(log10(n)) + 1
sum of digits         → sum += n%10; n/=10
reverse number        → rev = rev*10 + n%10; n/=10
palindrome            → reverse(n) == n   (full) OR half-reverse trick
Armstrong (d-digit)   → Σ (digitᵈ) == n    153 = 1³+5³+3³
count zeroes          → n%10==0 && counter++
digit frequency       → freq[n%10]++ on int freq[10] = {0}
```

## Complexity table
| Operation | Time | Derivation | Space |
|-----------|------|-----------|-------|
| Count digits (loop) | O(log₁₀ n) | 1 digit removed per iteration; d = floor(log10 n) + 1 | O(1) |
| Count digits (log10) | O(1) | one `log10` call + `floor` | O(1) |
| Sum of digits | O(log₁₀ n) | same loop; d iterations | O(1) |
| Reverse a number | O(log₁₀ n) | same loop; d iterations | O(1) |
| Palindrome (either) | O(log₁₀ n) | reverse loop + compare; half-reverse runs d/2 rounds | O(1) |
| Armstrong (d-digit) | O(log₁₀ n) | d loops, each with O(1) `pow` | O(1) |
| Digit frequency | O(log₁₀ n) | d loops over fixed-size array | O(1) |

## ⚠️ Common mistakes
- Forgetting the `n == 0` edge case → count 0 instead of 1, sum 0 instead of 0 (fine), reverse 0 instead of 0 (fine), but digits/log10 break.
- Using `log10` on `n <= 0` (undefined) — guard with `if (n == 0) return 1;`.
- Ignoring negatives: `(-123) % 10` is `-3` in C++ — call `abs(n)` before digit loops.
- Forgetting the half-reverse filter `n % 10 == 0` (10, 100, 110 would wrongly pass).
- Full-reverse overflow on huge numbers — `rev = rev*10 + d` can exceed the type; prefer half-reverse there.
- Assuming reversing restores leading zeros (`reverse(100) == 1`, not 001).

## Interview Q&A
**Q1. How do you count digits of 0?**
Both `while` loop and `log10` fail on it by default — return 1 explicitly.

**Q2. Why is the loop complexity O(log n) and not O(n)?**
Each step divides n by 10 (`n = n/10`), so iterations = number of digits d ≈ log₁₀ n, not n itself. n = 10^6 → only 7 iterations.

**Q3. Where does `d = floor(log10(n)) + 1` come from?**
Every d-digit number satisfies `10^(d-1) ≤ n < 10^d`; applying `log10` gives `d-1 ≤ log10(n) < d`, so `d = floor(log10(n)) + 1`.

**Q4. Reverse vs palindrome — why does full reverse overflow?**
`rev` grows with one more digit each round, so `rev*10` can exceed the integer range for big n. The half-reverse trick keeps `rev ≤ n`, eliminating overflow.

**Q5. When is an Armstrong check a bad idea?**
`pow` returns floating-point; for huge digit powers rounding can creep in — use integer multiplication for small fixed powers (e.g., `last*last*last` for 3-digit).