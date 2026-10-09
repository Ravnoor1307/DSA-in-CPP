
# 07 — Compiler Errors and Debugging

## Overview

This folder teaches you how to identify, diagnose, and fix problems in C++ programs. It covers compiler diagnostics, linker errors, warnings, runtime errors, logical errors, assertions, debugging tools, and sanitizers.

## Files

| File                     | Purpose                                                        |
| ------------------------ | -------------------------------------------------------------- |
| `notes.md`               | Detailed explanations of error types and debugging techniques. |
| `examples.cpp`           | Working example of calculations and diagnostic output.         |
| `practice.cpp`           | Exercises with intentional bugs to identify and fix.           |
| `debugging_checklist.md` | Reusable checklist for diagnosing program failures.            |
| `README.md`              | Learning objectives and progress tracking.                     |

## Learning Objectives

By completing this topic, you should be able to:

* Distinguish compilation, linker, runtime, and logical errors.

* Interpret compiler errors and warnings.

* Use a systematic debugging workflow.

* Inspect variable values with diagnostic output.

* Use assertions to check assumptions.

* Understand breakpoints, stepping, and variable inspection.

* Compile with debugging information using `-g`.

* Understand undefined behavior.

* Recognize the purpose of sanitizers.

* Test fixes against the original failure and additional cases.

## Recommended Learning Order

1. Read `notes.md`.

2. Compile and run `examples.cpp`.

3. Observe the diagnostic output.

4. Complete each exercise in `practice.cpp`.

5. Use `debugging_checklist.md` to investigate any errors you encounter.

6. Recompile and rerun after each fix.

7. Answer the review questions in `notes.md`.

## Compilation Commands

Compile the working example:

```
g++ -std=c++17 -Wall -Wextra -pedantic examples.cpp -o examples
```

Compile the practice file after fixing the intentional syntax error:

```
g++ -std=c++17 -Wall -Wextra -pedantic practice.cpp -o practice
```

To include debugging information:

```
g++ -std=c++17 -Wall -Wextra -g examples.cpp -o examples
```

To request AddressSanitizer and UndefinedBehaviorSanitizer instrumentation on supported GCC or Clang toolchains:

```
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined examples.cpp -o examples
```

## Completion Checklist

* I understand the major categories of errors.

* I can read compiler diagnostics.

* I understand warnings and why they matter.

* I can fix common syntax errors.

* I can diagnose logical errors by tracing variables.

* I understand how to use assertions.

* I understand the purpose of breakpoints and stepping.

* I can compile with debugging information.

* I understand undefined behavior.

* I know what sanitizers are used for.

* I completed the practice exercises.

* I can follow the debugging checklist independently.

## Completion Criteria

Consider this topic complete when you can take a small broken C++ program, identify its error category, explain the underlying cause, fix it, and verify the correction through compilation and testing.

## Fundamentals Section Complete

After completing Topics 01–07, you should have a foundation in:

* What C++ is and where it is used.

* C++ history and features.

* Program structure.

* Compilation and execution.

* Syntax and statements.

* Comments and formatting.

* Compiler errors and debugging.
