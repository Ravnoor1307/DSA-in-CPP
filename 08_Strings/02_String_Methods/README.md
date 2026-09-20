# 02_String_Methods

## Real-world analogy summary

String methods text editor tools jaise hain: length check, copy, join, find, replace, insert, erase, compare, and traverse.

## C-string functions visual

```text
strlen("cat") -> [c][a][t][\0] -> 3
strcpy(dest, src) -> src copied including \0
strcat("hi", "!") -> "hi!"
strcmp("abc", "abc") -> 0 means equal
```

## Approach comparison table

| Method / operation | Real-world work | Calculation | Time | Space |
|---|---|---:|---:|---:|
| strlen | count until stop sign | n chars + `\0` | O(n) | O(1) |
| strcpy | copy each char | n assignments | O(n) | O(1) extra |
| strcat | find end + copy source | d+s chars | O(d+s) | O(1) extra |
| strcmp | dictionary compare | up to min(n,m) chars | O(min(n,m)) | O(1) |
| substr | selected text copy | len chars copied | O(len) | O(len) |
| find | pattern search | worst n*m checks conceptually | O(n*m) worst | O(1) |
| replace | edit text | shift/copy up to n chars | O(n) | O(n) possible |
| push_back/pop_back | end edit | fixed end op | O(1) amortized / O(1) | O(1) |
| iteration | inspect every char | n visits | O(n) | O(1) |

## Common mistakes

1. `strcmp` equal hone par 1 expect karna; correct return is 0.
2. `substr(pos,len)` me second argument end index samajhna; woh length hai.
3. `find` not found case me `string::npos` check na karna.
4. insert/erase ke shifting cost ko O(1) bolna.
5. Iterator dereference without end check.

## Interview questions

1. strlen, strcpy, strcat, strcmp explain karo.
2. strcmp equal strings ke liye kya return karta hai?
3. string `find` and `substr` ka example do.
4. `==`, `strcmp`, and `compare()` difference kya hai?
5. String iterate karne ke 3 ways batao.
