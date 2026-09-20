# 03_String_Traversals_Patterns

## Real-world analogy summary

String traversal ek name board ke har letter ko inspect karne jaisa hai. Reverse problems bookshelf swap, word reverse stack of cards, and sentence flip tricks se samajh aate hain.

## Approach comparison table

| Problem | Approach | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Count vowels/consonants | one scan | teacher checks each letter | n checks | O(n) | O(1) |
| Count words/spaces | insideWord flag | word processor status bar | n checks | O(n) | O(1) |
| Reverse string | extra string | photocopy then read backward | n appends | O(n) | O(n) |
| Reverse string | two pointers | swap bookshelf ends | floor(n/2) swaps | O(n) | O(1) |
| Reverse words | stack | word cards pile | n read + n pop/build | O(n) | O(n) |
| Reverse words | reverse trick | flip full board, then each word | linear passes | O(n) | O(1) possible |

## Key formulas / tricks

```text
Last index = n - 1
Two pointers: left=0, right=n-1, swap while left<right
Words robust count: new word starts when current char not space and insideWord=false
Reverse words trick: reverse whole string -> reverse each word
```

## Common mistakes

1. Space count + 1 formula leading/trailing/multiple spaces par use karna.
2. Reverse two pointers me loop `left <= right` unnecessary swap karna.
3. Reverse words stack approach me extra spaces normalize effect ignore karna.
4. In-place reverse words me full reverse ke baad words reverse karna bhoolna.
5. Vowel count me uppercase letters handle na karna.

## Interview questions

1. Count vowels/consonants in O(n).
2. Word count ke edge cases kya hain?
3. Reverse string using extra and two-pointer methods compare karo.
4. Reverse words using stack explain karo.
5. Reverse + reverse-each-word trick ka dry run do.
