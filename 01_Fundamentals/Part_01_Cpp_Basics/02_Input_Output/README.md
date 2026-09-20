# Input and Output (cin, cout, Formatting)

`cin` reads data from the keyboard into variables, `cout` prints data to the console. Together they form the communication channel between the program and the user. Formatting tools (`setw`, `setprecision`, `fixed`) make output readable and professional — like a well-formatted report card.

**Real-world analogy:** The program is a waiter taking a food order. `cout` is the menu shown to the customer, `cin` is the waiter listening to what they say (stopping at each pause/space), and formatted output (`setw`) is writing the bill neatly in aligned columns so it's easy to read.

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + compile-ready demo: cin/cout, endl vs \n, input buffer diagram, setw/setprecision, getline + buffer pitfall |
| `task.cpp` | 5 practice tasks (numbers, personal form, interest, banner, report card) with hints, starter code, and full solutions |
| `README.md` | This file — summary, cheat sheet, complexity, common mistakes, interview Q&A |

## Cheat Sheet / Syntax Table

```cpp
#include <iostream>
#include <iomanip>     // for setw, setprecision, fixed, setfill
#include <string>

// Basic input / output
int age;
cin >> age;            // reads integer — stops at whitespace
cout << "Age: " << age << endl;   // prints, then newline + flush

// Multiple reads at once
int a, b, c;
cin >> a >> b >> c;

// String with spaces
string line;
cin.ignore();          // eat leftover '\n' from previous cin >>
getline(cin, line);    // reads ENTIRE line including spaces

// Formatted output
double m = 85.56789;
cout << fixed << setprecision(2) << m;   // 85.57
cout << setw(10) << left << "Name";      // 10-char column, left-aligned
cout << setw(10) << right << 42;         // 10-char column, right-aligned
cout << setfill('*') << setw(8) << 123;  // '******123' style padding
```

## Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Single cin / cout | O(1) per fixed-size operation | O(1) |
| Reading a string of length L | O(L) | O(L) |
| Looped output of N items | O(N) | O(1) |

**Derivation:** each formatted output is proportional to the number of characters written; a single variable is fixed-size, so it is O(1). Reading a string with `getline` costs O(L) where L is the string length.

## Common Mistakes

1. **Same name collisions:** Don't name variables `int` etc. (fine here, but avoid reserved words).
2. **cin skips spaces:** `cin >> name` fails when name has spaces — use `getline`.
3. **getline after cin>>:** A leftover `\n` makes `getline` read an empty line — always `cin.ignore()` first.
4. **endl vs "\n":** `endl` flushes the buffer (slow in loops). Use `"\n"` for performance.
5. **Integer division in average:** `sum/3` truncates decimals — use `sum/3.0`.
6. **setprecision misuse:** without `fixed`, precision counts the total significant digits, not decimals after the point.
7. **setw only affects next output:** every value you want padded needs its own `setw`.

## Interview Q&A

**Q1: Difference between `endl` and `"\n"`?**
A: Both create a newline, but `endl` also flushes the output buffer immediately (slower), while `"\n"` does not. In performance-critical loops use `"\n"`; use `endl` when you need output to appear immediately (debugging).

**Q2: Why does `getline` sometimes skip the first line?**
A: After `cin >> age`, the Enter key's `\n` stays in the buffer. `getline` reads that newline as an empty line. Solution: call `cin.ignore();` before `getline`.

**Q3: How do you read a value with spaces from the user?**
A: Use `getline(cin, str)` instead of `cin >> str`, since `cin >>` stops at the first whitespace. Ensure you flush leftover newlines with `cin.ignore()` first.