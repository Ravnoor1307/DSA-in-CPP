# Patterns using Loops (Nested Loops)

- Prints star/number patterns using nested loops: the outer loop picks the row, the inner loop fills it with characters.
- Every pattern reduces to one question: "how many characters should row i print?" — right triangle prints i, pyramid prints 2i−1, diamond prints both halves.
- Complexity is derived by counting inner executions: 1 + 2 + ... + n = n(n+1)/2 → O(n²).
- Space stays O(1) because only a few loop counters are used, no matter how large n is.
- Master these to build grid/board renderers, ASCII art, seating charts, and rock-solid loop intuition.

- Real-world analogy: A wedding seating chart is built row by row — row 1 gets 1 chair, row 2 gets 2 chairs; printing it is exactly a nested loop (outer loop = row, inner loop = chairs in that row).

- Files in this folder:
  - `01_theory.cpp` — full concept, ASCII pattern diagrams, dry runs, O(n²) derivation, compile-ready demo with edge cases (n=0, n=1).
  - `task.cpp` — 7 tasks EASY→HARD (right-aligned, inverted, number pyramid, diamond, number triangle, alphabet, hollow triangle) + full solutions.

- Cheat sheet / syntax table:

  | Pattern      | Spaces        | Characters        | Loop structure                      |
  |--------------|---------------|-------------------|-------------------------------------|
  | right triang.| —             | i                 | `for i=1..n` / `for j=1..i`          |
  | right-align  | n−i           | i                 | spaces loop then stars loop          |
  | inverted     | —             | i (i from n→1)    | `for i=n..1` / `for j=1..i`          |
  | pyramid      | n−i           | 2i−1              | spaces loop + stars loop + newline   |
  | diamond      | n−i then n−i  | 2i−1 (twice)      | top loop + bottom loop (i=n−1→1)     |
  | hollow       | —             | boundary only     | print `*` if `j==1 || j==i || i==n`  |

- Complexity:
  - Time: outer loop n rows; inner total = Σ i = n(n+1)/2 → **O(n²)**.
  - Space: **O(1)** extra (loop counters only).

- ⚠️ Common mistakes:
  - Off-by-one: starting rows at 0 while the pattern spec is 1-based, or printing n stars on row 1.
  - Swapping i and j — printing the column counter where the row number was needed (and vice versa).
  - Forgetting the newline — the whole pattern squashes onto one line.
  - Pyramid spacing counted as 1 char when the star field is wider, destroying the center alignment.
  - Repeating the widest row in a diamond instead of starting the bottom half at i = n−1.

- Interview Q&A:
  - Q: Why is a triangle O(n²) and not O(n)? A: Row i runs the inner loop i times; the total is Σ i = n(n+1)/2 = O(n²).
  - Q: Can we do it faster than O(n²)? A: No — printing itself is the work; O(n²) characters must be produced.
  - Q: How does a diamond avoid a duplicated middle row? A: The top half ends at i=n and the bottom half starts at i=n−1.
  - Q: What makes the hollow triangle O(n²)? A: The inner loop still iterates i times per row even though most cells print spaces.