# 46_Bit_Manipulation — &, |, ^, <<, >>, ~

- Six operators work bit-by-bit on an int: AND (`&`) masks/checks, OR (`|`) sets, XOR (`^`) toggles and cancels pairs, NOT (`~`) inverts for clearing (`x & ~(1<<i)`), shifts multiply/divide by `2^k`.
- The universal tool is the mask `1 << i`: with `&` you read bit i, with `|` you set it, with `&~` you clear it, with `^` you flip it — all in O(1).
- XOR superpowers: `a^a==0`, `a^0==a`; a XOR swap needs no temp; XORing an array finds the single unpaired element in O(1) extra space.
- Counting set bits: `__builtin_popcount` is one CPU instruction; the hand loop is O(32); Kernighan's `x &= x-1` runs once per set bit.
- Power-of-two test in one shot: `x > 0 && (x & (x-1)) == 0`.

## Real-world analogy
Linux file permissions are bits (rwx for owner/group/others) — granting write means `|`, revoking means `&~`, asking "can owner execute?" means `&`. A railway seat-map stores 32 seats in one int: book = set bit, cancel = clear bit, and `isPowerOfTwo`/`popcount` style checks run the free-seat counter.

```
 mask = 1<<2 (bit 2, value 4):    12(1100) & 0100 → 0100 ≠ 0 → bit SET
 clear: 12 & ~0100 = 1100 & 1011 = 1000 (8)     toggle: 8 ^ 0100 = 12
 8 = 1000 → 8&7 = 1000&0111 = 0 → power of two ✓
```

## Files in this folder

| File | Purpose |
|---|---|
| `01_theory.cpp` | Pure concept + compile-ready demo: binary print, verify bit 2 of 12, set/clear/toggle functions, popcount three ways (hand loop, Kernighan, builtin), isPowerOfTwo, shift multiply/divide, XOR swap, unique-number via XOR, edge cases 0 and negative |
| `task.cpp` | 6 tasks easy→hard (is power of two, count set bits, toggle kth bit, XOR swap, unique in array, parity) + full solutions |

## Cheat sheet / syntax table

| Action | Code | Complexity |
|---|---|---|
| Check bit i | `(x & (1<<i)) != 0` | O(1) |
| Set bit i | `x | (1<<i)` | O(1) |
| Clear bit i | `x & ~(1<<i)` | O(1) |
| Toggle bit i | `x ^ (1<<i)` | O(1) |
| Multiply by 2^k | `x << k` | O(1) |
| Divide (floor) by 2^k | `x >> k` (unsigned) | O(1) |
| Zero | `x ^ x == 0` | O(1) |
| Identity | `x ^ 0 == x` | O(1) |
| Swap w/o temp | `a^=b; b^=a; a^=b;` | O(1) |
| Power of two? | `x>0 && (x&(x-1))==0` | O(1) |
| Strip lowest set bit | `x = x & (x-1)` | O(1) |
| Count set bits (fastest) | `__builtin_popcount(x)` | O(1) CPU instr |
| Count set bits (loop) | `while(x){cnt+=x&1; x>>=1;}` | O(32) |

## Complexity — with the math

- **Time:** single-bit ops are parallel ALU work on a fixed 32-bit word → **O(1)**. Bit-printing walks 32 bits → O(32) = effectively constant. `__builtin_popcount` = one hardware POPCNT → **O(1)**. Kernighan loops exactly popcount times (≤ 32) → **O(popcount)** ≤ O(32). The unique element scan is one pass → **O(n)** (each XOR O(1)).
- **Space:** every trick runs on registers and a single accumulator → **O(1)** auxiliary; O(n) only for holding the input array itself.

## ⚠️ Common mistakes

- **`0` and `isPowerOfTwo`** — `0 & -1 == 0` gives a wrong `true`; always guard `x > 0` first.
- **Logical vs bitwise** — `&&`, `||`, `!` are NOT bitwise `&`, `|`, `~`; writing `x && 1<<i` checks truthiness, not the bit.
- **Shifting negative / signed overflow** — `x >> k` on a negative int is implementation-defined (arithmetic shift usually); prefer unsigned types for portable bit games.
- **XOR swap on the same variable** — `a ^= a;` self-XOR zeroes the variable; works only across distinct variables.
- **Operator precedence** — `x & 1 == 0` parses as `x & (1==0)`; parenthesize: `(x & 1) == 0`.
- **Forgetting `~mask` when clearing** — `x & mask` keeps bit i; you need `x & ~mask` to kill it.
- **`1 << 31`** on a 32-bit signed int overflows into the sign bit — use `1u << 31` or `1LL << k` for the high bits.

## Interview Q&A

1. **Check if the k-th bit is set?** `x & (1<<k)` — non-zero result means set; this is O(1), one AND with a precomputed mask.
2. **Turn off (clear) a particular bit?** `x = x & ~(1<<k)`; the inverted mask has 0 at k and 1s elsewhere so only that bit is zeroed.
3. **Why does `(a^b)^b` restore a?** XOR is its own inverse: flipping bit-by-bit twice returns the original — `(a^b)^b = a^(b^b) = a^0 = a`. That's the basis of the no-temp swap.
4. **Check power of 2 in O(1)?** `x>0 && (x&(x-1))==0`: subtracting 1 turns `1000…0` into `0111…1`, so AND is 0 only for exactly-one-bit numbers.
5. **Count set bits fast?** `__builtin_popcount` = one POPCNT instruction, O(1). Without it, Kernighan `while(x){x &= x-1; cnt++;}` runs popcount times (≤ 32) instead of 32 always.
6. **Find the single non-repeating number in an array (every other twice)?** XOR all elements — duplicates cancel to 0 and the unique value remains. O(n) time, O(1) space.