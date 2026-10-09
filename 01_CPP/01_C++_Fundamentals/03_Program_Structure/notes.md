

# C++ Program Structure

## 1. Introduction

A C++ program consists of instructions, declarations, functions, and other language constructs that work together to perform a task.

Understanding program structure is essential because every C++ program must follow the language's syntax rules.

Consider this simple program:

```
#include <iostream>

int main() {
    std::cout << "Hello, World!" << '\n';
    return 0;
}
```

Although this program is small, it introduces several fundamental components of C++.

## 2. The Main Components of a C++ Program

A typical beginner-level C++ program contains:

1. Preprocessor directives.

2. Header inclusions.

3. The `main()` function.

4. Declarations and statements.

5. An output or processing operation.

6. A return statement.

Not every C++ program needs to contain all these components in exactly this form, but this structure is common in introductory programs.

## 3. Preprocessor Directives

Preprocessor directives begin with the `#` character.

Example:

```
#include <iostream>
```

The `#include` directive makes the declarations provided by the specified header available to the program.

In this example, `<iostream>` provides facilities for standard input and output.

Important points:

* Preprocessor directives are processed before the main compilation stage.

* They do not normally end with a semicolon.

* Header inclusion is a common way to access standard library facilities.

## 4. Header Files

Headers provide declarations that allow code to use functions, classes, objects, and other facilities.

Common C++ headers include:

| Header        | Common use                        |
| ------------- | --------------------------------- |
| `<iostream>`  | Standard input and output streams |
| `<string>`    | The `std::string` class           |
| `<vector>`    | The `std::vector` container       |
| `<algorithm>` | Algorithms such as `std::sort`    |
| `<cmath>`     | Mathematical functions            |
| `<iomanip>`   | Input/output formatting tools     |

Example:

```
#include <iostream>
#include <string>

int main() {
    std::string name = "Alex";
    std::cout << name << '\n';
    return 0;
}
```

Including the required headers explicitly makes programs easier to understand and more portable.

## 5. The `main()` Function

The `main()` function is the entry point of a hosted C++ program.

Example:

```
int main() {
    return 0;
}
```

### Understanding the components

* `int` is the return type.

* `main` is the function name.

* `()` contains the parameter list, which is empty here.

* `{` begins the function body.

* `}` ends the function body.

* `return 0;` indicates successful completion.

The standard hosted forms include:

```
int main() {
    return 0;
}
```

and:

```
int main(int argc, char* argv[]) {
    return 0;
}
```

The second form can receive command-line arguments.

For beginner programs, the first form is usually sufficient.

## 6. Curly Braces `{}`

Curly braces define a block of code.

Example:

```
int main() {
    int number = 10;

    if (number > 0) {
        std::cout << "Positive\n";
    }

    return 0;
}
```

The braces identify the bodies of both the function and the `if` statement.

Incorrect brace placement can cause compilation errors or change the program's meaning.

## 7. Statements

A statement is an instruction that performs an operation or controls program execution.

Example:

```
int age = 20;
age = age + 1;
std::cout << age << '\n';
```

These statements initialize a variable, update its value, and display the result.

Many C++ statements end with a semicolon (`;`).

A semicolon is not required after every closing brace. For example, a normal function definition does not end with a semicolon.

## 8. Variables and Declarations

A declaration introduces a name and its type or other relevant properties.

Example:

```
int age = 20;
double price = 99.50;
char grade = 'A';
```

Here:

* `age` is an integer variable.

* `price` is a floating-point variable with double precision.

* `grade` is a character variable.

A declaration can also initialize a variable, as shown in these examples.

## 9. Output Using `std::cout`

The `std::cout` stream displays output in the console.

Example:

```
#include <iostream>

int main() {
    std::cout << "Welcome to C++\n";
    std::cout << 100 << '\n';
    return 0;
}
```

Output:

```
Welcome to C++
100
```

The insertion operator `<<` sends data to the output stream.

Multiple values can be printed in a single statement:

```
int a = 10;
int b = 20;

std::cout << "Sum: " << a + b << '\n';
```

Output:

```
Sum: 30
```

## 10. Return Statements

The statement `return 0;` ends the execution of `main()` and reports successful completion to the host environment.

Example:

```
int main() {
    return 0;
}
```

In a hosted C++ program, reaching the closing brace of `main()` without an explicit return statement is equivalent to returning zero.

However, writing `return 0;` explicitly is useful while learning because it makes the control flow clear.

## 11. Comments

Comments explain code and are ignored as executable instructions.

### Single-line comment

```
// This is a single-line comment
```

### Multi-line comment

```
/*
This is a multi-line comment.
It can span several lines.
*/
```

Comments help document decisions and clarify code, but they should not simply repeat every obvious instruction.

## 12. Whitespace and Formatting

Whitespace includes spaces, tabs, and line breaks.

C++ generally allows whitespace between tokens where the language syntax permits it.

These statements have the same meaning:

```
int number = 10;

int number=10;
```

The first version is easier to read.

Consistent indentation makes blocks and nested statements easier to understand.

Recommended style:

```
int main() {
    int number = 10;

    if (number > 0) {
        std::cout << "Positive\n";
    }

    return 0;
}
```

## 13. A Complete Program Breakdown

```
#include <iostream>

int main() {
    int firstNumber = 10;
    int secondNumber = 20;
    int sum = firstNumber + secondNumber;

    std::cout << "First number: " << firstNumber << '\n';
    std::cout << "Second number: " << secondNumber << '\n';
    std::cout << "Sum: " << sum << '\n';

    return 0;
}
```

Output:

```
First number: 10
Second number: 20
Sum: 30
```

Execution proceeds through the statements in `main()` from top to bottom, except where control-flow constructs change that order.

## 14. Common Beginner Mistakes

### Mistake 1: Missing a semicolon

Incorrect:

```
int age = 20
```

Correct:

```
int age = 20;
```

### Mistake 2: Incorrect capitalization

Incorrect:

```
Int age = 20;
```

Correct:

```
int age = 20;
```

C++ is case-sensitive.

### Mistake 3: Missing a closing brace

Incorrect:

```
int main() {
    std::cout << "Hello\n";
```

Correct:

```
int main() {
    std::cout << "Hello\n";
    return 0;
}
```

### Mistake 4: Omitting a required header

If your program uses standard library facilities, include the appropriate header rather than relying on indirect inclusion.

### Mistake 5: Using `cout` without qualification

If you have not introduced the `std` namespace, write:

```
std::cout << "Hello\n";
```

Alternatively, you can write `using std::cout;` after including `<iostream>`.

## 15. Key Takeaways

* `#include` makes declarations from headers available.

* `main()` is the entry point of a hosted C++ program.

* Curly braces define blocks.

* Declarations introduce names and types.

* Statements perform operations.

* Semicolons terminate many statements.

* `std::cout` prints output.

* `return 0;` indicates successful completion.

* Comments and formatting improve readability.

## 16. Revision Questions

1. What are the main components of a basic C++ program?

2. What is the purpose of `#include <iostream>`?

3. What is the role of `main()`?

4. What do curly braces represent?

5. Why do many C++ statements end with a semicolon?

6. What is the purpose of `std::cout`?

7. What does `return 0;` indicate?

8. What is the difference between a declaration and a statement?

9. What is the difference between single-line and multi-line comments?

10. Why is consistent indentation important?

11. Does every C++ line require a semicolon?

12. What happens when a required closing brace is missing?

## 17. Completion Checklist

* Identify the main components of a C++ program.

* Explain the purpose of header files.

* Understand the structure of `main()`.

* Use braces, statements, and semicolons correctly.

* Write output using `std::cout`.

* Explain the role of `return 0;`.

* Compile and run both example programs.

* Answer the revision questions independently.
