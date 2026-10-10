# Constants and `const` in C++ — Detailed Notes

## 1. What Is a Constant?

A constant is a value that is intended to remain unchanged.

Consider a program that calculates the area of a circle. The value of \(\pi\) is used in the formula:

\[
\text{Area} = \pi \times r \times r
\]

You do not want the value representing \(\pi\) to be accidentally changed while the program is running.

```cpp
const double PI = 3.141592653589793;
double radius = 5.0;

double area = PI * radius * radius;
```

Here, `PI` is a constant object, while `radius` is a variable that can be modified.

### Analogy: A Fixed Rule

Imagine a classroom where the number of days in a week is fixed at seven. The number of students may change, but the number of days in a week does not.

```cpp
constexpr int DAYS_IN_WEEK = 7;
int numberOfStudents = 40;
```

The first declaration expresses a fixed value; the second represents information that can change.

## 2. Why Do We Need Constants?

Constants make programs easier to understand, maintain, and protect against accidental changes.

### Reason 1: Prevent Accidental Modification

```cpp
const int MAX_ATTEMPTS = 3;

// MAX_ATTEMPTS = 5; // Compilation error
```

The compiler rejects the attempted assignment because `MAX_ATTEMPTS` is a const-qualified object.

### Reason 2: Improve Readability

Compare:

```cpp
double total = price * 1.18;
```

with:

```cpp
constexpr double TAX_MULTIPLIER = 1.18;
double total = price * TAX_MULTIPLIER;
```

The second version gives the multiplier a meaningful name. In a real program, the multiplier should reflect the actual tax rule and applicable requirements.

### Reason 3: Make Maintenance Easier

Suppose the same fixed limit appears in several places. Naming the value as a constant lets you update the intended value in one place rather than searching through many expressions.

### Reason 4: Communicate Intent

A declaration such as:

```cpp
const int accountId = 12345;
```

communicates that the object should not be modified through that name after initialization.

Remember, `const` prevents modification through the const-qualified object or access path; it does not automatically make every object reachable through pointers or references immutable.

---

## 3. The `const` Keyword

The `const` keyword adds a qualification that prevents modifying an object through a const-qualified access path.

Example:

```cpp
const int age = 20;
```

After initialization, you cannot assign a new value to `age`.

```cpp
// age = 21; // Compilation error
```

By contrast, an ordinary variable can be changed:

```cpp
int score = 80;
score = 95;
```

### Basic Syntax

```cpp
const data_type variable_name = value;
```

Examples:

```cpp
const int MAX_SCORE = 100;
const double PI = 3.14159;
const char GRADE = 'A';
const std::string COURSE_NAME = "C++";
```

For `std::string`, include the `<string>` header.

### Naming Constants

Many projects use uppercase names for named constants:

```cpp
const int MAX_USERS = 100;
const double DISCOUNT_RATE = 0.10;
```

This is a naming convention, not a language requirement. Follow the style of your project.

---

## 4. Initializing a `const` Variable

A local const-qualified object must be initialized when it is defined.

Correct:

```cpp
const int year = 2026;
const double price{99.50};
```

Incorrect:

```cpp
// const int year;
// year = 2026;
```

The first line attempts to define a local const integer without an initializer, which is ill-formed. You cannot repair it with a later assignment.

### Why?

The object is meant to be read-only through its const-qualified type. C++ requires a valid initial value when such an object is defined.

### Important Distinction

Initialization establishes an object's initial value. Assignment attempts to change the value of an existing object.

```cpp
const int limit = 10;  // Initialization
// limit = 20;         // Invalid assignment
```

---

## 5. `const` with Different Data Types

The `const` qualifier can be applied to many different object types.

### Integer

```cpp
const int MAX_MARKS = 100;
```

### Floating-Point

```cpp
const double PI = 3.141592653589793;
```

### Character

```cpp
const char SECTION = 'A';
```

### Boolean

```cpp
const bool IS_PRODUCTION = false;
```

### String

```cpp
#include <string>

const std::string LANGUAGE = "C++";
```

In each case, the object cannot be modified through its const-qualified name after initialization.

---

## 6. `const` vs `constexpr`

Both keywords are useful for values that should not change, but they express different requirements.

### `const`

`const` means the object cannot be modified through that const-qualified access path after initialization.

```cpp
int readValue() {
    return 10;
}

int main() {
    const int value = readValue();
}
```

The initializer does not need to be a compile-time constant expression merely because the object is `const`.

### `constexpr`

`constexpr` indicates that the variable must be initialized with a constant expression and can be used where a constant expression is required, subject to the language rules.

```cpp
constexpr int DAYS_IN_WEEK = 7;
constexpr int HOURS_IN_DAY = 24;
constexpr int HOURS_IN_WEEK = DAYS_IN_WEEK * HOURS_IN_DAY;
```

The compiler can evaluate these constant expressions at compile time.

### Comparison

| Feature | `const` | `constexpr` |
|---|---|---|
| Prevents modification through the object | Yes | Yes, for a constexpr variable |
| Requires a constant-expression initializer for a variable | Not generally | Yes |
| Useful for runtime-computed read-only values | Yes | Not if the initializer fails constant-expression requirements |
| Useful for compile-time constants | Often, but not every const object is one | Yes |

### Example: Runtime Value

```cpp
int getUserInput() {
    return 42;
}

int main() {
    const int answer = getUserInput();
    // constexpr int otherAnswer = getUserInput(); // Invalid:
    // the function is not a constexpr function.
}
```

The `const` variable can be initialized using the runtime result. A `constexpr` variable needs a valid constant expression.

### When Should You Use Each?

- Use `const` when an object should not be modified after initialization.
- Use `constexpr` when a value is required to be a compile-time constant and its initializer satisfies the language rules.

Do not assume every `const` variable can be used as a compile-time array bound or in every other constant-expression context.

---

## 7. Constants in Calculations

Named constants make formulas clearer.

### Example: Area of a Circle

```cpp
#include <iostream>

int main() {
    constexpr double PI = 3.141592653589793;
    double radius = 5.0;

    const double area = PI * radius * radius;

    std::cout << "Area: " << area << '\n';
}
```

Here:

- `PI` is a compile-time constant.
- `radius` is a variable because it may change.
- `area` is const because this example calculates it once and does not modify it afterward.

If a later operation needs to update the radius or area, the design should reflect that requirement.

### Example: Discount Calculation

```cpp
constexpr double DISCOUNT_RATE = 0.10;

double price = 500.0;
const double discount = price * DISCOUNT_RATE;
const double finalPrice = price - discount;
```

This separates the fixed rate from the values calculated using it.

---

## 8. `const` with References

A reference can provide read-only access to an object when declared as a const reference.

```cpp
int score = 90;
const int& scoreView = score;
```

You can read through `scoreView`:

```cpp
std::cout << scoreView << '\n';
```

But you cannot modify `score` through that reference:

```cpp
// scoreView = 100; // Compilation error
```

However, the original object is not itself constant:

```cpp
score = 100;
std::cout << scoreView << '\n'; // Prints 100
```

This distinction is important: a const reference prevents modification through that reference; it does not necessarily make the referred-to object immutable.

### Why Is This Useful?

Const references are commonly used to pass large objects to functions without copying them, while preventing the function from modifying the object through that parameter.

Example:

```cpp
#include <iostream>
#include <string>

void printName(const std::string& name) {
    std::cout << name << '\n';
}
```

The function can read the string without copying it and cannot modify it through `name`.

---

## 9. `const` with Pointers

Pointers introduce two separate concepts:

1. Whether the pointed-to object can be modified through the pointer.
2. Whether the pointer itself can be changed to point somewhere else.

### 9.1 Pointer to Const Data

```cpp
int value = 10;
const int* ptr = &value;
```

You cannot modify `value` through `ptr`:

```cpp
// *ptr = 20; // Compilation error
```

But you can make the pointer point to another compatible object:

```cpp
int anotherValue = 30;
ptr = &anotherValue;
```

The pointer is changeable; access through it is read-only.

### 9.2 Const Pointer

```cpp
int value = 10;
int* const ptr = &value;
```

The pointer itself cannot be redirected:

```cpp
*ptr = 20; // Allowed: modifies value
// ptr = &anotherValue; // Compilation error
```

The pointed-to object can be modified through the pointer, but the pointer cannot be changed to point somewhere else.

### 9.3 Const Pointer to Const Data

```cpp
int value = 10;
const int* const ptr = &value;
```

Neither the pointed-to object can be modified through `ptr`, nor can `ptr` be redirected.

### Comparison Table

| Declaration | Modify data through pointer? | Redirect pointer? |
|---|---|---|
| `int* ptr` | Yes | Yes |
| `const int* ptr` | No | Yes |
| `int* const ptr` | Yes | No |
| `const int* const ptr` | No | No |

These examples illustrate the basic rules. More complicated pointer and qualification conversions have additional constraints.

---

## 10. Const-Correctness in Functions

Const-correctness means expressing which objects a function may modify and which it only reads.

For example:

```cpp
#include <iostream>
#include <string>

void printMessage(const std::string& message) {
    std::cout << message << '\n';
}

int main() {
    const std::string greeting = "Hello, C++!";
    printMessage(greeting);
}
```

The parameter is a const reference, so the function can read the string without copying it and cannot modify it through that parameter.

This is a common and useful C++ style.

---

## 11. Common Mistakes

### Mistake 1: Declaring a Const Variable Without Initialization

```cpp
// const int LIMIT;
```

A local const integer object requires initialization at its definition.

### Mistake 2: Reassigning a Const Object

```cpp
const int LIMIT = 10;
// LIMIT = 20; // Compilation error
```

Initialize it with the intended value instead.

### Mistake 3: Assuming `const` Always Means Compile-Time Constant

```cpp
int getValue() {
    return 10;
}

const int value = getValue();
```

This is valid, but `value` is not necessarily a constant expression usable in every compile-time context.

### Mistake 4: Assuming a Const Reference Makes the Original Object Constant

```cpp
int score = 50;
const int& reference = score;

score = 75; // Valid
```

The original object remains modifiable through other non-const access paths.

### Mistake 5: Confusing Pointer-to-Const with Const Pointer

Remember:

```cpp
const int* ptr; // Read-only access to the pointed-to int
int* const ptr2 = nullptr; // Fixed pointer; if non-null, can modify int
```

The second declaration illustrates a const pointer that must be initialized in a definition; the null initializer is valid, though dereferencing it would not be.

### Mistake 6: Using Constants Without Meaningful Names

```cpp
double result = price * 0.15;
```

If `0.15` has a meaningful role, such as a rate, a named constant can make the code easier to understand.

### Mistake 7: Believing `const` Makes an Entire Object Graph Immutable

A const-qualified object can contain pointers or references to other objects. Those other objects are not automatically made const.

---

## 12. Best Practices

1. Use `const` for objects that should not be modified after initialization.
2. Prefer `constexpr` when a compile-time constant is required and possible.
3. Give named constants clear, meaningful names.
4. Initialize const objects at their definitions.
5. Use const references for read-only access to suitable objects.
6. Learn pointer-to-const and const-pointer syntax before combining pointers with complex data structures.
7. Avoid duplicating unexplained numeric literals throughout a program.
8. Do not assume a `const` variable is always a compile-time constant.
9. Make function parameters const when the function only needs to read the supplied object.
10. Follow consistent naming conventions throughout the project.

---

## 13. Quick Revision Table

| Concept | Meaning |
|---|---|
| `const int x = 10;` | A const-qualified integer object |
| `constexpr int x = 10;` | A compile-time constant variable |
| `const int& ref = x;` | A read-only reference |
| `const int* ptr = &x;` | A pointer that provides read-only access to an integer |
| `int* const ptr = &x;` | A pointer that cannot be redirected |
| `const int* const ptr = &x;` | A fixed pointer providing read-only access |

## 14. Review Questions and Answers

**Q1. What is a constant?**

A value or object intended to remain unchanged.

**Q2. What does `const` do?**

It prevents modification through a const-qualified object or access path.

**Q3. Must a local const variable be initialized?**

Yes, a local const object must be initialized when defined.

**Q4. What is the difference between `const` and `constexpr`?**

`const` expresses read-only access, while `constexpr` requires a constant-expression initializer for a constexpr variable.

**Q5. Can a const reference refer to a non-const object?**

Yes. The object can still be modified through other non-const access paths.

**Q6. What does `const int* ptr` mean?**

It is a pointer that does not allow modifying the pointed-to integer through that pointer.

**Q7. What does `int* const ptr` mean?**

It is a const pointer that cannot be redirected after initialization, although it can modify the pointed-to integer.

**Q8. Why are named constants useful?**

They communicate intent, improve readability, reduce repeated literal values, and help prevent accidental modification.

**Q9. Can a const variable be initialized using a runtime function result?**

Yes, provided the initializer is otherwise valid. The resulting object is not necessarily a constant expression.

**Q10. Why use const references in functions?**

They allow read-only access without copying the referenced object.
