# Functions in C++

Path: `DSA_JOURNEY/01_C++__/08_FUNCTIONS/`

## Prerequisites

You should already understand:

- variables and data types
- operators
- input/output
- conditionals
- loops
- scope at a very basic block level

Functions let us divide a large program into smaller reusable units.

They are fundamental to DSA. Later, almost every algorithm will be written as a function:

```cpp
binarySearch(...)
mergeSort(...)
dfs(...)
bfs(...)
solve(...)
```

---

# 1. What Is a Function?

A function is a named block of code designed to perform a task.

Example:

```cpp
void greet() {
    cout << "Hello\n";
}
```

The function does nothing until it is called:

```cpp
greet();
```

Output:

```text
Hello
```

---

# 2. Why Functions Matter

Without functions:

```cpp
cout << "Hello\n";
cout << "Welcome\n";

// many statements...

cout << "Hello\n";
cout << "Welcome\n";
```

Repeated logic becomes difficult to maintain.

Instead:

```cpp
void greet() {
    cout << "Hello\n";
    cout << "Welcome\n";
}
```

Then:

```cpp
greet();
greet();
```

Benefits include:

- reuse
- organization
- readability
- easier testing
- easier debugging
- decomposition of large problems

---

# 3. Real-World Analogy

Think of a vending machine.

You provide input:

```text
money + selection
```

The machine performs internal steps:

```text
validate
calculate
dispense
```

and may produce output:

```text
product/change
```

A function similarly has:

```text
input -> computation -> result
```

For example:

```cpp
int square(int x) {
    return x * x;
}
```

Call:

```cpp
square(5)
```

Result:

```text
25
```

---

# 4. Function Anatomy

Example:

```cpp
int add(int a, int b) {
    return a + b;
}
```

Parts:

```text
int
|
return type

add
|
function name

(int a, int b)
|
parameter list

{
    return a + b;
}
|
function body
```

Call:

```cpp
int result = add(10, 20);
```

---

# 5. Function Definition

A function definition provides the implementation.

```cpp
int multiply(int a, int b) {
    return a * b;
}
```

It tells the compiler:

```text
name: multiply
parameters: two ints
return type: int
body: return their product
```

---

# 6. Function Call

A function executes when it is called.

```cpp
multiply(4, 5);
```

Conceptually:

```text
caller
  |
  v
multiply
  |
perform work
  |
return result
  |
  v
caller continues
```

Example:

```cpp
int answer = multiply(4, 5);
```

Final:

```text
answer = 20
```

---

# 7. Parameters vs Arguments

These terms are related but different.

Definition:

```cpp
int add(int a, int b) {
    return a + b;
}
```

`a` and `b` are parameters.

Call:

```cpp
add(10, 20);
```

`10` and `20` are arguments.

Mental model:

```text
arguments supplied by caller
          |
          v
parameters inside function
```

---

# 8. Full Dry Run

Code:

```cpp
int add(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int answer = add(4, 7);
}
```

Step 1:

```text
main starts
```

Step 2:

```text
call add(4, 7)
```

Parameter state inside `add`:

```text
a = 4
b = 7
```

Step 3:

```cpp
int result = a + b;
```

State:

```text
a = 4
b = 7
result = 11
```

Step 4:

```cpp
return result;
```

The value:

```text
11
```

is returned to the caller.

Step 5:

```text
answer = 11
```

The `add` call finishes and execution continues in `main`.

---

# 9. Return Type

The return type describes the type of value a function returns.

Example:

```cpp
int getNumber() {
    return 10;
}
```

Return type:

```text
int
```

Another:

```cpp
double half(double x) {
    return x / 2.0;
}
```

Return type:

```text
double
```

---

# 10. void Functions

A function that does not return a value can use:

```cpp
void
```

Example:

```cpp
void printLine() {
    cout << "----------\n";
}
```

Call:

```cpp
printLine();
```

`void` means there is no return value for the caller to use.

---

# 11. return

For a value-returning function:

```cpp
int square(int x) {
    return x * x;
}
```

`return`:

1. determines the value returned
2. immediately ends that function call

Example:

```cpp
int classify(int x) {
    if (x < 0) {
        return -1;
    }

    return 1;
}
```

If:

```text
x < 0
```

is true, the first `return` ends the function. The later statement in that invocation is not reached.

---

# 12. return in void Functions

A `void` function may use:

```cpp
return;
```

without a value.

Example:

```cpp
void printPositive(int x) {
    if (x <= 0) {
        return;
    }

    cout << x << '\n';
}
```

This is often called an early return.

It can reduce unnecessary nesting.

---

# 13. Missing Return

A non-`void` function should return an appropriate value along every execution path that reaches the end.

Bad:

```cpp
int sign(int x) {
    if (x > 0) {
        return 1;
    }

    // What if x <= 0?
}
```

If control reaches the end of a value-returning function other than `main`, behavior is undefined.

Correct:

```cpp
int sign(int x) {
    if (x > 0) {
        return 1;
    }

    return 0;
}
```

or handle all categories explicitly.

Compiler warnings help catch this.

---

# 14. Function Declaration / Prototype

Consider:

```cpp
int main() {
    cout << add(2, 3);
}

int add(int a, int b) {
    return a + b;
}
```

At the point where `main` calls `add`, the compiler has not yet seen a declaration of `add`.

One solution is to define `add` before `main`.

Another is a function declaration:

```cpp
int add(int a, int b);
```

Then:

```cpp
int main() {
    cout << add(2, 3);
}

int add(int a, int b) {
    return a + b;
}
```

---

# 15. Declaration vs Definition

Declaration:

```cpp
int add(int a, int b);
```

It tells the compiler that a function with this interface exists.

Definition:

```cpp
int add(int a, int b) {
    return a + b;
}
```

It provides the body.

Real-world analogy:

A restaurant menu describes an available dish.

The kitchen recipe describes how it is actually made.

The declaration exposes the callable interface.

The definition supplies the implementation.

---

# 16. Function Signature: Beginner View

When reasoning about overloaded functions later, important distinguishing pieces include the function name and parameter-type list.

Example:

```cpp
int add(int, int);
```

The return type alone cannot distinguish overloads.

This is invalid as an overload pair:

```cpp
int test(int x);
double test(int x);
```

because the parameter lists are the same.

Function overloading receives its own later folder.

---

# 17. Multiple Parameters

A function can receive multiple parameters.

```cpp
int maximum(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}
```

Call:

```cpp
maximum(10, 25)
```

Result:

```text
25
```

Parameter order can matter.

Example:

```cpp
int subtract(int a, int b) {
    return a - b;
}
```

Then:

```text
subtract(10, 3) = 7
subtract(3, 10) = -7
```

---

# 18. No Parameters

A function can take no parameters.

```cpp
void greet() {
    cout << "Hello\n";
}
```

Call:

```cpp
greet();
```

In C++:

```cpp
void greet()
```

means the function takes no parameters.

---

# 19. Passing by Value: First Introduction

With ordinary parameters:

```cpp
void change(int x) {
    x = 100;
}
```

Call:

```cpp
int number = 5;
change(number);
```

The parameter receives a copy of the argument value.

Inside:

```text
x = 5
```

Changing:

```text
x = 100
```

does not change `number`.

After the call:

```text
number = 5
```

Pass-by-value/reference/pointer semantics are studied deeply in:

```text
01_C++__/10_PASS_BY_VALUE_REFERENCE_POINTER/
```

For this folder, remember:

```text
ordinary scalar parameter -> separate value object
```

---

# 20. Dry Run: Pass by Value

```cpp
void change(int x) {
    x = 50;
}

int main() {
    int number = 10;

    change(number);

    cout << number;
}
```

Before call:

```text
number = 10
```

Call:

```text
change(number)
```

Parameter receives copied value:

```text
x = 10
```

Inside function:

```text
x = 50
```

States:

```text
x = 50
number = 10
```

Function ends.

Local parameter `x` is destroyed.

Back in `main`:

```text
number = 10
```

Output:

```text
10
```

---

# 21. Local Variables

A variable declared inside a function is local to that scope.

```cpp
int square(int x) {
    int result = x * x;

    return result;
}
```

`result` belongs to that block/function call.

`main` cannot directly write:

```cpp
cout << result;
```

because that name is not in scope there.

Scope gets a dedicated folder later.

---

# 22. Every Function Call Gets Its Own Locals

Consider:

```cpp
int square(int x) {
    int result = x * x;
    return result;
}

square(3);
square(4);
```

Conceptually, each active invocation has its own parameters/local variables.

First call:

```text
x = 3
result = 9
```

Call ends.

Second call:

```text
x = 4
result = 16
```

This becomes crucial when learning recursion.

---

# 23. Call Stack: Beginner Mental Model

When one function calls another, the caller temporarily waits.

Example:

```text
main
 |
 v
square
 |
 return
 |
 v
main continues
```

For nested calls:

```text
main
 |
 v
A
 |
 v
B
 |
 return
 v
A
 |
 return
 v
main
```

The runtime typically manages active function calls using call-stack-like machinery.

Each active call needs information such as:

- return location
- parameters/local state as required by the implementation
- saved execution context

The exact machine-level implementation is more complex, but the stack mental model is very useful.

---

# 24. Real-World Analogy for the Call Stack

Imagine working on a task.

While doing task A, you realize you need task B.

You place A on hold and complete B.

Then you return to A.

```text
Start A
  |
Need B
  |
Pause A
  |
Do B
  |
Finish B
  |
Resume A
```

Function calls behave similarly.

Recursion later relies heavily on this idea.

---

# 25. Nested Function Calls

Suppose:

```cpp
int square(int x) {
    return x * x;
}

int add(int a, int b) {
    return a + b;
}

int result =
    add(square(2), square(3));
```

Conceptually, the calls produce:

```text
square(2) -> 4
square(3) -> 9

add(4, 9) -> 13
```

Final:

```text
result = 13
```

Avoid relying on a guessed order between function arguments when side effects are involved; argument evaluation-order rules are a separate language topic.

With pure calculations like the above, the conceptual result is straightforward.

---

# 26. Functions Calling Functions

Functions are not limited to being called by `main`.

Example:

```cpp
int square(int x) {
    return x * x;
}

int sumOfSquares(int a, int b) {
    return square(a) + square(b);
}
```

Then:

```cpp
sumOfSquares(3, 4)
```

produces:

```text
25
```

This is function composition.

Complex algorithms are often built by combining smaller helper functions.

---

# 27. Function Decomposition

Suppose a problem requires:

```text
read number
check property
calculate result
print result
```

Instead of putting everything into `main`, later we might use:

```text
main
 |
 +--> isPrime()
 |
 +--> calculateSomething()
 |
 +--> printResult()
```

Good decomposition gives each function one clear responsibility.

This makes algorithms easier to:

- understand
- test
- debug
- reuse

---

# 28. Pure Functions

A function such as:

```cpp
int square(int x) {
    return x * x;
}
```

depends only on its arguments and produces a result without modifying external state.

This is close to the idea of a pure function.

Pure functions are particularly easy to reason about.

For the same argument:

```text
square(5)
```

always produces:

```text
25
```

assuming ordinary representable arithmetic.

Not every useful function must be pure, but pure helper functions are very valuable in DSA.

---

# 29. Functions With Side Effects

Example:

```cpp
void printHello() {
    cout << "Hello\n";
}
```

The function changes observable program state by producing output.

That is a side effect.

Other side effects encountered later include:

- modifying referenced objects
- modifying global state
- file I/O
- dynamic allocation

Side effects are not inherently bad.

The important skill is knowing where state changes occur.

---

# 30. Returning vs Printing

These are different designs.

Version A:

```cpp
int add(int a, int b) {
    return a + b;
}
```

Version B:

```cpp
void addAndPrint(int a, int b) {
    cout << a + b;
}
```

Version A is usually more reusable.

Its result can be:

```cpp
int x = add(2, 3);
cout << add(5, 6);
int y = add(1, 2) * 10;
```

A function that only prints the answer cannot as easily provide that computed value to another calculation.

In DSA, computation functions often return values while output remains near the caller.

---

# 31. Early Return

Instead of:

```cpp
int absoluteValue(int x) {
    int result;

    if (x >= 0) {
        result = x;
    } else {
        result = -x;
    }

    return result;
}
```

for safe values we could write:

```cpp
int absoluteValue(int x) {
    if (x >= 0) {
        return x;
    }

    return -x;
}
```

This is compact and clear.

Important edge case:

Negating the minimum representable signed integer overflows.

Even tiny helper functions must respect type limits.

---

# 32. Boolean Functions

Functions can return `bool`.

Example:

```cpp
bool isEven(int x) {
    return x % 2 == 0;
}
```

Then:

```cpp
if (isEven(10)) {
    cout << "Even\n";
}
```

This reads almost like English.

Boolean helper functions often use names such as:

```text
isEven
isPrime
isSorted
contains
canPlace
isValid
```

These become extremely common in DSA.

---

# 33. Avoid Redundant Boolean Code

Instead of:

```cpp
bool isEven(int x) {
    if (x % 2 == 0) {
        return true;
    } else {
        return false;
    }
}
```

write:

```cpp
bool isEven(int x) {
    return x % 2 == 0;
}
```

because:

```cpp
x % 2 == 0
```

already produces a `bool`.

---

# 34. Function Naming

Prefer names describing behavior.

Good:

```cpp
calculateSum()
isPrime()
printPattern()
findMaximum()
```

Weak:

```cpp
doStuff()
thing()
abc()
```

In DSA, short conventional names can still be appropriate:

```cpp
dfs()
bfs()
gcd()
lcm()
```

Clarity depends on context.

---

# 35. Parameter Naming

Good:

```cpp
int power(int base, int exponent)
```

rather than:

```cpp
int power(int a, int b)
```

when descriptive names improve understanding.

For tiny mathematical helpers, short names such as `a` and `b` are often reasonable.

---

# 36. main Is a Function

This:

```cpp
int main() {
    return 0;
}
```

is itself a function definition.

Special property:

```text
program execution begins at main
```

`main` has language-specific rules and should not be called by your C++ program.

---

# 37. Calling Before Declaration

C++ is compiled with declarations needing to be known at the point of use.

This does not compile:

```cpp
int main() {
    greet();
}

void greet() {
}
```

if no declaration of `greet` was visible before the call.

Solution:

```cpp
void greet();

int main() {
    greet();
}

void greet() {
}
```

or define `greet` first.

---

# 38. Header Files Preview

In larger programs, declarations are often placed in header files.

Conceptually:

```text
math_utils.hpp
    |
    contains declarations

math_utils.cpp
    |
    contains definitions
```

Then other source files include the header.

This is studied later in:

```text
01_C++__/27_NAMESPACES_AND_HEADER_FILES/
```

For now our examples remain in one `.cpp` file.

---

# 39. Return Value Conversion

Consider:

```cpp
int function() {
    return 3.9;
}
```

The returned expression must be converted to the function's return type.

So the returned value becomes:

```text
3
```

This compiles with a conversion, although it may indicate poor design or accidental data loss.

Prefer matching return types:

```cpp
double function() {
    return 3.9;
}
```

Warnings and brace-oriented habits can help expose unwanted narrowing elsewhere.

---

# 40. Parameter Conversion

Suppose:

```cpp
void show(double x) {
    cout << x;
}
```

Call:

```cpp
show(5);
```

The integer argument can be converted to `double`.

Inside:

```text
x = 5.0
```

Function calls participate in type-conversion rules learned earlier.

---

# 41. Default Arguments Preview

C++ allows parameters to have default arguments.

Example:

```cpp
void greet(int times = 1);
```

Then:

```cpp
greet();
```

can use the default argument.

However, default arguments are covered in the dedicated folder:

```text
01_C++__/11_FUNCTION_OVERLOADING_DEFAULT_ARGUMENTS/
```

We will not depend on them yet.

---

# 42. Function Overloading Preview

C++ can have several functions with the same name when their parameter lists permit overload resolution to distinguish them.

Example idea:

```cpp
int maximum(int a, int b);
double maximum(double a, double b);
```

This is called function overloading.

It has a dedicated folder later.

For now, use unique/simple interfaces.

---

# 43. Recursion Preview

A function can call itself.

Conceptually:

```cpp
void countdown(int n) {
    ...
    countdown(n - 1);
}
```

This is recursion.

Recursion is powerful but requires understanding:

- base cases
- recursive cases
- call stack
- termination
- recursion complexity

It has an entire phase later:

```text
07_RECURSION_AND_BACKTRACKING__/
```

Do not rush into recursion yet.

---

# 44. Functions and Complexity

A function call itself is not automatically O(1).

Example:

```cpp
int square(int x) {
    return x * x;
}
```

For fixed-width integer arithmetic:

```text
O(1)
```

But:

```cpp
long long sumToN(int n) {
    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    return sum;
}
```

runs:

```text
n iterations
```

so:

```text
O(n)
```

The complexity of a function is determined by what it does.

---

# 45. Calling an O(n) Function Repeatedly

Suppose a helper costs:

```text
O(n)
```

and we call it inside a loop that runs `n` times.

Conceptually:

```text
n calls
*
n work per call
=
n² work
```

Result:

```text
O(n²)
```

This insight will become critical in DSA optimization.

Function abstraction improves organization, but it does not hide computational cost from Big-O analysis.

---

# 46. Function Call Overhead

Real function calls can have small runtime overhead due to tasks such as:

- passing arguments
- setting up call state
- returning

Optimizing compilers can inline calls in many situations.

For DSA analysis, we normally focus on asymptotic algorithmic cost rather than tiny constant call overhead.

Do not avoid useful helper functions merely because "function calls cost something."

Choose clear design first unless profiling or constraints demonstrate a real problem.

---

# 47. Common Interview Mistakes

1. Confusing parameters and arguments.

2. Forgetting to call a function after defining it.

3. Calling a function before the compiler has seen its declaration.

4. Forgetting a return value in a non-`void` function.

5. Assuming code after `return` in the same execution path will execute.

6. Expecting pass-by-value scalar changes to modify the caller.

7. Printing inside every helper when returning a value would be more reusable.

8. Choosing the wrong return type.

9. Ignoring conversion when returning/receiving values.

10. Creating huge functions that perform unrelated tasks.

11. Over-decomposing trivial code into meaningless one-line helpers.

12. Using global state when parameters/return values would be clearer.

13. Forgetting overflow inside a helper.

14. Assuming a function is O(1) because it appears as one line at the call site.

15. Trying to overload functions by return type alone.

16. Writing a Boolean function with unnecessary `if/else` around a Boolean expression.

17. Confusing function declaration with function definition.

18. Assuming local variables are shared between independent calls.

---

# 48. Complexity Table

| Function Pattern | Time | Auxiliary Space |
|---|---:|---:|
| Return fixed scalar | O(1) | O(1) |
| Arithmetic helper | O(1) | O(1) |
| Boolean scalar check | O(1) | O(1) |
| Loop from 1 to n | O(n) | O(1) |
| Two nested n-loops | O(n²) | O(1) |
| Function calling an O(n) helper once | O(n) | depends on helper |
| n-loop calling O(n) helper | O(n²) | depends on helper |

For non-recursive scalar examples, each active function invocation usually uses a fixed amount of local state in our simplified DSA model.

Recursion changes space analysis because many calls can remain active simultaneously.

---

# 49. Practice Questions

1. HackerRank — Functions  
   https://www.hackerrank.com/challenges/c-tutorial-functions/problem

2. GFG — Functions in C++  
   https://www.geeksforgeeks.org/functions-in-cpp/

3. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

4. LeetCode 2413 — Smallest Even Multiple  
   https://leetcode.com/problems/smallest-even-multiple/

5. LeetCode 1281 — Subtract the Product and Sum of Digits  
   https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

---

# 50. Final Checklist

You should understand:

```text
function
function declaration
function prototype
function definition
function call
return type
void
parameter
argument
return
early return
local variable
pass by value introduction
function decomposition
Boolean functions
functions calling functions
call stack mental model
side effects
returning vs printing
function complexity
```

You should be able to write from memory:

```cpp
int add(int a, int b) {
    return a + b;
}
```

and:

```cpp
bool isEven(int x) {
    return x % 2 == 0;
}
```

and explain exactly what happens during:

```cpp
int answer = add(10, 20);
```

---

# What's Next

`01_C++__/09_SCOPE_STORAGE_AND_LIFETIME/`

Next we study where names can be used, how long objects exist, block/function/global scope, shadowing, automatic storage duration, static local variables, global objects, and why scope and lifetime are different concepts.
