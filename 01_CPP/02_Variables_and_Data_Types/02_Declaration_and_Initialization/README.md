# Declaration and Initialization in C++

## Overview

This folder explains how variables are declared, initialized, and assigned values in C++.

You will study declaration without initialization, copy initialization, direct initialization, brace initialization, default initialization, and the differences between initialization and assignment.

## Files in This Folder

| File | Purpose |
|---|---|
| `README.md` | Folder overview, objectives, and instructions |
| `notes.md` | Detailed theory, syntax, examples, and common mistakes |
| `examples.cpp` | Working demonstrations of declaration and initialization |
| `practice.cpp` | Exercises to reinforce the concepts |

## Learning Objectives

After completing this topic, you should be able to:

- Distinguish declaration, initialization, and assignment.
- Identify the different initialization forms in C++.
- Explain why uninitialized local variables can be dangerous.
- Understand the difference between default initialization and value initialization.
- Recognize narrowing conversions in brace initialization.
- Choose appropriate initialization forms for everyday C++ code.
- Read and fix common initialization errors.

## Recommended Learning Order

1. Read `notes.md`.
2. Study the initialization examples.
3. Compile and run `examples.cpp`.
4. Attempt each exercise in `practice.cpp`.
5. Review compiler errors and explain why incorrect examples fail.

## Compilation Instructions

Compile using GCC with C++17:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic examples.cpp -o examples
```

Compile the practice file:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic practice.cpp -o practice
```

Run on Windows PowerShell:

```powershell
.\examples.exe
.\practice.exe
```

Run on Linux/macOS:

```bash
./examples
./practice
```

Some initialization forms intentionally produce compilation errors in the notes. They are explanations, not code that should be copied into the working examples.

## Completion Checklist

- [ ] I understand declaration, initialization, and assignment.
- [ ] I can write copy initialization.
- [ ] I can write direct initialization.
- [ ] I can write brace initialization.
- [ ] I understand default initialization and value initialization.
- [ ] I understand why uninitialized local variables should not be read.
- [ ] I understand narrowing conversions.
- [ ] I have compiled and executed `examples.cpp`.
- [ ] I have completed the exercises in `practice.cpp`.

## Completion Criteria

Move forward when you can select an appropriate initialization form, predict the resulting value, explain the difference between initialization and assignment, and identify unsafe or invalid code.
