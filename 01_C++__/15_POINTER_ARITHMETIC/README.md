# Pointer Arithmetic in C++

Path:

`DSA_JOURNEY/01_C++__/15_POINTER_ARITHMETIC/`

## Prerequisites

You should already understand:

- raw arrays
- contiguous storage
- pointer declarations
- address-of `&`
- dereference `*`
- `nullptr`
- array-to-pointer conversion
- pointer-to-array syntax
- object lifetime

This folder answers:

```text
What does ptr + 1 mean?
Why does it move by one element instead of one byte?
Why is a one-past-the-end pointer legal to form but illegal to dereference?
How are a[i] and *(a + i) related?
When can two pointers be subtracted?
How does pointer arithmetic work for 2D arrays?
```

Pointer arithmetic is powerful, but it is only valid within tightly defined array boundaries.

---

# 1. Pointer Arithmetic Is About Arrays

Consider:

```cpp
int values[5] = {
    10, 20, 30, 40, 50
};

int* ptr = values;
```

`ptr` points to:

```text
values[0]
```

Now:

```cpp
ptr + 1
```

points to:

```text
values[1]
```

and:

```cpp
ptr + 2
```

points to:

```text
values[2]
```

Pointer arithmetic moves in units of the pointed-to type.

---

# 2. Real-World Analogy

Imagine numbered houses along a street.

A pointer is an address to one house.

If you say:

```text
next house
```

you move to the next complete house, not one centimeter forward.

Likewise:

```cpp
ptr + 1
```

means:

```text
move to the next element
```

not:

```text
add one raw byte
```

C++ scales pointer arithmetic according to the pointed-to type.

---

# 3. Conceptual Addresses

Suppose an implementation uses:

```text
sizeof(int) = 4
```

and an array begins conceptually at address 1000.

Then:

```text
&values[0] -> 1000
&values[1] -> 1004
&values[2] -> 1008
&values[3] -> 1012
&values[4] -> 1016
```

Therefore:

```cpp
ptr + 1
```

might numerically advance four bytes on such a system.

But do not manually multiply by `sizeof(int)`.

C++ pointer arithmetic already performs element scaling.

---

# 4. Important: Do Not Depend on Numeric Addresses

Real addresses are implementation/runtime dependent.

When dry-running, prefer symbolic positions:

```text
BEGIN + 0 elements
BEGIN + 1 element
BEGIN + 2 elements
```

The language's pointer arithmetic rules are expressed in terms of objects/elements, not assumptions about a specific hardware address representation.

---

# 5. Array-to-Pointer Conversion

Given:

```cpp
int values[5];
```

in many expressions:

```cpp
values
```

converts to:

```cpp
&values[0]
```

Therefore:

```cpp
int* ptr = values;
```

is equivalent in effect to:

```cpp
int* ptr = &values[0];
```

for initializing `ptr`.

Remember:

```text
array object != pointer object
```

The array merely converts to a pointer in many expression contexts.

---

# 6. Pointer Addition

Given:

```cpp
int* ptr = values;
```

Then:

```cpp
ptr + 0 -> &values[0]
ptr + 1 -> &values[1]
ptr + 2 -> &values[2]
...
```

Dereference:

```cpp
*(ptr + 2)
```

gives:

```text
values[2]
```

---

# 7. Indexing Equivalence

A crucial identity:

```cpp
values[i]
```

is defined in terms of pointer arithmetic as:

```cpp
*(values + i)
```

Likewise, with:

```cpp
int* ptr = values;
```

these access the same element:

```cpp
ptr[i]
*(ptr + i)
```

Example:

```text
values[2]
ptr[2]
*(values + 2)
*(ptr + 2)
```

all designate the third element in this setup.

---

# 8. Full Dry Run

Array:

```text
[10, 20, 30, 40]
```

State:

```text
ptr = &values[0]
```

Evaluate:

```cpp
*ptr
```

Result:

```text
10
```

Evaluate:

```cpp
*(ptr + 1)
```

Result:

```text
20
```

Evaluate:

```cpp
*(ptr + 3)
```

Result:

```text
40
```

No array elements were moved.

Only the pointer expression identifies different positions.

---

# 9. Incrementing a Pointer

Given:

```cpp
int* ptr = values;
```

execute:

```cpp
++ptr;
```

Now:

```text
ptr -> values[1]
```

Again:

```cpp
++ptr;
```

Now:

```text
ptr -> values[2]
```

The pointer object's stored address changes.

The array itself does not change.

---

# 10. Pointer Increment vs Pointed Value Increment

These are different:

```cpp
++ptr;
```

means:

```text
move pointer to next element
```

Whereas:

```cpp
++(*ptr);
```

means:

```text
increment the pointed-to integer
```

This distinction is essential.

---

# 11. Dry Run: ++ptr vs ++(*ptr)

Array:

```text
[10, 20, 30]
```

Start:

```text
ptr -> values[0]
```

Execute:

```cpp
++(*ptr);
```

State:

```text
array = [11, 20, 30]
ptr -> values[0]
```

Execute:

```cpp
++ptr;
```

State:

```text
array = [11, 20, 30]
ptr -> values[1]
```

Execute:

```cpp
++(*ptr);
```

Final:

```text
array = [11, 21, 30]
ptr -> values[1]
```

---

# 12. Postfix Trap: *ptr++

Expression:

```cpp
*ptr++
```

is parsed as:

```cpp
*(ptr++)
```

because postfix `++` has higher precedence than unary `*`.

Conceptually:

1. dereference the old pointer position for the expression value
2. increment the pointer

It does not mean:

```cpp
(*ptr)++
```

The latter increments the pointed value.

Use parentheses when clarity matters.

---

# 13. Three Similar Expressions

Given valid `ptr`:

```cpp
*ptr++
```

means approximately:

```text
use current pointed value, then advance pointer
```

```cpp
(*ptr)++
```

means:

```text
increment pointed value using postfix semantics
pointer stays
```

```cpp
*++ptr
```

means:

```text
advance pointer first, then dereference
```

These are common interview expressions, but production/DSA code should prioritize readability.

---

# 14. Pointer Decrement

If:

```cpp
ptr = &values[3];
```

then:

```cpp
--ptr;
```

produces:

```text
ptr = &values[2]
```

provided the movement stays within the permitted array range.

Pointer decrement is common in reverse traversal and two-pointer algorithms.

---

# 15. One-Past-the-End Pointer

For:

```cpp
int values[5];
```

C++ permits forming:

```cpp
values + 5
```

This is a pointer one past the final element.

Conceptually:

```text
values + 0 -> element 0
values + 1 -> element 1
values + 2 -> element 2
values + 3 -> element 3
values + 4 -> element 4
values + 5 -> one-past-end
```

The final pointer is useful as a boundary marker.

---

# 16. One-Past Pointer Cannot Be Dereferenced

Allowed:

```cpp
int* end = values + 5;
```

Allowed to compare/use as boundary:

```cpp
ptr != end
```

Not allowed:

```cpp
*end
```

There is no array element at that location.

This is one of the most important pointer rules.

---

# 17. Why One-Past Exists

It enables half-open ranges:

```text
[begin, end)
```

where:

```text
begin -> first element
end   -> one past last element
```

Then traversal:

```cpp
for (int* ptr = begin;
     ptr != end;
     ++ptr) {

    // use *ptr
}
```

This is conceptually the same range model used throughout the STL.

---

# 18. Half-Open Pointer Range

Array:

```text
[10, 20, 30]
```

Pointers:

```text
begin -> 10
end   -> one past 30
```

Traversal state:

```text
ptr = begin
*ptr = 10

ptr++
*ptr = 20

ptr++
*ptr = 30

ptr++
ptr == end
stop
```

The end pointer is never dereferenced.

---

# 19. Going Beyond One-Past

For an array of five elements:

```cpp
values + 5
```

may be formed as the one-past pointer.

But performing pointer arithmetic to produce positions outside the array's permitted range is not generally valid.

Do not form/use:

```cpp
values + 6
```

as though it were another legitimate array position.

C++ pointer arithmetic is not unrestricted integer arithmetic on memory addresses.

---

# 20. Pointer Arithmetic Rules

For practical beginner reasoning, arithmetic is valid when pointers stay within:

```text
the same array object
or
its one-past-the-end position
```

An ordinary non-array object is treated similarly to an array of one element for certain pointer-arithmetic rules, but pointer arithmetic is primarily useful with actual arrays.

Do not walk through arbitrary memory.

---

# 21. Pointer Subtraction

Suppose:

```cpp
int values[5];

int* first = &values[1];
int* second = &values[4];
```

Then:

```cpp
second - first
```

gives the distance in elements:

```text
3
```

not the distance in raw bytes.

---

# 22. ptrdiff_t

Pointer subtraction produces a signed integer type:

```cpp
std::ptrdiff_t
```

available through headers such as:

```cpp
#include <cstddef>
```

Example:

```cpp
ptrdiff_t distance =
    second - first;
```

The result describes how many array elements separate the pointers.

---

# 23. Pointer Subtraction Requirement

Subtract pointers only when they refer into the same array object (or its permitted one-past relationship) according to the language rules.

Wrong conceptual idea:

```cpp
int a;
int b;

&b - &a
```

Do not assume unrelated local objects can be meaningfully subtracted as array positions.

Even if their printed addresses appear close, they are not elements of one array.

---

# 24. Pointer Comparison

Equality:

```cpp
p == q
p != q
```

can ask whether pointers represent the same pointer value.

Relational pointer comparisons such as:

```cpp
p < q
```

are meaningful for positions within the same array/range according to C++ rules.

For unrelated objects, built-in relational pointer comparisons are not a portable way to establish a total memory ordering.

For DSA pointer iteration:

```cpp
ptr < end
```

can be fine when both belong to the same array range.

Often:

```cpp
ptr != end
```

is simpler for sequential traversal.

---

# 25. Pointer-Based Array Traversal

Index form:

```cpp
for (int i = 0; i < n; ++i) {
    cout << values[i];
}
```

Pointer form:

```cpp
for (int* ptr = values;
     ptr != values + n;
     ++ptr) {

    cout << *ptr;
}
```

Both traverse all elements.

Complexity:

```text
O(n)
```

Neither changes the asymptotic complexity.

---

# 26. Array Indexing vs Pointer Traversal

Index:

```cpp
values[i]
```

can be easier when you need the index itself.

Pointer:

```cpp
*ptr
```

can be natural for iterator-style ranges.

Modern C++ often uses iterators/range-based loops rather than manually using raw pointer arithmetic.

But understanding raw pointers explains how contiguous iterators work conceptually.

---

# 27. Sum Using Pointers

```cpp
long long sum = 0;

for (const int* ptr = values;
     ptr != values + n;
     ++ptr) {

    sum += *ptr;
}
```

For:

```text
[2, 4, 6]
```

dry run:

```text
ptr -> 2
sum = 2

ptr -> 4
sum = 6

ptr -> 6
sum = 12

ptr -> one-past
stop
```

---

# 28. const Pointer Traversal

For read-only traversal:

```cpp
const int* ptr = values;
```

This means:

```text
pointer can move
pointed integers cannot be modified through ptr
```

That is ideal for read-only array scanning.

---

# 29. Modifying Through Moving Pointer

For mutable traversal:

```cpp
for (int* ptr = values;
     ptr != values + n;
     ++ptr) {

    *ptr *= 2;
}
```

Input:

```text
[1, 2, 3]
```

Result:

```text
[2, 4, 6]
```

Pointer movement and pointed-value modification are independent operations.

---

# 30. Reverse Traversal With Pointers

A safe half-open approach:

```cpp
const int* begin = values;
const int* ptr = values + n;

while (ptr != begin) {
    --ptr;
    cout << *ptr;
}
```

Why decrement before dereferencing?

Initially:

```text
ptr = one-past-end
```

which cannot be dereferenced.

First move back to the final real element.

---

# 31. Reverse Traversal Dry Run

Array:

```text
[10, 20, 30]
```

Initial:

```text
begin -> 10
ptr -> one-past 30
```

Iteration:

```text
--ptr -> 30
print 30
```

Next:

```text
--ptr -> 20
print 20
```

Next:

```text
--ptr -> 10
print 10
```

Now:

```text
ptr == begin
```

Loop condition fails before another decrement.

Output:

```text
30 20 10
```

---

# 32. Empty Range

Suppose:

```text
n = 0
```

Then:

```cpp
begin = values;
end = values + 0;
```

So:

```text
begin == end
```

A half-open loop:

```cpp
while (ptr != end)
```

naturally performs zero iterations.

This is one reason half-open ranges are elegant.

Note that an actual raw zero-length array is not standard C++, so in real raw-array code you typically pair a valid pointer/range representation with a logical length; standard containers handle empty storage more naturally.

---

# 33. Arrays of Different Element Types

Pointer arithmetic automatically scales by pointed element type.

Conceptually:

```cpp
int* intPtr;
double* doublePtr;
char* charPtr;
```

`intPtr + 1` moves to the next `int`.

`doublePtr + 1` moves to the next `double`.

`charPtr + 1` moves to the next `char`.

You do not write:

```cpp
ptr + sizeof(type)
```

for ordinary element movement.

---

# 34. Why char* Looks Byte-Oriented

C++ defines:

```text
sizeof(char) == 1
```

where one `char` occupies one C++ byte.

Therefore:

```cpp
charPtr + 1
```

moves by one byte in the C++ object representation sense.

This is why character/byte-oriented pointers often appear in low-level memory code.

But arbitrary object-representation manipulation has additional type and aliasing rules that are beyond this beginner lesson.

---

# 35. void* Does Not Support Standard Pointer Arithmetic

Given:

```cpp
void* ptr;
```

standard C++ does not permit:

```cpp
ptr + 1
```

because `void` has no size.

Some compilers may provide non-standard extensions.

Do not rely on them.

Convert to an appropriate typed pointer when low-level code legitimately requires it.

---

# 36. nullptr Arithmetic Is Invalid

Do not perform:

```cpp
int* ptr = nullptr;

ptr + 1;
```

Pointer arithmetic requires a valid array/object relationship.

`nullptr` does not point into an array.

Null is useful as:

```text
no object
```

not as the start of an imaginary memory range.

---

# 37. Integer + Pointer

C++ allows:

```cpp
ptr + i
```

and:

```cpp
i + ptr
```

for valid array positions.

So:

```cpp
2 + ptr
```

can identify the same position as:

```cpp
ptr + 2
```

This leads to a strange identity:

```cpp
i[ptr]
```

is technically defined through indexing rules similarly to:

```cpp
ptr[i]
```

because indexing is based on:

```cpp
*(a + b)
```

But never write reversed indexing in normal code.

It is a language curiosity, not good style.

---

# 38. a[i] Means *(a + i)

This is one of C/C++'s central array identities.

Given:

```cpp
int values[3] = {
    10, 20, 30
};
```

then:

```cpp
values[1]
```

is equivalent to:

```cpp
*(values + 1)
```

The subscript operator fundamentally combines pointer arithmetic and dereference semantics.

---

# 39. Pointer Arithmetic Does Not Modify Array

Given:

```cpp
int* ptr = values;

++ptr;
```

only the pointer changes.

State:

```text
values:
[10, 20, 30]

ptr:
now points to 20
```

The first element still exists and remains unchanged.

If you need the original beginning later, preserve it:

```cpp
int* begin = values;
int* ptr = begin;
```

---

# 40. Losing the Beginning Pointer

Example:

```cpp
int* ptr = values;

while (ptr != values + n) {
    ++ptr;
}
```

At the end:

```text
ptr = one-past-end
```

You cannot dereference it.

The array still exists, and its beginning is still available as:

```cpp
values
```

For dynamically allocated arrays later, preserving the original allocation pointer becomes even more important because deallocation must use the correct pointer.

---

# 41. Pointer Difference as Length

Given half-open range:

```cpp
int* begin = values;
int* end = values + n;
```

Then:

```cpp
end - begin
```

equals:

```text
n
```

when representable in `ptrdiff_t`.

This is conceptually how iterator ranges often determine distances.

---

# 42. Pointer Midpoint Concept

For:

```cpp
int* begin = values;
int* end = values + n;
```

you might identify a midpoint:

```cpp
int* middle =
    begin + (end - begin) / 2;
```

This mirrors binary-search reasoning.

The subtraction first computes an element distance.

Then half that distance is added to the beginning.

This idea becomes very important in binary search.

---

# 43. Why Avoid begin + end

Pointers cannot be added together:

```cpp
begin + end
```

is invalid.

A pointer can be:

```text
pointer + integer offset
```

not:

```text
pointer + pointer
```

To calculate a midpoint:

```text
distance = end - begin
middle = begin + distance/2
```

---

# 44. Two Pointers Into One Array

Example:

```cpp
int values[5] = {
    1, 2, 3, 4, 5
};

int* left = values;
int* right = values + 4;
```

State:

```text
left  -> 1
right -> 5
```

You can move:

```cpp
++left;
--right;
```

toward the center.

This is the raw-pointer form of the two-pointer technique.

Later we will normally use integer indexes for many interview problems because they are easy to reason about.

---

# 45. Reverse With Two Pointers

```cpp
int* left = values;
int* right = values + n - 1;

while (left < right) {
    int temp = *left;
    *left = *right;
    *right = temp;

    ++left;
    --right;
}
```

This requires:

```text
n > 0
```

before forming:

```cpp
values + n - 1
```

For empty logical ranges, prefer a half-open technique that avoids constructing a before-begin position.

---

# 46. Empty-Array Edge Case

Dangerous generic pattern:

```cpp
int* right = values + n - 1;
```

when:

```text
n = 0
```

The mathematical expression suggests:

```text
values - 1
```

which is outside the permitted range.

Even forming such a pointer is not valid.

Robust pointer algorithms must consider empty ranges before performing offset arithmetic.

---

# 47. 2D Array Pointer Arithmetic

Given:

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

`matrix` converts in many expressions to:

```text
pointer to array of 3 int
```

Type:

```cpp
int (*)[3]
```

Therefore:

```cpp
matrix + 1
```

moves by one entire row.

It points to:

```text
matrix[1]
```

---

# 48. Real-World Analogy for 2D Pointer Movement

Imagine shelves.

Each row is one complete shelf containing three boxes:

```text
row 0: [1][2][3]
row 1: [4][5][6]
```

A pointer-to-row moves in shelf-sized steps.

```cpp
matrix + 1
```

means:

```text
next row
```

not:

```text
next individual int
```

because the pointee type is:

```text
array of 3 int
```

---

# 49. matrix[row] Meaning

Given:

```cpp
matrix[row][col]
```

using indexing identities:

```cpp
matrix[row]
```

is related to:

```cpp
*(matrix + row)
```

That yields the row array.

Then the row expression typically converts to a pointer to its first `int` for the second indexing operation.

Conceptually:

```cpp
matrix[row][col]
```

corresponds to:

```cpp
*(*(matrix + row) + col)
```

This is a key multidimensional-array identity.

---

# 50. 2D Dry Run

Matrix:

```text
1 2 3
4 5 6
```

Expression:

```cpp
*(*(matrix + 1) + 2)
```

Step 1:

```text
matrix + 1
-> pointer to row 1
```

Step 2:

```text
*(matrix + 1)
-> row 1 array
-> [4,5,6]
```

In the next arithmetic expression it decays to the row's first-element pointer.

Step 3:

```text
row pointer + 2
-> address of 6
```

Step 4:

```text
dereference
-> 6
```

Same as:

```cpp
matrix[1][2]
```

---

# 51. Pointer to Whole Array

Given:

```cpp
int values[4] = {
    10, 20, 30, 40
};

int (*p)[4] =
    &values;
```

`p` points to the entire array.

Then:

```cpp
(*p)[2]
```

is:

```text
30
```

What would:

```cpp
p + 1
```

mean?

It points one whole array-of-4-int object past `values`.

That is one-past the whole array.

Do not dereference that one-past pointer.

---

# 52. Pointer-to-Array Scaling

This demonstrates the general rule:

```text
pointer arithmetic scales according to pointee type
```

For:

```cpp
int* p
```

one step means:

```text
one int
```

For:

```cpp
int (*p)[4]
```

one step means:

```text
one array of 4 int
```

This is why type information is essential to pointer arithmetic.

---

# 53. Array of Pointers

Given:

```cpp
int a = 10;
int b = 20;
int c = 30;

int* pointers[3] = {
    &a, &b, &c
};
```

Here:

```text
pointers
```

is an array whose elements are `int*`.

Index:

```cpp
pointers[1]
```

is a pointer to `b`.

Dereference:

```cpp
*pointers[1]
```

is:

```text
20
```

This is not a 2D integer array.

---

# 54. Array of Pointers vs 2D Array

2D array:

```cpp
int matrix[2][3];
```

is one contiguous array-of-arrays object.

Array of pointers:

```cpp
int* rows[2];
```

contains two pointer objects.

Each pointer could point somewhere completely different.

They have very different memory layouts and ownership implications.

This becomes important in dynamic 2D allocation.

---

# 55. C-String Pointer Traversal

Given:

```cpp
const char* text =
    "hello";
```

we can traverse until null terminator:

```cpp
const char* ptr = text;

while (*ptr != '\0') {
    cout << *ptr;
    ++ptr;
}
```

State:

```text
h -> e -> l -> l -> o -> '\0'
```

At `'\0'`, stop.

Do not continue blindly past the terminator.

---

# 56. C-String Length With Pointers

```cpp
int length = 0;

const char* ptr = text;

while (*ptr != '\0') {
    ++length;
    ++ptr;
}
```

For:

```text
"DSA"
```

dry run:

```text
D -> length 1
S -> length 2
A -> length 3
\0 -> stop
```

Result:

```text
3
```

Complexity:

```text
O(n)
```

---

# 57. Pointer Subtraction for C-String Length

Another educational pattern:

```cpp
const char* begin = text;
const char* end = text;

while (*end != '\0') {
    ++end;
}

ptrdiff_t length =
    end - begin;
```

Because both pointers are within the same character array/string literal object:

```text
end - begin
```

gives the number of characters before the terminator.

---

# 58. const char* Arithmetic

For:

```cpp
const char* ptr
```

the pointer itself can move:

```cpp
++ptr;
```

while:

```cpp
*ptr = 'X';
```

is forbidden because the pointed characters are const through that pointer.

Constness of the pointee does not prevent pointer arithmetic.

---

# 59. Iterator Preview

STL iterators often act conceptually like generalized pointers.

For a contiguous container, an iterator may support:

```text
++it
--it
it + n
it - n
it2 - it1
*it
```

depending on iterator category.

Raw pointers themselves can serve as random-access iterators over arrays.

Understanding pointer arithmetic therefore helps later STL learning.

---

# 60. Pointer Arithmetic and Complexity

These are O(1) operations in the standard DSA model:

```text
ptr + k
ptr - k
ptr2 - ptr1
++ptr
--ptr
*ptr
```

That does not mean traversing `n` elements is O(1).

A loop performing `++ptr` `n` times is:

```text
O(n)
```

Constant-time movement per step multiplied by `n` steps is linear.

---

# 61. Pointer Arithmetic vs Integer Arithmetic

Pointers are not ordinary integers.

You cannot portably:

- multiply two pointers
- divide pointers
- add two pointers
- perform `%` on pointers
- use arbitrary numeric address calculations

Valid common operations are intentionally limited:

```text
pointer +/- integer
pointer - pointer (same array/range)
pointer comparisons under relevant rules
dereference
```

This protects the language's object model.

---

# 62. Do Not Cast Pointers to Integers for Normal Traversal

C++ provides integer types such as:

```cpp
std::uintptr_t
```

on implementations that support them, for certain pointer/integer representation uses.

But ordinary array traversal should use typed pointer arithmetic.

Do not do:

```text
cast address to integer
add sizeof(T)
cast back
```

when:

```cpp
ptr + 1
```

already expresses the correct operation safely within an array.

---

# 63. Provenance/Object-Model Intuition

Modern C++ pointer validity is about more than numeric address bits.

A pointer is associated with objects and permitted ranges under language rules.

Two numerically plausible addresses do not automatically make arbitrary pointer arithmetic or dereferencing legal.

For DSA, follow this practical rule:

```text
Only perform pointer arithmetic within the array/range
the pointer legitimately refers to.
```

That avoids the advanced object-model pitfalls.

---

# 64. Common Interview Mistakes

1. Thinking `ptr + 1` always means one byte.

2. Manually adding `sizeof(T)` to a typed pointer.

3. Dereferencing the one-past-end pointer.

4. Moving beyond one-past the array.

5. Subtracting pointers to unrelated objects.

6. Comparing unrelated pointers with `<` as though memory has a portable total order.

7. Performing arithmetic on `nullptr`.

8. Using pointer arithmetic on `void*` in standard C++.

9. Confusing:

```cpp
++ptr
```

with:

```cpp
++(*ptr)
```

10. Confusing:

```cpp
*ptr++
```

with:

```cpp
(*ptr)++
```

11. Forgetting postfix operator precedence.

12. Losing track of the original beginning pointer.

13. Forming:

```cpp
values + n - 1
```

without handling `n == 0`.

14. Assuming an array is a pointer.

15. Assuming `sizeof(pointer)` is the array size.

16. Adding two pointers together.

17. Thinking pointer subtraction returns byte distance.

18. Using the wrong `ptrdiff_t`/index type carelessly.

19. Confusing pointer-to-array with array-of-pointers.

20. Forgetting that `matrix + 1` advances one complete row.

21. Walking past a C-string terminator.

22. Treating pointer movement as automatically O(n); one valid arithmetic operation is O(1), traversal is O(n).

23. Assuming pointer syntax is inherently faster than indexed array syntax.

Modern optimizers typically compile equivalent clear forms very effectively.

---

# 65. Complexity Table

| Operation | Time | Extra Space |
|---|---:|---:|
| `ptr + k` | O(1) | O(1) |
| `ptr - k` | O(1) | O(1) |
| `++ptr` / `--ptr` | O(1) | O(1) |
| Valid dereference `*ptr` | O(1) | O(1) |
| Same-array pointer subtraction | O(1) | O(1) |
| Pointer equality comparison | O(1) | O(1) |
| Traverse n elements | O(n) | O(1) |
| Reverse traversal | O(n) | O(1) |
| Sum via pointers | O(n) | O(1) |
| C-string scan | O(n) | O(1) |
| R × C matrix traversal | O(R*C) | O(1) |

---

# 66. Practice Questions

1. GFG — Pointer Arithmetic  
   https://www.geeksforgeeks.org/cpp-pointer-arithmetic/

2. GFG — Pointers and Arrays  
   https://www.geeksforgeeks.org/cpp-pointers-and-arrays/

3. HackerRank — Pointer  
   https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

4. LeetCode 344 — Reverse String  
   https://leetcode.com/problems/reverse-string/

5. LeetCode 283 — Move Zeroes  
   https://leetcode.com/problems/move-zeroes/

The LeetCode problems commonly use vectors/indexes. Their movement patterns are closely related to pointer/index traversal and can be revisited after STL.

---

# 67. Final Mental Model

For:

```cpp
int a[4] = {
    10, 20, 30, 40
};
```

think:

```text
a
|
v
+------+------+------+------+
| 10   | 20   | 30   | 40   |
+------+------+------+------+
  ^      ^      ^      ^
 a+0    a+1    a+2    a+3

a+4
 |
 +--> legal one-past boundary
      NOT an element
```

And:

```text
a[i]
==
*(a + i)
```

The key safety rule:

```text
Pointer arithmetic belongs to an array/range.
Stay within that array or its one-past boundary,
and never dereference the one-past pointer.
```

---

# What's Next

`01_C++__/16_DYNAMIC_MEMORY/`

Next we study runtime allocation, `new`, `delete`, `new[]`, `delete[]`, memory leaks, dangling pointers, double deletion, ownership, dynamic arrays, exception safety at a beginner level, and why RAII/standard containers are preferred over manual memory management in modern C++.
