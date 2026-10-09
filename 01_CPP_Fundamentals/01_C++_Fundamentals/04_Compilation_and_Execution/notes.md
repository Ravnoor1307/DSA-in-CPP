

# Compilation and Execution in C++

## 1. Introduction

When we write a C++ program, the computer does not directly execute the human-readable source code in a `.cpp` file. The source code must be processed by a compiler and, in many cases, a linker to produce an executable program.

The overall process is commonly described as:

**Source Code → Preprocessing → Compilation → Assembly → Linking → Executable → Execution**

Understanding this process helps us write, build, run, and debug C++ programs.

---

## 2. Source Code

Source code is the human-readable code written by a programmer.

Example:

```
#include <iostream>

int main() {
    std::cout << "Hello, C++!" << '\n';
    return 0;
}
```

Save this code in a file named `hello.cpp`.

* **File extension:** `.cpp`

* **Purpose:** Contains C++ source code.

* **Readability:** Humans can read and edit it.

* **Execution:** It usually needs to be compiled before it can run as a native executable.

---

## 3. What Is a Compiler?

A compiler is a software tool that translates source code into a lower-level representation that a computer can execute.

Popular C++ compiler toolchains include:

* **GCC:** Common on Linux and available on Windows through environments such as MinGW-w64.

* **Clang/LLVM:** Available on Linux, macOS, and other platforms.

* **Microsoft Visual C++ (MSVC):** Commonly used with Visual Studio on Windows.

A compiler also checks your code for many kinds of errors, such as invalid syntax and incompatible types.

### Compiler vs. Programming Language

C++ is a programming language. GCC, Clang, and MSVC are compiler toolchains that can compile C++ programs.

A code editor, such as Visual Studio Code, is not itself a C++ compiler. It can provide an interface for invoking a compiler installed on your system.

---

## 4. The Build Process

### Step 1: Preprocessing

The preprocessor handles directives that begin with `#`, such as:

```
#include <iostream>
#define MESSAGE "Hello"
```

For example, `#include <iostream>` makes the declarations provided by the standard input/output library available to the program.

Preprocessing also handles macros and conditional compilation directives.

### Step 2: Compilation

The compiler processes the preprocessed source code, checks language rules, and translates it into an assembly representation or another intermediate form as part of the toolchain.

Examples of errors detected during this stage include:

* Missing semicolons.

* Undeclared variables.

* Invalid expressions.

* Incompatible types.

### Step 3: Assembly

An assembler translates assembly instructions into machine-code object files.

Object files commonly use these extensions:

* `.o` on many Linux and Unix-like systems.

* `.obj` on Windows toolchains.

An object file is not necessarily a complete, runnable program.

### Step 4: Linking

The linker combines object files and resolves references to functions and other entities, including required library code.

For example, if your program calls a function defined in another source file, the linker helps connect the call to its definition.

A linker error can occur when a required definition cannot be found or when symbols conflict.

### Step 5: Executable Creation

After successful linking, the toolchain produces an executable file.

Common examples include:

* `program.exe` on Windows.

* `program` on Linux.

* An executable binary on macOS, often without a file extension.

The exact file format and extension depend on the operating system and toolchain.

### Step 6: Execution

The operating system loads and runs the executable.

The program performs its operations and may display output, read input, modify files, or carry out other tasks.

---

## 5. Compiler, Linker, and Runtime

| Component           | Main responsibility                                                       |
| ------------------- | ------------------------------------------------------------------------- |
| Preprocessor        | Handles directives such as `#include` and `#define`.                      |
| Compiler            | Checks and translates C++ source code.                                    |
| Assembler           | Produces machine-code object files from assembly.                         |
| Linker              | Combines object files and resolves external references.                   |
| Operating system    | Loads and runs the executable.                                            |
| Runtime environment | Provides the execution support required by the program and its libraries. |

These stages are related, but they are not interchangeable.

---

## 6. Compile and Run Your First Program

Suppose `hello.cpp` contains:

```
#include <iostream>

int main() {
    std::cout << "Hello, C++!" << '\n';
    return 0;
}
```

### Compile using GCC or a compatible `g++` installation

```
g++ hello.cpp -o hello
```

This asks `g++` to compile `hello.cpp` and create an executable named `hello` (or `hello.exe` on Windows).

For useful warnings during learning, use:

```
g++ -std=c++17 -Wall -Wextra -pedantic hello.cpp -o hello
```

What the options mean:

* `-std=c++17`: Use the C++17 language standard.

* `-Wall`: Enable many common warnings.

* `-Wextra`: Enable additional warnings.

* `-pedantic`: Diagnose certain non-standard language extensions.

* `-o hello`: Choose the output executable's name.

C++17 is used here as a learning example; you can select another standard if your course or project requires it.

### Run on Windows PowerShell

```
.\hello.exe
```

### Run on Linux or macOS

```
./hello
```

Expected output:

```
Hello, C++!
```

**Important:** Compilation and execution are separate operations. Successfully compiling a program does not mean you have run it yet.

---

## 7. Common Types of Errors

### Syntax or Compilation Errors

These occur when the compiler cannot accept your source code.

Example:

```
#include <iostream>

int main() {
    std::cout << "Hello"
    return 0;
}
```

The output statement is missing a semicolon.

Correct version:

```
std::cout << "Hello";
```

### Linker Errors

These happen when the linker cannot resolve a required symbol or encounters another linking problem.

For example, declaring a function but never providing its required definition can cause a linker error if the program uses that function.

### Runtime Errors

These occur while the program is running.

Examples include:

* Trying to open a file that does not exist and failing to handle the failure.

* Accessing memory incorrectly.

* Dividing an integer by zero on typical implementations, which causes undefined behavior in C++.

A program can compile successfully and still have runtime errors.

### Logical Errors

A logical error occurs when the program runs but produces an incorrect result.

Example:

```
int length = 5;
int width = 3;

int area = length + width;  // Incorrect formula
```

The correct formula for the area of a rectangle is:

```
int area = length * width;
```

Logical errors often require testing, tracing, and careful reasoning to identify.

---

## 8. Warnings vs. Errors

* **Error:** A problem that prevents a particular build stage from succeeding.

* **Warning:** A diagnostic about code that may be unsafe, suspicious, non-portable, or unintended.

A compiler may produce an executable even when warnings are present. Do not ignore warnings simply because the program runs.

Using `-Wall -Wextra -pedantic` is a useful starting point, but these options do not detect every possible bug.

---

## 9. The `main()` Function and Program Exit

A typical hosted C++ program starts execution at `main()`.

```
int main() {
    return 0;
}
```

Returning `0` conventionally indicates successful program termination. A nonzero return value is commonly used to indicate failure.

You may also write:

```
int main() {
    return 0;
}
```

without an explicit return statement, because reaching the closing brace of `main()` is equivalent to returning `0`.

---

## 10. Important Concepts to Remember

1. A `.cpp` file contains source code, not necessarily a runnable executable.

2. A compiler toolchain transforms source code into a program that can run on a target platform.

3. Linking is needed to combine object files and resolve references.

4. Compilation and execution are different steps.

5. Compilation errors, linker errors, runtime errors, and logical errors have different causes.

6. Warnings can reveal bugs even when a program compiles successfully.

7. The command to run an executable depends on your operating system and shell.

8. Compiler flags help control the language standard and the diagnostics you receive.

---

## 11. Quick Review

**Q1. What is compilation?**

The process of translating source code through the compiler toolchain into a form that can be linked and executed.

**Q2. What does a linker do?**

It combines object files and resolves references to required functions and other symbols.

**Q3. Can a program compile successfully but still be incorrect?**

Yes. It may contain runtime or logical errors.

**Q4. What does** `**-o hello**` **do in a** `**g++**` **command?**

It specifies the name of the output file.

**Q5. What is the difference between source code and an executable?**

Source code is human-readable program text; an executable is a platform-specific file that the operating system can run.

**Q6. Why should you enable compiler warnings?**

Warnings can help identify suspicious code and potential bugs before or during testing.
