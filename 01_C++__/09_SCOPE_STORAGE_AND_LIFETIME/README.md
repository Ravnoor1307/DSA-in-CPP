# Scope, Storage Duration, and Lifetime

Path:

`DSA_JOURNEY/01_C++__/09_SCOPE_STORAGE_AND_LIFETIME/`

## Prerequisites

You should already understand:

- variables and data types
- blocks `{ }`
- conditionals
- loops
- functions
- parameters and arguments
- return values
- local variables
- basic function-call mental model

This folder answers several questions that look similar but are actually different:

```text
Where can I use this name?
How long does this object exist?
Where is its storage maintained?
What happens when two variables have the same name?
Why can a static local remember its old value?
Why should global mutable state usually be minimized?
```

These ideas become especially important before references, pointers, dynamic memory, recursion, classes, and data structures.

---

# 1. Three Concepts You Must Separate

Beginners often mix together:

```text
scope
storage duration
lifetime
```

They are related, but they are not synonyms.

A useful first mental model is:

```text
SCOPE
Where is this NAME visible?

STORAGE DURATION
For how long is the object's STORAGE maintained?

LIFETIME
During what part of execution does the OBJECT actually exist?
```

Keeping these questions separate prevents many C++ mistakes.

---

# 2. Scope

Scope primarily concerns names.

Example:

```cpp
int main() {
    int age = 20;

    cout << age;
}
```

The name:

```text
age
```

can be used in the region where it is in scope.

If we attempt to use that local name somewhere outside its scope, the compiler cannot resolve it there.

---

# 3. Real-World Analogy for Scope

Imagine two classrooms.

Classroom A has a student named:

```text
Alex
```

Classroom B may also have a student named:

```text
Alex
```

Within each classroom, saying:

```text
Alex
```

refers to the person known in that context.

Scope works similarly.

A name belongs to a region of source code.

The same spelling may refer to different entities in different scopes.

---

# 4. Block Scope

A block is enclosed by:

```cpp
{
    ...
}
```

A variable declared inside a block normally has block scope.

Example:

```cpp
int main() {

    {
        int x = 10;
        cout << x;
    }

}
```

Inside the block:

```text
x is visible
```

Outside the block:

```cpp
cout << x;
```

would fail because the name `x` is no longer in scope.

---

# 5. Dry Run: Block Scope

Code:

```cpp
int main() {
    int outer = 10;

    {
        int inner = 20;

        cout << outer << '\n';
        cout << inner << '\n';
    }

    cout << outer << '\n';
}
```

Before inner block:

```text
outer = 10
```

Enter block:

```text
outer = 10
inner = 20
```

Both names can be used inside the inner block.

Leave block:

```text
inner is no longer in scope
```

`outer` is still in its surrounding scope.

Final valid output:

```text
10
20
10
```

---

# 6. Inner Scopes Can See Outer Names

Example:

```cpp
int main() {
    int x = 10;

    {
        cout << x;
    }
}
```

The inner block can use `x` from the enclosing scope, provided another declaration does not hide it.

Conceptually:

```text
outer scope
|
| x
|
+---- inner scope
      |
      +---- can look outward for x
```

---

# 7. Outer Scopes Cannot Use Inner Local Names

Example:

```cpp
int main() {

    {
        int x = 10;
    }

    // cout << x;   // ERROR
}
```

The name `x` only belongs to the inner region.

Information visibility is therefore not symmetric.

An inner scope can often find names from enclosing scopes.

The enclosing outer region cannot use names declared only inside a nested block.

---

# 8. Function Scope and Function Parameters

Function parameters are available within the function body.

Example:

```cpp
int square(int x) {
    return x * x;
}
```

The parameter:

```text
x
```

belongs to the function's parameter scope/body context under C++'s scope rules.

For practical beginner reasoning:

```text
x is usable inside square()
x is not a variable name main() can directly access
```

Example:

```cpp
int main() {
    // cout << x; // x from square is not visible here
}
```

---

# 9. Local Variables in Different Functions

These functions can both declare:

```cpp
int value;
```

Example:

```cpp
void first() {
    int value = 10;
}

void second() {
    int value = 20;
}
```

These are different objects.

There is no naming conflict because their declarations occur in separate local scopes.

Conceptual state during calls:

```text
first():
value = 10
```

and separately:

```text
second():
value = 20
```

---

# 10. Variables Inside if Statements

Example:

```cpp
if (true) {
    int answer = 42;

    cout << answer;
}
```

`answer` belongs to that block.

After the block:

```cpp
// cout << answer;
```

would be invalid.

The same rule applies to blocks used by:

- `if`
- `else`
- loops
- nested standalone blocks
- functions

---

# 11. Variables Declared by a for Loop

Example:

```cpp
for (int i = 0; i < 5; ++i) {
    cout << i;
}
```

The variable:

```text
i
```

is associated with the `for` statement's scope.

After the loop:

```cpp
// cout << i;
```

is invalid.

If you need the variable afterward:

```cpp
int i = 0;

for (; i < 5; ++i) {
}

cout << i;
```

Now the name was declared in the surrounding scope.

---

# 12. Shadowing

An inner scope can declare a name identical to an outer name.

Example:

```cpp
int x = 10;

{
    int x = 20;

    cout << x;
}
```

Inside the inner block:

```text
x
```

refers to the inner `x`.

The outer name is hidden by the nearer declaration.

This is called shadowing.

---

# 13. Real-World Analogy for Shadowing

Imagine your phone has a contact:

```text
Alex
```

but inside a particular work project, the label `Alex` is being used for a specific project member.

Within that project context, the more local meaning wins.

Similarly:

```text
outer x = 10

inner block:
    inner x = 20
```

Inside the inner block, unqualified `x` resolves to the nearer declaration.

---

# 14. Full Dry Run: Shadowing

Code:

```cpp
int x = 10;

cout << x << '\n';

{
    int x = 20;

    cout << x << '\n';
}

cout << x << '\n';
```

State before inner block:

```text
outer x = 10
```

First output:

```text
10
```

Enter inner block.

Create another object:

```text
outer x = 10
inner x = 20
```

Inside block, `x` means:

```text
inner x
```

Output:

```text
20
```

Leave block.

Inner `x`'s lifetime ends.

Outer `x` remains:

```text
outer x = 10
```

Output:

```text
10
```

Final:

```text
10
20
10
```

---

# 15. Shadowing Is Legal but Can Be Confusing

This is valid:

```cpp
int score = 50;

{
    int score = 100;
}
```

However, excessive shadowing makes programs harder to reason about.

When reading:

```cpp
score
```

you must determine which declaration is active.

In beginner DSA code, avoid unnecessary shadowing.

Compile with warnings such as:

```bash
-Wshadow
```

when your compiler supports it.

Example GCC/Clang command:

```bash
g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic file.cpp
```

---

# 16. Global Variables

A variable declared at namespace scope, outside functions, has namespace scope.

Example:

```cpp
int globalScore = 100;

int main() {
    cout << globalScore;
}
```

Here:

```text
globalScore
```

is not local to `main`.

It is a namespace-scope variable.

In simple single-file programs, people often casually call such variables "global variables."

---

# 17. Global Scope vs Namespace Scope

In modern C++, it is more precise to say that a declaration such as:

```cpp
int value = 10;
```

outside functions at the top level appears in global namespace scope.

The term:

```text
global variable
```

is commonly used informally.

Namespaces are studied properly later.

---

# 18. Accessing a Shadowed Global

Example:

```cpp
int value = 10;

int main() {
    int value = 20;

    cout << value << '\n';
    cout << ::value << '\n';
}
```

Inside `main`:

```text
value
```

refers to the local object.

The scope-resolution operator:

```text
::
```

can refer to the name in the global namespace:

```cpp
::value
```

Output:

```text
20
10
```

This is useful to understand, but deliberately relying on repeated global/local names is often poor design.

---

# 19. Why Global Mutable Variables Can Be Dangerous

Consider:

```cpp
int score = 0;

void first() {
    score = 100;
}

void second() {
    score = 200;
}
```

Many functions can modify the same state.

Now reasoning becomes harder:

```text
Who changed score?
When?
What value should it currently have?
```

Real-world analogy:

Imagine a whiteboard in a hallway that everyone in a company can rewrite.

It is easy to access.

It is also difficult to know who changed it or whether the current value is trustworthy.

Prefer local state and explicit data flow when practical.

---

# 20. Are Globals Always Bad?

No.

Global or namespace-level objects can be appropriate in some contexts.

Examples include:

- immutable constants
- certain program-wide configuration
- carefully controlled state
- competitive-programming implementations where global arrays simplify memory management
- objects whose program-wide lifetime is intentional

The useful rule is not:

```text
never use globals
```

It is:

```text
avoid unnecessary global mutable state
```

Understand the tradeoff.

---

# 21. const Global Values

A program-wide constant can be reasonable:

```cpp
constexpr int MOD = 1'000'000'007;
```

You have not formally learned `constexpr` yet.

For now, a simpler example is:

```cpp
const int DAYS = 7;
```

The important idea is that immutable shared data is easier to reason about than mutable shared state.

`constexpr` will become more meaningful as your C++ knowledge grows.

---

# 22. Lifetime

Scope answers:

```text
Where can a name be used?
```

Lifetime answers:

```text
When does the object exist?
```

These are not identical.

For a simple local variable:

```cpp
void function() {
    int x = 10;
}
```

the lifetime of `x` normally begins when execution reaches its initialization and ends when execution leaves its block.

This aligns closely with its local scope, which is why beginners often confuse the concepts.

But later examples will separate them.

---

# 23. Real-World Analogy for Lifetime

Scope is like:

```text
where someone's name appears on an employee directory
```

Lifetime is like:

```text
the period during which that employee is actually working for the company
```

Visibility of a name and existence of an entity are conceptually separate questions.

In C++, those distinctions become important with:

- static objects
- dynamic allocation
- references
- pointers
- temporary objects

---

# 24. Automatic Storage Duration

Typical local variables have automatic storage duration.

Example:

```cpp
void demo() {
    int x = 10;
}
```

Each time execution enters the block and reaches `x`, a new `x` object is created.

When execution leaves the block, its lifetime ends.

Conceptually:

```text
call demo()
    |
create x
    |
use x
    |
leave block
    |
x lifetime ends
```

Call `demo()` again:

```text
a new x is created
```

---

# 25. Local Variables Do Not Remember Previous Calls

Example:

```cpp
void counter() {
    int count = 0;

    ++count;

    cout << count << '\n';
}
```

Call:

```cpp
counter();
counter();
counter();
```

Output:

```text
1
1
1
```

Why?

Every call creates a new automatic `count`, initialized to zero.

State:

```text
call 1:
count 0 -> 1 -> destroyed

call 2:
count 0 -> 1 -> destroyed

call 3:
count 0 -> 1 -> destroyed
```

---

# 26. Static Local Variables

Now add:

```cpp
static
```

Example:

```cpp
void counter() {
    static int count = 0;

    ++count;

    cout << count << '\n';
}
```

Calls:

```cpp
counter();
counter();
counter();
```

Output:

```text
1
2
3
```

The local name still has local/block scope.

But the object has static storage duration and persists for the program's lifetime once initialized.

This is one of the clearest examples showing:

```text
scope != storage duration
```

---

# 27. Full Dry Run: Static Local

Function:

```cpp
void visit() {
    static int count = 0;

    ++count;
    cout << count << '\n';
}
```

First call:

```text
static count initialized = 0
++count -> 1
print 1
function ends
```

Important:

```text
count's name is no longer accessible from the caller,
but the object persists
```

Second call:

```text
existing count = 1
++count -> 2
print 2
```

Third:

```text
existing count = 2
++count -> 3
print 3
```

Output:

```text
1
2
3
```

---

# 28. Static Local Initialization Happens Once

Example:

```cpp
void demo() {
    static int value = 10;

    ++value;
}
```

The initialization:

```cpp
= 10
```

happens only once.

It does not reset `value` to 10 on every call.

This differs from:

```cpp
int value = 10;
```

which creates and initializes a fresh automatic object each time the declaration is executed.

Since C++11, initialization of function-local statics is thread-safe in the sense defined by the language: concurrent first-use does not initialize the object multiple times.

Threading itself is outside our DSA roadmap.

---

# 29. Static Storage Duration

Objects with static storage duration have storage that lasts for the duration of the program.

Examples include:

- namespace-scope variables
- `static` namespace-scope variables
- static local variables
- static data members of classes

We have not learned classes yet.

At this stage:

```text
global/namespace variable -> static storage duration

static local -> static storage duration
```

is enough.

---

# 30. Zero Initialization of Static-Storage Objects

Objects with static storage duration receive zero initialization before other initialization rules are applied.

Example:

```cpp
int globalNumber;
```

If no explicit initializer is provided, it begins as zero.

Similarly:

```cpp
static int localStatic;
```

begins as zero.

Compare with:

```cpp
void f() {
    int local;
}
```

An uninitialized automatic local `int` does not automatically receive zero.

Reading its indeterminate value can produce undefined behavior.

This difference is important.

---

# 31. Do Not Depend on Accidental Local Values

Wrong:

```cpp
int sum;

sum += 5;
```

`sum` was not initialized.

Correct:

```cpp
int sum = 0;

sum += 5;
```

Do not think:

```text
"It printed 0 on my machine, therefore locals default to zero."
```

They do not.

Undefined behavior may appear to work during one run and fail later.

---

# 32. Storage Duration Categories: Overview

C++ includes several storage-duration categories.

At a high level:

```text
automatic
static
thread
dynamic
```

For this roadmap:

```text
automatic -> ordinary local variables

static -> namespace-scope objects and static locals

dynamic -> objects created through dynamic allocation
           (studied later)

thread -> per-thread objects
          (not central to this DSA roadmap)
```

Dynamic memory receives its own dedicated folder.

---

# 33. Storage Duration Is Not "Stack vs Heap"

This distinction is important.

C++ language rules formally discuss:

```text
storage duration
lifetime
scope
```

Terms such as:

```text
stack
heap
```

describe common implementation/runtime memory concepts.

An automatic local variable is commonly implemented using stack storage, but the C++ standard's semantic concept is:

```text
automatic storage duration
```

Similarly, dynamically allocated objects are commonly associated with heap/free-store mechanisms.

Do not treat "stack variable" as a perfect synonym for "automatic object."

The memory model is studied later.

---

# 34. Scope vs Lifetime: Static Local

Consider:

```cpp
void function() {
    static int x = 10;
}
```

Scope:

```text
The name x is only usable in its local scope.
```

Storage duration:

```text
static
```

Lifetime:

```text
once initialized, the object persists until program termination
```

Therefore:

```text
limited name visibility
+
long object lifetime
```

This proves scope and lifetime are different properties.

---

# 35. Nested Block Lifetime

Example:

```cpp
int main() {

    int outer = 1;

    {
        int inner = 2;
    }
}
```

Timeline:

```text
enter main
|
construct/initialize outer
|
enter inner block
|
construct/initialize inner
|
leave inner block
|
inner lifetime ends
|
leave main
|
outer lifetime ends
```

Objects with automatic storage duration are generally destroyed in reverse order when leaving their scope.

This becomes visible when we learn classes and destructors.

---

# 36. Why Reverse Destruction Order Matters

Suppose conceptually:

```text
create A
create B
create C
```

When leaving the scope, automatic objects are destroyed in reverse order:

```text
destroy C
destroy B
destroy A
```

Real-world analogy:

Imagine stacking trays:

```text
A
then B on top
then C on top
```

To remove them naturally:

```text
C
B
A
```

This LIFO behavior relates closely to stack reasoning.

With plain `int`, destruction has no visible effect, but with class objects it becomes extremely important.

---

# 37. Initialization and Destruction of Global Objects

Objects with static storage duration have initialization and destruction rules extending across the program.

Global class objects can introduce initialization-order complications across translation units.

You do not need those details yet.

Beginner rule:

```text
Do not create global objects unnecessarily.
```

Later OOP/RAII sections will make object construction/destruction more concrete.

---

# 38. Name Lookup

When C++ encounters a name such as:

```cpp
value
```

it needs to determine which declaration that name refers to.

A simplified mental model:

```text
look in nearest relevant scope
|
if found -> use it
|
otherwise consider enclosing scopes according to C++ lookup rules
```

Actual C++ name lookup has many rules involving:

- namespaces
- classes
- templates
- argument-dependent lookup

Those come later.

For local variables, the nearest-scope model is sufficient.

---

# 39. Same Name in Separate Non-Overlapping Blocks

This is valid:

```cpp
{
    int x = 10;
}

{
    int x = 20;
}
```

They are separate objects in separate scopes.

There is no simultaneous name conflict.

---

# 40. Redeclaration in the Same Scope

This is invalid:

```cpp
int x = 10;
int x = 20;
```

within the same ordinary block scope.

The second declaration attempts to redeclare the same name incompatibly in the same scope.

But this can be valid:

```cpp
int x = 10;

{
    int x = 20;
}
```

because the second declaration belongs to a nested scope and shadows the outer one.

---

# 41. Function Parameters and Local Redeclaration

This is invalid:

```cpp
void demo(int x) {
    int x = 10;
}
```

The function parameter already introduces `x` in the relevant function parameter/body scope.

You cannot simply redeclare another local `x` in the same scope.

However, a deeper nested block could introduce another `x`:

```cpp
void demo(int x) {

    {
        int x = 10;
        cout << x;
    }
}
```

That inner declaration shadows the parameter.

Again, avoid unnecessary shadowing.

---

# 42. Global and Local With Same Name

Example:

```cpp
int number = 10;

int main() {
    int number = 20;

    cout << number;
}
```

Output:

```text
20
```

The local declaration hides the global one.

Use:

```cpp
::number
```

to explicitly access the global namespace version.

Still, better naming usually eliminates the ambiguity entirely.

---

# 43. Static Global / Namespace-Scope Variable

At namespace scope:

```cpp
static int value = 10;
```

has static storage duration, but the `static` keyword also affects linkage in this context.

Specifically, namespace-scope `static` gives the name internal linkage, broadly meaning it is confined to that translation unit for linking purposes.

We have not learned multi-file programs or linkage yet.

For now:

```text
static local:
persistent local object

namespace-scope static:
different use of static; affects linkage
```

Do not assume every appearance of `static` means exactly the same thing.

Linkage is covered with headers and translation units later.

---

# 44. static Has Multiple Meanings

Depending on context, `static` participates in different language features.

You will eventually see:

```text
static local variables
static namespace variables
static class data members
static member functions
```

This folder focuses primarily on:

```cpp
static int count = 0;
```

inside a function.

OOP-related static features come later.

---

# 45. Lifetime and References Preview

Suppose later we write a function that returns a reference to a local variable.

Conceptually:

```cpp
int& bad() {
    int x = 10;
    return x;
}
```

When the function ends:

```text
x's lifetime ends
```

A returned reference would refer to an object that no longer exists.

That creates a dangling reference and using it is invalid/undefined behavior.

We have not learned reference syntax properly yet.

The important lesson is:

```text
scope/lifetime knowledge protects us from dangling access
```

This will matter immediately in the next folder.

---

# 46. Lifetime and Pointers Preview

The same problem can occur with pointers.

Conceptually:

```text
pointer remembers address
object dies
pointer still contains address
```

The address value existing does not mean the original object still exists there.

This creates a dangling pointer.

Therefore:

```text
address validity depends on object lifetime
```

Pointers are studied deeply shortly.

---

# 47. Dynamic Lifetime Preview

Later:

```cpp
new int(10)
```

creates a dynamically allocated object.

Its lifetime is not tied to leaving the current local block in the same way an automatic local's lifetime is.

That is why dynamic memory requires explicit ownership/lifetime management.

Later we will learn:

```text
new/delete
RAII
smart pointers
```

Do not use dynamic allocation yet.

---

# 48. Temporary Object Lifetime Preview

C++ expressions can also create temporary objects.

Example ideas become important with:

- strings
- classes
- return values
- references

Temporary lifetime rules can be subtle.

We will introduce them when the relevant types are known.

This folder's essential foundation is simply:

```text
objects do not necessarily live as long as the names referring to them might suggest
```

---

# 49. State and Functions

Consider:

```cpp
int globalCounter = 0;

void visit() {
    ++globalCounter;
}
```

The function modifies external state.

Compare:

```cpp
int incremented(int value) {
    return value + 1;
}
```

The second style makes data flow explicit.

Given:

```text
input value
```

it produces:

```text
output value
```

without hidden shared mutable state.

This generally makes algorithms easier to test and reason about.

---

# 50. Static Local State Is Also Hidden State

Example:

```cpp
int nextValue() {
    static int value = 0;

    return ++value;
}
```

Calls produce:

```text
1
2
3
```

The output depends not only on explicit arguments but also on earlier calls.

This can be useful.

It can also make functions harder to test because they are stateful.

Use static local state intentionally.

---

# 51. Pure Functions and Lifetime Simplicity

From the functions lesson:

```cpp
int square(int x) {
    return x * x;
}
```

has straightforward local state.

Every call receives a value and computes a result.

No global/static mutable state is involved.

This simplicity makes algorithmic reasoning easier.

Many DSA helper functions should be designed this way when practical.

---

# 52. Recursive Calls Preview

Later recursion may look like:

```cpp
function(3)
    |
    function(2)
        |
        function(1)
```

Every active call has its own local variables.

These local objects can exist simultaneously while earlier calls wait for deeper calls to return.

That is one reason recursion can require:

```text
O(depth)
```

auxiliary stack space.

We will study this formally in recursion.

---

# 53. Scope in Loops

Consider:

```cpp
for (int i = 0; i < 3; ++i) {
    int x = i;
}
```

`x` is created during each iteration when its declaration is executed and its lifetime ends when that iteration leaves the block.

Conceptually:

```text
iteration 0:
create x = 0
destroy x

iteration 1:
create x = 1
destroy x

iteration 2:
create x = 2
destroy x
```

It is not one persistent automatic `x` retaining its previous value.

---

# 54. Static Local Inside a Loop

Compare:

```cpp
for (int i = 0; i < 3; ++i) {
    static int x = 0;

    ++x;
    cout << x << '\n';
}
```

The static local is initialized once and persists.

Output:

```text
1
2
3
```

Even though execution repeatedly enters/leaves the block, the static object remains alive.

Its name is only accessible in the block.

Again:

```text
scope != storage duration
```

---

# 55. Object Identity

Two variables can contain equal values while still being different objects.

Example:

```cpp
int a = 10;
int b = 10;
```

State:

```text
a -> separate int object containing 10
b -> separate int object containing 10
```

Changing:

```cpp
a = 20;
```

does not modify `b`.

This idea prepares you for:

- references
- pointers
- aliases
- copying
- object identity

---

# 56. Common Interview Mistakes

1. Confusing scope with lifetime.

2. Assuming a variable declared in an inner block can be used afterward.

3. Accidentally shadowing an outer variable.

4. Redeclaring the same name in the same scope.

5. Assuming ordinary local integers are automatically initialized to zero.

6. Relying on an observed garbage value.

7. Assuming static locals reset on every function call.

8. Assuming static locals have global scope.

They do not; their names remain locally scoped.

9. Using global mutable state for everything.

10. Assuming local variables from separate function calls are the same objects.

11. Returning references/pointers to automatic local objects.

12. Confusing automatic storage duration with "must physically be on the stack."

13. Thinking scope alone determines whether an object still exists.

14. Forgetting that `static` means different things in different contexts.

15. Forgetting that loop-body local variables are recreated for each normal execution of their declaration.

16. Assuming `break` or `return` somehow preserves automatic locals after leaving their scope.

17. Creating stateful static helpers without realizing calls depend on history.

---

# 57. Complexity

Scope and storage-duration rules generally do not change asymptotic complexity by themselves.

For the primitive examples here:

| Operation | Time | Extra Algorithmic Space |
|---|---:|---:|
| Create scalar local | O(1) | O(1) while alive |
| Assign scalar | O(1) | O(1) |
| Enter/leave simple block | O(1) model | O(1) |
| Access scalar local | O(1) | O(1) |
| Access scalar global | O(1) | O(1) |
| Access scalar static local | O(1) | O(1) |
| Fixed number of nested scopes | O(1) overhead | O(1) |

If a function is called recursively `n` levels deep, each call's local state can contribute to O(n) auxiliary space. Recursion is studied later.

Storage duration also affects when memory is retained, which is distinct from asymptotic operation count.

---

# 58. Practice Questions

This topic is more language-semantic than algorithmic, so dedicated LeetCode problems are uncommon. Use these resources and related exercises:

1. GFG — Scope of Variables in C++  
   https://www.geeksforgeeks.org/scope-of-variables-in-c/

2. cppreference — Scope  
   https://en.cppreference.com/w/cpp/language/scope

3. cppreference — Storage Duration  
   https://en.cppreference.com/w/cpp/language/storage_duration

4. HackerRank — Functions  
   https://www.hackerrank.com/challenges/c-tutorial-functions/problem

5. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

For this folder, manually predicting variable visibility and state is more useful than solving difficult algorithm problems.

---

# 59. Final Mental Model

Whenever you see a variable, ask three separate questions.

Question 1:

```text
Where is this NAME in scope?
```

Question 2:

```text
What storage duration does the OBJECT have?
```

Question 3:

```text
Is the OBJECT currently alive?
```

Example:

```cpp
void visit() {
    static int count = 0;
}
```

Answers:

```text
Scope:
local to visit's block

Storage duration:
static

Lifetime:
once initialized, persists until program termination
```

That distinction is the central lesson of this folder.

---

# What's Next

`01_C++__/10_PASS_BY_VALUE_REFERENCE_POINTER/`

Next we learn one of the most important C++ concepts for DSA: copying values versus aliasing existing objects, reference parameters, pointer parameters, addresses, mutation through functions, `const` references, null pointers, and when each passing style should be used.
