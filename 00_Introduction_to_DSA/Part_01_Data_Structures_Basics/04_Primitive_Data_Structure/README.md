# PRIMITIVE DATA STRUCTURE

- Primitive data structures are **built-in types** (int, char, float, double, bool, long, void) directly supported by hardware/CPU — each holds one fixed-size value.
- Choose by **range**: `int` ~±2.1e9, `long`/`long long` up to ~9.2e18, so pick bigger types when numbers can grow.
- **int division truncates**; always `(double)a / b` to keep decimals — mixing ints silently drops fractions.
- **Float is approximate**: `0.1f + 0.2f` ≠ `0.3` exactly; never store money in float, prefer double. `char` can hold letters AND digits, and `bool` treats any non-zero number as `true`.
- Overflow wraps around (`UINT_MAX + 1 == 0`) — that's why 10^9 × 10^9 needs `long long`, not `int`.

**Real-world analogy:** Primitive types are standard-size bowls in a kitchen: a shot glass (bool/char), a coffee mug (int), a big pot (long/double). Tiny bowls overflow when given too much, and eyeballing liquids in a shot glass loses accuracy — same as float vs double.

## Files in this folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Sizes, ranges and 3 edge cases (overflow wrap, float/double precision loss, bool conversion) all demonstrated in one compiling program. |
| `task.cpp` | 6 problems (EASY → HARD): sizeof report, int vs double division, char vowel/cons/digit, overflow with long long, leap year with bool, float 0.1×10 trap. Solutions inside. |
| `README.md` | Summary, cheat-sheet, type table, mistakes and interview Q&A. |

## Concept cheat sheet

```cpp
// size & range
cout << sizeof(int) << " bytes\n";          // 4
cout << INT_MAX << " " << INT_MIN << "\n";  // climits

// avoid integer division trap
double q = (double)a / b;                   // cast FIRST, then divide

// char holds letters and digits
char c; cin >> c;  if (c >= '0' && c <= '9') ...

// overflow-safe multiplication
long long p = (long long)a * b;             // not int p = a * b;

// bool from an expression
bool leap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);

// precision check
cout << setprecision(20) << (0.1f + 0.2f) << "\n";  // 0.30000001192...
```

## Type reference table

| Type | Size | Range | Best for |
|------|------|-------|----------|
| `bool` | 1 B | true/false | flags, ON/OFF |
| `char` | 1 B | -128..127 | single letters, codes |
| `short` | 2 B | -32768..32767 | small counters |
| `int` | 4 B | ~±2.1e9 | everyday counting |
| `long`/`long long` | 8 B (long = 4 on Windows/MinGW) | ~±9.2e18 (or int range for a 4-byte long) | big numbers, 10^18 products |
| `float` | 4 B | ~±3.4e38, 7 digits | quick approx decimals |
| `double` | 8 B | ~±1.7e308, 15 digits | money, exact decimals |
| `void` | — | no value | function return type |

## ⚠️ Common mistakes

- Using `int` for products that exceed ±2.1e9 → silent overflow wrap.
- Integer division `a / b` on ints drops the decimal part — cast to `double` first.
- Storing money/prices in `float` → accumulated rounding errors in totals.
- Testing `f == 0.3` for floats — never compare floats with `==`; use a tolerance like `abs(x - 0.3) < 1e-9`.
- Forgetting that `char` can hold digits and that `bool` treats every non-zero as true.
- Assuming `sizeof` is a runtime function — it resolves at compile time at zero runtime cost.

## Interview Q&A

- **Q: What is a primitive data type?** A: A built-in, fixed-size type the hardware executes directly (int, char, float, double, bool...).
- **Q: Why is `0.1 + 0.2` not equal to `0.3` in C++?** A: 0.1 cannot be represented exactly in binary, so floating point stores an approximation and arithmetic accumulates the error.
- **Q: What happens on integer overflow?** A: The value wraps around modulo 2^n (e.g. `UINT_MAX + 1` becomes 0) — undefined/inconsistent for signed int.
- **Q: int vs double division?** A: `a / b` with both ints truncates; casting one operand to double first keeps the fraction.
- **Q: When would you choose long long over int?** A: When products or sums can exceed ±2.1e9 — the safe range of int.