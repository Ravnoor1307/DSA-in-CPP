# C-Style Strings (Char Arrays)

C-style strings are character arrays terminated by a null character `'\0'`. Functions from `<cstring>` (strlen, strcpy, strcat, strcmp) operate on them. Manual loops over indices or two pointers handle length, reversing, and palindrome checks without any library.

Real-world analogy: A classroom attendance register — names are written letter-by-letter in fixed boxes on paper, and a special marker at the end shows where the name stops.

## Files

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory: null terminator, cstring library, manual length/reverse/palindrome with ASCII memory layout |
| `task.cpp` | 6 tasks: manual length, toggle case, palindrome, word count, reverse words, remove consecutive duplicates |
| `README.md` | This file — summary, cheat sheet, complexity, mistakes, interview Q&A |

## Cheat Sheet

```cpp
char name[16] = "hi";          // 'h','i','\0' in memory
strlen(name);                  // 2 — does NOT count '\0'
strcpy(dst, src);              // copy src -> dst (incl '\0')
strcat(dst, src);              // append src to dst
strcmp(a, b);                  // 0 equal | <0 a<b | >0 a>b

// Manual length
int len = 0;
while (name[len] != '\0') len++;

// Palindrome: two pointers meet in the middle
int l = 0, r = len - 1;
while (l < r) { if (s[l] != s[r]) return false; l++; r--; }
```

## Complexity

| Operation | Time | Derivation |
|-----------|------|------------|
| strlen / manual length | O(N) | One pass, N characters checked |
| Reverse | O(N) | N/2 swaps, each O(1) → ~N/2 steps |
| Palindrome | O(N) | N/2 comparisons → ~N/2 steps |
| strcmp | O(N) | Worst case N character comparisons |
| strcpy | O(N) | N characters + '\0' copied |

**Space:** O(N) for the string itself. All above operations use O(1) extra space (only index variables).

## Common Mistakes

1. **Forgetting '\0'**: A char array without '\0' is NOT a string — strlen would read garbage.
2. **Buffer overflow**: `strcpy(dst, very_long_src)` when dst is small — always reserve enough space.
3. **`strcmp` equals `==`**: `if (a == b)` compares POINTERS (addresses), not contents. Use `strcmp`.
4. **Off-by-one**: `char s[5] = "hello"` needs 6 slots ('h','e','l','l','o','\0') — compile error/warning.
5. **Modifying string literals**: `char* s = "hi"; s[0]='x'` is undefined behavior. Use `char s[]`.

## Interview Q&A

**Q: Why does a C-string need '\0'?**
A: There's no length stored with char arrays. '\0' is the sentinel that marks the end so functions like strlen know where to stop.

**Q: `strlen("hi")` returns?**
A: 2. It counts characters before '\0' only.

**Q: Difference between `char s[] = "hi"` and `char* s = "hi"`?**
A: `char s[]` allocates a writable local array. `char* s` points to a string literal in read-only memory — modifying it is undefined behavior.

**Q: How to compare two C-strings?**
A: `strcmp(a, b) == 0` for equality. It compares character by character (lexicographic).