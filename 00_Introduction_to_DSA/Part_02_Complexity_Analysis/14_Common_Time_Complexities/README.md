# 14 — Common Time Complexities

## 📌 Summary (5 English lines)
- Eight classes dominate algorithm analysis: **O(1), O(log n), O(n), O(n log n), O(n²), O(n³), O(2ⁿ), O(n!)** — from instant to unusable.
- Each class maps to a recognizable **loop shape**: constants → O(1), halving → O(log n), single loop → O(n), outer + halving → O(n log n), nested full loops → O(n²)/O(n³).
- Nested loop factors **multiply**; sequential blocks **add**; then drop constants and lower-order terms.
- `1 + 2 + ... + n = n(n-1)/2` patterns are still **O(n²)**.
- For the same n, doubling the input multiplies ops by ~2 (O(n)), ~4 (O(n²)), or +1 (O(log n)) — ratios reveal the class.

## 🌍 Real-World Analogy
**Post office clerk** handling n parcels each morning — one glance (O(1)), halving the ledger (O(log n)), reading the arrival list (O(n)), split-and-merge shelf sorting (O(n log n)), comparing every parcel with every other (O(n²)), testing every triple (O(n³)), listing all subsets (O(2ⁿ)), trying every truck ordering (O(n!)).

---

## 📂 Files

| File | Kya hai |
|---|---|
| `01_theory.cpp` | 5 loop shapes timed with `std::chrono` (µs), ops-per-call table, growth-ratio check |
| `task.cpp` | 6 tasks: count ops, match algorithms, order growth rates, exact verifier at n=64 |

---

## 📐 Formulas / Cheat Sheet

| Class | Loop shape / cause | Count f(n) |
|---|---|---|
| O(1) | no n-loop | constant |
| O(log n) | `i *= 2` / `i /= 2` | ⌊log₂n⌋ |
| O(n) | single loop 0..n | n |
| O(n log n) | outer n × inner halving, or split+merge | n·log₂n |
| O(n²) | double nested / triangular sum | n² / n(n-1)/2 |
| O(n³) | triple nested | n³ |
| O(2ⁿ) | subset enumeration, recursive 2-way | 2ⁿ |
| O(n!) | permutation enumeration | n! |

```
Growth: 1 < log n < √n < n < n log n < n² < n²log n < n³ < 2ⁿ < n!
```

---

## 📊 Complexity Comparison Table

| Class | Algorithm example | ops @ n=1000 | wall-time @ 10⁸ ops/s |
|---|---|---|---|
| O(1) | array indexing | 1 | ~10 ns |
| O(log n) | binary search | ~10 | ~100 ns |
| O(n) | linear search | 1,000 | ~10 µs |
| O(n log n) | merge sort | ~10,000 | ~100 µs |
| O(n²) | bubble sort | 1,000,000 | ~10 ms |
| O(n³) | naive matrix mult | 10⁹ | ~10 s |
| O(2ⁿ) | subset gen (n=30) | ~10⁹ | ~10 s |
| O(n!) | brute TSP (n=12) | ~4.8·10⁸ | ~5 s |

---

## ⚠️ Common Mistakes

1. **Sequential loops ko multiply karna** — do alag-alag O(n) loops = O(n + n) = **O(n)**, O(n²) nahi.
2. **`i += 2` ko O(log n) samajhna** — i += 2 chalta hai n/2 baar = **O(n)**; halving (`*=2` / `/=` 2) hi O(log n) deta hai.
3. **Triangular loop ko O(n log n) batana** — `j < i` sum = n(n-1)/2 → **O(n²)**.
4. **Constants matter karna little-n pe** — Big-O sirf large n (asymptotic) ke liye hai; measurement me constant overhead dikhta hai.
5. **Log base bhoolna** — log₂n vs log₁₀n constant factor me chhup jaata hai → dono **O(log n)**.

---

## 💬 Interview Q&A

**Q1:** *What is the complexity of the halving loop `i=n; i>0; i/=2`?*
**A:** O(log n) — n → n/2 → n/4 … ≈ log₂n iterations.

**Q2:** *`for i<n: for j<i: work` — complexity?*
**A:** O(n²) — 0+1+…+(n-1) = n(n-1)/2 ≈ n²/2.

**Q3:** *Sorting — best worst-case achievable?*
**A:** Comparison sorts: **O(n log n)** (merge/heap sort). O(n) possible only for special inputs (counting/radix).

**Q4:** *Why is 2ⁿ considered "useless"?*
**A:** n=50 → 2⁵⁰ ≈ 10¹⁵ operations — even at 10⁹ ops/s that is ~12 days; n=100 is beyond the universe's lifetime.

**Q5:** *Binary search in a sorted array of 1 billion items — how many steps?*
**A:** ⌊log₂10⁹⌋ ≈ 30 comparisons — the power of log n.