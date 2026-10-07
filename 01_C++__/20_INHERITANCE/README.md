# 20 — Inheritance in C++

## Learning goals

Inheritance allows one class to build upon another class.

By the end of this lesson, you should understand:

- base classes and derived classes
- the "is-a" relationship
- basic inheritance syntax
- inherited members
- `public`, `protected`, and `private` members
- public, protected, and private inheritance
- what derived classes can and cannot access
- constructor order
- destructor order
- passing arguments to base constructors
- function hiding
- overriding as preparation for polymorphism
- single inheritance
- multilevel inheritance
- hierarchical inheritance
- multiple inheritance
- ambiguity in multiple inheritance
- diamond inheritance and virtual inheritance
- object slicing
- inheritance versus composition
- why base-class destructors sometimes need to be virtual

The next lesson, `21_POLYMORPHISM`, develops virtual functions,
runtime dispatch, overriding, and abstract interfaces in depth.

---

## 1. What is inheritance?

Suppose a program contains several kinds of employees.

All employees might have:

```text
name
employee ID
```

A developer also has programming-language information.

A manager may have team-size information.

Without inheritance, we might repeat the common members:

```cpp
class Developer {
    string name;
    int id;
    string language;
};

class Manager {
    string name;
    int id;
    int teamSize;
};
```

Inheritance lets us express the common concept once:

```cpp
class Employee {
    // common Employee state
};

class Developer : public Employee {
    // Developer-specific state
};

class Manager : public Employee {
    // Manager-specific state
};
```

`Employee` is the base class.

`Developer` and `Manager` are derived classes.

---

## 2. Real-world analogy

Think of categories:

```text
Vehicle
├── Car
└── Bike
```

A car is a vehicle.

A bike is a vehicle.

They may inherit common properties of vehicles while adding their
own specialized behavior.

Inheritance models this type relationship.

---

## 3. The "is-a" test

Public inheritance should usually express an **is-a** relationship.

Ask:

```text
Is a Dog an Animal?
```

Yes.

Therefore this can make conceptual sense:

```cpp
class Dog : public Animal {
};
```

Now ask:

```text
Is a Car an Engine?
```

No.

A car **has an** engine.

That relationship is better represented by composition:

```cpp
class Car {
private:
    Engine engine;
};
```

A useful beginner guideline is:

```text
Inheritance  -> is-a
Composition  -> has-a
```

This is not the whole theory of software design, but it prevents
many poor inheritance hierarchies.

---

## 4. Basic inheritance syntax

```cpp
class Animal {
public:
    void eat() {
        cout << "Eating\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking\n";
    }
};
```

Usage:

```cpp
Dog dog;

dog.eat();
dog.bark();
```

`Dog` has access to the inherited public interface of `Animal`.

Conceptually:

```text
Animal
  |
  v
 Dog

Dog object
├── Animal portion
└── Dog portion
```

---

## 5. Base and derived classes

Terminology:

```cpp
class Base {
};

class Derived : public Base {
};
```

`Base` may also be called:

- parent class
- superclass

`Derived` may also be called:

- child class
- subclass

In C++, "base class" and "derived class" are the standard terms.

---

## 6. public, protected, and private members

A base class may contain:

```cpp
class Base {
public:
    int publicValue;

protected:
    int protectedValue;

private:
    int privateValue;
};
```

For a derived class:

- public base members can be accessed according to inheritance rules
- protected base members are directly available inside the derived class
- private base members are not directly accessible by the derived class

Example:

```cpp
class Person {
private:
    int secret;

protected:
    string name;

public:
    void show() const {
        cout << name;
    }
};

class Student : public Person {
public:
    void setName(const string& value) {
        name = value;       // allowed
    }

    // secret = 10;         // not allowed
};
```

`private` does not mean the member disappears.

It means derived code cannot directly access it.

The base class can expose controlled functions to work with private data.

---

## 7. Why private base data still matters

Consider:

```cpp
class Account {
private:
    int balance;

public:
    int getBalance() const {
        return balance;
    }
};
```

A derived class cannot write:

```cpp
balance = 1000;
```

directly.

But it can use accessible base-class functions.

This preserves the base class's encapsulation.

Inheritance does not give a derived class unlimited access to
the implementation of its base class.

---

## 8. Inheritance access modes

The word before the base class is an inheritance access mode:

```cpp
class Derived : public Base
```

Possible modes are:

```cpp
public
protected
private
```

These modes affect the accessibility of inherited public and
protected members.

### Public inheritance

```cpp
class Derived : public Base
```

Conceptually:

```text
Base public     -> Derived public
Base protected  -> Derived protected
Base private    -> still inaccessible directly
```

Public inheritance is the common choice for an "is-a" relationship.

### Protected inheritance

```cpp
class Derived : protected Base
```

Conceptually:

```text
Base public     -> Derived protected
Base protected  -> Derived protected
Base private    -> inaccessible directly
```

### Private inheritance

```cpp
class Derived : private Base
```

Conceptually:

```text
Base public     -> Derived private
Base protected  -> Derived private
Base private    -> inaccessible directly
```

Do not confuse:

```text
member access specifiers
```

with:

```text
inheritance access modes
```

They are related, but they answer different questions.

---

## 9. Default inheritance mode

For:

```cpp
class Derived : Base {
};
```

inheritance is private by default.

For:

```cpp
struct Derived : Base {
};
```

inheritance is public by default.

For clarity, explicitly writing the intended inheritance mode is
usually preferable for beginner code.

---

## 10. Construction order

The base-class part of an object must exist before the derived
part can be initialized.

Example:

```cpp
class Base {
public:
    Base() {
        cout << "Base constructor\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor\n";
    }
};
```

Creating:

```cpp
Derived object;
```

prints:

```text
Base constructor
Derived constructor
```

The order is:

```text
1. Base-class construction
2. Member construction
3. Derived constructor body
```

For the simple example without member objects:

```text
Base
  ↓
Derived
```

---

## 11. Destruction order

Destruction runs in the reverse direction.

For the previous example:

```text
Derived destructor
Base destructor
```

Think of object construction as building from the foundation upward.

The base is the foundation, so it is constructed first.

During destruction, the specialized derived portion is dismantled
before the base foundation.

---

## 12. Passing arguments to a base constructor

Suppose the base class has no default constructor:

```cpp
class Person {
private:
    string name;

public:
    Person(const string& name)
        : name(name) {
    }
};
```

The derived constructor can initialize the base part:

```cpp
class Student : public Person {
private:
    int rollNumber;

public:
    Student(const string& name, int roll)
        : Person(name), rollNumber(roll) {
    }
};
```

The important initializer is:

```cpp
Person(name)
```

This constructs the base-class portion of the `Student`.

---

## 13. Dry run: derived construction

Consider:

```cpp
Student student("Asha", 42);
```

With:

```cpp
Student(const string& name, int roll)
    : Person(name), rollNumber(roll) {
}
```

Conceptual dry run:

```text
Step 1:
Storage for complete Student object exists.

Step 2:
Person base subobject is constructed.
Person::name = "Asha"

Step 3:
Student members are initialized.
rollNumber = 42

Step 4:
Student constructor body executes.

Final state:
Person portion:
    name = "Asha"

Student portion:
    rollNumber = 42
```

---

## 14. Inherited member functions

A derived object can use accessible inherited functions.

```cpp
class Shape {
public:
    void info() const {
        cout << "I am a shape\n";
    }
};

class Rectangle : public Shape {
};
```

Then:

```cpp
Rectangle r;
r.info();
```

works.

`Rectangle` did not write its own `info()` function.

---

## 15. Function hiding

Suppose:

```cpp
class Base {
public:
    void show() {
        cout << "Base\n";
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived\n";
    }
};
```

Then:

```cpp
Derived d;
d.show();
```

calls:

```text
Derived::show
```

The derived declaration hides the base declaration with that name
during ordinary lookup.

You can explicitly access the base version:

```cpp
d.Base::show();
```

---

## 16. Same name with different parameters

Function hiding can surprise beginners.

```cpp
class Base {
public:
    void print(int value) {
        cout << value;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived";
    }
};
```

Now:

```cpp
Derived d;
// d.print(10);
```

does not simply choose `Base::print(int)`.

The name declared in `Derived` hides base overloads from ordinary
lookup.

One solution is:

```cpp
using Base::print;
```

inside `Derived`.

Then both overload sets can participate in lookup.

---

## 17. Overriding preview

If the base declares a function `virtual`, a derived class can
override it.

```cpp
class Animal {
public:
    virtual void speak() const {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof\n";
    }
};
```

`override` tells the compiler that this function is intended to
override a virtual base function.

This topic becomes central in the next lesson:

`21_POLYMORPHISM`

For now, remember that simple same-name function hiding and runtime
polymorphic overriding are related but not identical concepts.

---

## 18. Single inheritance

One derived class inherits from one base:

```text
Animal
  |
 Dog
```

Example:

```cpp
class Animal {};
class Dog : public Animal {};
```

This is single inheritance.

---

## 19. Multilevel inheritance

A class can derive from a class that is itself derived.

```text
LivingThing
    |
  Animal
    |
   Dog
```

Example:

```cpp
class LivingThing {};
class Animal : public LivingThing {};
class Dog : public Animal {};
```

`Dog` indirectly inherits from `LivingThing`.

Avoid making hierarchies deeper merely because the language allows it.
Deep hierarchies can become difficult to understand and maintain.

---

## 20. Hierarchical inheritance

Multiple classes may derive from the same base:

```text
       Animal
       /    \
     Dog    Cat
```

Example:

```cpp
class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};
```

The base stores or defines common concepts.

Each derived type can add specialized state and behavior.

---

## 21. Multiple inheritance

C++ permits a class to inherit from more than one base.

```cpp
class Scanner {
public:
    void scan() const {}
};

class Printer {
public:
    void print() const {}
};

class AllInOne : public Scanner, public Printer {
};
```

Conceptually:

```text
Scanner     Printer
    \         /
     \       /
     AllInOne
```

An `AllInOne` object contains base-class subobjects for both bases.

Multiple inheritance can be useful, but it adds complexity.

---

## 22. Multiple-inheritance ambiguity

Suppose:

```cpp
class A {
public:
    void show() const {
        cout << "A\n";
    }
};

class B {
public:
    void show() const {
        cout << "B\n";
    }
};

class C : public A, public B {
};
```

Then:

```cpp
C object;
// object.show();
```

is ambiguous.

The compiler cannot know whether you mean:

```cpp
A::show()
```

or:

```cpp
B::show()
```

You can qualify it:

```cpp
object.A::show();
object.B::show();
```

---

## 23. The diamond problem

Consider:

```text
      Person
      /    \
 Student  Employee
      \    /
   Assistant
```

With ordinary inheritance:

```cpp
class Person {};
class Student : public Person {};
class Employee : public Person {};
class Assistant : public Student, public Employee {};
```

`Assistant` normally contains two separate `Person` base subobjects:

```text
Assistant
├── Student
│   └── Person
└── Employee
    └── Person
```

That can create ambiguity and duplicate shared base state.

---

## 24. Virtual inheritance

C++ provides virtual inheritance for hierarchies where shared
intermediate paths should refer to one common virtual base subobject.

Example:

```cpp
class Person {};

class Student : virtual public Person {};
class Employee : virtual public Person {};

class Assistant : public Student, public Employee {};
```

Now the complete `Assistant` object has one shared `Person` virtual
base subobject.

Conceptually:

```text
        Person
        /    \
   Student  Employee
        \    /
       Assistant
```

Virtual inheritance is different from virtual functions.

The repeated word `virtual` serves different language mechanisms.

---

## 25. Upcasting

With public inheritance:

```cpp
class Animal {};
class Dog : public Animal {};
```

a `Dog` can be viewed as an `Animal`.

Example:

```cpp
Dog dog;
Animal* ptr = &dog;
```

This conversion from a derived type to a base type is commonly called
upcasting.

Similarly:

```cpp
Animal& ref = dog;
```

can bind a base reference to the base portion of the derived object.

This is essential to runtime polymorphism.

---

## 26. Object slicing

A more subtle case is passing or assigning a derived object by value
to a base object.

```cpp
class Base {
public:
    int baseValue = 10;
};

class Derived : public Base {
public:
    int derivedValue = 20;
};

Derived d;
Base b = d;
```

`b` is a standalone `Base`, not a complete `Derived`.

The derived-specific portion is not stored in `b`.

Conceptually:

```text
d:
+------------------+
| Base portion     |
| baseValue = 10   |
+------------------+
| Derived portion  |
| derivedValue=20  |
+------------------+

Base b = d:

b:
+------------------+
| Base portion     |
| baseValue = 10   |
+------------------+
```

This is called object slicing.

When polymorphism is required, base references or pointers are
typically used rather than passing polymorphic objects by base value.

---

## 27. Virtual destructors: important preview

Consider:

```cpp
class Base {
public:
    ~Base() {
    }
};

class Derived : public Base {
};
```

Later, you may write:

```cpp
Base* ptr = new Derived;
```

If an object can be deleted through a base pointer, the base class
must have an appropriate virtual destructor.

Typical polymorphic base:

```cpp
class Base {
public:
    virtual ~Base() = default;
};
```

Then:

```cpp
Base* ptr = new Derived;
delete ptr;
```

correctly destroys the complete derived object.

Deleting a derived object through a base pointer whose destructor is
not virtual results in undefined behavior.

This becomes particularly important in the next lesson.

---

## 28. Inheritance versus composition

Suppose a `Car` uses an `Engine`.

Bad conceptual relationship:

```cpp
class Car : public Engine {
};
```

This says:

```text
Car is an Engine
```

which is generally false.

Composition communicates the actual relationship:

```cpp
class Car {
private:
    Engine engine;
};
```

This says:

```text
Car has an Engine
```

Prefer inheritance when substitutability and a genuine type
relationship exist.

Prefer composition when one object simply owns or uses another
object as part of its implementation.

---

## 29. Complexity

Inheritance itself does not change the asymptotic complexity of
ordinary member access.

The algorithm inside a member function determines its complexity.

| Operation | Typical time | Extra space |
|---|---:|---:|
| Access inherited ordinary member | O(1) | O(1) |
| Call ordinary inherited function | Depends on function | Depends |
| Construct fixed-size base + derived object | O(1) if constructors do fixed work | O(1) |
| Destroy fixed-size base + derived object | O(1) if destructors do fixed work | O(1) |
| Upcast pointer/reference | O(1) | O(1) |
| Copy fixed-size derived object | O(1) | O(1) |
| Traverse n inherited objects | O(n) | O(1) auxiliary |

Virtual dispatch, when used, is still commonly treated as O(1), but
its implementation details and tradeoffs belong to polymorphism.

---

## 30. Common interview and beginner mistakes

1. Using inheritance for every code-reuse situation.

2. Ignoring the "is-a" relationship.

3. Trying to directly access private base members.

4. Confusing protected members with public members.

5. Confusing inheritance mode with member access specifiers.

6. Forgetting that `class Derived : Base` means private inheritance.

7. Forgetting that the base constructor runs before the derived
   constructor body.

8. Forgetting that destruction occurs in the opposite direction.

9. Failing to explicitly call a required base constructor.

10. Assuming initializer-list textual order controls all
    initialization order.

11. Confusing function hiding with virtual overriding.

12. Forgetting that a same-name derived declaration can hide base
    overloads.

13. Ignoring ambiguity in multiple inheritance.

14. Confusing virtual inheritance with virtual functions.

15. Accidentally slicing a derived object by storing it as a base
    object by value.

16. Deleting a derived object through a base pointer without a
    suitable virtual base destructor.

17. Building excessively deep inheritance hierarchies when simpler
    composition would communicate the design better.

---

## Practice questions and references

1. HackerRank — Inheritance Introduction  
   https://www.hackerrank.com/challenges/inheritance-introduction/problem

2. HackerRank — Multi Level Inheritance  
   https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem

3. GeeksforGeeks — Inheritance in C++  
   https://www.geeksforgeeks.org/inheritance-in-c/

4. GeeksforGeeks — Virtual Base Class in C++  
   https://www.geeksforgeeks.org/virtual-base-class-in-c/

5. GeeksforGeeks — Object Slicing in C++  
   https://www.geeksforgeeks.org/object-slicing-in-c/

---

## Revision checklist

Before continuing, make sure you can explain:

- base versus derived classes
- "is-a" versus "has-a"
- public inheritance
- protected inheritance
- private inheritance
- public/protected/private base members
- constructor order
- destructor order
- calling a base constructor
- single inheritance
- multilevel inheritance
- hierarchical inheritance
- multiple inheritance
- ambiguity
- diamond inheritance
- virtual inheritance
- function hiding
- upcasting
- object slicing
- why polymorphic bases often need virtual destructors
- inheritance versus composition

# What's Next

Continue to:

`01_C++__/21_POLYMORPHISM/`

The next lesson develops compile-time and runtime polymorphism,
virtual functions, overriding, dynamic dispatch, pure virtual
functions, abstract classes, base references/pointers, and virtual
destructors in depth.
