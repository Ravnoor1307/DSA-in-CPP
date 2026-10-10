# Variables in C++

## 1. What Is a Variable?

A **variable** is a named entity associated with a value stored in a program's memory. It allows a program to work with information while it executes.

For example, imagine you are building a student management system. Your program may need to store:

- A student's age
- The student's marks
- The student's name
- Whether the student passed an examination

Instead of writing these values directly everywhere, you can store them in variables and use their names whenever needed.

```cpp
int age = 20;
int marks = 85;
```

Here:

- `age` is a variable name.
- `20` is the value assigned to `age`.
- `marks` is another variable name.
- `85` is the value assigned to `marks`.

The type `int` indicates that these variables store integer values.

### Real-world analogy

Think of a variable as a labelled container.

A container labelled `age` holds the value `20`. Another container labelled `marks` holds the value `85`.

Your program can read these values, use them in calculations, and assign new values when necessary.

The analogy is not exact: a variable is a programming-language construct, and its actual storage and behavior depend on its type and context.

## 2. Why Do We Need Variables?

Variables make programs flexible and reusable.

Consider this program without variables:

```cpp
#include <iostream>

int main() {
    std::cout << 20 + 5 << '\n';
    std::cout << 20 * 2 << '\n';

    return 0;
}
```

The values `20` and `5` are written directly in the expressions. Such values are sometimes called *literals*.

Now consider a version using variables:

```cpp
#include <iostream>

int main() {
    int age = 20;

    std::cout << age + 5 << '\n';
    std::cout << age * 2 << '\n';

    return 0;
}
```

If the age changes, you can update the value in one place, and both expressions use the new value.

Variables are useful because they allow you to:

1. Store information.
2. Perform calculations.
3. accept user input.
4. Reuse values in multiple places.
5. Update information as a program runs.
6. Make code easier to understand.

## 3. Declaration of a Variable

**Declaration** introduces a variable and specifies its type and name.

### Syntax

```cpp
data_type variable_name;
```

Example:

```cpp
int age;
double salary;
char grade;
```

Explanation:

- `int` is the type of `age`.
- `double` is the type of `salary`.
- `char` is the type of `grade`.
- The semicolon ends each declaration.

At this stage, these declarations do not explicitly provide initial values.

For example:

```cpp
int age;
```

This declares an integer variable named `age`. Because it is a local variable inside a function, it does not automatically receive a meaningful initial value.

Reading an uninitialized local `int` before assigning a value results in undefined behavior in C++.

**Best practice:** initialize variables before using them.

## 4. Initialization of a Variable

**Initialization** gives a variable its initial value when it is created.

There are several ways to initialize variables in C++.

### 4.1 Copy initialization

```cpp
int age = 20;
double price = 99.50;
char grade = 'A';
```

The equals sign introduces the initial value.

### 4.2 Direct initialization

```cpp
int age(20);
double price(99.50);
char grade('A');
```

The initial value is supplied inside parentheses.

### 4.3 Brace initialization

```cpp
int age{20};
double price{99.50};
char grade{'A'};
```

Brace initialization is often a good default because it rejects certain narrowing conversions.

For example:

```cpp
int number{3.8}; // Compilation error
```

The compiler rejects this because converting `3.8` to `int` would discard the fractional part.

Compare that with:

```cpp
int number = 3.8; // Allowed, but converts to 3
```

The second statement permits the conversion, but the fractional part is lost.

### Recommendation

For new C++ code, prefer brace initialization when it fits the situation:

```cpp
int count{10};
double temperature{36.5};
```

## 5. Assignment to a Variable

**Assignment** gives a new value to an already existing variable.

Example:

```cpp
int score{50};

score = 75;
```

Initially, `score` contains `50`. After the assignment, it contains `75`.

The assignment operator is `=`.

### Initialization vs. assignment

| Initialization | Assignment |
|---|---|
| Provides the initial value when a variable is created | Updates the value of an existing variable |
| `int score{50};` | `score = 75;` |
| Happens as part of creating the variable | Happens after the variable exists |

Example:

```cpp
int score{50}; // Initialization

score = 60;    // Assignment
score = 90;    // Another assignment
```

The final value of `score` is `90`.

## 6. Variables Can Change Their Values

A variable can be assigned different values during program execution, provided those values are compatible with its type.

```cpp
int temperature{25};

temperature = 30;
temperature = 28;
```

The value changes in this sequence:

| Operation | Value of `temperature` |
|---|---:|
| Initialization | 25 |
| First assignment | 30 |
| Second assignment | 28 |

The final value is `28`.

This property is useful in counters, calculations, game scores, and user-input processing.

## 7. Using Variables in Expressions

An **expression** is a combination of values, variables, operators, and possibly function calls that produces a result.

Variables can participate in arithmetic expressions.

```cpp
int firstNumber{10};
int secondNumber{5};

int sum = firstNumber + secondNumber;
int difference = firstNumber - secondNumber;
int product = firstNumber * secondNumber;
int quotient = firstNumber / secondNumber;
```

The resulting values are:

| Variable | Value |
|---|---:|
| `sum` | 15 |
| `difference` | 5 |
| `product` | 50 |
| `quotient` | 2 |

Because both operands of the division are integers, the result is integer division.

For example:

```cpp
int result{7 / 2}; // 3
```

If you need a fractional result, use a floating-point type and floating-point arithmetic:

```cpp
double result{7.0 / 2.0}; // 3.5
```

## 8. Rules for Naming Variables

Variable names are also called **identifiers**.

C++ has rules governing which identifiers are valid.

### Rule 1: Names can contain letters, digits, and underscores

Valid:

```cpp
int age;
int student_age;
int marks2026;
```

### Rule 2: A name cannot begin with a digit

Invalid:

```cpp
int 2marks;
int 2026score;
```

Valid alternatives:

```cpp
int marks2;
int score2026;
```

### Rule 3: Spaces are not allowed inside an identifier

Invalid:

```cpp
int student age;
```

Valid:

```cpp
int studentAge;
int student_age;
```

### Rule 4: C++ is case-sensitive

These are different identifiers:

```cpp
int score{10};
int Score{20};
int SCORE{30};
```

They represent three separate variables.

### Rule 5: Keywords cannot be used as ordinary variable names

Keywords have special meanings in C++.

Invalid:

```cpp
int return;
int class;
int while;
```

Use different names:

```cpp
int returnValue;
int studentClass;
int whileCount;
```

### Rule 6: Avoid reserved identifiers

Names containing certain leading underscores or double underscores are reserved to the implementation in specified contexts. Beginners should avoid identifiers beginning with underscores, especially double underscores.

Prefer descriptive names such as `totalMarks` rather than `_totalMarks`.

## 9. Naming Conventions

A naming convention is a consistent style for choosing identifier names.

Common styles include:

| Style | Example |
|---|---|
| camelCase | `studentAge` |
| snake_case | `student_age` |
| PascalCase | `StudentAge` |
| ALL_CAPS | `MAX_SCORE` |

These styles are conventions, not interchangeable language rules. C++ itself does not require one particular style for ordinary variables.

For this course, use **camelCase** for ordinary variables:

```cpp
int studentAge{20};
double totalMarks{450.5};
int numberOfStudents{60};
```

For constants, use a consistent style such as:

```cpp
const double pi{3.14159};
```

Meaningful names help other programmers understand what a value represents.

Avoid:

```cpp
int x{20};
int a{450};
```

Prefer:

```cpp
int studentAge{20};
int totalMarks{450};
```

Short names are still appropriate when their purpose is clear, such as `i` in a small loop.

## 10. Type, Name, and Value

These three ideas are related but different.

Consider:

```cpp
int age{20};
```

- **Type:** `int` — specifies the kind of value the variable stores.
- **Name:** `age` — lets the program refer to the variable.
- **Value:** `20` — the current value.

Changing one does not necessarily mean changing the others.

For example:

```cpp
age = 21;
```

The value changes from `20` to `21`, but the variable name and declared type remain the same.

A variable's type constrains which values and operations are appropriate. It does not mean every possible value of that type is valid for every application.

For example, `int age` can technically store negative integers, even though a negative age would usually be invalid application data.

## 11. Multiple Variables

You can declare variables in separate statements:

```cpp
int firstNumber{10};
int secondNumber{20};
int thirdNumber{30};
```

Or declare variables of the same type in one statement:

```cpp
int firstNumber{10}, secondNumber{20}, thirdNumber{30};
```

Both forms are valid. Separate declarations are often easier for beginners to read and maintain.

Each variable has its own value:

```cpp
int firstNumber{10};
int secondNumber{20};

firstNumber = 100;
```

Changing `firstNumber` does not automatically change `secondNumber`.

## 12. Common Mistakes

### Mistake 1: Using a variable before initializing it

```cpp
int score;
std::cout << score;
```

For an uninitialized local `int`, this is not a safe way to obtain a value.

Correct:

```cpp
int score{0};
std::cout << score;
```

### Mistake 2: Using a variable before declaring it

```cpp
score = 50;
int score;
```

The first statement refers to `score` before its declaration is in scope.

Correct:

```cpp
int score;
score = 50;
```

Better:

```cpp
int score{50};
```

### Mistake 3: Using `=` when you mean comparison

```cpp
int age{20};

if (age = 18) {
    // ...
}
```

This assigns `18` to `age`; it does not test whether `age` equals `18`. The resulting integer value is then used as the condition.

To compare values, use `==`:

```cpp
if (age == 18) {
    // ...
}
```

### Mistake 4: Incorrect capitalization

```cpp
int studentAge{20};
std::cout << studentage;
```

`studentAge` and `studentage` are different identifiers.

Correct:

```cpp
std::cout << studentAge;
```

### Mistake 5: Using an invalid name

```cpp
int student age{20};
```

Correct:

```cpp
int studentAge{20};
```

### Mistake 6: Assuming assignment creates a new variable

```cpp
int age{20};
age = 21;
```

The second statement changes the existing variable. It does not declare another one.

### Mistake 7: Ignoring integer division

```cpp
int result{5 / 2};
```

The result is `2`, not `2.5`.

Use floating-point arithmetic when you need a fractional result.

## 13. Practical Applications

### Application 1: Student information

```cpp
int studentAge{19};
int studentMarks{88};
```

These variables can be used to display student information or perform calculations.

### Application 2: Shopping bill

```cpp
double itemPrice{250.0};
int quantity{3};

double totalPrice{itemPrice * quantity};
```

The total is `750.0`.

### Application 3: Updating a score

```cpp
int score{0};

score = score + 10;
score = score + 5;
```

The final score is `15`.

The statement `score = score + 10;` calculates the right-hand side using the current value of `score`, then assigns the result back to `score`.

## 14. Best Practices

1. Initialize variables when practical.
2. Choose names that communicate meaning.
3. Follow a consistent naming convention.
4. Use the appropriate data type for the information.
5. Keep variables in the smallest reasonable scope.
6. Avoid reusing a variable for unrelated purposes.
7. Use constants when a value should not change after initialization.
8. Do not assume that a variable's type guarantees application-level validity.
9. Compile with warnings enabled while learning.
10. Read compiler diagnostics instead of guessing when a variable-related error occurs.

## 15. Quick Revision

- A variable is a named entity associated with a value.
- A declaration introduces a variable and its type.
- Initialization supplies the initial value.
- Assignment changes the value of an existing variable.
- An identifier is the name used to refer to a variable or another program entity.
- C++ identifiers are case-sensitive.
- Variable names cannot begin with digits or contain spaces.
- Keywords cannot be used as ordinary variable names.
- Variables should be initialized before they are read.
- Integer division discards the fractional part of the quotient.

## 16. Review Questions

### Beginner Level

**Q1. What is a variable?**

A variable is a named entity associated with a value that a program can use.

**Q2. What does this statement do?**

```cpp
int age{20};
```

It declares an integer variable named `age` and initializes it with `20`.

**Q3. What is the difference between initialization and assignment?**

Initialization gives a variable its initial value when it is created. Assignment updates the value of an existing variable.

**Q4. Is `studentAge` the same as `studentage`?**

No. C++ is case-sensitive, so they are different identifiers.

### Intermediate Level

**Q5. What is the final value of `score`?**

```cpp
int score{10};
score = 20;
score = score + 5;
```

Answer: `25`.

**Q6. Is this a valid identifier?**

```cpp
int 2students;
```

No. An identifier cannot begin with a digit.

**Q7. What is the result?**

```cpp
int result{9 / 2};
```

Answer: `4`, because integer division is performed.

**Q8. Why is this unsafe?**

```cpp
int marks;
std::cout << marks;
```

The local variable `marks` is uninitialized. Reading it this way results in undefined behavior.

## Final Takeaway

Variables let programs remember and work with information. Understanding declarations, initialization, assignment, naming rules, and types prepares you for the next topics: detailed initialization techniques and C++ data types.