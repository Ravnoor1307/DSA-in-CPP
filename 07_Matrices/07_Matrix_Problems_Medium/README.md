# 07_Matrix_Problems_Medium

## Real-world analogy summary

Medium matrix problems image rotation, spreadsheet cleanup, optimized factory operation order, and boolean access propagation jaise scenarios par based hain. In problems me transformations ke saath space optimization important hoti hai.

## Approach comparison table

| Problem | Approach | Trick | Loop count / calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Rotate 90 | Extra matrix | `R[j][n-1-i]=A[i][j]` | n² assignments | O(n²) | O(n²) |
| Rotate 90 | Transpose + reverse | in-place swaps | n(n-1)/2 + n²/2 swaps | O(n²) | O(1) |
| Set matrix zeros | Brute copy | clear row+col for each original zero | n² zeros * 2n clear | O(n³) square | O(n²) |
| Set matrix zeros | In-place | first row/column as markers | about 2RC scans | O(R*C) | O(1) |
| Matrix chain order | DP preview | choose split k | n*n*n states/splits | O(n³) | O(n²) |
| Boolean matrix row/col set | marker arrays | rowMark + colMark | 2RC scans | O(R*C) | O(R+C) |

## Key formulas / tricks

```text
Rotate clockwise extra: R[j][n-1-i] = A[i][j]
Rotate in-place: transpose -> reverse every row
Set Zeroes in-place: A[i][0] and A[0][j] as markers
MCM cost: dims[i] * dims[k+1] * dims[j+1]
Boolean matrix: rowMark[i] || colMark[j] => A[i][j]=1
```

## Common mistakes

1. Rotate matrix 90 clockwise and anticlockwise formulas confuse karna.
2. In-place rotate me reverse columns instead of rows kar dena for clockwise rotation.
3. Set Matrix Zeroes me original zeros and newly-created zeros mix kar dena.
4. First row/first column flags skip karna in O(1) zeroes approach.
5. Matrix chain multiplication me final matrix multiply nahi, cost optimize karna hota hai ye bhoolna.
6. Boolean matrix problem me direct mutation se cascading 1s create kar dena.

## Interview questions

1. Rotate matrix 90 degree using extra space and in-place dono explain karo.
2. Transpose + reverse trick ka dry run do.
3. Set Matrix Zeroes O(1) space approach explain karo.
4. Matrix multiplication order matter kyun karta hai?
5. Boolean matrix row-column set me marker arrays kyun zaruri hain?
