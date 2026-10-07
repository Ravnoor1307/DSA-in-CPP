# 19 — Constructors and Destructors

## Learning goals

This lesson explains how C++ objects are initialized and cleaned up.

By the end, you should understand:

- what constructors are
- when constructors execute
- default constructors
- parameterized constructors
- constructor overloading
- default arguments in constructors
- member initializer lists
- why initialization is different from assignment
- initialization order
- delegating constructors
- the first look at copy constructors
- what destructors are
- when destructors execute
- automatic object lifetime
- nested-scope destruction
- dynamic objects and `delete`
- arrays of objects
- constructor/destructor order
- basic resource ownership
- RAII foundations
- common constructor and destructor mistakes

Copy-control rules, smart pointers, and move semantics receive deeper treatment in later lessons.

---

## 1. The initialization problem

In the previous lesson, we often wrote code such as:

```cpp
BankAccount account;
account.setOwner("Asha");
account.deposit(1000);
```

The object exists before some of its meaningful state is configured.

That can be undesirable.

Suppose a class represents a rectangle that should always have a width and height.

Without a constructor:

```cpp
class Rectangle {
private:
    int width = 0;
    int height = 0;

public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
};
```

We might create:

```cpp
Rectangle r;
```

and forget to configure it.

Constructors let a class participate directly in object initialization.

---

## 2. What is a constructor?

A constructor is a special member function that runs when an object is initialized.

It has:

- the same name as the class
- no return type
- not even `void`

Example:

```cpp
class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle() {
        width = 1;
        height = 1;
    }
};
```

When:

```cpp
Rectangle r;
```

is executed, `Rectangle()` runs automatically.

Analogy:

Think of opening a new bank account.

The bank does not hand you an arbitrary record and ask you to manually repair every field. The account-creation process establishes its initial state.

A constructor plays a similar role for an object.

---

## 3. Default constructor

A constructor callable with no arguments is a default constructor.

```cpp
class Counter {
private:
    int value;

public:
    Counter() {
        value = 0;
    }
};
```

Usage:

```cpp
Counter c;
```

The constructor initializes `value`.

A constructor can also be defaulted explicitly:

```cpp
class Example {
public:
    Example() = default;
};
```

This asks the compiler to generate the corresponding default constructor when appropriate.

---

## 4. Compiler-generated default constructor

If you declare no constructor, C++ may implicitly declare a default constructor for you.

Example:

```cpp
class Point {
public:
    int x = 0;
    int y = 0;
};
```

Then:

```cpp
Point p;
```

works.

But an important rule appears when you declare your own constructor.

Consider:

```cpp
class Point {
public:
    int x;
    int y;

    Point(int a, int b) : x(a), y(b) {}
};
```

Now:

```cpp
Point p;
```

does not automatically work.

Once you declare a constructor such as the parameterized one above, do not assume C++ will also provide a no-argument constructor.

You could explicitly add one:

```cpp
Point() : x(0), y(0) {}
```

---

## 5. Parameterized constructors

Constructors can take parameters.

```cpp
class Point {
private:
    int x;
    int y;

public:
    Point(int xValue, int yValue) {
        x = xValue;
        y = yValue;
    }
};
```

Usage:

```cpp
Point p(3, 7);
```

or:

```cpp
Point p{3, 7};
```

The constructor receives:

```text
xValue = 3
yValue = 7
```

and establishes the object's initial state.

---

## 6. Constructor overloading

Just like ordinary functions, constructors can be overloaded.

```cpp
class Box {
private:
    int width;
    int height;

public:
    Box() {
        width = 1;
        height = 1;
    }

    Box(int side) {
        width = side;
        height = side;
    }

    Box(int w, int h) {
        width = w;
        height = h;
    }
};
```

Usage:

```cpp
Box a;
Box b(5);
Box c(4, 6);
```

The compiler selects a constructor based on the arguments.

Conceptually:

```text
Box a       -> Box()
Box b(5)    -> Box(int)
Box c(4, 6) -> Box(int, int)
```

---

## 7. Member initializer lists

A preferred way to initialize data members is a member initializer list.

Instead of:

```cpp
Point(int a, int b) {
    x = a;
    y = b;
}
```

write:

```cpp
Point(int a, int b)
    : x(a), y(b) {
}
```

The part:

```cpp
: x(a), y(b)
```

is the member initializer list.

This initializes the members directly.

---

## 8. Initialization versus assignment

These two approaches may appear similar:

```cpp
Example(int value) {
    data = value;
}
```

and:

```cpp
Example(int value)
    : data(value) {
}
```

but conceptually they are different.

First version:

```text
data is initialized
constructor body begins
data is assigned value
```

Second version:

```text
data is initialized directly with value
constructor body begins
```

For simple integers, the observable difference may be small.

For class-type members, initialization can avoid unnecessary default construction followed by assignment.

More importantly, some members must use an initializer list.

---

## 9. const members require initialization

Consider:

```cpp
class IdCard {
private:
    const int id;

public:
    IdCard(int value)
        : id(value) {
    }
};
```

You cannot correctly replace it with:

```cpp
IdCard(int value) {
    id = value; // ERROR
}
```

Why?

Because `id` is const. By the time the constructor body begins, members have already been initialized.

The constructor body is too late to assign a new value to a const member.

---

## 10. Reference members also require initialization

References must be bound when initialized.

```cpp
class RefHolder {
private:
    int& reference;

public:
    RefHolder(int& value)
        : reference(value) {
    }
};
```

Again, the initializer list is essential.

---

## 11. Initialization order

A subtle but important rule:

Members are initialized in the order they are DECLARED in the class, not the order written in the initializer list.

Example:

```cpp
class Example {
private:
    int first;
    int second;

public:
    Example()
        : second(20), first(10) {
    }
};
```

Actual initialization order is:

```text
first
second
```

because the declaration order is:

```cpp
int first;
int second;
```

Good practice is to write initializer-list entries in the same order as member declarations.

This improves readability and avoids bugs involving dependencies between members.

---

## 12. In-class member initializers

C++ also permits defaults directly in member declarations:

```cpp
class Player {
private:
    int health = 100;
    int score = 0;
};
```

Constructors can override these defaults:

```cpp
class Player {
private:
    int health = 100;

public:
    Player() = default;

    Player(int startingHealth)
        : health(startingHealth) {
    }
};
```

This can reduce duplication when multiple constructors share common defaults.

---

## 13. Delegating constructors

One constructor can delegate to another constructor of the same class.

```cpp
class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle()
        : Rectangle(1, 1) {
    }

    Rectangle(int side)
        : Rectangle(side, side) {
    }

    Rectangle(int w, int h)
        : width(w), height(h) {
    }
};
```

Flow for:

```cpp
Rectangle r(5);
```

is conceptually:

```text
Rectangle(int side)
        |
        v
Rectangle(int w, int h)
        |
        v
width = 5
height = 5
```

Delegation can keep initialization logic in one place.

---

## 14. Constructors can validate input

A constructor can enforce class rules.

```cpp
class Percentage {
private:
    int value;

public:
    Percentage(int input)
        : value(0) {
        if (input >= 0 && input <= 100) {
            value = input;
        }
    }
};
```

However, think carefully about invalid input.

Silently changing bad input to another value is not always the best design.

Possible strategies include:

- use a safe fallback
- reject creation through another design
- throw an exception

Exception handling is covered later in:

`26_EXCEPTION_HANDLING`

---

## 15. The destructor

A destructor is a special member function that runs when an object's lifetime ends.

Syntax:

```cpp
class Demo {
public:
    ~Demo() {
        cout << "Destroyed\n";
    }
};
```

A destructor:

- has the class name preceded by `~`
- has no return type
- takes no parameters
- cannot be overloaded with multiple parameter lists

For class `Demo`:

```cpp
~Demo()
```

is its destructor.

---

## 16. Why destructors exist

Some objects manage resources.

Examples include:

- dynamically allocated memory
- files
- locks
- sockets
- database handles

When the object dies, the resource may need cleanup.

Analogy:

Imagine borrowing a locker key.

Acquiring the key gives you access to the locker. When your usage ends, the key must be returned.

A destructor can connect resource cleanup to object lifetime.

This idea becomes the foundation of RAII.

---

## 17. Automatic objects and scope

Consider:

```cpp
class Trace {
public:
    Trace() {
        cout << "Construct\n";
    }

    ~Trace() {
        cout << "Destroy\n";
    }
};

int main() {
    Trace t;
}
```

Conceptually:

```text
enter main
construct t
use t
leave scope
destroy t
```

For normal automatic objects, you do not manually invoke the destructor.

C++ invokes it when the lifetime ends.

---

## 18. Nested scopes

Destruction can happen before the end of a function.

```cpp
cout << "A\n";

{
    Trace t;
    cout << "B\n";
}

cout << "C\n";
```

Flow:

```text
A
constructor
B
destructor
C
```

The object dies when its block ends.

This deterministic destruction is extremely important in C++.

---

## 19. Reverse destruction order

Objects in the same scope are generally destroyed in reverse order of completed construction.

Example:

```cpp
Trace first("first");
Trace second("second");
Trace third("third");
```

Construction:

```text
first
second
third
```

Destruction when leaving the scope:

```text
third
second
first
```

Analogy:

Think of stacking plates.

You place:

```text
first
second
third
```

and normally remove them from the top:

```text
third
second
first
```

---

## 20. Dynamic objects

Suppose:

```cpp
Trace* ptr = new Trace;
```

The object does not die merely because the pointer variable later leaves an inner scope.

A matching:

```cpp
delete ptr;
```

ends the dynamically allocated object's lifetime and releases its allocated storage.

Conceptually:

```text
new Trace
    |
    +-- allocate storage
    +-- construct object

delete ptr
    |
    +-- run destructor
    +-- release storage
```

This is another reason forgetting `delete` is dangerous when using raw owning pointers.

Later, smart pointers will automate this ownership pattern.

---

## 21. Do not manually call destructors casually

You might technically see syntax such as:

```cpp
object.~Type();
```

but beginners should not manually destroy ordinary automatic objects.

Doing so without correctly managing the object's lifetime can lead to undefined behavior when C++ later attempts normal cleanup.

Use normal scope-based destruction.

For dynamic objects created with `new`, use matching `delete`.

---

## 22. Arrays of objects

Consider:

```cpp
class Trace {
public:
    Trace() {
        cout << "Construct\n";
    }

    ~Trace() {
        cout << "Destroy\n";
    }
};

Trace values[3];
```

Three objects are constructed.

At scope exit, the array elements are destroyed in reverse element order.

If you dynamically allocate an array:

```cpp
Trace* values = new Trace[3];
```

the matching cleanup is:

```cpp
delete[] values;
```

not:

```cpp
delete values;
```

Matching `new[]` with `delete[]` is essential.

---

## 23. Member objects

A class can contain another class object.

```cpp
class Engine {
public:
    Engine() {
        cout << "Engine constructed\n";
    }

    ~Engine() {
        cout << "Engine destroyed\n";
    }
};

class Car {
private:
    Engine engine;

public:
    Car() {
        cout << "Car constructed\n";
    }

    ~Car() {
        cout << "Car destroyed\n";
    }
};
```

When:

```cpp
Car car;
```

is created:

```text
Engine constructed
Car constructed
```

When it dies:

```text
Car destroyed
Engine destroyed
```

The member must exist before the containing object's constructor body executes.

During destruction, the containing destructor body runs before member subobjects are destroyed.

---

## 24. First look at the copy constructor

Suppose:

```cpp
class Point {
public:
    int x;
    int y;

    Point(int x, int y)
        : x(x), y(y) {
    }
};
```

Then:

```cpp
Point a(1, 2);
Point b = a;
```

initializes `b` from `a`.

This involves copy construction.

For simple value members, the compiler-generated copy behavior is usually appropriate.

A copy constructor has the usual form:

```cpp
Type(const Type& other);
```

Example:

```cpp
class Number {
private:
    int value;

public:
    Number(int value)
        : value(value) {
    }

    Number(const Number& other)
        : value(other.value) {
        cout << "Copied\n";
    }
};
```

This lesson only introduces the mechanism.

Resource-owning classes make copying more complicated.

---

## 25. Construction is not assignment

These are different operations:

```cpp
Point b = a;
```

and:

```cpp
Point b;
b = a;
```

The first initializes a new object from another object.

The second first creates `b`, then assigns to an already existing `b`.

Conceptually:

```text
Point b = a
---------
create b using a


Point b;
b = a;
---------
create b
then modify existing b through assignment
```

This distinction becomes crucial for resource-managing classes.

---

## 26. Resource ownership example

Consider a class that manually owns one dynamically allocated integer:

```cpp
class IntOwner {
private:
    int* data;

public:
    IntOwner(int value)
        : data(new int(value)) {
    }

    ~IntOwner() {
        delete data;
    }
};
```

This shows an important constructor/destructor pairing:

```text
constructor -> acquire resource
destructor  -> release resource
```

But this class has a serious copying problem.

A default member-wise copy can make two objects contain the same pointer:

```text
first.data ------+
                 |
                 v
              [42]
                 ^
                 |
second.data -----+
```

Both destructors could then try to delete the same allocation.

Therefore resource ownership requires careful copy/move design.

Later lessons on RAII, smart pointers, and move semantics will develop safer solutions.

For now, remember:

> Adding a destructor to a raw-resource-owning class is not by itself sufficient to make the class safely copyable.

---

## 27. RAII foundation

RAII means:

**Resource Acquisition Is Initialization**

Despite the name, the central idea is about lifetime.

A resource is tied to an object's lifetime:

```text
object begins lifetime
       |
       +-- acquire/manage resource
       |
       v
object is used
       |
       v
object ends lifetime
       |
       +-- release resource
```

This pattern is fundamental to modern C++.

You will revisit it thoroughly in:

`30_SMART_POINTERS_AND_RAII`

---

## 28. Constructor and destructor complexity

Constructors and destructors are functions, so their complexity depends on the work they perform.

A constructor merely assigning several integers is typically O(1).

A constructor copying an array of `n` values could be O(n).

A destructor releasing one allocation can be considered O(1) with respect to the number of class-managed elements in a simple model, while destroying a structure containing `n` separately managed objects can require O(n) cleanup.

Never assume construction or destruction is automatically constant time.

---

## Complexity table

| Operation | Typical simple example | Extra space |
|---|---:|---:|
| Initialize primitive members | O(1) | O(1) |
| Default constructor with fixed work | O(1) | O(1) |
| Parameterized constructor with fixed work | O(1) | O(1) |
| Destructor with fixed cleanup | O(1) | O(1) |
| Copy object with fixed-size value members | O(1) | O(1) |
| Construct array of n objects | O(n) plus constructor work | Depends |
| Destroy array of n objects | O(n) plus destructor work | O(1) auxiliary |
| Copy n dynamically stored values | O(n) | O(n) for new owned storage |

Actual complexity always depends on the implementation.

---

## Common interview and beginner mistakes

1. Giving a constructor a return type.

Incorrect:

```cpp
void Player() {}
```

That is not a constructor.

2. Assuming the compiler always supplies a no-argument constructor after another constructor is declared.

3. Confusing initialization with assignment.

4. Ignoring member initializer lists.

5. Trying to assign to a const or reference member inside the constructor body instead of initializing it.

6. Assuming members initialize in initializer-list order.

They initialize according to declaration order.

7. Forgetting that destructors execute automatically for automatic objects.

8. Calling a destructor manually on an ordinary automatic object without managing the lifetime consequences.

9. Using `new[]` with `delete` instead of `delete[]`.

10. Forgetting `delete` for raw dynamically allocated objects.

11. Assuming a destructor automatically makes a raw-pointer-owning class safe to copy.

12. Copying an owning raw pointer and causing double deletion.

13. Believing destructor code executes before the destructor body when member cleanup actually follows the containing destructor body's execution.

14. Using raw ownership in new designs when automatic objects or later smart-pointer techniques are more appropriate.

---

## Practice questions

1. HackerRank — Classes and Objects  
   https://www.hackerrank.com/challenges/classes-objects/problem

2. GeeksforGeeks — Constructors in C++  
   https://www.geeksforgeeks.org/constructors-c/

3. GeeksforGeeks — Destructors in C++  
   https://www.geeksforgeeks.org/destructors-c/

4. LeetCode 1603 — Design Parking System  
   https://leetcode.com/problems/design-parking-system/

5. LeetCode 155 — Min Stack  
   https://leetcode.com/problems/min-stack/

For problems requiring STL containers not yet covered in depth, focus on the object-lifetime and class-design aspects now. The relevant containers receive dedicated lessons later.

---

## Revision checklist

Make sure you can explain:

- constructor syntax
- default constructor
- parameterized constructor
- constructor overloading
- initializer lists
- initialization versus assignment
- member initialization order
- in-class member initializers
- delegating constructors
- destructor syntax
- automatic destruction
- reverse destruction order
- `new`/`delete`
- `new[]`/`delete[]`
- member-object lifetime
- basic copy construction
- why owning raw pointers complicate copying
- how constructors/destructors relate to RAII

---

# What's Next

Continue to:

`01_C++__/20_INHERITANCE/`

There we will study base classes, derived classes, inheritance modes, inherited members, construction/destruction order across an inheritance hierarchy, overriding foundations, and the important "is-a" relationship.
