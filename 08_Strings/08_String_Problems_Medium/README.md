# 08_String_Problems_Medium

## Real-world analogy summary

Medium string problems mapping, grouping, stack validation, sliding window, and prefix sum patterns use karte hain. Ye arrays/stacks/hashing concepts ka string problems me reuse hai.

## Approach comparison table

| Problem | Approach | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Isomorphic strings | two-way mapping | cipher code | n positions | O(n) | O(1) |
| Group anagrams | freq-key hashing | Scrabble boxes | total chars T + 26*k | O(T) | O(T) |
| Valid parentheses | stack | latest gate closes first | n push/pop ops | O(n) | O(n) |
| Longest unique substring | brute | every playlist segment | O(n²) substrings * O(n) check | O(n³) | O(1) |
| Longest unique substring | sliding window | adjustable no-repeat window | left+right each move n | O(n) | O(1) |
| Count vowels queries | prefix sum | dashboard precompute | build n + q queries | O(n+q) | O(n) |

## Key tricks

```text
Isomorphic: map s->t and t->s
Group anagrams: frequency key of 26 counts
Valid parentheses: push opening, match closing with stack top
Sliding window: expand right, shrink left while duplicate exists
Prefix vowels: query(l,r) = prefix[r+1] - prefix[l]
```

## Common mistakes

1. Isomorphic strings me only one-direction map check karna.
2. Group anagrams me key ambiguous banana.
3. Parentheses validation me final stack empty check skip karna.
4. Longest substring without repeat me window duplicate cleanup incomplete rakhna.
5. Prefix query formula me `prefix[r]-prefix[l]` use karna; correct inclusive range is `prefix[r+1]-prefix[l]`.

## Interview questions

1. Isomorphic strings one-to-one mapping explain karo.
2. Group anagrams frequency-key hashing ka dry run do.
3. Valid parentheses stack se solve karo.
4. Longest substring without repeat brute vs sliding compare karo.
5. Prefix sum on strings se vowel range queries kaise solve hote hain?
