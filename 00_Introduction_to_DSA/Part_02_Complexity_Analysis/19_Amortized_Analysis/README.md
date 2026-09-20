# AMORTIZED ANALYSIS — Average Cost per Operation

Amortized analysis computes the cost of one operation as `(total cost of a sequence of m operations) / m`. It is the honest answer when a data structure has rare but expensive internal repairs: `std::vector::push_back` occasionally copies everything during a resize, yet averaged over many pushes each push is only O(1).

- Real-world analogy: your monthly mess bill — one ₹2,000 birthday dinner among cheap days. The per-meal average answers "how much does one meal cost?" far better than the peak or the cheapest day.
- **Files in this folder + purpose**:
  - `01_theory.cpp` — interactive simulation (asks for m), prints size/cap/cost/avg per push, then verifies the geometric-series bound `total ≤ 2m` and prints `amortized ≈ 1.94` for m=16, plus edge cases m=1 and m=8.
  - `task.cpp` — 4 tasks: simulate 16 pushes and prove amortized O(1) with the geometric series; show why append-only (+1) growth costs Θ(m); design the doubling-vs-chunking trade-off; and argue worst-case vs amortized in the classic interview question.
  - `README.md` — this cheat-sheet document.
- **Cheat sheet / formulas**:
  - Amortized cost = `total cost of m ops / m`
  - Geometric series: `1 + 2 + 4 + ... + k = 2k − 1 < 2k`
  - Dynamic array, m pushes: `copies ≤ 1+2+4+...+2^(k−1) = 2^k − 1 < 2^k ≤ 2m`, so `total ≤ m + 2m = 3m` → per-push ≤ 3 → O(1) amortized.
- **Complexity comparison table**:

| Scenario | Single worst push | Amortized per push | Space |
|---|---|---|---|
| Doubling capacity (vector) | O(n) resize once in a while | O(1) | O(n) |
| Grow by +1 each time | O(n) every time | Θ(n) | O(n) |
| Grow by chunks of 5 | O(n) each 5th push | Θ(n) | O(n) |

- ⚠️ Common mistakes:
  - Saying "vector push is O(1)" without the word *amortized* — the single worst push is O(n).
  - Believing amortized == average-case probabilistic — amortized is a *deterministic* guarantee over a sequence, not probability.
  - Mixing up "O(1) amortized" with "O(1) always" in interview answers.
  - Using arithmetic (not geometric) growth and still claiming O(1) — that is Θ(n) amortized.
- **Interview Q&A**:
  - Q: "Prove dynamic array push is amortized O(1)." — A: m pushes cost m writes; copies follow `1+2+4+...+2^(k−1) = 2^k − 1 < 2^k ≤ 2m`; total ≤ m + 2m = 3m; divide by m → ≤ 3 → O(1) amortized.
  - Q: "Difference between worst-case and amortized?" — A: worst-case reports the single most expensive call (O(n) for a resize push); amortized spreads a whole sequence's total cost evenly over all m operations (O(1) per push).
  - Q: "Why double instead of growing by a constant?" — A: additive growth makes every push a copy (total = m(m+1)/2 → Θ(m)); geometric growth spreads copies into one geometric series → O(1).