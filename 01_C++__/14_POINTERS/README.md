# Pointers in C++

Path:

`DSA_JOURNEY/01_C++__/14_POINTERS/`

## Prerequisites

You should already understand:

- variables and object lifetime
- scope
- functions
- pass by value
- references
- introductory pointer parameters
- arrays
- array-to-pointer conversion
- C-strings
- `const`

This folder develops a reliable pointer mental model before we move into pointer arithmetic and dynamic memory.

Pointers are foundational for:

- linked lists
- trees
- graphs
- dynamic memory
- polymorphism
- low-level APIs
- iterators
- smart pointers
- understanding how arrays work

---

# 1. What Is a Pointer?

A pointer is an object whose value can represent the address of another object or function, or a special null pointer value.

Example:

```cpp
int number = 10;

int* ptr = &number;
```

Conceptually:

```text
number
+------------+
|     10     |
+------------+
      ^
      |
      |
     ptr
```

`ptr` contains an address that designates `number`.

---

# 2. Real-World Analogy

Imagine a house:

```text
House:
42 Algorithm Street
```

The house contains furniture.

A piece of paper contains:

```text
"42 Algorithm Street"
```

The paper is not the house.

It contains information that tells you where the house is.

Likewise:

```text
object
```

contains data.

A:

```text
pointer
```

contains an address.

Dereferencing the pointer means:

```text
use the address to access the object
```

---

# 3. Pointer Declaration

Example:

```cpp
int* ptr;
```

Read this as:

```text
ptr is a pointer to int
```

The pointed-to type matters.

Examples:

```cpp
int* intPointer;
double* doublePointer;
char* charPointer;
bool* boolPointer;
```

These are different pointer types.

---

# 4. Prefer Initialization

This declaration alone:

```cpp
int* ptr;
```

creates an uninitialized local pointer.

Its value is indeterminate.

Do not dereference it.

Prefer:

```cpp
int* ptr = nullptr;
```

when there is no object to point to yet.

Or initialize directly:

```cpp
int value = 10;
int* ptr = &value;
```

---

# 5. Address-of Operator

Given:

```cpp
int value = 10;
```

the expression:

```cpp
&value
```

produces the address of `value`.

Example:

```cpp
int* ptr = &value;
```

State:

```text
value = 10

ptr = address of value
```

The actual numeric address depends on the execution environment.

Use symbolic addresses when dry-running:

```text
ADDR_VALUE
```

rather than assuming actual values such as `0x1234`.

---

# 6. Dereference Operator

Given:

```cpp
int value = 10;
int* ptr = &value;
```

the expression:

```cpp
*ptr
```

accesses the pointed-to `int`.

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

changes `value`.

Final:

```text
value = 50
```

---

# 7. Symbolic Memory Dry Run

Code:

```cpp
int x = 10;
int* ptr = &x;
```

Represent memory symbolically:

```text
Object x
address: ADDR_X
value:   10

Object ptr
address: ADDR_PTR
value:   ADDR_X
```

Important:

`ptr` itself is also an object.

It has its own storage and its own address.

Its stored value happens to be another object's address.

---

# 8. &ptr vs ptr vs *ptr

Given:

```cpp
int x = 10;
int* ptr = &x;
```

Three different expressions:

```text
ptr
```

means:

```text
address stored in ptr
= address of x
```

```text
*ptr
```

means:

```text
the pointed-to x object/value
```

```text
&ptr
```

means:

```text
address of the pointer object itself
```

Mental diagram:

```text
ADDR_PTR
+----------------+
| ptr = ADDR_X   |
+----------------+
         |
         v
ADDR_X
+----------------+
| x = 10         |
+----------------+
```

---

# 9. Pointer Reassignment

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

Neither `a` nor `b` changes just because the pointer was reseated.

---

# 10. Dry Run: Reassignment

Initial:

```text
a = 10 at ADDR_A
b = 20 at ADDR_B
ptr = ADDR_A
```

Execute:

```cpp
*ptr = 15;
```

State:

```text
a = 15
b = 20
ptr = ADDR_A
```

Execute:

```cpp
ptr = &b;
```

State:

```text
a = 15
b = 20
ptr = ADDR_B
```

Execute:

```cpp
*ptr = 99;
```

Final:

```text
a = 15
b = 99
ptr = ADDR_B
```

---

# 11. nullptr

Modern C++ represents an intentional null pointer using:

```cpp
nullptr
```

Example:

```cpp
int* ptr = nullptr;
```

Meaning:

```text
ptr currently does not point to an int object
```

A null pointer is still a valid pointer value.

But it does not designate an object that can be dereferenced.

---

# 12. Null Pointer Dereference

Wrong:

```cpp
int* ptr = nullptr;

cout << *ptr;
```

Dereferencing a null pointer causes undefined behavior.

The program may crash, but a crash is not guaranteed.

Always ensure the pointer designates a valid object before dereferencing.

---

# 13. Checking a Pointer

Explicit:

```cpp
if (ptr != nullptr) {
    cout << *ptr;
}
```

Idiomatic:

```cpp
if (ptr) {
    cout << *ptr;
}
```

A null pointer converts to:

```text
false
```

A non-null pointer converts to:

```text
true
```

---

# 14. nullptr vs 0 vs NULL

Older C++ code may use:

```cpp
0
```

or:

```cpp
NULL
```

to represent null pointers.

Modern C++ should prefer:

```cpp
nullptr
```

Why?

`nullptr` has a dedicated type and behaves more predictably with function overloading.

Example:

```cpp
void f(int);
void f(int*);
```

Using:

```cpp
f(nullptr);
```

clearly selects a pointer-related overload.

Using an integer `0` participates as an integer expression and can create different overload behavior.

---

# 15. Pointer Copying

Pointers themselves are ordinary copyable values.

Example:

```cpp
int value = 10;

int* p1 = &value;
int* p2 = p1;
```

State:

```text
p1 -> value
p2 -> value
```

There is still only one `int value`.

There are two pointer objects containing the same address.

---

# 16. Aliasing Through Multiple Pointers

Given:

```cpp
int value = 10;

int* p1 = &value;
int* p2 = &value;
```

Execute:

```cpp
*p1 = 50;
```

Then:

```text
value = 50
*p2 = 50
```

Both pointers access the same object.

This is aliasing.

Aliasing becomes essential in linked structures.

---

# 17. Pointer Parameters

Example:

```cpp
void change(int* ptr) {
    if (ptr != nullptr) {
        *ptr = 100;
    }
}
```

Call:

```cpp
int value = 10;

change(&value);
```

Final:

```text
value = 100
```

The function receives a copy of the pointer/address value.

The pointed object is shared.

---

# 18. Pointer Parameter Is Passed by Value

Function:

```cpp
void reset(int* ptr) {
    ptr = nullptr;
}
```

Call:

```cpp
int value = 10;
int* original = &value;

reset(original);
```

Inside:

```text
ptr becomes nullptr
```

But caller:

```text
original still points to value
```

because only the pointer parameter copy was modified.

---

# 19. Reference to Pointer

If a function needs to modify the caller's pointer itself:

```cpp
void reset(int*& ptr) {
    ptr = nullptr;
}
```

Now:

```cpp
reset(original);
```

changes:

```text
original
```

itself.

Mental model:

```text
ptr reference
    |
    v
caller's pointer object
    |
    v
pointed object
```

This pattern later appears in linked-list implementations that need to change a head pointer.

---

# 20. Pointer to Pointer

A pointer can point to another pointer.

Example:

```cpp
int value = 10;

int* ptr = &value;

int** ptrToPtr = &ptr;
```

Diagram:

```text
ptrToPtr
   |
   v
 ptr
   |
   v
value
```

Types:

```text
value     -> int
ptr       -> int*
ptrToPtr  -> int**
```

---

# 21. Double Dereference

Given:

```cpp
int value = 10;
int* ptr = &value;
int** pp = &ptr;
```

Then:

```cpp
*pp
```

is:

```text
ptr
```

and:

```cpp
**pp
```

is:

```text
value
```

Example:

```cpp
**pp = 99;
```

Final:

```text
value = 99
```

---

# 22. Full Double-Pointer Dry Run

State:

```text
value = 10
ptr = ADDR_VALUE
pp = ADDR_PTR
```

Evaluate:

```cpp
*pp
```

Follow `pp`:

```text
find ptr
```

Result:

```text
ADDR_VALUE
```

Evaluate:

```cpp
**pp
```

Follow the resulting pointer:

```text
find value
```

Result:

```text
10
```

Execute:

```cpp
**pp = 50;
```

Final:

```text
value = 50
```

---

# 23. Why Pointer-to-Pointer Exists

It becomes useful when:

- modifying a pointer through another pointer
- representing arrays of pointers
- C APIs use output pointers
- building certain dynamic data structures
- working with command-line argument representations
- managing multi-level indirection

For DSA, you will commonly encounter it while manually manipulating linked structures or dynamic 2D memory.

---

# 24. Pointer Type Matters

Example:

```cpp
int number = 10;
```

Correct:

```cpp
int* ptr = &number;
```

Not:

```cpp
double* ptr = &number;
```

The pointer type tells C++ what kind of object it is allowed to access through that pointer.

This affects:

- dereference type
- pointer arithmetic
- type checking
- const correctness

---

# 25. void*

C++ provides a generic object pointer type:

```cpp
void*
```

Example:

```cpp
int value = 10;

void* generic =
    &value;
```

A `void*` can hold the address of an object, subject to language conversion rules.

But:

```cpp
*generic
```

is invalid because `void` has no object size/type information suitable for ordinary dereferencing.

You must convert back to an appropriate object pointer type before accessing the object.

---

# 26. void* Example

```cpp
int value = 10;

void* generic = &value;

int* ptr =
    static_cast<int*>(generic);

cout << *ptr;
```

Output:

```text
10
```

`void*` is useful in low-level generic C-style APIs.

Modern C++ often prefers type-safe templates and abstractions instead.

---

# 27. const int*

Declaration:

```cpp
const int* ptr;
```

Read:

```text
pointer to const int
```

Example:

```cpp
int value = 10;

const int* ptr =
    &value;
```

Allowed:

```cpp
cout << *ptr;
```

Not allowed:

```cpp
*ptr = 50;
```

The pointer cannot be used to modify the pointed object.

---

# 28. Pointer-to-const Can Be Reseated

Example:

```cpp
int a = 10;
int b = 20;

const int* ptr = &a;
```

Later:

```cpp
ptr = &b;
```

This is allowed.

So:

```text
pointed value read-only through ptr
pointer itself mutable
```

---

# 29. int* const

Declaration:

```cpp
int* const ptr = &value;
```

Read:

```text
const pointer to int
```

Pointer cannot be reseated.

Allowed:

```cpp
*ptr = 50;
```

Not allowed:

```cpp
ptr = &another;
```

---

# 30. const int* const

```cpp
const int* const ptr =
    &value;
```

Meaning:

```text
const pointer
to
const int
```

Through this pointer:

```text
cannot reseat pointer
cannot modify pointed int
```

---

# 31. Const Pointer Cheat Sheet

```text
int* p
```

pointer mutable, pointee mutable.

```text
const int* p
```

pointer mutable, pointee read-only through p.

```text
int* const p
```

pointer fixed, pointee mutable.

```text
const int* const p
```

pointer fixed, pointee read-only through p.

A useful reading technique is to start at the variable name and work outward.

---

# 32. Const Object and Pointer

Given:

```cpp
const int value = 10;
```

You cannot create:

```cpp
int* ptr = &value;
```

because that would provide mutable access to a const object.

Correct:

```cpp
const int* ptr =
    &value;
```

Const correctness prevents accidental mutation.

---

# 33. Removing const With const_cast

C++ has:

```cpp
const_cast
```

which can alter const qualification in certain type relationships.

Example syntax:

```cpp
const_cast<int*>(ptr)
```

But this does not make an actually const object safe to modify.

If an object was originally defined as const:

```cpp
const int value = 10;
```

casting away constness and attempting modification produces undefined behavior.

Do not use `const_cast` to "defeat" correct type safety.

It is rarely needed in normal DSA code.

---

# 34. Dangling Pointer

A dangling pointer points to storage where the object it formerly designated no longer exists.

Example:

```cpp
int* ptr = nullptr;

{
    int value = 10;

    ptr = &value;
}
```

After the block:

```text
value lifetime ended
```

But:

```text
ptr still contains old address information
```

It is dangling.

Do not dereference it.

---

# 35. Real-World Analogy for Dangling Pointer

Imagine writing a house address on paper.

Later the house is demolished.

The paper still contains:

```text
42 Algorithm Street
```

but the original house no longer exists.

Likewise, an address value may remain after the object's lifetime ends.

Address existence is not proof of object existence.

---

# 36. Returning Pointer to Local

Wrong:

```cpp
int* bad() {
    int value = 10;

    return &value;
}
```

When `bad()` returns:

```text
value's lifetime ends
```

The returned pointer is dangling.

Never return a pointer to an automatic local object.

---

# 37. Pointer Lifetime vs Pointee Lifetime

These are separate.

Example:

```cpp
int value = 10;

{
    int* ptr = &value;
}
```

Here the pointer object dies first.

`value` remains alive.

Reverse situation:

```cpp
int* ptr = nullptr;

{
    int value = 10;
    ptr = &value;
}
```

Here `ptr` remains alive but its former pointee dies.

So always ask:

```text
Is the pointer object alive?

AND

Is the pointed-to object alive?
```

Both matter.

---

# 38. Wild Pointer Terminology

A colloquial term:

```text
wild pointer
```

often means an uninitialized pointer such as:

```cpp
int* ptr;
```

whose indeterminate value is then misused.

Prefer initialized pointers:

```cpp
int* ptr = nullptr;
```

The C++ standard itself does not use "wild pointer" as a formal core-language category.

It is common educational terminology.

---

# 39. Invalid Pointer

A pointer can become invalid for many reasons.

Examples later include:

- pointed local object dies
- dynamically allocated object is deleted
- vector reallocation invalidates pointers into its storage
- container element erased
- pointer arithmetic leaves permitted range and is then misused

Pointer validity is fundamentally tied to object lifetime and API invalidation rules.

---

# 40. Arrays and Pointers

Given:

```cpp
int values[3] = {
    10, 20, 30
};
```

in many expressions:

```cpp
values
```

converts to a pointer to its first element:

```cpp
&values[0]
```

Example:

```cpp
int* ptr = values;
```

Then:

```cpp
*ptr
```

is:

```text
values[0]
```

or:

```text
10
```

---

# 41. Array Is Not a Pointer

This distinction is critical.

Given:

```cpp
int values[3];
```

`values` is an array object.

It is not itself a pointer object.

But in many expressions it is converted to a pointer to its first element.

Evidence:

```cpp
sizeof(values)
```

reports total array storage.

Whereas:

```cpp
int* ptr = values;

sizeof(ptr)
```

reports pointer storage size.

They are different types and objects.

---

# 42. Array-to-Pointer Conversion Exceptions

An array does not decay to a pointer in every context.

Examples where array type information matters include:

```cpp
sizeof(values)
```

and:

```cpp
&values
```

`&values` is not the same type as:

```cpp
&values[0]
```

Even if their printed address representations often look numerically identical.

Types:

```text
&values[0]
-> int*

&values
-> pointer to entire array
   int (*)[N]
```

This distinction becomes central in pointer arithmetic.

---

# 43. Pointer to Entire Array

Given:

```cpp
int values[3];
```

this:

```cpp
int (*ptr)[3] =
    &values;
```

declares:

```text
ptr is a pointer to array of 3 int
```

Parentheses are necessary.

Without them:

```cpp
int* ptr[3];
```

means:

```text
array of 3 pointers to int
```

These are completely different types.

---

# 44. Pointer to Array vs Array of Pointers

Pointer to array:

```cpp
int (*p)[3];
```

Mental model:

```text
p
|
v
+---+---+---+
|int|int|int|
+---+---+---+
```

Array of pointers:

```cpp
int* p[3];
```

Mental model:

```text
+---------+---------+---------+
| int*    | int*    | int*    |
+---------+---------+---------+
```

Each element is a pointer.

Declaration parentheses change meaning.

---

# 45. 2D Arrays and Pointers

Given:

```cpp
int matrix[2][3];
```

`matrix` is:

```text
array of 2
array-of-3-int rows
```

In many expressions it converts to:

```text
pointer to array of 3 int
```

Type:

```cpp
int (*)[3]
```

That is why a function parameter can be:

```cpp
void print(
    int matrix[][3],
    int rows
);
```

The parameter adjusts to:

```cpp
int (*matrix)[3]
```

---

# 46. Pointer to Struct Preview

Suppose later we define:

```cpp
struct Node {
    int value;
};
```

If:

```cpp
Node* ptr;
```

points to a `Node`, member access can be written:

```cpp
ptr->value
```

This is equivalent to:

```cpp
(*ptr).value
```

Structures come later, so treat this as a preview.

The arrow operator becomes extremely important in linked lists and trees.

---

# 47. Character Pointers

A character pointer has special interactions with C-strings.

Example:

```cpp
const char* text =
    "hello";
```

`text` points to the first character of a null-terminated string literal.

When used with:

```cpp
cout << text;
```

the stream treats it as a C-string and prints characters until `'\0'`.

This differs from ordinary pointer output.

---

# 48. Printing an Ordinary Pointer

For:

```cpp
int value = 10;
int* ptr = &value;
```

`cout << ptr` produces an implementation-defined textual representation of the pointer value/address.

We should not rely on the exact format.

For `char*`/`const char*`, stream insertion normally interprets it as text instead.

---

# 49. Printing a Character Pointer's Address

If you specifically need the address representation rather than C-string content:

```cpp
const char* text = "hello";

cout << static_cast<const void*>(text);
```

Converting to:

```cpp
const void*
```

selects pointer-style output rather than C-string output.

Exact address still varies.

---

# 50. Pointer Comparisons

Pointers can be compared for equality:

```cpp
p1 == p2
p1 != p2
```

This is useful for asking:

```text
Do these pointers represent the same address?
```

Example:

```cpp
int x = 10;

int* p1 = &x;
int* p2 = &x;

cout << (p1 == p2);
```

Output:

```text
true
```

Relational ordering comparisons between pointers have more restricted/nuanced semantics and should not be casually used for unrelated objects.

Pointer arithmetic/comparison within arrays is studied next.

---

# 51. Pointer Equality Does Not Compare Object Values

Example:

```cpp
int a = 10;
int b = 10;

int* p1 = &a;
int* p2 = &b;
```

Then:

```cpp
*p1 == *p2
```

is:

```text
true
```

because both integers contain 10.

But:

```cpp
p1 == p2
```

is normally:

```text
false
```

because they point to distinct objects.

Do not confuse:

```text
pointer equality
```

with:

```text
pointed-value equality
```

---

# 52. Reference vs Pointer

Reference:

```cpp
int& ref = value;
```

Pointer:

```cpp
int* ptr = &value;
```

Reference characteristics:

- alias-like syntax
- normally initialized immediately
- cannot normally be reseated
- no ordinary null-reference state
- accessed directly as `ref`

Pointer characteristics:

- separate address-holding object
- can be null
- can be reseated
- explicit dereference `*ptr`
- supports pointer arithmetic in valid array contexts

---

# 53. When to Prefer Reference

A reference is commonly appropriate when:

```text
an object must exist
```

and the function should:

- read without copying
- modify the caller's object

Examples:

```cpp
void increment(int& value);

void inspect(
    const string& text
);
```

---

# 54. When a Pointer Is Natural

A pointer can be natural when:

- "no object" is represented by `nullptr`
- an API naturally manipulates addresses
- linked structures use pointer links
- C APIs require pointer parameters
- pointer arithmetic is intentionally used with arrays
- multiple levels of indirection are required

Do not use pointers merely because they look lower-level or "faster."

---

# 55. Pointer Ownership

A raw pointer does not automatically communicate ownership.

Given:

```cpp
int* ptr;
```

you do not know merely from the type whether:

- it owns dynamically allocated memory
- it borrows another object's address
- it points to an array
- it is allowed to delete something
- it can be null

Modern C++ uses clearer ownership abstractions such as smart pointers and containers.

We will study those later.

---

# 56. Do Not delete Borrowed Addresses

You have not learned `delete` yet, but this warning is important.

Given:

```cpp
int value = 10;
int* ptr = &value;
```

`ptr` merely points to an automatic object.

You must not later write:

```cpp
delete ptr;
```

Dynamic deallocation only applies to appropriate dynamically allocated objects.

We will study exact rules in dynamic memory.

---

# 57. Pointer Size

On many 64-bit systems:

```text
sizeof(pointer) = 8 bytes
```

But do not assume this universally.

Example:

```cpp
cout << sizeof(int*);
cout << sizeof(double*);
```

They often match on mainstream systems.

The C++ standard does not require every pointer type to have the same representation or size.

Use `sizeof` rather than hard-coded assumptions.

---

# 58. Pointer Type vs Pointee Size

Even when:

```cpp
sizeof(int*) == sizeof(double*)
```

the pointed types are different.

`int*` dereference gives:

```text
int
```

`double*` dereference gives:

```text
double
```

And valid pointer arithmetic scales in terms of the pointee type's array elements.

That scaling is studied in the next folder.

---

# 59. Function Pointers: Introduction

Functions also have addresses.

Suppose:

```cpp
int add(int a, int b) {
    return a + b;
}
```

A pointer to such a function can be declared:

```cpp
int (*operation)(int, int) =
    add;
```

Call:

```cpp
operation(2, 3);
```

Result:

```text
5
```

This syntax looks difficult initially.

Read:

```text
operation
is a pointer
to a function
taking (int, int)
returning int
```

---

# 60. Function Pointer Why?

Function pointers allow behavior to be passed around.

Possible uses:

- callbacks
- custom algorithms
- C APIs
- dispatch tables

Later C++ often uses:

- lambdas
- function objects
- templates
- `std::function`

Function pointers remain important foundational knowledge.

---

# 61. Function Pointer Dry Run

Function:

```cpp
int multiply(int a, int b) {
    return a * b;
}
```

Pointer:

```cpp
int (*operation)(int, int) =
    multiply;
```

Mental state:

```text
operation
    |
    v
multiply function
```

Call:

```cpp
operation(4, 5)
```

transfers control to:

```cpp
multiply(4, 5)
```

Result:

```text
20
```

---

# 62. &function Is Usually Optional in Assignment

These can both be used:

```cpp
int (*op)(int, int) =
    add;
```

and:

```cpp
int (*op)(int, int) =
    &add;
```

Likewise function call syntax commonly works as:

```cpp
op(2, 3)
```

without explicitly writing:

```cpp
(*op)(2, 3)
```

The shorter form is standard and clearer.

---

# 63. nullptr Function Pointer

A function pointer can also be null:

```cpp
int (*operation)(int, int) =
    nullptr;
```

Do not call it until it points to a valid function.

Safe:

```cpp
if (operation != nullptr) {
    operation(1, 2);
}
```

---

# 64. Pointer Declaration Style Trap

Consider:

```cpp
int* a, b;
```

This declares:

```text
a -> int*
b -> int
```

The `*` belongs grammatically to each declarator, not globally to the base type declaration line.

To declare two pointers:

```cpp
int* a;
int* b;
```

or:

```cpp
int *a, *b;
```

For readability, one declaration per line is often safest.

---

# 65. References Have a Similar Declarator Issue

Example:

```cpp
int& a = x, b = y;
```

`a` is a reference.

`b` is an ordinary `int`.

Again, declaration syntax applies per declarator.

Prefer:

```cpp
int& a = x;
int b = y;
```

when teaching or writing clarity-focused code.

---

# 66. Pointer and Reference Operators Depend on Context

Symbol:

```text
&
```

can mean:

```text
reference declarator
address-of operator
bitwise AND
```

Symbol:

```text
*
```

can mean:

```text
pointer declarator
dereference operator
multiplication
```

Context determines meaning.

Examples:

```cpp
int* ptr;       // pointer declarator

int x = *ptr;   // dereference

int product =
    a * b;      // multiplication
```

---

# 67. Indirection Levels

Types:

```text
int       value
int*      pointer to int
int**     pointer to pointer to int
int***    pointer to pointer to pointer to int
```

Every `*` adds one pointer indirection level in this simplified reading.

To reach the underlying int:

```text
int*   -> *p
int**  -> **p
int*** -> ***p
```

provided every pointer in the chain is valid.

---

# 68. Null at Any Level

Example:

```cpp
int** pp;
```

Even if:

```text
pp != nullptr
```

the pointer stored in:

```cpp
*pp
```

could itself be null.

Therefore:

```cpp
**pp
```

is only valid when all required levels designate live objects appropriately.

Pointer chains require checking the correct level.

---

# 69. Pointer-to-Pointer Safe Example

```cpp
int value = 10;
int* ptr = &value;
int** pp = &ptr;
```

Safe because:

```text
pp -> ptr
ptr -> value
```

If later:

```cpp
ptr = nullptr;
```

then:

```text
pp still points to ptr
```

but:

```text
*pp == nullptr
```

and:

```cpp
**pp
```

must not be evaluated.

---

# 70. Address Stability

A local object's address remains its address during that object's lifetime, but some high-level container operations later can move elements to new storage.

For example, vector reallocation can invalidate pointers to its elements.

This means:

```text
pointer validity
```

depends not only on syntax but also on the lifetime/invalidation rules of the object being pointed to.

This becomes a major STL topic.

---

# 71. Pointer Invalidity Is Not Always Visible

A dangling pointer may still print the same address it had before.

That does not make it valid.

Example conceptual state:

```text
ptr = 0xABCD

object alive:
0xABCD designates x

object destroyed:
ptr may still contain 0xABCD
```

The bits remaining in `ptr` do not resurrect the object.

Never test pointer validity by "seeing whether the address looks reasonable."

---

# 72. Setting Dangling Pointers to nullptr

When you manually control a pointer and its pointee becomes invalid, setting the pointer to:

```cpp
nullptr
```

can sometimes help avoid accidental reuse.

However, this only changes that one pointer.

If several aliases pointed to the same object, they are not automatically updated.

Example:

```text
p1 -> object
p2 -> same object
```

Making:

```cpp
p1 = nullptr;
```

does not change:

```text
p2
```

Ownership/lifetime discipline is the real solution.

---

# 73. Raw Pointer Safety Checklist

Before dereferencing:

```cpp
*ptr
```

ask:

1. Was the pointer initialized?
2. Is it non-null?
3. Does it designate the correct type of object?
4. Is that object's lifetime still active?
5. Is the pointer within a valid permitted array/object range?
6. Is the access allowed with respect to `const`?
7. Does the operation respect ownership/invalidation rules?

This checklist prevents most beginner pointer bugs.

---

# 74. Common Interview Mistakes

1. Dereferencing an uninitialized pointer.

2. Dereferencing `nullptr`.

3. Assuming non-null means valid.

4. Using a pointer after its pointee's lifetime ended.

5. Returning the address of an automatic local.

6. Confusing `ptr`, `*ptr`, and `&ptr`.

7. Confusing pointer address with pointed value.

8. Forgetting a pointer parameter itself is normally passed by value.

9. Expecting `ptr = nullptr` inside a value-parameter function to reset the caller's pointer.

10. Confusing `int**` with `int*`.

11. Forgetting to validate every required level of a pointer chain.

12. Confusing:

```cpp
const int*
```

and:

```cpp
int* const
```

13. Casting away const and modifying an actually const object.

14. Thinking an array is literally a pointer object.

15. Using `sizeof(pointer)` to infer an array's length.

16. Confusing:

```cpp
int (*p)[3]
```

with:

```cpp
int* p[3]
```

17. Comparing pointer addresses when the intention was comparing values.

18. Using relational comparisons on unrelated pointers without understanding their semantics.

19. Assuming every pointer type has the same size.

20. Printing `char*` expecting an address.

21. Treating a raw pointer as automatic proof of ownership.

22. Calling `delete` on non-dynamically allocated objects.

23. Keeping pointers to container elements without considering invalidation.

24. Writing several pointer declarations on one line and misreading the declarators.

25. Assuming a dangling pointer will always become `nullptr` automatically.

It will not.

---

# 75. Complexity Table

For valid pointers to ordinary objects:

| Operation | DSA Time | Extra Space |
|---|---:|---:|
| Take address `&x` | O(1) | O(1) |
| Copy pointer | O(1) | O(1) |
| Compare pointer equality | O(1) | O(1) |
| Dereference valid pointer | O(1) | O(1) |
| Assign through pointer | O(1) | O(1) |
| Null check | O(1) | O(1) |
| Follow `**pp` | O(1) | O(1) |
| Reseat pointer | O(1) | O(1) |
| Call through function pointer | body-dependent | O(1) call mechanism model |

Pointer operations may be O(1), but pointer-based algorithms are not automatically O(1). Traversing a linked list through `n` pointers is still O(n).

---

# 76. Practice Questions

1. HackerRank — Pointer  
   https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

2. GFG — Pointers in C++  
   https://www.geeksforgeeks.org/cpp-pointers/

3. GFG — Double Pointer  
   https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/

4. GFG — Function Pointer  
   https://www.geeksforgeeks.org/function-pointer-in-c/

5. LeetCode 876 — Middle of the Linked List  
   https://leetcode.com/problems/middle-of-the-linked-list/

The linked-list problem belongs to a later phase. Bookmark it now; it will become much easier once nodes and linked lists are introduced.

---

# 77. Final Mental Model

One level:

```text
int value = 10;

int* ptr = &value;

ptr
 |
 v
value
```

Two levels:

```text
int** pp = &ptr;

pp
 |
 v
ptr
 |
 v
value
```

Array relationship:

```text
int a[3];

a
(in many expressions)
 |
 v
&a[0]
```

But:

```text
array != pointer object
```

Most important pointer rule:

```text
A pointer is useful only while it designates an object
that you are actually allowed to access.
```

---

# What's Next

`01_C++__/15_POINTER_ARITHMETIC/`

Next we study how pointers move through arrays, `ptr + i`, `ptr - i`, pointer subtraction, one-past-the-end pointers, the equivalence between indexing and pointer expressions, multidimensional array pointer movement, and the undefined behavior traps surrounding invalid pointer arithmetic.
