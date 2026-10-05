# Variables and Data Types

Path:

`DSA_JOURNEY/01_C++__/02_VARIABLES_AND_DATA_TYPES/`

## Prerequisites

From the previous folder, you should understand:

- basic C++ program structure
- `#include <iostream>`
- `main()`
- statements and semicolons
- `cout`
- `std`
- compilation vs execution
- comments
- escape sequences

This folder introduces one of the most fundamental ideas in programming: storing and representing data.

---

# 1. Why Do Programs Need Data?

The program from the previous folder could print fixed text:

```cpp
cout << "Hello\n";
```

But useful programs need to remember information.

Examples include:

```text
player score
student age
bank balance
temperature
number of elements
graph edge weight
array index
character in a string
true/false state
```

A program therefore needs places where values can be stored and manipulated.

That brings us to variables.

---

# 2. What Is a Variable?

A variable is a named object that stores a value of some type.

Example:

```cpp
int age = 20;
```

There are three important pieces:

```text
int     age     = 20;
 |       |        |
type    name     value
```

`int` tells C++ what type of value the object stores.

`age` is the name we use to refer to the object.

`20` is the initial value.

---

# 3. Real-World Analogy: Labeled Containers

Imagine a collection of labeled containers:

```text
+-----------+
| age       |
|    20     |
+-----------+

+-----------+
| score     |
|    95     |
+-----------+
```

A variable behaves somewhat like a labeled storage location.

The label lets us refer to it:

```cpp
cout << age;
```

We can also replace its stored value:

```cpp
age = 21;
```

Now:

```text
age
 |
 v
+------+
|  21  |
+------+
```

The analogy is useful, but remember that C++ variables are language-level objects with types, storage duration, lifetime, and other rules that we will gradually study.

---

# 4. Declaration

A declaration introduces a name and tells the compiler its type.

Example:

```cpp
int score;
```

This declares `score` as an integer.

General form:

```text
type variableName;
```

Examples:

```cpp
int age;
double price;
char grade;
bool passed;
```

At this point, local fundamental-type variables such as:

```cpp
int age;
```

are not automatically assigned a useful value.

Reading an uninitialized local variable can lead to undefined behavior.

Do not do this:

```cpp
int age;
cout << age;
```

Instead, initialize variables before reading them.

---

# 5. Initialization

Initialization gives an object its initial value.

Example:

```cpp
int age = 20;
```

The variable begins life with the value `20`.

Other valid initialization styles include:

```cpp
int a = 10;
int b(20);
int c{30};
```

C++ also supports:

```cpp
int d{};
```

This value-initializes `d`; for `int`, the resulting value is `0`.

For beginner code, you will frequently see:

```cpp
int x = 10;
```

and:

```cpp
int x{10};
```

Brace initialization is especially useful because it rejects many narrowing conversions.

Example:

```cpp
int x{3.9};
```

is ill-formed because information would be lost.

---

# 6. Assignment

Initialization and assignment are related but different concepts.

Initialization:

```cpp
int score = 50;
```

The object is being created with its initial value.

Assignment:

```cpp
score = 80;
```

The object already exists and its value is replaced.

Dry run:

```text
int score = 50;

score
+------+
|  50  |
+------+

score = 80;

score
+------+
|  80  |
+------+
```

This distinction becomes increasingly important later in C++.

---

# 7. Variables Can Change

Example:

```cpp
int level = 1;

cout << level << '\n';

level = 2;

cout << level << '\n';
```

Output:

```text
1
2
```

Step-by-step:

```text
Step 1:
level = 1

Step 2:
print level
output = 1

Step 3:
level = 2

Step 4:
print level
output =
1
2
```

The name remains the same while the stored value changes.

---

# 8. What Is a Data Type?

A data type describes what kind of information a value represents and determines which operations and representations are available.

Consider:

```cpp
20
```

This can represent an integer.

Consider:

```cpp
20.5
```

This requires a type capable of representing a fractional value.

Consider:

```cpp
'A'
```

This is a character literal.

Consider:

```cpp
true
```

This is a Boolean value.

C++ has different types because different categories of data have different representations and semantics.

---

# 9. Fundamental Types We Need First

The important beginner types include:

```text
int
long long
float
double
char
bool
```

There are additional fundamental types and modifiers in C++, but these are the ones you will use constantly during early DSA.

---

# 10. int

`int` stores integer values.

Examples:

```cpp
int age = 20;
int score = 95;
int temperature = -5;
int zero = 0;
```

An integer has no fractional part.

Wrong idea:

```cpp
int price = 19.99;
```

This conversion can discard the fractional portion, giving `19` on normal implementations under the relevant floating-to-integer conversion rules.

That is probably not what was intended.

Use a floating-point type for fractional values.

---

# 11. How Large Is int?

The C++ standard specifies minimum ranges, not one universal byte size for every implementation.

On most modern competitive-programming systems:

```text
sizeof(int) = 4 bytes
```

and a typical signed 32-bit `int` range is:

```text
-2,147,483,648
to
 2,147,483,647
```

However, portable C++ code should not assume every implementation uses exactly that representation unless the environment guarantees it.

We can ask the compiler:

```cpp
cout << sizeof(int);
```

`sizeof` returns the amount of storage occupied by the type in bytes, where a C++ byte is `sizeof(char)` by definition.

---

# 12. long long

When values may exceed the range commonly provided by `int`, DSA code often uses:

```cpp
long long
```

Example:

```cpp
long long population = 8000000000LL;
```

On common competitive-programming implementations, `long long` is 64 bits and supports roughly:

```text
-9 × 10^18
to
 9 × 10^18
```

The standard guarantees that `long long` is at least 64 bits.

The suffix:

```text
LL
```

makes an integer literal a `long long` literal.

This is especially important when expressions themselves need to be evaluated using `long long`.

---

# 13. Integer Overflow

Consider a typical 32-bit `int` maximum:

```text
2147483647
```

Trying to calculate a mathematically larger signed integer result outside the type's representable range causes signed integer overflow.

In C++, signed integer overflow is undefined behavior.

This is more serious than simply saying "it wraps around."

Do not rely on wrapping for signed integers.

DSA example:

Suppose:

```cpp
int a = 1'000'000'000;
int b = 1'000'000'000;
int c = 1'000'000'000;
```

Then:

```cpp
a + b + c
```

mathematically equals:

```text
3,000,000,000
```

which may exceed a 32-bit `int`.

Use an appropriate wider type:

```cpp
long long sum =
    1LL * a + b + c;
```

The `1LL` promotes the arithmetic to `long long`.

Overflow is one of the most common causes of wrong answers in DSA and competitive programming.

---

# 14. Digit Separators

C++ allows apostrophes inside numeric literals for readability:

```cpp
int million = 1'000'000;
long long billion = 1'000'000'000LL;
```

The apostrophes do not change the numeric value.

They simply make long numbers easier to read.

---

# 15. float

`float` stores floating-point values.

Example:

```cpp
float temperature = 36.5f;
```

The suffix:

```text
f
```

makes the literal a `float`.

Without it:

```cpp
36.5
```

is a `double` literal.

A `float` commonly uses 32 bits and typically provides around 6-7 decimal digits of precision, though implementation details matter.

---

# 16. double

`double` is another floating-point type.

Example:

```cpp
double pi = 3.141592653589793;
```

A `double` commonly uses 64 bits and usually provides substantially more precision than `float`.

In DSA, when floating-point values are necessary, `double` is usually the default choice unless there is a specific reason to use another type.

---

# 17. Floating-Point Values Are Approximations

This is a crucial concept.

Consider:

```cpp
double x = 0.1;
```

Many decimal fractions cannot be represented exactly in binary floating-point.

Real-world analogy:

Suppose you can only measure length using a ruler marked to the nearest centimeter.

A length such as:

```text
10.347 cm
```

cannot be represented exactly using that ruler.

You choose the closest available representation.

Floating-point arithmetic works under a similar idea, although its representation is binary and much more sophisticated.

That means calculations such as:

```cpp
0.1 + 0.2
```

need not produce an internal value exactly equal to the real-number value `0.3`.

This becomes important when comparing floating-point values.

We will revisit this when we have learned operators.

---

# 18. char

`char` represents a character-sized integer type and is commonly used to store character data.

Example:

```cpp
char grade = 'A';
```

Character literals use single quotes:

```cpp
'A'
```

Strings use double quotes:

```cpp
"A"
```

These are different.

```text
'A'    character literal
"A"    string literal
```

Example:

```cpp
char symbol = '#';

cout << symbol;
```

Output:

```text
#
```

---

# 19. Characters Have Numeric Codes

Character values are represented numerically.

For commonly used ASCII-compatible execution character sets:

```text
'A' -> 65
'B' -> 66
'a' -> 97
'0' -> 48
```

Do not assume ASCII values in fully portable C++ unless your environment guarantees an ASCII-compatible encoding.

For typical DSA platforms, ASCII-compatible behavior is standard in practice.

Later, character arithmetic such as:

```cpp
c - '0'
```

will be extremely useful.

---

# 20. bool

`bool` represents Boolean values:

```cpp
true
false
```

Example:

```cpp
bool isReady = true;
bool isFinished = false;
```

Without special formatting, `cout` normally prints them as:

```text
1
0
```

Example:

```cpp
cout << true << '\n';
cout << false << '\n';
```

Output:

```text
1
0
```

With:

```cpp
cout << boolalpha;
```

they can be printed as:

```text
true
false
```

---

# 21. void

`void` represents the absence of a value in contexts such as function return types.

Later we will write functions such as:

```cpp
void greet() {
    cout << "Hello\n";
}
```

The function performs an action but does not return a value.

You cannot create an ordinary variable with type `void`:

```cpp
void x;   // invalid
```

Functions are covered properly later.

---

# 22. sizeof

The `sizeof` operator tells us the storage size of a type or object in bytes.

Example:

```cpp
cout << sizeof(int) << '\n';
cout << sizeof(double) << '\n';
```

Possible common output:

```text
4
8
```

But do not memorize these as universal guarantees.

You can also write:

```cpp
int x = 10;

cout << sizeof(x);
```

The result has type:

```cpp
size_t
```

which we will encounter more often later.

---

# 23. Signed and Unsigned Integers

Integer types can be signed or unsigned.

Example:

```cpp
signed int a = -5;
unsigned int b = 5;
```

Signed types represent negative and non-negative values.

Unsigned types represent only non-negative values and use modulo arithmetic.

For an unsigned type with `N` bits, values are represented modulo:

```text
2^N
```

This means unsigned arithmetic has defined wraparound behavior.

However, using unsigned types does not automatically solve overflow problems, and mixing signed and unsigned arithmetic can create surprising results.

For most beginner DSA problems, use:

```cpp
int
```

or:

```cpp
long long
```

unless the problem gives you a reason to use unsigned arithmetic.

---

# 24. Type Modifiers

C++ supports modifiers including:

```text
signed
unsigned
short
long
```

Examples:

```cpp
short int a;
long int b;
long long int c;
unsigned int d;
```

These affect integer type properties.

You do not need to use every combination frequently.

For DSA, the most common choices are:

```text
int
long long
```

---

# 25. const

Sometimes a value should not be changed after initialization.

Example:

```cpp
const int DAYS_IN_WEEK = 7;
```

Trying to assign another value later:

```cpp
DAYS_IN_WEEK = 8;
```

causes a compilation error.

Real-world analogy:

A variable is like a writable whiteboard.

A `const` object is more like a printed sign: you can read it, but ordinary code cannot rewrite it.

Another common style is:

```cpp
const double PI = 3.141592653589793;
```

---

# 26. Literals

A literal is a value written directly in source code.

Examples:

```cpp
10
```

integer literal.

```cpp
10LL
```

long long literal.

```cpp
3.14
```

double literal.

```cpp
3.14f
```

float literal.

```cpp
'A'
```

character literal.

```cpp
true
```

Boolean literal.

```cpp
"Hello"
```

string literal.

We will study strings later.

---

# 27. auto

Modern C++ can sometimes infer the type from an initializer.

Example:

```cpp
auto age = 20;
auto price = 9.99;
auto letter = 'A';
```

Here the compiler deduces types approximately as:

```text
age    -> int
price  -> double
letter -> char
```

`auto` does not mean "the variable has no type."

The compiler determines a concrete type at compile time.

Since this folder is about learning types explicitly, we will mostly spell out the type for now.

---

# 28. Identifier Rules

Variable names are identifiers.

Valid examples:

```cpp
age
score
studentAge
student_age
value2
_total
```

Identifiers may contain letters, digits, and underscores, subject to language rules, but they cannot begin with a digit.

Invalid:

```cpp
2value
```

Reserved C++ keywords cannot be used as variable names.

Invalid:

```cpp
int return = 5;
```

because `return` is a keyword.

Also avoid identifiers reserved to the implementation, including names with certain underscore patterns.

For ordinary code, use simple descriptive names.

---

# 29. Naming Style

Prefer meaningful names:

```cpp
int studentCount;
long long totalDistance;
double average;
bool found;
```

Weak:

```cpp
int x1;
int aaa;
int thing;
```

Short names are perfectly reasonable when their role is conventional and local.

For example, later:

```cpp
for (int i = 0; ...)
```

`i` is commonly understood as an index.

Good naming depends on context.

---

# 30. Multiple Variables

C++ allows:

```cpp
int a = 10, b = 20, c = 30;
```

But this is often clearer:

```cpp
int a = 10;
int b = 20;
int c = 30;
```

Readable code is preferable to minimizing line count.

Also be careful with declarations such as pointers later, where multiple declarations on one line can become misleading.

---

# 31. Copying Values

Consider:

```cpp
int a = 10;
int b = a;
```

At this point:

```text
a = 10
b = 10
```

Now:

```cpp
a = 50;
```

What happens to `b`?

Nothing.

State:

```text
a = 50
b = 10
```

The value of `a` was copied into `b`.

They are separate `int` objects.

This idea matters tremendously when we later study pass-by-value and references.

---

# 32. Full Dry Run: Variable State

Program:

```cpp
int score = 10;
int copy = score;

score = 25;

cout << score << ' ' << copy;
```

Initial:

```text
score does not exist yet
copy does not exist yet
```

After:

```cpp
int score = 10;
```

State:

```text
score = 10
```

After:

```cpp
int copy = score;
```

State:

```text
score = 10
copy  = 10
```

After:

```cpp
score = 25;
```

State:

```text
score = 25
copy  = 10
```

After output:

```text
25 10
```

This demonstrates value copying.

---

# 33. Scope Preview

A variable name is only usable where it is in scope.

Example:

```cpp
int main() {
    int age = 20;

    cout << age;
}
```

`age` exists as a local object associated with that block and is usable within its scope.

We will study scope, storage duration, and lifetime properly in:

```text
01_C++__/09_SCOPE_STORAGE_AND_LIFETIME/
```

For now, declare variables inside `main()`.

---

# 34. Memory Mental Model

Suppose:

```cpp
int age = 20;
double temperature = 36.5;
char grade = 'A';
```

A simplified conceptual view is:

```text
Memory

+------------------+
| age              |
| int: 20          |
+------------------+

+------------------+
| temperature      |
| double: 36.5     |
+------------------+

+------------------+
| grade            |
| char: 'A'        |
+------------------+
```

The real representation is in memory bytes, and exact layout depends on implementation details.

Later folders will study:

- addresses
- pointers
- stack and heap concepts
- dynamic memory

Do not confuse this conceptual diagram with a guarantee about physical memory layout.

---

# 35. Fixed-Width Integer Types

When an exact-width integer type is required and supported, C++ provides types through:

```cpp
#include <cstdint>
```

Examples:

```cpp
std::int32_t
std::int64_t
std::uint32_t
```

These types exist only when the implementation provides an integer type with exactly the requested width.

For ordinary DSA problems, you will generally use:

```cpp
int
long long
```

but knowing fixed-width types exist is useful.

---

# 36. Numeric Limits

Instead of manually memorizing limits, C++ provides:

```cpp
#include <limits>
```

Example:

```cpp
numeric_limits<int>::min()
numeric_limits<int>::max()
```

These tell us the actual limits for the implementation.

Example:

```cpp
cout << numeric_limits<int>::max();
```

On a typical 32-bit `int` implementation:

```text
2147483647
```

This is safer and more expressive than hard-coding assumptions.

---

# 37. Common Interview and DSA Mistakes

## Mistake 1: Using int for values that can become too large

Example:

```cpp
int sum;
```

may be wrong if the maximum possible sum exceeds `int`.

Always inspect constraints.

## Mistake 2: Thinking signed overflow safely wraps

It does not.

Signed integer overflow is undefined behavior in C++.

## Mistake 3: Multiplying ints before storing in long long

Wrong:

```cpp
int a = 100000;
int b = 100000;

long long result = a * b;
```

The multiplication itself is performed as `int` first, so overflow may occur before conversion to `long long`.

Better:

```cpp
long long result = 1LL * a * b;
```

Now the arithmetic is promoted before multiplication.

## Mistake 4: Using uninitialized local variables

Wrong:

```cpp
int x;

cout << x;
```

Initialize variables before reading them.

## Mistake 5: Confusing char and string literals

```text
'A'  -> character
"A"  -> string
```

## Mistake 6: Using float when precision matters

Prefer `double` for general floating-point DSA calculations unless requirements say otherwise.

## Mistake 7: Comparing floating-point numbers as though they were exact real numbers

Many decimal values are approximated in binary.

This will matter when we learn operators.

## Mistake 8: Assuming sizeof(int) is always 4

It commonly is, but C++ does not universally guarantee it.

## Mistake 9: Mixing signed and unsigned carelessly

Implicit conversions can produce surprising comparisons and arithmetic.

## Mistake 10: Forgetting the literal's type

If a computation must happen as `long long`, use an appropriate operand such as:

```cpp
1LL
```

---

# 38. Complexity Table

Declaring or assigning a simple scalar variable is treated as constant-time work in ordinary DSA analysis.

| Operation | Time | Auxiliary Space |
|---|---:|---:|
| Declare one scalar variable | O(1) | O(1) |
| Initialize scalar | O(1) | O(1) |
| Assign scalar | O(1) | O(1) |
| Copy `int`/`double`/`char`/`bool` | O(1) | O(1) |
| Read scalar value | O(1) | O(1) |
| `sizeof(type)` | O(1) | O(1) |

This model applies to the simple fundamental types in this folder.

Copying large containers later will be very different.

---

# 39. Practice Questions

Since input, operators, conditions, and loops have not yet been formally learned, most normal LeetCode problems are still ahead of us.

Use these for familiarity and bookmark the later problems.

1. HackerRank — C++ Data Types  
   https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

2. GFG — C++ Data Types  
   https://www.geeksforgeeks.org/cpp-data-types/

3. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

4. LeetCode 2469 — Convert the Temperature  
   https://leetcode.com/problems/convert-the-temperature/

5. GFG — Variables and Types in C++  
   https://www.geeksforgeeks.org/cpp-variables/

Problems 3 and 4 use concepts from upcoming folders. Bookmark them rather than forcing yourself to solve them before learning operators/functions.

---

# 40. Checklist Before Moving On

You should be able to explain:

```text
variable
data type
declaration
initialization
assignment
int
long long
float
double
char
bool
void
signed
unsigned
const
auto
sizeof
literals
integer overflow
floating-point approximation
identifier
copying values
```

You should also understand why:

```cpp
long long result = 1LL * a * b;
```

can be safer than:

```cpp
long long result = a * b;
```

when `a` and `b` are `int`.

---

# What's Next

`01_C++__/03_TYPE_CONVERSION_AND_CASTING/`

The next folder explains what happens when values move between different data types, including implicit conversion, narrowing, promotions, and explicit casts.
