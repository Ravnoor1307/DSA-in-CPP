# C++ Arrays — 1D and 2D

Path:

`DSA_JOURNEY/01_C++__/12_ARRAYS_1D_2D/`

## Prerequisites

You should already understand:

- variables and data types
- loops
- conditionals
- functions
- references and pointer basics
- scope and lifetime
- `sizeof`

This folder introduces raw built-in C++ arrays.

Arrays are foundational because most data structures ultimately rely on organizing multiple values rather than one isolated scalar.

Later we will study:

```text
std::array
std::vector
dynamic arrays
prefix sums
two pointers
sliding windows
binary search
sorting
matrices
```

First we need the underlying array model.

---

# 1. Why Arrays Exist

Suppose five students have scores:

```text
85
92
76
88
95
```

Without an array:

```cpp
int score1 = 85;
int score2 = 92;
int score3 = 76;
int score4 = 88;
int score5 = 95;
```

This does not scale.

With an array:

```cpp
int scores[5] = {
    85, 92, 76, 88, 95
};
```

Now the five values belong to one indexed collection.

---

# 2. Real-World Analogy

Imagine a row of numbered lockers:

```text
index
  0       1       2       3       4
+-----+ +-----+ +-----+ +-----+ +-----+
| 85  | | 92  | | 76  | | 88  | | 95  |
+-----+ +-----+ +-----+ +-----+ +-----+
```

The array name identifies the collection.

The index selects one element.

```cpp
scores[0]
```

means:

```text
element at index 0
```

---

# 3. Basic Array Declaration

Syntax:

```cpp
type name[size];
```

Example:

```cpp
int numbers[5];
```

This creates an array containing five `int` elements.

Valid indexes are:

```text
0
1
2
3
4
```

Not:

```text
5
```

---

# 4. Why Indexing Starts at Zero

For an array:

```cpp
int numbers[5];
```

the first element is:

```cpp
numbers[0]
```

Conceptually, index `0` means:

```text
zero element-sized offsets from the beginning
```

index `1` means:

```text
one element-sized offset from the beginning
```

and so on.

Pointer arithmetic will make this model more explicit later.

---

# 5. Array Initialization

Fully initialized:

```cpp
int values[5] = {
    10, 20, 30, 40, 50
};
```

State:

```text
index 0 -> 10
index 1 -> 20
index 2 -> 30
index 3 -> 40
index 4 -> 50
```

---

# 6. Size Deduction

The compiler can deduce the number of elements from an initializer:

```cpp
int values[] = {
    10, 20, 30
};
```

The array has:

```text
3 elements
```

Equivalent conceptually to:

```cpp
int values[3] = {
    10, 20, 30
};
```

---

# 7. Partial Initialization

Example:

```cpp
int values[5] = {
    10, 20
};
```

The explicitly supplied values initialize the first elements.

Remaining elements are zero-initialized.

State:

```text
10 20 0 0 0
```

---

# 8. Zero Initialization

A useful pattern:

```cpp
int values[5] = {};
```

or:

```cpp
int values[5]{};
```

All elements become zero.

State:

```text
0 0 0 0 0
```

---

# 9. Uninitialized Local Array

Consider:

```cpp
int values[5];
```

inside a normal function.

Its fundamental-type elements are not automatically initialized to zero.

Reading them before assigning values is invalid/undefined behavior due to indeterminate values.

Wrong:

```cpp
int values[5];

cout << values[0];
```

Correct approaches include:

```cpp
int values[5]{};
```

or assigning each element before reading it.

---

# 10. Global Arrays

An array with static storage duration:

```cpp
int values[5];
```

at namespace scope is zero-initialized.

This follows the static-storage initialization rules from the previous lessons.

But do not rely on globals just to get zero initialization.

Initialize intentionally.

---

# 11. Accessing Elements

Given:

```cpp
int values[4] = {
    10, 20, 30, 40
};
```

we can read:

```cpp
cout << values[2];
```

Output:

```text
30
```

We can modify:

```cpp
values[2] = 99;
```

New state:

```text
10 20 99 40
```

Array elements are ordinary objects of the element type.

---

# 12. Full Dry Run: Modification

Initial:

```text
values = [10, 20, 30, 40]
```

Execute:

```cpp
values[1] = 50;
```

State:

```text
values = [10, 50, 30, 40]
```

Execute:

```cpp
values[3] += 5;
```

State:

```text
values = [10, 50, 30, 45]
```

Execute:

```cpp
++values[0];
```

Final:

```text
values = [11, 50, 30, 45]
```

---

# 13. Traversing an Array

For:

```cpp
int values[5] = {
    10, 20, 30, 40, 50
};
```

use:

```cpp
for (int i = 0; i < 5; ++i) {
    cout << values[i] << ' ';
}
```

Indexes visited:

```text
0
1
2
3
4
```

Output:

```text
10 20 30 40 50
```

---

# 14. The Standard Array Loop Pattern

For an array with `n` elements:

```cpp
for (int i = 0; i < n; ++i) {
    // use array[i]
}
```

Why:

```text
i starts at 0
i < n
```

?

Because valid indexes are:

```text
0 through n - 1
```

This half-open range appears constantly in DSA.

---

# 15. Off-by-One Error

Wrong:

```cpp
for (int i = 0; i <= n; ++i) {
    cout << array[i];
}
```

When:

```text
i = n
```

the expression:

```cpp
array[n]
```

is one position beyond the valid array.

Built-in arrays do not perform automatic bounds checking.

Accessing outside the array produces undefined behavior.

Correct:

```cpp
i < n
```

---

# 16. Out-of-Bounds Access

For:

```cpp
int values[3] = {
    10, 20, 30
};
```

valid:

```text
values[0]
values[1]
values[2]
```

Invalid:

```text
values[3]
values[-1]
```

C++ raw arrays do not automatically throw an exception for these accesses.

The program may:

- print garbage
- corrupt memory
- crash
- appear to work
- behave differently later

All are possible consequences of undefined behavior.

Never treat "it didn't crash" as proof that an access was valid.

---

# 17. Contiguous Memory

Array elements are contiguous.

Conceptually:

```text
values[0]
values[1]
values[2]
values[3]

stored consecutively
```

If each `int` occupies four bytes on a particular implementation, a conceptual layout might be:

```text
ADDR
1000 -> values[0]
1004 -> values[1]
1008 -> values[2]
1012 -> values[3]
```

The actual addresses and `sizeof(int)` are implementation-dependent.

The guaranteed important property is:

```text
array elements are contiguous
```

---

# 18. Why Contiguity Matters

Contiguous storage enables:

- constant-time indexed access
- good cache locality in common hardware
- pointer arithmetic
- efficient sequential traversal

Conceptually:

```text
address of element i
=
start address + i * element size
```

C++ implements pointer arithmetic in terms of elements rather than requiring you to multiply by byte sizes manually.

Pointer arithmetic receives a dedicated lesson later.

---

# 19. Array Access Complexity

For:

```cpp
values[i]
```

the program does not need to scan from index 0.

The location can be computed directly.

Therefore indexed access is:

```text
O(1)
```

This is one of the fundamental strengths of arrays.

---

# 20. Searching an Unsorted Array

Suppose:

```text
[40, 10, 90, 30, 70]
```

We want:

```text
30
```

Without additional structure, we may inspect elements one by one.

```cpp
for (int i = 0; i < n; ++i) {
    if (values[i] == target) {
        ...
    }
}
```

Worst case:

```text
inspect all n elements
```

Complexity:

```text
O(n)
```

This is linear search.

---

# 21. Linear Search Dry Run

Array:

```text
[40, 10, 90, 30, 70]
```

Target:

```text
30
```

State:

```text
i = 0
values[0] = 40
40 == 30 -> false
```

Next:

```text
i = 1
10 == 30 -> false
```

Next:

```text
i = 2
90 == 30 -> false
```

Next:

```text
i = 3
30 == 30 -> true
```

Found:

```text
index = 3
```

Stop if only the first match is needed.

---

# 22. Summing Array Elements

```cpp
int values[5] = {
    2, 4, 6, 8, 10
};

long long sum = 0;

for (int i = 0; i < 5; ++i) {
    sum += values[i];
}
```

Dry run:

```text
sum = 0

i=0:
sum = 0 + 2 = 2

i=1:
sum = 2 + 4 = 6

i=2:
sum = 6 + 6 = 12

i=3:
sum = 12 + 8 = 20

i=4:
sum = 20 + 10 = 30
```

Final:

```text
30
```

---

# 23. Finding Minimum

Given non-empty array:

```cpp
int minimum = values[0];

for (int i = 1; i < n; ++i) {
    if (values[i] < minimum) {
        minimum = values[i];
    }
}
```

Why initialize using:

```cpp
values[0]
```

instead of:

```cpp
minimum = 0
```

?

Because all array values might be positive or negative.

Example:

```text
[5, 7, 9]
```

Starting minimum at zero would incorrectly produce:

```text
0
```

even though zero is not in the array.

Use an actual element when the array is known to be non-empty.

---

# 24. Finding Maximum

Likewise:

```cpp
int maximum = values[0];

for (int i = 1; i < n; ++i) {
    if (values[i] > maximum) {
        maximum = values[i];
    }
}
```

Complexity:

```text
O(n)
```

Extra space:

```text
O(1)
```

---

# 25. Counting Matching Elements

Example:

```cpp
int count = 0;

for (int i = 0; i < n; ++i) {
    if (values[i] == target) {
        ++count;
    }
}
```

This is a common array pattern:

```text
initialize accumulator/counter
traverse
test element
update answer
```

You will reuse this pattern constantly.

---

# 26. Input Into an Array

Example:

```cpp
constexpr int N = 5;
int values[N];

for (int i = 0; i < N; ++i) {
    cin >> values[i];
}
```

Input:

```text
10 20 30 40 50
```

Final state:

```text
[10, 20, 30, 40, 50]
```

Raw built-in array bounds must be compile-time-known in standard C++ when using this direct local fixed-size form.

---

# 27. Variable-Length Arrays Are Not Standard C++

You may encounter:

```cpp
int n;
cin >> n;

int values[n];
```

Some compilers accept this as an extension.

But variable-length arrays are not part of standard C++17.

Do not use them in portable C++17.

Later, for runtime-sized collections, use:

```cpp
std::vector<int>
```

which is one reason vectors are so important.

---

# 28. Fixed Array Size

Standard raw array:

```cpp
int values[5];
```

has fixed extent.

You cannot resize it later to hold 10 elements.

This is a major distinction between:

```text
raw fixed array
```

and later:

```text
std::vector
```

---

# 29. sizeof an Array

Given:

```cpp
int values[5];
```

inside the scope where `values` is still an actual array type:

```cpp
sizeof(values)
```

returns the total storage occupied by the array.

Conceptually:

```text
5 * sizeof(int)
```

Therefore the element count can be calculated locally using:

```cpp
sizeof(values) / sizeof(values[0])
```

For a five-element array:

```text
5
```

assuming normal complete array semantics.

But there is a major trap when arrays are passed to functions.

---

# 30. Arrays and Functions

You might write:

```cpp
void printArray(int values[], int n) {
}
```

The parameter declaration:

```cpp
int values[]
```

is adjusted to:

```cpp
int* values
```

in a function parameter list.

So the function is effectively receiving a pointer to the first element, not a complete array object by value.

---

# 31. Equivalent Array Parameter Forms

In a parameter list:

```cpp
void printArray(int values[], int n);
```

and:

```cpp
void printArray(int* values, int n);
```

declare equivalent parameter types after adjustment.

You may also see:

```cpp
void printArray(int values[100], int n);
```

The `100` does not make the function receive a 100-element array by value.

The array parameter is adjusted to pointer form.

This is a crucial C++ rule.

---

# 32. Why Functions Need the Array Size

Because this parameter:

```cpp
int values[]
```

becomes pointer-like:

```cpp
int* values
```

the function generally does not automatically know the array's length.

So we commonly pass:

```cpp
void printArray(
    const int values[],
    int n
);
```

Call:

```cpp
printArray(values, 5);
```

Mental model:

```text
pointer to first element
+
number of elements
```

---

# 33. sizeof Trap in Array Parameters

Outside function:

```cpp
int values[5];

sizeof(values)
```

means:

```text
size of entire array object
```

Inside:

```cpp
void f(int values[]) {
    cout << sizeof(values);
}
```

`values` is really a pointer parameter.

So:

```cpp
sizeof(values)
```

means:

```text
size of a pointer
```

not:

```text
size of original array
```

This is a famous C++ interview trap.

---

# 34. Passing Array to Function Allows Mutation

Example:

```cpp
void changeFirst(int values[]) {
    values[0] = 99;
}
```

Call:

```cpp
int data[3] = {1, 2, 3};

changeFirst(data);
```

Final:

```text
[99, 2, 3]
```

Why does this differ from pass-by-value `int`?

Because the array parameter adjusted to a pointer.

The function accesses the original elements through that pointer.

---

# 35. const Array Parameter

If a function should only read elements:

```cpp
void printArray(
    const int values[],
    int n
) {
    ...
}
```

This is effectively:

```cpp
const int* values
```

The function cannot modify the array elements through that pointer.

This is good interface design.

---

# 36. Raw Arrays Do Not Copy With =

Suppose:

```cpp
int a[3] = {1, 2, 3};
int b[3];
```

This is invalid:

```cpp
b = a;
```

Built-in arrays are not assignable as whole objects using ordinary `=`.

To copy element-by-element manually:

```cpp
for (int i = 0; i < 3; ++i) {
    b[i] = a[i];
}
```

Later standard containers have much friendlier value semantics.

---

# 37. Raw Arrays Cannot Be Returned by Value Directly

A function cannot simply return a built-in array type by value like an `int`.

Later alternatives include:

```text
std::array
std::vector
struct/class
```

This is another reason standard containers are generally preferable in modern C++ application code.

Raw arrays remain essential to understand because they reveal the memory model used throughout DSA.

---

# 38. Array-to-Pointer Conversion

In many expressions, an array expression is automatically converted ("decays") to a pointer to its first element.

Example:

```cpp
int values[3] = {
    10, 20, 30
};

int* ptr = values;
```

Conceptually:

```text
values
  |
  v
&values[0]
```

So:

```cpp
ptr == &values[0]
```

is true.

Important:

Arrays do not decay in every context.

For example:

```cpp
sizeof(values)
```

still sees the array type when `values` is an actual array object.

We will study this more deeply in the pointer lessons.

---

# 39. values vs &values[0]

Given:

```cpp
int values[3];
```

in many expressions:

```cpp
values
```

converts to:

```cpp
&values[0]
```

Both indicate the first element's address for ordinary pointer use.

This explains why:

```cpp
printArray(values, 3);
```

can supply a pointer parameter.

---

# 40. Range-Based for Loop

You learned range-based loops briefly in the roadmap but their full dedicated lesson comes later.

For an actual array in scope:

```cpp
int values[3] = {
    10, 20, 30
};

for (int value : values) {
    cout << value << ' ';
}
```

Output:

```text
10 20 30
```

Here `value` receives a copy of each element.

---

# 41. Modifying With Range-Based Reference

If we use:

```cpp
for (int& value : values) {
    value *= 2;
}
```

the reference aliases each actual array element in turn.

Initial:

```text
[1, 2, 3]
```

After loop:

```text
[2, 4, 6]
```

This directly connects to the previous references lesson.

---

# 42. Read-Only Range Loop

For read-only access:

```cpp
for (const int& value : values) {
    cout << value;
}
```

For `int`, copying is cheap, so:

```cpp
for (int value : values)
```

is also perfectly reasonable.

Later, for large element types, const references can avoid copies.

---

# 43. Reverse an Array In Place

Given:

```text
[10, 20, 30, 40, 50]
```

we can swap:

```text
index 0 with 4
index 1 with 3
```

Result:

```text
[50, 40, 30, 20, 10]
```

Manual pattern:

```cpp
int left = 0;
int right = n - 1;

while (left < right) {
    int temp = values[left];

    values[left] = values[right];
    values[right] = temp;

    ++left;
    --right;
}
```

This is an early preview of the two-pointer technique.

---

# 44. Reverse Dry Run

Array:

```text
[1, 2, 3, 4, 5]
```

Start:

```text
left = 0
right = 4
```

Swap indexes 0 and 4:

```text
[5, 2, 3, 4, 1]

left = 1
right = 3
```

Swap:

```text
[5, 4, 3, 2, 1]

left = 2
right = 2
```

Condition:

```text
left < right
2 < 2 -> false
```

Stop.

---

# 45. 2D Arrays

A 2D array organizes elements using rows and columns.

Example:

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Visual representation:

```text
       col
       0  1  2

row 0  1  2  3
row 1  4  5  6
```

Access:

```cpp
matrix[1][2]
```

gives:

```text
6
```

---

# 46. 2D Array Is an Array of Arrays

The type:

```cpp
int matrix[2][3];
```

means:

```text
array of 2 elements
```

where each element is:

```text
array of 3 int
```

Conceptually:

```text
matrix
|
+-- row 0 -> int[3]
|
+-- row 1 -> int[3]
```

This model becomes important when passing 2D arrays to functions.

---

# 47. Row-Major Contiguous Layout

Built-in multidimensional arrays are stored contiguously in row-major order.

For:

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

memory order is conceptually:

```text
1 2 3 4 5 6
```

not:

```text
1 4 2 5 3 6
```

The first row is stored contiguously, followed by the second row.

---

# 48. 2D Array Indexing

Access syntax:

```cpp
matrix[row][column]
```

Example:

```cpp
matrix[0][0] -> 1
matrix[0][2] -> 3
matrix[1][0] -> 4
matrix[1][2] -> 6
```

Both indices must be valid.

For:

```cpp
int matrix[2][3];
```

valid rows:

```text
0, 1
```

valid columns:

```text
0, 1, 2
```

---

# 49. Traversing a Matrix

Use nested loops:

```cpp
for (int row = 0; row < ROWS; ++row) {

    for (int col = 0; col < COLS; ++col) {
        cout << matrix[row][col] << ' ';
    }

    cout << '\n';
}
```

Outer loop:

```text
select row
```

Inner loop:

```text
visit columns in that row
```

For an `R × C` matrix, traversal is:

```text
O(R * C)
```

---

# 50. Matrix Dry Run

Matrix:

```text
1 2
3 4
```

Loops:

```text
row = 0
    col = 0 -> matrix[0][0] = 1
    col = 1 -> matrix[0][1] = 2

row = 1
    col = 0 -> matrix[1][0] = 3
    col = 1 -> matrix[1][1] = 4
```

Visit sequence:

```text
1 2 3 4
```

---

# 51. Initialize 2D Arrays

Example:

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Can also flatten initializer values:

```cpp
int matrix[2][3] = {
    1, 2, 3,
    4, 5, 6
};
```

The nested-brace form usually communicates rows more clearly.

---

# 52. Zero-Initialize a Matrix

```cpp
int matrix[3][4]{};
```

All twelve integers are zero-initialized.

Conceptually:

```text
0 0 0 0
0 0 0 0
0 0 0 0
```

---

# 53. Partial 2D Initialization

Example:

```cpp
int matrix[2][3] = {
    {1, 2},
    {3}
};
```

Missing elements are zero-initialized.

State:

```text
1 2 0
3 0 0
```

---

# 54. Row Sum

For:

```text
1 2 3
4 5 6
```

row 0:

```text
1 + 2 + 3 = 6
```

row 1:

```text
4 + 5 + 6 = 15
```

Code pattern:

```cpp
for (int row = 0; row < ROWS; ++row) {

    int sum = 0;

    for (int col = 0; col < COLS; ++col) {
        sum += matrix[row][col];
    }

    cout << sum << '\n';
}
```

---

# 55. Column Sum

Reverse loop roles:

```cpp
for (int col = 0; col < COLS; ++col) {

    int sum = 0;

    for (int row = 0; row < ROWS; ++row) {
        sum += matrix[row][col];
    }

    cout << sum << '\n';
}
```

For:

```text
1 2 3
4 5 6
```

column sums:

```text
5 7 9
```

---

# 56. Main Diagonal

For a square matrix:

```text
a00 a01 a02
a10 a11 a12
a20 a21 a22
```

main diagonal positions satisfy:

```text
row == column
```

Elements:

```text
matrix[0][0]
matrix[1][1]
matrix[2][2]
```

Loop:

```cpp
for (int i = 0; i < N; ++i) {
    cout << matrix[i][i];
}
```

Complexity:

```text
O(N)
```

---

# 57. Secondary Diagonal

For an `N × N` matrix:

```text
row + column = N - 1
```

So:

```cpp
matrix[i][N - 1 - i]
```

visits the secondary diagonal.

For:

```text
1 2 3
4 5 6
7 8 9
```

secondary diagonal:

```text
3 5 7
```

---

# 58. Passing a 2D Raw Array to a Function

Suppose:

```cpp
int matrix[2][3];
```

A function can be declared with the later dimensions known:

```cpp
void printMatrix(
    const int matrix[][3],
    int rows
);
```

Equivalent pointer-oriented type:

```cpp
const int (*matrix)[3]
```

Why must the column extent be known?

Because pointer arithmetic needs to know the size of one row.

Conceptually:

```text
matrix points to rows

one row has exactly 3 int elements
```

---

# 59. Why This Is More Complicated Than 1D Arrays

For 1D:

```cpp
int values[]
```

adjusts to:

```cpp
int*
```

The size of an `int` is known.

For 2D:

```cpp
int matrix[][3]
```

adjusts to a pointer to:

```text
array of 3 int
```

The compiler needs the row width to calculate:

```cpp
matrix[row]
```

correctly.

This becomes clearer after pointer arithmetic.

---

# 60. Fixed Dimensions With constexpr

Useful:

```cpp
constexpr int ROWS = 2;
constexpr int COLS = 3;

int matrix[ROWS][COLS];
```

`constexpr` here creates compile-time constants appropriate for fixed extents.

We have not given `constexpr` a dedicated lesson yet, but for basic integral constants this use is straightforward.

You may also use literal extents directly while learning:

```cpp
int matrix[2][3];
```

---

# 61. 3D and Higher-Dimensional Arrays

C++ supports:

```cpp
int cube[2][3][4];
```

Conceptually:

```text
array of 2
    arrays of 3
        arrays of 4 int
```

The same ideas extend to higher dimensions.

DSA commonly uses:

```text
1D arrays
2D grids/matrices
occasionally 3D DP tables
```

---

# 62. Array Size and Compile-Time Constants

This is standard:

```cpp
constexpr int N = 100;
int values[N];
```

This is also typically valid when `N` is an appropriate integral constant expression:

```cpp
const int N = 100;
int values[N];
```

But:

```cpp
int n;
cin >> n;

int values[n];
```

is not standard C++17.

Use `vector` later for runtime sizes.

---

# 63. Large Local Arrays

A very large local raw array may consume substantial automatic storage.

Example:

```cpp
int values[10'000'000];
```

On common systems this may exceed available stack-like automatic storage and crash.

Competitive programmers sometimes use large global/static arrays because static-storage regions often have different capacity characteristics.

Later we will study:

```text
stack vs heap memory
dynamic allocation
vector
```

Do not create enormous local arrays casually.

---

# 64. Array Memory Usage

For:

```cpp
int values[n]
```

conceptually:

```text
n * sizeof(int)
```

bytes of element storage are required.

For:

```cpp
int matrix[R][C]
```

conceptually:

```text
R * C * sizeof(int)
```

bytes.

This is:

```text
O(n)
```

storage for `n` elements.

And:

```text
O(R*C)
```

storage for an `R × C` matrix.

---

# 65. Arrays and const

Read-only raw array:

```cpp
const int values[3] = {
    1, 2, 3
};
```

You can read:

```cpp
cout << values[0];
```

but not assign:

```cpp
values[0] = 10;
```

Likewise, read-only function interface:

```cpp
void print(
    const int values[],
    int n
);
```

prevents modification through the parameter pointer.

---

# 66. Array Elements and References

You can bind a reference to an array element:

```cpp
int values[3] = {
    10, 20, 30
};

int& ref = values[1];

ref = 99;
```

Final:

```text
[10, 99, 30]
```

Why?

```text
ref aliases values[1]
```

This connects arrays directly to the previous references lesson.

---

# 67. Reference to an Entire Array

C++ can also reference the whole array type:

```cpp
int values[3] = {
    1, 2, 3
};

int (&ref)[3] = values;
```

The syntax looks unusual.

`ref` is:

```text
reference to array of 3 int
```

Unlike ordinary function array parameters, an array reference preserves the extent.

This enables generic patterns later with templates.

You do not need to use this often yet, but it proves that an array itself has a real type including its extent.

---

# 68. Pointer to Array vs Array of Pointers

These are completely different:

```cpp
int (*ptr)[3];
```

means:

```text
pointer to array of 3 int
```

Whereas:

```cpp
int* ptrs[3];
```

means:

```text
array of 3 pointers to int
```

Parentheses matter.

We will study declaration syntax more deeply in pointer lessons.

---

# 69. C-Style Array vs std::array

Later:

```cpp
std::array<int, 5>
```

provides a fixed-size standard-library container with friendlier value semantics.

It can:

- be copied
- be assigned
- know its `.size()`
- work naturally with STL algorithms

Raw arrays are still important because:

- legacy APIs use them
- language fundamentals depend on them
- pointer relationships become clearer
- interview code sometimes uses them
- multidimensional memory understanding starts here

But in modern application code, standard containers are frequently preferable.

---

# 70. C-Style Array vs std::vector

Raw fixed array:

```cpp
int values[5];
```

Size is fixed at compile-time in the ordinary built-in case.

Vector:

```cpp
vector<int> values(n);
```

supports runtime size and dynamic resizing.

We will study `vector` thoroughly in STL.

Do not try to imitate a vector by using non-standard variable-length arrays.

---

# 71. Common Interview Mistakes

1. Using index `n` for an array of size `n`.

2. Starting loops at 1 when using zero-based indexing.

3. Writing:

```cpp
i <= n
```

instead of:

```cpp
i < n
```

4. Reading an uninitialized local array.

5. Assuming local arrays automatically contain zeros.

6. Using non-standard variable-length arrays:

```cpp
int a[n];
```

when `n` is runtime input.

7. Assuming raw arrays know their length inside a pointer-style function parameter.

8. Using `sizeof(array)` inside:

```cpp
void f(int array[])
```

to infer original element count.

9. Forgetting that raw array parameters adjust to pointers.

10. Assuming an array is copied when passed to a function.

11. Accidentally modifying original array elements inside a function.

12. Forgetting `const` when a function should only read.

13. Trying:

```cpp
array2 = array1;
```

with raw arrays.

14. Assuming raw arrays can be returned by value like an `int`.

15. Accessing negative indexes.

16. Assuming out-of-bounds access must crash.

17. Initializing minimum to zero instead of an actual element.

18. Accessing `values[0]` when the logical array is empty.

19. Overflowing an array sum stored in `int`.

20. Confusing rows and columns in a matrix.

21. Writing matrix loops with swapped bounds.

22. Forgetting the column extent when passing a raw 2D array.

23. Creating extremely large local arrays and exhausting automatic storage.

24. Confusing:

```cpp
int (*p)[3]
```

with:

```cpp
int* p[3]
```

25. Assuming nested loops are always inefficient without considering actual dimensions and constraints.

---

# 72. Complexity Table

| Operation | Time | Extra Space |
|---|---:|---:|
| Access `a[i]` | O(1) | O(1) |
| Modify `a[i]` | O(1) | O(1) |
| Traverse n elements | O(n) | O(1) |
| Linear search | O(n) worst case | O(1) |
| Find min/max | O(n) | O(1) |
| Sum n elements | O(n) | O(1) |
| Count matching values | O(n) | O(1) |
| Reverse in place | O(n) | O(1) |
| Copy raw array manually | O(n) | O(n) destination storage |
| Access `matrix[r][c]` | O(1) | O(1) |
| Traverse R × C matrix | O(R*C) | O(1) |
| Row sum for all rows | O(R*C) | O(1) |
| Column sum for all columns | O(R*C) | O(1) |
| Main diagonal of N × N | O(N) | O(1) |
| Store n-element array | — | O(n) |
| Store R × C matrix | — | O(R*C) |

---

# 73. Practice Questions

1. LeetCode 1480 — Running Sum of 1d Array  
   https://leetcode.com/problems/running-sum-of-1d-array/

2. LeetCode 1929 — Concatenation of Array  
   https://leetcode.com/problems/concatenation-of-array/

3. LeetCode 1672 — Richest Customer Wealth  
   https://leetcode.com/problems/richest-customer-wealth/

4. GFG — Arrays in C/C++  
   https://www.geeksforgeeks.org/cpp-arrays/

5. GFG — Multidimensional Arrays in C++  
   https://www.geeksforgeeks.org/multidimensional-arrays-in-cpp/

Some LeetCode solutions conventionally use `std::vector`, which we have not deeply studied yet. Understand the array logic now and revisit the platform-specific implementations after STL.

---

# 74. Final Mental Model

1D:

```text
array name
    |
    v
+------+------+------+------+------+
| a[0] | a[1] | a[2] | a[3] | a[4] |
+------+------+------+------+------+
```

Traversal:

```text
i = 0
while i < n
    process a[i]
    i++
```

2D:

```text
matrix[row][column]

       c0 c1 c2
r0     [] [] []
r1     [] [] []
```

Function parameter:

```cpp
void f(int a[], int n)
```

Think:

```text
pointer/access to original elements
+
explicit size
```

And always enforce:

```text
0 <= index < size
```

Raw C++ arrays do not protect you from violating that rule.

---

# What's Next

`01_C++__/13_STRINGS_AND_C_STRINGS/`

Next we study character sequences, `std::string`, C-style null-terminated strings, indexing, traversal, input with spaces, common string operations, comparisons, conversions, and the crucial difference between modern C++ strings and character arrays.
