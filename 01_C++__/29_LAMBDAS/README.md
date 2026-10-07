# 29 — Lambda Expressions in C++

## Learning goals

A lambda expression lets you create a small callable object directly
where it is needed.

By the end of this lesson, you should understand:

- what lambdas are
- lambda syntax
- closure objects and closure types
- parameter lists
- return-value deduction
- explicit return types
- capture lists
- capture by value
- capture by reference
- mixed captures
- `[=]` and `[&]`
- `mutable` lambdas
- const behavior of ordinary lambdas
- init-capture in C++14/C++17
- generic lambdas
- immediately invoked lambdas
- lambdas as function arguments
- returning lambdas with `auto`
- lambdas with standard algorithms
- custom sorting predicates
- `std::function`
- stateless lambdas and function pointers
- lifetime dangers of reference captures
- `this` capture basics in C++17
- complexity considerations

---

## 1. Why lambdas exist

Suppose you need a tiny operation only once:

```cpp
bool isEven(int value) {
    return value % 2 == 0;
}
```

Creating a separately named function is perfectly valid.

But sometimes the operation is useful only near one algorithm call.

A lambda lets you write the callable directly:

```cpp
auto isEven = [](int value) {
    return value % 2 == 0;
};
```

Usage:

```cpp
cout << isEven(8);
```

A lambda is especially useful when behavior is short and local to the
code that consumes it.

---

## 2. Basic lambda syntax

General shape:

```cpp
[capture](parameters) -> return_type {
    body
}
```

Example:

```cpp
[](int a, int b) -> int {
    return a + b;
}
```

Parts:

```text
[]                  capture list
(int a, int b)      parameters
-> int              optional explicit return type
{ return a + b; }   body
```

The compiler can often deduce the return type, so this is common:

```cpp
[](int a, int b) {
    return a + b;
}
```

---

## 3. Real-world analogy

Think of a lambda as a small task card.

A normal function is like a reusable procedure stored under a permanent
name:

```text
Procedure: calculateTax
```

A lambda is often more like:

```text
For this operation only:
take a number
return whether it is even
```

The task card can also carry selected information from the surrounding
scope.

That carried information is represented through captures.

---

## 4. A lambda creates an object

A lambda expression produces an object of an unnamed compiler-generated
class type called a closure type.

Example:

```cpp
auto square = [](int value) {
    return value * value;
};
```

`square` is not merely "a function."

It stores a closure object that can be called:

```cpp
square(5);
```

Conceptually, the compiler generates something roughly resembling:

```cpp
class SomeUnnamedType {
public:
    int operator()(int value) const {
        return value * value;
    }
};
```

The actual closure type is compiler-generated and has language-defined
properties. The class above is only a mental model.

This connects directly to `operator()` from the operator-overloading
lesson.

---

## 5. A lambda without captures

Example:

```cpp
auto add = [](int a, int b) {
    return a + b;
};
```

Usage:

```cpp
cout << add(3, 4);
```

Output:

```text
7
```

No surrounding state is required.

The capture list is empty:

```cpp
[]
```

---

## 6. Capture by value

Suppose:

```cpp
int factor = 3;

auto multiply = [factor](int value) {
    return value * factor;
};
```

The lambda captures `factor` by value.

Conceptually, the closure stores its own captured value.

Dry run:

```text
factor = 3

create lambda:
closure.factor = 3

change outside factor:
factor = 10

call lambda with 5:
closure.factor is still 3
5 * 3 = 15
```

Changing the original variable later does not update that stored value.

---

## 7. Capture by reference

Example:

```cpp
int total = 0;

auto addToTotal = [&total](int value) {
    total += value;
};
```

The closure refers to the existing `total`.

Calls:

```cpp
addToTotal(10);
addToTotal(20);
```

produce:

```text
total = 30
```

Conceptually:

```text
closure
   |
   +---- reference-like access ----> total
```

The original object is modified.

---

## 8. Value versus reference capture

Compare:

```cpp
int number = 10;

auto byValue = [number]() {
    return number;
};

auto byReference = [&number]() {
    return number;
};

number = 99;
```

Now:

```text
byValue()     -> 10
byReference() -> 99
```

because the first closure stored the captured value from creation,
while the second refers to the original variable.

---

## 9. Default value capture `[=]`

This:

```cpp
[=]() {
    // ...
}
```

allows odr-used local variables to be captured by value by default.

Example:

```cpp
int a = 10;
int b = 20;

auto sum = [=]() {
    return a + b;
};
```

The lambda can use both values without listing each one explicitly.

Do not use `[=]` blindly. Explicit captures often make dependencies
clearer.

---

## 10. Default reference capture `[&]`

This:

```cpp
[&]() {
    // ...
}
```

captures used automatic local variables by reference by default.

Example:

```cpp
int a = 10;
int b = 20;

auto modify = [&]() {
    a++;
    b++;
};
```

After calling:

```cpp
modify();
```

the original variables become:

```text
a = 11
b = 21
```

Again, broad reference capture should be used carefully because it can
create hidden dependencies and lifetime risks.

---

## 11. Mixed captures

You can combine a default with exceptions.

Example:

```cpp
[=, &total]
```

means:

```text
capture used locals by value by default
capture total by reference
```

Likewise:

```cpp
[&, limit]
```

means:

```text
capture used locals by reference by default
capture limit by value
```

You may also list captures explicitly:

```cpp
[a, &b]
```

---

## 12. Captured-by-value variables are read-only by default

Consider:

```cpp
int count = 10;

auto lambda = [count]() {
    // count++;
};
```

By default, the lambda's call operator is const.

Therefore the captured value cannot normally be modified inside the
body.

To allow modification of the closure's own captured copy, use
`mutable`.

---

## 13. `mutable` lambda

Example:

```cpp
int count = 10;

auto next = [count]() mutable {
    return ++count;
};
```

Calls:

```cpp
next(); // 11
next(); // 12
```

But the outside variable remains:

```text
count = 10
```

Dry run:

```text
outside count = 10

lambda creation:
closure copy = 10

next():
closure copy = 11
outside count = 10

next():
closure copy = 12
outside count = 10
```

`mutable` modifies the closure's captured value, not the original
variable.

---

## 14. Reference capture does not need `mutable` to modify the referent

Example:

```cpp
int value = 10;

auto change = [&value]() {
    value = 50;
};
```

This is valid without `mutable`.

The lambda is not modifying a stored copied integer.

It is modifying the external object reached through the reference
capture.

---

## 15. Explicit return types

The compiler often deduces a lambda return type:

```cpp
auto add = [](int a, int b) {
    return a + b;
};
```

You can make it explicit:

```cpp
auto divide = [](double a, double b) -> double {
    return a / b;
};
```

Explicit return types can help when:

- several return statements need a deliberate common type
- conversions should be made explicit
- the interface is clearer with the return type shown

---

## 16. Lambdas are statically typed

Each lambda expression has its own unique closure type.

Even two visually identical lambdas generally have different closure
types:

```cpp
auto a = []() { return 1; };
auto b = []() { return 1; };
```

Do not assume:

```text
type of a == type of b
```

The compiler knows each exact type, while `auto` saves us from having
to spell an unnamed closure type.

---

## 17. Passing a lambda to a function template

Because a lambda is an object, a function template can receive it:

```cpp
template <typename Function>
void repeat(int times, Function action) {
    for (int i = 0; i < times; ++i) {
        action();
    }
}
```

Usage:

```cpp
repeat(3, []() {
    cout << "Hello\n";
});
```

This form is highly efficient and common in generic C++ because the
callable's concrete type is known at compile time.

---

## 18. Returning a lambda

Because `auto` can deduce the unnamed closure type:

```cpp
auto makeMultiplier(int factor) {
    return [factor](int value) {
        return value * factor;
    };
}
```

Usage:

```cpp
auto triple = makeMultiplier(3);

cout << triple(10);
```

Output:

```text
30
```

The returned closure owns its copy of `factor`, so this is safe.

---

## 19. Dangerous returned reference capture

This is dangerous:

```cpp
auto makeBadLambda() {
    int local = 10;

    return [&local]() {
        return local;
    };
}
```

When `makeBadLambda()` returns:

```text
local is destroyed
```

but the lambda still attempts to refer to it.

Calling the lambda later produces undefined behavior.

Rule:

```text
A lambda capturing by reference must not outlive the captured object.
```

This is one of the most important lambda lifetime rules.

---

## 20. Init-capture

Modern C++ allows a capture to initialize its own closure member:

```cpp
int value = 10;

auto lambda = [copy = value]() {
    return copy;
};
```

The capture name does not have to match the outside variable.

You can also compute a value:

```cpp
auto lambda = [factor = value * 2](int x) {
    return factor * x;
};
```

This feature was introduced in C++14 and is available in C++17.

---

## 21. Why init-capture matters

Init-capture can:

- rename captured values
- capture computed expressions
- prepare closure-local state
- move objects into a closure

The move-related case becomes more meaningful after the move-semantics
lesson.

For now:

```cpp
[limit = base + offset]
```

is enough to understand the syntax.

---

## 22. Generic lambdas

Since C++14, lambda parameters can use `auto`:

```cpp
auto add = [](auto a, auto b) {
    return a + b;
};
```

Usage:

```cpp
add(2, 3);
add(2.5, 1.5);
```

This behaves somewhat like a tiny function template.

Conceptually, the closure's call operator is templated.

---

## 23. Generic lambda requirements

This lambda:

```cpp
[](const auto& a, const auto& b) {
    return a < b;
}
```

can work for types supporting the needed `<` operation.

As with ordinary templates, `auto` in a generic lambda does not mean
every imaginable type must work.

The operations in the body impose requirements.

---

# Part II — Lambdas and Algorithms

## 24. Lambdas are excellent algorithm predicates

Suppose:

```cpp
std::vector<int> values = {
    1, 2, 3, 4, 5, 6
};
```

You can count even numbers:

```cpp
int count = std::count_if(
    values.begin(),
    values.end(),
    [](int value) {
        return value % 2 == 0;
    }
);
```

The predicate is written next to the algorithm that uses it.

---

## 25. Custom sorting

Suppose we want descending order:

```cpp
std::sort(
    values.begin(),
    values.end(),
    [](int a, int b) {
        return a > b;
    }
);
```

The lambda acts as the comparison function.

For sorting, the comparator must obey the required strict weak
ordering rules.

For a simple integer descending comparator:

```cpp
a > b
```

does.

---

## 26. Comparator mistake: using `>=`

This is a common mistake:

```cpp
[](int a, int b) {
    return a >= b;
}
```

For equal values:

```text
comp(a, a) == true
```

which violates the strict ordering requirement expected by sorting
algorithms.

Use:

```cpp
a > b
```

for descending order, not `>=`.

---

## 27. Sorting objects by a field

Suppose:

```cpp
struct Student {
    string name;
    int marks;
};
```

Sort descending by marks:

```cpp
sort(
    students.begin(),
    students.end(),
    [](const Student& a, const Student& b) {
        return a.marks > b.marks;
    }
);
```

Using:

```cpp
const Student&
```

avoids copying students during each comparison merely to receive
arguments.

---

## 28. Capture in predicates

Suppose we need to count values above a runtime threshold:

```cpp
int threshold = 10;
```

Lambda:

```cpp
[threshold](int value) {
    return value > threshold;
}
```

Now the predicate carries the threshold it needs.

This is a major advantage over plain function pointers.

---

# Part III — `std::function`

## 29. Storing callables behind one type

Different lambdas have different closure types.

Sometimes we need one common wrapper type.

C++ provides:

```cpp
std::function
```

Example:

```cpp
std::function<int(int, int)> operation;
```

This means:

```text
a callable
taking (int, int)
returning int
```

Then:

```cpp
operation = [](int a, int b) {
    return a + b;
};
```

and later:

```cpp
operation(2, 3);
```

---

## 30. Why not always use `std::function`?

`std::function` provides convenient type erasure, but it can involve:

- extra indirection
- potentially dynamic allocation depending on callable/storage
- less optimization opportunity than directly templated callable use

For generic algorithms, accepting the callable as a template parameter
is often preferable.

Use `std::function` when you actually need a uniform runtime-storable
callable type.

---

## 31. Stateless lambda and function pointer

A non-capturing lambda can convert to a compatible ordinary function
pointer.

Example:

```cpp
int (*operation)(int, int) =
    [](int a, int b) {
        return a + b;
    };
```

A capturing lambda cannot generally convert to such a plain function
pointer because it carries state.

Compare:

```text
[]       -> no captured state
[factor] -> closure carries factor
```

---

# Part IV — Lambdas and Classes

## 32. Capturing `this`

Inside a non-static member function:

```cpp
[this]() {
    return value;
}
```

captures the current object through its `this` pointer.

In C++17, `[=]` inside a member function can implicitly capture `this`
when needed, but making object dependency explicit is often clearer.

Example:

```cpp
class Counter {
private:
    int value = 10;

public:
    void show() const {
        auto lambda = [this]() {
            return value;
        };

        cout << lambda();
    }
};
```

---

## 33. Lifetime danger with `this`

Capturing `this` stores access to the object.

If the lambda survives after that object is destroyed, using the
captured pointer is dangerous.

Conceptually:

```text
lambda ----> object

object destroyed

lambda ----> dangling pointer
```

The same core lifetime rule applies:

```text
A captured reference/pointer must remain valid while the lambda uses it.
```

---

## 34. Capturing `*this` in C++17

C++17 supports:

```cpp
[*this]
```

which captures a copy of the current object rather than merely the
`this` pointer.

This can be useful when a closure should own a snapshot.

Copying the whole object may be expensive, and copy semantics still
matter, so use it deliberately.

---

## 35. Lambdas and `mutable` with copied `*this`

A copied object captured with:

```cpp
[*this]
```

belongs to the closure.

To modify that copy inside the lambda, `mutable` may be needed.

Again, this does not modify the original object unless the design
contains some separate shared/reference state.

---

# Part V — Immediately Invoked Lambdas

## 36. Calling a lambda immediately

You can create and invoke a lambda in one expression:

```cpp
int result = [](int a, int b) {
    return a + b;
}(3, 4);
```

The final:

```cpp
(3, 4)
```

calls the lambda immediately.

This style is sometimes called an immediately invoked lambda
expression.

---

## 37. Useful initialization pattern

Suppose a value needs multi-step initialization:

```cpp
const int result = [&]() {
    if (condition) {
        return 10;
    }

    return 20;
}();
```

The lambda lets `result` remain const while initialization logic stays
local.

Do not overuse this where a normal function or simple conditional would
be clearer.

---

# Part VI — Complexity and Design

## 38. A lambda does not change Big-O by itself

This:

```cpp
[](int x) {
    return x * x;
}
```

performs O(1) work.

This:

```cpp
[&values]() {
    for (int x : values) {
        // ...
    }
}
```

may perform O(n) work.

A lambda is syntax for a callable object.

The body determines algorithmic complexity.

---

## 39. Capture costs

Value captures store state in the closure.

If you capture a large object by value:

```cpp
[largeObject]
```

creating the closure may copy that object.

Reference capture:

```cpp
[&largeObject]
```

avoids the object copy but creates a lifetime dependency.

Neither form is automatically "better."

Choose according to ownership, lifetime, and semantics.

---

## 40. DSA uses

Lambdas become particularly useful for:

```text
custom sorting
priority queue comparators
binary search predicates
DFS recursion helpers
filtering
STL algorithms
custom ordering of pairs/nodes
local validation predicates
sweep-line event ordering
```

You will see them repeatedly later in the roadmap.

---

## Complexity table

| Operation | Time | Extra space |
|---|---:|---:|
| Call fixed-work lambda | O(1) | O(1) |
| Capture primitive by value | O(1) | O(1) |
| Capture large object of size n by value | O(n) copy cost | O(n) closure state |
| Capture object by reference | O(1) | O(1) |
| Invoke predicate for n elements | O(n) if each call is O(1) | O(1) auxiliary |
| Sort n values with comparator | O(n log n) comparisons typical | Algorithm-dependent |
| Lambda traversing n values | O(n) | Depends on body |
| `std::function` invocation | O(1) dispatch conceptually | Implementation-dependent |

Always include the complexity of captured-object copies and work inside
the lambda when relevant.

---

## Common interview and beginner mistakes

1. Thinking a lambda is dynamically typed.

2. Forgetting the capture list:

```cpp
[]
```

3. Trying to use an uncaptured automatic local variable.

4. Expecting value capture to observe later changes to the original
   variable.

5. Expecting a `mutable` value capture to modify the original variable.

6. Capturing a local variable by reference and returning the lambda.

7. Capturing `this` and allowing the lambda to outlive the object.

8. Using `[&]` everywhere without considering lifetime.

9. Using `[=]` everywhere and accidentally copying large objects.

10. Forgetting that different lambda expressions have distinct closure
    types.

11. Assuming every capturing lambda converts to a function pointer.

12. Using `>=` or `<=` as a `std::sort` comparator and violating strict
    weak ordering.

13. Copying large objects in comparator parameters rather than using
    `const&`.

14. Wrapping every lambda in `std::function` when a template or `auto`
    is enough.

15. Forgetting `mutable` when intentionally modifying value-captured
    closure state.

16. Assuming lambdas automatically make an algorithm faster.

---

## Practice questions and references

1. GeeksforGeeks — Lambda Expressions in C++  
   https://www.geeksforgeeks.org/lambda-expression-in-c/

2. cppreference — Lambda expressions  
   https://en.cppreference.com/w/cpp/language/lambda

3. LeetCode 2418 — Sort the People  
   https://leetcode.com/problems/sort-the-people/

4. LeetCode 1636 — Sort Array by Increasing Frequency  
   https://leetcode.com/problems/sort-array-by-increasing-frequency/

5. LeetCode 1356 — Sort Integers by The Number of 1 Bits  
   https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

For the LeetCode problems, use a lambda comparator where appropriate.
Some solutions rely on STL facilities that receive much deeper coverage
later.

---

## Revision checklist

Before moving on, make sure you can explain:

- lambda syntax
- closure objects
- closure types
- empty captures
- capture by value
- capture by reference
- `[=]`
- `[&]`
- mixed captures
- `mutable`
- init-capture
- generic lambdas
- lambda return-type deduction
- passing lambdas to templates
- returning value-capturing lambdas
- dangling reference captures
- lambdas with `sort`
- strict comparator requirements
- `std::function`
- stateless lambda conversion to function pointer
- `[this]`
- `[*this]`
- immediately invoked lambdas
- lambda complexity

# What's Next

Continue to:

`01_C++__/30_SMART_POINTERS_AND_RAII/`

The next lesson introduces ownership, RAII, `std::unique_ptr`,
`std::shared_ptr`, `std::weak_ptr`, automatic cleanup, custom
deleters, ownership cycles, and why modern C++ usually avoids raw
owning pointers.
