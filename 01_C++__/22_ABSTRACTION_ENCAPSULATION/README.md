# 22 — Abstraction and Encapsulation

## Learning goals

This lesson connects the class features learned so far to two major
object-oriented design principles:

- encapsulation
- abstraction

By the end, you should understand:

- what encapsulation means
- what abstraction means
- the difference between them
- data hiding
- access control
- class invariants
- controlled interfaces
- why getters/setters are not the definition of encapsulation
- why making members private is useful but not sufficient by itself
- implementation hiding
- interface versus implementation
- abstract classes as one mechanism for abstraction
- abstraction without inheritance
- information hiding
- coupling and implementation changes
- designing classes around behavior
- command-query separation as a useful guideline
- composition as an abstraction tool
- practical examples for DSA class design

---

## 1. Why these ideas matter

Suppose a bank account is represented like this:

```cpp
struct Account {
    int balance;
};
```

Any part of the program can write:

```cpp
account.balance = -1000000;
```

If negative balances are forbidden, the object can now contain an
invalid state.

The problem is not merely syntax.

The real problem is that the representation is exposed without
enforcing the rules of the abstraction.

A better design can keep the state private:

```cpp
class Account {
private:
    int balance = 0;

public:
    bool deposit(int amount);
    bool withdraw(int amount);
    int getBalance() const;
};
```

Outside code works through meaningful operations.

This brings us to encapsulation.

---

## 2. What is encapsulation?

Encapsulation means organizing state and the operations responsible
for that state behind a controlled boundary.

A class is a major C++ mechanism for doing this.

Example:

```cpp
class Counter {
private:
    int value = 0;

public:
    void increment() {
        ++value;
    }

    int getValue() const {
        return value;
    }
};
```

Outside code cannot directly perform:

```cpp
counter.value = 999;
```

Instead it interacts through the public interface.

Conceptually:

```text
+---------------------------+
| Counter                   |
|                           |
| private state:            |
|   value                   |
|                           |
| public interface:         |
|   increment()             |
|   getValue()              |
+---------------------------+
```

The object's internal state and the code governing it are grouped
behind a class boundary.

---

## 3. Real-world analogy for encapsulation

Think of a vending machine.

You are allowed to:

```text
insert money
choose item
receive result
```

You are not normally allowed to reach inside and directly manipulate:

```text
coin mechanism
inventory mechanism
electrical components
internal counters
```

The machine exposes controlled operations while protecting its
internal state.

That resembles encapsulation.

---

## 4. Data hiding

Data hiding is closely related to encapsulation.

In C++, access specifiers help restrict direct access:

```cpp
private:
protected:
public:
```

Example:

```cpp
class Temperature {
private:
    double celsius;

public:
    double getCelsius() const {
        return celsius;
    }
};
```

The representation is hidden from normal outside access.

But simply writing `private` does not automatically produce a good
design.

---

## 5. Private does not automatically mean well encapsulated

Consider:

```cpp
class Account {
private:
    int balance;

public:
    int getBalance() const {
        return balance;
    }

    void setBalance(int value) {
        balance = value;
    }
};
```

The state is technically private, but:

```cpp
account.setBalance(-999999);
```

may still violate the intended rules.

A stronger interface might be:

```cpp
bool deposit(int amount);
bool withdraw(int amount);
int getBalance() const;
```

Now the public operations communicate the meaning of the class.

Encapsulation is about controlling state through a sensible boundary,
not merely placing `private` before variables.

---

## 6. Class invariants

An invariant is a condition that should remain true for every valid
observable state of an object.

For a bank account that does not permit overdrafts:

```text
balance >= 0
```

may be an invariant.

For a percentage:

```text
0 <= value <= 100
```

may be an invariant.

For a rectangle:

```text
width >= 0
height >= 0
```

could be invariants.

A good class tries to establish its invariant during construction and
preserve it through every public modifying operation.

---

## 7. Dry run: preserving an invariant

Consider:

```cpp
class BankAccount {
private:
    int balance;

public:
    BankAccount(int initial)
        : balance(initial >= 0 ? initial : 0) {
    }

    bool withdraw(int amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }

        balance -= amount;
        return true;
    }
};
```

Suppose:

```text
initial balance = 500
```

State:

```text
balance = 500
invariant: balance >= 0 -> true
```

Call:

```cpp
withdraw(200)
```

Check:

```text
amount > 0       -> true
amount <= 500    -> true
```

Update:

```text
balance = 500 - 200
balance = 300
```

Invariant:

```text
300 >= 0 -> true
```

Now call:

```cpp
withdraw(700)
```

Check:

```text
700 > balance
```

The method returns `false`.

State remains:

```text
balance = 300
```

The invalid transition never occurs.

---

## 8. What is abstraction?

Abstraction means exposing the essential operations or concepts while
hiding unnecessary implementation details.

A user asks:

```text
What can this object do?
```

instead of needing to know:

```text
Exactly how does it do it internally?
```

Example:

```cpp
stack.push(10);
stack.pop();
```

A user of a stack abstraction should not need to care whether the
stack is internally implemented with:

```text
an array
a dynamic array
a linked structure
```

The interface communicates stack behavior.

---

## 9. Real-world analogy for abstraction

Driving a car provides a useful analogy.

You interact with operations such as:

```text
steering
braking
accelerating
```

You do not need to manually control every combustion event or
electronic subsystem to drive.

The complicated implementation is hidden behind a useful interface.

That is abstraction.

---

## 10. Encapsulation versus abstraction

They are related, but they are not identical.

A practical distinction is:

```text
Encapsulation:
How do we package and protect state and behavior behind boundaries?

Abstraction:
Which essential interface or concept should the user see?
```

Example:

```cpp
class BankAccount {
private:
    int balance;

public:
    bool withdraw(int amount);
};
```

Encapsulation:

```text
balance is hidden and controlled
```

Abstraction:

```text
the user thinks in terms of "withdraw",
not direct arithmetic on the stored representation
```

---

## 11. Interface versus implementation

Consider:

```cpp
class Counter {
public:
    void increment();
    int getValue() const;

private:
    int value;
};
```

The public part forms the usable interface.

An implementation could be:

```cpp
void Counter::increment() {
    ++value;
}
```

Caller code should normally depend on:

```text
increment()
getValue()
```

rather than the exact internal representation.

This separation reduces coupling.

---

## 12. Abstraction does not require inheritance

A common misconception is:

> abstraction means abstract classes

Abstract classes are one tool for abstraction, but abstraction is much
broader.

This ordinary class is an abstraction:

```cpp
class Timer {
private:
    int seconds;

public:
    void tick();
    int remaining() const;
};
```

Users interact with timer concepts instead of direct representation.

No inheritance is required.

---

## 13. Abstract classes as an abstraction tool

Inheritance can define a common abstract interface:

```cpp
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};
```

Users can work with:

```cpp
const Shape&
```

without knowing whether the actual object is:

```text
Rectangle
Circle
Triangle
```

The interface exposes what matters:

```text
area()
```

The implementation varies by concrete type.

---

## 14. Information hiding

Information hiding means designing modules so that implementation
decisions that may change are not unnecessarily exposed.

Suppose version 1 stores:

```cpp
int seconds;
```

Later, the implementation changes to:

```cpp
int minutes;
int seconds;
```

If callers only use:

```cpp
getTotalSeconds()
```

the implementation can change with less impact on caller code.

If callers directly manipulate storage details everywhere, changes
spread throughout the program.

---

## 15. Coupling

Coupling describes how strongly pieces of code depend on one another.

High coupling:

```text
caller knows internal variables
caller knows representation
caller directly repairs state
caller depends on implementation details
```

Lower coupling:

```text
caller uses stable public operations
class controls its representation
implementation can change internally
```

Abstraction and encapsulation often help reduce unnecessary coupling.

---

## 16. Getters and setters

Getters and setters can be useful:

```cpp
int getAge() const;
bool setAge(int age);
```

But do not automatically create getters and setters for every member.

This:

```cpp
class Account {
private:
    int balance;

public:
    int getBalance() const;
    void setBalance(int balance);
};
```

may simply recreate public data through function calls.

Ask:

```text
What meaningful operations should the object support?
```

For an account:

```text
deposit
withdraw
getBalance
```

usually communicates the domain more clearly.

---

## 17. Queries versus commands

A useful design guideline distinguishes:

```text
query:
asks for information without changing logical state

command:
requests a state change
```

Example:

```cpp
int getBalance() const;   // query
bool withdraw(int value); // command
```

Using `const` for read-only member functions makes this distinction
clearer in C++.

This is a guideline, not a rigid rule for every design.

---

## 18. Avoid exposing mutable internals

Consider:

```cpp
class Scores {
private:
    int values[3];

public:
    int* getValues() {
        return values;
    }
};
```

A caller now receives mutable access to internal storage:

```cpp
int* p = scores.getValues();
p[0] = -100000;
```

This can bypass class validation.

Sometimes exposing references or pointers is appropriate, but it
should be a conscious design decision.

Do not accidentally defeat your own encapsulation.

---

## 19. `const` and public interfaces

A read-only query should often be marked `const`:

```cpp
int getBalance() const {
    return balance;
}
```

This communicates:

```text
this operation does not modify ordinary observable object state
through this interface
```

It also allows calls on const objects:

```cpp
const Account account(...);
account.getBalance();
```

Const-correct interfaces strengthen class contracts.

---

## 20. Composition and abstraction

A class can hide helper objects inside itself:

```cpp
class Engine {
public:
    void ignite() {
    }
};

class Car {
private:
    Engine engine;

public:
    void start() {
        engine.ignite();
    }
};
```

The `Car` user interacts with:

```cpp
car.start();
```

and does not need to operate directly on the engine.

Composition therefore works naturally with abstraction and
encapsulation.

---

## 21. A stack abstraction

Later you will study stacks deeply.

Even now, consider the interface:

```cpp
class Stack {
public:
    void push(int value);
    bool pop();
    int top() const;
    bool empty() const;
};
```

This tells users what stack operations exist.

It does not require callers to know the representation.

Internally it might use:

```text
fixed array
dynamic array
linked nodes
```

The stack interface is the abstraction.

The hidden representation and controlled access support
encapsulation.

---

## 22. Dry run: stack interface

Suppose a fixed-capacity stack contains:

```text
[10, 20, _, _, _]
size = 2
```

Call:

```cpp
push(30)
```

Internal implementation performs:

```text
values[size] = 30
values[2] = 30

size++
size = 3
```

Internal state:

```text
[10, 20, 30, _, _]
size = 3
```

The caller only needed:

```cpp
stack.push(30);
```

The caller did not need the index arithmetic.

That implementation detail is abstracted away.

---

## 23. Encapsulation in DSA

Encapsulation is especially useful when implementing structures such
as:

```text
Stack
Queue
LinkedList
BinarySearchTree
Heap
DisjointSet
Trie
SegmentTree
```

For example, users of a disjoint-set structure may call:

```cpp
find(x)
unite(a, b)
```

without manually manipulating parent and rank arrays.

Keeping representation rules inside the class helps prevent accidental
corruption.

---

## 24. Avoid "god classes"

Encapsulation does not mean placing an entire program inside one giant
class.

A class should represent a coherent responsibility.

Bad conceptual design:

```text
ApplicationManager
  handles users
  handles files
  handles networking
  sorts arrays
  sends email
  manages database
  prints reports
```

This hides many unrelated responsibilities behind one boundary.

Good abstractions should have focused responsibilities.

---

## 25. Public interface should be small and meaningful

Every public member increases what external code can depend upon.

Compare:

```text
setRawBalance
setInternalFlag
setTransactionCounter
getRawStorage
modifyHistoryPointer
```

with:

```text
deposit
withdraw
getBalance
```

The second interface is easier to understand and gives the
implementation greater freedom.

Do not expose implementation details "just in case."

---

## 26. Encapsulation is not security

`private` is primarily a compile-time language access-control
mechanism.

It is not encryption.

Do not treat:

```cpp
private:
    string password;
```

as a security system merely because ordinary C++ source code cannot
access the member directly.

Security requires additional techniques far beyond class access
specifiers.

---

## 27. Abstraction layers

Large systems often contain several abstraction levels.

Example:

```text
Application
    |
    v
File interface
    |
    v
Operating system APIs
    |
    v
Storage system
    |
    v
Hardware
```

Each layer tries to let the layer above work with concepts relevant to
its task rather than every lower-level detail.

DSA libraries do something similar.

A user can call:

```text
push
pop
find
insert
erase
```

without reimplementing storage mechanics every time.

---

## 28. Complexity

Abstraction and encapsulation are design principles, not algorithms.

They do not automatically change Big-O complexity.

A getter:

```cpp
int getValue() const;
```

may be O(1).

But an apparently simple abstraction:

```cpp
int countItems() const;
```

could be O(n) if its implementation traverses a structure.

The public interface name does not reveal complexity by itself.

Complexity remains part of the interface contract developers should
understand and document.

---

## Complexity table

| Example operation | Time | Extra space |
|---|---:|---:|
| Return stored primitive member | O(1) | O(1) |
| Validate and assign one value | O(1) | O(1) |
| Deposit/withdraw shown here | O(1) | O(1) |
| Fixed-capacity stack push | O(1) | O(1) |
| Fixed-capacity stack pop | O(1) | O(1) |
| Traverse n hidden elements | O(n) | O(1) |
| Copy n hidden elements | O(n) | O(n) if new storage is needed |

Abstraction can hide implementation details, but it should not hide
important performance expectations from programmers.

---

## Common interview and beginner mistakes

1. Saying encapsulation only means "making variables private."

2. Saying abstraction only means "using abstract classes."

3. Treating abstraction and encapsulation as identical definitions.

4. Providing setters that let callers violate invariants.

5. Creating a getter and setter for every member automatically.

6. Exposing raw mutable internal storage unnecessarily.

7. Forgetting `const` on query functions.

8. Putting unrelated responsibilities into one giant class.

9. Using inheritance where composition better expresses the design.

10. Assuming a private member provides security or encryption.

11. Hiding complexity information merely because implementation
    details are abstracted.

12. Designing classes around storage fields rather than meaningful
    behavior.

13. Letting callers maintain invariants that the class itself should
    protect.

14. Exposing implementation details that make future representation
    changes expensive.

---

## Practice questions and references

1. GeeksforGeeks — Encapsulation in C++  
   https://www.geeksforgeeks.org/encapsulation-in-cpp/

2. GeeksforGeeks — Abstraction in C++  
   https://www.geeksforgeeks.org/abstraction-in-cpp/

3. LeetCode 1603 — Design Parking System  
   https://leetcode.com/problems/design-parking-system/

4. LeetCode 155 — Min Stack  
   https://leetcode.com/problems/min-stack/

5. LeetCode 707 — Design Linked List  
   https://leetcode.com/problems/design-linked-list/

Some of these problems use concepts whose dedicated DSA lessons occur
later. At this stage, focus on identifying state, invariants, public
operations, and hidden implementation details.

---

## Revision checklist

Before moving on, make sure you can explain:

- encapsulation
- abstraction
- the difference between them
- data hiding
- information hiding
- invariants
- interface versus implementation
- why private fields alone are insufficient
- why getters/setters should be intentional
- command versus query operations
- const-correct interfaces
- coupling
- abstraction without inheritance
- abstract classes as an abstraction mechanism
- composition
- why mutable implementation details should not be exposed casually
- how these ideas apply to DSA classes

# What's Next

Continue to:

`01_C++__/23_STATIC_CONST_FRIEND/`

The next lesson studies class-related uses of `static`, `const`, and
`friend`, including static data members, static member functions,
const objects, const member functions, mutable state, friend functions,
and friend classes.
