# What Is C++?

## 1. Introduction

C++ is a general-purpose, statically typed, compiled programming language. It supports procedural programming, object-oriented programming, and generic programming.

C++ is widely used for developing high-performance applications, games, systems software, embedded systems, and competitive programming solutions.

## 2. What Does General-Purpose Mean?

A general-purpose programming language can be used to develop many different kinds of software rather than being restricted to one specific task.

C++ can be used for:

* Game development
* Operating-system components
* Desktop applications
* Embedded systems
* Robotics
* Competitive programming
* Data Structures and Algorithms (DSA)
* Performance-critical applications

## 3. Important Characteristics of C++

### 3.1 Compiled Language

C++ source code is generally compiled into machine code or another compiled representation before execution.

A compiler such as GCC's `g++` translates C++ source code into executable code.

### 3.2 Statically Typed Language

In C++, types are checked primarily at compile time.

Example:

```cpp
int age = 20;
double price = 99.50;
char grade = 'A';
```

Each variable has a declared type that determines the kinds of values and operations it supports.

### 3.3 Procedural Programming

C++ allows programs to be organized into functions that perform specific tasks.

Example:

```cpp
#include <iostream>

int main() {
    std::cout << "Learning C++" << '\n';
    return 0;
}
```

### 3.4 Object-Oriented Programming

C++ supports classes and objects, which allow data and related operations to be organized together.

Important concepts include:

* Classes and objects
* Encapsulation
* Inheritance
* Polymorphism
* Abstraction

### 3.5 Generic Programming

C++ supports templates, which allow reusable functions and classes to work with different types.

Templates will be studied in more detail later.

### 3.6 Performance and Memory Control

C++ provides features that allow programmers to control resource usage and write efficient software. It also provides automatic resource-management techniques, including RAII and smart pointers.

## 4. Source Code, Compiler, and Machine Code

### Source Code

Source code is the human-readable program written by a programmer.

C++ source files commonly use the `.cpp` extension.

### Compiler

A compiler translates source code into a form that can be executed or further processed. The build process may also involve preprocessing and linking.

### Machine Code

Machine code consists of processor instructions encoded in a form the computer's CPU can execute.

### Executable

An executable is a program file produced by the build process. On Windows, it commonly has the `.exe` extension.

## 5. How a C++ Program Runs

A simplified build and execution process is:

1. Write the program in a `.cpp` file.
2. Preprocess directives such as `#include`.
3. Compile the source code.
4. Assemble and link the required code.
5. Run the resulting executable.
6. Observe the program's output.

The exact build process depends on the compiler and development environment.

## 6. First C++ Program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << '\n';
    return 0;
}
```

Output:

```text
Hello, World!
```

## 7. Explanation of the First Program

* `#include <iostream>` provides standard input/output facilities.
* `int main()` defines the main function of a hosted C++ program.
* `{` begins the function body.
* `std::cout` writes output to the standard output stream.
* `<<` inserts data into the output stream.
* `"Hello, World!"` is a string literal.
* `'\n'` inserts a newline character.
* `return 0;` indicates successful completion.
* `}` ends the function body.

## 8. Compiler vs Code Editor vs IDE

### Compiler

A compiler translates source code into executable code.

Example: GCC's `g++`.

### Code Editor

A code editor helps programmers write and modify source files.

Example: Visual Studio Code.

### Integrated Development Environment (IDE)

An IDE combines coding tools and commonly provides build and debugging facilities.

Example: Microsoft Visual Studio.

An editor does not necessarily include a C++ compiler, so the required compiler and configuration must be installed separately.

## 9. C++ vs Python

| Feature                | C++                                                 | Python                                              |
| ---------------------- | --------------------------------------------------- | --------------------------------------------------- |
| Type system            | Statically typed                                    | Dynamically typed                                   |
| Common execution model | Compiled to machine code                            | Commonly executed through a language implementation |
| Syntax                 | More explicit declarations                          | Generally more concise                              |
| Memory management      | Supports low-level control and automatic techniques | Commonly uses automatic memory management           |
| Common applications    | Systems, games, DSA                                 | Automation, data science, ML                        |

Neither language is universally better. The appropriate choice depends on the application.

## 10. Important Terms

| Term                 | Meaning                                                    |
| -------------------- | ---------------------------------------------------------- |
| Programming language | A language used to express instructions for a computer     |
| Source code          | Human-readable program instructions                        |
| Compiler             | A tool that translates source code                         |
| Machine code         | Processor-executable instructions                          |
| Executable           | A program file that can be run                             |
| Syntax               | The rules governing valid program structure                |
| IDE                  | An integrated development environment                      |
| Standard library     | Facilities provided by the C++ implementation and standard |

## 11. Key Takeaways

* C++ is a general-purpose, statically typed programming language.
* It supports procedural, object-oriented, and generic programming.
* C++ source files commonly use the `.cpp` extension.
* A compiler translates source code as part of the build process.
* `main()` is the usual entry point of a hosted C++ program.
* `std::cout` is used for output.
* `return 0;` conventionally indicates successful completion.

## 12. Revision Questions

1. What is C++?
2. What does general-purpose mean?
3. What is a compiler?
4. What is the difference between source code and machine code?
5. What is an executable?
6. What is the role of `main()`?
7. What does `std::cout` do?
8. What is the difference between a compiler and an IDE?
9. Name five applications of C++.
10. How does C++ differ from Python?

## 13. Completion Criteria

Before moving to the next topic, make sure you can:

* Explain C++ in your own words.
* Describe the basic compilation process.
* Identify the important parts of the first C++ program.
* Compile and run a simple C++ program.
* Answer the revision questions without relying entirely on these notes.
