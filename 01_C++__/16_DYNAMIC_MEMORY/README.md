# Dynamic Memory in C++

Path:

`DSA_JOURNEY/01_C++__/16_DYNAMIC_MEMORY/`

## Prerequisites

You should already understand:

- variables and lifetime
- automatic vs static storage duration
- raw pointers
- pointer arithmetic
- arrays
- function parameters
- dangling pointers
- `nullptr`

This folder introduces dynamic storage duration and manual memory management with:

```cpp
new
delete
new[]
delete[]
```

You need to understand these mechanisms because manual nodes in linked lists, trees, tries, and many textbook data structures rely on dynamically created objects.

At the same time, modern C++ generally prefers RAII-based ownership such as:

```text
std::vector
std::string
std::unique_ptr
std::make_unique
```

over manually owning raw pointers.

So this lesson has two goals:

```text
understand manual memory deeply

AND

learn why safer abstractions are preferred
```

---

# 1. Why Dynamic Memory Exists

Consider:

```cpp
int values[100];
```

The array extent is fixed in the source code.

But what if the amount of memory required is only known while the program is running?

Example:

```text
input:
n = 100000

program needs:
n integers
```

One historical/manual C++ solution is dynamic allocation:

```cpp
int* values =
    new int[n];
```

Later, the normal modern C++ solution for this use case is usually:

```cpp
vector<int> values(n);
```

but understanding `new[]` explains the underlying lifetime/ownership problems that containers solve.

---

# 2. Automatic vs Dynamic Lifetime

Automatic local:

```cpp
void demo() {
    int value = 10;
}
```

`value` is destroyed automatically when execution leaves its scope.

Dynamic object:

```cpp
int* ptr =
    new int(10);
```

The dynamically allocated object does not automatically die merely because the pointer variable goes out of scope.

Its lifetime normally continues until explicitly ended with:

```cpp
delete ptr;
```

unless ownership is handled by an RAII object.

---

# 3. Real-World Analogy

Think of an automatic local variable like a hotel room reservation that ends automatically when checkout occurs.

Dynamic allocation is closer to renting a storage unit:

```text
request storage
    |
receive access information
    |
use storage
    |
explicitly release rental
```

If you lose the access information without releasing the storage:

```text
the storage is still occupied
but you can no longer reach it
```

That resembles a memory leak.

---

# 4. new for One Object

Example:

```cpp
int* ptr =
    new int;
```

This dynamically allocates one `int`.

However, in this form the scalar `int` is default-initialized, which for a fundamental type means its value is indeterminate.

Do not read it before assigning a value.

Safer:

```cpp
int* ptr =
    new int(10);
```

or:

```cpp
int* ptr =
    new int{10};
```

Now the dynamic `int` contains:

```text
10
```

---

# 5. Value Initialization

This:

```cpp
int* ptr =
    new int{};
```

value-initializes the `int`.

Result:

```text
*ptr = 0
```

For fundamental types, brace initialization is often useful when you want a known initial value.

---

# 6. What new Returns

Expression:

```cpp
new int(10)
```

creates an `int` object with dynamic storage duration and returns a pointer to it.

Conceptual state:

```text
dynamic object
+-------------+
|     10      |
+-------------+
       ^
       |
      ptr
```

The pointer is how your program accesses the object.

---

# 7. Accessing Dynamic Object

Exactly like other valid pointers:

```cpp
cout << *ptr;
```

reads the dynamic object.

```cpp
*ptr = 25;
```

modifies it.

The pointer itself may still be an automatic local variable.

This means:

```text
pointer lifetime
!=
pointee lifetime
```

---

# 8. Pointer Object vs Dynamic Object

Example:

```cpp
void demo() {
    int* ptr =
        new int(10);
}
```

There are two relevant objects:

```text
ptr
    automatic pointer object

*ptr
    dynamically allocated int object
```

When `demo()` returns:

```text
ptr dies automatically
```

but unless the allocation was released first:

```text
dynamic int remains allocated
```

That is a leak.

---

# 9. delete

For one object allocated with scalar `new`:

```cpp
int* ptr =
    new int(10);
```

release it using:

```cpp
delete ptr;
```

This ends the dynamically allocated object's lifetime and releases its storage appropriately.

After:

```cpp
delete ptr;
```

the pointer variable itself still exists.

But it no longer points to a live allocated object.

It is dangling.

---

# 10. delete Does Not Reset the Pointer

Code:

```cpp
int* ptr =
    new int(10);

delete ptr;
```

Do not assume:

```text
ptr == nullptr
```

C++ does not automatically clear the pointer.

A useful local defensive step when the pointer remains in scope is:

```cpp
ptr = nullptr;
```

Now accidental null dereference is easier to detect than accidental dangling-pointer reuse.

But this only resets that one pointer.

Other aliases remain dangling.

---

# 11. Full Dry Run: Scalar Allocation

Code:

```cpp
int* ptr =
    new int(10);

*ptr = 20;

delete ptr;
ptr = nullptr;
```

Step 1:

```text
dynamic int created

dynamic value = 10
ptr -> dynamic int
```

Step 2:

```text
*ptr = 20
```

State:

```text
dynamic value = 20
ptr -> dynamic int
```

Step 3:

```text
delete ptr
```

State:

```text
dynamic int lifetime ended
storage released

ptr still contains old pointer value
but must not be dereferenced
```

Step 4:

```text
ptr = nullptr
```

Final:

```text
ptr designates no object
```

---

# 12. Memory Leak

Wrong:

```cpp
int* ptr =
    new int(10);

ptr = nullptr;
```

The allocated object was never deleted.

The program has lost the only pointer that could reach it.

Conceptually:

```text
before:

ptr ------> [dynamic int]


after:

ptr -> nullptr

             [dynamic int]
              still allocated
              unreachable
```

That is a memory leak.

---

# 13. Losing an Owning Pointer

Another leak:

```cpp
int* ptr =
    new int(10);

ptr =
    new int(20);
```

The pointer to the first allocation is overwritten.

State:

```text
first allocation:
10
unreachable -> leaked

ptr -> second allocation:
20
```

If a raw pointer owns an allocation, do not overwrite it until ownership has been transferred or the old allocation has been released.

---

# 14. Dangling Pointer

Example:

```cpp
int* ptr =
    new int(10);

delete ptr;
```

Now:

```text
ptr
```

is dangling.

Wrong:

```cpp
cout << *ptr;
```

This accesses an object whose lifetime has ended.

Undefined behavior.

---

# 15. Use-After-Free

Using a pointer after its dynamic object has been deleted is commonly called:

```text
use-after-free
```

Example:

```cpp
delete ptr;

*ptr = 50;
```

This is undefined behavior.

Use-after-free bugs are serious because the memory may have been reused for something else.

---

# 16. Double Delete

Wrong:

```cpp
delete ptr;
delete ptr;
```

Deleting the same allocation twice is undefined behavior.

A defensive local pattern:

```cpp
delete ptr;
ptr = nullptr;
```

Then:

```cpp
delete ptr;
```

is safe because deleting a null pointer has no effect.

But setting one alias to null does not fix other aliases.

---

# 17. delete nullptr

This is valid:

```cpp
int* ptr = nullptr;

delete ptr;
```

Nothing happens.

Likewise:

```cpp
delete[] ptr;
```

is harmless when `ptr` is null and the form is otherwise appropriate.

This can simplify cleanup logic.

---

# 18. Aliasing and delete

Consider:

```cpp
int* first =
    new int(10);

int* second =
    first;
```

Both point to the same allocation.

Then:

```cpp
delete first;
first = nullptr;
```

State:

```text
first = nullptr

second = old address
```

`second` is now dangling.

Do not dereference it.

This shows why ownership is harder than merely remembering to call `delete`.

---

# 19. Owning vs Non-Owning Pointer

Conceptually:

```text
owning pointer:
responsible for releasing resource

non-owning pointer:
merely observes/borrows resource
```

A raw pointer's type:

```cpp
int*
```

does not tell you which role it has.

That ambiguity is one reason modern C++ uses:

```text
unique_ptr
shared_ptr
weak_ptr
references
containers
```

to communicate ownership more clearly.

---

# 20. Dynamic Arrays

Runtime-sized manual array:

```cpp
int n = 5;

int* values =
    new int[n];
```

This allocates an array of `n` integers.

For fundamental `int`, the elements are not initialized by this form.

Safer zero initialization:

```cpp
int* values =
    new int[n]{};
```

Now the elements are value-initialized to zero.

---

# 21. Dynamic Array Access

Once allocation succeeds:

```cpp
values[i]
```

works just like indexed access through a pointer.

Example:

```cpp
for (int i = 0; i < n; ++i) {
    values[i] = i * 10;
}
```

State for `n = 5`:

```text
[0, 10, 20, 30, 40]
```

---

# 22. Dynamic Array Is Still Fixed After Allocation

Suppose:

```cpp
int* values =
    new int[5];
```

That allocation contains five elements.

You cannot resize that allocation in place by simply changing a variable:

```cpp
n = 10;
```

The allocated object remains an array of five elements.

To manually "resize," you would need to:

1. allocate another array
2. copy/move relevant elements
3. release the old array
4. update the owning pointer

This is exactly the kind of management `std::vector` handles for you.

---

# 23. delete[]

Dynamic array:

```cpp
int* values =
    new int[n];
```

must be released using:

```cpp
delete[] values;
```

not:

```cpp
delete values;
```

The forms must match.

---

# 24. Matching Rule

Use:

```text
new      <-> delete
new[]    <-> delete[]
```

Examples:

```cpp
int* scalar =
    new int(5);

delete scalar;
```

and:

```cpp
int* array =
    new int[5];

delete[] array;
```

Mismatching allocation/deallocation forms produces undefined behavior.

This is a classic interview question.

---

# 25. Dry Run: Dynamic Array

Code:

```cpp
int n = 3;

int* values =
    new int[n]{};

values[0] = 10;
values[1] = 20;
values[2] = 30;

delete[] values;
values = nullptr;
```

State after allocation:

```text
values -> [0, 0, 0]
```

After assignments:

```text
values -> [10, 20, 30]
```

After:

```cpp
delete[] values;
```

array lifetime ends.

After:

```cpp
values = nullptr;
```

the pointer no longer contains the stale allocation address.

---

# 26. Pointer Arithmetic Still Applies

A dynamically allocated array behaves as an array for valid pointer arithmetic.

Given:

```cpp
int* values =
    new int[n];
```

then within the allocation:

```cpp
values + i
```

points to element `i`.

And:

```cpp
*(values + i)
```

is equivalent to:

```cpp
values[i]
```

for valid `i`.

One-past:

```cpp
values + n
```

may be formed as a boundary but not dereferenced.

---

# 27. Runtime Size Advantage

Raw local standard array:

```cpp
int values[100];
```

has compile-time-known extent.

Dynamic allocation allows:

```cpp
int n;
cin >> n;

int* values =
    new int[n];
```

where `n` is determined at runtime.

However, modern C++ normally writes:

```cpp
vector<int> values(n);
```

because the vector manages cleanup and provides safer value/container semantics.

---

# 28. What if n Is Zero?

C++ permits:

```cpp
new int[0]
```

The result may be a non-null pointer value that must still be correctly passed to:

```cpp
delete[]
```

but there are zero elements to access.

Do not dereference/index it.

For beginner code, vectors make empty dynamic sequences substantially simpler.

---

# 29. Negative Array Size

Do not do:

```cpp
int n = -5;

new int[n];
```

The negative value must be converted to the allocation size representation and cannot represent a meaningful negative element count.

Array allocation size rules can result in allocation failure/error behavior.

Validate logical sizes before allocation.

---

# 30. Allocation Failure

Ordinary throwing `new` reports allocation failure by throwing:

```text
std::bad_alloc
```

Example:

```cpp
int* ptr =
    new int;
```

normally either:

```text
returns valid pointer
```

or:

```text
throws
```

It does not normally return `nullptr` on allocation failure.

Exception handling comes later.

---

# 31. nothrow new

C++ also supports:

```cpp
#include <new>

int* ptr =
    new (nothrow) int;
```

On allocation failure this form can return:

```cpp
nullptr
```

instead of throwing.

Normal modern C++ code usually relies on RAII and standard allocation behavior rather than manually checking every ordinary `new`.

You should know `nothrow` exists, but it is not the default pattern.

---

# 32. Why Manual new Can Leak During Exceptions

Consider conceptually:

```cpp
int* ptr =
    new int(10);

someFunctionThatThrows();

delete ptr;
```

If the middle function throws an exception:

```text
delete ptr
```

may never execute.

The allocation leaks.

RAII solves this by tying cleanup to an object's destructor.

You will study RAII and smart pointers later.

---

# 33. Resource Acquisition Is Initialization — Preview

RAII means roughly:

```text
resource lifetime
is tied to
an object's lifetime
```

Instead of:

```cpp
int* ptr = new int(10);

// remember cleanup manually

delete ptr;
```

later:

```cpp
auto ptr =
    make_unique<int>(10);
```

The smart pointer automatically releases its owned allocation when the smart pointer's lifetime ends.

We will learn this deeply in:

```text
01_C++__/30_SMART_POINTERS_AND_RAII/
```

---

# 34. Why Learn new/delete If Modern C++ Avoids Them?

Because you need to understand:

- what dynamic lifetime means
- how linked-list nodes are created
- what ownership means
- why memory leaks exist
- why dangling pointers exist
- why destructors matter
- what smart pointers automate
- how legacy code works
- how raw memory APIs behave

The goal is understanding, not encouraging unnecessary manual ownership.

---

# 35. Returning a Dynamically Allocated Pointer

Technically:

```cpp
int* createValue() {
    return new int(10);
}
```

can return a pointer to a live dynamic object.

Unlike returning the address of a local automatic object, the dynamic object's lifetime does not end when the function returns.

But this interface creates an ownership question:

```text
Who must delete it?
```

Caller:

```cpp
int* ptr =
    createValue();

delete ptr;
```

If the caller forgets:

```text
leak
```

This is why owning raw-pointer-return APIs are discouraged in modern C++.

---

# 36. Dynamic Object Lifetime vs Pointer Scope

Example:

```cpp
int* outer = nullptr;

{
    int* local =
        new int(42);

    outer = local;
}
```

After block:

```text
local pointer object is dead

dynamic int still alive

outer still points to dynamic int
```

This is valid until the dynamic object is deleted:

```cpp
delete outer;
outer = nullptr;
```

This contrasts with pointing to an automatic local.

---

# 37. Automatic Local vs Dynamic Object

Automatic:

```cpp
int* ptr = nullptr;

{
    int value = 42;
    ptr = &value;
}
```

After block:

```text
ptr dangling
```

Dynamic:

```cpp
int* ptr = nullptr;

{
    int* local =
        new int(42);

    ptr = local;
}
```

After block:

```text
ptr still points to live dynamic object
```

until:

```cpp
delete ptr;
```

This is a central lifetime distinction.

---

# 38. Dynamic Memory and Functions

Example:

```cpp
int* makeArray(int n) {
    return new int[n]{};
}
```

Caller:

```cpp
int* values =
    makeArray(5);

// use...

delete[] values;
```

This works mechanically but pushes cleanup responsibility onto callers.

Later alternatives:

```text
return vector<int>
```

or:

```text
return unique_ptr<int[]>
```

communicate ownership more safely.

---

# 39. Memory Leak in a Loop

Wrong:

```cpp
for (int i = 0; i < 1000; ++i) {
    int* ptr =
        new int(i);
}
```

Each loop iteration loses the pointer when the block ends.

The dynamic `int` does not automatically disappear.

Potentially:

```text
1000 leaked allocations
```

Correct manual version:

```cpp
for (int i = 0; i < 1000; ++i) {
    int* ptr =
        new int(i);

    // use ptr

    delete ptr;
}
```

Better modern design usually avoids allocating one scalar per loop iteration at all.

---

# 40. Repeated Allocation Cost

Dynamic allocation is generally much more expensive than ordinary stack-like local scalar creation.

Why?

An allocator may need to:

- find suitable memory
- maintain allocation metadata
- synchronize internally in some environments
- later release/recycle memory

Do not use:

```cpp
new
```

for every tiny temporary value.

Allocate dynamically only when lifetime/size/ownership requirements justify it.

---

# 41. Heap Fragmentation: High-Level Idea

Repeated allocations and deallocations of varying sizes can leave available memory divided into pieces.

This is broadly called:

```text
fragmentation
```

Allocator implementations work hard to manage it.

For DSA complexity analysis we usually do not model fragmentation directly, but understanding it explains why many small dynamic allocations can have poor constant factors.

Linked lists and trees often allocate nodes individually, while vectors use contiguous storage.

---

# 42. Dynamic Array Initialization Forms

Uninitialized fundamental values:

```cpp
int* a =
    new int[5];
```

Do not read elements before assigning them.

Zero/value-initialized:

```cpp
int* b =
    new int[5]{};
```

Result:

```text
0 0 0 0 0
```

Initializer list:

```cpp
int* c =
    new int[5]{
        1, 2, 3
    };
```

Result:

```text
1 2 3 0 0
```

---

# 43. Scalar Initialization Forms

Examples:

```cpp
int* a =
    new int;
```

indeterminate initial value for fundamental `int`.

```cpp
int* b =
    new int();
```

value-initialized:

```text
0
```

```cpp
int* c =
    new int{};
```

also:

```text
0
```

```cpp
int* d =
    new int(42);
```

value:

```text
42
```

```cpp
int* e =
    new int{42};
```

value:

```text
42
```

Prefer intentional initialization.

---

# 44. Dynamic Objects of Class Types — Preview

Later:

```cpp
Node* node =
    new Node(...);
```

does more than reserve bytes.

It also constructs a `Node` object.

Then:

```cpp
delete node;
```

runs its destructor before releasing storage.

This becomes important in OOP and linked data structures.

For arrays of class objects:

```cpp
delete[] objects;
```

destroys each element appropriately.

This is another reason matching `new[]` with `delete[]` matters.

---

# 45. delete Expression and Destruction

For a class object:

```cpp
delete ptr;
```

conceptually involves:

```text
run object's destructor
then release allocation storage
```

For:

```cpp
delete[] ptr;
```

the corresponding array elements are destroyed and the allocation released according to array-delete rules.

Destructors are studied in the OOP section.

---

# 46. Manual Dynamic 2D Array — Contiguous Option

Suppose runtime dimensions:

```text
rows
cols
```

One simple low-level representation is one flat allocation:

```cpp
int* matrix =
    new int[rows * cols]{};
```

Element:

```cpp
matrix[row * cols + col]
```

Conceptually:

```text
2D coordinates
      |
      v
1D contiguous offset
```

This representation has one allocation and one matching:

```cpp
delete[] matrix;
```

---

# 47. 2D Flattening Formula

For:

```text
rows = 2
cols = 3
```

matrix:

```text
a00 a01 a02
a10 a11 a12
```

flat storage:

```text
[a00, a01, a02, a10, a11, a12]
```

Index:

```text
row * cols + col
```

Examples:

```text
(0,0) -> 0*3+0 = 0
(0,2) -> 0*3+2 = 2
(1,0) -> 1*3+0 = 3
(1,2) -> 1*3+2 = 5
```

This is row-major indexing.

---

# 48. Overflow in Allocation Size

Be careful with:

```cpp
rows * cols
```

If both are `int`, multiplication can overflow before being converted to a larger allocation-size type.

For large dimensions, size arithmetic should use an appropriate unsigned size type and validate multiplication.

At our current level, use small controlled examples.

Later, constraints and overflow analysis become part of routine DSA design.

---

# 49. Dynamic 2D Array — Pointer-to-Pointer Style

Another textbook approach:

```cpp
int** matrix =
    new int*[rows];

for (int r = 0; r < rows; ++r) {
    matrix[r] =
        new int[cols]{};
}
```

Now each row is separately allocated.

Conceptually:

```text
matrix
 |
 +--> row0 allocation
 |
 +--> row1 allocation
 |
 +--> row2 allocation
```

This is not necessarily one contiguous matrix.

---

# 50. Correct Cleanup of Pointer-to-Pointer Matrix

You must delete every row:

```cpp
for (int r = 0; r < rows; ++r) {
    delete[] matrix[r];
}
```

Then delete the outer pointer array:

```cpp
delete[] matrix;
```

Cleanup order:

```text
row allocations first
outer pointer array second
```

Forgetting any row leaks memory.

---

# 51. Why Contiguous 2D Storage Is Often Better

Flat allocation:

```cpp
int* matrix =
    new int[rows * cols];
```

advantages include:

- one allocation
- one deallocation
- contiguous data
- usually better locality
- simpler ownership

Pointer-to-pointer style can support rows with different lengths, but ownership is more complex.

Later, `vector<vector<int>>` and flat `vector<int>` provide safer alternatives.

---

# 52. Ragged Arrays

With separately allocated rows, different rows can have different sizes.

Conceptually:

```text
row 0 -> 3 values
row 1 -> 5 values
row 2 -> 2 values
```

This is sometimes called:

```text
jagged
or
ragged
```

storage.

A built-in rectangular:

```cpp
int matrix[R][C]
```

has the same `C` for every row.

---

# 53. Shallow Copy Problem

Suppose:

```cpp
int* first =
    new int[3]{
        1, 2, 3
    };

int* second =
    first;
```

This does not copy the array.

It copies the pointer.

State:

```text
first  ----+
           |
           v
        [1 2 3]
           ^
           |
second ----+
```

Both pointers refer to the same allocation.

---

# 54. Double Delete From Shallow Ownership

If both pointers are mistakenly treated as owners:

```cpp
delete[] first;
delete[] second;
```

the second deletion attempts to release the same allocation again.

Undefined behavior.

This demonstrates a central ownership rule:

```text
copying a raw pointer
does not create a second independent allocation
```

---

# 55. Deep Copy

To make an independent dynamic array:

```cpp
int* second =
    new int[n];

for (int i = 0; i < n; ++i) {
    second[i] =
        first[i];
}
```

Now:

```text
first -> independent allocation
second -> independent allocation
```

Each needs its own matching:

```cpp
delete[]
```

This is a deep copy.

---

# 56. Shallow vs Deep Copy Analogy

Shallow pointer copy:

```text
two people receive copies of the same house address
```

There is still one house.

Deep copy:

```text
build a separate identical house
```

Now there are two independent houses.

This distinction becomes crucial when we study classes that own dynamic resources.

---

# 57. Rule of Three/Five Preview

If a class manually owns dynamic memory, it may need custom:

- destructor
- copy constructor
- copy assignment

and in modern C++ often:

- move constructor
- move assignment

This leads to:

```text
Rule of Three
Rule of Five
Rule of Zero
```

We will study these in OOP/move-semantics contexts.

For now, recognize that manual ownership complicates copying.

---

# 58. Memory Leak vs Dangling Pointer

These are opposite-style lifetime failures.

Leak:

```text
object still exists
but no usable owner can reach/release it
```

Dangling pointer:

```text
pointer still exists
but object no longer exists
```

Diagram:

```text
LEAK

pointer lost

        [live allocation]


DANGLING

ptr ----> [dead allocation/object]
```

Do not confuse them.

---

# 59. Double Free/Delete

Another category:

```text
object already released
then release attempted again
```

This is undefined behavior.

Typical cause:

```text
multiple raw pointers
all treated as owners
```

Clear ownership prevents the problem.

---

# 60. Memory Leak Is Not Immediately Visible

A leaked program may appear to run normally.

The operating system usually reclaims a process's memory after the entire process terminates.

That does not make leaks harmless.

Long-running programs can:

- steadily consume memory
- degrade performance
- eventually fail allocations

More importantly, leaking indicates broken resource ownership.

---

# 61. Tools for Detecting Memory Bugs

Common tools include:

```text
AddressSanitizer
LeakSanitizer
Valgrind
```

With GCC/Clang, a useful development command is:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic \
    -fsanitize=address,undefined \
    -g program.cpp -o program
```

Then run:

```bash
./program
```

Sanitizers can detect many:

- out-of-bounds accesses
- use-after-free bugs
- some memory leaks depending on setup/platform
- undefined behavior

Tool availability varies by compiler/platform.

---

# 62. AddressSanitizer Is Not a Proof of Correctness

If a sanitizer reports nothing, that does not prove the program has no bug.

It only means:

```text
the tested execution
did not trigger a problem that the enabled tool detected
```

You still need correct lifetime reasoning and tests.

---

# 63. Dynamic Memory Complexity

Allocation is often treated simplistically in DSA, but actual allocator costs are implementation-dependent.

For algorithmic reasoning:

```text
allocate n-element array
```

requires storage:

```text
O(n)
```

Initialization:

```cpp
new int[n]{}
```

must initialize `n` elements:

```text
O(n)
```

A raw uninitialized allocation can avoid that element initialization work for trivial types, though allocation itself is not usefully modeled as a universal O(1) hardware operation.

---

# 64. Dynamic Array Access Complexity

After successful allocation:

```cpp
values[i]
```

is:

```text
O(1)
```

Traversal:

```text
O(n)
```

Manual copy:

```text
O(n)
```

Flat matrix:

```text
matrix[r * cols + c]
```

access:

```text
O(1)
```

Full traversal:

```text
O(rows * cols)
```

---

# 65. Stack vs Heap Terminology

You will often hear:

```text
stack memory
heap memory
```

Typical implementations use a call stack for automatic locals and a heap/free store for dynamic allocations.

But C++ language semantics are better expressed as:

```text
automatic storage duration
dynamic storage duration
```

The standard does not require every implementation to map those concepts onto one exact hardware memory layout.

Use "stack/heap" as a useful implementation model, not as the full language definition.

---

# 66. Stack-Like Automatic Allocation Advantages

Automatic local storage normally has:

- automatic cleanup
- clear scope-based lifetime
- low management overhead
- no manual `delete`

Example:

```cpp
int value = 10;
```

If an object can naturally have automatic lifetime, that is often simpler than dynamic allocation.

Do not write:

```cpp
int* value =
    new int(10);
```

when:

```cpp
int value = 10;
```

does the job.

---

# 67. When Dynamic Lifetime Is Needed

Possible reasons include:

- runtime-sized storage
- object must outlive creating scope
- linked data structures
- polymorphic ownership
- resource lifetime determined dynamically
- object too large/inappropriate for automatic storage
- APIs that require dynamic ownership

Even then, modern C++ often uses a container or smart pointer instead of direct `new`.

---

# 68. Prefer vector for Runtime Arrays

Instead of:

```cpp
int* values =
    new int[n]{};

// use...

delete[] values;
```

modern C++ generally uses:

```cpp
vector<int> values(n);
```

Advantages:

- automatic cleanup
- `.size()`
- copy/move support
- resizing
- STL integration
- exception safety
- fewer ownership bugs

`vector` is studied deeply later.

---

# 69. Prefer string for Dynamic Character Data

Instead of manually allocating:

```cpp
char* text =
    new char[n];
```

for normal text handling, prefer:

```cpp
string text;
```

`std::string` manages memory and null-terminated interoperability for you.

Manual character buffers remain relevant for low-level interfaces.

---

# 70. Prefer unique_ptr for Exclusive Dynamic Ownership

Later:

```cpp
auto ptr =
    make_unique<int>(10);
```

communicates:

```text
this smart pointer uniquely owns this object
```

No manual:

```cpp
delete
```

is required.

When `ptr` leaves scope:

```text
resource automatically released
```

This is RAII.

---

# 71. shared_ptr Is Not a Replacement for Thinking

Later:

```cpp
shared_ptr<T>
```

supports shared ownership.

But shared ownership has:

- reference-count overhead
- possible cycles
- less obvious lifetime

Use it only when ownership really is shared.

Most dynamic ownership should be as simple as possible.

---

# 72. Dynamic Nodes Preview

A linked-list node might eventually be:

```cpp
struct Node {
    int value;
    Node* next;
};
```

Create:

```cpp
Node* node =
    new Node{10, nullptr};
```

Now its lifetime is independent of the function block that created the pointer.

This is why dynamic memory and pointers are prerequisites for linked lists.

Structures are your next topic, so this pattern will soon become concrete.

---

# 73. Tree Nodes Preview

Similarly:

```text
TreeNode
 |
 +-- value
 +-- left pointer
 +-- right pointer
```

Individual nodes may need lifetimes independent from one another.

Dynamic allocation can create such structures.

Later we will also discuss ownership strategies that avoid raw owning pointers.

---

# 74. Common Interview Mistakes

1. Using `new` when an automatic local would be simpler.

2. Forgetting `delete`.

3. Forgetting `delete[]`.

4. Matching `new[]` with `delete`.

5. Matching scalar `new` with `delete[]`.

6. Reading an uninitialized dynamically allocated fundamental value.

7. Reading uninitialized elements from:

```cpp
new int[n]
```

8. Dereferencing a pointer after `delete`.

9. Assuming `delete` automatically sets pointer to null.

10. Deleting the same allocation twice.

11. Losing the owning pointer before releasing memory.

12. Overwriting an owning pointer with another allocation.

13. Treating two copied raw pointers as two independent allocations.

14. Assuming setting one alias to `nullptr` fixes every alias.

15. Returning dynamically allocated memory without documenting ownership.

16. Returning pointer to a local automatic object and confusing it with dynamic allocation.

17. Forgetting all rows when manually freeing an `int**` matrix.

18. Deleting the outer `int**` array before freeing row allocations and then losing row pointers.

19. Assuming an `int**` matrix is contiguous.

20. Assuming runtime-sized raw arrays like `int a[n]` are standard C++17.

21. Ignoring multiplication overflow when computing allocation size.

22. Assuming ordinary `new` returns `nullptr` on failure.

23. Manually owning memory when `vector`, `string`, or `unique_ptr` would make ownership automatic.

24. Assuming pointer existence implies pointee lifetime.

25. Ignoring exception paths that skip manual cleanup.

---

# 75. Complexity Table

| Operation | Simplified Complexity |
|---|---:|
| Dereference allocated scalar | O(1) |
| Delete scalar | O(1) for trivial scalar model |
| Index dynamic array | O(1) |
| Traverse n dynamic elements | O(n) |
| Value-initialize n ints | O(n) |
| Copy n-element dynamic array | O(n) |
| Flat matrix access | O(1) |
| Flat R×C initialization/traversal | O(R*C) |
| Allocate R separate rows | O(R) allocation calls plus element work |
| Deep copy n elements | O(n) |
| Raw pointer copy | O(1), but does not copy pointee |

Actual allocator costs and class destruction costs depend on the implementation/type.

---

# 76. Practice Questions

1. GFG — Dynamic Memory Allocation in C++  
   https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

2. cppreference — new expression  
   https://en.cppreference.com/w/cpp/language/new

3. cppreference — delete expression  
   https://en.cppreference.com/w/cpp/language/delete

4. LeetCode 707 — Design Linked List  
   https://leetcode.com/problems/design-linked-list/

5. LeetCode 206 — Reverse Linked List  
   https://leetcode.com/problems/reverse-linked-list/

The linked-list problems belong to a later phase. Bookmark them; dynamic node lifetime will make their implementations much easier to understand later.

---

# 77. Final Mental Model

Manual scalar ownership:

```text
new
 |
 v
dynamic object
 |
 v
pointer owns/accesses object
 |
use
 |
 v
delete
 |
 v
object lifetime ends
 |
pointer should no longer be dereferenced
```

Manual array ownership:

```text
new[]
 |
 v
dynamic array
 |
use elements
 |
 v
delete[]
```

And remember these three failure patterns:

```text
LEAK
object alive, owner lost

DANGLING
pointer alive, object dead

DOUBLE DELETE
same allocation released twice
```

Modern C++ attempts to make these states harder to create through:

```text
RAII
containers
smart pointers
value semantics
```

Learn manual memory so you understand the machinery. Prefer automatic ownership abstractions when writing real modern C++.

---

# What's Next

`01_C++__/17_STRUCTURES_UNIONS_ENUMS/`

Next we learn how to group related data into custom types using `struct`, how member access works, how structs interact with pointers and functions, `enum` vs `enum class`, unions and their active-member limitations, and how these features prepare us for classes and object-oriented programming.
