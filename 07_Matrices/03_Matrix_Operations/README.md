# 03_Matrix_Operations

## Real-world analogy summary

Matrix operations Excel tables par operations jaisi hoti hain. Same-size tables add/subtract hote hain, row-column relationship se multiplication hota hai, aur transpose rows ko columns bana deta hai.

## Approach comparison table

| Operation | Condition | Formula | Loop count / calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Addition | same dimensions | `C[i][j]=A[i][j]+B[i][j]` | R*C additions | O(R*C) | O(R*C) |
| Subtraction | same dimensions | `C[i][j]=A[i][j]-B[i][j]` | R*C subtractions | O(R*C) | O(R*C) |
| Multiplication | A(m*n), B(n*p) | dot product | m*p*n multiply-adds | O(m*n*p) | O(m*p) |
| Dimension rule | A cols == B rows | `(m*n)(n*p)=m*p` | fixed check | O(1) | O(1) |
| Transpose | any matrix | `T[j][i]=A[i][j]` | R*C assignments | O(R*C) | O(R*C) |
| Square in-place transpose | square matrix | swap above diagonal | n(n-1)/2 swaps | O(n²) | O(1) |
| Matrix power repeated | square matrix | multiply k times | k*n³ | O(k*n³) | O(n²) |

## Key formulas

```text
Addition:       C[i][j] = A[i][j] + B[i][j]
Subtraction:    C[i][j] = A[i][j] - B[i][j]
Multiplication: C[i][j] = Σ A[i][k] * B[k][j]
Dimensions:     (m*n)(n*p) = (m*p)
Transpose:      T[j][i] = A[i][j]
```

## Common mistakes

1. Addition/subtraction me dimension check skip karna.
2. Multiplication condition me A rows and B cols compare karna; correct: A columns == B rows.
3. Matrix multiplication me `C[i][j]` initialize 0 na karna.
4. Transpose me `T[i][j]=A[i][j]` likh dena instead of `T[j][i]`.
5. In-place transpose non-square matrix par apply karna.

## Interview questions

1. Matrix addition kab possible hai?
2. Matrix multiplication dimension rule explain karo.
3. 2x2 multiplication manually dry run karo.
4. Transpose in-place kaise karte hain?
5. Matrix power repeated multiplication ki complexity calculate karo.
