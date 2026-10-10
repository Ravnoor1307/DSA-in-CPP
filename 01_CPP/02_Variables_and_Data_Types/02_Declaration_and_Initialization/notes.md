# Declaration and Initialization in C++

## 1. Introduction

Every C++ program works with data. Before a program can use a named variable, the variable must be declared in a context where its name is available.

For example:

```cpp
int age{20};
```

This statement declares an integer variable named `age` and initializes it with `20`.

Three related concepts are important:

- **Declaration:** introduces a name and its type.
- **Initialization:** establishes the initial value of an object when it is created.
- **Assignment:** replaces or updates the value of an existing object.

Understanding these differences helps prevent compilation errors and bugs.

## 2. Declaration

A declaration tells the compiler about a name and its type.

### Syntax

```cpp
data_type variable_name;
```

Examples:

```cpp
int age;
double salary;
char grade;
bool isStudent;
```

These declarations introduce four variables.

For ordinary local variables inside a function, however, declaration without an initializer does not give the variables a meaningful initial value.

For example:

```cpp
int main() {
    int score;

    // Assign a value before reading score.
    score = 85;

    return 0;
}
```

This is safe with respect to initialization: `score` receives `85` before it is read.

### Important distinction

Declaring a variable and assigning a value to it are separate operations:

```cpp
int score;  // Declaration
score = 85; // Assignment
```

Compare this with:

```cpp
int score{85}; // Declaration and initialization
```

The second form is shorter and makes the initial value explicit.

## 3. Initialization

Initialization gives an object its initial value as part of its creation.

C++ supports several initialization forms.

### 3.1 Copy initialization

```cpp
int age = 20;
double price = 99.5;
char grade = 'A';
```

The syntax uses an equals sign.

Despite the `=` symbol, this is initialization, not assignment, because the variables are being created.

### 3.2 Direct initialization

```cpp
int age(20);
double price(99.5);
char grade('A');
```

The initial value is provided inside parentheses.

Direct initialization can use constructors when creating class-type objects.

### 3.3 Direct-list initialization

```cpp
int age{20};
double price{99.5};
char grade{'A'};
```

This form uses braces and is also called brace initialization.

A major advantage is that it rejects narrowing conversions in contexts where narrowing is prohibited.

For example:

```cpp
int number{3.8}; // Compilation error
```

The compiler rejects this initialization because `3.8` cannot be represented as the integer `3` without losing information.

### 3.4 Copy-list initialization

```cpp
int age = {20};
double price = {99.5};
char grade = {'A'};
```

This form combines `=` with braces.

It is another valid initialization form, but its conversion and constructor rules can differ from direct-list initialization.

For example, copy-list initialization cannot select an `explicit` constructor, while direct-list initialization can select one.

Beginners generally need to recognize this form before learning the more detailed rules for classes.

### Comparison

| Form | Example | Main idea |
|---|---|---|
| Copy initialization | `int age = 20;` | Uses `=` when creating the variable |
| Direct initialization | `int age(20);` | Uses parentheses |
| Direct-list initialization | `int age{20};` | Uses braces and rejects narrowing |
| Copy-list initialization | `int age = {20};` | Uses `=` and braces |

For simple built-in types such as `int`, all four examples above initialize `age` to `20`.

## 4. Initialization vs. Assignment

This is one of the most important distinctions in C++.

### Initialization

```cpp
int marks{75};
```

A variable is created and receives its initial value.

### Assignment

```cpp
marks = 90;
```

The already existing variable receives a new value.

### Complete example

```cpp
#include <iostream>

int main() {
    int marks{75}; // Initialization

    std::cout << "Initial marks: " << marks << '\n';

    marks = 90; // Assignment

    std::cout << "Updated marks: " << marks << '\n';

    return 0;
}
```

Output:

```text
Initial marks: 75
Updated marks: 90
```

### Why does the difference matter?

Consider:

```cpp
int score{50};
int score{80};
```

This is an error in the same scope because it attempts to declare the same local variable twice.

If the intention is to update the value, write:

```cpp
int score{50};
score = 80;
```

The first statement creates the variable. The second changes its value.

## 5. Default Initialization

**Default initialization** is the initialization that occurs when an object is created without an initializer.

Its effect depends on the type and context.

### 5.1 Local built-in variables

```cpp
int main() {
    int number;

    return 0;
}
```

Here, `number` is a local integer with automatic storage duration. It is default-initialized, which does not initialize its value for this type.

Do not read `number` before assigning it a value.

```cpp
int main() {
    int number;
    number = 10;

    return number;
}
```

The variable receives a value before it is used.

### 5.2 Static-storage variables

Variables with static storage duration are zero-initialized before other initialization takes place.

For example:

```cpp
int globalCount;

int main() {
    return globalCount;
}
```

`globalCount` is initialized to zero.

This differs from an ordinary uninitialized local integer.

### 5.3 Class-type objects

For class types, default initialization can invoke a default constructor.

```cpp
#include <string>

int main() {
    std::string name;

    return static_cast<int>(name.size());
}
```

The default-constructed string is empty.

**Key point:** never assume that every variable without an explicit initializer has the same behavior.

## 6. Value Initialization

Value initialization is another important concept.

For built-in scalar types, value initialization produces zero.

Examples:

```cpp
int count{};
double price{};
bool isReady{};
char letter{};
```

The resulting values are:

| Variable | Value |
|---|---|
| `count` | `0` |
| `price` | `0.0` |
| `isReady` | `false` |
| `letter` | `'\0'` |

For class types, value initialization follows class-specific rules, which may involve zero-initialization and default construction.

### Compare default and value initialization

```cpp
int first;
int second{};
```

- `first` is a local integer without an initialized value.
- `second` is initialized to zero.

The safer version when zero is the intended initial value is:

```cpp
int second{};
```

### Practical example

A counter commonly begins at zero:

```cpp
int numberOfAttempts{};
```

This is clearer and safer than declaring an uninitialized counter and hoping to assign it before its first use.

## 7. Zero Initialization

Zero initialization sets an object or its relevant subobjects to their zero-initialized state according to the applicable C++ rules.

For common built-in types:

```cpp
int number{};
double amount{};
bool isActive{};
```

The values are zero, `0.0`, and `false`.

For pointers, zero-initialization produces a null pointer value.

```cpp
int* pointer{};
```

The pointer is null. When writing modern C++, `nullptr` is also a clear way to express a null pointer:

```cpp
int* pointer{nullptr};
```

Zero initialization is not identical to every other form of initialization. In particular, default initialization of an ordinary local `int` does not mean it becomes zero.

## 8. Brace Initialization and Narrowing

Brace initialization is useful because it prevents many accidental conversions that lose information.

### Example 1: Safe initialization

```cpp
int count{10};
double temperature{36.5};
```

Both are valid.

### Example 2: Narrowing conversion

```cpp
int count{10.7}; // Compilation error
```

A floating-point value cannot be converted to an integer through this brace initialization because the conversion loses the fractional part.

### Example 3: Conversion with `=`

```cpp
int count = 10.7;
```

This is allowed, but the floating-point value is converted to an integer, giving `10`.

The conversion may be undesirable even though the compiler accepts it.

### Example 4: Floating-point precision

```cpp
float measurement{3.14f};
double preciseMeasurement{3.14};
```

The `f` suffix marks the first literal as a `float`. The second literal is a `double`.

Brace initialization does not guarantee that every value is represented exactly; it prevents specific narrowing conversions.

## 9. Initializing Constants

A constant is a value or object that cannot be modified through the relevant name after initialization, depending on the kind of constant.

The `const` keyword is commonly used for variables whose values should not change.

```cpp
const int maximumAttempts{3};
const double pi{3.14159};
```

These variables must be initialized.

This is invalid:

```cpp
const int maximumAttempts;
```

A local `const` variable without an initializer is not valid in this context.

This is also invalid:

```cpp
const int maximumAttempts{3};
maximumAttempts = 5;
```

The second statement attempts to modify a constant object.

Use `const` for values that should remain unchanged after initialization.

## 10. Multiple Declarations and Initialization

You can declare several variables of the same type in a single statement.

```cpp
int first{10}, second{20}, third{30};
```

Each variable has its own initializer.

You can also write:

```cpp
int first{10};
int second{20};
int third{30};
```

Separate statements often make the code easier to read, particularly when the variables represent different concepts.

Be careful with declarations such as:

```cpp
int first, second = 20;
```

Only `second` is explicitly initialized to `20`. `first` is not initialized by this statement.

A clearer alternative is:

```cpp
int first{};
int second{20};
```

## 11. Initialization of Strings

Initialization also applies to objects such as `std::string`.

```cpp
#include <string>

int main() {
    std::string firstName{"Aman"};
    std::string emptyName{};

    return 0;
}
```

Here:

- `firstName` is initialized with `"Aman"`.
- `emptyName` is initialized as an empty string.

An empty string is a valid value. It is not the same as an uninitialized local integer.

## 12. Initialization and Constructors

For class types, initialization can determine which constructor is called.

A constructor is a special member function that initializes an object.

For example:

```cpp
#include <string>

int main() {
    std::string firstName{"Aman"};
    std::string anotherName("Riya");

    return 0;
}
```

Both strings are initialized with their respective text.

For built-in types, initialization is relatively simple. For classes, different initialization forms can affect constructor selection, implicit conversions, and whether explicit constructors are allowed.

These details become more important when studying classes and objects.

## 13. Common Errors and Misconceptions

### Error 1: Reading an uninitialized local variable

```cpp
int score;
std::cout << score;
```

The program reads an uninitialized local integer. This results in undefined behavior.

Correct:

```cpp
int score{};
std::cout << score;
```

### Error 2: Redeclaring a variable in the same scope

```cpp
int age{20};
int age{21};
```

This is invalid in the same scope.

Correct:

```cpp
int age{20};
age = 21;
```

### Error 3: Narrowing with braces

```cpp
int number{4.9};
```

This is rejected.

If truncation is intended, write the conversion explicitly:

```cpp
int number = static_cast<int>(4.9);
```

The result is `4`. Only do this when discarding the fractional part is intentional.

### Error 4: Forgetting to initialize a constant

```cpp
const int limit;
```

A local constant requires an initializer.

Correct:

```cpp
const int limit{100};
```

### Error 5: Confusing empty values with uninitialized values

```cpp
std::string name{};
int age;
```

`name` is initialized to an empty string. `age` is an uninitialized local integer.

The two situations are different.

### Error 6: Assuming `=` always means assignment

```cpp
int number = 10;
```

This is copy initialization because the variable is being created.

```cpp
number = 20;
```

This is assignment because the variable already exists.

## 14. Recommended Practices

1. Prefer initializing variables at the point of declaration.
2. Use `{}` when zero or the type's appropriate empty state is intended.
3. Prefer brace initialization when you want the compiler to reject narrowing conversions.
4. Use explicit conversions when a conversion is intentional and understood.
5. Use `const` for values that should not be modified.
6. Avoid declaring variables far before their first use without a reason.
7. Keep declarations readable.
8. Compile with warnings enabled.
9. Do not treat the absence of a compiler warning as proof that a variable is initialized.
10. Explain whether each important statement declares, initializes, or assigns a value.

## 15. Quick Revision Table

| Concept | Example | Meaning |
|---|---|---|
| Declaration | `int age;` | Introduces a variable |
| Copy initialization | `int age = 20;` | Creates a variable initialized to 20 |
| Direct initialization | `int age(20);` | Creates a variable initialized to 20 |
| Direct-list initialization | `int age{20};` | Creates a variable initialized to 20 |
| Copy-list initialization | `int age = {20};` | Creates a variable initialized to 20 |
| Assignment | `age = 25;` | Updates an existing variable |
| Value initialization | `int age{};` | Initializes the integer to zero |
| Constant initialization | `const int limit{10};` | Creates a non-modifiable constant object |

## 16. Review Questions and Answers

**Q1. What is declaration?**

Declaration introduces a name and its type.

**Q2. What is initialization?**

Initialization establishes the initial value of an object when it is created.

**Q3. What is assignment?**

Assignment updates the value of an existing object.

**Q4. What is the value of `int number{};`?**

The value is `0`.

**Q5. What happens with `int number{3.8};`?**

It fails to compile because the brace initialization would require a narrowing conversion.

**Q6. Is `int number = 3.8;` valid?**

Yes. The value is converted to `int`, producing `3`. The fractional part is lost.

**Q7. Is `int number;` guaranteed to initialize a local integer to zero?**

No. An ordinary local integer declared this way is not initialized to zero.

**Q8. Can a `const` variable be assigned a new value after initialization?**

No. Assigning a new value to that constant object is not allowed.

**Q9. What is the difference between `int a;` and `int a{};` for a local variable?**

The first leaves the integer uninitialized. The second initializes it to zero.

**Q10. Which initialization form is a good general choice for built-in types?**

Brace initialization is a good default when its conversion rules fit the intended behavior.

## Final Takeaway

Declaration introduces variables, initialization gives them their initial values, and assignment updates existing values. Understanding the different initialization forms helps you write safer and clearer C++ programs.

Before proceeding, practise predicting values, identifying narrowing conversions, and distinguishing initialized objects from uninitialized local variables.