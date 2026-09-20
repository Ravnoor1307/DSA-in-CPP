# 05_Advanced_Recursion_Patterns

## Real-world analogy summary

Advanced recursion patterns choices, undo, and 2D spread use karte hain: Tower of Hanoi rods, permutations of friends, staircase jumps, binary search half discard, and paint bucket flood fill.

## Approach comparison table

| Pattern | Core idea | Calculation | Time | Space |
|---|---|---:|---:|---:|
| Tower of Hanoi | move n-1, largest, n-1 | T(n)=2T(n-1)+1 = 2^n-1 | O(2^n) | O(n) |
| Permutations | swap choice + undo | n! leaves, n print each | O(n*n!) | O(n) stack |
| Staircase paths | choose 1 or 2 steps | binary tree height n | O(2^n) naive | O(n) |
| Recursive binary search | halve array | n/2^k=1 -> k=log₂n | O(log n) | O(log n) |
| Flood fill | 4-direction DFS | each cell once, 4 checks | O(R*C) | O(R*C) worst |

## Key formulas

```text
Tower of Hanoi moves = 2^n - 1
Permutations count = n!
Staircase ways(n) = ways(n-1) + ways(n-2)
Binary search size after k calls = n / 2^k
n / 2^k = 1 -> n = 2^k -> k = log₂n
Flood fill directions: up, down, left, right
```

## Common mistakes

1. Tower of Hanoi helper/destination rods swap wrong karna.
2. Permutations me swap back/undo bhoolna.
3. Staircase base `n==0 return 1` and `n<0 return 0` confuse karna.
4. Binary search recursive base `low>high` skip karna.
5. Flood fill me oldColor==newColor check skip karna causing infinite-style repeated work.
6. Flood fill boundary checks after grid access karna.

## Interview questions

1. Tower of Hanoi n=3 ke 7 moves likho.
2. Hanoi formula 2^n-1 ka recurrence explain karo.
3. Permutations of abc using swap tree draw karo.
4. Backtracking me undo kyun zaruri hai?
5. Staircase paths Fibonacci kaise hai?
6. Recursive binary search O(log n) prove karo.
7. Flood fill DFS ka 2D recursion dry run karo.
