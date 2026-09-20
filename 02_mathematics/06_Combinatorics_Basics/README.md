# Combinatorics Basics

Counting is the art of answering "how many ways?". A **permutation** (nPr) counts ordered arrangements — who gets which medal in a race; a **combination** (nCr) counts unordered groups — which 3 friends join you for dinner. Both reduce to factorials, but factorials explode fast: 20! ≈ 2.43e18 barely fits in `long long` (max ≈ 9.22e18), while 21! ≈ 5.11e19 silently overflows. The **multiplicative formula** (`nCr = n/1 × (n−1)/2 × …`, r terms) keeps every intermediate value ≤ the final answer, so it never overflows as long as the result fits. **Pascal's triangle** builds the whole table with pure addition (`C[i][j] = C[i−1][j−1] + C[i−1][j]`), and adding `% MOD` keeps values small even for n = 10⁶, which is why competitive programmers always use Pascal plus modulo.

## Real-world analogy
- **Team selection**: choose 3 of 10 players — order irrelevant, so `10C3 = 120`.
- **Lottery**: pick 6 of 49 numbers — order irrelevant; odds = 1 / `49C6 ≈ 1 / 1.4e7`.
- **Medal ceremony**: rank 3 of 10 athletes — order matters, so `10P3 = 720`.
- **Friend groups**: from 5 friends pick 2 → `5C2 = 10` possible dinner pairs.

## Files + purpose
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + demo: factorials (incl. 21! overflow guard), 3 ways to compute nCr, Pascal triangle 0..6, modulo variant, edge cases. Compiles and runs standalone. |
| `task.cpp` | 5 solved tasks (easy → hard): factorial, nPr, multiplicative nCr, Pascal printing, Pascal DP modulo. |

## Cheat sheet (formulas)
- **Factorial**: `n! = n × (n−1) × … × 1`, `0! = 1`
- **Permutation**: `nPr = n! / (n−r)!` (order matters)
- **Combination**: `nCr = n! / (r!(n−r)!)` (order ignored)
- **Multiplicative (overflow-safe)**: `nCr = ∏_{i=1..r} (n−r+i) / i`
- **Pascal**: `C[i][j] = C[i−1][j−1] + C[i−1][j]`, borders = 1
- **Symmetry**: `C(n,r) = C(n, n−r)` → always use `min(r, n−r)` in the loop
- **Modulo**: `(a + b) % M = ((a % M) + (b % M)) % M`

## Complexity table
| Approach | Time | Space | Safe? |
|----------|------|-------|-------|
| Naive (3 factorials) | O(n) | O(1) | ✗ n ≥ 21 overflows |
| Multiplicative loop | O(r) = O(n) worst | O(1) | ✓ no overflow if result fits |
| Pascal full table | O(R²) | O(R²) | ✓ pure addition |
| Pascal rolling rows | O(R²) | O(R) | ✓ |
| Pascal + modulo | O(n²) per query | O(n²) | ✓ unlimited n (mod kept) |

Derivations: naive = 3 single loops of length ≤ n; multiplicative = r iterations; Pascal = total cells `1+2+…+(R+1) = (R+1)(R+2)/2` ≈ R²/2, each cell one addition.

## ⚠️ Common mistakes
1. **Overflow**: computing `n!` first kills you — 20! ≈ 2.43e18 is max that fits, 21! already overflows. Use the multiplicative formula or Pascal.
2. **Forgetting `r > n`**: the answer is 0 (you cannot choose more than you have); a naive loop returns nonsense.
3. **Forgetting `r == 0`**: an empty choice has exactly 1 way, not 0.
4. **Int instead of long long**: `20!` needs full 64 bits; use `long long` everywhere in the multiplicative loop.
5. **Fractional intermediates**: dividing first (`res/i*(n-r+i)`) can be fractional — always multiply THEN divide (`res*(n−r+i)/i` stays integer at every step).
6. **No modulo when n is huge**: 100C50 ≈ 1.0089e29 — needs Pascal + `% MOD`, never raw factorials.

## Interview Q&A
**Q: Why does 21! overflow?**
A: `long long` max is 2⁶³ − 1 ≈ 9.22e18, and 21! ≈ 5.11e19 > that. The multiplicative formula and Pascal avoid holding n! at all.

**Q: When do you prefer multiplicative vs Pascal?**
A: One query → multiplicative, O(r) time, O(1) space. Many queries or values across a range → Pascal DP, O(R²) once then O(1) per value.

**Q: Why is Pascal overflow-safe?**
A: Every cell is an addition of two non-negative integers ≤ the true nCr, so intermediate values never exceed the final answer — unlike `n!` which overshoots it hugely.

**Q: Compute 8C3 manually via multiplicative formula?**
A: `8/1 × 7/2 × 6/3 = 8 × 3.5… no —` careful: `(1×8)/1 = 8`, `(8×7)/2 = 28`, `(28×6)/3 = 56`. The running value is exactly C(6,1)=8, C(7,2)=28, C(8,3)=56 — it is always an integer.

**Q: How do you get nCr mod M for n = 10⁶?**
A: Pascal DP with `% MOD` at every addition — O(n²) might be too slow; for bigger n use modular inverses and factorial tables, but for n ≤ 10³ the int-matrix Pascal shown here is standard.