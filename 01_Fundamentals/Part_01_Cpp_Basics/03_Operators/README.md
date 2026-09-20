# Operators

Operators are the symbols that perform computations and comparisons: arithmetic (`+ - * / %`), relational (`< > == !=`), logical (`&& || !`), assignment (`= += -=`), and more. They are the building blocks of every program's logic.

**Real-world analogy:** A shop's billing system. `+` adds prices, `%` checks if an item's quantity forms an even stack, `>` checks if total crosses a discount threshold, `&&` combines "student + festival day" conditions, and `+=` keeps the growing bill total. Prefix/postfix is like a turn counter — read the score before or after the increment.

## Files in This Folder

| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure theory + compile-ready demo: all operator groups, prefix vs postfix diagram, precedence ladder, short-circuit |
| `task.cpp` | 5 practice tasks (even/odd, mini calc, ternary max, digit reverse, scholarship) with hints, starter code, and solutions |
| `README.md` | This file — summary, cheat sheet, complexity, common mistakes, interview Q&A |

## Cheat Sheet / Syntax Table

```cpp
// Arithmetic
int q = 17 / 5;   // 3  (integer division — remainder dropped)
int r = 17 % 5;   // 2  (remainder)
// 5 * 3 + 2 == 17  → check: quotient*divisor + remainder == dividend

// Relational  → bool result
bool g = (10 > 5);   // true
bool e = (10 == 5);  // false   (== compares, = assigns!)

// Logical
bool both = (true && false);    // false
bool one  = (true || false);    // true
bool flp  = (!true);            // false
// Short-circuit: a && b  skips b if a false; a || b skips b if a true.

// Assignment / compound
int x = 10;
x += 5;   // 15       x -= 3;  // 12
x *= 2;   // 24       x /= 4;  // 6
x %= 4;   // 2

// Prefix vs Postfix
int i = 5;
int p = ++i;   // i → 6, p = 6   (increment first)
i = 5;
int q2 = i++;  // q2 = 5, i → 6  (use old value first)

// Ternary
int m = (a > b) ? a : b;   // returns larger
```

## Precedence Ladder (high → low)

```
()  []          highest
++ -- !  (unary)
*  /  %
+  -
<  <=  >  >=
==  !=
&&
||
?:
=  +=  -=  *=  /=  %=    lowest
```

## Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Any single operator | O(1) | O(1) |
| Nested ternary (fixed depth) | O(1) | O(1) |
| Compound-assignment chains | O(1) per operation | O(1) |

**Derivation:** every operator is compiled to one or a few CPU instructions on fixed-size operands, so runtime does not grow with any input size — each is constant time and constant space.

## Common Mistakes

1. **`=` vs `==`:** `if (x = 5)` ASSIGNS 5 (always true!) instead of comparing. Use `==`.
2. **Integer division:** `9/2 == 4`, not 4.5. Cast or use `9.0/2` for decimals.
3. **Prefix/postfix confusion:** `i++` inside a printf/assignment uses the OLD value; `++i` uses the NEW one.
4. **Division by zero:** Crashes at runtime; always guard `if (b != 0)`.
5. **Modulo on negative numbers:** Results can be negative in C++ (`-5 % 2 == -1`); verify expected behavior.
6. **Forgetting short-circuit:** `(x != 0) && (100/x > 5)` is safe; reversing the order causes division by zero.
7. **Bare `O(n)`:** these are O(1) ops — only answer with the derived constant-time reasoning.

## Interview Q&A

**Q1: What is the difference between prefix `++i` and postfix `i++`?**
A: Prefix increments and returns the new value (equivalent to `i += 1; return i;`). Postfix returns the old value then increments (`int tmp = i; i += 1; return tmp;`). For built-in types most compilers optimize them equally; for class objects postfix can create extra copies.

**Q2: How does short-circuit evaluation help?**
A: In `a && b`, if `a` is false, `b` is never evaluated (avoids errors and saves time). In `a || b`, if `a` is true, `b` is skipped. This lets you write safe guards like `(div != 0) && (n/div > 5)` without crashing.

**Q3: Can you swap two integers without a temporary variable?**
A: Yes, with arithmetic: `a = a + b; b = a - b; a = a - b;` — or with XOR: `a ^= b; b ^= a; a ^= b;`. The XOR version avoids potential overflow for large values.