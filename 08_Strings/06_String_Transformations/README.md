# 06_String_Transformations

## Real-world analogy summary

String transformations text editor/data-cleaning features jaise hain: case convert, toggle caps, remove vowels/spaces/duplicates, title case, compression, and rotation check.

## Approach comparison table

| Transformation | Trick | Calculation | Time | Space |
|---|---|---:|---:|---:|
| Upper/lower convert | ASCII or `tolower/toupper` | n chars | O(n) | O(n) output / O(1) in-place |
| Toggle case | A-Z add 32, a-z subtract 32 | n checks | O(n) | O(1) |
| Remove vowels | skip vowel chars | n checks | O(n) | O(n) |
| Remove spaces+duplicates | seen[256] | n checks | O(n) | O(n) output + O(1) seen |
| Capitalize first letter | `newWord` flag | n checks | O(n) | O(1) |
| String compression | group consecutive chars | n-1 comparisons | O(n) | O(n) |
| Rotation check | `(s+s).find(goal)` | build 2n + find worst n² | O(n²) worst | O(n) |

## Key tricks

```text
'a' - 'A' = 32
Upper -> lower: ch + 32
Lower -> upper: ch - 32

Compression: "aaabbc" -> "a3b2c1"
Rotation: goal is rotation if goal is substring of s+s
```

## Common mistakes

1. ASCII conversion non-alphabet chars par apply karna.
2. Remove vowels me uppercase vowels skip na karna.
3. Compression me last group append karna bhoolna.
4. Single char compression edge case ignore karna.
5. Rotation check me length mismatch check skip karna.

## Interview questions

1. ASCII case conversion explain karo.
2. Toggle case ka algorithm kya hai?
3. Remove spaces and duplicates preserving order kaise karoge?
4. String compression "aaabbc" dry run karo.
5. Rotation check double-string trick explain karo.
