# 27 — Namespaces and Header Files

## Learning goals

Real C++ programs are usually split across many files and contain code
from many libraries. Namespaces and header files help organize that
code safely.

By the end of this lesson, you should understand:

- why namespaces exist
- namespace syntax
- the scope-resolution operator `::`
- nested namespaces
- namespace aliases
- `using` declarations
- `using namespace`
- name ambiguity
- anonymous namespaces
- declarations versus definitions
- header files
- source files
- `#include`
- quoted versus angle-bracket includes
- header guards
- `#pragma once`
- translation units
- separate compilation
- linking
- external and internal linkage basics
- the One Definition Rule at a beginner level
- forward declarations
- incomplete types
- why templates are usually defined in headers
- `inline` and header definitions
- what should and should not normally appear in a header
- multi-file compile commands

---

## 1. Why namespaces exist

Suppose two libraries both define:

```cpp
void print();
```

Without a mechanism for separating names, the compiler may not know
which function you want.

Namespaces create named scopes.

Example:

```cpp
namespace first {
    void print() {
        cout << "first";
    }
}

namespace second {
    void print() {
        cout << "second";
    }
}
```

Now the names are:

```text
first::print
second::print
```

There is no collision.

---

## 2. Real-world analogy

Imagine two apartment buildings.

Both can contain:

```text
Apartment 101
```

The apartment number alone is ambiguous.

The fully qualified location is more like:

```text
BuildingA::Apartment101
BuildingB::Apartment101
```

Namespaces similarly let identical local names coexist inside different
named scopes.

---

## 3. Basic namespace syntax

```cpp
namespace math {
    int square(int value) {
        return value * value;
    }
}
```

Access the function with:

```cpp
math::square(5);
```

The `::` operator is the scope-resolution operator.

It tells C++ which scope contains the name.

---

## 4. The global namespace

Names declared outside named namespaces, classes, and functions may
belong to the global namespace.

Example:

```cpp
int value = 10;
```

Inside a function containing another `value`, the global one can be
accessed with:

```cpp
::value
```

Example:

```cpp
int value = 10;

int main() {
    int value = 20;

    cout << value;   // 20
    cout << ::value; // 10
}
```

---

## 5. Nested namespaces

Namespaces can be nested:

```cpp
namespace company {
    namespace graphics {
        void draw() {
        }
    }
}
```

Usage:

```cpp
company::graphics::draw();
```

C++17 also allows:

```cpp
namespace company::graphics {
    void draw() {
    }
}
```

This is convenient for deeply organized libraries.

---

## 6. Reopening a namespace

A namespace does not have to be defined in one block.

This is valid:

```cpp
namespace tools {
    void first() {
    }
}

namespace tools {
    void second() {
    }
}
```

Both functions belong to:

```text
tools
```

This property is important because library code may contribute to the
same namespace from multiple files.

---

## 7. Namespace aliases

Long namespace paths can be shortened:

```cpp
namespace graphics = company::graphics;
```

Then:

```cpp
graphics::draw();
```

can be used.

Aliases are especially useful for deeply nested third-party namespaces.

---

## 8. `using` declarations

Instead of repeatedly writing:

```cpp
std::cout
```

you can introduce one specific name:

```cpp
using std::cout;
```

Then:

```cpp
cout << "Hello";
```

works in that scope.

This is called a using declaration.

It imports one selected name.

---

## 9. `using namespace`

You have frequently seen:

```cpp
using namespace std;
```

This makes names from `std` available for unqualified lookup in the
relevant scope.

It is convenient for small learning programs, but using directives can
increase the chance of name collisions.

In larger code, especially header files, prefer qualification:

```cpp
std::cout
std::string
std::vector
```

or carefully chosen using declarations.

---

## 10. Why `using namespace std;` is especially undesirable in headers

Suppose a header contains:

```cpp
using namespace std;
```

Every source file including that header now has the directive affecting
lookup in ways the source file did not explicitly request.

Headers are shared interfaces.

They should avoid unnecessarily changing the name-lookup environment of
their users.

A strong rule for this repository is:

```text
Do not put `using namespace std;` in reusable header files.
```

---

## 11. Namespace ambiguity

Consider:

```cpp
namespace A {
    int value = 10;
}

namespace B {
    int value = 20;
}
```

If both namespaces are introduced broadly:

```cpp
using namespace A;
using namespace B;
```

then:

```cpp
cout << value;
```

can be ambiguous.

Qualification solves the problem:

```cpp
cout << A::value;
cout << B::value;
```

Explicit qualification often improves readability.

---

## 12. Anonymous namespaces

A namespace without a name looks like:

```cpp
namespace {
    int helper() {
        return 42;
    }
}
```

Names inside an anonymous namespace have internal linkage semantics
appropriate for making them local to the translation unit.

This is useful for implementation details that should not be exposed
to other `.cpp` files.

Conceptually:

```text
file1.cpp
    private helper implementation

file2.cpp
    cannot link directly to that helper
```

For `.cpp`-local helpers, anonymous namespaces are common modern C++.

---

# Part II — Declarations and Definitions

## 13. Declaration versus definition

A declaration introduces a name and enough information for the compiler
to understand how it may be used.

Example:

```cpp
int add(int a, int b);
```

This declares a function.

A definition supplies its implementation:

```cpp
int add(int a, int b) {
    return a + b;
}
```

A function can be declared before its definition.

---

## 14. Why declarations are useful

Suppose:

```cpp
int main() {
    cout << add(2, 3);
}
```

appears before the compiler has seen `add`.

A prior declaration:

```cpp
int add(int, int);
```

tells the compiler:

```text
There is a function called add.
It takes two ints.
It returns int.
```

The implementation can appear later or in another source file.

---

## 15. Header files

A header commonly stores declarations and definitions that must be
visible to multiple translation units.

Example:

```cpp
// math_utils.h

int add(int a, int b);
int subtract(int a, int b);
```

A source file can include it:

```cpp
#include "math_utils.h"
```

The preprocessor handles the include before compilation.

At a simplified beginner level, you can think of `#include` as making
the header's contents available at that location.

The actual preprocessing model has additional details.

---

## 16. Header and source separation

A common structure is:

```text
project/
├── math_utils.h
├── math_utils.cpp
└── main.cpp
```

`math_utils.h`:

```cpp
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);

#endif
```

`math_utils.cpp`:

```cpp
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}
```

`main.cpp`:

```cpp
#include <iostream>
#include "math_utils.h"

int main() {
    std::cout << add(2, 3);
}
```

Compile:

```bash
g++ -std=c++17 main.cpp math_utils.cpp -o app
```

Run:

```bash
./app
```

---

## 17. Why include your own header in its `.cpp`

Suppose:

```cpp
// math_utils.h
int add(int, int);
```

but accidentally:

```cpp
// math_utils.cpp
double add(double, double) {
    ...
}
```

If the implementation file includes its own public header, the compiler
has a better opportunity to detect inconsistencies.

Good style:

```cpp
#include "math_utils.h"
```

near the top of `math_utils.cpp`.

---

## 18. Angle brackets versus quotes

Standard-library headers use:

```cpp
#include <iostream>
#include <string>
```

Project headers commonly use:

```cpp
#include "math_utils.h"
```

Roughly:

```text
<...>  -> implementation/system include search rules
"..."  -> commonly searches relative/project locations first,
          then other configured include paths
```

Precise lookup rules depend on the compiler and build configuration.

---

# Part III — Header Guards

## 19. The repeated-inclusion problem

Suppose:

```text
a.h includes common.h
b.h includes common.h
main.cpp includes a.h and b.h
```

Conceptually:

```text
main.cpp
├── a.h
│   └── common.h
└── b.h
    └── common.h
```

Without protection, declarations/definitions from `common.h` may be
processed more than once in the same translation unit.

Some declarations tolerate repetition, while definitions such as class
definitions cannot simply be duplicated in the same translation unit.

Header guards solve this.

---

## 20. Header guards

Typical pattern:

```cpp
#ifndef DSA_MATH_UTILS_H
#define DSA_MATH_UTILS_H

// Header contents

#endif
```

First include:

```text
DSA_MATH_UTILS_H is not defined
-> define it
-> process header
```

Second include in the same translation unit:

```text
DSA_MATH_UTILS_H is already defined
-> skip protected contents
```

---

## 21. `#pragma once`

Many compilers also support:

```cpp
#pragma once
```

at the top of a header.

It asks the implementation to process the header once per translation
unit.

It is widely supported, concise, and commonly used.

However, traditional macro include guards are a portable standard
preprocessor technique and are important to understand.

---

## 22. Include guards do not solve every ODR problem

A guard stops repeated processing of the same guarded header within one
translation unit.

It does not mean you can put arbitrary non-inline global definitions in
a header included by many `.cpp` files.

Example of problematic header design:

```cpp
int globalCounter = 0;
```

If included into several translation units, this can create multiple
definitions of the same externally linked entity.

C++17 offers tools such as:

```cpp
inline variables
```

when a header-defined global entity is appropriate.

But ordinary headers should generally avoid accidental global
definitions.

---

# Part IV — Translation Units and Linking

## 23. What is a translation unit?

After preprocessing a `.cpp` file and its included headers, the
compiler effectively works with a translation unit.

Suppose:

```text
main.cpp
math_utils.cpp
```

These are compiled separately:

```text
main.cpp       -> object code
math_utils.cpp -> object code
```

Then the linker combines the pieces.

Conceptually:

```text
source + headers
      |
      v
preprocessing
      |
      v
translation unit
      |
      v
compiler
      |
      v
object file
      |
      +------+
             |
other object files
             |
             v
           linker
             |
             v
         executable
```

---

## 24. Separate compilation

You can explicitly compile in stages.

Linux/macOS-style commands:

```bash
g++ -std=c++17 -c main.cpp -o main.o
g++ -std=c++17 -c math_utils.cpp -o math_utils.o
g++ main.o math_utils.o -o app
```

First command:

```text
compile main.cpp -> main.o
```

Second:

```text
compile math_utils.cpp -> math_utils.o
```

Third:

```text
link object files -> app
```

This model is fundamental to larger C++ projects.

---

## 25. Compiler error versus linker error

Consider:

```cpp
int add(int, int);

int main() {
    return add(1, 2);
}
```

The compiler knows how `add` is declared, so compilation can succeed.

If no definition of `add` is linked, the linker may report an error
such as an undefined reference/unresolved external.

Conceptual distinction:

```text
Compiler:
"Is this source code valid given the declarations I can see?"

Linker:
"Can all required cross-file definitions be connected?"
```

Exact diagnostic wording depends on the toolchain.

---

# Part V — Linkage

## 26. External linkage basics

A normal non-static function defined at namespace scope typically has
external linkage:

```cpp
int add(int a, int b) {
    return a + b;
}
```

Other translation units can refer to it when they have an appropriate
declaration and the definition is linked into the program.

This is what makes header declarations plus `.cpp` definitions work.

---

## 27. Internal linkage basics

Sometimes an implementation detail should belong only to one
translation unit.

An anonymous namespace is a common approach:

```cpp
namespace {
    int helper(int x) {
        return x * 2;
    }
}
```

`helper` is not intended to be linked from another `.cpp`.

Namespace-scope `static` can also provide internal linkage:

```cpp
static int helper(int x) {
    return x * 2;
}
```

In modern C++, anonymous namespaces are generally preferred for
translation-unit-local implementation names.

Do not confuse this namespace-scope meaning of `static` with class
static members from the previous lesson.

---

## 28. `extern` basics

Suppose one source file defines:

```cpp
int globalValue = 42;
```

Another file may declare:

```cpp
extern int globalValue;
```

`extern` here declares that the definition exists elsewhere.

However, global mutable variables can create tightly coupled code.

Knowing `extern` is important, but do not use global state casually.

A header might contain:

```cpp
extern int globalValue;
```

and exactly one `.cpp` would contain its non-inline definition.

---

# Part VI — One Definition Rule

## 29. Beginner model of the ODR

C++ has rules collectively known as the One Definition Rule (ODR).

A practical beginner model is:

- declarations may often appear in multiple translation units
- many non-inline entities requiring one program-wide definition must
  have exactly one appropriate definition
- class definitions may appear in multiple translation units when they
  satisfy the ODR requirements, normally by coming from the same header
- inline functions and templates have rules designed for header-based
  use

Violating the ODR can lead to linker errors or, in some cases, more
subtle undefined behavior.

---

## 30. Function definition accidentally placed in a header

Suppose:

```cpp
// helper.h
int square(int x) {
    return x * x;
}
```

and multiple `.cpp` files include the header.

Without appropriate inline treatment, the program may end up with
multiple definitions of the same function across translation units.

A header-defined ordinary function should often be marked:

```cpp
inline int square(int x) {
    return x * x;
}
```

when header definition is actually desired.

Functions defined inside a class definition are implicitly inline for
ODR purposes.

---

## 31. What `inline` really means here

Historically, `inline` suggests that a compiler might substitute a
function body directly at the call site.

Modern compilers make optimization decisions independently.

For language organization, an important role of `inline` is that it
allows identical definitions of the same inline entity to appear in
multiple translation units under the ODR requirements.

Do not interpret:

```cpp
inline
```

as a command forcing the optimizer to remove a function call.

---

# Part VII — Forward Declarations

## 32. Forward-declaring a class

Sometimes code only needs to know that a type exists:

```cpp
class Engine;
```

This is a forward declaration.

At this point, `Engine` is incomplete.

You can declare certain things such as:

```cpp
Engine* pointer;
Engine& reference();
```

without knowing the full object layout.

---

## 33. What an incomplete type cannot do

After only:

```cpp
class Engine;
```

you generally cannot create an object by value:

```cpp
Engine engine; // full size/layout not known here
```

You also cannot access members whose declaration has not been seen.

To store an `Engine` object directly as a member:

```cpp
class Car {
    Engine engine;
};
```

the complete `Engine` definition must normally be available first.

---

## 34. Why forward declarations help

Forward declarations can reduce unnecessary header dependencies.

Suppose a class only stores:

```cpp
Engine* engine;
```

The header may sometimes forward-declare `Engine` rather than include
the complete engine header.

The implementation `.cpp` can include the complete definition when it
needs to call member functions or perform operations requiring the
complete type.

This can improve compilation dependencies in large projects.

Ownership and destructor details can complicate incomplete-type
designs, especially with smart pointers, so treat this as the basic
model for now.

---

# Part VIII — Templates and Headers

## 35. Why templates are usually defined in headers

You learned templates in the previous folder.

Suppose a header contains only:

```cpp
template <typename T>
T maximum(T a, T b);
```

but the definition lives privately inside a normal `.cpp`.

When another translation unit tries:

```cpp
maximum<int>(1, 2);
```

the compiler generally needs the template definition to instantiate
that specialization.

Therefore templates are usually defined in headers:

```cpp
template <typename T>
T maximum(T a, T b) {
    return a < b ? b : a;
}
```

There are explicit-instantiation techniques, but they are not needed
for beginner DSA code.

---

## 36. Namespaces across headers and source files

A clean organization might be:

```cpp
// math_utils.h
namespace dsa {
    int add(int a, int b);
}
```

Implementation:

```cpp
// math_utils.cpp
#include "math_utils.h"

namespace dsa {
    int add(int a, int b) {
        return a + b;
    }
}
```

Usage:

```cpp
#include "math_utils.h"

int main() {
    return dsa::add(2, 3);
}
```

Namespaces and file separation solve different problems:

```text
namespace:
organizes names

header/source separation:
organizes declarations and implementations across translation units
```

They work well together.

---

## 37. What normally belongs in a header?

Common header contents include:

```text
class declarations/definitions
function declarations
template definitions
inline function definitions
type aliases
enum definitions
compile-time constants when designed appropriately
```

Headers should be self-contained where practical.

A source file that includes a header should not need mysterious prior
includes for the header to compile.

---

## 38. What normally belongs in a `.cpp`?

Common `.cpp` contents include:

```text
non-inline function definitions
out-of-class method definitions
private implementation helpers
anonymous-namespace helpers
definitions of non-inline externally linked entities
```

Separating interface from implementation helps larger projects stay
manageable.

---

## 39. Avoid unnecessary includes

If a file does not need a header, do not include it simply out of habit.

Unnecessary includes can:

- increase compile time
- increase dependency coupling
- accidentally make code depend on transitive includes

For example, do not assume one standard header always includes another
header you actually use.

If you directly use `std::string`, include:

```cpp
#include <string>
```

rather than hoping `<iostream>` happens to make it available.

---

## 40. Include what you use

A useful principle is:

```text
Include the headers required for the names you directly use.
```

This makes dependencies explicit.

Likewise, a reusable header should include what it needs for the types
that must be complete in its own declarations.

Forward declarations can sometimes replace full includes, but only when
the incomplete type is sufficient.

---

## 41. Include cycles

Suppose:

```text
A.h includes B.h
B.h includes A.h
```

Header guards prevent infinite textual inclusion, but they do not
automatically make the type dependency valid.

If both classes only need pointers/references to one another, forward
declarations may help break the cycle.

Example:

```cpp
// A.h
class B;

class A {
private:
    B* partner;
};
```

Then the implementation file can include `B.h` when it needs the full
definition.

---

## 42. Dry run: multi-file compilation

Project:

```text
math.h
math.cpp
main.cpp
```

`main.cpp` includes:

```cpp
#include "math.h"
```

The compiler sees the declaration:

```cpp
int add(int, int);
```

So this call is valid:

```cpp
add(2, 3)
```

Meanwhile:

```text
math.cpp
```

provides the definition.

Compilation:

```text
main.cpp -> main.o
math.cpp -> math.o
```

Linking:

```text
main.o + math.o -> executable
```

The linker connects the call from `main.o` to the definition in
`math.o`.

---

## 43. Dry run: namespace lookup

Suppose:

```cpp
namespace first {
    int value = 10;
}

namespace second {
    int value = 20;
}
```

Expression:

```cpp
first::value
```

lookup proceeds in:

```text
first namespace
```

Result:

```text
10
```

Expression:

```cpp
second::value
```

lookup proceeds in:

```text
second namespace
```

Result:

```text
20
```

The namespaces allow the identical local name `value` to coexist.

---

## 44. DSA repository organization

As your DSA repository grows, multi-file design becomes useful.

A larger exercise might eventually contain:

```text
graph.h
graph.cpp
main.cpp
```

or template structures such as:

```text
stack.h
main.cpp
```

with a template implementation in the header.

Competitive-programming submissions are commonly kept in one source
file because online judges expect a single submission.

That is a submission constraint, not the normal organization model for
all C++ software.

---

## Complexity

Namespaces, declarations, and header organization are compile-time and
program-organization mechanisms.

They do not inherently alter an algorithm's runtime Big-O complexity.

| Concept | Runtime cost |
|---|---:|
| Namespace qualification | O(0) conceptual runtime overhead |
| Header inclusion | Compile-time/preprocessing concern |
| Function declaration | No runtime operation |
| Header guard | Preprocessing concern |
| Namespace alias | No runtime overhead |
| Forward declaration | No runtime overhead |
| Separate compilation | Build-time concern |
| Calling ordinary function | Depends on function/call optimization |
| Anonymous namespace | Linkage choice, not algorithmic cost |

The implementation of the functions still determines algorithmic
complexity.

---

## Common interview and beginner mistakes

1. Confusing namespaces with classes.

2. Assuming namespace qualification has runtime lookup cost.

3. Writing `using namespace std;` inside reusable headers.

4. Importing several namespaces broadly and causing ambiguity.

5. Forgetting `::` qualification.

6. Confusing a declaration with a definition.

7. Declaring a function but forgetting to link its definition.

8. Defining the same non-inline function in a header included by
   multiple translation units.

9. Believing include guards solve every multiple-definition problem.

10. Forgetting include guards or `#pragma once`.

11. Assuming `#include` dynamically loads code at runtime.

12. Confusing compiler errors with linker errors.

13. Forgetting to compile and link all required `.cpp` files.

14. Putting template definitions only in a normal `.cpp` and expecting
   arbitrary external instantiations to work.

15. Trying to create an object from only a forward declaration.

16. Accessing members of an incomplete type.

17. Creating circular header dependencies unnecessarily.

18. Depending accidentally on transitive includes.

19. Confusing namespace-scope `static` with a static class member.

20. Assuming `inline` guarantees machine-code inlining.

21. Defining global mutable state in headers carelessly.

22. Using `extern` without providing exactly the required definition.

---

## Practice questions and references

1. GeeksforGeeks — Namespaces in C++  
   https://www.geeksforgeeks.org/namespace-in-c/

2. GeeksforGeeks — Header Files in C/C++  
   https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/

3. cppreference — Namespace declaration  
   https://en.cppreference.com/w/cpp/language/namespace

4. cppreference — Definitions and ODR  
   https://en.cppreference.com/w/cpp/language/definition

5. cppreference — Language linkage / storage concepts  
   https://en.cppreference.com/w/cpp/language/storage_duration

For hands-on practice, split one of your previous classes into a
header, implementation `.cpp`, and `main.cpp`, then compile all source
files together.

---

## Revision checklist

Before moving on, make sure you can explain:

- namespace
- `::`
- nested namespaces
- namespace aliases
- using declarations
- using directives
- anonymous namespaces
- declarations versus definitions
- headers versus source files
- `#include`
- quotes versus angle brackets
- include guards
- `#pragma once`
- translation units
- compiling versus linking
- external linkage
- internal linkage
- `extern`
- beginner-level ODR rules
- `inline`
- forward declarations
- incomplete types
- template definitions in headers
- circular dependency basics
- why headers should avoid `using namespace std;`

# What's Next

Continue to:

`01_C++__/28_AUTO_RANGE_BASED_LOOPS/`

The next lesson introduces `auto`, type deduction, `const auto`,
`auto&`, `const auto&`, range-based `for`, copies versus references,
arrays and iterable objects, structured iteration patterns, and common
deduction pitfalls.
