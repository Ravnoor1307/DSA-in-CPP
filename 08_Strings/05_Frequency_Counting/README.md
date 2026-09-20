# 05_Frequency_Counting

## Real-world analogy summary

Frequency counting voting/attendance register jaisa hai. Har character apne box me count hota hai. Array-indexing trick `freq[s[i]-'a']` strings me bahut important hai.

## Approach comparison table

| Problem | Approach | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Char frequency | nested scan | register baar-baar scan | n*n comparisons | O(n²) | O(n) visited |
| Char frequency | array26 | 26 alphabet boxes | n direct increments | O(n) | O(1) |
| Max occurring char | freq + max scan | vote winner | n + 26 | O(n) | O(1) |
| First non-repeating | nested | each token scan whole line | n*n | O(n²) | O(1) |
| First non-repeating | two-pass freq | attendance register then line scan | 2n + 256 | O(n) | O(1) |
| Anagram | sort | arrange tiles | n log n + n | O(n log n) | O(n) |
| Anagram | freq array | add/subtract alphabet boxes | n + 26 | O(n) | O(1) |

## Key tricks

```text
index = s[i] - 'a'
freq[index]++

First non-repeating:
PASS 1 -> frequency
PASS 2 -> first char with frequency 1

Anagram freq:
for i:
    freq[a[i]-'a']++
    freq[b[i]-'a']--
all zero => anagram
```

## Common mistakes

1. Uppercase letters ko lowercase normalize na karna.
2. `freq[ch-'a']` non-lowercase char par apply karna.
3. First non-repeating me frequency banane ke baad original order scan na karna.
4. Anagram me length mismatch check skip karna.
5. Sorting complexity me log calculation explain na karna.

## Interview questions

1. Character frequency O(n²) and O(n) dono explain karo.
2. `freq[s[i]-'a']` ka visual mapping banao.
3. Max occurring char ka algorithm kya hai?
4. First non-repeating char two-pass method explain karo.
5. LISTEN and SILENT anagram frequency-array dry run karo.
