# BIG OMEGA (LOWER BOUND) — Ω Notation

Big Omega is the floor guarantee of an algorithm: it states the minimum growth rate of the running time, a threshold the work can never drop below once n is large enough. Formally, `f(n) = Ω(g(n))` means there exist constants `c > 0` and `n₀ ≥ 0` such that `f(n) ≥ c·g(n)` for all `n ≥ n₀`. It pairs with the best-case idea: even the luckiest input must do this much work.

- Real-world analogy: a courier promising "your parcel will NOT arrive in fewer than 2 days" — 2 days is a floor you can rely on, just like `g(n)` is a floor under `f(n)`.
- **Files in this folder + purpose**:
  - `01_theory.cpp` — the full concept, ASCII floor diagram, demos verifying `n ≥ 1·n` (equal → Ω(n)), the trivial Ω(1) floor, and a worst-case check that linear search touches exactly n comparisons. Edge case n=0 included.
  - `task.cpp` — 4 tasks: prove `n²+2n = Ω(n²)`, TRUE/FALSE quiz on Ω claims, prove linear search is `Ω(n)` and `Ω(1)`, and show `7n` is `Ω(n)` but NOT `Ω(n²)` (with a code + math derivation).
  - `README.md` — this cheat-sheet document.
- **Cheat sheet / formulas**:
  - Definition: `∃ c>0, ∃ n₀ ≥ 0 : f(n) ≥ c·g(n) ∀ n ≥ n₀`
  - Trivial bound: every algorithm does at least 1 operation → always `Ω(1)`
  - Linear search: worst = n comparisons → `Ω(n)`, best = 1 → `Θ(1)`
- **Complexity comparison table**:

| Notation | Meaning | f(n)=n | Valid weaker claims |
|---|---|---|---|
| O (upper) | `f ≤ c·g` | O(n) | also O(n²), O(2ⁿ) |
| Ω (lower) | `f ≥ c·g` | Ω(n) | also Ω(1), Ω(log n) |
| Θ (tight) | `c₁g ≤ f ≤ c₂g` | Θ(n) | none — exact |

- ⚠️ Common mistakes:
  - Writing "the best case is Ω(n)" — a lower bound is not a specific input; it is a claim about the guaranteed minimum of the *function*. Say "T(n)=n is Ω(n)".
  - Believing Ω(1) is useless — it is a valid but weak/trivial floor; always look for the strongest true one.
  - Forgetting the function values the statement is about: `Ω(n²)` and `Ω(n)` can both be *false* for the same small-n fanout — the big-Omega claim requires a *single* `c` for **all** `n ≥ n₀`.
- **Interview Q&A**:
  - Q: "Prove linear search is Ω(n)." — A: `T(n) = n` comparisons worst case; choose `c=1, n₀=0`; then `n ≥ 1·n` identification gives the bound for every `n`.
  - Q: "Can a lower bound be O(n) at the same time?" — A: Yes, if the function is tight (`Θ`), both O and Ω hold with different constants; that is the definition of Big-Theta.
  - Q: "Why does Ω(1) always hold?" — A: even an empty-step algorithm barely touches an operation; any non-trivial algorithm performs ≥1 comparison/step per run, so `f(n) ≥ 1 = 1·1` for all `n ≥ 1`.