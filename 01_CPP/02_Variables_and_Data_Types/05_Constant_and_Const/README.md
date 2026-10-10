# Constants and `const` in C++

## Overview

A constant is a value or object that should not be modified after it has been established.

C++ provides `const` to make an object read-only through that name after initialization. It also provides `constexpr` for variables and functions that can participate in constant expressions when the relevant requirements are satisfied.

Example:

```cpp
const double PI = 3.141592653589793;
constexpr int DAYS_IN_WEEK = 7;
```

These declarations make the intended usage clear and help prevent accidental changes.

## Files in This Folder

| File | Purpose |
|---|---|
| `README.md` | Topic overview and instructions |
| `notes.md` | Detailed theory, examples, and revision |
| `examples.cpp` | Runnable demonstrations |
| `practice.cpp` | Exercises and reference solutions |

## Learning Objectives

By completing this topic, you should be able to:

- Explain why constants are useful.
- Declare and initialize `const` variables.
- Understand why a `const` object cannot be modified after initialization.
- Distinguish `const` from `constexpr`.
- Use constants instead of unexplained literal values.
- Understand basic `const` references and pointers.
- Recognize common compilation errors involving constants.

## Recommended Learning Order

1. Read `notes.md`.
2. Compile and run `examples.cpp`.
3. Inspect the `const` and `constexpr` examples.
4. Attempt the exercises in `practice.cpp`.
5. Complete the review questions.

## Compilation and Execution

### Windows PowerShell

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic examples.cpp -o examples
.\examples.exe
```

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic practice.cpp -o practice
.\practice.exe
```

### Linux or macOS

```bash
g++ -std=c++17 -Wall -Wextra -pedantic examples.cpp -o examples
./examples
```

```bash
g++ -std=c++17 -Wall -Wextra -pedantic practice.cpp -o practice
./practice
```

Run the commands from this folder, or provide the appropriate file path.

## Completion Checklist

- [ ] I understand why constants are useful.
- [ ] I can declare and initialize `const` variables.
- [ ] I understand why a `const` variable cannot be reassigned.
- [ ] I can explain the basic difference between `const` and `constexpr`.
- [ ] I can use constants in formulas and conditions.
- [ ] I understand basic const-reference and const-pointer syntax.
- [ ] I have completed the practice exercises.

## Completion Criteria

You are ready to move on when you can decide which values should be constants, choose between `const` and `constexpr` appropriately, and explain why an attempted modification of a constant produces a compilation error.

