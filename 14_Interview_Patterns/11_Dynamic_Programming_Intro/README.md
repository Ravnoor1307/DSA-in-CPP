# 11_Dynamic_Programming_Intro

## Real-world analogy summary

DP restaurant notebook jaisa hai: same bill/subproblem baar-baar calculate mat karo; answer store kar lo. DP = Recursion + Memory.

## 5-step framework

```text
1. Recursion state define karo.
2. Overlapping subproblems identify karo.
3. Memoization lagao.
4. Tabulation bottom-up banao.
5. Space optimize karo if possible.
```

## Pattern table

| Problem | State | Recurrence | Time | Space |
|---|---|---|---:|---:|
| Fibonacci | f(n) | f(n-1)+f(n-2) | O(n) memo/tab | O(n) or O(1) |
| Climbing stairs | ways(n) | ways(n-1)+ways(n-2) | O(n) | O(n)/O(1) |
| House robber | dp[i] | max(skip, rob) | O(n) | O(n)/O(1) |
| Coin change | dp[amount] | min(dp[a-coin]+1) | O(A*C) | O(A) |
| LCS | dp[i][j] | match diag+1 else max(top,left) | O(n*m) | O(n*m) |
| 0/1 Knapsack | dp[i][cap] | max(skip,take) | O(n*W) | O(n*W) |

## Complexity formula

```text
DP time = number of states * transition work per state
DP space = memo/table states
```

## Common mistakes

1. State define kiye bina table banana.
2. Base cases miss karna.
3. Memo array initialize na karna.
4. Tabulation fill order wrong rakhna.
5. 0/1 knapsack and unbounded coin change transitions confuse karna.

## Interview questions

1. DP kya hota hai?
2. Fibonacci recursion O(2^n) kyun and memo O(n) kyun?
3. Memoization vs tabulation compare karo.
4. House robber recurrence explain karo.
5. Coin change min coins DP explain karo.
6. LCS 2D DP formula batao.
7. 0/1 knapsack recurrence explain karo.
8. DP 5-step framework batao.
