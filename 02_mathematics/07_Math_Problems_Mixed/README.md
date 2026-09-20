# Mixed Math Problems — Revision All-in-One

Revision set combining every maths toolkit from the module: digit ops, gcd/lcm, sieve/primes, XOR & bit tricks, modular arithmetic, and fast power. `01_theory.cpp` re-teaches the toolkit by solving 3 representative mixed problems end-to-end; `task.cpp` drills 8 rapid-fire tasks from easy to hard.

**Real-world analogy:** like a Swiss-army knife — one exam, many tools. Digits (`%10 /10`) peel layers of an onion; the sieve marks off a seating chart row by row; XOR is a self-destructing sticky note that erases when two identical notes meet; fast power cooks your exponent in half the time by doubling the spice each step.

## Files

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + toolkit table + 3 solved mixed problems (A digits, B sieve+gcd, C XOR+fastpow) with dry runs and complexity derivations. |
| `task.cpp` | 8 tasks easy→hard, each with hint, starter code, full solution + derived complexity. |
| `README.md` | This overview: analogy, cheat sheet, complexity table, mistakes, interview Q&A. |

## Toolkit cheat sheet

| Problem type | Tool | Time | Space |
|--------------|------|------|-------|
| Count digits, digit sum, reverse | `%10 /10` pop loop | O(log n) | O(1) |
| Palindrome check | reverse then compare | O(d) = O(log n) | O(1) |
| GCD | Euclid `gcd(a, a%b)` | O(log min(a,b)) | O(1) |
| LCM | `(a/gcd(a,b)) * b` | O(log min(a,b)) | O(1) |
| Primes ≤ n | Sieve of Eratosthenes | O(n log log n) | O(n) |
| Single non-repeating element | XOR `x ^= a[i]` | O(n) | O(1) |
| Power of 2 test | `n>0 && (n&(n-1))==0` | O(1) | O(1) |
| x^y mod m (huge y) | Binary fast power | O(log y) | O(1) |
| nCr (small r) | multiplicative loop | O(min(r, n-r)) | O(1) |
| Digital root | `n % 9` (or 9 when r==0) | O(1) formula | O(1) |

## Complexity table (the 3 theory problems)

| Problem | Best technique | Time | Space |
|---------|----------------|------|-------|
| A — digits/sum/reverse/palindrome of n | digit-pop helper | O(log₁₀ n) | O(1) |
| B — primes ≤ n, count, gcd of array | sieve + Euclid | O(n log log n) + O(log min) | O(n) |
| C — single non-repeating + x^y mod m | XOR + fast pow | O(n + log y) | O(1) |

## ⚠️ Common mistakes

- **Negative input unguarded** — digit loops on `-123` pop wrong values; take `|n|` first.
- **`n = 0` digit count** — `while (n > 0)` never runs; handle `0` as exactly 1 digit.
- **Overflow in LCM / nCr** — compute `(a / gcd) * b` and multiply-then-divide in `long long`, not `int`.
- **Sieve marking from `2p` instead of `p*p`** — wrong answers are still correct but you waste work; start at `p*p`.
- **Forgetting 0 and 1 are not prime** — sieve must pre-mark `comp[0] = comp[1] = true`.
- **`(n & (n-1)) == 0` without `n > 0`** — 0 falsely tests as a power of 2.
- **Digital root `n % 9`** — returns 0 for multiples of 9; map 0 → 9 unless n itself is 0.
- **Reciting complexity without derivation** — always derive from the loop count (digits popped, sieve marking Σ n/p, bits of exponent).

## Interview Q&A

**Q1: Fastest way to count digits of n?**
`floor(log10(n)) + 1` in O(1) (log call), else the `%10 /10` loop in O(log n). Watch `n = 0` → 1 digit.

**Q2: Why does XOR find the single non-repeating number?**
XOR is commutative, associative, and self-inverse: `a ^ a = 0`, `a ^ 0 = a`. Every duplicate pair collapses to 0 and only the unpaired value survives — O(n) time, O(1) extra memory, no hashmap.

**Q3: Why does the sieve stop at √n?**
Every composite m ≤ n has a prime factor p ≤ √n; if m were factor-free below √n it would be prime. Beyond √n there is nothing new to mark.

**Q4: Compute 7^2023 mod 10 without a calculator.**
Digital root of the power pattern: 7¹=7, 7²→9, 7³→3, 7⁴→1, cycle length 4; `2023 % 4 = 3`, answer 3. Or run binary fast power in O(log 2023) ≈ 11 multiplications.

**Q5: lcm overflow-safe formula?**
`lcm(a,b) = (a / gcd(a,b)) * b` — divide first so the product never exceeds the true LCM magnitude, then use `long long`.

**Q6: nCr(10,4) by hand?**
`(10·9·8·7)/(4·3·2·1) = 5040/24 = 210`. Iterator version `res = res*(n-r+i)/i` stays integer-exact at each step.

**Q7: When is the XOR trick valid?**
Only when EVERY other number appears an even number of times. Change one count to odd and XOR silently gives the wrong survivor.