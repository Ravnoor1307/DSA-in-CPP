# 28 — `auto` and Range-Based Loops

## Learning goals

Modern C++ can often deduce types from initializers and simplify
iteration over collections.

By the end of this lesson, you should understand:

- what `auto` means
- compile-time type deduction
- `auto` is still statically typed
- `auto` requires an initializer in ordinary variable declarations
- copies made by plain `auto`
- `auto&`
- `const auto&`
- `auto*`
- top-level `const` deduction
- reference deduction basics
- `decltype(auto)` preview
- range-based `for`
- iteration by value
- iteration by reference
- iteration by const reference
- modifying elements through a range loop
- C-style arrays in range-based loops
- `std::array` and `std::vector` examples
- strings as ranges
- nested range-based loops
- structured bindings in C++17
- structured bindings by value/reference
- iterator desugaring at a conceptual level
- common lifetime and copying mistakes
- choosing readable types versus `auto`

---

## 1. Why `auto` exists

Consider:

```cpp
int value = 10;
```

The type is obvious from the declaration.

But C++ types can become much longer:

```cpp
std::vector<int>::iterator iterator = values.begin();
```

Modern C++ lets the compiler deduce the type:

```cpp
auto iterator = values.begin();
```

`auto` reduces repetition when the initializer already communicates the
type sufficiently.

---

## 2. `auto` does not make C++ dynamically typed

Given:

```cpp
auto value = 10;
```

the compiler determines:

```text
value has type int
```

Once deduced, `value` does not dynamically change to unrelated types at
runtime.

This is still statically typed C++.

Conceptually:

```text
source code:
auto value = 10;

compile-time deduction:
initializer type -> int

effective variable type:
int
```

---

## 3. Real-world analogy

Imagine a form containing:

```text
Package type: infer from enclosed item
```

If the enclosed item is clearly a book, the system labels the package
accordingly before shipping.

The package is not changing categories randomly while traveling.

Similarly, `auto` tells the compiler to deduce a type from the
initializer during compilation.

---

## 4. Basic `auto`

Examples:

```cpp
auto integer = 10;
auto decimal = 3.14;
auto letter = 'A';
auto text = std::string("DSA");
```

Typical deductions:

```text
integer -> int
decimal -> double
letter  -> char
text    -> std::string
```

---

## 5. `auto` needs an initializer

This is not valid:

```cpp
auto value;
```

How could the compiler determine the intended type?

Instead:

```cpp
auto value = 10;
```

provides information for deduction.

There are contexts involving placeholder return types and other syntax,
but for ordinary local variables remember:

```text
auto variable -> initializer required
```

---

## 6. `auto` does not mean "shortest possible type"

Suppose:

```cpp
long long value = 10;
auto copy = value;
```

`copy` is deduced from `value`, so it is:

```text
long long
```

The compiler does not inspect the numerical value `10` and decide that
an `int` happens to be smaller.

Deduction is based on expression type rules.

---

## 7. Plain `auto` usually creates a value

Consider:

```cpp
int original = 10;
auto copy = original;
```

Now:

```text
original = 10
copy     = 10
```

Then:

```cpp
copy = 50;
```

results in:

```text
original = 10
copy     = 50
```

`copy` is a separate integer.

This is an important rule when iterating through containers.

---

## 8. `auto&`

To deduce a reference:

```cpp
auto& reference = original;
```

Now:

```cpp
reference = 50;
```

modifies:

```cpp
original
```

because `reference` refers to the same object.

Dry run:

```text
original = 10

auto& reference = original

reference ----+
              |
              v
         original = 10

reference = 50

original = 50
```

---

## 9. `const auto&`

For read-only access without copying:

```cpp
const auto& reference = object;
```

This is extremely common.

It means approximately:

```text
deduce the referenced type
bind a reference
do not allow modification through this reference
```

For large objects, this avoids copying.

---

## 10. Top-level const and plain `auto`

Consider:

```cpp
const int original = 10;
auto value = original;
```

Plain `auto` deduces a new value variable and generally drops the
initializer's top-level `const`.

Therefore:

```cpp
value = 20;
```

is valid.

But:

```cpp
const auto value = original;
```

explicitly makes the new variable const.

---

## 11. `auto&` and constness

Given:

```cpp
const int value = 10;
auto& reference = value;
```

the deduced reference must respect the fact that `value` is const.

The effective type is a reference to const integer.

Therefore:

```cpp
reference = 20;
```

is not allowed.

Deduction does not permit modifying an originally const object through
a reference.

---

## 12. `auto*`

Pointer types can also be deduced:

```cpp
int value = 10;
auto* pointer = &value;
```

`pointer` becomes:

```text
int*
```

Plain:

```cpp
auto pointer = &value;
```

also deduces an `int*`.

Writing `auto*` can make the pointer nature visually explicit.

---

## 13. `auto` with function return values

Suppose:

```cpp
double average() {
    return 3.5;
}
```

Then:

```cpp
auto result = average();
```

deduces:

```text
double
```

This becomes especially useful with complicated library return types.

---

## 14. `auto` as a function return type

C++14 and later can deduce a function's return type:

```cpp
auto add(int a, int b) {
    return a + b;
}
```

The compiler determines the return type from the return statement.

This works under language rules that require compatible deduction
across the function's return statements.

Avoid using return-type deduction merely to conceal an important public
interface type.

---

## 15. `decltype(auto)` preview

C++ also has:

```cpp
decltype(auto)
```

It uses `decltype`-style deduction rules and can preserve references in
situations where plain `auto` would produce a value.

Example idea:

```cpp
decltype(auto) access() {
    return (someObject);
}
```

The parentheses can matter to `decltype`.

This is useful in advanced generic programming but is easy to misuse.

For DSA code at this stage, focus primarily on:

```text
auto
auto&
const auto&
```

---

# Part II — Range-Based `for`

## 16. Traditional index loop

For an array:

```cpp
int values[] = {10, 20, 30};

for (int i = 0; i < 3; ++i) {
    cout << values[i] << '\n';
}
```

This is appropriate when you need the index.

But when you only need each element, C++ offers range-based `for`.

---

## 17. Basic range loop

```cpp
for (int value : values) {
    cout << value << '\n';
}
```

Read it as:

```text
for each value in values
```

With `auto`:

```cpp
for (auto value : values) {
    cout << value << '\n';
}
```

This avoids repeating the element type.

---

## 18. Iteration by value

Consider:

```cpp
int values[] = {10, 20, 30};

for (auto value : values) {
    value *= 2;
}
```

What happens to the array?

Nothing.

Each `value` is a copy.

Dry run:

```text
array:
[10, 20, 30]

iteration 1:
value = copy of 10
value becomes 20
array still [10, 20, 30]

iteration 2:
value = copy of 20
value becomes 40
array still [10, 20, 30]

iteration 3:
value = copy of 30
value becomes 60
array still [10, 20, 30]
```

Final array:

```text
[10, 20, 30]
```

---

## 19. Iteration by reference

To modify actual elements:

```cpp
for (auto& value : values) {
    value *= 2;
}
```

Dry run:

```text
Initial:
[10, 20, 30]

iteration 1:
value refers to values[0]
10 -> 20
[20, 20, 30]

iteration 2:
value refers to values[1]
20 -> 40
[20, 40, 30]

iteration 3:
value refers to values[2]
30 -> 60
[20, 40, 60]
```

Final:

```text
[20, 40, 60]
```

---

## 20. Read-only iteration

A very useful pattern is:

```cpp
for (const auto& value : collection) {
    // read value
}
```

Benefits:

- avoids copying each element
- prevents modification through `value`
- works well for large objects

For small primitive types such as `int`, this:

```cpp
for (int value : values)
```

is often perfectly fine.

Do not treat references as automatically faster in every situation.

---

## 21. Choosing value versus reference

Useful rule of thumb:

```text
Need independent small copy?
    auto value

Need to modify original element?
    auto& value

Need read-only access without copy?
    const auto& value
```

The exact best choice depends on element type and semantics.

---

## 22. Strings are ranges

A `std::string` can be traversed:

```cpp
std::string word = "DSA";

for (char character : word) {
    cout << character << '\n';
}
```

You can modify characters with:

```cpp
for (char& character : word) {
    ...
}
```

or:

```cpp
for (auto& character : word) {
    ...
}
```

---

## 23. C-style arrays work

Given:

```cpp
int values[] = {1, 2, 3, 4};
```

this works:

```cpp
for (auto value : values) {
}
```

because the compiler knows the array bounds in that scope.

However, once an array parameter decays to a pointer:

```cpp
void process(int values[]) {
}
```

the function does not have a range with known array bounds from that
parameter alone.

This distinction comes directly from your earlier array lessons.

---

## 24. `std::array`

C++ provides:

```cpp
std::array<int, 3>
```

which works naturally with range-based loops:

```cpp
std::array<int, 3> values = {10, 20, 30};

for (const auto& value : values) {
    cout << value;
}
```

`std::array` will receive a dedicated STL deep-dive later.

We use it lightly here to demonstrate iteration.

---

## 25. `std::vector`

Likewise:

```cpp
std::vector<int> values = {10, 20, 30};

for (auto value : values) {
    cout << value;
}
```

`vector` receives a dedicated lesson in the STL section.

At this stage, the important point is that range-based `for` works with
many types that expose the required iteration interface.

---

## 26. Conceptual desugaring

A range-based loop such as:

```cpp
for (auto& value : values) {
    value++;
}
```

can be understood approximately as:

```text
obtain the range
obtain begin position
obtain end position

while current position != end:
    bind value to current element
    execute loop body
    advance current position
```

Actual standard wording and compiler transformations have more detail.

This mental model becomes useful when you later study iterators.

---

## 27. `begin()` and `end()`

Many standard containers provide iteration positions via concepts such
as:

```cpp
container.begin()
container.end()
```

Range-based loops use language-defined lookup machinery related to
`begin` and `end`.

You do not need to write these calls manually for ordinary range-based
iteration.

Iterators get a full dedicated lesson later.

---

# Part III — Structured Bindings

## 28. Structured bindings in C++17

Suppose we have:

```cpp
std::pair<std::string, int> student{
    "Asha",
    95
};
```

C++17 allows:

```cpp
auto [name, marks] = student;
```

This decomposes the object into named bindings.

Conceptually:

```text
student
+---------+-------+
| "Asha"  | 95    |
+---------+-------+
     |        |
     v        v
   name     marks
```

With plain `auto`, these bindings behave as value bindings according to
structured-binding rules.

---

## 29. Structured bindings by reference

To work with the original elements:

```cpp
auto& [name, marks] = student;
```

Then:

```cpp
marks = 100;
```

modifies the corresponding value inside `student`.

For read-only access:

```cpp
const auto& [name, marks] = student;
```

This pattern becomes very common with maps and pairs later.

---

## 30. Array structured binding

C++17 can decompose a known-size array:

```cpp
int point[2] = {3, 4};

auto [x, y] = point;
```

Now:

```text
x = 3
y = 4
```

Using references:

```cpp
auto& [x, y] = point;
x = 10;
```

can modify the original array element.

---

## 31. Structured binding with custom structs

Given:

```cpp
struct Point {
    int x;
    int y;
};
```

you can write:

```cpp
Point point{3, 7};

auto [x, y] = point;
```

This is useful for small aggregate-style data types.

The exact structured-binding rules support several categories of types,
including arrays and tuple-like objects.

---

# Part IV — Copying Costs

## 32. Hidden copies in range loops

Suppose:

```cpp
std::vector<std::string> words;
```

Then:

```cpp
for (auto word : words) {
}
```

copies each string into `word`.

If each string is large, this can be unnecessary.

Prefer:

```cpp
for (const auto& word : words) {
}
```

when you only need to read.

---

## 33. Dry run: expensive copy idea

Imagine three large objects:

```text
objects = [A, B, C]
```

With:

```cpp
for (auto object : objects)
```

each iteration conceptually creates a copy:

```text
copy A -> use copy -> destroy copy
copy B -> use copy -> destroy copy
copy C -> use copy -> destroy copy
```

With:

```cpp
for (const auto& object : objects)
```

each iteration instead binds a read-only reference to the existing
element.

No element copy is required merely for the loop variable.

---

## 34. When plain value iteration is desirable

Do not blindly write references everywhere.

For:

```cpp
int values[] = {1, 2, 3};
```

this is simple and clear:

```cpp
for (int value : values) {
    cout << value;
}
```

Copying an integer is trivial.

Value semantics are also useful when you intentionally want an
independent temporary that can be modified without changing the
collection.

---

# Part V — `auto` Pitfalls

## 35. `auto` can hide an important type

Compare:

```cpp
auto result = compute();
```

with:

```cpp
double result = compute();
```

Sometimes the explicit type communicates important meaning.

`auto` is most useful when:

- the type is obvious from the initializer
- the exact spelling is long or noisy
- the exact implementation type is not important
- avoiding repetition improves readability

Do not use it simply to avoid understanding the type.

---

## 36. Brace initialization can surprise

C++ `auto` deduction with braces has special rules.

Examples:

```cpp
auto x = {1, 2, 3};
```

commonly deduces:

```text
std::initializer_list<int>
```

whereas:

```cpp
auto x{1};
```

in modern C++ deduces:

```text
int
```

These forms are not interchangeable.

For beginner DSA code, prefer straightforward initializers when the
deduction behavior matters.

---

## 37. Integer division does not disappear with `auto`

```cpp
auto value = 5 / 2;
```

The expression:

```cpp
5 / 2
```

uses integer division first.

Therefore:

```text
value = 2
type = int
```

`auto` does not magically infer that you wanted `2.5`.

Use:

```cpp
auto value = 5.0 / 2;
```

to get a floating-point result.

---

## 38. References can outlive their objects

This is dangerous:

```cpp
const auto& reference = getSomethingTemporary();
```

Whether it is safe depends on temporary-lifetime rules and the exact
expression.

Likewise, a reference to an element can become invalid when the
container changes or dies.

References do not own objects.

Later container lessons will discuss iterator/reference invalidation in
detail.

---

## 39. Modifying a collection while iterating

A range-based loop can become unsafe if its body structurally changes
the collection in a way that invalidates the underlying iteration
positions.

For example, later with `vector`, operations that reallocate storage
can invalidate references and iterators.

Do not assume this is always safe:

```cpp
for (auto& value : vector) {
    // add more elements to the same vector
}
```

The precise invalidation rules depend on the container and operation.

---

## 40. Nested range loops

A 2D array can be traversed elegantly:

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

for (const auto& row : matrix) {
    for (auto value : row) {
        cout << value << ' ';
    }
}
```

Why use:

```cpp
const auto& row
```

instead of plain:

```cpp
auto row
```

?

C-style array rows have special array behavior, and binding a reference
preserves the row as an array rather than attempting ordinary value
deduction/copy semantics.

This is a useful example where `auto&` is especially natural.

---

## 41. DSA usage patterns

You will frequently write:

```cpp
for (int value : values)
```

for small integers.

You will also see:

```cpp
for (const auto& edge : graph[node])
```

for read-only graph edges.

And:

```cpp
for (auto& value : values)
```

when modifying elements.

Later, with maps:

```cpp
for (const auto& [key, value] : map) {
}
```

will become a common C++17 pattern.

---

## Complexity

`auto` affects type spelling and deduction, not runtime Big-O
complexity.

Range-based loops have the complexity of the traversal they perform.

| Operation | Time | Extra space |
|---|---:|---:|
| `auto x = integer` | O(1) | O(1) |
| `auto& x = integer` | O(1) | O(1) |
| Traverse n integers by value | O(n) | O(1) |
| Traverse n elements by reference | O(n) | O(1) |
| Modify n elements by reference | O(n) | O(1) |
| Nested traversal of r x c matrix | O(r*c) | O(1) |
| Copy n expensive objects in loop | O(sum of copy costs) | One loop-copy object at a time |
| Structured binding of fixed small object | O(1)* | Depends on value/reference form |

`*` Assuming component operations are constant-time.

---

## Common interview and beginner mistakes

1. Thinking `auto` means dynamically typed.

2. Writing:

```cpp
auto value;
```

without enough information for deduction.

3. Forgetting that plain `auto` normally creates a separate value.

4. Expecting:

```cpp
for (auto x : values)
```

to modify the collection.

5. Copying large objects accidentally with value iteration.

6. Using `auto&` when a read-only `const auto&` better expresses intent.

7. Forgetting that references must not outlive the objects they refer
   to.

8. Assuming `auto` changes integer division.

9. Assuming `const auto&` means the original object itself was declared
   const.

10. Modifying a collection structurally while iterating without
    understanding invalidation.

11. Using broad `auto` everywhere until code becomes difficult to read.

12. Assuming a C-style array parameter remains a complete iterable
    array inside a function after decay to pointer.

13. Forgetting references for rows in convenient 2D range traversal.

14. Confusing structured bindings by value with structured bindings by
    reference.

15. Assuming `auto x = {1, 2, 3}` simply means `int`.

---

## Practice questions and references

1. GeeksforGeeks — Type Inference in C++ (`auto` and `decltype`)  
   https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/

2. GeeksforGeeks — Range-Based `for` Loop  
   https://www.geeksforgeeks.org/range-based-loop-c/

3. cppreference — `auto`  
   https://en.cppreference.com/w/cpp/language/auto

4. cppreference — Range-based `for`  
   https://en.cppreference.com/w/cpp/language/range-for

5. cppreference — Structured binding  
   https://en.cppreference.com/w/cpp/language/structured_binding

For hands-on practice, rewrite earlier array/string loops using all
three forms where appropriate:

```text
value
reference
const reference
```

and predict which versions modify the original data.

---

## Revision checklist

Before moving on, make sure you can explain:

- compile-time deduction with `auto`
- why C++ remains statically typed
- plain `auto`
- `auto&`
- `const auto&`
- `auto*`
- top-level const behavior
- range-based loops
- iteration by value
- iteration by reference
- read-only reference iteration
- C-style array iteration
- string iteration
- nested matrix traversal
- conceptual `begin`/`end` iteration
- structured bindings
- structured bindings by reference
- accidental copying
- collection invalidation concerns
- when explicit types are clearer than `auto`

# What's Next

Continue to:

`01_C++__/29_LAMBDAS/`

The next lesson introduces lambda expressions, captures, parameters,
return types, mutable lambdas, capture by value/reference, generic
lambdas, lambdas with algorithms, and common lifetime pitfalls.
