# Bit Manipulation

Bit manipulation is programming at the level of individual binary digits: with one CPU
instruction you can test, flip, combine, or shift bits using `&`, `|`, `^`, `<<`, `>>`,
and `~`. The two ideas that unlock everything else are the **mask** (`1 << k` isolates
the k-th bit) and **XOR self-cancellation** (`a ^ a = 0`), which makes duplicate-finding
and no-temp swapping trivial. Anything involving binary strings, powers of two, flags,
permissions, or "every number repeats twice except one" is a bit-manipulation problem.

**Real-world analogy:** think of a row of light switches — each bit is one switch. A mask
is a stencil that only lets you see or flip the switch you care about. Permission bits are
exactly this: Unix `rwx` for owner/group/others packs into 9 bits (e.g. `0755`), where
`chmod` just SETs and CLEARs individual bits with masks. XOR is like toggling a lamp that
returns to off when you press the same switch twice.

## Files

| File           | Purpose                                                       |
| -------------- | ------------------------------------------------------------- |
| `01_theory.cpp`| Concepts + traceable demo code (binary print, operators, masks, Kernighan, XOR magic) |
| `task.cpp`     | Solved exercises easy→hard (even/odd, count bits, power of two, single number, swap, rightmost bit, flip-count) |
| `README.md`    | This cheat sheet: formulas, complexity, mistakes, interview Q&A |

## Compile & test

```bash
g++ 01_theory.cpp -o theory && ./theory
g++ task.cpp -o tasks && ./tasks
```

## Cheat sheet (mask formulas for a 32-bit int)

| Operation          | Formula                           | Example (n=12=1100, k=2) |
| ------------------ | --------------------------------- | ------------------------ |
| Is n even/odd      | `n & 1`                           | `12 & 1 = 0` → even      |
| Get k-th bit       | `(n >> k) & 1`                    | `(12>>2)&1 = 1`          |
| Set k-th bit to 1  | `n | (1 << k)`                    | `12 | 4 = 12`            |
| Clear k-th bit to 0| `n & ~(1 << k)`                   | `12 & ~4 = 8`            |
| Toggle k-th bit    | `n ^ (1 << k)`                    | `12 ^ 4 = 8`             |
| Multiply / divide by 2^k | `n << k` / `n >> k`          | `12<<1 = 24`, `12>>1 = 6`|
| Count set bits      | `n = n & (n-1)` until 0           | 2 iterations for 1100    |
| Power of two        | `n > 0 && (n & (n-1)) == 0`       | `16 → true`, `18 → false`|
| Rightmost set bit   | `n & (-n)`                        | `40 → 8`                 |
| Single non-repeater | `res ^= x` over all elements      | `{1,2,3,2,1} → 3`        |
| Bits differing a→b  | `a ^ b`, then count set bits      | `29^15=18 → 2`           |
| Swap without temp   | `x^=y; y^=x; x^=y;`               | swap 5,9 → 9,5           |

## Complexity table

| Operation                 | Time                             | Space |
| ------------------------- | -------------------------------- | ----- |
| Get/set/clear/toggle bit  | O(1) (one mask + one op)         | O(1)  |
| Build binary string       | O(32) = O(1) (fixed-width loop)  | O(1)  |
| Count set bits (naive)    | O(32) = O(1)                     | O(1)  |
| Count set bits (Kernighan)| O(popcount) ≤ 32 = O(1)        | O(1)  |
| Power of two check        | O(1)                             | O(1)  |
| Single non-repeater (XOR) | O(n) for n elements, each O(1)   | O(1)  |
| Swap (XOR)                | O(1), no extra variable          | O(1)  |

## Common mistakes

- **Forgetting the `n > 0` guard** in power-of-two checks — `0 & -1 == 0` passes otherwise.
- **Confusing division vs `>>`:** right shift of a **negative** number is implementation-defined
  (arithmetic shift on GCC/MSVC); use `unsigned` to be safe.
- **`~(1 << k)` vs `-1 << k`:** only the complement form clears just one bit; `-1 << k` clears
  the top bits too.
- **`1 << 31` overflow** on 32-bit `int` — shifting past the sign bit is UB or a silent wrap;
  guard with `unsigned` / `int64_t`.
- **Thinking XOR swap is "faster"** — it is a neat trick but the temp-variable version is
  clearer and free on modern compilers.
- **Using `n % 2` when `n & 1` suffices** — minor, but `&` avoids the modulo dependency chain.
- **Counting bits on negatives** — reinterpret as `unsigned` or the sign bit pollutes the count.

## Interview Q&A

**Q1. How do you find the single non-repeating number in an array where every other element appears twice?**
XOR every element; pairs cancel (`a ^ a = 0`) leaving the unique value. O(n) time, O(1) space.

**Q2. Why does the Kernighan trick terminate in O(popcount)?**
`n & (n-1)` clears the lowest set bit, so each iteration removes exactly one 1-bit — the loop
runs exactly `popcount(n)` times, never more than 32 for a fixed-width int.

**Q3. Is `x = x ^ y; y = x ^ y; x = x ^ y;` really a valid swap?**
Yes. After step 1, `x = a^b`; step 2 gives `y = a^b^b = a`; step 3 gives `x = a^b^a = b`
(XOR is associative and self-inverse). Caveat: breaks for `x == y` in-place and is harder to read.

**Q4. How to count the number of bits to flip to convert a into b?**
`a ^ b` has a 1 exactly where the bits differ, so the answer is `popcount(a ^ b)`, computable
with Kernighan's loop. NOTE: works only if both are non-negative for the naive/shift form.

**Q5. Why does `n & (n-1) == 0` prove n is a power of two?**
A power of two has a single 1-bit. Subtracting 1 borrows from that bit, flipping it and all
lower bits to 1; AND-ing the two patterns clears the set bit → exactly 0. Any other number
keeps at least one shared 1-bit.

**Q6. How do you get/set/clear/toggle the k-th bit?**
Mask = `1 << k`. Get: `(n >> k) & 1`. Set: `n | mask`. Clear: `n & ~mask`. Toggle: `n ^ mask`.
The complement `~mask` is what makes "clear" touch only one position.

**Q7. What is the edge case everyone forgets with bit counting?**
Zero and negatives. `countSetBits(0) = 0`; for negative `int`, the sign bit is set so a
`while (n)` loop on signed values behaves differently — cast to `unsigned` first.