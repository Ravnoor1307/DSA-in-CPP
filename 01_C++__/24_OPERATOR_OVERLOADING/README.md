# 24 — Operator Overloading

## Learning goals

C++ lets user-defined types participate in operator syntax when that
syntax gives the type a natural meaning.

By the end of this lesson, you should understand:

- what operator overloading is
- why operators should preserve intuitive meaning
- member versus non-member operator functions
- friend operators
- arithmetic operators
- comparison operators
- compound assignment
- prefix and postfix increment
- stream insertion `<<`
- stream extraction `>>`
- subscript `[]`
- function-call `()`
- const and non-const subscript overloads
- operators that must be members
- operators that cannot be overloaded
- limitations of operator overloading
- why precedence, associativity, and operand count do not change
- conversion-related pitfalls
- assignment-operator basics
- `operator->` and `operator*` conceptually
- how operator overloading appears in DSA and STL-style classes

---

## 1. What is operator overloading?

You already use operators with built-in types:

```cpp
int a = 10;
int b = 20;

int c = a + b;
```

The meaning of:

```cpp
a + b
```

is already defined for integers.

Suppose we create:

```cpp
class Point {
private:
    int x;
    int y;
};
```

It may be natural for:

```cpp
Point c = a + b;
```

to mean coordinate-wise addition:

```text
c.x = a.x + b.x
c.y = a.y + b.y
```

C++ lets a class define such operator behavior.

---

## 2. Operators are special functions

An overloaded operator is implemented as a function with a special
name.

For `+`:

```cpp
operator+
```

Example:

```cpp
Point operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}
```

Then:

```cpp
Point c = a + b;
```

can conceptually correspond to:

```cpp
Point c = a.operator+(b);
```

for this member implementation.

---

## 3. Real-world analogy

Think of the symbol `+`.

For numbers:

```text
3 + 5 -> numerical addition
```

For a mathematical vector:

```text
(2, 3) + (4, 1) -> (6, 4)
```

The symbol remains associated with an addition-like concept, but the
details depend on the type.

Good operator overloads follow the meaning programmers already expect.

A surprising overload such as:

```text
a + b deletes a file
```

would be legal in some artificial design but extremely poor API
design.

---

## 4. Basic member operator

Example:

```cpp
class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y)
        : x(x), y(y) {
    }

    Point operator+(const Point& other) const {
        return Point(
            x + other.x,
            y + other.y
        );
    }
};
```

Given:

```cpp
Point a(2, 3);
Point b(5, 4);

Point c = a + b;
```

dry run:

```text
a = (2, 3)
b = (5, 4)

x coordinate:
2 + 5 = 7

y coordinate:
3 + 4 = 7

c = (7, 7)
```

---

## 5. Why parameters often use `const T&`

For:

```cpp
Point operator+(const Point& other) const
```

the parameter is a const reference.

This means:

- no unnecessary full object copy just to receive the argument
- the operator promises not to modify `other`

The trailing `const` means the left-hand object is also not modified.

Therefore ordinary `+` behaves like a read-only operation on both
operands.

That matches normal expectations.

---

## 6. `+` versus `+=`

These usually communicate different semantics.

`+` generally creates a result:

```cpp
c = a + b;
```

without modifying `a` or `b`.

`+=` normally changes the left operand:

```cpp
a += b;
```

A typical implementation is:

```cpp
Point& operator+=(const Point& other) {
    x += other.x;
    y += other.y;
    return *this;
}
```

Returning `*this` by reference allows chaining patterns and matches
conventional compound-assignment behavior.

---

## 7. Building `+` from `+=`

A useful design is:

```cpp
Point& operator+=(const Point& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

friend Point operator+(Point lhs, const Point& rhs) {
    lhs += rhs;
    return lhs;
}
```

Why is `lhs` passed by value?

Because `+` needs a new result anyway.

Dry run:

```text
a = (1, 2)
b = (3, 4)

lhs is initialized as a copy of a:
lhs = (1, 2)

lhs += b:
lhs = (4, 6)

return lhs
```

This centralizes the addition logic inside `+=`.

---

## 8. Member versus non-member operators

Operators can often be implemented as member functions or non-member
functions.

Member:

```cpp
class Number {
public:
    Number operator+(const Number& rhs) const;
};
```

Usage conceptually resembles:

```cpp
a.operator+(b)
```

Non-member:

```cpp
Number operator+(const Number& lhs, const Number& rhs);
```

Conceptually:

```cpp
operator+(a, b)
```

Neither approach is universally superior.

The correct design depends on the operator and desired conversions.

---

## 9. Why symmetric binary operators are often non-members

Consider a type:

```cpp
class Distance {
public:
    Distance(int meters);
};
```

If `operator+` is only a member, the left operand has a special role.

A non-member operator can often treat both operands more symmetrically,
which can matter when implicit conversions are involved.

For mathematical binary operations, non-member operators are therefore
common.

Friendship may be used when direct access to private representation is
appropriate.

---

## 10. Friend operator

Example:

```cpp
class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y)
        : x(x), y(y) {
    }

    friend Point operator+(
        const Point& a,
        const Point& b
    );
};
```

Definition:

```cpp
Point operator+(
    const Point& a,
    const Point& b
) {
    return Point(
        a.x + b.x,
        a.y + b.y
    );
}
```

The operator is not a member function.

Friendship merely grants it access to private members.

---

## 11. Comparison operators

A class can define equality:

```cpp
bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
}
```

Then:

```cpp
if (a == b) {
}
```

has a meaningful interpretation.

For C++17, if you want `!=`, define it explicitly:

```cpp
bool operator!=(const Point& other) const {
    return !(*this == other);
}
```

Later language versions add additional comparison facilities, but this
repository targets C++17.

---

## 12. Ordering must have a clear meaning

What should this mean?

```cpp
pointA < pointB
```

Possible definitions include:

```text
compare x first, then y
compare distance from origin
compare some ID
```

There is no universally obvious answer.

Do not overload `<` unless your type has a clearly documented ordering.

An arbitrary ordering can cause difficult bugs when objects are later
used with ordered data structures.

---

## 13. Prefix increment

Built-in integers support:

```cpp
++x;
```

For a user-defined type:

```cpp
Counter& operator++() {
    ++value;
    return *this;
}
```

This is prefix increment.

There is no dummy integer parameter.

Conventional behavior:

```text
increment object
return updated object/reference
```

---

## 14. Postfix increment

Postfix uses:

```cpp
x++;
```

Its overload has a dummy `int` parameter:

```cpp
Counter operator++(int) {
    Counter old = *this;
    ++(*this);
    return old;
}
```

The integer parameter is not normal user data.

Its purpose is to distinguish postfix syntax from prefix syntax.

Conceptually:

```text
old = current state
increment current object
return old state
```

---

## 15. Prefix versus postfix dry run

Suppose:

```text
counter.value = 5
```

Prefix:

```cpp
result = ++counter;
```

Flow:

```text
counter.value: 5 -> 6
result sees value 6
```

Postfix:

```cpp
result = counter++;
```

starting from 6:

```text
save old value 6
counter.value: 6 -> 7
return saved old state

result = 6
counter = 7
```

This distinction matters for iterator-like types later.

---

## 16. Stream insertion `<<`

For built-in types:

```cpp
cout << value;
```

For your class, you can overload stream insertion:

```cpp
friend ostream& operator<<(
    ostream& out,
    const Point& point
) {
    out << '('
        << point.x
        << ", "
        << point.y
        << ')';

    return out;
}
```

Then:

```cpp
cout << point;
```

works naturally.

---

## 17. Why return `ostream&`?

Consider:

```cpp
cout << a << b << '\n';
```

The first operation must return the stream so the next `<<` can
continue using it.

Conceptually:

```text
cout << a
    |
    v
returns cout
    |
    v
cout << b
```

Therefore the usual signature returns:

```cpp
ostream&
```

---

## 18. Why `operator<<` is usually not a member of your class

The expression is:

```cpp
cout << point
```

The left operand is:

```text
cout
```

whose type is `ostream`.

Your `Point` class is the right operand.

Making stream insertion a non-member, often a friend, naturally
supports this syntax.

---

## 19. Stream extraction `>>`

Input can also be overloaded:

```cpp
friend istream& operator>>(
    istream& in,
    Point& point
) {
    in >> point.x >> point.y;
    return in;
}
```

The `Point` is non-const because input modifies it.

Usage:

```cpp
cin >> point;
```

Be careful when input values must satisfy invariants.

Reading directly into private fields and leaving an invalid object is
bad design.

Validation should still be considered.

---

## 20. Subscript operator `[]`

A container-like class may naturally support:

```cpp
object[index]
```

Example:

```cpp
int& operator[](int index) {
    return values[index];
}
```

For const objects:

```cpp
const int& operator[](int index) const {
    return values[index];
}
```

The pair allows:

```cpp
array[0] = 10;
```

for mutable objects while preventing modification through a const
object.

---

## 21. `[]` and bounds checking

An overloaded `operator[]` does not automatically check bounds.

If your implementation is:

```cpp
return values[index];
```

then an invalid index can still cause undefined behavior.

You decide whether the abstraction should:

- leave `[]` unchecked
- validate and report errors
- provide a separate checked method

STL containers often distinguish unchecked `operator[]` from checked
methods such as `at()`.

Exceptions receive a later lesson.

---

## 22. Function-call operator `()`

A class can behave syntactically like a callable object:

```cpp
class Multiplier {
private:
    int factor;

public:
    Multiplier(int factor)
        : factor(factor) {
    }

    int operator()(int value) const {
        return factor * value;
    }
};
```

Usage:

```cpp
Multiplier triple(3);

cout << triple(10);
```

prints:

```text
30
```

An object that implements `operator()` is commonly called a function
object or functor.

Functors become useful with STL algorithms.

---

## 23. Assignment operator

Classes also have assignment operators.

Conceptually:

```cpp
a = b;
```

may invoke:

```cpp
a.operator=(b);
```

For simple value-member classes, compiler-generated copy assignment
is often sufficient.

A conventional user-defined copy assignment signature is:

```cpp
Type& operator=(const Type& other);
```

Resource-owning classes require considerably more care.

Those concerns connect to:

- copy construction
- destructors
- RAII
- move semantics

Later lessons develop these topics further.

---

## 24. Self-assignment

A user-defined assignment operation may encounter:

```cpp
object = object;
```

This is self-assignment.

Simple member-wise assignments often naturally tolerate it.

Resource-management implementations may need deliberate handling.

For example:

```cpp
if (this == &other) {
    return *this;
}
```

You should understand the concept, but avoid writing manual resource
management unless it is actually necessary.

---

## 25. `operator*` and `operator->`

Pointer-like classes can overload operators such as:

```cpp
operator*
operator->
```

This is important in smart pointer classes.

Example conceptually:

```cpp
pointer->member
*pointer
```

Later, `30_SMART_POINTERS_AND_RAII` explores smart pointers in the
proper ownership context.

This lesson focuses on recognizing that pointer-like operator syntax
can also be customized.

---

## 26. Operators that must be members

Some operators must be overloaded as non-static member functions.

Important examples include:

```text
operator=
operator[]
operator()
operator->
```

C++ also has additional operators with member-only requirements, but
these are the most relevant at this stage.

Stream `<<` and `>>` for your own type are normally non-member
functions because the stream is the left operand.

---

## 27. Operators that cannot be overloaded

C++ does not allow overloading every operator.

Important examples that cannot be overloaded include:

```text
::
.
.*
?:
sizeof
```

You cannot invent completely new operator symbols either.

For example, you cannot create:

```text
**
```

as a custom exponent operator.

---

## 28. You cannot change operator arity

If an operator is binary in the relevant syntax, overloading does not
turn it into an arbitrary three-operand operation.

Example:

```cpp
a + b
```

still has two operands.

Operator overloading customizes behavior for user-defined types; it
does not redefine the grammar of C++.

---

## 29. Precedence does not change

Suppose a class overloads:

```text
+
*
```

This:

```cpp
a + b * c
```

still follows normal C++ precedence:

```cpp
a + (b * c)
```

Overloading cannot make `+` bind more strongly than `*`.

---

## 30. Associativity does not change

Normal operator associativity is preserved.

Overloading does not let you redefine how the parser groups an
operator expression.

Again, operator overloading changes operator behavior for types, not
the language grammar.

---

## 31. At least one operand must involve a user-defined type

You cannot redefine how ordinary built-in integer addition works:

```cpp
int + int
```

to mean something completely different.

Operator overloading is intended for user-defined types.

For example:

```cpp
Point + Point
Point + int
int + Point
```

may be candidates when properly defined.

---

## 32. Member versus friend dry run

Suppose member addition:

```cpp
a + b
```

uses:

```cpp
a.operator+(b)
```

Then:

```text
current object = a
parameter      = b
```

With non-member addition:

```cpp
operator+(a, b)
```

both operands are explicit parameters:

```text
lhs = a
rhs = b
```

This difference influences API design and conversion behavior.

---

## 33. Avoid surprising semantics

A type should obey programmer expectations.

Good examples:

```text
Vector + Vector -> vector addition
Money + Money   -> monetary addition
Point == Point  -> equality of point state
Counter++       -> increment counter
```

Potentially surprising examples:

```text
a + b modifies both a and b
x == y modifies x
counter++ deletes an external resource
```

Legal syntax is not the same as good design.

---

## 34. Operator overloading in DSA

You will encounter overloaded operators in:

- priority queue custom element types
- ordered sets/maps
- iterators
- custom heap nodes
- coordinates
- graph-state objects
- sorting/comparison helpers
- function objects
- smart pointers

Understanding operator syntax makes STL code significantly easier to
read later.

---

## 35. Complexity

Operator syntax does not determine complexity.

This:

```cpp
a + b
```

could be O(1) for a two-integer `Point`.

For a large custom array, an overloaded `+` that processes every
element could be O(n).

Similarly:

```cpp
a == b
```

could be:

```text
O(1) for two fixed-size values
O(n) for sequences of n values
```

Always analyze the implementation, not the symbol.

---

## Complexity table

| Example | Time | Extra space |
|---|---:|---:|
| `Point + Point` with two ints | O(1) | O(1) |
| `Point += Point` | O(1) | O(1) |
| Fixed-size equality | O(1) | O(1) |
| Sequence equality of n items | O(n) | O(1) |
| Prefix increment of one int field | O(1) | O(1) |
| Postfix increment of fixed-size object | O(1) | O(1) |
| Array-like `operator[]` | O(1) | O(1) |
| Stream fixed number of members | O(1) conceptually | O(1) auxiliary |
| Add two custom arrays of n items | O(n) | O(n) for result |

Stream operations have real system/library costs; the table focuses on
the number of represented class elements processed.

---

## Common interview and beginner mistakes

1. Overloading operators with surprising meanings.

2. Making `operator+` modify the operands unexpectedly.

3. Forgetting `const` on read-only operators.

4. Passing large right-hand operands by value without reason.

5. Returning a reference to a local result.

6. Forgetting to return `*this` from compound assignment.

7. Confusing prefix and postfix `++`.

8. Forgetting the dummy `int` parameter for postfix increment.

9. Returning `void` from `operator<<` and breaking chaining.

10. Making stream insertion a member of the right-hand class and
    expecting `cout << object` to work naturally.

11. Forgetting a non-const overload of `[]` when mutation is needed.

12. Assuming `operator[]` automatically checks bounds.

13. Assuming operator precedence can be changed.

14. Assuming operator associativity can be changed.

15. Trying to overload operators such as `.` or `::`.

16. Trying to redefine operations involving only built-in operands.

17. Defining an arbitrary `<` ordering without documenting its
    semantics.

18. Forgetting object slicing/copying costs when operator parameters
    and results are passed by value.

19. Writing complicated manual assignment logic before understanding
    ownership and RAII.

---

## Practice questions and references

1. GeeksforGeeks — Operator Overloading in C++  
   https://www.geeksforgeeks.org/operator-overloading-cpp/

2. GeeksforGeeks — Overloading Stream Insertion and Extraction  
   https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/

3. GeeksforGeeks — Increment and Decrement Operator Overloading  
   https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/

4. HackerRank — Operator Overloading  
   https://www.hackerrank.com/challenges/overloading-ostream-operator/problem

5. HackerRank — Overload Operators  
   https://www.hackerrank.com/challenges/overload-operators/problem

---

## Revision checklist

Before moving on, make sure you can explain:

- what operator overloading means
- member versus non-member operators
- friend operators
- `+` versus `+=`
- equality operators
- prefix versus postfix `++`
- `operator<<`
- `operator>>`
- `operator[]`
- const/non-const `[]`
- `operator()`
- copy-assignment basics
- operators that must be members
- operators that cannot be overloaded
- why precedence and associativity remain unchanged
- why overloaded operators should preserve intuitive semantics
- why complexity depends on implementation rather than operator syntax

# What's Next

Continue to:

`01_C++__/25_TEMPLATES/`

The next lesson introduces function templates, class templates,
template parameters, type deduction, explicit template arguments,
specialization basics, non-type template parameters, and generic
programming.
