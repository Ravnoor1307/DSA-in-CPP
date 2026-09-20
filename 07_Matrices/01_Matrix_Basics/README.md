# 01_Matrix_Basics

## Real-world analogy summary

Matrix ko classroom seating chart ya Excel sheet ki tarah samjho. Screen par 2D grid dikhta hai, lekin C++ memory me elements row-major 1D sequence me store hote hain.

## Key formulas

```text
A[i][j] = row i, column j
Row-major offset = i * cols + j
Address = base + (i * cols + j) * sizeof(type)
```

Example:

```text
A[2][2] = {{16,20},{30,50}}
base=1000, cols=2, sizeof(int)=4
A[1][1] address = 1000 + (1*2 + 1)*4 = 1012
```

## Approach comparison table

| Operation | Loop count / calculation | Time | Space |
|---|---:|---:|---:|
| Direct access A[i][j] | fixed address arithmetic | O(1) | O(1) |
| Row-wise traversal | R rows * C cols | O(R*C) | O(1) |
| Column-wise traversal | C cols * R rows | O(R*C) | O(1) |
| Row sums + column sums | 2 * R*C visits | O(R*C) | O(R+C) |
| Input + output | R*C reads + R*C prints | O(R*C) | O(R*C) |

## Row-wise vs column-wise cache note

C++ stores 2D arrays in row-major order. Row-wise traversal accesses nearby memory addresses, so it is usually more cache-friendly than column-wise traversal for large matrices.

## Common mistakes

1. 1-based indexing use karna while C++ arrays 0-based hain.
2. A[i][j] me i and j swap kar dena.
3. Address formula me `cols` ki jagah `rows` use karna for row-major.
4. Nested loop bounds galat lagana.
5. Row-wise and column-wise traversal ka time different assume karna; asymptotic time same hai, cache behavior different hai.

## Interview questions

1. Matrix memory me kaise store hota hai?
2. Row-major order kya hota hai?
3. A[i][j] ka address formula derive karo.
4. Row-wise traversal and column-wise traversal me difference kya hai?
5. Cache performance row-wise traversal me better kyun hoti hai?
