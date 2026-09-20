# 04_Special_Matrices

## Real-world analogy summary

Special matrices regular tables jaisi nahi hoti; unme zeros/diagonal/mirror pattern hota hai. In patterns ko exploit karke checks fast aur storage optimized ho sakta hai.

## Approach comparison table

| Matrix type | Condition | Loop count / calculation | Time | Space idea |
|---|---|---:|---:|---:|
| Identity | `i==j -> 1`, else `0` | n² cells fill/check | O(n²) | O(n²) full |
| Diagonal | off-diagonal zero | compact access O(1) | O(1) access | O(n) compact |
| Symmetric | `A[i][j]=A[j][i]` | n(n-1)/2 comparisons | O(n²) | O(1) check |
| Upper triangular | `i>j` cells zero | n(n-1)/2 checks | O(n²) | n(n+1)/2 compact |
| Lower triangular | `i<j` cells zero | n(n-1)/2 checks | O(n²) | n(n+1)/2 compact |
| Scalar | diagonal same k, off diagonal 0 | n² checks | O(n²) | O(1) check |
| Unit | scalar with k=1 | n² checks | O(n²) | O(1) check |

## Key formulas / conditions

```text
Identity:       A[i][j] = 1 if i==j else 0
Diagonal:       A[i][j] = 0 if i!=j
Symmetric:      A[i][j] = A[j][i]
Upper:          A[i][j] = 0 for i > j
Lower:          A[i][j] = 0 for i < j
Scalar:         A[i][i] = k for all i, off-diagonal 0
Unit/Identity:  scalar with k=1
```

## Common mistakes

1. Identity matrix non-square declare karna.
2. Diagonal and scalar matrix ko same samajhna; scalar me all diagonal values same hote hain.
3. Symmetric check me non-square matrix allow kar dena.
4. Upper triangular me wrong region check karna.
5. Compact storage count n(n+1)/2 bhoolna.

## Interview questions

1. Identity matrix property I×A=A prove/explain karo.
2. Diagonal matrix ko O(n) space me kaise store karoge?
3. Symmetric matrix check ka optimized loop kya hai?
4. Upper and lower triangular matrix difference kya hai?
5. Scalar matrix and unit matrix me relation kya hai?
