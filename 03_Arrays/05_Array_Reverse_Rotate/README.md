# REVERSE & ROTATE ARRAY

## 📌 5-Line Summary
1. **Reverse** flips order; **rotate** shifts elements cyclically with wraparound — elements pushed off one end come back at the other.
2. Best reverse = **two-pointer** (swap `a[lo]`/`a[hi]`, move inward): `O(n)` time, `O(1)` space.
3. Naive rotate-by-k = shift-by-one repeated k times → `O(n·k)` — too slow for big k.
4. Best rotate = **reversal algorithm**: reverse blocks then the whole → `O(n)` time, `O(1)` space.
5. Always start with `k %= n`; **right-rotate by k == left-rotate by (n-k)**.

## 🌍 Real-World Analogy
A sushi conveyor belt: plates move one slot forward (rotate left by 1); if the belt spins
k slots, plates wrap around exactly like cyclic array rotation. Reduce k by the belt length —
7 spins around a 5-plate belt look identical to 2 spins. Train yards reorder wagons the same
way when the front car is moved to the back.

## 📁 Files & Purpose
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Concepts, complexity derivation, ASCII walkthroughs, compile-ready demo |
| `task.cpp` | 7 solved tasks EASY→HARD with Hinglish comments |
| `README.md` | Cheat sheet + common mistakes + interview Q&A |

## 🧮 Cheat Sheet
```
reverseTwoPointer:  lo=0, hi=n-1; while(lo<hi){ swap(a[lo],a[hi]); lo++; hi--; }
rotateLeftBy1:      temp=a[0]; for(i=1..n-1) a[i-1]=a[i]; a[n-1]=temp;
rotateLeftRev(k):   rev(0..k-1); rev(k..n-1); rev(0..n-1);
rotateRightRev(k):  rev(0..n-1); rev(0..k-1); rev(k..n-1);
always:             k %= n;   right k == left (n-k)
```

## ⏱️ Complexity Table
| Operation | Time | Space |
|---|---|---|
| Reverse extra array | O(n) — 1 copy pass | O(n) |
| Reverse two-pointer | O(n) — n/2 swaps | O(1) |
| Rotate left by 1 | O(n) — 1 shift pass | O(1) |
| Rotate by k naive | O(n·k) — k shift passes | O(1) |
| Rotate by k extra array | O(n) — 1 mapping pass | O(n) |
| Rotate by k reversal | O(n) — ~n swaps | O(1) |

## ⚠️ Common Mistakes
- **Forgetting `k %= n`** → crashes or wasted work when k > n.
- **Wrong reversal order** → left/right rotation get swapped.
- **Off-by-one in `reverseRange(l..r)`** → use inclusive bounds consistently.
- **Naive rotate for huge k** → O(n·k) gives TLE; always use the reversal algorithm.
- **Copying instead of in-place** when the problem demands O(1) extra space.

## ❓ Interview Q&A
**Q: Rotate an array by k without extra space?**
A: `k %= n`, then reversal algorithm (reverse first k, reverse the rest, reverse whole) — O(n) time, O(1) space.

**Q: Why does the reversal rotation work?**
A: Each half is reversed once, then the whole is reversed; the two half-flips keep block-internal order while the whole-reverse swaps the two block positions, yielding one cyclic shift.

**Q: Detect if array B is a rotation of array A?**
A: Locate A[0] inside B, then compare the two arrays cyclically for n positions; a full match means rotation.

**Q: Left vs right rotate — which is faster?**
A: They are equivalent: right-rotate by k ⇔ left-rotate by n−k. Pick whichever k is smaller for fewer steps.