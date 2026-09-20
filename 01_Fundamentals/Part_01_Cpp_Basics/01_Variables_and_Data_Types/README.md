# Variables and Data Types

A **variable** is a named memory location that stores a value. **Data types** determine how much memory is allocated and what kind of data (integer, character, decimal, boolean) can be stored. Choosing the right data type is the first step in writing efficient and bug-free programs.

**Real-world analogy:** A variable is like a labeled box in a warehouse — the label is the variable name, the box size depends on the data type (int gets a big box, char gets a small one), and the content is the value you put inside.

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + compile-ready demo: variable declaration, data types, sizeof, ranges, ASCII, overflow |
| `task.cpp` | 5 practice tasks (swap, size report, area, temperature, Caesar cipher) with hints, starter code, and full solutions |
| `README.md` | This file — summary, cheat sheet, complexity, common mistakes, interview Q&A |

## Cheat Sheet / Syntax Table

```cpp
// Declaration and Initialization
int age = 21;              // whole number
double pi = 3.14159;       // high-precision decimal
float price = 9.99f;       // single-precision decimal (f suffix)
char grade = 'A';          // single character (1 byte)
bool is_active = true;     // true or false (1 byte)
long long big = 9e18;      // very large integer

// sizeof — check size at compile time
cout << sizeof(int);       // 4
cout << sizeof(char);      // 1

// Type modifiers
unsigned int pos = 42;     // only non-negative values
long long huge = 1e18;     // 8-byte integer

// ASCII relationship
char ch = 'A';             // stored as 65
int val = (int)ch;         // val = 65
char back = (char)66;      // back = 'B'

// Min/Max ranges (include <climits> and <cfloat>)
#include <climits>
INT_MIN   // -2147483648
INT_MAX   //  2147483647
LLONG_MAX //  9223372036854775807
```

## Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Variable declaration | O(1) | O(1) per variable |
| sizeof check | O(1) | O(1) |
| Arithmetic on primitives | O(1) | O(1) |

All variable operations are constant-time and constant-space since they involve single CPU instructions on fixed-size memory.

## Common Mistakes

1. **Integer overflow:** `int a = 2147483647; a = a + 1;` → wraps to negative. Use `long long` for large values.
2. **Integer division:** `9/5 = 1` (not 1.8). Use `9.0/5.0` for decimal result.
3. **Float precision loss:** `float f = 0.1 + 0.2;` may NOT equal `0.3` exactly. Use `double` when precision matters.
4. **Uninitialized variables:** `int x; cout << x;` → garbage value. Always initialize.
5. **Wrong data type:** Using `int` for currency causes rounding errors. Use `double` or dedicated libraries.
6. **char arithmetic without casting:** Mixing char and int can produce unexpected ASCII results.

## Interview Q&A

**Q1: What is the difference between `int` and `long long`?**
A: `int` is typically 4 bytes (range ±2.1 billion), while `long long` is 8 bytes (range ±9.2×10¹⁸). Use `long long` when values may exceed 2 billion, such as in competitive programming or large summations.

**Q2: Why does `float` lose precision compared to `double`?**
A: `float` uses 32 bits (23 bits for mantissa → ~7 decimal digits), while `double` uses 64 bits (52 bits for mantissa → ~15 decimal digits). For financial or scientific calculations requiring high accuracy, `double` is preferred.

**Q3: What happens when you add 1 to `INT_MAX`?**
A: Signed integer overflow is **undefined behavior** in C++. In practice on most compilers, it wraps around to `INT_MIN` (-2147483648). Always check bounds before arithmetic to avoid bugs.
