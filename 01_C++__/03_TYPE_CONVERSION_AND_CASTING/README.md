# Type Conversion and Casting

Path:

`DSA_JOURNEY/01_C++__/03_TYPE_CONVERSION_AND_CASTING/`

## Prerequisites

You should already understand:

- variables
- initialization and assignment
- `int`
- `long long`
- `float`
- `double`
- `char`
- `bool`
- `const`
- literals
- `sizeof`
- integer overflow basics

Now we study what happens when a value represented by one type needs to become another type.

---

# 1. Why Type Conversion Exists

Consider:

```cpp
int whole = 10;
double decimal = whole;
```

`whole` is an `int`.

`decimal` is a `double`.

Yet C++ allows the assignment.

Conceptually:

```text
int value
   |
   | conversion
   v
double value
```

Programs constantly combine values of different types, so conversions are unavoidable.

Examples include:

```text
int -> double
double -> int
char -> int
bool -> int
int -> long long
float -> double
```

Understanding these conversions is critical because some preserve information while others lose information.

---

# 2. Real-World Analogy: Different Containers

Imagine pouring 250 milliliters of water into a 1-liter container.

Everything fits.

That resembles a conversion where the destination can represent the source value without loss.

Now imagine trying to pour 1 liter into a 250-milliliter container.

Some information cannot fit.

Type conversions can have the same problem.

```text
larger/richer representation
          |
          v
smaller/restricted representation
          |
          v
possible information loss
```

The analogy is imperfect because numeric type ranges and precision do not form one simple "container size" ordering, but it captures the danger: changing representation can lose information.

---

# 3. Implicit Conversion

An implicit conversion is performed automatically by the language when required.

Example:

```cpp
int x = 10;
double y = x;
```

We did not explicitly request a cast.

C++ converts `x` to `double`.

Conceptually:

```text
x
int: 10
   |
   v
conversion
   |
   v
double: 10.0
```

This particular value can normally be represented exactly by `double`.

---

# 4. Explicit Conversion

Sometimes we explicitly ask for a conversion.

Modern C++ provides named casts such as:

```cpp
static_cast<int>(value)
```

Example:

```cpp
double price = 19.75;

int whole = static_cast<int>(price);
```

Result:

```text
whole = 19
```

The fractional part is discarded.

This does not round to the nearest integer.

For finite floating-point values whose integer part is representable in the destination, floating-to-integer conversion truncates toward zero.

Examples:

```text
 19.75 ->  19
-19.75 -> -19
```

---

# 5. Conversion vs Cast

The terms are related but slightly different.

A conversion is the actual change from one type to another.

A cast is syntax used to explicitly request a conversion.

For example:

```cpp
double x = 4.9;
int y = static_cast<int>(x);
```

The cast expression is:

```cpp
static_cast<int>(x)
```

The resulting operation performs a conversion from `double` to `int`.

---

# 6. int to double

Example:

```cpp
int x = 25;
double y = x;
```

Result:

```text
x = 25
y = 25.0 conceptually
```

However, an important nuance exists.

A `double` cannot necessarily represent every possible large integer exactly.

On common IEEE-754 systems, `double` has enough precision to represent all integers exactly only up to a certain magnitude.

Therefore:

```text
int -> double
```

is often safe for ordinary 32-bit `int` values on common systems, but the broader rule is:

Do not assume every integer-to-floating conversion is exact for every source integer type/value.

---

# 7. double to int

Example:

```cpp
double x = 8.9;
int y = x;
```

`y` becomes:

```text
8
```

The fractional part is discarded.

Another example:

```cpp
double x = -8.9;
int y = x;
```

Result:

```text
-8
```

This is truncation toward zero.

Real-world analogy:

Suppose a ticket system only stores whole completed kilometers.

If the measured value is:

```text
8.9
```

and the system merely discards the fractional component, it stores:

```text
8
```

It does not automatically round.

---

# 8. Dangerous Floating-to-Integer Conversion

If a finite floating-point value's truncated result cannot be represented by the destination integer type, the behavior is undefined.

Therefore this is not a safe way to handle arbitrary huge values:

```cpp
double huge = 1e100;
int x = static_cast<int>(huge);
```

Always ensure the value lies in an acceptable range before performing such conversions when input can be uncontrolled.

Range checking itself will become easier after learning operators and conditionals.

---

# 9. float to double

Example:

```cpp
float f = 1.5f;
double d = f;
```

A `double` can represent every value of many common `float` implementations exactly, and the language conversion is generally a widening floating-point conversion.

But remember an important detail:

If the original decimal literal was already rounded when stored in `float`, converting that `float` to `double` does not magically recover the lost decimal precision.

Example:

```cpp
float f = 0.1f;
double d = f;
```

`d` stores the floating-point value that `f` had, represented as a `double`.

It does not become the same value as if we had written:

```cpp
double d = 0.1;
```

---

# 10. double to float

Example:

```cpp
double d = 3.141592653589793;
float f = d;
```

A `float` generally has less precision and often a smaller range.

Information may be lost.

This is a narrowing conversion conceptually.

Use the destination type intentionally.

---

# 11. Integral Promotions

Certain small integer types are promoted during many expressions.

Examples include:

```text
bool
char
signed char
unsigned char
short
unsigned short
```

They are commonly promoted to `int` if `int` can represent all values of the original type; otherwise another unsigned integer type may be involved according to the rules.

For beginner DSA, the most visible example involves `char`.

```cpp
char c = 'A';

cout << static_cast<int>(c);
```

On ASCII-compatible systems:

```text
65
```

`char` participates in integer arithmetic because it is an integer type.

---

# 12. char and int

Characters are stored as numeric character codes.

Example:

```cpp
char c = 'A';
int code = c;
```

On ASCII-compatible systems:

```text
code = 65
```

Similarly:

```cpp
char digit = '7';
```

The character `'7'` is not numerically equal to integer `7`.

On ASCII-compatible systems:

```text
'7' -> 55
7   -> integer 7
```

This distinction becomes extremely important in string algorithms.

---

# 13. Character Digit to Integer Digit

Suppose:

```cpp
char digit = '7';
```

A common technique is:

```cpp
int value = digit - '0';
```

Why?

On the execution character set used by C++, decimal digit characters are guaranteed to have consecutive codes.

Therefore:

```text
'7' - '0' = 7
```

This is not merely an ASCII trick; the decimal digit characters are required to be contiguous.

We have not formally learned arithmetic operators yet, so treat this as a preview.

---

# 14. Integer Digit to Character Digit

The reverse pattern is:

```cpp
int value = 7;
char digit = static_cast<char>('0' + value);
```

provided `value` is between `0` and `9`.

Result:

```text
'7'
```

Again, we will revisit this after operators.

---

# 15. bool Conversions

Numeric values can be converted to `bool`.

Zero becomes:

```text
false
```

A nonzero numeric value becomes:

```text
true
```

Examples:

```cpp
bool a = 0;    // false
bool b = 1;    // true
bool c = -5;   // true
```

Converting `bool` to an integer type produces:

```text
false -> 0
true  -> 1
```

---

# 16. Usual Arithmetic Conversions

When arithmetic combines different numeric types, C++ applies rules to find a common type for the operation.

Example:

```cpp
int a = 5;
double b = 2.0;

auto result = a + b;
```

Conceptually:

```text
a: int
  |
  v
converted to double
  |
  + b: double
  |
  v
double result
```

The exact language rules are detailed and include:

- lvalue-to-rvalue conversions
- integral promotions
- floating-point conversion rank
- integer conversion rank
- signed/unsigned interactions

You do not need to memorize the complete standard wording yet.

For early DSA, the important rule is:

Pay attention to the types of the operands before an operation happens.

---

# 17. The Classic Integer Division Problem

Consider:

```cpp
int a = 5;
int b = 2;

double result = a / b;
```

A beginner might expect:

```text
2.5
```

But the division is performed using the operand types first.

Both operands are integers.

Therefore integer division happens first:

```text
5 / 2 -> 2
```

Only afterward is `2` converted to `double`:

```text
2 -> 2.0
```

Final result:

```text
2.0
```

The destination type does not travel backward in time and change how the earlier expression was evaluated.

This is one of the most important ideas in this folder.

---

# 18. Correct Floating-Point Division

We need at least one operand to be floating-point before division.

Example:

```cpp
double result =
    static_cast<double>(a) / b;
```

Conceptually:

```text
a
int 5
 |
 v
double 5.0

5.0 / 2
    |
    v
2.5
```

Another possibility:

```cpp
double result = 1.0 * a / b;
```

But an explicit cast often expresses the intent more clearly.

We will study division properly in the operators folder.

---

# 19. Full Dry Run: Integer Division

Code:

```cpp
int a = 7;
int b = 2;

double result = a / b;
```

Step 1:

```text
a = 7
b = 2
```

Step 2:

```text
evaluate a / b

operand types:
a -> int
b -> int
```

Step 3:

```text
integer division:

7 / 2 = 3
```

Step 4:

```text
result has type double

3 -> 3.0
```

Final:

```text
a      = 7
b      = 2
result = 3.0
```

Not:

```text
3.5
```

---

# 20. Full Dry Run: Cast Before Division

Code:

```cpp
int a = 7;
int b = 2;

double result =
    static_cast<double>(a) / b;
```

Step 1:

```text
a = 7
b = 2
```

Step 2:

```text
static_cast<double>(a)

7 -> 7.0
```

Step 3:

```text
7.0 / 2
```

Because one operand is `double`, the other is converted appropriately for the operation:

```text
2 -> 2.0
```

Step 4:

```text
7.0 / 2.0 = 3.5
```

Final:

```text
result = 3.5
```

---

# 21. Narrowing

Narrowing means a conversion that can lose information or otherwise cannot preserve the source value in the destination representation.

Examples include:

```text
double -> int
long long -> int
double -> float
```

depending on the value.

Example:

```cpp
double x = 3.9;
int y = x;
```

Information is lost:

```text
3.9 -> 3
```

Another example:

```cpp
long long big = 5'000'000'000LL;
int small = big;
```

A typical 32-bit `int` cannot represent the source value.

The result of conversion to a signed integer type when the source integer value is not representable is defined by modern C++ in terms of the unique value congruent modulo 2^N for the destination width in C++20; however, this roadmap uses C++17, where behavior for out-of-range conversion to a signed integer type is implementation-defined.

The practical DSA rule is simpler:

Do not intentionally rely on out-of-range narrowing conversions.

---

# 22. Brace Initialization Helps Detect Narrowing

Consider:

```cpp
double pi = 3.14;
int x{pi};
```

This is rejected because list initialization prohibits this narrowing conversion.

Likewise:

```cpp
int x{3.14};
```

does not compile.

Compare:

```cpp
int x = 3.14;
```

which permits the conversion and produces `3`.

This is one reason brace initialization can be useful.

It can catch accidental information loss at compile time.

---

# 23. static_cast

For ordinary explicit numeric conversions, prefer:

```cpp
static_cast<T>(value)
```

Example:

```cpp
double x = 9.8;

int y = static_cast<int>(x);
```

Benefits:

- clearly visible
- explicitly states destination type
- checked according to the rules of `static_cast`
- easier to search for in code
- preferable to old C-style casts in modern C++ code

---

# 24. C-Style Casts

You may see:

```cpp
int x = (int)value;
```

This is a C-style cast.

It works in many situations, but modern C++ generally prefers named casts because they communicate what kind of conversion is intended.

Prefer:

```cpp
static_cast<int>(value)
```

over:

```cpp
(int)value
```

for ordinary numeric conversions.

---

# 25. Functional-Style Casts

You may also encounter:

```cpp
int(value)
```

Example:

```cpp
double x = 5.8;
int y = int(x);
```

This can perform conversion/construction using function-style syntax.

For educational clarity when an explicit conversion is intended, we will generally write:

```cpp
static_cast<int>(x)
```

---

# 26. reinterpret_cast

C++ has another cast:

```cpp
reinterpret_cast
```

It is intended for certain low-level reinterpretation operations.

It is not a numeric conversion tool for ordinary DSA arithmetic.

Example contexts involve pointer/integer representation and low-level interfaces.

Do not use `reinterpret_cast` simply because you want to convert `double` to `int`.

Use:

```cpp
static_cast<int>(value)
```

for that purpose.

We will understand low-level pointer-related casts much later.

---

# 27. const_cast

`const_cast` can add or remove certain `const`/`volatile` qualifications.

Example syntax:

```cpp
const_cast<T>(expression)
```

This is not needed for ordinary numeric conversion.

More importantly, removing constness does not make an originally `const` object safe to modify; attempting to modify an object that was actually defined as `const` through such a path results in undefined behavior.

You do not need `const_cast` in beginner DSA.

---

# 28. dynamic_cast

`dynamic_cast` is primarily associated with safe runtime-checked conversions in polymorphic class hierarchies.

That requires object-oriented concepts that come much later.

Example idea:

```text
base-class pointer
       |
       v
checked conversion
       |
       v
derived-class pointer
```

We will revisit this during polymorphism.

For now:

```text
numeric conversion -> static_cast
```

is the important connection.

---

# 29. The Four Named C++ Casts

Modern C++ provides:

```text
static_cast
dynamic_cast
const_cast
reinterpret_cast
```

At your current level:

```text
static_cast
```

is the important one.

The other three should not be used merely as alternatives to one another; they represent very different categories of operation.

---

# 30. long long Promotion in DSA

Recall:

```cpp
int a = 100000;
int b = 100000;

long long result = a * b;
```

This is dangerous.

Why?

Step-by-step:

```text
a -> int
b -> int

a * b
performed as int first
```

Only after the multiplication would the result be assigned to `long long`.

If the int multiplication overflows, using a `long long` destination does not repair it.

Correct:

```cpp
long long result = 1LL * a * b;
```

Dry run:

```text
1LL -> long long

1LL * a
    |
    v
long long arithmetic

then multiply by b
    |
    v
long long result
```

This pattern appears constantly in DSA.

---

# 31. Assignment Conversion

The right side is evaluated first.

Then its result is converted as needed for assignment to the left side.

Example:

```cpp
double d = 8.75;
int x;

x = d;
```

Conceptually:

```text
evaluate d
   |
8.75
   |
convert to int
   |
8
   |
assign to x
```

Final:

```text
x = 8
```

---

# 32. Initialization Conversion

Similarly:

```cpp
double d = 8.75;
int x = d;
```

The initializer is converted to the destination type.

Final:

```text
x = 8
```

But:

```cpp
int x{d};
```

is rejected because list initialization prohibits that narrowing conversion.

---

# 33. auto and Conversion

Consider:

```cpp
auto x = 5;
```

`x` becomes an `int`.

Consider:

```cpp
auto y = 5.0;
```

`y` becomes a `double`.

Consider:

```cpp
auto z = static_cast<double>(5);
```

`z` becomes a `double`.

`auto` deduces from the expression after conversions inherent in that expression.

It does not mean that the variable changes type later.

---

# 34. Conversion Does Not Change the Original Object

Example:

```cpp
double d = 5.9;

int x = static_cast<int>(d);
```

After the cast:

```text
d = 5.9
x = 5
```

`static_cast<int>(d)` produces a converted value.

It does not modify `d`.

Real-world analogy:

Converting a temperature reading from Celsius into another representation does not rewrite the original measurement written in your notebook. You produced a new representation.

---

# 35. Common Interview Mistakes

## 1. Integer division before double assignment

Wrong expectation:

```cpp
double x = 5 / 2;
```

Actual value:

```text
2.0
```

Use:

```cpp
double x =
    static_cast<double>(5) / 2;
```

## 2. Assuming a long long destination fixes int overflow

Dangerous:

```cpp
long long x = a * b;
```

when `a` and `b` are `int`.

Use:

```cpp
long long x = 1LL * a * b;
```

when wider arithmetic is required.

## 3. Assuming double-to-int rounds

```cpp
static_cast<int>(4.9)
```

gives:

```text
4
```

not `5`.

## 4. Forgetting negative truncation direction

```cpp
static_cast<int>(-4.9)
```

produces:

```text
-4
```

Truncation is toward zero.

## 5. Confusing `'5'` and `5`

```text
'5' -> character
5   -> integer
```

They are different values/types.

## 6. Using C-style casts everywhere

Prefer intent-revealing modern C++ casts such as:

```cpp
static_cast<int>(x)
```

for ordinary numeric conversions.

## 7. Believing widening always means exact

Integer-to-floating conversions may lose precision for sufficiently large integer values.

## 8. Ignoring signed/unsigned conversion rules

Mixed signed/unsigned expressions can produce surprising results.

## 9. Casting without checking range

A cast does not magically make an invalid mathematical value representable by the destination type.

## 10. Using casts to hide compiler warnings

A cast should express a conversion you understand, not silence the compiler without reasoning about correctness.

---

# 36. Complexity

Primitive numeric conversions are treated as constant-time operations in standard DSA complexity analysis.

| Operation | Time | Auxiliary Space |
|---|---:|---:|
| `int -> double` | O(1) | O(1) |
| `double -> int` | O(1) | O(1) |
| `char -> int` | O(1) | O(1) |
| `int -> char` | O(1) | O(1) |
| `bool -> int` | O(1) | O(1) |
| `static_cast` for scalar numeric values | O(1) | O(1) |
| Integral promotion | O(1) | O(1) |

These are algorithmic complexity models, not processor-cycle guarantees.

---

# 37. Practice Questions

Some of these use operations formally covered in upcoming folders. Bookmark anything that uses unfamiliar syntax.

1. HackerRank — Basic Data Types  
   https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

2. LeetCode 2469 — Convert the Temperature  
   https://leetcode.com/problems/convert-the-temperature/

3. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

4. GFG — Type Conversion in C++  
   https://www.geeksforgeeks.org/type-conversion-in-c/

5. GFG — Type Casting in C++  
   https://www.geeksforgeeks.org/type-casting-in-c/

---

# 38. Final Mental Model

Always ask:

```text
What is the source type?
        |
        v
What is the destination/common type?
        |
        v
Is conversion implicit or explicit?
        |
        v
Can information be lost?
        |
        v
Does an operation happen BEFORE assignment?
```

That final question prevents many DSA bugs.

For:

```cpp
long long answer = a * b;
```

do not only inspect:

```text
answer -> long long
```

Inspect:

```text
a * b -> what type is this expression?
```

The expression is evaluated before assignment.

That distinction will matter throughout your entire C++ journey.

---

# What's Next

`01_C++__/04_INPUT_OUTPUT/`

Next we learn how programs receive values from users/judges using `cin`, how output formatting works, how whitespace affects input, and how competitive-programming I/O is handled.
