# Pass by Value, Reference, and Pointer

Path:

`DSA_JOURNEY/01_C++__/10_PASS_BY_VALUE_REFERENCE_POINTER/`

## Prerequisites

You should already understand:

- variables and fundamental types
- functions
- parameters and arguments
- scope
- object lifetime
- automatic local variables
- copying scalar values

This folder introduces one of the most important distinctions in C++:

```text
copy an object's value

vs

refer to the existing object

vs

store/access its address
```

These ideas are foundational for:

- arrays
- strings
- linked lists
- trees
- graphs
- recursion
- dynamic memory
- object-oriented programming
- efficient function interfaces

---

# 1. The Core Problem

Suppose:

```cpp
int number = 10;
```

We call:

```cpp
change(number);
```

Should `change` modify the original `number`?

There are several possible interfaces.

Pass by value:

```cpp
void change(int x)
```

Reference parameter:

```cpp
void change(int& x)
```

Pointer parameter:

```cpp
void change(int* x)
```

They behave differently.

---

# 2. Three Mental Models

## Pass by value

```text
caller object
    |
    | copy value
    v
parameter object
```

Changing the parameter does not change the caller's scalar object.

## Reference parameter

```text
caller object
      ^
      |
parameter is an alias
```

The parameter refers to the existing object.

Changing through it changes that object.

## Pointer parameter

```text
caller object
      ^
      |
   address
      |
pointer parameter
```

The function receives an address value and can access the pointed-to object through indirection.

---

# 3. Pass by Value

Function:

```cpp
void change(int x) {
    x = 99;
}
```

Caller:

```cpp
int number = 10;

change(number);

cout << number;
```

Output:

```text
10
```

Why?

`x` is a separate object initialized from `number`.

---

# 4. Full Dry Run: Pass by Value

Before call:

```text
number = 10
```

Call:

```cpp
change(number)
```

A new parameter object is created:

```text
number = 10
x      = 10
```

Inside:

```cpp
x = 99;
```

State:

```text
number = 10
x      = 99
```

Function returns.

`x`'s lifetime ends.

Final:

```text
number = 10
```

---

# 5. Real-World Analogy for Pass by Value

Imagine a document.

You photocopy it and give the copy to someone.

They write:

```text
99
```

on their copy.

Your original document does not change.

That is a useful analogy for pass-by-value semantics.

---

# 6. References

C++ allows a reference to act as another name, or alias, for an existing object.

Example:

```cpp
int number = 10;

int& alias = number;
```

Now:

```text
number
alias
```

refer to the same `int` object.

Example:

```cpp
alias = 50;

cout << number;
```

Output:

```text
50
```

---

# 7. Reference Syntax

Declaration:

```cpp
int& ref = number;
```

Breakdown:

```text
int     referenced type
&       reference declarator
ref     new reference name
number  object being referred to
```

At this point, think:

```text
ref is another way to refer to number
```

---

# 8. Reference Must Be Initialized

A reference normally needs an initializer.

Valid:

```cpp
int value = 10;
int& ref = value;
```

Invalid:

```cpp
int& ref;
```

A reference is not designed as an empty placeholder that can later be made to refer somewhere.

---

# 9. References Do Not Rebind

Consider:

```cpp
int a = 10;
int b = 20;

int& ref = a;

ref = b;
```

A beginner may think:

```text
ref now refers to b
```

It does not.

The statement:

```cpp
ref = b;
```

assigns `b`'s value into the object referred to by `ref`.

Since `ref` refers to `a`:

```text
a becomes 20
```

Reference still refers to `a`.

Final:

```text
a = 20
b = 20
ref aliases a
```

---

# 10. Full Dry Run: Reference Alias

Code:

```cpp
int x = 5;
int& ref = x;

ref = 12;
```

Initial:

```text
x = 5
```

After reference declaration:

```text
x = 5

ref ─────> x
```

After:

```cpp
ref = 12;
```

the same object is modified:

```text
x = 12
```

Therefore:

```cpp
cout << x;
```

prints:

```text
12
```

---

# 11. Pass by Reference

Function:

```cpp
void change(int& x) {
    x = 99;
}
```

Caller:

```cpp
int number = 10;

change(number);
```

The parameter `x` aliases `number`.

Inside:

```cpp
x = 99;
```

modifies the caller's object.

Final:

```text
number = 99
```

---

# 12. Real-World Analogy for Reference Parameters

Pass by value is like giving someone a photocopy.

Pass by reference is like giving someone access to the original whiteboard.

If they erase:

```text
10
```

and write:

```text
99
```

everyone who looks at that original whiteboard now sees:

```text
99
```

---

# 13. Dry Run: Pass by Reference

Code:

```cpp
void increment(int& x) {
    ++x;
}

int main() {
    int number = 5;
    increment(number);
}
```

Before:

```text
number = 5
```

Call:

```text
increment(number)
```

Inside:

```text
x aliases number
```

Execute:

```cpp
++x;
```

State:

```text
number = 6
x refers to number
```

Return.

Final:

```text
number = 6
```

---

# 14. Why Use Reference Parameters?

References are useful when a function should:

```text
modify the caller's object
```

or when later we want to:

```text
avoid copying a potentially large object
```

Examples later include:

```cpp
vector<int>& values
string& text
TreeNode*& root
```

You have not learned those types yet.

For this folder we focus on scalar examples.

---

# 15. const References

Sometimes we want to avoid copying an object but do not want the function to modify it.

C++ provides:

```cpp
const T&
```

Example:

```cpp
void show(const int& x) {
    cout << x;
}
```

Inside `show`, this is not allowed:

```cpp
x = 50;
```

The reference provides read-only access through that interface.

For a tiny `int`, passing by `const` reference is usually unnecessary because copying an `int` is cheap.

But for large types later:

```cpp
const string&
const vector<int>&
```

is extremely common.

---

# 16. Real-World Analogy for const Reference

Imagine giving someone access to an original document in a glass display case.

They can inspect it.

They cannot modify it through the access you gave them.

Conceptually:

```text
reference -> original object
const     -> no modification through this reference
```

---

# 17. const Reference Can Bind to Temporaries

A `const` reference can bind in situations where a non-const lvalue reference cannot.

Example:

```cpp
const int& ref = 10;
```

This is valid.

The lifetime of the temporary used to initialize this local reference is extended to match the reference's lifetime under the relevant lifetime-extension rule.

But:

```cpp
int& ref = 10;
```

is invalid because a non-const lvalue reference cannot bind to that temporary value.

Temporary/reference rules become more important later.

---

# 18. Address of an Object

Every normal object occupies storage somewhere.

The address-of operator is:

```text
&
```

Example:

```cpp
int x = 10;

cout << &x;
```

`&x` means:

```text
address of x
```

The printed address is implementation/runtime dependent.

Example conceptual address:

```text
0x7ffd...
```

Never hard-code or rely on the exact address from one run.

---

# 19. Pointer Basics

A pointer is an object that can store an address.

Example:

```cpp
int value = 10;

int* ptr = &value;
```

Mental model:

```text
value
+----------+
|    10    |
+----------+
     ^
     |
   ptr
```

`ptr` contains the address of `value`.

---

# 20. Pointer Declaration

```cpp
int* ptr;
```

means:

```text
ptr is a pointer to int
```

A safer initialized example:

```cpp
int* ptr = nullptr;
```

Later:

```cpp
int value = 10;
ptr = &value;
```

Now the pointer points to `value`.

---

# 21. Do Not Use an Uninitialized Pointer

Wrong:

```cpp
int* ptr;
```

followed by:

```cpp
cout << *ptr;
```

The pointer has an indeterminate value.

Dereferencing it is invalid behavior.

Prefer:

```cpp
int* ptr = nullptr;
```

when the pointer does not yet point to an object.

---

# 22. nullptr

`nullptr` is the modern C++ null pointer literal.

Example:

```cpp
int* ptr = nullptr;
```

This means:

```text
ptr currently points to no object
```

Prefer:

```cpp
nullptr
```

over older styles such as:

```cpp
NULL
```

or:

```cpp
0
```

for pointer-nullness in modern C++.

---

# 23. Dereference Operator *

If:

```cpp
int value = 10;
int* ptr = &value;
```

then:

```cpp
*ptr
```

means:

```text
the object pointed to by ptr
```

Example:

```cpp
cout << *ptr;
```

Output:

```text
10
```

And:

```cpp
*ptr = 50;
```

modifies:

```text
value
```

Final:

```text
value = 50
```

---

# 24. Real-World Analogy for Pointers

Imagine:

```text
value = a house
pointer = paper containing the house address
```

The paper is not the house.

It tells you where the house is.

Dereferencing means:

```text
go to the address and access the house
```

Similarly:

```text
ptr
```

is the address value.

```text
*ptr
```

accesses the pointed-to object.

---

# 25. Pointer vs Pointed Value

Given:

```cpp
int x = 10;
int* ptr = &x;
```

These are different expressions:

```cpp
ptr
```

means:

```text
address stored in pointer
```

and:

```cpp
*ptr
```

means:

```text
the int object at that address
```

and:

```cpp
&x
```

means:

```text
address of x
```

Thus:

```text
ptr == &x
```

would be true.

---

# 26. Full Pointer Dry Run

Code:

```cpp
int x = 10;
int* ptr = &x;

*ptr = 25;
```

Initial:

```text
x = 10
```

After:

```cpp
int* ptr = &x;
```

state:

```text
x = 10

ptr contains address of x
```

Execute:

```cpp
*ptr = 25;
```

Interpretation:

```text
follow ptr
find x
assign 25 to that object
```

Final:

```text
x = 25
```

---

# 27. Pointer Parameters

A function can accept a pointer.

Example:

```cpp
void change(int* ptr) {
    *ptr = 99;
}
```

Call:

```cpp
int number = 10;

change(&number);
```

The expression:

```cpp
&number
```

provides the address.

Inside:

```cpp
*ptr = 99;
```

modifies the caller's object.

Final:

```text
number = 99
```

---

# 28. Pointer Parameter Dry Run

Before:

```text
number = 10
```

Call:

```cpp
change(&number)
```

The argument is:

```text
address of number
```

Parameter:

```text
ptr = address of number
```

Inside:

```cpp
*ptr = 99
```

Follow pointer:

```text
ptr -> number
```

Modify pointed object:

```text
number = 99
```

Return.

Final:

```text
number = 99
```

---

# 29. Important Terminology: C++ Still Passes the Pointer by Value

Consider:

```cpp
void change(int* ptr)
```

The pointer parameter itself is passed by value.

The function receives a copy of the address.

Conceptually:

```text
caller pointer/address value
          |
          | copy
          v
parameter ptr
```

But both address values can point to the same `int`.

Therefore modifying:

```cpp
*ptr
```

changes the shared pointed-to object.

This distinction is very important.

---

# 30. Reassigning a Pointer Parameter

Consider:

```cpp
void reset(int* ptr) {
    ptr = nullptr;
}
```

Caller:

```cpp
int x = 10;
int* original = &x;

reset(original);
```

Because `ptr` itself was passed by value, assigning:

```cpp
ptr = nullptr;
```

changes only the local pointer copy.

After the call:

```text
original still points to x
```

This surprises many beginners.

To modify the caller's pointer itself, later we could use:

```cpp
int*&
```

but that is a reference-to-pointer and should be understood only after both references and pointers are comfortable.

---

# 31. Reference vs Pointer Parameter

Both can allow a function to modify an existing object.

Reference:

```cpp
void change(int& x) {
    x = 50;
}
```

Call:

```cpp
change(value);
```

Pointer:

```cpp
void change(int* ptr) {
    *ptr = 50;
}
```

Call:

```cpp
change(&value);
```

Reference syntax is usually cleaner when:

```text
an object is required to exist
```

Pointer syntax is often appropriate when:

```text
null/no-object is a meaningful possibility
```

or when an API naturally works with addresses/pointers.

This is a guideline, not a universal law.

---

# 32. Reference vs Pointer Characteristics

Beginner mental model:

```text
REFERENCE
- alias to an object
- normally initialized immediately
- cannot be reseated
- used with ordinary variable syntax
- ordinary reference should refer to a valid object

POINTER
- separate object storing an address
- can be reassigned
- can be nullptr
- dereferenced using *
- address obtained using &
```

Later we will refine this with:

- const pointers
- references to pointers
- pointer arithmetic
- smart pointers
- iterators

---

# 33. Null Pointer Check

This is invalid:

```cpp
int* ptr = nullptr;

cout << *ptr;
```

Dereferencing a null pointer causes undefined behavior.

Check first:

```cpp
if (ptr != nullptr) {
    cout << *ptr;
}
```

or idiomatically:

```cpp
if (ptr) {
    cout << *ptr;
}
```

A null pointer converts to false.

A non-null pointer converts to true.

---

# 34. Safe Pointer Function

Example:

```cpp
void increment(int* ptr) {
    if (ptr == nullptr) {
        return;
    }

    ++(*ptr);
}
```

Now:

```cpp
increment(nullptr);
```

does not dereference the null pointer.

And:

```cpp
int x = 5;
increment(&x);
```

makes:

```text
x = 6
```

---

# 35. Why Parentheses Around *ptr?

Consider:

```cpp
++(*ptr);
```

This clearly means:

```text
increment the pointed-to int
```

Operator precedence also allows forms you will see, but parentheses can make pointer expressions easier to read while learning.

Later:

```cpp
(*ptr)++
```

means:

```text
post-increment pointed-to value
```

whereas pointer arithmetic expressions involving:

```cpp
ptr++
```

move the pointer itself.

Pointer arithmetic gets a dedicated folder.

---

# 36. const Reference Parameter

Suppose a function only needs to inspect:

```cpp
void show(const int& value) {
    cout << value;
}
```

Attempting:

```cpp
value = 20;
```

inside the function would fail to compile.

This is a promise enforced through that reference:

```text
function does not modify the object through value
```

Again, for a tiny `int`, simply passing by value is usually better.

The pattern becomes important for larger objects.

---

# 37. Pointer to const

A pointer can provide read-only access to the pointed object:

```cpp
const int* ptr = &value;
```

Equivalent commonly written form:

```cpp
int const* ptr = &value;
```

Through `ptr`:

```cpp
cout << *ptr;
```

is allowed.

But:

```cpp
*ptr = 50;
```

is not allowed.

The pointer itself may still be reassigned:

```cpp
ptr = &anotherValue;
```

---

# 38. const Pointer

This is different:

```cpp
int* const ptr = &value;
```

The pointer itself cannot be reassigned.

But the pointed-to `int` can be modified:

```cpp
*ptr = 50;
```

allowed.

But:

```cpp
ptr = &other;
```

not allowed.

---

# 39. Pointer to const vs const Pointer

Read:

```cpp
const int* ptr
```

as:

```text
pointer to const int
```

Cannot modify the `int` through this pointer.

Pointer may point elsewhere.

Read:

```cpp
int* const ptr
```

as:

```text
const pointer to int
```

Pointer cannot point elsewhere.

Pointed int may be modified.

Both const:

```cpp
const int* const ptr = &value;
```

means:

```text
pointer cannot be reassigned
and
pointed object cannot be modified through ptr
```

This syntax becomes important in advanced C++ and data structures.

---

# 40. Reference to const vs Pointer to const

Reference:

```cpp
const int& ref = value;
```

Pointer:

```cpp
const int* ptr = &value;
```

Usage:

```cpp
cout << ref;
cout << *ptr;
```

Reference:

```text
direct alias-like syntax
```

Pointer:

```text
explicit indirection
can be nullptr
can be reseated
```

---

# 41. Swap: Classic Pass-by-Value Failure

Suppose:

```cpp
void swapValues(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Caller:

```cpp
int x = 10;
int y = 20;

swapValues(x, y);
```

Inside, only copies are swapped.

Final caller state:

```text
x = 10
y = 20
```

No real swap occurred outside the function.

---

# 42. Swap Using References

Correct:

```cpp
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Caller:

```cpp
int x = 10;
int y = 20;

swapValues(x, y);
```

Dry run:

```text
a aliases x
b aliases y

temp = 10

a = b
x = 20

b = temp
y = 10
```

Final:

```text
x = 20
y = 10
```

---

# 43. Swap Using Pointers

Also possible:

```cpp
void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

Call:

```cpp
swapValues(&x, &y);
```

This modifies the pointed objects.

For required non-null objects, references often produce cleaner interfaces.

---

# 44. Returning Multiple Results via References

Suppose a function computes quotient and remainder.

One approach:

```cpp
void divide(
    int a,
    int b,
    int& quotient,
    int& remainder
) {
    quotient = a / b;
    remainder = a % b;
}
```

Caller:

```cpp
int q;
int r;

divide(17, 5, q, r);
```

Final:

```text
q = 3
r = 2
```

This is sometimes called using output parameters.

Later, modern C++ alternatives include:

- `pair`
- `tuple`
- structs

Those can often produce clearer interfaces.

---

# 45. Input, Output, and In-Out Parameters

A useful conceptual classification:

Input-only:

```cpp
int x
```

or for larger objects:

```cpp
const T& x
```

Output/in-out:

```cpp
T& x
```

Optional pointer-like relationship:

```cpp
T* ptr
```

But the type syntax alone does not fully document semantics.

Good function names and documentation still matter.

---

# 46. Returning by Value

Do not assume references/pointers are always "more efficient."

For simple values:

```cpp
int square(int x)
```

is ideal.

Returning:

```cpp
int
```

by value is natural and efficient.

Modern C++ also optimizes many returns of larger objects very effectively.

Do not replace clear value semantics with pointers merely because you fear copies.

Use the interface that models ownership and mutation correctly.

---

# 47. When to Pass int by Value

For cheap scalar types:

```text
int
double
char
bool
pointer values
```

pass-by-value is normally appropriate when the function does not need to modify the caller's variable.

Example:

```cpp
int square(int x);
```

Prefer this over:

```cpp
int square(const int& x);
```

for an ordinary `int`.

The reference adds indirection/semantic complexity without useful copy savings.

---

# 48. When const Reference Becomes Valuable

Later:

```cpp
void printVector(const vector<int>& values);
```

Why?

If a vector contains one million integers, passing by value conceptually requests a copy of the vector.

Passing by const reference allows read-only access without copying the container.

We have not learned `vector` deeply yet, but the design principle is important.

---

# 49. Pointer Variables Are Also Values

Suppose:

```cpp
int x = 10;

int* p1 = &x;
int* p2 = p1;
```

The pointer value is copied.

State:

```text
p1 -> x
p2 -> x
```

There are now two pointer objects containing the same address.

Modify:

```cpp
*p2 = 50;
```

Now:

```text
x = 50
```

This is analogous to copying someone's street address onto two pieces of paper.

Both papers can lead to the same house.

---

# 50. Pointer Reassignment

Example:

```cpp
int a = 10;
int b = 20;

int* ptr = &a;
```

State:

```text
ptr -> a
```

Then:

```cpp
ptr = &b;
```

State:

```text
ptr -> b
```

Unlike a reference, a pointer can normally be reseated.

The values of `a` and `b` themselves do not change merely because `ptr` changes where it points.

---

# 51. Dangling Pointer

Consider:

```cpp
int* ptr = nullptr;

{
    int value = 10;

    ptr = &value;
}
```

After the block:

```text
value's lifetime has ended
```

`ptr` still contains an address value, but it no longer points to a live `int` object.

It is dangling.

Dereferencing it is undefined behavior.

This directly connects to the previous scope/lifetime lesson.

---

# 52. Dangling Reference

Similarly, do not return a reference to an automatic local variable.

Wrong:

```cpp
int& badFunction() {
    int value = 10;

    return value;
}
```

`value` dies when the function returns.

The returned reference is dangling.

Compiler warnings may detect this.

Never use this pattern.

---

# 53. Returning Pointer to Local Is Also Wrong

Wrong:

```cpp
int* badFunction() {
    int value = 10;

    return &value;
}
```

When the function returns:

```text
value's lifetime ends
```

Returned pointer:

```text
dangling
```

A memory address is not a lifetime guarantee.

This is one of the most important pointer rules.

---

# 54. Reference Lifetime Does Not Extend Ordinary Local Lifetime

A reference is an alias.

It does not generally keep an automatic local variable alive after the variable's lifetime would normally end.

Example concept:

```text
local object created
reference points/refers to it
block ends
local object dies
reference outside would be invalid
```

Do not think references provide ownership.

---

# 55. References Are Not Owners

References typically express:

```text
this function/object refers to something that already exists
```

They do not usually mean:

```text
this reference owns the referred object and controls its lifetime
```

Ownership becomes crucial with dynamic memory and smart pointers.

---

# 56. Raw Pointers Do Not Automatically Express Ownership Either

A raw pointer:

```cpp
int* ptr
```

stores an address.

By itself, it does not tell you whether:

- it owns an allocation
- it merely observes another object
- it may be null
- it points to one object or an array
- someone else controls lifetime

This ambiguity is one reason modern C++ uses:

- references
- containers
- RAII
- smart pointers

for clearer ownership.

Raw pointers remain important for understanding data structures and low-level behavior.

---

# 57. Pointer Size Is Not Pointed Object Size

On a common 64-bit platform:

```cpp
sizeof(int*)
```

may be:

```text
8
```

But this is implementation-dependent.

A pointer stores address-like information.

Its size is not:

```text
sizeof(pointed object)
```

For example, `int*` and `double*` often have the same size on mainstream systems despite pointing to objects of different sizes.

Do not rely on one specific pointer size unless the environment guarantees it.

---

# 58. Address Output

You can print:

```cpp
cout << &value;
```

for many object-pointer cases, and the stream formats the pointer representation.

Exact output:

```text
0x...
```

is not stable.

It can vary:

- across runs
- across platforms
- across compiler/runtime configurations

When dry-running pointers, use symbolic addresses:

```text
ADDR_X
ADDR_Y
```

rather than memorizing numeric addresses.

---

# 59. Symbolic Pointer Dry Run

Code:

```cpp
int x = 10;
int y = 20;

int* ptr = &x;
```

Represent:

```text
x:
address = ADDR_X
value   = 10

y:
address = ADDR_Y
value   = 20

ptr:
value = ADDR_X
```

Then:

```cpp
*ptr = 15;
```

State:

```text
x = 15
y = 20
ptr = ADDR_X
```

Then:

```cpp
ptr = &y;
```

State:

```text
x = 15
y = 20
ptr = ADDR_Y
```

Then:

```cpp
*ptr = 99;
```

State:

```text
x = 15
y = 99
ptr = ADDR_Y
```

This symbolic technique is extremely useful when learning linked lists later.

---

# 60. Reference Address

Given:

```cpp
int x = 10;
int& ref = x;
```

Then:

```cpp
&x
```

and:

```cpp
&ref
```

produce the address of the same referred object in this ordinary case.

Conceptually:

```text
ref is an alias for x
```

This helps reinforce that a reference is not an independent copied `int`.

---

# 61. Function Overload Implications Preview

Later we can have:

```cpp
void process(int x);
void process(int* x);
```

because parameter types differ.

Reference/value overload combinations can become more subtle due to overload resolution.

Function overloading gets the next dedicated lesson after this one.

For now, avoid creating ambiguous overload sets.

---

# 62. Reference-to-Pointer Preview

Suppose:

```cpp
void reset(int*& ptr) {
    ptr = nullptr;
}
```

Now `ptr` is a reference to the caller's pointer object.

So:

```cpp
int value = 10;
int* p = &value;

reset(p);
```

can change:

```text
p
```

itself to `nullptr`.

Mental model:

```text
reference
    |
    v
caller's pointer
    |
    v
pointed object
```

This is useful later in linked-list functions that may need to change a head pointer.

---

# 63. Pointer-to-Pointer Preview

Another technique is:

```cpp
int**
```

which means:

```text
pointer to pointer to int
```

It can also allow a function to manipulate a pointer through another address level.

We do not need to master this yet.

It becomes clearer after the dedicated pointers and linked-list lessons.

---

# 64. const Correctness

"Const correctness" means expressing which data should not be modified.

Example:

```cpp
void inspect(const int& x);
```

communicates:

```text
inspect does not modify x through this parameter
```

Benefits include:

- compiler enforcement
- clearer interfaces
- fewer accidental mutations
- ability to work with const objects

Const correctness becomes especially valuable with classes and containers.

---

# 65. Aliasing

Aliasing means multiple expressions/names/access paths refer to the same underlying object.

Example:

```cpp
int x = 10;

int& ref = x;
int* ptr = &x;
```

Now:

```text
x
ref
*ptr
```

all designate/access the same `int` object.

Modification through any mutable access path can affect what all others observe.

This is a deep concept that matters in optimization, APIs, and data structures.

---

# 66. Aliasing Dry Run

Initial:

```text
x = 10
ref aliases x
ptr points to x
```

Execute:

```cpp
ref = 20;
```

State:

```text
x = 20
*ptr = 20
ref = 20
```

Execute:

```cpp
*ptr = 30;
```

State:

```text
x = 30
ref = 30
*ptr = 30
```

There are not three integer objects.

There is one integer object with multiple access paths.

---

# 67. Pass-by-Value Can Protect Caller State

Copying is not inherently bad.

Example:

```cpp
int absoluteCopy(int x) {
    if (x < 0) {
        x = -x;
    }

    return x;
}
```

The function can freely modify its local parameter without affecting the caller.

Pass-by-value can make reasoning safer when modification should remain local.

---

# 68. Reference Parameters Make Mutation Less Obvious at Call Site

Compare:

```cpp
change(x);
```

If `change` takes:

```cpp
int&
```

the call syntax itself does not visually show that `x` may be modified.

Compare pointer style:

```cpp
change(&x);
```

which visibly passes an address.

This is one tradeoff between reference and pointer interfaces.

Good naming helps:

```cpp
increment(x);
swapValues(a, b);
```

clearly suggests mutation.

---

# 69. Prefer Return Values When Natural

Suppose:

```cpp
void square(int x, int& result) {
    result = x * x;
}
```

This works.

But this is simpler:

```cpp
int square(int x) {
    return x * x;
}
```

Use output references/pointers when the interface genuinely benefits from them.

Do not use them merely because you can.

---

# 70. Swap and std::swap Preview

Later, the Standard Library provides:

```cpp
std::swap(a, b);
```

Our manual reference swap:

```cpp
void swapValues(int& a, int& b)
```

is educational because it demonstrates why references are useful.

Once STL is learned, prefer the standard facility where appropriate.

---

# 71. Efficiency: Scalar Values

For:

```cpp
int
char
bool
double
```

copying is cheap.

Use pass-by-value for read-only scalar input:

```cpp
int square(int x)
```

rather than mechanically writing:

```cpp
int square(const int& x)
```

"References are faster" is not a reliable universal rule.

---

# 72. Efficiency: Large Objects

For a large object copied by value, the cost may be proportional to the object's size.

Conceptual example:

```text
object has n elements

pass by value:
copy n elements -> potentially O(n)

pass by const reference:
no full object copy -> O(1) parameter binding model
```

Actual types and implementations matter.

This is why complexity can be affected by parameter-passing choices.

Later, passing a vector by value accidentally can turn efficient algorithms into much more expensive ones.

---

# 73. Function Complexity Trap

Suppose later:

```cpp
void process(vector<int> values)
```

receives a vector by value.

A copy of the vector may cost:

```text
O(n)
```

before the function body even begins its main work.

Whereas:

```cpp
void process(const vector<int>& values)
```

avoids that full copy.

We have not formally learned `vector` yet, but remember this when we reach STL.

---

# 74. Common Interview Mistakes

1. Expecting pass-by-value to modify the caller.

2. Using reference parameters without understanding aliasing.

3. Thinking a reference contains a copied value.

4. Thinking references can normally be reseated.

5. Declaring an uninitialized reference.

6. Confusing:

```cpp
int& ref
```

with pointer syntax.

7. Confusing:

```cpp
&x
```

address-of with `&` in a reference declaration.

8. Confusing:

```cpp
int* ptr
```

with:

```cpp
*ptr
```

declaration vs dereference context.

9. Dereferencing `nullptr`.

10. Dereferencing an uninitialized pointer.

11. Returning a pointer to a local automatic object.

12. Returning a reference to a local automatic object.

13. Using a pointer after its pointed object has died.

14. Thinking reassigning a pointer parameter changes the caller's pointer.

15. Forgetting pointer parameters themselves are passed by value unless a reference-to-pointer or equivalent is used.

16. Passing every scalar by const reference for "performance."

17. Passing large objects by value accidentally.

18. Modifying data through a reference when the function should be read-only.

19. Confusing `const int*` with `int* const`.

20. Assuming raw pointers automatically communicate ownership.

21. Assuming pointer addresses are stable between program runs.

22. Using references or pointers when a simple return value would make the API clearer.

---

# 75. Complexity Table

For the scalar examples in this folder:

| Operation | Time | Extra Space |
|---|---:|---:|
| Copy an `int` | O(1) | O(1) |
| Bind an lvalue reference | O(1) model | O(1) |
| Copy a raw pointer | O(1) | O(1) |
| Take address `&x` | O(1) | O(1) |
| Dereference valid pointer `*ptr` | O(1) model | O(1) |
| Modify via reference | O(1) | O(1) |
| Modify via valid pointer | O(1) | O(1) |
| Null check | O(1) | O(1) |
| Swap two scalar ints | O(1) | O(1) |

For large objects, pass-by-value can require a nonconstant copy. We will analyze those costs when containers are introduced.

---

# 76. Practice Questions

1. HackerRank — Pointer  
   https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

2. GFG — References in C++  
   https://www.geeksforgeeks.org/references-in-cpp/

3. GFG — Pointers in C++  
   https://www.geeksforgeeks.org/cpp-pointers/

4. LeetCode 2235 — Add Two Integers  
   https://leetcode.com/problems/add-two-integers/

5. LeetCode 1929 — Concatenation of Array  
   https://leetcode.com/problems/concatenation-of-array/

The array problem belongs to an upcoming topic; bookmark it for later. The HackerRank pointer exercise is especially relevant now.

---

# 77. Final Decision Guide

For a simple scalar read-only input:

```cpp
int square(int x)
```

Use pass by value.

When a function must modify an existing required object:

```cpp
void increment(int& x)
```

A non-const reference is natural.

When a function should read a potentially expensive-to-copy object:

```cpp
void inspect(const T& value)
```

`const` reference is often appropriate.

When "no object" is a meaningful possibility or pointer semantics are natural:

```cpp
void inspect(const T* ptr)
```

a pointer may be appropriate.

Do not select a parameter style from memorized slogans.

Ask:

```text
Do I need a copy?
Do I need mutation?
Can there be no object?
Who owns the object?
How expensive is copying?
How long will the referred object live?
```

---

# 78. Final Mental Model

Pass by value:

```text
original
   |
   | COPY
   v
parameter
```

Reference:

```text
parameter
    |
    +------> original object
```

Pointer:

```text
pointer parameter
      |
      | stores address
      v
original object
```

And always remember:

```text
reference/pointer validity depends on object lifetime
```

That one idea will reappear throughout linked lists, trees, dynamic memory, and advanced C++.

---

# What's Next

`01_C++__/11_FUNCTION_OVERLOADING_DEFAULT_ARGUMENTS/`

Next we study multiple functions with the same name, overload resolution basics, ambiguous overloads, default arguments, where defaults are declared, and common interview traps involving function interfaces.
