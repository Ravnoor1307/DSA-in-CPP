

# Comments and Formatting in C++

## 1. Introduction

Writing code that works is important, but writing code that other people can understand is equally important.

Readable code is easier to:

* Understand and review.

* Debug when something goes wrong.

* Modify when requirements change.

* Maintain in large projects.

* Share with teammates.

Two important tools for improving readability are **comments** and **consistent formatting**.

Comments explain code. Formatting organizes code visually.

---

## 2. What Are Comments?

Comments are notes written inside source code to explain its purpose, behavior, or reasoning.

In C++, the compiler does not treat ordinary comments as executable program instructions.

There are two main comment styles:

1. Single-line comments: `//`

2. Block comments: `/* ... */`

### Single-Line Comments

A single-line comment begins with `//` and continues to the end of that line.

```
// Store the user's age.
int age = 21;
```

Another example:

```
int price = 100; // Price before tax
```

Single-line comments are useful for short explanations.

### Multi-Line Comments

A block comment begins with `/*` and ends with `*/`.

```
/*
    This program demonstrates
    basic C++ comments and formatting.
*/
```

Block comments are useful for longer explanations or introductory descriptions.

Important: Traditional C++ block comments do not nest. An inner `/*` does not create a separate nested comment.

---

## 3. Why Are Comments Useful?

Comments can explain:

* What a section of code is intended to do.

* Why a particular approach was selected.

* Important assumptions or constraints.

* Tricky algorithms or calculations.

* Temporary decisions that need revisiting.

Example:

```
// Convert minutes to whole hours.
int hours = totalMinutes / 60;
```

The comment provides context about the calculation.

### Comments Should Explain Intent

Consider this example:

```
// Add 1 to count.
count++;
```

The comment merely repeats what the code already says.

A more useful comment might explain why the counter is incremented:

```
// Count this item because it passed validation.
count++;
```

A good comment adds information that is not immediately obvious from the code.

---

## 4. When Should You Avoid Comments?

Comments are not automatically beneficial. Too many unnecessary comments can make code harder to read.

Avoid comments that:

* Repeat every line of code.

* Describe obvious operations without adding context.

* Are outdated or contradict the implementation.

* Hide poorly named variables or confusing logic.

Less useful:

```
// Create an integer called age and set it to 20.
int age = 20;
```

More useful:

```
int minimumVotingAge = 18;
```

A descriptive name often communicates intent more effectively than an extra comment.

**Rule of thumb:** Write code that explains itself where possible, and add comments where context or reasoning is needed.

---

## 5. What Is Code Formatting?

Code formatting is the way source code is arranged visually.

It includes:

* Indentation.

* Spaces around operators.

* Blank lines.

* Brace placement.

* Line length.

* Consistency of style.

Formatting usually does not change a program's meaning when whitespace is insignificant, but certain spaces and newlines are required to separate tokens or preserve string contents.

### Poorly Formatted Code

```
#include<iostream>
int main(){int a=10;int b=20;int sum=a+b;std::cout<<sum<<'\n';return 0;}
```

This may compile, but it is difficult to scan.

### Better Formatting

```
#include <iostream>

int main() {
    int firstNumber = 10;
    int secondNumber = 20;
    int sum = firstNumber + secondNumber;

    std::cout << sum << '\n';

    return 0;
}
```

The second version separates logical steps and makes the program structure visible.

---

## 6. Indentation

Indentation means adding spaces at the beginning of lines to show their structural relationship.

Example:

```
int main() {
    int score = 95;

    if (score >= 50) {
        std::cout << "Passed\n";
    }
}
```

The statements inside `main()` are indented. The statement inside the `if` block is indented one additional level.

### Recommended Practice

* Use a consistent indentation width, commonly four spaces.

* Indent code inside braces.

* Align statements at the same nesting level.

* Avoid mixing tabs and spaces inconsistently within a project.

Indentation does not determine block scope in C++, but it makes the actual brace structure easier to see.

---

## 7. Brace Placement

Braces define blocks in C++. Several brace styles are used in real projects.

### Allman Style

Opening braces appear on separate lines.

```
int main()
{
    int number = 10;

    if (number > 0)
    {
        std::cout << "Positive\n";
    }

    return 0;
}
```

### K&R / Attached-Brace Style

Opening braces appear on the same line as the relevant declaration or control statement.

```
int main() {
    int number = 10;

    if (number > 0) {
        std::cout << "Positive\n";
    }

    return 0;
}
```

Both styles are commonly used. Choose a style appropriate to your project and apply it consistently.

---

## 8. Spacing Around Operators

Spaces can improve readability around operators.

Less readable:

```
int total=price+tax*quantity;
```

More readable:

```
int total = price + tax * quantity;
```

Recommended style:

```
int sum = firstNumber + secondNumber;
bool isAdult = age >= 18;
int doubled = number * 2;
```

Spaces are especially helpful in longer expressions.

---

## 9. Blank Lines

Blank lines separate logical sections of a program.

Example:

```
#include <iostream>

int main() {
    // Input data
    int length = 5;
    int width = 3;

    // Calculate the area
    int area = length * width;

    // Display the result
    std::cout << "Area: " << area << '\n';

    return 0;
}
```

Blank lines make it easier to distinguish input, calculations, and output.

Avoid both extremes:

* One enormous block with no visual separation.

* Too many blank lines that scatter related statements.

---

## 10. Naming Conventions

Consistent names make code easier to understand.

### Variables

Use descriptive names:

```
int studentAge = 20;
double accountBalance = 2500.50;
```

Avoid unclear names when a more descriptive name is practical:

```
int x = 20;
double y = 2500.50;
```

Short names such as `i` are appropriate in many small loop contexts, but meaningful names are often better for longer-lived variables.

### Constants

Use `const` when a value should not be modified through that variable:

```
const double pi = 3.141592653589793;
const int maximumAttempts = 3;
```

Naming styles vary across teams. Examples include `maximumAttempts`, `maximum_attempts`, and `MAXIMUM_ATTEMPTS`. Follow the conventions of your project.

### Functions

Use names that describe the action:

```
int calculateTotal(int price, int quantity) {
    return price * quantity;
}
```

The function name `calculateTotal` communicates more than an ambiguous name such as `doWork`.

---

## 11. Formatting Long Statements

Long lines can be difficult to read, especially when expressions or output statements contain many parts.

Less readable:

```
std::cout << "Student: " << studentName << ", Age: " << age << ", Score: " << score << '\n';
```

One possible improvement:

```
std::cout << "Student: " << studentName
          << ", Age: " << age
          << ", Score: " << score << '\n';
```

The continuation lines are aligned so the structure is easy to follow.

Do not split lines arbitrarily. Keep related parts together and follow your project's formatting conventions.

---

## 12. Comments for Functions

Comments can explain a function's purpose, parameters, assumptions, and return value.

Example:

```
// Returns the area of a rectangle.
// Assumes length and width are non-negative.
int calculateArea(int length, int width) {
    return length * width;
}
```

For small, self-explanatory functions, extensive comments may not be necessary. For complicated functions, document important constraints and behavior.

---

## 13. Documentation Comments

Some projects use special comment conventions for documentation tools.

For example:

```
/**
 * Calculates the area of a rectangle.
 *
 * @param length The rectangle's length.
 * @param width The rectangle's width.
 * @return The calculated area.
 */
int calculateArea(int length, int width) {
    return length * width;
}
```

Tools such as Doxygen can use structured comments to generate documentation.

These special conventions are optional; ordinary C++ comments are sufficient for many beginner programs.

---

## 14. Automated Formatting Tools

As projects grow, manually formatting every line can become tedious.

Common tools include:

* **ClangFormat:** Automatically formats C++ source code according to configured rules.

* **Editor formatting features:** Many editors can format source code using built-in or installed tools.

* **IDE formatting tools:** Many development environments provide configurable formatting commands.

A typical ClangFormat command is:

```
clang-format -i examples.cpp
```

The `-i` option edits the file in place. Keep a backup or use version control if you want to review the changes before accepting them.

A project may use a `.clang-format` configuration file to share consistent formatting settings.

Formatting tools do not replace good naming, useful comments, or sound program design.

---

## 15. Common Formatting Mistakes

### Mistake 1: Inconsistent Indentation

```
int main() {
    int age = 20;
  int score = 95;
        std::cout << age << '\n';
}
```

Use consistent indentation.

### Mistake 2: Unclear Variable Names

```
int a = 100;
int b = 5;
int c = a * b;
```

Prefer descriptive names when the purpose is not obvious:

```
int price = 100;
int quantity = 5;
int totalCost = price * quantity;
```

### Mistake 3: Outdated Comments

```
// Set the age to 18.
int age = 21;
```

Keep comments synchronized with the implementation.

### Mistake 4: Over-Commenting

```
// Print a message.
std::cout << "Welcome\n";
```

The comment may be unnecessary because the code already communicates the operation.

### Mistake 5: Inconsistent Brace Styles

Using different brace styles in the same file without a reason makes code less predictable. Choose one style for the project.

---

## 16. A Complete Example of Readable Code

```
#include <iostream>
#include <string>

// Calculates the total cost of a purchase.
double calculateTotal(double price, int quantity) {
    return price * quantity;
}

int main() {
    const std::string productName = "Notebook";
    const double unitPrice = 45.50;
    const int quantity = 3;

    // Calculate the total purchase cost.
    const double totalCost = calculateTotal(unitPrice, quantity);

    // Display the purchase summary.
    std::cout << "Purchase Summary\n";
    std::cout << "----------------\n";
    std::cout << "Product: " << productName << '\n';
    std::cout << "Unit price: " << unitPrice << '\n';
    std::cout << "Quantity: " << quantity << '\n';
    std::cout << "Total cost: " << totalCost << '\n';

    return 0;
}
```

This example uses:

* Descriptive identifiers.

* Consistent indentation.

* Blank lines between logical sections.

* A short explanatory comment.

* A function with a clear name.

* Constants for values that should not change.

* Readable output statements.

---

## 17. Quick Review Questions

1. What is the difference between comments and formatting?

2. How do you write a single-line comment in C++?

3. How do you write a block comment?

4. Why should comments explain intent rather than repeat code?

5. Does indentation determine block scope in C++?

6. What makes a variable name meaningful?

7. Why should brace styles be consistent?

8. What is the purpose of ClangFormat?

9. What problems can outdated comments cause?

10. When should you add documentation comments?

### Answers

1. Comments provide explanations; formatting arranges code visually.

2. Start the comment with `//`.

3. Enclose the comment between `/*` and `*/`.

4. Useful comments provide context not immediately apparent from the code.

5. No. Braces and language rules determine scope; indentation only improves readability.

6. It describes the variable's role or meaning.

7. Consistency makes code easier to scan and maintain.

8. It automatically formats source code according to configured rules.

9. They can mislead readers about what the program actually does.

10. When a function or API needs documented behavior, parameters, return values, or constraints.
