# 09_Backtracking_Pattern

## Real-world analogy summary

Backtracking maze solving hai: choice lo, explore karo, dead-end aaye to undo karke next choice try karo.

## Mantra

```text
CHOOSE -> EXPLORE -> UNDO
```

## Pattern table

| Problem | Choice | Complexity | Space |
|---|---|---:|---:|
| Subsets | include/exclude | O(n*2^n) | O(n) + output |
| Permutations | choose position value | O(n*n!) | O(n) + output |
| Combination Sum | choose candidate, reuse allowed | exponential | O(target/min) |
| Word Search | choose grid cell path | O(R*C*4*3^(L-1)) | O(L) |
| N-Queens | choose safe column per row | O(n!) | O(n²) |

## Common mistakes

1. Undo step bhoolna.
2. Combination sum reuse allowed me recursive start `i` ki jagah `i+1` karna.
3. Word search me visited restore na karna.
4. N-Queens diagonal checks slow O(n) rakhna jab arrays se O(1) ho sakta hai.
5. Backtracking and DP confuse karna.

## Interview questions

1. Backtracking mantra explain karo.
2. Subsets decision tree me 2^n leaves kyun?
3. Permutations n! kyun hoti hain?
4. Combination sum me reuse kaise allow hota hai?
5. Word search grid backtracking kaise hai?
6. N-Queens safe check explain karo.
7. Backtracking vs DP difference kya hai?
