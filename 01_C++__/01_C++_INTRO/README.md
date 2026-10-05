# C++ Introduction

## Goal

This is the first folder of the DSA journey.

Before studying data structures and algorithms, we need to understand what a C++ program is, how it is compiled, where execution starts, and how basic output works.

## 1. What is programming?

Programming means giving a computer a precise sequence of instructions.

For example:

```text
START
print "Hello"
print "DSA"
END
```

A computer follows instructions literally. It does not automatically infer what we intended.

Think of a program like a cooking recipe. If a recipe says "put the cake in the oven" but never says to turn the oven on, a human may notice the missing instruction. A computer simply follows the instructions it was given.

## 2. What is C++?

C++ is a general-purpose compiled programming language.

It is widely used in:

- data structures and algorithms
- competitive programming
- game engines
- operating systems
- browsers
- databases
- embedded systems
- performance-sensitive software

For DSA, C++ is especially useful because it provides both low-level control and a powerful Standard Library.

Later we will use facilities such as:

```cpp
vector
string
stack
queue
set
map
priority_queue
```

## 3. Source code

The program we type is called source code.

C++ source files commonly use the extension:

```text
.cpp
```

For example:

```text
main.cpp
```

The processor does not directly execute C++ source code.

It must first be translated into executable machine code by a C++ toolchain.

Simplified pipeline:

```text
C++ source
    |
    v
preprocessing
    |
    v
compilation
    |
    v
assembly
    |
    v
linking
    |
    v
executable
```

Real-world analogy:

Suppose an architect produces a blueprint. The blueprint describes the building, but people cannot live inside the blueprint. It must be turned into an actual building.

Similarly:

```text
source code = blueprint
executable  = finished building
```

## 4. First C++ program

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World!\n";
    return 0;
}
```

Output:

```text
Hello, World!
```

Now examine every component.

## 5. #include <iostream>

```cpp
#include <iostream>
```

`iostream` provides declarations for standard stream-based input and output facilities.

For example:

```cpp
std::cout
std::cin
std::cerr
```

We currently need `cout`.

Real-world analogy:

Imagine a workshop. Before using a particular tool, the workshop needs access to the toolbox containing that tool.

`<iostream>` gives our source file access to declarations for standard I/O tools.

## 6. Preprocessor

`#include` is a preprocessing directive.

Conceptually:

```text
source
  |
  v
preprocessor
  |
  v
compiler
```

You do not need to understand the preprocessor deeply yet.

## 7. main()

```cpp
int main() {
}
```

A normal standalone C++ program begins execution at `main()`.

Think of a large building with many rooms. The building still needs an entrance.

`main()` is the program's entry point.

Later we may have functions such as:

```text
main()
search()
sort()
solve()
```

Execution still begins through `main()`.

## 8. Why int main()?

`int` indicates that `main` returns an integer status.

We commonly write:

```cpp
return 0;
```

A return status of zero conventionally represents successful program termination.

In C++, reaching the end of `main()` without explicitly writing `return 0;` also returns zero.

## 9. Statements

A statement is an instruction.

Example:

```cpp
cout << "Hello";
```

Many C++ statements end with:

```text
;
```

Example:

```cpp
cout << "A";
cout << "B";
return 0;
```

Statements normally execute sequentially.

## 10. cout

`cout` represents the standard output stream.

Example:

```cpp
cout << "Hello";
```

The `<<` operator sends information into that output stream.

Conceptually:

```text
"Hello"
   |
   v
 cout
   |
   v
terminal
```

## 11. cout does not automatically create newlines

Consider:

```cpp
cout << "A";
cout << "B";
```

Output:

```text
AB
```

To move to another line:

```cpp
cout << "A\n";
cout << "B\n";
```

Output:

```text
A
B
```

## 12. Escape sequences

Some common escape sequences are:

| Sequence | Meaning |
|---|---|
| `\n` | newline |
| `\t` | tab |
| `\\` | backslash |
| `\"` | double quote |

Example:

```cpp
cout << "\"C++\"\n";
```

Output:

```text
"C++"
```

## 13. '\n' versus endl

Both can create a new line:

```cpp
cout << "Hello\n";
```

and:

```cpp
cout << "Hello" << endl;
```

But `endl` also flushes the output stream.

For ordinary DSA output, we will usually prefer:

```cpp
'\n'
```

## 14. Namespace std

The actual fully-qualified standard-library name is:

```cpp
std::cout
```

For example:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello\n";
}
```

This is valid without:

```cpp
using namespace std;
```

Beginner programs often use:

```cpp
using namespace std;
```

and then write:

```cpp
cout
```

Namespaces help prevent naming conflicts.

Imagine two cities each containing a `MainStreet`.

The city name distinguishes them:

```text
CityA::MainStreet
CityB::MainStreet
```

Similarly:

```cpp
std::cout
```

identifies `cout` from `std`.

## 15. Comments

Single-line:

```cpp
// comment
```

Multi-line:

```cpp
/*
comment
*/
```

Comments are intended for humans and are not executed as program instructions.

Useful comments explain reasoning rather than merely restating obvious code.

## 16. Compilation

Using g++:

```bash
g++ -std=c++17 main.cpp -o main
```

Breakdown:

```text
g++             compiler driver
-std=c++17      use C++17
main.cpp        source file
-o main         output executable
```

Run on Linux/macOS:

```bash
./main
```

Typical Windows PowerShell usage:

```powershell
.\main.exe
```

## 17. Compile time versus runtime

Compile time occurs while source code is being translated.

Runtime occurs while the resulting executable is executing.

```text
source
  |
  v
COMPILE TIME
  |
  v
executable
  |
  v
RUNTIME
  |
  v
result
```

## 18. Types of errors

Compilation/syntax errors prevent successful compilation.

Example:

```cpp
cout << "Hello"
```

The semicolon is missing.

Linker errors happen when the linker cannot resolve something required to create the complete executable.

Runtime errors occur while the executable is running.

Logical errors are especially important in DSA: the program executes, but the algorithm produces an incorrect result.

## 19. Case sensitivity

C++ is case-sensitive.

These are different:

```text
cout
Cout
COUT
```

Likewise:

```text
main
Main
```

are different.

## 20. Dry run

Program:

```cpp
cout << "A";
cout << "B";
cout << '\n';
cout << "C\n";
```

Initial state:

```text
output = ""
```

After the first statement:

```text
output = "A"
```

After the second:

```text
output = "AB"
```

After newline:

```text
AB
<cursor is now on next line>
```

After the final statement:

```text
AB
C
```

Final output:

```text
AB
C
```

## 21. Development workflow

Use this repeatedly:

```text
write
  |
  v
compile
  |
  v
fix compilation errors
  |
  v
run
  |
  v
compare actual vs expected output
  |
  v
debug
```

## Complexity

| Operation | Simplified time | Auxiliary space |
|---|---:|---:|
| Fixed simple statement | O(1) | O(1) |
| Print string of length n | O(n) | O(1)* |
| k sequential constant-work statements | O(k) | O(1) |

`*` This is a simplified algorithmic model; real stream I/O uses buffering and implementation/OS resources.

Complexity will be studied formally later.

## Common mistakes

1. Forgetting `;`.
2. Writing `Main` instead of `main`.
3. Forgetting `#include <iostream>`.
4. Writing `cout` without making `std::cout` available.
5. Expecting `cout` to automatically print a newline.
6. Confusing compilation with execution.
7. Ignoring compiler diagnostics.
8. Assuming a program is correct merely because it runs.
9. Copying code without predicting its output.
10. Assuming `#include <bits/stdc++.h>` is standard C++; it is a common GCC convenience, not an ISO C++ header.

## Practice

1. GFG C++ Programming Language  
   https://www.geeksforgeeks.org/c-plus-plus/

2. GFG Basic Input/Output  
   https://www.geeksforgeeks.org/basic-input-output-c/

3. HackerRank Hello World  
   https://www.hackerrank.com/challenges/cpp-hello-world/problem

4. HackerRank C++ Input and Output  
   https://www.hackerrank.com/challenges/cpp-input-and-output/problem

5. LeetCode Problemset  
   https://leetcode.com/problemset/

Because this is the very first folder, focus primarily on compiling tiny programs yourself rather than trying advanced LeetCode problems.

## What's Next

`01_C++__/02_VARIABLES_AND_DATA_TYPES/`
