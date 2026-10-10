# Basic Data Types in C++

## Overview

Every variable in C++ has a type. A type tells the compiler what kind of value a variable can represent, which operations are appropriate for it, and how its values are represented and stored.

For example:

```cpp
int age = 20;
double height = 1.75;
char grade = 'A';
bool isStudent = true;
std::string name = "Alex";
```

Each variable represents a different kind of information.

## Files in This Folder

| File | Purpose |
|---|---|
| `README.md` | Topic overview, objectives, and instructions |
| `notes.md` | Detailed theory, examples, comparisons, and revision |
| `examples.cpp` | Runnable examples demonstrating basic data types |
| `practice.cpp` | Exercises and reference solutions |

## Learning Objectives

By completing this topic, you should be able to:

- Explain why C++ uses data types.
- Distinguish integer, floating-point, character, and Boolean types.
- Understand the differences between `short`, `int`, `long`, and `long long`.
- Understand the differences between `float`, `double`, and `long double`.
- Store individual characters using `char`.
- Represent true/false conditions using `bool`.
- Store text using `std::string`.
- Explain signed and unsigned integer types.
- Inspect type sizes and numeric limits.
- Select a suitable type for a given problem.

## Recommended Learning Order

1. Read `notes.md` carefully.
2. Compile and run `examples.cpp`.
3. Modify the example values and observe the results.
4. Solve the exercises in `practice.cpp` before checking its reference solutions.
5. Revise the comparison tables and answer the review questions.

## Compilation and Execution

Use a C++17-compatible compiler such as GCC.

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

Run these commands from this folder, or provide the correct file path.

## Completion Checklist

- [ ] I understand what a data type represents.
- [ ] I can identify integer and floating-point types.
- [ ] I can distinguish `char`, `bool`, and `std::string`.
- [ ] I understand signed and unsigned integers.
- [ ] I can inspect sizes and numeric limits.
- [ ] I can choose appropriate types for everyday problems.
- [ ] I have completed the practice exercises.

## Completion Criteria

You are ready to move on when you can select appropriate types for variables without relying on memorization alone, explain your choices, and recognize common type-related errors.
