

# Syntax and Statements in C++

## 1. What Is Syntax?

Syntax is the set of rules that determines how code must be written in a programming language.

Just as human languages have grammatical rules, C++ has rules governing keywords, identifiers, expressions, statements, braces, and punctuation.

Consider this valid statement:

```
int age = 20;
```

It declares an integer variable named `age` and initializes it with the value `20`.

Now consider:

```
int = age 20
```

This is invalid C++ syntax because the declaration does not follow the required structure.

Understanding syntax helps you write code the compiler can interpret.

---

## 2. Basic Structure of a C++ Program

A simple C++ program looks like this:

```
#include <iostream>

int main() {
    std::cout << "Hello, C++!" << '\n';
    return 0;
}
```

Its important elements are:

* `#include <iostream>` makes standard input/output declarations available.

* `int main()` defines the program's entry-point function in a typical hosted C++ program.

* `{` begins the function body.

* `std::cout` sends output to the standard output stream.

* `;` terminates the output statement.

* `return 0;` indicates successful termination.

* `}` ends the function body.

Each part follows specific C++ language rules.

---

## 3. Statements

A statement is an instruction or construct that performs an action or controls program execution.

### A. Declaration Statement

Declares a variable:

```
int age = 20;
```

### B. Expression Statement

An expression followed by a semicolon becomes an expression statement:

```
age = 25;
```

Another example:

```
age++;
```

### C. Output Statement

Displays information:

```
std::cout << "Welcome!" << '\n';
```

### D. Return Statement

Returns control from a function:

```
return 0;
```

### E. Compound Statement

A group of statements enclosed in braces is called a compound statement or block:

```
{
    int x = 10;
    int y = 20;

    std::cout << x + y << '\n';
}
```

The braces group the statements into one block and establish a scope for local variables.

---

## 4. Semicolons

A semicolon (`;`) terminates many C++ statements.

Correct:

```
int number = 10;
number = number + 5;
std::cout << number << '\n';
```

Incorrect:

```
int number = 10
number = number + 5
```

The missing semicolons cause syntax errors.

### Important: Not Every Construct Ends with a Semicolon

A function definition does not require a semicolon after its closing brace:

```
int add(int a, int b) {
    return a + b;
}
```

A class definition, however, requires a semicolon after its closing brace:

```
class Example {
};
```

A semicolon can also appear as an empty statement:

```
;
```

An unnecessary semicolon after a control statement may change program behavior:

```
if (true);
{
    std::cout << "This block is separate from the if statement.\n";
}
```

Here, the `if` controls the empty statement. The following block is independent and executes regardless of the condition.

---

## 5. Expressions

An expression is a combination of operands and operators that produces a value or otherwise performs an operation.

Examples:

```
5 + 3
```

This produces the value `8`.

```
age >= 18
```

This produces a Boolean result.

```
number * 2
```

This computes twice the value of `number`.

Expressions can appear inside statements:

```
int result = 5 + 3;
```

Here, `5 + 3` is an expression, and the entire declaration is a declaration statement.

### Expression vs. Statement

| Expression   | Statement                          |
| ------------ | ---------------------------------- |
| `5 + 3`      | `int total = 5 + 3;`               |
| `age >= 18`  | `age = 20;`                        |
| `number * 2` | `std::cout << number * 2 << '\n';` |

The distinction is useful because expressions produce values or effects, while statements form the instructions that structure program execution.

---

## 6. Code Blocks and Braces

Curly braces `{}` mark the beginning and end of a block.

Example:

```
int main() {
    int first = 10;

    {
        int second = 20;
        std::cout << first + second << '\n';
    }

    return 0;
}
```

The inner block contains its own local variable, `second`.

A variable declared inside a block generally cannot be accessed outside its scope.

For example, this is invalid:

```
{
    int score = 100;
}

std::cout << score << '\n';
```

The variable `score` is out of scope at the output statement.

Matching braces correctly is important. A missing or misplaced brace can change the structure of a program or cause a compiler error.

---

## 7. Identifiers

Identifiers are names given to program elements such as variables, functions, classes, and namespaces.

Examples:

```
int age = 20;
double accountBalance = 1500.50;

int calculateTotal() {
    return 10 + 20;
}
```

Here, `age`, `accountBalance`, and `calculateTotal` are identifiers.

### Rules for Identifiers

1. An identifier may contain letters, digits, and underscores.

2. It cannot begin with a digit.

3. It cannot be a C++ keyword.

4. Identifiers are case-sensitive.

5. Avoid names that begin with underscores in contexts reserved to the implementation.

Valid identifiers:

```
age
studentName
total_marks
value2
```

Invalid identifiers:

```
2value
student-name
total marks
```

The hyphen is interpreted as an operator, and a space separates tokens rather than forming part of a single identifier.

### Case Sensitivity

```
int age = 20;
int Age = 25;
```

`age` and `Age` are different identifiers.

Although this is valid, using names that differ only in capitalization can make programs harder to read.

---

## 8. Keywords

Keywords are reserved words with predefined meaning in C++.

Examples include:

* `int`

* `double`

* `char`

* `if`

* `else`

* `for`

* `while`

* `return`

* `class`

* `public`

* `void`

* `const`

You cannot use a keyword as an ordinary identifier.

Invalid:

```
int return = 10;
```

Valid:

```
int result = 10;
```

The word `result` is an ordinary identifier.

---

## 9. Whitespace and Formatting

Whitespace includes spaces, tabs, and line breaks.

For ordinary C++ code, these two examples are equivalent:

```
int number = 10;
std::cout << number << '\n';

int
number
=
10
;

std
::
cout
<<
number
<<
'\n'
;
```

Both may compile, but the second version is unnecessarily difficult to read.

Good formatting makes programs easier to understand, maintain, and debug.

Recommended practices:

* Indent statements inside blocks.

* Put opening and closing braces consistently.

* Use meaningful variable names.

* Separate logical sections with blank lines.

* Keep lines reasonably short.

* Follow one formatting style throughout a project.

Example:

```
int main() {
    int firstNumber = 10;
    int secondNumber = 20;
    int sum = firstNumber + secondNumber;

    std::cout << "Sum: " << sum << '\n';

    return 0;
}
```

---

## 10. Comments

Comments explain code and are ignored as ordinary program instructions by the compiler.

### Single-Line Comment

```
// Calculate the total
int total = 10 + 20;
```

### Multi-Line Comment

```
/*
    This program demonstrates
    basic C++ syntax.
*/
```

Comments should explain intent, reasoning, or important details rather than repeat obvious code.

---

## 11. Common Syntax Errors

### Error 1: Missing Semicolon

Incorrect:

```
int age = 20
```

Correct:

```
int age = 20;
```

### Error 2: Unmatched Braces

Incorrect:

```
int main() {
    std::cout << "Hello!\n";
```

Correct:

```
int main() {
    std::cout << "Hello!\n";
    return 0;
}
```

### Error 3: Misspelled Keyword or Identifier

Incorrect:

```
innt age = 20;
```

Correct:

```
int age = 20;
```

### Error 4: Missing Quotation Mark

Incorrect:

```
std::cout << "Hello!\n;
```

Correct:

```
std::cout << "Hello!\n";
```

### Error 5: Using an Undeclared Variable

Incorrect:

```
std::cout << score << '\n';
```

If `score` has not been declared and is not otherwise available, the compiler cannot resolve the name.

Correct:

```
int score = 100;
std::cout << score << '\n';
```

### Error 6: Incorrect Assignment Syntax

Incorrect:

```
int number 10;
```

Correct:

```
int number = 10;
```

### Error 7: Incorrect Function Declaration

Incorrect:

```
int main {
    return 0;
}
```

Correct:

```
int main() {
    return 0;
}
```

---

## 12. Syntax Errors vs. Logical Errors

A syntax error violates the language's rules and is usually diagnosed by the compiler.

A logical error allows a program to compile but makes it behave incorrectly.

Example of a logical error:

```
int length = 5;
int width = 4;

int area = length + width;
```

This code is syntactically valid, but the formula is wrong for a rectangle's area.

Correct:

```
int area = length * width;
```

Always distinguish between code that cannot be compiled and code that compiles but produces the wrong result.

---

## 13. Best Practices

* Write one clear statement per line.

* End statements with the required punctuation.

* Match every opening brace with a closing brace.

* Use descriptive identifiers.

* Avoid using C++ keywords as names.

* Keep variable scope as small as practical.

* Format code consistently.

* Use compiler diagnostics to find syntax problems.

* Fix errors one at a time, starting with the first relevant diagnostic.

* Compile and run your program after meaningful changes.

---

## 14. Quick Review Questions

1. What is syntax in C++?

2. What is the purpose of a semicolon?

3. What is the difference between an expression and a statement?

4. What do curly braces define?

5. What is an identifier?

6. Why can't `int` be used as a variable name?

7. Is `age` the same identifier as `Age`?

8. Do all C++ constructs require a semicolon after their closing brace?

9. What is the difference between a syntax error and a logical error?

10. Why is consistent indentation useful?

### Answers

1. The rules governing how valid C++ code is written.

2. It terminates many statements.

3. An expression produces a value or performs an operation; a statement forms an instruction or control construct.

4. A block, which also establishes scope where applicable.

5. A name given to a program element.

6. `int` is a reserved keyword.

7. No, C++ is case-sensitive.

8. No; for example, a function definition does not require one after its closing brace, but a class definition does.

9. A syntax error prevents valid compilation; a logical error produces incorrect behavior despite successful compilation.

10. It improves readability and maintainability.
