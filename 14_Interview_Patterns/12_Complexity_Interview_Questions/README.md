# 12_Complexity_Interview_Questions

## Real-world analogy summary

Complexity analysis billing counter jaisa hai: operations count karo. Fir constants/lower terms remove karke growth class bolo.

## Cheat sheet

| Code pattern | Calculation | Big-O |
|---|---:|---:|
| single loop | n | O(n) |
| two separate same loops | n+n = 2n | O(n) |
| nested n by n | n*n | O(n²) |
| triangular nested | n+(n-1)+...+1 = n(n+1)/2 | O(n²) |
| halve each time | n/2^k=1 -> k=log₂n | O(log n) |
| outer n, inner log n | n*log n | O(n log n) |
| all subsets | 2 choices for n items | O(2^n) |
| all permutations | n! arrangements | O(n!) |

## Common mistakes

1. `O(2n)` likhna — answer `O(n)` hota hai.
2. `O(n²+n)` ko simplify na karna.
3. Different inputs `n` and `m` ko forcefully same maan lena.
4. Recursion stack space ignore karna.
5. HashMap average O(1) and worst O(n) nuance na samajhna.
6. Sorting ko O(n) bol dena.

## Interview questions

1. Five code snippets ka complexity batao with calculation.
2. Binary search O(log n) derive karo.
3. Nested triangular loop O(n²) kyun?
4. Merge sort O(n log n) kyun?
5. Constants Big-O me drop kyun karte hain?
6. Space complexity me recursion stack kab count karte hain?
