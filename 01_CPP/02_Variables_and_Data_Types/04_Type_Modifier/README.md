# Type Modifiers in C++

## Overview

Type modifiers change certain characteristics of built-in C++ types. They are commonly used to adjust the range of integer types or specify floating-point types.

Examples:

```cpp
short int smallNumber = 120;
unsigned int itemCount = 500;
long int population = 1000000L;
long long int largeNumber = 9000000000LL;
long double measurement = 123.456L;
```

The actual sizes and ranges depend on the C++ implementation, within the guarantees provided by the language standard.

## Files in This Folder

| File | Purpose |
|---|---|
| `README.md` | Topic overview and learning instructions |
| `notes.md` | Detailed explanations, rules, examples, and revision |
| `examples.cpp` | Runnable demonstrations of type modifiers |
| `practice.cpp` | Exercises and reference solutions |

## Learning Objectives

By completing this topic, you should be able to:

- Explain what type modifiers are.
- Distinguish signed and unsigned integer types.
- Understand `short`, `long`, and `long long`.
- Understand the role of `long` in `long double`.
- Recognize valid type combinations.
- Inspect type sizes and limits.
- Avoid common unsigned arithmetic and conversion mistakes.

## Recommended Learning Order

1. Read `notes.md`.
2. Compile and run `examples.cpp`.
3. Experiment with different values and inspect the output.
4. Attempt every exercise in `practice.cpp`.
5. Review the comparison tables and quiz yourself.

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

## Completion Checklist

- [ ] I understand signed and unsigned integers.
- [ ] I can explain `short`, `long`, and `long long`.
- [ ] I understand `long double`.
- [ ] I know which modifier combinations are valid.
- [ ] I can inspect type sizes and numeric limits.
- [ ] I understand unsigned wraparound and signed overflow.
- [ ] I have completed the practice exercises.

## Completion Criteria

You are ready to continue when you can choose a suitable modified type for a problem, explain the choice, and identify risks involving range, conversion, and arithmetic.
