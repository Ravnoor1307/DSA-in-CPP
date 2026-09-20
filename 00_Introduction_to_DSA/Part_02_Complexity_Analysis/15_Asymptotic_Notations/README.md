# 15 — Asymptotic Notations

## 📌 Summary (5 English lines)
- **Big-O** `O(g)` gives an **upper bound**: `f(n) ≤ c·g(n)` for all `n ≥ n₀` — the ceiling of growth.
- **Omega** `Ω(g)` gives a **lower bound**: `f(n) ≥ c·g(n)` for all `n ≥ n₀` — the floor of growth.
- **Theta** `Θ(g)` is the **tight bound**: `c₁·g(n) ≤ f(n) ≤ c₂·g(n)` holding both upper and lower.
- To prove `f(n) = O(g(n))` you only need to *exhibit one* valid **c** and **n₀** (not the tightest).
- **little-o** (`f < c·g` for every c) means strictly slower; **little-omega** (`f > c·g` for every c) means strictly faster.

## 🌍 Real-World Analogy
Teacher's three promises about a student's score: "at most 95" (Big-O, an upper cap), "at least 40" (Omega, a floor), "between 70 and 90 every time" (Theta, a tight band). An algorithm's runtime f(n) gets the same treatment — one cap, one floor, or both.

```
Big-O  : f(n) ≤ c·g(n)    ceiling
Omega  : f(n) ≥ c·g(n)    floor
Theta  : c1·g(n) ≤ f(n) ≤ c2·g(n)   band
```

---

## 📂 Files

| File | Kya hai |
|---|---|
| `01_theory.cpp` | verifies `f(n)=3n+2` vs `4n` table (Big-O), Omega check, Theta verdict, and why `n² ≠ O(n)` |
| `task.cpp` | 6 tasks: find c & n₀ for O(n), O(n²), Θ(n), Θ(n²) and disprove `n³ = O(n²)` |

---

## 📐 Definitions (formal)

| Notation | Definition | Meaning |
|---|---|---|
| `f = O(g)` | `∃ c, n₀ > 0 : f(n) ≤ c·g(n) ∀ n ≥ n₀` | grows no faster |
| `f = Ω(g)` | `∃ c, n₀ > 0 : f(n) ≥ c·g(n) ∀ n ≥ n₀` | grows no slower |
| `f = Θ(g)` | `∃ c₁,c₂,n₀ > 0 : c₁g(n) ≤ f(n) ≤ c₂g(n)` | exact rate |
| `f = o(g)` | `∀ c > 0 ∃ n₀ : f(n) < c·g(n)` | strictly slower |
| `f = ω(g)` | `∀ c > 0 ∃ n₀ : f(n) > c·g(n)` | strictly faster |

**Theorem:** `f = Θ(g) ⇔ f = O(g) and f = Ω(g)`

---

## 📊 Worked Examples

| f(n) | O-class | proof (c, n₀) | Ω-class | Θ? |
|---|---|---|---|---|
| 3n+2 | O(n) | c=4, n₀=2 | Ω(n), c=3 | **Θ(n)** |
| 5n+3 | O(n) | c=6, n₀=3 | Ω(n), c=5 | Θ(n) |
| n²+2n | O(n²) | c=2, n₀=2 | Ω(n²) | Θ(n²) |
| n²+10n | O(n²) | c=2, n₀=10 | Ω(n²) | Θ(n²) |
| 100n+5 | O(n) | c=101, n₀=5 | Ω(n), c=1 | Θ(n) |
| n²+3n+1 | O(n²) | c=5, n₀=1 | Ω(n²), c₁=1 | Θ(n²) |
| n³ | O(n³) | c=1, n₀=1 | Ω(n³) | Θ(n³) — but **NOT O(n²)** |

---

## ⚠️ Common Mistakes

1. **`Θ` aur `O` ko mix karna** — `O(n²)` sirf ceiling hai; sahi batane ke liye dono bounds chahiye → `Θ`.
2. **Sirf ek c dikhana bhoolna** — table ka **every** row within `n ≥ n₀` pass honi chahiye definition ke hisaab se.
3. **`n² = O(n)` man lena** — `n² ≤ c·n ⇔ n ≤ c` hamesha fail hota hai `n > c` pe.
4. **n₀ ko ignore karna** — constants sirf *eventually* (n ≥ n₀) par valid hain; n=1 ke failure se koi farak nahi.
5. **`o` vs `O`** — `o(g)` strict hai (f/galat rate), `O(g)` loose; `2n = O(n)` true par `2n = o(n)` false.

---

## 💬 Interview Q&A

**Q1:** *Prove 3n² + 5n is O(n³) — is it Θ(n³)?*
**A:** `3n²+5n ≤ 3n²+5n² = 8n² ≤ 8n³` for n≥1 → O(n³). But Θ(n³) is **false** — the lower bound fails: `f/n³ → 0`, so it is `o(n³)` actually.

**Q2:** *If f(n) = O(n²) and g(n) = O(n), what is f+g and f·g?*
**A:** `f+g = O(n²)` (dominant term wins), `f·g = O(n³)` (multiply bounds).

**Q3:** *Is 2^n = Θ(3^n)?*
**A:** No — 2ⁿ/3ⁿ → 0, so `2ⁿ = o(3ⁿ)`; no constant c₁ can floor 3ⁿ by 2ⁿ eventually.

**Q4:** *"Worst-case is O(n log n)" vs "Theta(n log n)" — difference?*
**A:** O only caps; Θ pins the exact growth — stronger claim, always preferred when true.

**Q5:** *Can a function be O(n) and Ω(n²) simultaneously?*
**A:** Yes — a ceiling doesn't conflict with a floor. Example: f hovering between n and n². But then Θ(n²) is false.

**Q6:** *Why do we pick a specific c and n₀ in proofs?*
**A:** The definition is existential (∃ c, n₀) — exhibiting any valid pair is a complete proof.