# std::string (C++ String Class)

`std::string` wraps a dynamic char buffer, auto-grows on append, and provides safe readable operations: `length()`, `+`, `==`, `substr`, `find`, `replace`, `erase`, and `getline`. It removes the manual `'\0'` and buffer-size management that C-strings require.

Real-world analogy: A text editor like Google Docs — you type, the document grows automatically, and searching / replacing words is instant and safe.

## Files

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Theory: getline vs cin, length/append/find/substr/replace/erase, memory growth diagram |
| `task.cpp` | 6 tasks: count vowels, first unique char, reverse word order, longest word, anagram, remove spaces |
| `README.md` | This file — summary, cheat sheet, complexity, mistakes, interview Q&A |

## Cheat Sheet

```cpp
#include <string>
string s = "hi";          // auto manages memory
s.length();  s.size();    // O(1) — stored, not scanned
s += " there";            // safe concatenation
s.append("!");            // same
s == "hi there!"          // compare by VALUE
s.find("ther");           // returns index or string::npos
s.substr(3, 5);           // substring from index 3, length 5
s.replace(pos, len, str); // overwrite len chars at pos
s.erase(0, 3);            // erase 3 chars at position 0

// input
getline(cin, line);       // whole line incl. spaces
cin >> word;              // stops at whitespace
```

## Complexity

| Operation | Time | Derivation |
|-----------|------|------------|
| length() / size() | O(1) | length stored as a member; no scan |
| at(i) / [i] | O(1) | direct index into buffer |
| append / += | amortized O(N) | copy N chars; rare realloc doubles capacity |
| find(sub) | O(N×M) | each position tests up to M chars |
| substr(pos,len) | O(len) | copies len characters |
| replace | O(N+M) | erase part + insert copy |
| toUpperCase via loop | O(N) | each char visited once |

**Space:** O(N) for the string. `substr` / `replace` may allocate a copy → extra O(N) temporarily.

## Common Mistakes

1. **`npos` check**: always test `if (find != string::npos)` — using the raw result without checking causes crash on index 18446744073709551615 (npos).
2. **`cin >>` vs `getline`**: `cin >> name` captures only the first word. For "Rohan Sharma" use `getline`.
3. **Mixing after `cin >>`**: `getline` after `cin >>` reads the leftover `\n` — call `cin.ignore()` first.
4. **`==` on C-strings**: works on `std::string`; for `char*` it compares addresses. Keep everything `std::string`.
5. **Off-by-one in substr**: `substr(pos, len)` — if pos+len exceeds size, it returns what's available (no crash).

## Interview Q&A

**Q: Difference between `size()` and `length()`?**
A: None for std::string — both return the same value.

**Q: What is `string::npos`?**
A: The largest possible value of `size_t` (all 1s). `find()` returns it when nothing is found. Check `!= npos` before using the index.

**Q: Does std::string store '\0'?**
A: Internally it can, but it tracks length separately, so '\0' inside a string is preserved and printed.

**Q: Is `s += c` faster than `s = s + c`?**
A: Yes. `s += c` appends in place (amortized O(1)). `s = s + c` builds a new temporary then copies — O(N) overhead.