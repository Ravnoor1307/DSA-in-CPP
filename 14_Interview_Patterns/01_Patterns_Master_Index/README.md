# 01_Patterns_Master_Index

## Real-world analogy summary

Interview question ek unknown city route jaisa hai. Pattern recognition GPS hai. Agar signal samajh aa gaya — sorted, contiguous, top-k, all combinations, repeated states — route clear ho jata hai.

## Mega pattern table

| Pattern | Use when | Key signal | Pehle kahan seekha | Template |
|---|---|---|---|---|
| Two Pointers | pair/search/reverse | sorted, opposite ends | Arrays/LL | `l=0,r=n-1` |
| Sliding Window | contiguous segment | longest/min substring/subarray | Arrays/Strings | expand right, shrink left |
| Prefix Sum | range/subarray sums | sum equals k, many range queries | Arrays+Hashing | `prefix += a[i]` |
| Fast-Slow | cycle/middle | linked list cycle, duplicate number | Linked List | `slow+=1, fast+=2` |
| Merge Intervals | overlap timeline | meetings, intervals | New | sort by start |
| Cyclic Sort | 1..n numbers | missing/duplicate seat | New | swap to correct index |
| Top K Heap | kth/top/frequent | top k, closest, stream | Heaps | heap size k |
| Backtracking | all choices | subsets/permutations/grid word | Recursion | choose-explore-undo |
| Greedy | local best | scheduling, jump, platforms | New | sort + pick with proof |
| DP | repeated states | ways/min/max, overlapping | Recursion | memo/tabulate |

## Common mistakes

1. Pattern signal ignore karke direct code likhna.
2. Sliding window and prefix sum confuse karna: both subarray, but window often positive/constraint based; prefix handles exact sum with negatives too.
3. Greedy use karna without proof.
4. DP tabulation se pehle recursion state define na karna.

## Interview questions

1. Top-k signal par heap kyun?
2. Contiguous substring signal par sliding window kyun?
3. Sorted pair signal par two pointers kyun?
4. Overlapping meetings par sort-by-start kyun?
5. DP identify kaise karte ho?
