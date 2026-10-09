# History and Features of C++

## 1. Introduction

C++ is a general-purpose programming language developed by Bjarne Stroustrup. It evolved from the C programming language and introduced features that support data abstraction, object-oriented programming, and generic programming.

C++ is widely used in systems software, game development, embedded systems, performance-critical applications, and competitive programming.

## 2. History of C++

### 2.1 The C Programming Language

The C programming language was developed by Dennis Ritchie at Bell Laboratories during the early 1970s.

C became popular because it offered:

* Efficient execution.

* A relatively small language.

* Direct access to low-level operations.

* Support for structured and procedural programming.

* Portability across different computer systems.

However, developers wanted additional tools for organizing large programs and representing complex data abstractions.

### 2.2 The Beginning of C++

Bjarne Stroustrup began developing a language called **C with Classes** in 1979 at Bell Laboratories.

His goal was to combine the efficiency and flexibility of C with features that made it easier to organize and manage large software systems.

C with Classes introduced concepts such as:

* Classes.

* Data abstraction.

* Derived classes.

* Stronger support for organizing complex programs.

### 2.3 The Name C++

In 1983, the language was renamed **C++**.

The name uses the C increment operator, `++`, as a reference to C with additional capabilities.

### 2.4 Standardization

As C++ became more widely used, a formal standard became necessary so different compiler implementations could support a common language specification.

The first ISO C++ standard was published in **1998**, commonly called C++98.

Subsequent standards introduced additional language features and library improvements.

## 3. Important C++ Versions

| Version | Year                                                               | Major developments                                                                                       |
| ------- | ------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------- |
| C++98   | 1998                                                               | First ISO C++ standard                                                                                   |
| C++03   | 2003                                                               | Corrections and clarifications to C++98                                                                  |
| C++11   | 2011                                                               | Major update introducing features such as `auto`, lambda expressions, move semantics, and smart pointers |
| C++14   | 2014                                                               | Improvements and refinements to C++11                                                                    |
| C++17   | 2017                                                               | Features such as structured bindings and `if constexpr`                                                  |
| C++20   | 2020                                                               | Major features including concepts, ranges, and modules                                                   |
| C++23   | 2023                                                               | Further language and library enhancements                                                                |
| C++26   | In progress during earlier development; standard published in 2026 | New language and library capabilities                                                                    |

**Note:** The C++ standard defines the language and library. Compiler support for individual features can vary by compiler version.

## 4. Major Features of C++

### 4.1 General-Purpose Language

C++ can be used to develop many kinds of software, including games, desktop applications, system tools, and embedded software.

### 4.2 High Performance

C++ provides efficient compiled execution and gives developers considerable control over memory layout and resource usage.

Actual performance depends on the program, algorithms, compiler, and optimization settings.

### 4.3 Statically Typed

Variables and expressions have types that are checked primarily at compile time.

Example:

```
int age = 20;
double price = 49.99;
char grade = 'A';
```

The declared types help the compiler detect many programming mistakes.

### 4.4 Procedural Programming

C++ supports functions and step-by-step instructions.

Example:

```
#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    std::cout << a + b << '\n';
    return 0;
}
```

### 4.5 Object-Oriented Programming

C++ supports classes and objects for organizing data and behavior.

Important concepts include:

* Encapsulation.

* Abstraction.

* Inheritance.

* Polymorphism.

### 4.6 Generic Programming

Templates allow programmers to create reusable functions and classes that work with multiple data types.

The Standard Template Library uses generic programming extensively.

### 4.7 Standard Library

The C++ standard library provides reusable facilities such as:

* Strings.

* Containers.

* Algorithms.

* Iterators.

* Input/output streams.

* Smart pointers.

* Utility types.

Examples include `std::string`, `std::vector`, and `std::sort`.

### 4.8 Memory Management

C++ provides direct control over object lifetimes and dynamic memory, while also supporting safer automatic resource management through techniques such as RAII and smart pointers.

Examples of smart pointers include:

* `std::unique_ptr`

* `std::shared_ptr`

* `std::weak_ptr`

### 4.9 Portability

Standard-conforming C++ programs can often be compiled on different platforms with relatively few changes. Platform-specific APIs, compiler extensions, and system dependencies can reduce portability.

### 4.10 Multi-Paradigm Programming

C++ supports several programming styles:

* Procedural programming.

* Object-oriented programming.

* Generic programming.

* Functional-style programming.

Programmers can combine these styles when appropriate.

## 5. Advantages of C++

* High performance for many workloads.

* Strong support for data structures and algorithms.

* A powerful standard library.

* Control over memory and resource lifetimes.

* Suitable for both low-level and high-level software.

* Broad use in industry and competitive programming.

## 6. Limitations of C++

* The language has many features and can be challenging for beginners.

* Compiler errors can be complex.

* Manual memory management can introduce bugs.

* Undefined behavior can cause unpredictable results.

* Large projects can require careful build and dependency management.

## 7. C++ vs C

| Feature              | C                           | C++                                            |
| -------------------- | --------------------------- | ---------------------------------------------- |
| Programming style    | Primarily procedural        | Multi-paradigm                                 |
| Classes and objects  | Not built in                | Supported                                      |
| Function overloading | Not supported in standard C | Supported                                      |
| Templates            | Not supported               | Supported                                      |
| Standard library     | C standard library          | C++ standard library plus C library facilities |
| Memory management    | Explicit allocation APIs    | Explicit control plus RAII and smart pointers  |

C++ retains substantial compatibility with C, but the two languages are distinct and not every valid C program is valid C++.

## 8. Where C++ Is Used

Common applications include:

* Game engines and game systems.

* Operating-system components.

* Browsers and desktop software.

* Embedded systems and robotics.

* Scientific computing.

* Financial and performance-critical systems.

* Competitive programming.

* Data Structures and Algorithms practice.

## 9. Example: Using a Standard Library Feature

The following example demonstrates `std::sort`, a standard library algorithm.

```
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 3};

    std::sort(numbers.begin(), numbers.end());

    for (int number : numbers) {
        std::cout << number << ' ';
    }

    std::cout << '\n';
    return 0;
}
```

Output:

```
1 2 3 5 8
```

This example demonstrates how C++ combines efficient containers and reusable algorithms.

## 10. Key Takeaways

* Bjarne Stroustrup began developing C with Classes in 1979.

* The language was renamed C++ in 1983.

* C++98 was the first ISO C++ standard, published in 1998.

* C++ supports procedural, object-oriented, and generic programming.

* Its standard library provides containers, algorithms, and other reusable facilities.

* C++ offers performance and resource control but requires care around memory safety and undefined behavior.

## 11. Revision Questions

1. Who developed C++?

2. What was the original name of C++?

3. In which year was C++ renamed?

4. When was the first ISO C++ standard published?

5. Name five important features of C++.

6. What is object-oriented programming?

7. What is generic programming?

8. What is the purpose of the C++ standard library?

9. Name three differences between C and C++.

10. Give five real-world uses of C++.

11. What are two advantages and two limitations of C++?

12. What does `std::sort` do?

## 12. Completion Checklist

* Understand the origins of C++.

* Remember the key dates in its history.

* Understand its major features.

* Explain the differences between C and C++.

* Compile and run the example program.

* Answer the revision questions independently.
