# 07_Substring_Problems

## Real-world analogy summary

Substring continuous movie clip jaisa hai; subsequence highlights jaisa hai jisme scenes skip ho sakte hain. Search problems ruler-slide matching, prefix vertical comparison, and palindrome-center expansion se solve hote hain.

## Approach comparison table

| Problem | Approach | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Substrings listing | start/end loops | continuous clips | n(n+1)/2 substrings | O(n²) count | output heavy |
| Subsequences listing | take/skip tree | highlight choices | 2 choices per char | O(2^n) | output heavy |
| Check substring | built-in find | Ctrl+F | worst conceptual n*m | O(n*m) worst | O(1) |
| Check substring | naive | slide ruler | (n-m+1)*m | O(n*m) | O(1) |
| Longest common prefix | vertical scan | contact labels | k strings * L chars | O(kL) | O(L) |
| Longest pal substring | brute | all mirror clips | O(n²) substrings * O(n) check | O(n³) | O(n) |
| Longest pal substring | expand center | grow mirror from center | (2n-1)*n | O(n²) | O(1) extra |

## Key tricks

```text
Substring: continuous
Subsequence: order maintained, skip allowed
Naive pattern match: try each start i, compare pattern chars
LCP: compare words vertically column by column
Palindrome center: odd (c,c), even (c,c+1)
```

## Common mistakes

1. Substring and subsequence confuse karna.
2. `find()` not found case me `string::npos` ignore karna.
3. Naive substring loop `i <= n-m` instead of `<` mistakes.
4. Longest common prefix me shortest string boundary check na karna.
5. Longest palindromic substring me even-length centers skip karna.

## Interview questions

1. Substring vs subsequence visual explain karo.
2. Naive substring search O(n*m) prove karo.
3. Longest common prefix vertical comparison dry run karo.
4. Longest palindromic substring brute force O(n³) kyun?
5. Expand around center odd/even centers explain karo.
