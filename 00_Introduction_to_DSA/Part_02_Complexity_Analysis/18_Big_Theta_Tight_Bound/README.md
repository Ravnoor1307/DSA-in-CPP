# BIG THETA (TIGHT BOUND) — Θ Notation

Big Theta is the precise growth label: `f(n) = Θ(g(n))` means there exist `c₁ > 0`, `c₂ > 0`, `n₀ ≥ 0` with `c₁·g(n) ≤ f(n) ≤ c₂·g(n)` for every `n ≥ n₀`. It is the golden sandwich — the same `g(n)` bounds the function from both below and above, so the algorithm grows *exactly* like `g(n)` up to constant factors.

- Real-world analogy: a bakery quote "between 20 and 30 minutes" — a window that contains the true time on both sides, so the true value can't sneak out. That is Θ; Big-O alone would only say "at most 30".
- **Files in this folder + purpose**:
  - `01_theory.cpp` — the sandwich diagram, a live table printing `1·n² ≤ n²+3n ≤ 2·n²` for n = 1..15 (rows 1–2 violate the upper slice — perfect edge-case demo), plus the Θ(n) proof of linear search worst case.
  - `task.cpp` — 4 tasks: prove `n³+2n = Θ(n³)`, classify classic loops (Θ(n), Θ(n²), Θ(log n), Θ(1)), run the decisive experiment showing `n³+2n` is NOT Θ(n²), and see why Ω alone can never imply Θ.
  - `README.md` — this cheat-sheet document.
- **Cheat sheet / formulas**:
  - Definition: `∃ c₁>0, c₂>0, n₀≥0 : c₁·g(n) ≤ f(n) ≤ c₂·g(n) ∀ n ≥ n₀`
  - Equivalence: `Θ(g) = O(g) ∩ Ω(g)` — Θ is both bounds at once.
  - Dominant-term rule: `n² + 3n = Θ(n²)`; `n³ + 2n = Θ(n³)`; the lower-order terms vanish inside the constants.
- **Complexity comparison table**:

| Function | O (upper) | Ω (lower) | Θ (exact) |
|---|---|---|---|
| `n` | O(n) (also O(n²)) | Ω(n) (also Ω(1)) | Θ(n) |
| `n²+3n` | O(n²) | Ω(n²) | Θ(n²) |
| `n³+2n` | O(n³) | Ω(n³) | Θ(n³) |

- ⚠️ Common mistakes:
  - Writing `Θ(n³)` for a function that is only `Ω(n²)` — you need BOTH slices for the same g.
  - Forgetting the domain: `n²+3n ≤ 2n²` requires `n ≥ 3`; picking n₀ too small breaks the sandwich.
  - Mixing "worst case Θ(n)" with "best case Θ(n)" — each case has its own Θ.
  - Believing `Θ` is always of the dominant term — constants matter: `5n` is Θ(n), not Θ(5n).
- **Interview Q&A**:
  - Q: "Prove `n² + 3n` is Θ(n²)." — A: choose c₁=1, c₂=2, n₀=3; then `1·n² ≤ n²+3n` holds since `3n ≥ 0`, and `n²+3n ≤ 2n²` ⟺ `n ≥ 3`. Both slices verified ⇒ Θ(n²).
  - Q: "Difference between O and Θ?" — A: O is only an upper bound; Θ requires a matching lower bound, pinning the exact growth class.
  - Q: "When can you NOT use Θ?" — A: when the function oscillates between two different classes (e.g. best O(log n) but worst O(n)) you describe per-case instead of one Θ for the whole algorithm.