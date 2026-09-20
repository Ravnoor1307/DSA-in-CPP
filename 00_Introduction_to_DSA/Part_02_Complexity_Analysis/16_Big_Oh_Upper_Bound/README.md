# 16 — Big O (Upper Bound)

## 📌 Summary (5 English lines)
- **Big-O** is the **upper-bound** notation: `f(n) = O(g(n))` ⇔ ∃ c, n₀ > 0 so `f(n) ≤ c·g(n)` for **all** n ≥ n₀.
- It is the *"delivery within 2 months"* promise — a pessimistic but honest ceiling on growth.
- You **drop constants** (5n³ and 1000n³ are both O(n³)) and **drop lower-order terms** (2n, 7 vanish against n³).
- A polynomial `aₖnᵏ + … + a₀` is simply `O(nᵏ)` — the highest power wins.
- Any one valid *(c, n₀)* pair proves the claim; small n may fail, the guarantee starts at n₀.

## 🌍 Real-World Analogy
Shopkeeper promises "parcels delivered within 2 months, whatever the backlog after order #10". Real cost f(n) may jolt with taxes, traffic, and setup fees, but a scaled simple budget c·g(n) always covers it from order n₀ onward. Big-O is that same promise for algorithms — 5n³+2n+7 is "an O(n³) job", costs and crumbs dropped.

```
cost ▲
     |                        f(n) = 5n³+2n+7 (real cost)
     |                      ╱
     |               ─────▶╱   c·g(n) = 6n³ (budget cap)
     |             ╱─────
     │   n₀ = 3 ←────────────────────────────────► n
  guarantee ON from here; f stays under the cap forever
```

---

## 📂 Files

| File | Kya hai |
|---|---|
| `01_theory.cpp` | proof-style table `5n³+2n+7` vs `6n³` for n=1..12, shows inequality holds ∀ n≥3, tight vs loose c |
| `task.cpp` | 6 tasks: reduce 7n²+9n+3, 2n²+n, log₂n+5, 3n+7logn, 4n³+2n²+100; decide 3n²=O(2ⁿ) vs 2ⁿ=O(n²) |

---

## 📐 Definitions & Rules

```
f(n) = O(g(n))  ⇔  ∃ c, n₀ > 0 :  0 ≤ f(n) ≤ c·g(n)   ∀ n ≥ n₀
```

| Rule | Example |
|---|---|
| Polynomial → highest power | `7n²+9n+3` → **O(n²)** |
| Constants dropped | `5n³` and `1000n³` → both **O(n³)** |
| Logarithmic vs linear | `3n + 7logn` → **O(n)** (n beats log n) |
| Exponential vs polynomial | `3n² = O(2ⁿ)` but `2ⁿ ≠ O(n²)` |
| Constant function | `100` → **O(1)** |

---

## 📊 Worked Reductions

| f(n) | Bound used | c, n₀ | Result |
|---|---|---|---|
| 7n² + 9n + 3 | 9n ≤ 9n², 3 ≤ 3n² | 19, 1 | **O(n²)** |
| 2n² + n | n ≤ n² | 3, 1 | **O(n²)** |
| log₂n + 5 | 5 ≤ 5log₂n (n≥2) | 6, 2 | **O(log n)** |
| 3n + 7log₂n | log₂n ≤ n | 10, 1 | **O(n)** |
| 4n³ + 2n² + 100 | 2n²+100 ≤ n³ (n≥6) | 5, 6 | **O(n³)** |
| 5n³ + 2n + 7 | 2n+7 ≤ n³ (n≥3) | 6, 3 | **O(n³)** |

---

## ⚠️ Common Mistakes

1. **Constant factor gold banana** — `5n³` ko O(n⁴) likhna: galat direction. Constants drop **within** the same class, they never change the class.
2. **Lower-order term ko "pichwade" kam na samajhna** — `+2n` in 5n³+2n+7 is genuinely irrelevant for large n; that IS why we drop it.
3. **Small n ke failure se dar jana** — n=1,2 fail ho sakte hain; Big-O ka wada n₀ se start hota hai.
4. **"Tight c" hi chahiye samajhna** — koi bhi c kaam karta hai; c=14 bhi O(n³) prove karta hai, c=6 se kam elegant nahi.
5. **log vs n ki ranking uljhana** — log n < n < n² … exponential har polynomial ko keep out hai.

---

## 💬 Interview Q&A

**Q1:** *Reduce 6n³ + 4n² + 50 to Big-O.*
**A:** Drop 4n²+50 and the constant 6 → **O(n³)**; e.g. `6n³+4n²+50 ≤ 12n³` for n≥1 (c=12, n₀=1).

**Q2:** *Is O(n²) the same as Θ(n²)?*
**A:** No. O only gives the upper bound; Θ requires a matching lower bound too.

**Q3:** *"3n² = O(n²)"? Is there a c smaller than 3?*
**A:** It's O(n²) since 3n² ≤ 3n² (c=3). Any c < 3 fails eventually — the tight bound coefficient is the leading coefficient itself.

**Q4:** *Why drop the constant in O(5n³)?*
**A:** The definition already has the free multiplier c, so 5 folds into it; complexity measures growth, not speed.

**Q5:** *Does O(n³) beat O(2ⁿ)?*
**A:** Yes — exponent beats any fixed power n³ eventually; that's why exponential algorithms only work for tiny n.