# Basic Data Types in C++ — Detailed Notes

## 1. What Is a Data Type?

A **data type** defines the kind of value a variable can hold and the operations that make sense for that value.

Consider a student management program:

```cpp
int age = 20;
double percentage = 87.5;
char grade = 'A';
bool passed = true;
std::string name = "Alex";
```

These variables represent different kinds of information.

- `age` stores a whole number.
- `percentage` stores a decimal number.
- `grade` stores one character.
- `passed` stores a true/false value.
- `name` stores a sequence of characters forming text.

### Analogy: Different Containers

Imagine a kitchen with different containers:

- A container for whole eggs.
- A measuring jug for liquid.
- A label holder for one letter.
- A switch that is either on or off.
- A box containing a person's name.

You could physically place the wrong thing in a container, but it might not work as intended. Data types similarly help C++ determine which values and operations are appropriate.

## 2. Why Are Data Types Important?

Data types help C++:

1. Determine how values are represented.
2. Decide which operations are permitted.
3. Detect many programming mistakes during compilation.
4. Interpret expressions correctly.
5. Manage memory for objects.
6. Represent numeric limits and precision.

For example:

```cpp
int count = 10;
double price = 19.99;
```

The two variables have different types because whole-number counts and fractional monetary values often require different representations.

Choosing a type does not automatically guarantee that a program is accurate. You must also consider range, precision, conversion, and the problem's requirements.

## 3. Main Categories of Types

| Category | Common type | Typical use |
|---|---|---|
| Integer | `int` | Counts, ages, quantities |
| Floating-point | `double` | Measurements and decimal calculations |
| Character | `char` | A character such as `'A'` |
| Boolean | `bool` | True/false conditions |
| Text | `std::string` | Names, messages, sentences |
| Integer with wider range | `long long` | Large whole-number values |

The exact range and representation of built-in types depend on the C++ implementation. Do not assume every computer uses the same sizes.

---

## 4. Integer Types

Integer types represent whole-number values, including negative numbers where the type is signed.

### 4.1 `short`

`short` is an integer type that may be useful when a smaller integer range is sufficient.

```cpp
short temperature = -5;
short numberOfStudents = 120;
```

The C++ standard guarantees a minimum range, but it does not require `short` to occupy fewer bytes than `int` on every implementation.

### 4.2 `int`

`int` is the conventional default choice for ordinary whole-number calculations.

```cpp
int age = 20;
int score = 95;
int totalStudents = 60;
```

Use `int` for typical counts and indices when its range is sufficient.

### 4.3 `long`

`long` is an integer type that may offer a wider range than `int`, depending on the implementation.

```cpp
long populationEstimate = 1000000L;
```

The `L` suffix indicates a `long` integer literal when the literal's value is representable in that type.

### 4.4 `long long`

`long long` provides a guaranteed minimum range that is at least as wide as `long`.

```cpp
long long distanceInMillimeters = 123456789012LL;
```

The `LL` suffix is commonly used to express a `long long` integer literal.

Use this type when you need a large integer range and have verified that it is appropriate for the problem.

### Important: Integer Types Do Not All Have Fixed Sizes

The following is illustrative, not a universal size table:

| Type | Minimum required size in bits |
|---|---:|
| `short` | 16 |
| `int` | 16 |
| `long` | 32 |
| `long long` | 64 |

These figures describe minimum storage widths in bits, not guaranteed byte sizes. A C++ byte is not required to contain exactly eight bits, although eight-bit bytes are standard on common platforms.

Use `sizeof` and `std::numeric_limits` to inspect your actual implementation.

---

## 5. Floating-Point Types

Floating-point types represent real-number approximations, including fractional values.

### 5.1 `float`

```cpp
float temperature = 36.5f;
float height = 1.75f;
```

A floating-point literal without a suffix, such as `36.5`, has type `double`. The `f` suffix makes the literal a `float`.

### 5.2 `double`

```cpp
double percentage = 87.65;
double bankBalance = 12500.75;
```

`double` is a common default for decimal calculations because it generally offers more precision than `float`.

### 5.3 `long double`

```cpp
long double preciseMeasurement = 123.456789L;
```

`long double` provides at least the range and precision guarantees of `double`, but its actual representation and additional precision vary by implementation. It may offer no extra precision on some systems.

### Comparison

| Type | Typical use | Key point |
|---|---|---|
| `float` | Memory-sensitive calculations | Usually less precision than `double` |
| `double` | General decimal calculations | Often the practical default |
| `long double` | When additional precision is available and needed | Implementation-dependent benefits |

### Floating-Point Precision

Many decimal fractions cannot be represented exactly in binary floating-point.

For example:

```cpp
double result = 0.1 + 0.2;
std::cout << result << '\n';
```

The result may display as `0.3`, but the stored value can be a nearby approximation.

For this reason, comparing floating-point results using exact equality can be unreliable.

```cpp
double a = 0.1 + 0.2;
double b = 0.3;

// Exact equality is not a reliable general test for
// mathematically equivalent floating-point calculations.
```

For many numerical applications, compare the difference against an appropriate tolerance instead:

```cpp
#include <cmath>

bool approximatelyEqual(double a, double b) {
    return std::abs(a - b) < 1e-9;
}
```

The tolerance must be chosen according to the scale and accuracy requirements of the problem.

### Important: Decimal Types Are Not Automatically Suitable for Money

Floating-point values can introduce rounding differences. Financial software often uses integer units such as cents or an appropriate decimal arithmetic representation, depending on the application's requirements.

---

## 6. Character Type: `char`

`char` is a built-in type used to represent a character-sized unit. It is commonly used for basic characters such as English letters and digits.

```cpp
char grade = 'A';
char initial = 'R';
char digit = '7';
char symbol = '#';
```

### Single Quotes vs Double Quotes

```cpp
char grade = 'A';
std::string name = "Alex";
```

- `'A'` is a character literal.
- `"Alex"` is a string literal.

These are not interchangeable.

```cpp
char letter = 'A';       // Correct
// char letter = "A";    // Incorrect: incompatible types
```

A `char` is not guaranteed to be signed or unsigned by default. Its signedness is implementation-dependent.

Also, a `char` is not necessarily a complete Unicode character. Text containing many international characters or emoji may require UTF-8 or other Unicode-aware handling.

---

## 7. Boolean Type: `bool`

`bool` represents logical truth values:

- `true`
- `false`

Example:

```cpp
bool isLoggedIn = true;
bool hasPassed = false;
bool isAdult = true;
```

Boolean values are commonly used in conditions.

```cpp
int age = 20;
bool isAdult = age >= 18;

std::cout << std::boolalpha;
std::cout << isAdult << '\n';
```

With `std::boolalpha`, streams display `true` and `false` rather than `1` and `0`.

Without it, printing a `bool` normally displays `1` for true and `0` for false.

### Boolean Expressions

```cpp
int score = 85;

bool passed = score >= 40;
bool perfectScore = score == 100;
bool failed = score < 40;
```

Each comparison produces a Boolean result.

### Common Mistake: Confusing `=` and `==`

```cpp
int score = 90;       // Assignment
bool isNinety = score == 90;  // Comparison
```

- `=` assigns a value.
- `==` checks equality.

---

## 8. Text with `std::string`

C++ provides `std::string` in the standard library for working with text.

Include its header:

```cpp
#include <string>
```

Example:

```cpp
std::string firstName = "Alex";
std::string city = "Ludhiana";
std::string message = "Welcome to C++!";
```

Unlike `char`, a `std::string` can contain zero, one, or many characters.

```cpp
std::string emptyText = "";
std::string oneLetter = "A";
std::string sentence = "I am learning C++.";
```

### Joining Strings

```cpp
std::string firstName = "Alex";
std::string lastName = "Sharma";

std::string fullName = firstName + " " + lastName;
```

The `+` operator concatenates strings.

### Why Not Use `char` for a Name?

A single `char` cannot directly hold an entire name. Use `std::string` for ordinary text.

---

## 9. Signed and Unsigned Integers

Integer types other than `bool` can generally be used in signed or unsigned forms.

### Signed Integers

A signed integer can represent negative values, zero, and positive values.

```cpp
int temperatureChange = -8;
int accountDifference = 150;
```

### Unsigned Integers

An unsigned integer represents zero and positive values only.

```cpp
unsigned int numberOfItems = 50;
unsigned int days = 365;
```

For standard integer types, the unsigned representation provides a nonnegative range. The exact upper bound depends on the type's width.

### Comparison

| Signed integer | Unsigned integer |
|---|---|
| Can represent negative values | Cannot represent negative values |
| Useful for quantities that may be negative | Useful when a nonnegative range is specifically required |
| Signed overflow is not safe to rely on | Arithmetic follows modular behavior for the corresponding unsigned type |

### Important: Assigning a Negative Value to an Unsigned Type

```cpp
unsigned int value = -1;
```

This does not store `-1` as a negative value. The value is converted to the unsigned type according to its conversion rules and will be a large nonnegative value.

Avoid using unsigned types merely because a quantity is expected to be positive. Signed/unsigned conversions can cause surprising comparisons and arithmetic behavior.

For example, mixing negative signed values with unsigned values can produce unexpected results due to the usual arithmetic conversions.

### Unsigned Arithmetic Wraparound

Unsigned integer arithmetic is defined modulo one more than the maximum representable value.

```cpp
unsigned int value = 0;
--value;
```

After decrementing zero, `value` becomes the maximum value of its type.

This behavior is defined for unsigned arithmetic, but it is often a bug when used unintentionally.

Signed integer overflow, by contrast, is undefined behavior in C++.

---

## 10. Inspecting Sizes with `sizeof`

The `sizeof` operator reports the size of an object or type in C++ bytes.

```cpp
std::cout << sizeof(int) << '\n';
std::cout << sizeof(double) << '\n';
std::cout << sizeof(char) << '\n';
```

The results depend on the implementation.

Important points:

- `sizeof(char)` is always `1`.
- A byte is the size of a C++ byte, not necessarily eight bits.
- `sizeof` does not directly tell you how many decimal digits a type can store.
- Two different types can have the same size.
- A type's range and precision depend on more than its size alone.

To inspect the number of bits in a byte, use:

```cpp
#include <climits>

std::cout << CHAR_BIT << '\n';
```

`CHAR_BIT` tells you how many bits are in a byte on the current implementation.

---

## 11. Inspecting Numeric Limits

The `<limits>` header provides `std::numeric_limits`.

```cpp
#include <iostream>
#include <limits>

int main() {
    std::cout << std::numeric_limits<int>::min() << '\n';
    std::cout << std::numeric_limits<int>::max() << '\n';

    std::cout << std::numeric_limits<double>::max() << '\n';
}
```

Useful members include:

| Expression | Meaning |
|---|---|
| `std::numeric_limits<int>::min()` | Lowest value for `int` |
| `std::numeric_limits<int>::max()` | Highest value for `int` |
| `std::numeric_limits<unsigned int>::max()` | Highest value for `unsigned int` |
| `std::numeric_limits<double>::max()` | Largest finite value for `double` |
| `std::numeric_limits<double>::lowest()` | Lowest finite value for `double` |
| `std::numeric_limits<double>::epsilon()` | Difference between `1.0` and the next representable value above it |

For floating-point types, `min()` has a different meaning from the integer case: it returns the smallest positive normalized value, not the most negative finite value. Use `lowest()` for the latter.

---

## 12. Choosing the Right Type

| Requirement | Reasonable starting choice |
|---|---|
| Student age | `int` |
| Number of attempts | `int` |
| Large integer total | `long long`, if its range is sufficient |
| Average score | `double` |
| Temperature with decimal values | `double` |
| One basic character | `char` |
| Passed or failed | `bool` |
| Full name | `std::string` |
| Number of elements in a container | Often `std::size_t` when matching container size APIs |

Always verify that the chosen type meets the problem's range and accuracy requirements.

### Example: Student Record

```cpp
#include <string>

int main() {
    std::string name = "Alex";
    int age = 20;
    double percentage = 87.5;
    char grade = 'A';
    bool passed = true;
}
```

This example uses each type according to the information it represents.

---

## 13. Common Mistakes

### Mistake 1: Storing Decimal Data in an Integer

```cpp
int average = 87.5;
```

The fractional part is discarded when the value is converted to `int`.

Better:

```cpp
double average = 87.5;
```

### Mistake 2: Using Double Quotes for a Character

```cpp
// char grade = "A";
char grade = 'A';
```

### Mistake 3: Assuming Every Integer Type Has the Same Range

`short`, `int`, `long`, and `long long` have different minimum requirements, but their actual widths can overlap.

### Mistake 4: Assuming `float` Is Always Sufficient

Floating-point precision may be insufficient for a calculation. Choose the type based on required accuracy.

### Mistake 5: Assuming `char` Is Always Signed

Plain `char` can be signed or unsigned depending on the implementation.

### Mistake 6: Using an Unsigned Type for Values That Can Be Negative

This can cause conversion surprises and incorrect comparisons.

### Mistake 7: Forgetting the String Header

```cpp
#include <string>
```

Include the appropriate standard library header when using `std::string`.

### Mistake 8: Assuming `sizeof(int)` Is Always Four

Inspect the implementation rather than relying on a platform-specific assumption.

---

## 14. Best Practices

1. Choose types according to the information being represented.
2. Use `int` for ordinary whole-number calculations when its range is sufficient.
3. Prefer `double` for general floating-point calculations unless there is a reason to use another type.
4. Use `bool` for logical state.
5. Use `std::string` for ordinary text.
6. Use `std::numeric_limits` when checking ranges.
7. Avoid unnecessary signed/unsigned mixing.
8. Never rely on signed integer overflow.
9. Do not assume all systems use the same type sizes or floating-point precision.
10. For money, identifiers, and large calculations, check the domain's exact requirements before selecting a type.

---

## 15. Quick Revision

| Type | Stores | Example |
|---|---|---|
| `short` | Whole numbers | `short count = 10;` |
| `int` | Whole numbers | `int age = 20;` |
| `long` | Whole numbers | `long population = 1000000L;` |
| `long long` | Large whole numbers | `long long total = 9000000000LL;` |
| `float` | Approximate decimal values | `float height = 1.75f;` |
| `double` | Approximate decimal values | `double average = 87.5;` |
| `long double` | Approximate decimal values | `long double value = 12.5L;` |
| `char` | A character-sized unit | `char grade = 'A';` |
| `bool` | Logical truth value | `bool passed = true;` |
| `std::string` | Text | `std::string name = "Alex";` |

## 16. Review Questions and Answers

**Q1. What is a data type?**

A data type defines the kind of value an object can represent and helps determine the operations and representation associated with it.

**Q2. Which type would you use for an ordinary age?**

Usually `int`, assuming its range is sufficient.

**Q3. What is the difference between `float` and `double`?**

Both represent approximate floating-point values. `double` usually provides greater precision, although exact representation depends on the implementation.

**Q4. What is the difference between `char` and `std::string`?**

`char` is a built-in character-sized type. `std::string` is a library type used for sequences of characters.

**Q5. What does `bool` represent?**

Logical truth values: `true` and `false`.

**Q6. What does `sizeof` return?**

The size of an object or type in C++ bytes.

**Q7. Why should you avoid unnecessary unsigned types?**

Conversions and comparisons involving unsigned values can produce surprising results, especially when negative signed values are involved.

**Q8. How can you find the maximum value of `int`?**

Use `std::numeric_limits<int>::max()` from the `<limits>` header.

**Q9. Why is `double` not always ideal for money?**

Binary floating-point may not represent decimal fractions exactly, which can introduce rounding differences.

**Q10. Are data type sizes identical on every system?**

No. The C++ standard specifies minimum requirements and relationships, while implementations determine many actual sizes and ranges.
