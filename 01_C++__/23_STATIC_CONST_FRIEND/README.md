# 23 — `static`, `const`, and `friend` in C++

## Learning goals

This lesson brings together three important class-related C++ features:

- `static`
- `const`
- `friend`

By the end, you should understand:

- ordinary versus static data members
- static member functions
- class-wide shared state
- accessing static members through the class name
- `inline static` members in C++17
- static member definition basics
- local static variables inside member functions
- const objects
- const data members
- const member functions
- const overloads
- returning const references
- `mutable`
- logical constness
- static const and compile-time class constants
- friend functions
- friend classes
- friendship direction and non-transitivity
- why friendship should be used deliberately
- common interview traps involving `static`, `const`, and `friend`

---

## 1. Ordinary object state versus class-wide state

Consider:

```cpp
class Player {
public:
    int score = 0;
};
```

If we create:

```cpp
Player a;
Player b;
```

then each object has its own `score`.

Conceptually:

```text
a
+-----------+
| score = 0 |
+-----------+

b
+-----------+
| score = 0 |
+-----------+
```

Changing:

```cpp
a.score = 100;
```

does not change `b.score`.

These are ordinary non-static data members.

Sometimes, however, one value should belong to the class as a whole.

For example:

```text
How many Player objects currently exist?
```

This is where a static data member can help.

---

## 2. Static data members

A static data member is associated with the class rather than stored
as a separate ordinary member in each object.

Example:

```cpp
class Player {
public:
    inline static int count = 0;
};
```

C++17's `inline static` syntax lets us define and initialize the
member directly in the class definition.

Usage:

```cpp
Player::count
```

Conceptually:

```text
Player class
    |
    +---- shared count

object a ---- ordinary object state
object b ---- ordinary object state
object c ---- ordinary object state
```

There is one `count` variable shared by the class.

---

## 3. Real-world analogy for static members

Imagine students in a classroom.

Each student has an individual:

```text
name
roll number
marks
```

But all students may share a class-wide value such as:

```text
school name
```

An ordinary member resembles the personal information.

A static member resembles information belonging to the class as a
whole.

---

## 4. Counting live objects

A common demonstration is an object counter:

```cpp
class Tracker {
private:
    inline static int count = 0;

public:
    Tracker() {
        ++count;
    }

    ~Tracker() {
        --count;
    }

    static int getCount() {
        return count;
    }
};
```

Suppose:

```cpp
Tracker a;
Tracker b;
```

Dry run:

```text
Initial:
count = 0

construct a:
count = 1

construct b:
count = 2

destroy b:
count = 1

destroy a:
count = 0
```

The count is shared across all objects.

For a complete real-world tracker, copy/move behavior must also be
designed correctly because every way an object is created affects
what "count" means.

---

## 5. Pre-C++17 style static definition

You may encounter:

```cpp
class Counter {
public:
    static int count;
};

int Counter::count = 0;
```

The declaration appears inside the class and the definition appears
outside it.

For this C++17 repository, `inline static` is often convenient:

```cpp
class Counter {
public:
    inline static int count = 0;
};
```

Both forms are worth recognizing.

---

## 6. Accessing static members

Prefer class-qualified access:

```cpp
Counter::count
```

rather than:

```cpp
object.count
```

C++ may permit access through an object in many cases, but:

```cpp
Counter::count
```

more clearly communicates that the value belongs to the class rather
than to one particular object.

---

## 7. Static member functions

A member function can also be `static`:

```cpp
class Counter {
private:
    inline static int count = 0;

public:
    static int getCount() {
        return count;
    }
};
```

Call it with:

```cpp
Counter::getCount();
```

A static member function does not run for a particular object.

Therefore it has no ordinary `this` pointer.

---

## 8. Why static member functions cannot directly use ordinary members

Consider:

```cpp
class Example {
private:
    int value = 10;

public:
    static void show() {
        // cout << value; // ERROR
    }
};
```

Which object's `value` should `show()` use?

There may be:

```text
object a -> value = 10
object b -> value = 50
object c -> value = 99
```

A static member function has no current object, so there is no implicit
answer.

It can directly access static members because they are class-wide.

---

## 9. Static local variables in member functions

Do not confuse a static data member with a local static variable.

Example:

```cpp
class Demo {
public:
    void call() const {
        static int calls = 0;
        ++calls;

        cout << calls << '\n';
    }
};
```

`calls` is local to the function's scope, but its lifetime lasts until
program termination.

Multiple calls reuse the same variable.

Conceptually:

```text
call #1 -> calls becomes 1
call #2 -> calls becomes 2
call #3 -> calls becomes 3
```

This also happens when calls come from different objects.

---

## 10. Static initialization and lifetime

Static-storage-duration objects generally exist for the lifetime of
the program once initialized according to C++ initialization rules.

Their lifetime differs from ordinary local automatic objects.

Ordinary local:

```cpp
{
    Counter c;
}
```

typically dies when its block ends.

Static local:

```cpp
static Counter c;
```

is initialized on first passage through its declaration and remains
alive until program termination.

This can be useful, but static state should not be introduced without
reason because shared mutable state can make code harder to understand.

---

# Part II — `const`

## 11. Const objects

A const object cannot normally be modified after initialization.

```cpp
const int value = 10;
```

For class types:

```cpp
const Point point(3, 4);
```

The object may call member functions that promise to respect its
constness.

That promise is expressed with const member functions.

---

## 12. Const member functions

Consider:

```cpp
class Point {
private:
    int x;

public:
    int getX() const {
        return x;
    }
};
```

The trailing:

```cpp
const
```

is part of the member function declaration.

It means the function promises not to modify ordinary non-mutable
state through the current object.

Therefore:

```cpp
const Point p(...);
p.getX();
```

is valid.

---

## 13. `const` before versus after a function

These mean different things:

```cpp
const string& getName() const;
```

The first `const`:

```text
const string&
```

belongs to the return type.

The second `const`:

```text
getName() const
```

qualifies the member function.

Read it approximately as:

```text
Return a reference to const string,
and do not modify this object through this member function.
```

---

## 14. Why const-correctness matters

Suppose:

```cpp
void printAccount(const Account& account) {
    cout << account.getBalance();
}
```

Since `account` is const inside the function, it can call const member
functions.

If:

```cpp
getBalance()
```

were not const-qualified, the call would fail.

Const-correctness communicates intent and prevents accidental state
changes.

It is especially common when passing objects as:

```cpp
const Type&
```

---

## 15. Const member functions and `this`

Inside an ordinary non-const member function, think approximately of:

```text
this -> pointer to current object
```

Inside a const member function, the current object is treated through
a pointer-to-const view conceptually similar to:

```cpp
const Type* const this
```

The exact language treatment of `this` has details beyond this
simplification, but the useful mental model is:

```text
const member function
-> cannot modify ordinary data members through this
```

---

## 16. Const and non-const overloads

C++ allows member functions to differ by const qualification.

Example:

```cpp
class Box {
public:
    int& value() {
        return data;
    }

    const int& value() const {
        return data;
    }

private:
    int data = 0;
};
```

For:

```cpp
Box box;
```

the non-const version can be selected.

For:

```cpp
const Box box;
```

the const version is selected.

This pattern becomes particularly useful in containers.

---

## 17. Returning a const reference

Suppose:

```cpp
class Person {
private:
    string name;

public:
    const string& getName() const {
        return name;
    }
};
```

Returning:

```cpp
const string&
```

avoids copying the stored string and prevents callers from modifying
that string through the returned reference.

However, the reference remains tied to the object's lifetime.

This is dangerous:

```cpp
const string& ref = someObject.getName();
```

if `someObject` is destroyed while `ref` is still used.

Never return a reference to a local variable either.

---

## 18. Const data members

A data member itself can be const:

```cpp
class Employee {
private:
    const int id;

public:
    Employee(int id)
        : id(id) {
    }
};
```

As learned in the constructor lesson, a const data member must be
initialized rather than assigned later.

This is why the member initializer list is required.

---

## 19. `mutable`

Sometimes a member represents internal bookkeeping rather than the
logical value of an object.

C++ provides `mutable`:

```cpp
class Document {
private:
    string text;
    mutable int readCount = 0;

public:
    const string& read() const {
        ++readCount;
        return text;
    }
};
```

Although `read()` is const, it may modify `readCount` because that
member is mutable.

Use this carefully.

`mutable` should not become a way to bypass const-correctness
everywhere.

---

## 20. Logical constness

A const member function need not mean that absolutely no bit anywhere
can ever change.

The more useful design concept is often logical constness:

```text
Does this operation change the externally meaningful value/state of
the abstraction?
```

Examples of internally changing details may include:

- cache entries
- access counters
- lazily computed helper data

`mutable` can support such designs.

---

## 21. Class constants

A value shared by the class may be constant.

For integral compile-time constants you may see:

```cpp
class Buffer {
public:
    static const int SIZE = 10;
};
```

In modern C++17, another expressive option is:

```cpp
class Buffer {
public:
    inline static constexpr int SIZE = 10;
};
```

`constexpr` will appear again in later modern C++ material.

For now, recognize this as a convenient class-wide compile-time
constant.

---

# Part III — `friend`

## 22. The access problem

Private members normally cannot be accessed directly from ordinary
non-member functions:

```cpp
class Box {
private:
    int value;
};

void inspect(const Box& box) {
    // box.value; // ERROR
}
```

Sometimes a carefully chosen external function or class needs special
access to an implementation.

C++ provides friendship.

---

## 23. Friend functions

A function can be declared as a friend:

```cpp
class Box {
private:
    int value = 42;

    friend void inspect(const Box& box);
};
```

Then:

```cpp
void inspect(const Box& box) {
    cout << box.value;
}
```

may access the private member.

Important:

`inspect` is still not a member function.

It does not receive a `this` pointer.

It simply receives special access permission.

---

## 24. Real-world analogy for friendship

Imagine a secure office.

The public entrance is available to ordinary visitors.

Employees have internal access.

A specific external auditor may receive a special access badge for an
inspection.

The auditor does not become an employee.

Likewise, a friend function does not become a class member; it receives
special access.

---

## 25. Friend classes

An entire class can be granted friendship:

```cpp
class Vault {
private:
    int code = 1234;

    friend class Inspector;
};
```

Now member functions of `Inspector` may access private and protected
members of `Vault`.

Example:

```cpp
class Inspector {
public:
    void inspect(const Vault& vault) const {
        cout << vault.code;
    }
};
```

Friend classes should be used intentionally because they increase
coupling between implementations.

---

## 26. Friendship is not symmetric

If:

```cpp
class A {
    friend class B;
};
```

then `B` may access appropriate private/protected members of `A`.

That does NOT mean `A` automatically gains access to private members
of `B`.

Conceptually:

```text
A trusts B
```

does not imply:

```text
B trusts A
```

---

## 27. Friendship is not automatically transitive

If:

```text
A trusts B
B trusts C
```

that does not mean:

```text
A trusts C
```

Friend access does not automatically pass through friendship chains.

---

## 28. Friendship is not inherited automatically

If a class is a friend, its derived classes do not automatically
receive the same friend privileges merely because they inherit from
the friend class.

Friendship is explicitly granted.

---

## 29. Friend declarations and encapsulation

Friendship does not mean encapsulation completely disappears.

The class itself explicitly chooses which external function or class
receives access.

However, friendship does weaken the normal access boundary.

Therefore prefer ordinary public interfaces when they naturally solve
the problem.

Use `friend` when the cooperating function/class is genuinely part of
the implementation relationship.

---

## 30. When friend functions are useful

Common situations include:

```text
closely cooperating classes
stream insertion/extraction operators
symmetric binary operators
testing/debugging helpers in some designs
specialized implementation utilities
```

Operator overloading is the next lesson, where friend functions become
especially relevant.

---

## 31. Dry run: shared static counter

Consider:

```cpp
class Object {
private:
    inline static int live = 0;

public:
    Object() {
        ++live;
    }

    ~Object() {
        --live;
    }
};
```

Execution:

```cpp
Object a;
```

State:

```text
live = 1
```

Enter nested block:

```cpp
{
    Object b;
    Object c;
}
```

States:

```text
construct b:
live = 2

construct c:
live = 3

destroy c:
live = 2

destroy b:
live = 1
```

At the end of the outer scope:

```text
destroy a:
live = 0
```

One static member records state associated with all live objects.

---

## 32. Dry run: const object

Suppose:

```cpp
class Number {
private:
    int value;

public:
    int get() const {
        return value;
    }

    void set(int x) {
        value = x;
    }
};
```

Given:

```cpp
const Number n(...);
```

Then:

```cpp
n.get();
```

is valid because:

```text
get() is const
```

but:

```cpp
n.set(5);
```

is invalid because:

```text
set() is non-const
```

The compiler prevents an operation that could modify a const object.

---

## 33. Dry run: friend function

Consider:

```cpp
class Secret {
private:
    int value = 99;

    friend void reveal(const Secret&);
};
```

Outside ordinary code:

```text
secret.value
```

is inaccessible.

Inside the specifically declared friend:

```cpp
void reveal(const Secret& secret) {
    cout << secret.value;
}
```

the access is permitted.

The friendship changes access control for that function; it does not
turn `value` public.

---

## 34. Static members and object size

A static data member is not stored as a separate ordinary member in
every object.

Consider:

```cpp
class Example {
private:
    int value;
    inline static int shared = 0;
};
```

Each object contains its own ordinary `value`.

`shared` is associated with the class and has separate static storage.

Do not reason that every object's `sizeof(Example)` includes another
copy of `shared`.

Padding and alignment still affect actual object size.

---

## 35. Static state and DSA

Static state occasionally appears in recursive or algorithmic code,
but use it with caution.

Example:

```cpp
int visit() {
    static int calls = 0;
    return ++calls;
}
```

The variable survives across calls.

That means running the same algorithm again may not start from fresh
state unless you explicitly reset it.

For reusable DSA functions, hidden static mutable state can therefore
cause surprising bugs.

Prefer local state or explicit object state unless persistence across
calls is truly part of the design.

---

## Complexity table

`static`, `const`, and `friend` are primarily language/design features.
They do not impose one universal algorithmic complexity.

| Operation | Typical time | Extra space |
|---|---:|---:|
| Read/write primitive static member | O(1) | O(1) |
| Call fixed-work static function | O(1) | O(1) |
| Read primitive through const getter | O(1) | O(1) |
| Friend access to one primitive member | O(1) | O(1) |
| Increment object counter | O(1) | O(1) |
| Return const reference | O(1) | O(1) |
| Copy returned object of size n | O(n) | Depends on object |
| Friend function traversing n items | O(n) | Depends on implementation |

Access control and constness do not change the Big-O complexity of the
underlying algorithm.

---

## Common interview and beginner mistakes

1. Thinking each object contains a separate copy of a static data
   member.

2. Calling static members object-specific state.

3. Trying to directly access an ordinary member from a static member
   function without an object.

4. Assuming a static member function has `this`.

5. Confusing a static local variable with a static data member.

6. Forgetting that static locals retain their value across calls.

7. Forgetting `const` after read-only member functions.

8. Thinking:

```cpp
const int get()
```

makes the member function const.

The member-function qualifier is:

```cpp
int get() const
```

9. Returning a reference to a local variable.

10. Keeping a returned internal reference after its owning object has
    been destroyed.

11. Using `mutable` merely to avoid proper const design.

12. Believing a friend function becomes a member function.

13. Assuming friendship is symmetric.

14. Assuming friendship is transitive.

15. Assuming friendship automatically extends to derived classes.

16. Making many unrelated classes friends and tightly coupling the
    implementation.

17. Using hidden static mutable state in algorithms that should be
    independent between calls.

---

## Practice questions and references

1. GeeksforGeeks — Static Data Members in C++  
   https://www.geeksforgeeks.org/cpp-static-data-members/

2. GeeksforGeeks — Static Member Function in C++  
   https://www.geeksforgeeks.org/static-member-function-in-cpp/

3. GeeksforGeeks — Const Member Functions  
   https://www.geeksforgeeks.org/const-member-functions-c/

4. GeeksforGeeks — Friend Class and Function  
   https://www.geeksforgeeks.org/friend-class-function-cpp/

5. HackerRank — Classes and Objects  
   https://www.hackerrank.com/challenges/classes-objects/problem

---

## Revision checklist

Before moving on, make sure you can explain:

- static data members
- `inline static` in C++17
- static member functions
- why static member functions have no `this`
- local static variables
- static storage lifetime
- const objects
- const member functions
- const/non-const overloads
- const data members
- returning const references
- `mutable`
- logical constness
- class-wide constants
- friend functions
- friend classes
- why friendship is not symmetric
- why friendship is not transitive
- why friendship should be used selectively

# What's Next

Continue to:

`01_C++__/24_OPERATOR_OVERLOADING/`

The next lesson explains how operators such as `+`, `==`, `[]`, `<<`,
prefix/postfix `++`, assignment, and function-call syntax can be given
meaning for user-defined types while preserving predictable operator
semantics.
