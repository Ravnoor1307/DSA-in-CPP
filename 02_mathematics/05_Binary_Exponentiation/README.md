# Binary Exponentiation (Fast Power)

Compute `a^b` in **O(log b)** instead of **O(b)** using the trick: square the base
every step and multiply into the result only for the set bits of the exponent.
The identity `x^n = (x^(n/2))²` lets each halving cut the work in half, so a
billion-sized exponent needs only ~30 multiplications. Add mod: `(a*b)%m =
((a%m)*(b%m))%m` keeps every intermediate under `m²` (safe with `long long`), which
is exactly how servers compute `key^token mod p` instantly and how you find the
last digit of a huge power (value `% 10`) without ever building the number.

## Real-world analogy

Think "copy-paste doubling" in a document or "doubling bacteria":
- You can't double one cell 1000 times by hand (naive loop) — but if every F2
  doubles whatever is selected, then selecting the whole colony doubles everything
  at once. One command = one squaring step.
- 13 folds of dough: you never fold 13 times. You fold 1→2 (3¹→3²), 3→9, 9→81,
  81→6561 (3^8), then combine the levels that correspond to the set bits of 13
  (1101 → 3¹ × 3⁴ × 3⁸). Four folds, one result.

## Files + purpose

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure concept: naive vs recursive vs iterative vs modular, full derivation, DRY RUN table, trace of 3^13, edge cases. Compiles & runs. |
| `task.cpp` | 5 solved tasks EASY→HARD: naive loop, recursive halving, iterative bits, mod power 5^100%13, last digit of 7^2023. |
| `README.md` | Cheat sheet, complexity table, mistakes, interview Q&A. |

## Cheat sheet

```
Recurrences:
  a^b = (a^(b/2))²                b even       (since a^(2k) = (a^k)^2)
  a^b = a · (a^(b/2))²            b odd        (since a^(2k+1) = a·(a^k)^2)
  (a*b) % m = ((a%m)*(b%m)) % m                (modular product property)

Iterative bits code (answer template):
  ll fastPow(ll base, ll exp, ll mod) {        // mod pass karo ya 1e18+7
      ll res = 1;
      while (exp > 0) {
          if (exp & 1) res = (res * base) % mod;
          base = (base * base) % mod;
          exp >>= 1;
      }
      return res;
  }

13 = 1101₂  →  3^13 = 3^8 · 3^4 · 3^1   (only set bits multiply)
```

## Complexity table

| Approach | Time (derived) | Space | Overflow risk |
|----------|----------------|-------|---------------|
| Naive loop | O(b): b multiplications | O(1) | high for big b |
| Recursive halving | O(log b): `n/2^k = 1 → k = log2(n)` | O(log b) stack | high |
| Iterative bits | O(log b): halve exp each round | O(1) | reduced |
| Modular fast pow | O(log b) | O(1) | safe with long long |

## ⚠️ Common mistakes

- Not applying `% mod` inside the loop → intermediate survives, then overflow.
- Multiplying the result every iteration instead of only when `exp & 1` is set.
- Forgetting to square `base` every iteration → LSB-only, wrong answer.
- Passing negative exponents — fast loop assumes `exp >= 0` (handle sign first).
- Tracking bit positions separately instead of just `exp >>= 1` (the classic).
- Confusing `% m` mapping: last digit of n = `n % 10`, last two digits = `n % 100`.

## Interview Q&A

**Q1: Why is iterative fast power O(log b)?**
After k iterations exponent = b/2^k. It stops when b/2^k = 0 (last positive step),
so k = log2(b). Each iteration is O(1) → O(log b) vs naive O(b) — for b = 10^9
that's 30 vs a billion multiplications.

**Q2: How do you avoid overflow in a^b mod m?**
One step at a time: reduce base and each product mod m, i.e. `(res*base)%m` and
`(base*base)%m`. Because `(a*b)%m = ((a%m)*(b%m))%m`, values never exceed m²
(~10^18 for m=1e9+7), which fits in `long long`.

**Q3: Find 3^13 using binary representation.**
13 = 1101₂ = 8+4+1. So 3^13 = 3^8 · 3^4 · 3^1 = 6561·81·3 = 1594323. Set bits
only — bit 0 (2²=4, clear) contributes nothing.

**Q4: Last digit of 7^2023?**
Last digit = value mod 10. Cycle of powers of 7 mod 10: 7,9,3,1,7,… length 4.
2023 mod 4 = 3 → same as 7^3 = 343 → last digit **3**. Fast power confirms with
11 iterations of `modPow(7, 2023, 10)`.

**Q5: Recursive version space?**
Call depth equals number of halvings = log2(b), one frame each → O(log b) stack,
vs O(1) for the iterative loop — prefer iterative in space-tight or tail recursion
lanes.

**Q6: 0^0 and 0^5 with this template?**
Loop starts res=1; for exp=0 the loop body never runs → returns 1 (mathematically
undefined, standard C++/many libs return 1). For 0^5 the loop multiplies base=0
(eventually) → result 0.