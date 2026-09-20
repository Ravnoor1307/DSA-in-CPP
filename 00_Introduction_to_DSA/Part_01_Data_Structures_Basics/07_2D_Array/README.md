# 07 — 2D Array — Introduction

- A 2D array is an array of arrays — a grid organized as rows × columns, indexed as `mat[i][j]`.
- In C/C++ it is stored flat in memory in **row-major** order: row 0 entirely, then row 1, and so on.
- Address of `mat[i][j]` = `base + (i * C + j) * sizeof(type)` where C = number of columns.
- Full traversal needs two nested loops; the outer loop chooses the sweep pattern (row-major vs column-major).
- Signatures: `mat[3][3]`, matrix add/multiply, transpose, image/grid problems all use this structure.

## 🌍 Real-World Analogy

**Cinema hall ka seat plan (3 rows × 4 cols):**

```
       Col0   Col1   Col2   Col3
Row0  (0,0)  (0,1)  (0,2)  (0,3)
Row1  (1,0)  (1,1)  (1,2)  (1,3)
Row2  (2,0)  (2,1)  (2,2)  (2,3)
```

- Seat bhi do numbers se milta hai — row + column. Ek number kaafi nahi.
- Row-major counting = row ke aandar left-to-right, phir agli row — waise hi jaise ticket checks hoti hai.
- Stall to exit raaste pehle col0, col1... bhi jaa sakte ho — wahi column-major sweep.

> *Har seat ki pehchan = (row, col), matlab 2D array ka (i, j).*

## 📂 Files in this folder

| File | Purpose |
|---|---|
| `01_theory.cpp` | 2D array ka live demo: row-major traversal, column-major traversal, single access, row/column views, flat-memory visual |
| `task.cpp` | 7 tasks EASY→HARD: grid print → input grid → total sum → row sums → max+position → transpose → matrix multiplication |

## 📌 Cheat Sheet / Formulas

```
Declare     : int mat[R][C];
Address     : mat[i][j] = base + (i * C + j) * sizeof(type)      // row-major flat offset
Row-major   : for (i = 0; i < R; i++)  for (j = 0; j < C; j++) ...
Column-major: for (j = 0; j < C; j++)  for (i = 0; i < R; i++) ...
Transpose   : for (i < j)  swap(mat[i][j], mat[j][i])
Multiply    : C[i][j] = sum over k of A[i][k] * B[k][j]          // dimensions: (m x n)*(n x p) → m x p
Total cells : R * C
```

## ⏱ Complexity at a glance

| Operation | Step Count | Complexity |
|---|---|---|
| Access `mat[i][j]` | 1 mult + 1 add | f(R,C) = 1 → **O(1)** |
| Print / traverse all | outer×inner = R×C | f(R,C) = R·C → **O(R·C)** |
| Sum of all elements | R×C additions | f(R,C) = R·C → **O(R·C)** |
| Transpose (swap) | only i<j cells, ≈ R·C/2 | f(R,C) = R·C/2 → **O(R·C)** |
| Multiply (m×n)×(n×p) | m·n·p multiplications | f = m·n·p → **O(m·n·p)** |
| Storage | R×C cells × size | f(R,C) = R·C → **O(R·C)** |

## ⚠️ Common Mistakes

1. **Index order ulta karna** — `mat[i][j]` me pehla ROW hai, doosra COLUMN. Bohot log `mat[j][i]` likh dete hain.
2. **Bounds bhoolna** — `mat[R][j]` accessed to out-of-bounds memory par UB. Rows 0..R-1, columns 0..C-1.
3. **Row-major me column loop bahar** — traversal order badal jata hai; memory access bhi cache-unfriendly ho jata hai.
4. **Transpose me full loop** — `for (i <= j)` nahi, `i < j` hi karo; warna har pair do baar swap hoga → original wapas aayega.
5. **Multiplication ke dimensions galat** — A me columns = B me rows hona zaroori hai; warna formula meaning less.
6. **Single loop se 2D print** — 2D data ko 2 nested loops chahiye; `flat` ginti sirf address nikalne ke kaam aati hai.

## 🤝 Interview Q&A

**Q1. 2D array memory me kaise store hota hai?**
Flat, row-major order me — pehli poori row, phir dusri. Isliye `mat[i][j]` ka offset `i*C + j` hota hai.

**Q2. mat[i][j] ka address formula?**
`base + (i*C + j) * sizeof(type)` — C = columns ki sankhya.

**Q3. Row-major vs column-major traversal me kya farak?**
Row-major: outer loop rows, inner columns — memory ke adjacent elements me jate hain. Column-major: outer loop columns — memory me skip-hot e jump (poora row chhod kar) karna padta hai.

**Q4. 2D array ko 1D me convert kaise?**
Flat index = `i*C + j`; wapas `i = idx / C`, `j = idx % C`.

**Q5. Jab dimensions badal sakte hain (user input)?**
`vector<vector<int>> mat(R, vector<int>(C));` dynamic version. Static `mat[R][C]` ke liye R,C compile-time constants hone chahiye.

**Q6. Transpose kaise optimize hota hai?**
Cache-friendly blocks (tiling) se — cache misses kam ho jate hain. Logic wahi: swap mat[i][j] with mat[j][i] for i < j.