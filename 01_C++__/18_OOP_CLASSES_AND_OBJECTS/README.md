# 18 — OOP: Classes and Objects

## Learning goals

This lesson introduces the foundation of Object-Oriented Programming (OOP) in C++.

By the end, you should understand:

- why classes exist
- the relationship between a class and an object
- data members and member functions
- `private`, `public`, and `protected`
- encapsulation at the class level
- creating and using objects
- the `.` member-access operator
- methods that modify object state
- methods that only observe state
- the `this` pointer
- `const` objects and `const` member functions
- class scope
- defining member functions inside and outside a class
- object independence
- object copying at an introductory level
- arrays of objects
- pointers to objects and `->`
- passing objects to functions
- returning objects from functions
- stack and dynamically allocated objects
- `struct` versus `class`
- basic class design principles

Constructors and destructors are intentionally treated only lightly here because they receive their own complete lesson next.

---

## 1. Why Object-Oriented Programming?

So far, we have often kept data and functions separate.

Suppose a program represents a bank account:

```cpp
string owner = "Asha";
double balance = 5000;

void deposit(double& balance, double amount) {
    balance += amount;
}
```

This works, but larger programs may have hundreds or thousands of related values and functions.

We would like to express:

> An account has data and operations that belong to that data.

A class provides exactly this grouping.

```cpp
class BankAccount {
public:
    string owner;
    double balance;

    void deposit(double amount) {
        balance += amount;
    }
};
```

A class lets us describe a new type containing both:

1. state — the data describing an entity
2. behavior — operations the entity can perform

This is one of the foundations of OOP.

---

## 2. Class versus object

A **class** is a user-defined type describing what its objects contain and can do.

An **object** is an actual instance of that class.

Real-world analogy:

Think of a house blueprint.

The blueprint describes:

- number of rooms
- positions of doors
- dimensions
- structure

But the blueprint itself is not a physical house.

Similarly:

```cpp
class Player {
public:
    int health;
};
```

defines a type.

Then:

```cpp
Player p1;
Player p2;
```

creates two objects.

Conceptually:

```text
Class: Player
        |
        +------ p1
        |       health
        |
        +------ p2
                health
```

Each object has its own non-static data.

---

## 3. Data members

Variables declared inside a class are called **data members**.

```cpp
class Student {
public:
    string name;
    int marks;
};
```

Here:

- `name` is a data member
- `marks` is a data member

We can create an object and access public members using `.`:

```cpp
Student s;
s.name = "Riya";
s.marks = 91;
```

The expression:

```cpp
s.marks
```

means:

> Access the `marks` member belonging to object `s`.

---

## 4. Member functions

Functions declared as part of a class are called **member functions** or methods.

```cpp
class Counter {
public:
    int value = 0;

    void increment() {
        value++;
    }

    void show() {
        cout << value << '\n';
    }
};
```

Usage:

```cpp
Counter c;

c.increment();
c.increment();
c.show();
```

Output:

```text
2
```

A member function operates in the context of a particular object.

When:

```cpp
c.increment();
```

runs, the `value` used by `increment()` is the `value` belonging to `c`.

---

## 5. State and behavior

A useful mental model is:

```text
Object
├── State
│   └── data members
└── Behavior
    └── member functions
```

For a `Rectangle`:

```cpp
class Rectangle {
public:
    int width;
    int height;

    int area() {
        return width * height;
    }
};
```

State:

```text
width
height
```

Behavior:

```text
area()
```

---

## 6. Access specifiers

C++ classes can control who is allowed to access members.

The three main access specifiers are:

```cpp
public:
private:
protected:
```

### public

Accessible from outside the object.

### private

Accessible from member functions of the class, but not directly from ordinary outside code.

### protected

Similar to `private`, but derived classes can also access it.

Inheritance will be taught later, so `protected` becomes much more important in:

`20_INHERITANCE`

Example:

```cpp
class Account {
private:
    double balance = 0;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};
```

This is allowed:

```cpp
Account a;
a.deposit(100);
cout << a.getBalance();
```

This is not:

```cpp
a.balance = -999999;
```

because `balance` is private.

---

## 7. Why private data is useful

Suppose the balance were public:

```cpp
account.balance = -500000;
```

Nothing prevents invalid state.

By hiding the data:

```cpp
private:
    double balance;
```

and controlling modifications through functions:

```cpp
void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}
```

the class can enforce rules.

Analogy:

An ATM does not give you direct physical access to the bank's database. It exposes controlled operations such as deposit, withdrawal, and balance inquiry.

The same principle applies to a well-designed class.

---

## 8. Default access: class versus struct

You already learned structures.

An important C++ distinction is:

```cpp
struct Example {
    int x;
};
```

Members are `public` by default.

But:

```cpp
class Example {
    int x;
};
```

members are `private` by default.

Therefore:

```cpp
Example e;
e.x = 5;
```

would fail for the class above.

You can explicitly write:

```cpp
class Example {
public:
    int x;
};
```

C++ `struct` and `class` are otherwise much more similar than beginners sometimes expect.

---

## 9. Object independence

Consider:

```cpp
class Counter {
public:
    int value = 0;

    void increment() {
        value++;
    }
};
```

Now:

```cpp
Counter a;
Counter b;

a.increment();
a.increment();
b.increment();
```

Dry run:

```text
Step 0:
a.value = 0
b.value = 0

Step 1: a.increment()
a.value = 1
b.value = 0

Step 2: a.increment()
a.value = 2
b.value = 0

Step 3: b.increment()
a.value = 2
b.value = 1
```

The objects use the same class definition, but they contain independent state.

---

## 10. Functions inside versus outside the class

A function can be defined directly inside:

```cpp
class Box {
public:
    int value = 10;

    void show() const {
        cout << value;
    }
};
```

Or declared inside and defined later:

```cpp
class Box {
public:
    int value = 10;

    void show() const;
};

void Box::show() const {
    cout << value;
}
```

The `::` operator is the scope-resolution operator.

```cpp
Box::show
```

means:

> `show` belonging to the scope of `Box`.

This becomes especially useful when class definitions grow larger.

---

## 11. Class scope

Members declared inside a class belong to that class's scope.

```cpp
class Calculator {
public:
    int square(int x) {
        return x * x;
    }
};
```

The function is identified as:

```cpp
Calculator::square
```

when referred to outside its class definition.

Different classes may therefore contain methods with the same name:

```cpp
class A {
public:
    void show() {}
};

class B {
public:
    void show() {}
};
```

There is no conflict between:

```text
A::show
B::show
```

---

## 12. The `this` pointer

Inside a non-static member function, C++ provides an implicit pointer named:

```cpp
this
```

It points to the object on which the function was called.

Example:

```cpp
class Number {
private:
    int value = 0;

public:
    void setValue(int value) {
        this->value = value;
    }
};
```

There are two different `value`s:

```text
this->value     data member
value           function parameter
```

Suppose:

```cpp
Number n;
n.setValue(25);
```

Conceptually:

```text
n.setValue(25)
      |
      +---- this points to n
      |
      +---- parameter value = 25

this->value = value
n's member  = 25
```

You do not normally have to write `this->`.

For example:

```cpp
void increment() {
    value++;
}
```

is conceptually operating on the current object's `value`.

---

## 13. Const member functions

Suppose a function only reads object state:

```cpp
int getScore() const {
    return score;
}
```

The trailing `const` means the function promises not to modify ordinary data members of that object.

This matters when using const objects:

```cpp
const Player p;
```

A const object can call const member functions, but not ordinary non-const methods that might modify it.

Example:

```cpp
class Point {
private:
    int x = 0;

public:
    int getX() const {
        return x;
    }
};
```

Then:

```cpp
const Point p;
cout << p.getX();
```

is valid.

Think of `const` member functions as read-only operations.

---

## 14. Getters and setters

A function that returns a private value is commonly called a getter:

```cpp
int getAge() const {
    return age;
}
```

A controlled function that changes it is often called a setter:

```cpp
void setAge(int newAge) {
    if (newAge >= 0) {
        age = newAge;
    }
}
```

The key idea is not merely to write getters and setters for everything.

The important idea is:

> expose operations that preserve meaningful class rules.

Sometimes a class should not provide a setter at all.

For example, directly setting a bank balance may make less sense than providing:

```cpp
deposit()
withdraw()
```

---

## 15. Passing objects to functions

Objects can be passed the same ways you learned previously.

### Pass by value

```cpp
void printStudent(Student s);
```

A copy is passed.

For a large object, copying may cost more time and memory.

### Pass by reference

```cpp
void updateStudent(Student& s);
```

No copy is required, and the function can modify the original.

### Pass by const reference

```cpp
void printStudent(const Student& s);
```

No full object copy is required, and the function promises not to modify `s`.

For read-only access to larger objects, `const T&` is a common choice.

---

## 16. Returning objects

Functions can return objects:

```cpp
class Point {
public:
    int x = 0;
    int y = 0;
};

Point makePoint(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
```

Usage:

```cpp
Point p = makePoint(3, 4);
```

Modern C++ is designed to make returning objects practical. More details about copying and moving objects will appear in later lessons.

---

## 17. Arrays of objects

If a class represents a type, arrays can contain that type:

```cpp
class Item {
public:
    int price = 0;
};

Item items[3];

items[0].price = 10;
items[1].price = 20;
items[2].price = 30;
```

Memory conceptually contains three `Item` objects:

```text
items
+---------+---------+---------+
| Item 0  | Item 1  | Item 2  |
| price10 | price20 | price30 |
+---------+---------+---------+
```

The same principle applies later to containers such as `vector<Item>`.

---

## 18. Pointers to objects

Because objects occupy memory, a pointer can point to one.

```cpp
Player p;
Player* ptr = &p;
```

Members can be accessed through:

```cpp
(*ptr).health
```

or, more conveniently:

```cpp
ptr->health
```

Therefore:

```cpp
ptr->health
```

is effectively shorthand for:

```cpp
(*ptr).health
```

when accessing a member through a pointer.

---

## 19. Dynamically allocated objects

An object can also be created with `new`:

```cpp
Player* p = new Player;
p->health = 100;

delete p;
p = nullptr;
```

The object remains alive until it is deleted.

Manual `new`/`delete` is important for understanding memory, but modern production C++ usually prefers automatic lifetime management and smart pointers where dynamic ownership is required.

RAII and smart pointers are covered later in:

`30_SMART_POINTERS_AND_RAII`

---

## 20. Object copying — first look

Given:

```cpp
class Point {
public:
    int x = 0;
};
```

we can write:

```cpp
Point a;
a.x = 5;

Point b = a;
```

For this simple class:

```text
a.x = 5
b.x = 5
```

Then:

```cpp
b.x = 20;
```

produces:

```text
a.x = 5
b.x = 20
```

The objects are distinct.

Be careful when classes own raw pointers. A simple member-by-member copy may then copy an address rather than duplicate the underlying resource.

That problem connects to:

- constructors
- destructors
- copy operations
- move operations
- RAII

Those concepts will be developed in later lessons.

---

## 21. A complete example: BankAccount

```cpp
class BankAccount {
private:
    double balance = 0.0;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }

        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};
```

Suppose:

```cpp
BankAccount account;

account.deposit(1000);
account.withdraw(250);
account.deposit(100);
```

Dry run:

```text
Initial:
balance = 0

deposit(1000):
amount > 0
balance = 0 + 1000
balance = 1000

withdraw(250):
250 > 0
250 <= 1000
balance = 1000 - 250
balance = 750

deposit(100):
100 > 0
balance = 750 + 100
balance = 850
```

Outside code cannot directly perform:

```cpp
account.balance = -100;
```

The class controls how its state changes.

---

## 22. Object size

An object normally contains storage for its non-static data members, plus any padding required for alignment.

Member function machine code is not separately duplicated inside every ordinary object.

Example:

```cpp
class Pair {
public:
    int a;
    int b;

    int sum() const {
        return a + b;
    }
};
```

Conceptually, each object needs storage for `a` and `b`, but does not carry a private duplicate of the `sum()` machine code.

Actual size can include padding, so use:

```cpp
sizeof(Pair)
```

instead of assuming a byte count.

---

## 23. Empty classes

Even an empty class normally has nonzero size:

```cpp
class Empty {};
```

Typically:

```cpp
sizeof(Empty)
```

is `1`.

Why?

Distinct objects need distinct addresses.

The language therefore allows empty objects to occupy distinguishable locations.

Do not write algorithms that depend on the size always being exactly 1; use `sizeof` when the actual implementation result matters.

---

## 24. Good beginner class design

Prefer classes that maintain valid state.

Instead of:

```cpp
class Temperature {
public:
    double kelvin;
};
```

you might eventually provide controlled operations that reject physically invalid values.

Useful design questions include:

- What state belongs together?
- Which state should outside code be allowed to modify?
- What operations make sense?
- What class invariants must always remain true?
- Which functions should be `const`?
- Can an invalid state be prevented rather than repaired later?

An **invariant** is a condition intended to remain true while the object is valid.

For a bank account that forbids overdrafts:

```text
balance >= 0
```

could be an invariant.

---

## 25. Classes are not automatically "better"

Do not create classes merely to make code look object-oriented.

A class is useful when data and behavior form a meaningful abstraction.

For tiny stateless calculations, a normal function may be clearer.

DSA code uses both procedural and object-oriented styles. Examples where classes become useful include:

- linked-list implementations
- stacks
- queues
- trees
- tries
- disjoint-set structures
- segment trees

---

## Complexity analysis

Classes themselves do not impose one universal algorithmic complexity. Complexity depends on what each method does.

For the simple examples in this lesson:

| Operation | Time | Extra space |
|---|---:|---:|
| Read one data member | O(1) | O(1) |
| Assign one primitive member | O(1) | O(1) |
| Simple getter | O(1) | O(1) |
| Simple setter | O(1) | O(1) |
| Deposit/withdraw shown above | O(1) | O(1) |
| Access object through pointer | O(1) | O(1) |
| Traverse array of n objects | O(n) | O(1) |
| Copy object with n-sized owned data | Depends on class | Depends on class |

Do not assume that every member function is O(1).

A method containing a loop over `n` values can still be O(n), and a method that performs sorting could be O(n log n).

---

## Common interview and beginner mistakes

1. Confusing a class with an object.

   A class defines a type; an object is an instance.

2. Forgetting that class members are private by default.

3. Trying to access private members directly.

4. Making every data member public and therefore losing control over invariants.

5. Forgetting `const` on read-only member functions.

6. Confusing:

```cpp
object.member
```

with:

```cpp
pointer->member
```

7. Forgetting to `delete` an object manually created with `new`.

8. Assuming every object shares the same ordinary data members.

9. Assuming methods are physically copied into each object.

10. Returning a pointer or reference to a local object that has already been destroyed.

11. Passing a large read-only object by value unnecessarily.

12. Writing trivial getters/setters without thinking about what operations the abstraction should actually expose.

13. Confusing `this` with the object itself. `this` is a pointer to the current object.

14. Assuming object copying is always safe when raw resource-owning pointers are involved.

---

## Practice questions

1. HackerRank — Classes: Introduction  
   https://www.hackerrank.com/challenges/c-tutorial-class/problem

2. HackerRank — Classes and Objects  
   https://www.hackerrank.com/challenges/classes-objects/problem

3. GeeksforGeeks — C++ Classes and Objects  
   https://www.geeksforgeeks.org/c-classes-and-objects/

4. LeetCode 1603 — Design Parking System  
   https://leetcode.com/problems/design-parking-system/

5. LeetCode 1472 — Design Browser History  
   https://leetcode.com/problems/design-browser-history/

For the LeetCode design problems, focus first on understanding how an object stores state between method calls. Some solutions use STL containers that will be covered in much greater depth later.

---

## Checklist

Before moving on, make sure you can explain:

- class versus object
- state versus behavior
- public versus private
- why controlled access is useful
- data members
- member functions
- `.` versus `->`
- `this`
- const member functions
- passing objects by value/reference/const-reference
- arrays of objects
- why different objects have independent state
- why a raw-pointer-owning class requires extra care

---

# What's Next

Continue to:

`01_C++__/19_CONSTRUCTORS_DESTRUCTORS/`

There we will study object initialization and cleanup in detail, including constructor forms, destructor behavior, object lifetime, initialization lists, and the foundations needed for resource-managing classes.
