# Vector of Vectors — 2D Vector / Jagged Array

A `vector<vector<int>>` is a vector whose elements are themselves vectors, giving you a matrix or a ragged (jagged) array where every row can have a different length. The outer vector stores row by row, each inner vector being its own contiguous block, so `v[i][j]` is O(1): jump to row `i`, then column `j`. You build a fixed rectangle with `vector<vector<int>>(rows, vector<int>(cols, val))` or grow a jagged grid by pushing fresh row vectors. Printing always uses row-major order (outer loop rows, inner loop columns). Empty inner rows are legal and must be guarded before any `v[r][0]` access.

- Real-world analogy: a school seating chart — the outer register is the list of classrooms, each classroom row independently holds a different number of benches and students (the seats), and the principal reads "row 2, bench 0" in O(1).

## Files in this folder

| File            | Purpose                                                                 |
| --------------- | ----------------------------------------------------------------------- |
| `01_theory.cpp` | Pure theory: outer-vector-to-inner-vectors ASCII map, declaration forms, inner resize, jagged vs square build + print, empty-row edge case. |
| `task.cpp`      | 6 tasks (easy → hard): print seating chart, identity matrix, transpose, diagonal sums, per-shop sales totals, tallest student per row. |
| `README.md`     | This summary, cheat sheet, complexity derivation, mistakes, interview Q&A. |

## Cheat sheet / syntax table

| Snippet                                   | What it does                      | Time complexity |
| ----------------------------------------- | --------------------------------- | --------------- |
| `vector<vector<int>> g;`                  | Empty 2D vector                   | O(1) |
| `vector<vector<int>> m(r, vector<int>(c));` | r×c zero matrix                 | O(r×c) |
| `vector<vector<int>> m(r, vector<int>(c,v));`| r×c matrix all `v`             | O(r×c) |
| `g.push_back(vector<int>{...})`           | Add one row (jagged build)        | O(row length) |
| `g[i].resize(c)`                          | Set length of row `i` to c        | O(new length) |
| `g[i][j]`                                 | Access cell (row i, col j)        | O(1) |
| `g.size()`                                | Number of rows                    | O(1) |
| `g[r].size()`                             | Length of row r                   | O(1) |
| `g[r].push_back(x)`                       | Append to one row                 | O(1) amortized |
| Row-major print loop                      | Visit every cell once             | O(total cells) |

## Complexity: time & space (with derivation)

- **Build time O(cells)**: creating a square r×c matrix sets one value per cell, r·c assignments → **O(r·c)**; a jagged grid with n total cells does n inner `push_back`s → **O(n)**.
- **Access O(1)**: `g[i]` reads one pointer (outer) in one step, then `[j]` indexes that row's contiguous block in one step → 1 + 1 = constant → **O(1)**.
- **Print / traversal O(cells)**: every cell is touched exactly once across both nested loops; count = number of cells → **O(rows × cols)** for rectangles, **O(n)** for n total elements.
- **Space O(cells)**: memory equals the sum of all row lengths (n cells) plus outer metadata of j row pointers → n + j → **O(n)**; capacity doubling affects only one row or the outer list at a time, still linear.

## ⚠️ Common mistakes

- Indexing an empty row: `g[r][0]` on `vector<int>()` is undefined behaviour — check `!g[r].empty()` first.
- Forgetting `vector<vector<int>> m(3, vector<int>(3))` gives all zeros but must fix per-row length; writing only `m[0][0]=5` on an empty outer vector crashes.
- Mixing row vs column: in `g[r][c]`, `r` must be < `g.size()` and `c` < `g[r].size()` — column bound changes per row in a jagged array.
- Printing in column-major order accidentally (swap loops) — output looks transposed and may read `g[c][r]` out of bounds when row lengths differ.
- Using one fixed `cols` count for every row in a jagged array, losing its whole point.

## Interview Q&A

- **Q: What is a jagged (ragged) array?** A: A 2D structure where every row is an independent vector of its own size, e.g. `{{1,2,3},{4,5},{6}}` — ideal when rows represent groups of different sizes.
- **Q: Why is v[i][j] access O(1)?** A: `v[i]` fetches the row pointer in one step from the outer vector, then `[j]` jumps into that row's contiguous block by pointer arithmetic — both constant work.
- **Q: Memory layout difference from `int a[m][n]`?** A: `a[m][n]` is ONE continuous block so each row must be the same length; `vector<vector<int>>` stores the outer pointers plus per-row blocks, allowing differing lengths and dynamic growth.
- **Q: How do you transpose a matrix?** A: Build `t` with swapped dimensions and run `t[r][c] = a[c][r]` in nested loops — O(rows×cols).
- **Q: How to find main vs anti diagonal?** A: Main diagonal cells satisfy `r == c`; anti-diagonal cells satisfy `r + c == n - 1` for an n×n matrix.