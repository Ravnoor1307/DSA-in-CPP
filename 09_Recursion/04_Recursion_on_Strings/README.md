# 04_Recursion_on_Strings

## Real-world analogy summary

String recursion letters ko one-by-one ya dono ends se process karta hai. Name board reverse, vowel counting, mirror-word check, take/skip subsequences, and character removal common patterns hain.

## Approach comparison table

| Problem | Recursive idea | Calculation | Time | Space |
|---|---|---:|---:|---:|
| Reverse string | `reverse(rest)+first` | n calls, substr copies sum n² | O(n²) simple | O(n²) temp |
| Vowel count | current + rest count | n+1 calls | O(n) | O(n) stack |
| Palindrome string | compare ends | floor(n/2) calls | O(n) | O(n) stack |
| Subsequences | TAKE/SKIP each char | 2^n leaves, up to n print/copy | O(n*2^n) | O(n*2^n) output |
| Remove char | skip/keep current | n calls, string concat may copy | O(n²) simple | O(n²) temp |

## Key formulas / patterns

```text
reverse(s) = reverse(s.substr(1)) + s[0]
countVowels(i) = isVowel(s[i]) + countVowels(i+1)
isPal(l,r) = s[l]==s[r] && isPal(l+1,r-1)
subsequence: for each char -> TAKE or SKIP
removeChar(i): if s[i]==target skip else keep
```

## Common mistakes

1. Empty string base case bhoolna.
2. Palindrome recursion me left/right cross base case miss karna.
3. Subsequences me take/skip dono branches na banana.
4. Empty subsequence concept ignore karna.
5. String concatenation hidden copying cost ignore karna.

## Interview questions

1. Recursive string reverse explain karo.
2. Vowel count recursion me index base case kya hai?
3. Palindrome string recursive two-pointer dry run karo.
4. "abc" subsequence recursion tree draw karo.
5. Remove character recursive keep/skip logic explain karo.
