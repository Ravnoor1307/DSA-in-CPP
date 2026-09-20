# 05_Matrix_Patterns_Traversals

## Real-world analogy summary

Matrix traversal patterns mall routes, fence walk, chess diagonals, and wave lanes jaise real-world paths hain. Interview me pattern ko boundaries/pointers ke through implement karna hota hai.

## Approach comparison table

| Pattern | Core idea | Loop count / calculation | Time | Space |
|---|---|---:|---:|---:|
| Spiral traversal | top/bottom/left/right boundaries shrink | every cell once = R*C | O(R*C) | O(R*C) output |
| Boundary traversal | only perimeter | 2R+2C-4 elements | O(R+C) | O(R+C) output |
| Primary diagonal | `i==j` | n elements | O(n) | O(1) direct print |
| Secondary diagonal | `i+j=n-1` | n elements | O(n) | O(1) direct print |
| Zigzag diagonal | alternate direction by `row+col` | every cell once = R*C | O(R*C) | O(R*C) output |
| Wave traversal | even col down, odd col up | every cell once = R*C | O(R*C) | O(R*C) output |

## Key formulas

```text
Primary diagonal:   i == j
Secondary diagonal: i + j == n - 1
Spiral bounds:      top, bottom, left, right
Zigzag diagonal id: s = row + col
Wave traversal:     if col even -> top-down, else bottom-up
```

## Common mistakes

1. Spiral traversal me corners duplicate print karna.
2. Boundary traversal single row/single column cases ignore karna.
3. Secondary diagonal me `j=n-i` likhna; correct `j=n-1-i`.
4. Zigzag traversal me boundaries invalid hone dena.
5. Wave traversal row-wise and column-wise pattern confuse karna.

## Interview questions

1. 3x3 matrix ka spiral order manually likho.
2. Boundary traversal me corners duplicate kaise avoid karoge?
3. Primary and secondary diagonal conditions kya hain?
4. LeetCode diagonal traversal ka `row+col` idea explain karo.
5. Wave traversal column-wise ka dry run do.
