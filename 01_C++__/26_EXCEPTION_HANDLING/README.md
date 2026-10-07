# 26 — Exception Handling in C++

## Learning goals

Exception handling lets a program report and handle exceptional
situations without requiring every function to encode failure into its
ordinary return value.

By the end of this lesson, you should understand:

- what an exception is
- `try`, `throw`, and `catch`
- control flow after `throw`
- matching handlers by type
- multiple `catch` blocks
- catching standard exceptions
- `std::exception`
- `what()`
- throwing standard exception objects
- `std::runtime_error`
- `std::invalid_argument`
- `std::out_of_range`
- custom exception classes
- catching by `const` reference
- catch ordering with inheritance
- `catch (...)`
- rethrowing with `throw;`
- stack unwinding
- destructor execution during unwinding
- why RAII matters
- exception safety concepts
- basic, strong, and no-throw guarantees
- constructors that throw
- destructors and exceptions
- `noexcept`
- exceptions versus normal validation
- exceptions in competitive programming and DSA

---

## 1. What problem do exceptions solve?

Suppose we write:

```cpp
int divide(int a, int b) {
    return a / b;
}
```

What happens if:

```cpp
b == 0
```

?

We could return a special integer such as `-1`, but `-1` could also be
a perfectly valid result:

```text
-10 / 10 = -1
```

We could also return a status through another parameter, but this makes
every call more complicated.

C++ exceptions provide another mechanism for reporting exceptional
failure.

---

## 2. Basic syntax

A function can throw:

```cpp
throw runtime_error("Something failed");
```

Code that may throw can execute inside a `try` block:

```cpp
try {
    riskyOperation();
}
catch (const runtime_error& error) {
    cout << error.what();
}
```

The three central keywords are:

```text
try
throw
catch
```

---

## 3. Real-world analogy

Imagine an office workflow.

A worker normally processes a document and returns a result.

But if the document is corrupted, continuing normally makes no sense.

Instead, the worker raises an incident.

The incident travels upward until it reaches someone responsible for
handling that kind of failure.

That resembles exception propagation:

```text
function detects exceptional failure
        |
        v
      throw
        |
        v
search for matching handler
        |
        v
      catch
```

---

## 4. Basic example

```cpp
int divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument(
            "denominator cannot be zero"
        );
    }

    return numerator / denominator;
}
```

Usage:

```cpp
try {
    cout << divide(10, 0);
}
catch (const invalid_argument& error) {
    cout << error.what();
}
```

Instead of continuing with invalid division, the function reports the
problem.

---

## 5. What happens after `throw`?

Consider:

```cpp
cout << "A\n";

throw runtime_error("failure");

cout << "B\n";
```

Once the exception is thrown, ordinary execution does not continue with
the next statement in that block.

Therefore:

```text
A
```

prints, but:

```text
B
```

does not execute through normal continuation.

Control transfers while searching for an appropriate handler.

---

## 6. Dry run: try, throw, catch

Consider:

```cpp
try {
    cout << "1\n";

    if (true) {
        throw runtime_error("problem");
    }

    cout << "2\n";
}
catch (const runtime_error& error) {
    cout << "Caught\n";
}

cout << "3\n";
```

Execution:

```text
Step 1:
enter try block

Step 2:
print 1

Step 3:
runtime_error is thrown

Step 4:
remaining code in try is skipped
"2" is not printed

Step 5:
matching runtime_error handler is found

Step 6:
catch block executes
print Caught

Step 7:
execution continues after handlers
print 3
```

Output:

```text
1
Caught
3
```

---

## 7. Exceptions have types

You can throw different types:

```cpp
throw 10;
throw string("error");
throw runtime_error("error");
```

But modern C++ code usually throws exception types derived from or
related to the standard exception hierarchy rather than arbitrary
primitive values.

Example:

```cpp
throw invalid_argument("negative size");
```

Typed exception objects communicate meaning better than unexplained
integers.

---

## 8. Standard exception hierarchy

C++ provides exception classes in headers such as:

```cpp
<exception>
<stdexcept>
```

A simplified conceptual hierarchy includes:

```text
std::exception
├── std::logic_error
│   ├── std::invalid_argument
│   ├── std::domain_error
│   ├── std::length_error
│   └── std::out_of_range
│
└── std::runtime_error
    ├── std::range_error
    ├── std::overflow_error
    └── std::underflow_error
```

Other standard exception types also exist.

The hierarchy lets callers handle either specific failures or broader
categories.

---

## 9. `what()`

Standard exception objects expose:

```cpp
what()
```

Example:

```cpp
catch (const exception& error) {
    cout << error.what();
}
```

`what()` provides an explanatory C-style string.

The exact text of library-generated standard exceptions may vary by
implementation, so programs should not usually depend on exact wording
from the standard library.

For exception objects you construct yourself:

```cpp
runtime_error("file operation failed")
```

the supplied message is available through `what()`.

---

## 10. Catch by const reference

Prefer:

```cpp
catch (const exception& error)
```

rather than:

```cpp
catch (exception error)
```

Why?

Catching by reference:

- avoids an unnecessary copy
- preserves the dynamic exception object's polymorphic behavior
- avoids slicing a derived exception into a base exception object

The `const` prevents accidental modification of the caught exception.

---

## 11. Multiple catch blocks

Different exception types can have different handlers:

```cpp
try {
    operation();
}
catch (const invalid_argument& error) {
    cout << "Bad argument";
}
catch (const out_of_range& error) {
    cout << "Bad index";
}
catch (const exception& error) {
    cout << "Other standard exception";
}
```

Handlers are considered in order.

This creates an important rule.

---

## 12. Catch derived exceptions before base exceptions

Suppose:

```cpp
invalid_argument
```

is handled through a base `exception` handler.

If you write:

```cpp
catch (const exception& error) {
}
catch (const invalid_argument& error) {
}
```

the broad base handler comes first and can make the more specific
handler unreachable for relevant matching behavior.

Prefer:

```cpp
catch (const invalid_argument& error) {
}
catch (const exception& error) {
}
```

Think:

```text
specific first
general later
```

---

## 13. Propagation across function calls

An exception does not need to be caught in the function that throws it.

Example:

```cpp
void level3() {
    throw runtime_error("failure");
}

void level2() {
    level3();
}

void level1() {
    level2();
}
```

Then:

```cpp
try {
    level1();
}
catch (const runtime_error& error) {
}
```

can handle the exception.

Conceptually:

```text
level1()
  |
  v
level2()
  |
  v
level3()
  |
 throw
  |
  v
search outward through active calls
  |
  v
matching catch
```

---

## 14. Stack unwinding

As an exception propagates out of active scopes, automatic objects
whose lifetimes end are destroyed.

This process is called stack unwinding.

Example:

```cpp
class Trace {
public:
    ~Trace() {
        cout << "destroyed\n";
    }
};

void work() {
    Trace trace;
    throw runtime_error("failure");
}
```

When the exception leaves `work()`, `trace` is destroyed.

This behavior is essential to safe C++ resource management.

---

## 15. Dry run: stack unwinding

Suppose:

```cpp
void inner() {
    Trace b("B");
    throw runtime_error("problem");
}

void outer() {
    Trace a("A");
    inner();
}
```

Call:

```cpp
try {
    outer();
}
catch (...) {
}
```

Flow:

```text
construct A
construct B

throw

B's scope is exited:
destroy B

outer cannot continue normally:
A's scope is exited
destroy A

matching handler is entered
```

This is why automatic resource-managing objects work naturally with
exceptions.

---

## 16. RAII and exceptions

Suppose a resource is manually acquired:

```cpp
int* data = new int[100];

riskyFunction();

delete[] data;
```

If:

```cpp
riskyFunction()
```

throws, ordinary flow may skip:

```cpp
delete[] data;
```

and memory leaks.

A resource-managing object's destructor can instead connect cleanup to
scope exit:

```text
acquire resource in object
        |
operation throws
        |
stack unwinds
        |
object destructor executes
        |
resource released
```

This is one of the strongest reasons RAII is central to C++.

Smart pointers and RAII get a dedicated lesson later.

---

## 17. Constructors can throw

A constructor may detect that an object cannot be validly created:

```cpp
class Percentage {
private:
    int value;

public:
    Percentage(int value) {
        if (value < 0 || value > 100) {
            throw invalid_argument(
                "percentage must be 0..100"
            );
        }

        this->value = value;
    }
};
```

If the constructor throws, construction of that complete object does
not finish.

Its destructor is not called because the complete object's lifetime
never successfully began.

However, fully constructed base/member subobjects are cleaned up
appropriately as construction unwinds.

This is another reason members should manage their own resources.

---

## 18. Destructors should not normally let exceptions escape

Destruction often occurs during stack unwinding.

If another exception escapes from a destructor while an exception is
already propagating, the program can terminate.

Therefore destructors are normally designed not to throw outward.

Modern destructors are normally `noexcept` by default under relevant
language rules unless their exception specification is affected by
members/bases.

A useful practical rule is:

```text
cleanup functions, especially destructors, should not fail by throwing
outward when ordinary cleanup must happen reliably
```

---

## 19. `noexcept`

A function can declare that exceptions are not supposed to escape it:

```cpp
void cleanup() noexcept {
}
```

If an exception nevertheless escapes a `noexcept` function, the
program calls:

```cpp
std::terminate()
```

`noexcept` is therefore a real contract, not merely documentation.

Example:

```cpp
int add(int a, int b) noexcept {
    return a + b;
}
```

Use it when you can genuinely guarantee that no exception will escape.

---

## 20. `noexcept` and move operations

Later, when studying move semantics and standard containers, you will
see that `noexcept` can matter to optimization and container behavior.

For example, some standard-library operations can prefer moving
objects when the move operation is known not to throw.

For now, remember:

```text
noexcept means an exception must not escape the function
```

---

## 21. Catch-all handler

C++ supports:

```cpp
catch (...) {
    cout << "Unknown exception";
}
```

This catches exceptions regardless of their type.

However, it does not directly provide the caught object.

It is useful at certain application boundaries, but broad catch-all
handlers should not silently hide failures without a good reason.

---

## 22. Rethrowing

Inside a handler:

```cpp
catch (const exception& error) {
    cout << "Logging: "
         << error.what()
         << '\n';

    throw;
}
```

The statement:

```cpp
throw;
```

rethrows the currently handled exception.

This preserves the original exception object.

It is useful when the current layer performs partial handling such as
logging but cannot fully recover.

---

## 23. Do not rethrow with accidental slicing

Suppose:

```cpp
catch (const exception& error) {
    throw error;
}
```

This creates a throw expression using the statically typed base
reference expression and can slice derived exception information.

Prefer:

```cpp
throw;
```

when your intention is to rethrow the currently handled exception
unchanged.

---

## 24. Custom exception types

You can create domain-specific exception classes.

Example:

```cpp
class InsufficientFunds
    : public runtime_error {
public:
    explicit InsufficientFunds(
        const string& message
    )
        : runtime_error(message) {
    }
};
```

Then:

```cpp
throw InsufficientFunds(
    "balance too low"
);
```

Caller:

```cpp
catch (const InsufficientFunds& error) {
}
```

The custom type communicates the specific failure.

---

## 25. Exceptions versus ordinary expected outcomes

Not every unsuccessful operation requires an exception.

Consider:

```cpp
bool findValue(...);
```

Failure to find an item may be a completely normal expected result.

Similarly:

```cpp
bool withdraw(int amount);
```

may reasonably return `false` when funds are insufficient if that is
an expected business condition.

Exceptions are generally more appropriate for situations where the
normal operation cannot continue as intended and the caller should
handle the exceptional condition separately.

There is no single rule that fits every API.

---

## 26. Avoid exceptions for normal loop control

Bad conceptual style:

```cpp
while (true) {
    try {
        processNext();
    }
    catch (EndOfItems&) {
        break;
    }
}
```

when reaching the end is an ordinary expected event.

Normal control flow should normally use:

```text
conditions
return values
iteration state
```

Exceptions communicate exceptional failure, not a replacement for
every `if`.

---

## 27. Exception safety guarantees

A useful way to discuss exception-safe code is through guarantees.

### No guarantee

After failure, state may be corrupted or invalid.

This is generally undesirable.

### Basic guarantee

If an exception occurs:

- no resource leaks
- invariants remain valid

But state may have changed.

### Strong guarantee

If an operation fails:

```text
observable state is unchanged
```

This resembles transaction semantics:

```text
operation succeeds completely
or
original state remains
```

### No-throw guarantee

The operation promises not to throw.

In C++, such a guarantee may be expressed with `noexcept` where
appropriate.

---

## 28. Strong guarantee example

Suppose an object contains:

```text
value = 10
```

Operation:

```text
setFromComplexCalculation(...)
```

A strong-exception-safe design may first calculate the new state in a
temporary.

Only after everything succeeds does it commit:

```text
Before:
value = 10

temporary calculation:
failure occurs

Object after failure:
value = 10
```

This pattern is related to ideas such as "commit after success."

Later RAII and move/copy lessons make these patterns easier to
understand.

---

## 29. Exceptions and raw resources

This pattern is fragile:

```cpp
int* data = new int[100];

operationThatMayThrow();

delete[] data;
```

A throw can skip cleanup.

Whenever possible, use automatic objects whose destructors own
cleanup.

Later you will use:

```cpp
unique_ptr
shared_ptr
vector
string
```

and other RAII types instead of manually coordinating `new`/`delete`.

---

## 30. What if no matching handler exists?

If an exception propagates outward without being handled, the program
eventually calls termination machinery.

At the top level, an uncaught exception normally leads to program
termination.

Do not assume an uncaught exception automatically prints a friendly,
portable diagnostic message.

Applications should catch failures at appropriate architectural
boundaries when they can meaningfully report or recover from them.

---

## 31. Exception specifications from old C++

You may encounter old code such as:

```cpp
void work() throw(int);
```

Dynamic exception specifications of this kind belong to older C++ and
should not be used in modern C++17 code.

Use modern exception design and `noexcept` where appropriate.

---

## 32. Exceptions and competitive programming

Competitive programming solutions often avoid exceptions for ordinary
algorithmic cases because:

- input is normally guaranteed by the problem specification
- return values and conditions are straightforward
- concise predictable control flow is preferred
- exception handling rarely helps solve the algorithmic challenge

Example:

```cpp
if (index < 0 || index >= n) {
    // handle according to problem logic
}
```

rather than throwing an exception for normal constraint logic.

But understanding exceptions is still important for C++ software,
libraries, interviews, and standard-library behavior.

---

## 33. Exceptions and DSA

When implementing educational data structures, different APIs may
choose different failure policies.

For stack `top()` on an empty stack, possible designs include:

```text
return bool and use output parameter
return optional-like result
throw an exception
require caller to check empty() first
```

Each design has tradeoffs.

The STL itself sometimes provides both unchecked and checked
operations.

For example, later you will see container interfaces where checked
access can throw `std::out_of_range`.

---

## 34. Complexity of exceptions

The asymptotic complexity of successful ordinary execution depends on
the actual algorithm.

Exception throwing itself is not something to model as a simple
universal O(1) operation for practical performance analysis.

Handling may involve:

- finding a matching handler
- unwinding active scopes
- invoking destructors

If `k` automatic scopes/objects require destruction, unwinding work can
depend on that cleanup.

For DSA complexity questions, exceptions are usually not the central
complexity mechanism.

---

## Complexity table

| Operation | Typical algorithmic view |
|---|---:|
| Enter `try` with no exception | Does not change algorithmic Big-O |
| Validate one integer | O(1) |
| Construct simple exception object | O(1) conceptually* |
| `what()` access | O(1) conceptually |
| Unwind k constant-work objects | O(k) cleanup work |
| Catch and inspect one exception | O(1) conceptually |
| Algorithm throwing after O(n) scan | Still includes O(n) scan |

`*` Real implementations and message allocation can introduce costs.
Do not use this table as a microbenchmark model.

---

## Common interview and beginner mistakes

1. Using exceptions for every normal validation failure.

2. Throwing unexplained integer error codes.

3. Catching standard exceptions by value.

4. Catching a base exception before a more specific derived exception.

5. Assuming execution resumes immediately after the `throw` statement.

6. Forgetting that stack unwinding destroys automatic objects.

7. Manually owning raw resources across code that may throw.

8. Throwing from destructors without understanding termination risks.

9. Using `noexcept` on a function that can allow exceptions to escape.

10. Believing `noexcept` catches exceptions automatically.

11. Writing:

```cpp
throw error;
```

when the intention was to rethrow the current exception unchanged with:

```cpp
throw;
```

12. Swallowing all errors using an empty:

```cpp
catch (...) {}
```

13. Assuming a failed constructor causes the complete object's
destructor to execute.

14. Ignoring exception safety when modifying object state.

15. Using old dynamic exception specifications in C++17.

16. Assuming exceptions are required for typical competitive-programming
edge cases.

---

## Practice questions and references

1. GeeksforGeeks — Exception Handling in C++  
   https://www.geeksforgeeks.org/exception-handling-c/

2. cppreference — Exceptions  
   https://en.cppreference.com/w/cpp/language/exceptions

3. cppreference — `std::exception`  
   https://en.cppreference.com/w/cpp/error/exception

4. cppreference — `noexcept` specification  
   https://en.cppreference.com/w/cpp/language/noexcept_spec

5. HackerRank — Exceptional Server  
   https://www.hackerrank.com/challenges/exceptional-server/problem

---

## Revision checklist

Before moving on, make sure you can explain:

- `try`
- `throw`
- `catch`
- exception propagation
- matching by exception type
- standard exceptions
- `std::exception`
- `what()`
- catching by const reference
- catch ordering
- stack unwinding
- RAII connection
- constructor failure
- destructor concerns
- custom exceptions
- `catch (...)`
- `throw;`
- `noexcept`
- basic exception-safety guarantees
- when exceptions are appropriate
- why competitive-programming code often uses ordinary checks instead

# What's Next

Continue to:

`01_C++__/27_NAMESPACES_AND_HEADER_FILES/`

The next lesson explains namespaces, namespace qualification, `using`,
header/source separation, declarations versus definitions, include
guards, `#pragma once`, translation units, linkage basics, and how to
organize reusable C++ code.
