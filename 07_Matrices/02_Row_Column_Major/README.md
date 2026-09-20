# 02_Row_Column_Major

## Real-world analogy summary

Matrix ek building ke flats jaisa hai. Agar list row-by-row banegi to row-major, agar column-by-column banegi to column-major.

## Row Major vs Column Major table

| Feature | Row-major | Column-major |
|---|---|---|
| Flat order for `{{16,20},{30,50}}` | `[16,20,30,50]` | `[16,30,20,50]` |
| First complete unit | row | column |
| Formula | `base + (i*nCols + j)*sizeof` | `base + (j*nRows + i)*sizeof` |
| Used by | C/C++ | Fortran/MATLAB style |
| Cache friendly traversal in C++ | row-wise | not usually |

## Address formulas

### Row-major

```text
Address(A[i][j]) = base + (i * nCols + j) * sizeof(type)
```

Example:

```text
base=1000, i=2, j=1, nCols=4, sizeof(int)=4
= 1000 + (2*4 + 1)*4
= 1000 + 9*4
= 1036
```

### Column-major

```text
Address(A[i][j]) = base + (j * nRows + i) * sizeof(type)
```

Example:

```text
base=1000, i=2, j=1, nRows=3, sizeof(int)=4
= 1000 + (1*3 + 2)*4
= 1000 + 5*4
= 1020
```

## Common mistakes

1. Row-major formula me `nRows` use kar dena.
2. Column-major formula me `nCols` use kar dena.
3. i and j swap kar dena.
4. Base address plus byte offset multiply by sizeof bhoolna.
5. C++ ka storage row-major hai ye ignore karna.

## Interview questions

1. Row-major order explain karo.
2. Column-major order explain karo.
3. C++ 2D array memory me kaise store hota hai?
4. A[i][j] ka row-major address calculate karo.
5. Same i,j ka row-major and column-major address different kyun ho sakta hai?
