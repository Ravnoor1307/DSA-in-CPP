# 04_Palindrome_Problems

## Real-world analogy summary

Palindrome mirror-word hota hai. MADAM, RACECAR, and Nitin jaise words dono direction me same read hote hain. Spaces/case ignore karne wale phrases me non-alphanumeric skip karna hota hai.

## Approach comparison table

| Problem | Approach | Real-world analogy | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Basic palindrome | reverse + compare | mirror copy | n reverse + n compare | O(n) | O(n) |
| Basic palindrome | manual reverse string | reverse board build | n appends + compare | O(n) | O(n) |
| Basic palindrome | two pointers | compare both ends | floor(n/2) checks | O(n) | O(1) |
| Ignore case/spaces | skip + lowercase | clean mirror | each pointer crosses once | O(n) | O(1) |
| Number palindrome | number to string | number plate mirror | d digit checks | O(d) | O(d) |

## Key tricks

```text
Two pointers: left=0, right=n-1
while left < right:
    if s[left] != s[right] -> false
    left++, right--

Ignore case/spaces:
skip non-alphanumeric + compare tolower(left/right)
```

## Common mistakes

1. Case-sensitive check for "Nitin" karna and false bolna.
2. Spaces/punctuation skip na karna phrase palindrome me.
3. Two-pointer loop me pointers move na karna.
4. Negative numbers ko string palindrome incorrectly treat karna.
5. Extra-space approach ko O(1) space bolna.

## Interview questions

1. Palindrome kya hota hai?
2. MADAM and RACECAR dry run karo.
3. Reverse-compare and two-pointer methods compare karo.
4. Ignore case/spaces palindrome ka code logic batao.
5. Number palindrome string conversion se kaise check karoge?
