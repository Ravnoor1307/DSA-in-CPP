# 06_Matrix_Problems_Easy

## Real-world analogy summary

Easy matrix problems mostly searching and simple diagonal calculations par based hain. Library search, sorted shelves, staircase movement, cross-road diagonal sum, and attendance rows jaise scenarios se patterns yaad rakh sakte ho.

## Approach comparison table

| Problem | Approach | Condition | Loop count / calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Search matrix | Bruteforce | none | R*C comparisons | O(R*C) | O(1) |
| Search matrix | Row-wise binary search | each row sorted | R rows * log₂C | O(R log C) | O(1) |
| Search matrix | Staircase | rows and columns sorted | at most R+C moves | O(R+C) | O(1) |
| Sum diagonals | direct diagonal loop | square matrix | n iterations, <=2n additions | O(n) | O(1) |
| Row with max ones | top-right scan | rows sorted 0s then 1s | at most R+C moves | O(R+C) | O(1) |

## Key formulas

```text
Primary diagonal:   A[i][i]
Secondary diagonal: A[i][n-1-i]
Staircase search:   target < current -> left, target > current -> down
Row max ones:       1 -> move left and update answer, 0 -> move down
Binary search log:  C / 2^k = 1 -> C = 2^k -> k = log₂C
```

## Common mistakes

1. Staircase search sorted rows+columns condition skip karna.
2. Staircase direction reverse karna.
3. Odd-size diagonal sum me center double count karna.
4. Row with max ones me unsorted rows par top-right method apply karna.
5. Row-wise binary search complexity me log calculation explain na karna.

## Interview questions

1. Matrix search ka brute force explain karo.
2. Row-wise binary search kab valid hai?
3. Staircase search top-right se kaise kaam karta hai?
4. Diagonal sum me center double count kaise avoid karte hain?
5. Row with max ones optimized O(R+C) ka dry run do.
