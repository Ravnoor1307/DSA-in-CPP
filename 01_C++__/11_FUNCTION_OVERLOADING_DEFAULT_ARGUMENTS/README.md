# Function Overloading and Default Arguments

Path:

`DSA_JOURNEY/01_C++__/11_FUNCTION_OVERLOADING_DEFAULT_ARGUMENTS/`

## Prerequisites

You should already understand:

- functions
- declarations and definitions
- parameters and arguments
- return values
- pass by value
- references
- pointers
- implicit conversions
- scope

This folder studies two important C++ function-interface features:

```text
FUNCTION OVERLOADING
same function name + different parameter lists

DEFAULT ARGUMENTS
arguments automatically supplied when omitted by the caller
```

They improve interfaces when used carefully, but both can also produce confusing or ambiguous code.

---

# 1. Why Function Overloading Exists

Suppose we want to find the larger of two integers:

```cpp
int maximum(int a, int b);
```

Later we also want to compare two doubles.

Without overloading, we might invent names such as:

```cpp
maximumInt(...)
maximumDouble(...)
```

C++ lets us use the same conceptual operation name:

```cpp
int maximum(int a, int b);
double maximum(double a, double b);
```

The compiler determines which function is intended from the arguments at the call site.

This is called function overloading.

---

# 2. Real-World Analogy

Think of the word:

```text
open
```

You might say:

```text
open a door
open a file
open a box
```

The word is the same, but the kind of object tells us which operation is meant.

Function overloading follows a similar idea:

```cpp
print(int)
print(double)
print(char)
```

The common name represents one conceptual operation, while parameter types distinguish the callable forms.

---

# 3. Basic Overloading

Example:

```cpp
void print(int value) {
    cout << "int: " << value;
}

void print(double value) {
    cout << "double: " << value;
}
```

Calls:

```cpp
print(10);
print(3.5);
```

The compiler considers the overload set.

For:

```cpp
print(10)
```

the exact `int` overload is a natural match.

For:

```cpp
print(3.5)
```

the `double` overload is an exact match.

---

# 4. What Makes Overloads Different?

Functions can be overloaded when their parameter-type lists differ in ways recognized by overload resolution.

Examples:

```cpp
void show(int);
void show(double);
```

Different parameter types.

Also:

```cpp
void show(int);
void show(int, int);
```

Different number of parameters.

Also:

```cpp
void show(int, double);
void show(double, int);
```

Different parameter ordering/types.

---

# 5. Return Type Alone Cannot Overload

This is invalid:

```cpp
int getValue(int x);
double getValue(int x);
```

The parameter list is the same.

Only the return type differs.

Why can't C++ choose based on this?

Consider:

```cpp
getValue(5);
```

The return value is ignored.

Which overload should be selected?

The call itself does not provide enough information.

Therefore return type alone cannot distinguish function overloads.

---

# 6. Function Signature: Important Nuance

In beginner explanations, people often say:

```text
name + parameter types = signature
```

That is a useful practical approximation for understanding overloads.

The formal C++ standard uses the term "signature" in more specific ways depending on the entity.

What matters for us is:

```text
return type alone does not create a new overload

parameter distinctions drive overload resolution
```

---

# 7. Full Dry Run: Overload Resolution

Functions:

```cpp
void show(int x);
void show(double x);
```

Call:

```cpp
show(10);
```

Step 1:

```text
argument expression type = int
```

Candidate functions:

```text
show(int)
show(double)
```

Candidate 1:

```text
int -> int
exact match
```

Candidate 2:

```text
int -> double
conversion required
```

The exact match is better.

Selected:

```text
show(int)
```

---

# 8. Another Dry Run

Call:

```cpp
show(2.5);
```

The literal:

```text
2.5
```

has type:

```text
double
```

Candidates:

```text
show(int)
show(double)
```

Conversions:

```text
double -> int     conversion
double -> double  exact
```

Selected:

```text
show(double)
```

---

# 9. Overload Resolution

When a function name refers to several overloads, the compiler conceptually:

1. finds candidate functions
2. determines which are viable for the supplied arguments
3. ranks required conversions
4. selects the best viable function if one exists

If no viable function exists:

```text
compile-time error
```

If there is no unique best function:

```text
ambiguous call
```

---

# 10. Conversion Ranking: Beginner Model

You do not need the full standard rules yet.

A useful simplified ranking is:

```text
exact match
    better than
promotion
    better than
general standard conversion
```

Examples of promotions include common cases such as:

```text
char -> int
short -> int
float -> double
```

Other conversions include:

```text
int -> double
double -> int
```

Actual overload resolution is more detailed, especially with references, templates, inheritance, and user-defined conversions.

---

# 11. Integral Promotion Example

Functions:

```cpp
void process(int);
void process(double);
```

Suppose:

```cpp
char c = 'A';

process(c);
```

`char` can be promoted to `int`.

The `int` overload is normally preferred over a conversion to `double`.

Therefore:

```text
process(int)
```

is selected.

This illustrates why knowing type conversion matters for overloads.

---

# 12. Ambiguous Overloads

Consider:

```cpp
void test(int);
void test(double);
```

Call:

```cpp
test(10LL);
```

`10LL` has type:

```text
long long
```

Depending on the candidate set, converting `long long` to `int` and converting it to `double` can both be standard conversions with no unique better candidate.

That call can be ambiguous.

The compiler refuses to guess.

---

# 13. How to Resolve Ambiguity

One option is to pass the intended type explicitly:

```cpp
test(static_cast<int>(10LL));
```

or:

```cpp
test(static_cast<double>(10LL));
```

But do not add casts just to silence errors without understanding the desired semantics.

A better interface may be to add an appropriate overload:

```cpp
void test(long long);
```

if that type is genuinely part of the function's intended domain.

---

# 14. Overloading by Number of Parameters

Valid:

```cpp
int sum(int a, int b);
int sum(int a, int b, int c);
```

Calls:

```cpp
sum(1, 2);
sum(1, 2, 3);
```

The number of arguments distinguishes them.

This is often useful.

---

# 15. Overloading by Parameter Order

Valid:

```cpp
void display(int number, char symbol);
void display(char symbol, int number);
```

Calls:

```cpp
display(5, '*');
display('*', 5);
```

These are different parameter lists.

However, just because something can be overloaded does not mean it creates a good API.

Use overloads when the common name represents the same conceptual operation.

---

# 16. References and Overloading

References participate in overload resolution.

You might imagine:

```cpp
void process(int);
void process(int&);
```

Calling with an `int` lvalue can produce ambiguity because both candidates may be viable without one clearly being better.

Therefore value/reference overload pairs require care.

Do not create overload sets casually just because their syntax differs.

---

# 17. const Reference Overloads

C++ can distinguish certain reference qualification cases.

Example:

```cpp
void inspect(int&);
void inspect(const int&);
```

For a mutable `int` lvalue:

```cpp
int x = 10;
inspect(x);
```

the non-const reference overload is preferred.

For a const object:

```cpp
const int x = 10;
inspect(x);
```

only the const-reference form is viable among those two.

For a temporary:

```cpp
inspect(10);
```

the const-reference overload can bind.

This becomes important in advanced C++ interfaces.

---

# 18. Top-Level const on Value Parameters Does Not Create an Overload

These do not create two distinct overloads:

```cpp
void process(int);
void process(const int);
```

For a by-value parameter, top-level `const` on the parameter object does not distinguish the function type for overloading.

Inside the definition:

```cpp
void process(const int x)
```

means the local parameter cannot be modified.

But callers still pass an `int` value.

This distinction is frequently tested in C++ interviews.

---

# 19. Pointer constness Can Matter

These can represent different parameter types:

```cpp
void process(int*);
void process(const int*);
```

The pointed-to type differs:

```text
pointer to int
pointer to const int
```

This is not merely top-level const on a copied parameter object.

We introduced this distinction in the previous folder.

---

# 20. Function Overloading Is Compile-Time Polymorphism

You may hear:

```text
compile-time polymorphism
```

used for function overloading.

The compiler chooses the overload based on compile-time type information.

Later we will learn runtime polymorphism using virtual functions.

Broadly:

```text
function overloading
    -> compile-time selection

virtual function overriding
    -> runtime dynamic dispatch
```

We will study that deeply in OOP.

---

# 21. Overloading vs Overriding

Do not confuse:

```text
overloading
```

with:

```text
overriding
```

Overloading:

```cpp
void show(int);
void show(double);
```

Same name, different parameter lists.

Overriding comes later with inheritance and virtual functions:

```text
derived class provides behavior corresponding to
a virtual base-class function
```

They solve different problems.

---

# 22. Name Mangling: High-Level Idea

At the source-code level we can write:

```cpp
show(int)
show(double)
```

Compilers generally need distinct linker-level identities for overloaded functions.

Implementations commonly encode type information into generated symbol names.

This is often called:

```text
name mangling
```

The exact scheme is implementation-specific.

You do not need it for DSA, but it helps explain how compiled overloads can coexist.

---

# 23. Default Arguments

Now consider:

```cpp
void greet(string name = "Guest");
```

This allows a call that omits the argument:

```cpp
greet();
```

Conceptually, at the call site the compiler uses the available default:

```text
greet("Guest")
```

A supplied argument overrides the default:

```cpp
greet("Ada");
```

---

# 24. Default Arguments With Types We Already Know

To avoid relying heavily on strings yet:

```cpp
int multiply(int value, int factor = 2) {
    return value * factor;
}
```

Calls:

```cpp
multiply(5)
```

acts like:

```cpp
multiply(5, 2)
```

Result:

```text
10
```

Call:

```cpp
multiply(5, 3)
```

Result:

```text
15
```

---

# 25. Real-World Analogy for Default Arguments

Imagine ordering coffee.

Standard order:

```text
size = medium
```

If you simply say:

```text
coffee
```

you receive medium.

If you explicitly say:

```text
large coffee
```

your supplied choice replaces the default.

Function defaults work similarly:

```text
missing argument -> use declared default
provided argument -> use provided value
```

---

# 26. Default Arguments Are Used at the Call Site

This is a very important C++ idea.

Default arguments are substituted based on declarations visible at the point of the call.

They are not a special runtime state stored inside the function.

Conceptually:

```cpp
multiply(5);
```

is compiled using the visible default information as though the missing argument had been supplied.

This matters in multi-file programs and virtual-function edge cases later.

---

# 27. Trailing Parameter Rule

After a parameter has a default argument, parameters to its right generally must also have defaults, unless they already obtained defaults from a previous declaration or belong to specific special cases.

Valid:

```cpp
void example(
    int a,
    int b = 10,
    int c = 20
);
```

Calls:

```cpp
example(1);
example(1, 2);
example(1, 2, 3);
```

Invalid simple declaration:

```cpp
void example(
    int a = 10,
    int b
);
```

because callers cannot skip `a` while supplying only `b` by position.

---

# 28. You Cannot Skip a Middle Argument

Suppose:

```cpp
void test(
    int a,
    int b = 10,
    int c = 20
);
```

You can call:

```cpp
test(1);
test(1, 2);
test(1, 2, 3);
```

But C++ has no syntax like:

```text
test(a=1, c=3)
```

for named arguments.

You cannot skip `b` and directly supply `c`.

Arguments are positional.

---

# 29. Defaults Are Usually Written in the Declaration

A common organization:

```cpp
int power(int base, int exponent = 2);

int main() {
    cout << power(5);
}

int power(int base, int exponent) {
    ...
}
```

Notice the definition does not repeat:

```text
= 2
```

This is the normal style.

A default argument should not be redefined later in the same scope.

---

# 30. Adding Defaults Across Declarations

C++ has rules allowing defaults to be accumulated across visible declarations in the same scope, as long as each parameter receives a default appropriately and trailing-default rules are satisfied.

Example concept:

```cpp
void f(int a, int b);

void f(int a, int b = 20);

void f(int a = 10, int b);
```

can build up defaults under the language rules.

However, this style can be confusing.

For beginner and production readability:

```text
put defaults in one primary declaration
```

is usually better.

---

# 31. Do Not Repeat a Default Argument

Bad:

```cpp
void greet(int times = 1);

void greet(int times = 1) {
}
```

The default was already specified.

The definition should generally be:

```cpp
void greet(int times) {
}
```

---

# 32. Default Expressions Are Evaluated When Called

Consider:

```cpp
int nextValue = 10;

void show(int x = nextValue);
```

A call:

```cpp
show();
```

uses the default expression at the call site when executed; it does not necessarily freeze the value `10` forever merely because that was the variable's value when the declaration was encountered.

For example, if allowed by scope/lifetime:

```cpp
nextValue = 50;
show();
```

can pass `50`.

Avoid using changing global state in defaults unless the behavior is deliberate.

---

# 33. Default Arguments Can Use Earlier Parameters? Important Trap

You might try:

```cpp
void f(int x, int y = x);
```

This is not allowed: function parameters cannot be used this way in default argument expressions.

Do not assume defaults behave like sequential assignments between parameters.

Use another overload or compute the dependent value inside the function.

---

# 34. Default Arguments and Overloading Can Conflict

Consider:

```cpp
void show(int x);

void show(int x, int y = 0);
```

Call:

```cpp
show(5);
```

Candidate 1:

```text
show(int)
```

valid.

Candidate 2:

```text
show(int, int)
```

also valid because the second argument has a default.

The call can become ambiguous.

This is a major design trap.

---

# 35. Full Dry Run: Default-Argument Ambiguity

Given:

```text
show(int)
show(int, int = 0)
```

Call:

```cpp
show(5)
```

Candidate A needs:

```text
one supplied argument
```

exact match.

Candidate B also needs:

```text
one supplied argument
+
one defaulted argument
```

The supplied argument is an exact match there too.

Default arguments do not make one function "worse" in the way you might expect for overload ranking.

No unique best candidate.

Result:

```text
compile-time ambiguity
```

Avoid overlapping interfaces like this.

---

# 36. Overloads vs Default Arguments

Suppose we want:

```cpp
draw()
draw('*')
```

Option A: overloads.

```cpp
void draw() {
    draw('*');
}

void draw(char symbol) {
    ...
}
```

Option B: default argument.

```cpp
void draw(char symbol = '*') {
    ...
}
```

Both may model the interface.

Choose based on clarity.

Defaults are useful when behavior is truly the same operation with an optional conventional value.

Overloads are useful when parameter sets or behavior differ meaningfully.

---

# 37. Delegating Between Overloads

One overload can call another.

Example:

```cpp
int area(int side) {
    return area(side, side);
}

int area(int width, int height) {
    return width * height;
}
```

However, the two-parameter overload must be declared before it is called from the first overload, or otherwise made visible.

A safe organization:

```cpp
int area(int width, int height);

int area(int side) {
    return area(side, side);
}

int area(int width, int height) {
    return width * height;
}
```

This reduces duplicate logic.

---

# 38. Avoid Duplicate Implementations

Weak design:

```cpp
int area(int side) {
    return side * side;
}

int area(int width, int height) {
    return width * height;
}
```

This example is tiny, so duplication is harmless.

For complex logic, duplicating implementations across overloads can lead to bugs.

Often choose one "core" overload and make convenience overloads delegate to it.

---

# 39. Ambiguous Numeric Literals

Suppose:

```cpp
void calculate(long);
void calculate(double);
```

Call:

```cpp
calculate(5);
```

The literal `5` has type `int`.

Depending on conversions, neither candidate may be clearly better, producing ambiguity.

An explicit literal type or additional overload can resolve the intended interface:

```cpp
calculate(5L);
calculate(5.0);
```

Again, design your overload set so common calls are unsurprising.

---

# 40. Literal Suffixes Matter

Recall:

```text
10    -> int
10L   -> long
10LL  -> long long
3.5   -> double
3.5f  -> float
```

Overload resolution uses these expression types.

Example:

```cpp
void show(float);
void show(double);
```

Then:

```cpp
show(3.5);
```

selects:

```text
show(double)
```

while:

```cpp
show(3.5f);
```

selects:

```text
show(float)
```

The literal's type matters.

---

# 41. nullptr and Pointer Overloads

Suppose:

```cpp
void process(int*);
void process(double*);
```

Call:

```cpp
process(nullptr);
```

`nullptr` can convert to either pointer type.

Neither may be better.

The call can therefore be ambiguous.

This is another example showing that overloading requires careful interface design.

---

# 42. Avoid 0/NULL With Pointer Overloads

Historically:

```cpp
0
```

and macros such as:

```cpp
NULL
```

were used for null pointer constants.

With overloads, integer-like forms can interact badly with overload resolution.

Modern C++ uses:

```cpp
nullptr
```

which has its own type:

```text
std::nullptr_t
```

Even `nullptr` can still be ambiguous between unrelated pointer overloads, but it avoids accidental selection of an integer overload in many common situations.

---

# 43. Function Pointers and Overloads: Preview

Later, if you take a function's address and the name is overloaded:

```cpp
&show
```

the compiler may need contextual type information to determine which overload you mean.

For example conceptually:

```cpp
void (*ptr)(int) = show;
```

can select:

```cpp
show(int)
```

Function pointers are not a focus yet.

This is simply another consequence of one name referring to an overload set.

---

# 44. Overloading and const Objects

Suppose:

```cpp
void inspect(int&);
void inspect(const int&);
```

State:

```cpp
int mutableValue = 10;
const int constantValue = 20;
```

Calls:

```cpp
inspect(mutableValue);
```

prefers:

```text
int&
```

Call:

```cpp
inspect(constantValue);
```

uses:

```text
const int&
```

Call:

```cpp
inspect(30);
```

uses:

```text
const int&
```

because a non-const lvalue reference cannot bind to the temporary.

---

# 45. Full Dry Run: const Reference Overload

Overloads:

```text
inspect(int&)
inspect(const int&)
```

Argument:

```cpp
int x = 5;
```

Candidate 1:

```text
int& <- int lvalue
exact/direct binding
```

Candidate 2:

```text
const int& <- int lvalue
also viable
```

The non-const reference is preferred for the mutable lvalue in this overload set.

Now:

```cpp
const int y = 5;
```

Candidate:

```text
int&
```

cannot bind because it would permit mutable access to a const object.

So:

```text
const int&
```

is selected.

---

# 46. Avoid "Catch-All" Overload Thinking

Do not create many overloads just because types exist:

```cpp
f(short)
f(int)
f(long)
f(long long)
f(float)
f(double)
...
```

unless the API genuinely needs distinct behavior.

Too many overloads can:

- create ambiguity
- increase maintenance
- surprise callers
- duplicate code

Templates later solve many "same algorithm for many types" problems more elegantly.

---

# 47. Overloading vs Templates Preview

Suppose these all perform identical logic:

```cpp
int maximum(int, int);
long long maximum(long long, long long);
double maximum(double, double);
```

A function template can later express:

```text
same algorithm for a family of types
```

Templates receive a dedicated folder.

Overloading is still useful when different types need different behavior or when the interface itself differs.

---

# 48. Default Arguments and API Stability

Suppose:

```cpp
void connect(
    int timeout = 30
);
```

Callers can write:

```cpp
connect();
```

Changing the default later changes the effective argument used when those call sites are recompiled.

Because defaults are associated with call-site declarations, default arguments become part of an interface contract.

Choose defaults deliberately.

---

# 49. Default Arguments and Virtual Functions: Future Warning

Later, with virtual functions, an important rule appears:

```text
virtual dispatch chooses implementation dynamically

default arguments are selected statically from the visible declaration/type
```

This can be surprising.

We will revisit it during polymorphism.

For now, remember:

```text
defaults are compile-time call-site behavior
```

---

# 50. Functions With Many Default Arguments

Example:

```cpp
void configure(
    int width = 800,
    int height = 600,
    bool fullscreen = false
);
```

This is legal.

But calls such as:

```cpp
configure(1920, 1080, true);
```

can become hard to read because the meaning of each raw argument is not obvious.

Later, structs/classes and named configuration objects can provide clearer APIs.

Default arguments are useful but not a replacement for good interface design.

---

# 51. Sentinel Defaults

Sometimes programmers use a special default such as:

```cpp
int limit = -1
```

to mean:

```text
no limit
```

This can be appropriate when `-1` can never be a normal valid value.

But if `-1` is itself valid data, the interface becomes ambiguous.

Later C++ facilities such as `std::optional` can model optional values more explicitly, though that is outside our core DSA needs.

---

# 52. Default Boolean Parameters

Example:

```cpp
void print(int value, bool verbose = false);
```

Call:

```cpp
print(10, true);
```

At the call site, `true` does not explain what it means.

This is sometimes called a Boolean-parameter readability problem.

Small DSA helpers may use it, but production interfaces often benefit from clearer names/types.

---

# 53. Never Use Defaults to Hide Required Data

If a function logically requires a value to work correctly, do not invent a meaningless default merely to shorten calls.

Example:

```cpp
int divide(int a, int b = 0);
```

is a bad default because:

```text
division by zero
```

is invalid for integer division.

Defaults should represent sensible behavior.

---

# 54. Overload Resolution Happens Before Runtime

Consider:

```cpp
double value = 5.0;

show(value);
```

The compiler sees:

```text
static type = double
```

and chooses an overload accordingly.

The decision is not based on:

```text
"this double happens to contain a whole number"
```

Runtime numeric content does not change its static type.

---

# 55. Static Type Matters

Example:

```cpp
double x = 10.0;
```

Even though the value is mathematically an integer:

```text
10
```

the expression `x` has type:

```text
double
```

Therefore overload resolution treats it as a `double`.

This distinction later becomes critical with class hierarchies, where static and dynamic types can differ.

---

# 56. Function Declaration Must Be Visible

As with ordinary functions, overload candidates must be declared where the call is compiled.

Example:

```cpp
void show(int);

int main() {
    show(3.5);
}

void show(double) {
}
```

At the call site, if only `show(int)` has been declared, the later double overload is not part of the visible overload set for that earlier call.

This can cause unexpected conversions.

Declare the full intended overload set before calls, usually through a header in larger programs.

---

# 57. Overloads Should Have Consistent Semantics

Good:

```cpp
print(int)
print(double)
print(char)
```

All mean:

```text
display a value
```

Questionable:

```cpp
process(int)     // sorts
process(double)  // writes file
process(char)    // deletes data
```

The shared name no longer represents one clear operation.

Overloading should improve conceptual consistency, not hide unrelated behavior.

---

# 58. Common Interview Mistakes

1. Trying to overload only by return type.

2. Assuming the compiler chooses based on the receiving variable's type.

3. Forgetting implicit conversions participate in overload resolution.

4. Assuming the compiler "just picks the closest-looking one" when ambiguity exists.

5. Forgetting literal types such as `3.5` vs `3.5f`.

6. Creating overlapping overloads that become ambiguous.

7. Combining an overload with a default argument that makes the same call match both functions.

8. Thinking default arguments are runtime function state.

9. Repeating the same default argument in both declaration and definition.

10. Placing a non-defaulted parameter after a newly defaulted parameter in a simple declaration.

11. Trying to skip a middle positional parameter.

12. Expecting return type to resolve an ambiguous overload.

13. Believing `const int` value parameter creates a distinct overload from `int`.

14. Confusing pointer-to-const with top-level const on a copied parameter.

15. Confusing overloading with overriding.

16. Assuming all overloads visible later were visible at an earlier call site.

17. Adding explicit casts merely to suppress ambiguity without understanding why it occurred.

18. Creating too many overloads when a template would eventually be more appropriate.

19. Giving dangerous defaults such as a zero divisor.

20. Using defaults that make function calls unreadable.

---

# 59. Complexity

Overload resolution and default-argument selection are compile-time language mechanisms.

They do not add an algorithmic runtime search among overloads.

If:

```cpp
show(10);
```

resolves to:

```cpp
show(int)
```

the executable calls the selected function.

There is no runtime loop checking all overloads.

| Feature | Compile/Runtime Character | DSA Runtime Overhead |
|---|---|---:|
| Overload resolution | Compile time | O(1) model |
| Default argument substitution | Compile time | O(1) model |
| Calling selected scalar helper | Runtime | depends on function |
| Scalar default expression | Runtime when evaluated at call | usually O(1) |
| Function body with n-loop | Runtime | O(n) |

The complexity of the selected function body still matters.

---

# 60. Practice Questions

This topic is primarily about C++ language design rather than standalone algorithms.

1. GFG — Function Overloading in C++  
   https://www.geeksforgeeks.org/function-overloading-c/

2. GFG — Default Arguments in C++  
   https://www.geeksforgeeks.org/default-arguments-c/

3. HackerRank — Functions  
   https://www.hackerrank.com/challenges/c-tutorial-functions/problem

4. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

5. LeetCode 2413 — Smallest Even Multiple  
   https://leetcode.com/problems/smallest-even-multiple/

For this folder, compiler experiments are especially valuable. Write small overload sets and predict which function will be selected before compiling them.

---

# 61. Final Mental Model

When you see an overloaded call:

```cpp
function(argument);
```

think:

```text
What is the argument's exact type?
        |
        v
Which overload declarations are visible?
        |
        v
Which candidates are viable?
        |
        v
What conversions does each require?
        |
        v
Is there one unique best match?
        |
        +---- yes -> compile selected call
        |
        +---- no --> compile-time error
```

For default arguments:

```text
Which declaration is visible at the call site?
        |
        v
Which trailing arguments were omitted?
        |
        v
Use their declared defaults
        |
        v
Call the function
```

---

# What's Next

`01_C++__/12_ARRAYS_1D_2D/`

Next we begin our first fundamental data structure: contiguous fixed-size arrays. We will study indexing, memory layout, 1D and 2D arrays, traversal, passing arrays to functions, bounds, initialization, searching, aggregation, matrices, and the array-to-pointer adjustment that makes C-style array parameters especially important in C++.
