# 21 — Polymorphism in C++

## Learning goals

Polymorphism means that one interface can represent multiple forms.

By the end of this lesson, you should understand:

- what polymorphism means
- compile-time versus runtime polymorphism
- function overloading as compile-time polymorphism
- runtime polymorphism through inheritance
- virtual functions
- overriding
- `override`
- `final`
- static versus dynamic binding
- base references and pointers
- why passing polymorphic objects by value causes slicing
- pure virtual functions
- abstract classes
- abstract interfaces
- virtual destructors
- calling virtual functions through pointers/references
- qualified base-class calls
- virtual calls inside constructors/destructors
- why data members themselves are not polymorphic
- the conceptual cost of dynamic dispatch
- practical class-hierarchy design

Operator overloading receives its own dedicated lesson later.

---

## 1. What does polymorphism mean?

The word comes from:

```text
poly  = many
morph = forms
```

In programming, polymorphism allows the same general operation to
behave differently for different types.

Imagine several notification systems:

```text
Email notification -> send email
SMS notification   -> send SMS
Push notification  -> send push message
```

A program may want to say simply:

```text
send notification
```

without every caller needing to know exactly which implementation
performs the work.

That is the central idea behind runtime polymorphism.

---

## 2. Two broad forms in C++

For this stage of C++, think of polymorphism in two broad groups:

```text
Polymorphism
├── Compile-time
│   └── function overloading
└── Runtime
    └── virtual functions through inheritance
```

Templates also provide an important form of compile-time polymorphism,
but templates have their own lesson later.

---

## 3. Compile-time polymorphism

You already know function overloading:

```cpp
void print(int value);
void print(double value);
void print(const string& value);
```

When the compiler sees:

```cpp
print(10);
```

it determines which overload should be called based on the expression
types and overload-resolution rules.

The decision does not require runtime virtual dispatch.

This is commonly described as static or compile-time polymorphism.

---

## 4. Runtime polymorphism problem

Consider:

```cpp
class Animal {
public:
    void speak() const {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() const {
        cout << "Woof\n";
    }
};
```

Now:

```cpp
Dog dog;
Animal& animal = dog;

animal.speak();
```

Without `virtual`, the call is selected according to the static type
of `animal`, which is `Animal&`.

So the base function is called.

If we want the actual object's derived behavior to determine the
function at runtime, we need a virtual function.

---

## 5. Virtual functions

A base member function can be declared `virtual`:

```cpp
class Animal {
public:
    virtual void speak() const {
        cout << "Animal sound\n";
    }
};
```

A derived class can override it:

```cpp
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof\n";
    }
};
```

Now:

```cpp
Dog dog;
Animal& animal = dog;

animal.speak();
```

prints:

```text
Woof
```

The reference is statically typed as `Animal&`, but it refers to a
`Dog`.

Runtime dispatch selects `Dog::speak()`.

---

## 6. Real-world analogy

Imagine a remote control with a button labeled:

```text
START
```

The button represents one interface.

If the remote is controlling a television, START may turn on a TV.

If controlling another device, the corresponding implementation may
perform a different operation.

The caller deals with a common interface while the actual object
supplies specialized behavior.

---

## 7. Static type versus dynamic type

This distinction is central.

Consider:

```cpp
Dog dog;
Animal* ptr = &dog;
```

The expression `ptr` has static type:

```text
Animal*
```

The actual complete object is:

```text
Dog
```

For a virtual call:

```cpp
ptr->speak();
```

runtime dispatch considers the object's dynamic type.

Conceptually:

```text
ptr
 |
 | static view: Animal*
 v
+----------------+
| Dog object     |
| Animal portion |
| Dog portion    |
+----------------+

virtual call -> Dog implementation
```

---

## 8. Overriding

A derived function overrides a virtual base function when it matches
the required signature.

Good practice:

```cpp
void speak() const override {
}
```

rather than merely:

```cpp
void speak() const {
}
```

Why?

Because `override` asks the compiler to verify your intention.

Suppose the base has:

```cpp
virtual void speak() const;
```

but the derived class accidentally writes:

```cpp
void speak();
```

The missing `const` means it does not correctly override that
function.

With `override`, the compiler reports the mistake.

---

## 9. `virtual` versus `override`

Typical style:

```cpp
class Base {
public:
    virtual void run() const {
    }
};

class Derived : public Base {
public:
    void run() const override {
    }
};
```

The base introduces virtual dispatch with `virtual`.

The derived declaration uses `override` to verify that it actually
overrides a virtual base function.

An overriding function remains virtual in further derived classes,
even if the word `virtual` is not repeated.

---

## 10. The `final` specifier

You can prevent further overriding:

```cpp
class Base {
public:
    virtual void run() const {
    }
};

class Derived : public Base {
public:
    void run() const final {
    }
};
```

A class can also be marked `final`:

```cpp
class Finished final : public Base {
};
```

No class may derive from `Finished`.

Use `final` when the design intentionally closes an extension point.

---

## 11. Base references

A base reference can refer to a derived object:

```cpp
Dog dog;
Animal& animal = dog;

animal.speak();
```

This does not create a new `Animal`.

The reference refers to the base-class view of the existing `Dog`.

Virtual dispatch preserves the derived behavior.

---

## 12. Base pointers

Similarly:

```cpp
Dog dog;
Animal* animal = &dog;

animal->speak();
```

Again, no new object is created.

The pointer refers to the `Animal` base subobject inside `dog`.

Virtual dispatch chooses the final overrider for the actual object.

---

## 13. Why pass polymorphic objects by reference?

Consider:

```cpp
void makeSpeak(const Animal& animal) {
    animal.speak();
}
```

Now:

```cpp
Dog dog;
makeSpeak(dog);
```

can dispatch to `Dog::speak()`.

But:

```cpp
void makeSpeak(Animal animal) {
    animal.speak();
}
```

takes an `Animal` by value.

Passing a `Dog` this way constructs only an `Animal` parameter from
the base portion.

The derived portion is sliced away.

This is object slicing.

For polymorphic hierarchies, references and pointers are therefore
fundamental.

---

## 14. Dry run of a virtual call

Suppose:

```cpp
class Animal {
public:
    virtual void speak() const;
};

class Dog : public Animal {
public:
    void speak() const override;
};

Dog dog;
Animal* ptr = &dog;
ptr->speak();
```

Conceptual steps:

```text
Step 1:
dog is a Dog object.

Step 2:
ptr is an Animal* referring to dog's Animal base subobject.

Step 3:
speak() is virtual.

Step 4:
Runtime dispatch considers the dynamic object.

Dynamic type = Dog

Step 5:
The final overrider is Dog::speak().

Step 6:
Dog::speak() executes.
```

This decision happens automatically.

---

## 15. Dynamic binding

The process above is often called:

- dynamic binding
- late binding
- dynamic dispatch

A non-virtual member call is generally statically bound according to
normal language rules.

A virtual call made through an appropriate base pointer or reference
can be dynamically dispatched.

---

## 16. Calling a base implementation deliberately

A derived override can call its base implementation:

```cpp
class Dog : public Animal {
public:
    void speak() const override {
        Animal::speak();
        cout << "Woof\n";
    }
};
```

The qualified call:

```cpp
Animal::speak();
```

explicitly requests the base implementation.

A qualified virtual call does not perform normal virtual dispatch for
that call.

---

## 17. Pure virtual functions

Sometimes a base class should define an interface but have no general
implementation.

Example:

```cpp
class Shape {
public:
    virtual double area() const = 0;
};
```

The:

```cpp
= 0
```

makes `area()` pure virtual.

A class with at least one pure virtual function is abstract.

---

## 18. Abstract classes

You cannot directly instantiate an abstract class:

```cpp
Shape shape; // ERROR
```

But you can use pointers and references to the abstract base:

```cpp
Shape* ptr;
Shape& ref = someConcreteShape;
```

A concrete derived class can implement the required operation:

```cpp
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height)
        : width(width), height(height) {
    }

    double area() const override {
        return width * height;
    }
};
```

Then:

```cpp
Rectangle rectangle(4, 5);
Shape& shape = rectangle;

cout << shape.area();
```

prints:

```text
20
```

---

## 19. Abstract classes can contain ordinary members

An abstract class is not required to contain only pure virtual
functions.

This is valid:

```cpp
class Shape {
protected:
    string color;

public:
    Shape(const string& color)
        : color(color) {
    }

    const string& getColor() const {
        return color;
    }

    virtual double area() const = 0;

    virtual ~Shape() = default;
};
```

The base can contain:

- constructors
- data members
- ordinary member functions
- virtual functions
- pure virtual functions
- a destructor

---

## 20. Interfaces in C++

C++ does not have a separate `interface` keyword like some languages.

An interface-like base class is often written using pure virtual
functions:

```cpp
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};
```

Different classes can implement the same interface.

```cpp
class Report : public Printable {
public:
    void print() const override {
        cout << "Report\n";
    }
};
```

This lets caller code depend on the abstraction:

```cpp
void printAnything(const Printable& value) {
    value.print();
}
```

---

## 21. Virtual destructors

This rule is extremely important.

Suppose:

```cpp
class Base {
public:
    ~Base() {
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor\n";
    }
};
```

Then:

```cpp
Base* ptr = new Derived;
delete ptr;
```

has undefined behavior because deletion occurs through a base pointer
whose destructor is not virtual.

For a polymorphic base intended to support deletion through the base,
use:

```cpp
class Base {
public:
    virtual ~Base() = default;
};
```

Then:

```cpp
delete ptr;
```

correctly destroys the complete derived object.

---

## 22. Why the virtual destructor matters

Consider a derived class owning a resource:

```cpp
class Derived : public Base {
private:
    int* data;

public:
    Derived()
        : data(new int(42)) {
    }

    ~Derived() override {
        delete data;
    }
};
```

If the complete `Derived` destructor is not reached during deletion,
its cleanup logic cannot correctly run.

A virtual destructor lets deletion through an appropriate base pointer
invoke destruction for the complete dynamic object.

---

## 23. Pure virtual destructor detail

A destructor itself can be pure virtual:

```cpp
class Base {
public:
    virtual ~Base() = 0;
};
```

But unlike many pure virtual functions, a pure virtual destructor still
needs a definition:

```cpp
Base::~Base() {
}
```

This is because base destruction still occurs when a derived object is
destroyed.

This is an advanced detail worth recognizing in interviews.

---

## 24. Virtual calls in constructors

Consider:

```cpp
class Base {
public:
    Base() {
        show();
    }

    virtual void show() const {
        cout << "Base\n";
    }
};
```

If a derived object is being constructed, do not expect the base
constructor's virtual call to dispatch into a derived override.

During execution of a base constructor, virtual dispatch is restricted
to the class currently under construction rather than treating the
not-yet-constructed derived portion as active.

Why?

The derived part is not ready yet.

Analogy:

Do not ask a building's unfinished upper floor to perform work while
the foundation is still being constructed.

---

## 25. Virtual calls in destructors

A similar restriction applies while destruction is occurring.

When the derived portion has already been destroyed, a base destructor
must not dispatch into that destroyed derived portion.

Therefore avoid designs that depend on virtual dispatch from
constructors or destructors.

---

## 26. Data members are not virtual

Suppose:

```cpp
class Base {
public:
    int value = 10;
};

class Derived : public Base {
public:
    int value = 20;
};
```

A derived data member named `value` hides the base name.

There is no virtual data-member dispatch analogous to virtual
functions.

Polymorphic behavior should generally be expressed through virtual
member functions.

---

## 27. Default arguments and virtual functions

A subtle C++ rule:

Virtual dispatch chooses the function body dynamically, but default
arguments are selected using the static type at the call site.

Example:

```cpp
class Base {
public:
    virtual void show(int x = 1) const {
        cout << "Base " << x;
    }
};

class Derived : public Base {
public:
    void show(int x = 2) const override {
        cout << "Derived " << x;
    }
};
```

Then:

```cpp
Derived d;
Base& b = d;

b.show();
```

dispatches to:

```text
Derived::show
```

but supplies the default argument from `Base`:

```text
1
```

so the result is:

```text
Derived 1
```

Because of this, differing default arguments on virtual overrides are
usually best avoided.

---

## 28. How virtual dispatch is commonly implemented

The C++ standard specifies behavior, not one mandatory internal
implementation.

A common implementation uses structures informally called:

```text
vtable
vptr
```

Conceptually:

```text
Object
 |
 +-- hidden implementation pointer
          |
          v
      virtual-function table
          |
          +-- address of final virtual function
```

Do not treat exact vtable layout as guaranteed by the C++ language.

It is an implementation technique used by common compilers.

For DSA and most interviews, understand the behavioral model first.

---

## 29. Cost of virtual dispatch

A virtual function call is still typically treated as:

```text
O(1)
```

However, compared with a directly resolved call it may involve:

- an indirect function call
- implementation-specific per-object metadata
- fewer opportunities for some compiler optimizations in some cases

These are constant-factor considerations, not a change such as
O(1) becoming O(n).

Correct architecture and required polymorphic behavior usually matter
more than prematurely eliminating virtual calls.

---

## 30. A complete polymorphic example

```cpp
class Notification {
public:
    virtual void send() const = 0;
    virtual ~Notification() = default;
};

class Email : public Notification {
public:
    void send() const override {
        cout << "Email sent\n";
    }
};

class SMS : public Notification {
public:
    void send() const override {
        cout << "SMS sent\n";
    }
};

void notify(const Notification& notification) {
    notification.send();
}
```

Then:

```cpp
Email email;
SMS sms;

notify(email);
notify(sms);
```

The same function works with different concrete types.

---

## 31. Dry run of the notification example

First:

```cpp
notify(email);
```

State:

```text
parameter static type:
const Notification&

dynamic object:
Email
```

The call:

```cpp
notification.send();
```

is virtual.

Therefore:

```text
Email::send()
```

runs.

Next:

```cpp
notify(sms);
```

The parameter's static type is still:

```text
const Notification&
```

but its dynamic object is now:

```text
SMS
```

Therefore:

```text
SMS::send()
```

runs.

Caller code did not require separate overloads for every concrete
notification type.

---

## 32. When to use runtime polymorphism

Runtime polymorphism is useful when:

- several types share one meaningful interface
- callers should work through that interface
- the actual behavior depends on the runtime object
- new derived implementations should fit existing caller code

Examples include:

- UI widgets
- game entities
- payment methods
- loggers
- file-like interfaces
- notification systems
- shape hierarchies

---

## 33. When not to use inheritance-based polymorphism

Do not create a hierarchy merely because multiple classes happen to
contain similarly named functions.

Ask whether the base abstraction is meaningful.

Also consider composition when the relationship is:

```text
has-a
```

instead of:

```text
is-a
```

Templates and other techniques can also provide polymorphism without
runtime inheritance. They will be introduced later.

---

## Complexity table

| Operation | Typical complexity |
|---|---:|
| Function-overload selection | Compile-time |
| Direct fixed-work member call | O(1) |
| Virtual fixed-work member call | O(1) |
| Upcast pointer/reference | O(1) |
| Access base through reference | O(1) |
| Destroy fixed-size polymorphic object | O(1) plus destructor work |
| Process n polymorphic objects | O(n) plus method work |
| Virtual method containing O(n) loop | O(n) |

Virtual dispatch changes how a function is selected, not the
asymptotic complexity of the algorithm inside that function.

---

## Common interview and beginner mistakes

1. Believing every same-name derived function automatically overrides
   a base function.

2. Forgetting `virtual` in the base.

3. Omitting `override` and accidentally changing a signature.

4. Confusing overload resolution with overriding.

5. Passing polymorphic objects by value and causing slicing.

6. Expecting virtual dispatch from data members.

7. Deleting a derived object through a base pointer without a virtual
   base destructor.

8. Calling virtual functions from constructors expecting derived
   dispatch.

9. Calling virtual functions from destructors expecting already
   destroyed derived behavior.

10. Giving virtual overrides different default arguments and assuming
    the default is dynamically selected.

11. Assuming `vtable` and `vptr` are guaranteed language-level objects.

12. Forgetting that abstract classes can have constructors, state,
    and ordinary member functions.

13. Trying to instantiate an abstract class.

14. Forgetting a pure virtual destructor still needs a definition.

15. Using inheritance where composition gives a clearer relationship.

---

## Practice questions and references

1. HackerRank — Virtual Functions  
   https://www.hackerrank.com/challenges/virtual-functions/problem

2. GeeksforGeeks — Virtual Functions and Runtime Polymorphism  
   https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/

3. GeeksforGeeks — Pure Virtual Functions and Abstract Classes  
   https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

4. GeeksforGeeks — Virtual Destructor  
   https://www.geeksforgeeks.org/virtual-destructor/

5. LeetCode 1603 — Design Parking System  
   https://leetcode.com/problems/design-parking-system/

The LeetCode design problem does not require inheritance-based
polymorphism, but it is useful practice for class state and interfaces.
For this lesson, also implement the exercises in
`04_practice_problems.cpp`.

---

## Revision checklist

Before moving on, make sure you can explain:

- compile-time polymorphism
- runtime polymorphism
- virtual functions
- overriding
- `override`
- `final`
- static versus dynamic type
- dynamic binding
- base pointers and references
- object slicing
- pure virtual functions
- abstract classes
- interface-like classes
- virtual destructors
- constructor/destructor virtual-call behavior
- why data members are not polymorphic
- virtual functions with default arguments
- the conceptual role of vtables
- when inheritance-based polymorphism is useful

# What's Next

Continue to:

`01_C++__/22_ABSTRACTION_ENCAPSULATION/`

The next lesson connects class design to two major OOP principles:
abstraction and encapsulation.
