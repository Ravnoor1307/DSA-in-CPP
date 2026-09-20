# 2D Arrays

2D arrays store data in a grid of rows and columns, indexed by two coordinates `[i][j]`. Memory is laid out in **row-major** order — row 0 stored first, then row 1, all contiguously. This is the foundation for matrices, grids, maps, and image pixels.

Real-world analogy: Cinema hall seats — every seat is identified by row number and column number, exactly like `seats[row][col]`.

## Files

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory: declaration, initialization, row-major memory layout, traversal, sum, transpose with ASCII diagrams and edge cases |
| `task.cpp` | 6 tasks: diagonal sum, multiplication table, matrix addition, matrix multiplication, rotate 90°, spiral traversal |
| `README.md` | This file — summary, cheat sheet, complexity, mistakes, interview Q&A |

## Cheat Sheet

```cpp
// Declaration
int mat[3][4];              // 3 rows, 4 cols
int mat[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};  // initialized

// Traversal
for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
        cout << mat[i][j];

// Address formula: mat[i][j] lives at base + (i*C + j) * sizeof(int)
// Transpose: trans[j][i] = mat[i][j]
```

## Complexity

| Operation | Time | Derivation |
|-----------|------|------------|
| Traversal | O(R×C) | Outer loop R iterations × inner loop C iterations = R×C accesses |
| Row Sum | O(R×C) | For each of R rows, do C additions → R×C |
| Transpose | O(R×C) | Visit every cell once → R×C |
| Diagonal Sum | O(min(R,C)) | Only min(R,C) diagonal elements |

**Space:** O(R×C) for the matrix itself. O(1) extra for traversal/sum. O(R×C) for transpose (new matrix).

## Common Mistakes

1. **Loop order wrong**: Outer = rows (`i`), inner = columns (`j`). Reversing gives wrong traversal.
2. **Index out of bounds**: `mat[R][C]` → valid indices are `0..R-1` and `0..C-1`.
3. **Forgetting row-major**: `mat[i][j]` and `mat[j][i]` are different unless transposing.
4. **VLA not in C++**: `int mat[n][n]` with variable `n` is not standard C++. Use `const int N` or dynamic allocation.
5. **Transpose on non-square**: Output matrix must be `[C][R]`, not `[R][C]`.

## Interview Q&A

**Q: How is a 2D array stored in memory?**
A: Row-major — all elements of row 0 first, then row 1, etc. `mat[i][j]` is at offset `i*C + j`.

**Q: What is the difference between `mat[2][3]` and `mat[3][2]`?**
A: `mat[2][3]` has 2 rows and 3 columns (6 elements). `mat[3][2]` has 3 rows and 2 columns (also 6 elements). They have different shapes and different memory layouts.

**Q: How do you transpose a matrix?**
A: Swap `mat[i][j]` with `mat[j][i]` for all `i < j`. For rectangular matrices, create a new `[C][R]` array.

**Q: How do you rotate a matrix 90° clockwise?**
A: Two steps — (1) Transpose the matrix, (2) Reverse each row. Both are O(N²).
