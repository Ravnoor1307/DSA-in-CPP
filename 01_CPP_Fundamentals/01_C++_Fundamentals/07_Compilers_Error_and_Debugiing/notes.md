

# Compiler Errors and Debugging in C++

## 1. Introduction

Programming errors are a normal part of software development. Even experienced programmers make mistakes, so learning to identify and fix errors is an essential skill.

**Debugging** is the systematic process of finding, understanding, and correcting problems in a program.

When a C++ program does not behave as expected, ask:

1. Does the source code compile?

2. Does the linker successfully create the executable?

3. Does the program start and run?

4. Does it produce the expected result?

5. Does it work for different inputs and edge cases?

These questions help narrow down the cause of a problem.

---

## 2. The Main Categories of Errors

### A. Syntax Errors

Syntax errors occur when code violates the grammatical rules of C++.

Incorrect:

```
int age = 20
```

The declaration is missing a semicolon.

Correct:

```
int age = 20;
```

Other examples include missing braces, unmatched quotation marks, and malformed declarations.

### B. Compilation Errors

Compilation errors occur when the compiler cannot translate the source code successfully. Syntax errors are one type of compilation error.

Example:

```
int main() {
    unknownVariable = 10;
    return 0;
}
```

If `unknownVariable` has not been declared or otherwise made available, the compiler will report an error.

Correct:

```
int main() {
    int unknownVariable = 10;
    return 0;
}
```

### C. Linker Errors

A linker error occurs when the linker cannot successfully combine the compiled object files and required libraries.

For example, a function may be declared and called but have no matching definition available to the linker.

```
int calculateTotal();

int main() {
    return calculateTotal();
}
```

If no definition of `calculateTotal()` is supplied during linking, the build will generally fail.

### D. Runtime Errors

Runtime errors occur while the program is executing. Some cause the program to terminate; others lead to invalid behavior.

Examples include:

* Failing to open a file and not handling the failure.

* Accessing an element outside an array's bounds.

* Dereferencing an invalid pointer.

* Triggering an exception that is not handled.

Not every runtime problem produces a clear error message.

### E. Logical Errors

Logical errors occur when the program compiles and runs but produces an incorrect result.

Incorrect:

```
int length = 5;
int width = 3;

int area = length + width;
```

The correct formula for a rectangle's area is multiplication:

```
int area = length * width;
```

Logical errors often require tracing values and comparing actual results with expected results.

---

## 3. Errors vs. Warnings

An **error** is a problem that prevents a required build stage from completing successfully.

A **warning** indicates code that may be suspicious, unsafe, non-portable, or unintended. Some warnings still allow an executable to be produced.

Example:

```
int main() {
    int unusedValue = 10;
    return 0;
}
```

A compiler may warn that `unusedValue` is never used.

For beginner practice, compile with:

```
g++ -std=c++17 -Wall -Wextra -pedantic examples.cpp -o examples
```

These flags enable many useful diagnostics, but they do not detect every bug.

Do not ignore a warning just because the program compiles. Read it, understand it, and decide whether the code should change.

---

## 4. Understanding Compiler Messages

Compiler diagnostics commonly contain:

* The source file name.

* A line number or source location.

* An error or warning category.

* A description of the problem.

* Sometimes a caret or highlighted source line.

Example:

```
example.cpp: In function 'int main()':
example.cpp:5:5: error: expected ';' before 'return'
```

The exact wording varies by compiler and version.

### How to Read the Message

1. Identify the file mentioned.

2. Find the indicated line.

3. Read the diagnostic description.

4. Inspect the surrounding code, including the line above.

5. Look for missing punctuation, undeclared names, incorrect types, or mismatched braces.

6. Fix the underlying issue and compile again.

**Important:** The first diagnostic is often the best place to start. One syntax mistake can cause several later messages, so avoid fixing every reported line independently before understanding the first error.

---

## 5. A Practical Debugging Workflow

Follow this process whenever your program fails.

### Step 1: Reproduce the Problem

Run the program with the input or conditions that cause the issue.

Record what happens.

### Step 2: Identify the Error Category

Determine whether the problem is related to:

* Compilation.

* Linking.

* Runtime behavior.

* Incorrect logic.

* Input or environment configuration.

### Step 3: Read the Diagnostic Carefully

Do not immediately change random lines. Read the error message and inspect the indicated location.

### Step 4: Form a Hypothesis

Ask what could explain the observed behavior.

For example:

> The program prints 0 instead of the expected total. Perhaps the variable was never updated, or the wrong expression was used.

### Step 5: Inspect Values

Use output statements or a debugger to examine variables at important points.

```
std::cout << "DEBUG: total = " << total << '\n';
```

Temporary diagnostic output is useful, but remove unnecessary debug messages from the final program.

### Step 6: Make One Focused Change

Change the code that addresses your hypothesis rather than modifying many unrelated lines.

### Step 7: Recompile and Retest

Verify that the build succeeds and the original problem is resolved.

Also test other cases to ensure the fix has not introduced a new problem.

---

## 6. Debugging with Output Statements

One of the simplest debugging techniques is printing variable values.

Consider:

```
#include <iostream>

int main() {
    int first = 10;
    int second = 5;

    int result = first - second;

    std::cout << "First: " << first << '\n';
    std::cout << "Second: " << second << '\n';
    std::cout << "Result: " << result << '\n';

    return 0;
}
```

If the result is unexpected, print the values before the calculation and after it.

For example:

```
std::cout << "Before calculation\n";

int result = first - second;

std::cout << "After calculation: " << result << '\n';
```

This can help identify where the program begins behaving incorrectly.

Use clear labels in debug output so you can distinguish similar values.

---

## 7. Debugging Logical Errors

Consider this program:

```
#include <iostream>

int main() {
    int marks1 = 80;
    int marks2 = 90;
    int marks3 = 70;

    int average = marks1 + marks2 + marks3 / 3;

    std::cout << "Average: " << average << '\n';

    return 0;
}
```

The expression does not calculate the intended average because division has higher precedence than addition.

The corrected version is:

```
int average = (marks1 + marks2 + marks3) / 3;
```

The lesson is to check:

* Operator precedence.

* Parentheses.

* Variable values.

* Data types.

* The mathematical formula.

* The expected output.

For more accurate averages, use a floating-point result:

```
double average = (marks1 + marks2 + marks3) / 3.0;
```

Using `3.0` ensures that the division is performed using floating-point arithmetic.

---

## 8. Using Assertions

An assertion checks whether a condition that should be true actually holds.

C++ provides `assert` through the `<cassert>` header.

```
#include <cassert>
#include <iostream>

int main() {
    int age = 20;

    assert(age >= 0);

    std::cout << "Age: " << age << '\n';

    return 0;
}
```

If the condition is false while assertions are enabled, the program reports the failed assertion and terminates.

Assertions are useful for checking internal assumptions during development.

Important considerations:

* Assertions are not a replacement for validating user input.

* Assertions can be disabled when `NDEBUG` is defined.

* Do not place required side effects inside an assertion, because the expression may not be evaluated when assertions are disabled.

For example, avoid:

```
assert(++counter > 0);
```

The increment should be performed separately if it is required.

---

## 9. Using a Debugger

A debugger lets you pause program execution and inspect the program's state.

Common debugger features include:

### Breakpoints

A breakpoint pauses execution at a selected line.

Use one before a calculation or branch that you want to inspect.

### Step Over

Executes the current line and moves to the next line without stepping into a called function.

### Step Into

Enters a function call so you can inspect the function's execution.

### Step Out

Continues execution until the current function returns.

### Variable Inspection

Displays the current values of variables while execution is paused.

### Call Stack

Shows the chain of active function calls that led to the current location.

### Watch Expressions

Allows you to monitor selected expressions or variables while stepping through code.

A debugger is especially useful when a problem depends on a particular input, a complicated sequence of operations, or values that change over time.

---

## 10. Debugging with GCC and GDB

If GCC and GDB are installed, you can compile a program with debugging information.

```
g++ -std=c++17 -Wall -Wextra -g debug_demo.cpp -o debug_demo
```

The `-g` option requests debugging information.

Start GDB:

```
gdb ./debug_demo
```

Common GDB commands include:

```
break main
run
next
step
print variableName
backtrace
continue
quit
```

Their purposes are:

| Command              | Purpose                                                        |
| -------------------- | -------------------------------------------------------------- |
| `break main`         | Set a breakpoint at `main`.                                    |
| `run`                | Start the program.                                             |
| `next`               | Execute the next source line without stepping into a function. |
| `step`               | Step into a function call when possible.                       |
| `print variableName` | Display a variable's value.                                    |
| `backtrace`          | Show the call stack.                                           |
| `continue`           | Resume execution until another breakpoint or program stop.     |
| `quit`               | Exit GDB.                                                      |

The exact commands and interface may differ between debuggers. GDB is not installed by default on every operating system.

---

## 11. Undefined Behavior

Undefined behavior occurs when the C++ language standard imposes no requirements on what happens for a particular operation.

Examples include:

* Signed integer overflow.

* Accessing an array out of bounds.

* Dereferencing an invalid pointer.

* Reading an uninitialized local variable in situations where its value is not valid to read.

Undefined behavior is particularly dangerous because the program may appear to work, fail unpredictably, or behave differently after a compiler optimization.

Example of an out-of-bounds access:

```
int numbers[3] = {10, 20, 30};

// Invalid: valid indices are 0, 1, and 2.
int value = numbers[3];
```

A safer approach is to use a valid index or a container with bounds-checked access when appropriate.

For example:

```
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30};

    std::cout << numbers.at(2) << '\n';

    return 0;
}
```

The `.at()` method checks the index and throws an exception if it is out of range.

---

## 12. Sanitizers

Sanitizers can detect certain classes of runtime errors during testing.

For supported GCC or Clang environments, a useful example is:

```
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined debug_demo.cpp -o debug_demo
```

This requests AddressSanitizer and UndefinedBehaviorSanitizer instrumentation.

They can help detect issues such as:

* Certain out-of-bounds memory accesses.

* Use-after-free errors.

* Some forms of undefined behavior.

Availability and supported checks depend on the compiler, platform, and build configuration.

Sanitizers are testing tools, not proof that a program is free from bugs.

---

## 13. Common Debugging Mistakes

### Mistake 1: Ignoring the First Error

A missing semicolon can trigger several confusing follow-up messages.

**Better approach:** Start with the earliest relevant diagnostic and rebuild after fixing it.

### Mistake 2: Changing Many Lines at Once

If you change several unrelated parts, it becomes difficult to determine which change fixed or caused the problem.

**Better approach:** Make one focused change at a time.

### Mistake 3: Testing Only One Input

A program may work for a typical input but fail for zero, negative values, empty input, or large numbers.

**Better approach:** Test normal cases, boundary cases, and invalid inputs where applicable.

### Mistake 4: Assuming That Compilation Means Correctness

A successfully compiled program can still contain logical errors and runtime bugs.

**Better approach:** Test behavior, not just whether the program builds.

### Mistake 5: Ignoring Warnings

Warnings can reveal suspicious expressions, conversions, and unused variables.

**Better approach:** Review warnings and understand their implications.

### Mistake 6: Running an Old Executable

If compilation fails, an older executable may still remain on disk.

**Better approach:** Check the compiler's exit status and make sure you run the newly built program only after a successful build.

---

## 14. A Complete Debugging Example

The following program calculates the average of three marks.

```
#include <iostream>

int main() {
    int firstMark = 80;
    int secondMark = 90;
    int thirdMark = 70;

    int total = firstMark + secondMark + thirdMark;
    double average = total / 3.0;

    std::cout << "Total marks: " << total << '\n';
    std::cout << "Average marks: " << average << '\n';

    return 0;
}
```

Expected output:

```
Total marks: 240
Average marks: 80
```

To practice debugging:

1. Change the average calculation to use `total / 0`.

2. Compile the program and observe whether the compiler diagnoses the problem.

3. Restore the original calculation.

4. Change the expression to `firstMark + secondMark + thirdMark / 3`.

5. Run the program and compare the output with the expected average.

6. Correct the expression and test again.

Remember that division by zero involving integers is undefined behavior in C++. The compiler may not detect it during compilation.

---

## 15. Recommended Debugging Checklist

Before asking for help or declaring a program broken:

1. Save the latest source code.

2. Reproduce the problem.

3. Read the first relevant compiler diagnostic.

4. Identify whether the issue is a build, runtime, or logic problem.

5. Inspect the relevant variables and expressions.

6. Check operator precedence and data types.

7. Make a focused change.

8. Recompile successfully.

9. Run the program with the failing input.

10. Test additional cases.

11. Remove unnecessary debug output.

12. Record what caused the issue and how it was fixed.

---

## 16. Quick Review Questions

1. What is debugging?

2. What is the difference between a compilation error and a logical error?

3. What is a linker error?

4. Why should you read the first compiler diagnostic carefully?

5. What is the difference between an error and a warning?

6. What is a breakpoint?

7. What does the `-g` compiler flag do?

8. What is undefined behavior?

9. How can assertions help during development?

10. Why should a program be tested with multiple inputs?

11. What is the purpose of a sanitizer?

12. Why should you avoid making many unrelated changes while debugging?

### Answers

1. The systematic process of locating, understanding, and correcting program defects.

2. A compilation error prevents successful compilation; a logical error allows the program to compile but produces incorrect behavior.

3. An error during linking, often caused by missing definitions or unresolved symbols.

4. One underlying mistake can cause many subsequent diagnostics.

5. An error prevents a required stage from succeeding; a warning identifies potentially problematic code.

6. A marker that pauses execution at a selected location.

7. It requests debugging information for compatible debugging tools.

8. Behavior for which the C++ standard imposes no requirements.

9. They check whether assumptions that should hold are actually true.

10. Different inputs expose different bugs and edge cases.

11. It helps detect certain runtime memory errors and undefined behavior.

12. It makes cause-and-effect harder to identify and can introduce additional bugs.
