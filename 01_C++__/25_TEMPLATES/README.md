# 25 — Templates in C++

## Learning goals

Templates are one of C++'s main tools for generic programming.

By the end of this lesson, you should understand:

- why templates exist
- function templates
- `template<typename T>`
- `typename` versus `class`
- template argument deduction
- explicit template arguments
- multiple template parameters
- return types involving template parameters
- class templates
- member functions of class templates
- non-type template parameters
- template instantiation
- compile-time type checking
- function-template overloading
- specialization basics
- full specialization
- class-template specialization basics
- templates with references and const
- templates with operator requirements
- why template definitions normally live in headers
- generic programming in DSA
- common template errors and limitations

This lesson uses only C++17 features.

---

## 1. The repetition problem

Suppose you want a function that returns the larger of two integers:

```cpp
int bigger(int a, int b) {
    return a > b ? a : b;
}
```

Later you need the same operation for `double`:

```cpp
double bigger(double a, double b) {
    return a > b ? a : b;
}
```

Then perhaps for `long long`:

```cpp
long long bigger(long long a, long long b) {
    return a > b ? a : b;
}
```

The algorithm is the same.

Only the type changes.

Templates let us express the common pattern once.

---

## 2. Function templates

A function template can be written as:

```cpp
template <typename T>
T bigger(T a, T b) {
    return a > b ? a : b;
}
```

Usage:

```cpp
cout << bigger(10, 20);
cout << bigger(3.5, 1.2);
```

The compiler works with appropriate concrete types based on the calls.

---

## 3. Real-world analogy

Think of a cookie cutter.

The cutter describes a shape once.

You can use different dough:

```text
chocolate dough
vanilla dough
gingerbread dough
```

The pattern remains the same while the material changes.

A template similarly describes code in terms of parameters that can
later be replaced with appropriate concrete template arguments.

The analogy is imperfect because C++ performs strict compile-time type
checking, but it captures the central idea of reusable structure.

---

## 4. `typename T`

This:

```cpp
template <typename T>
```

introduces a type template parameter named `T`.

Inside the template:

```cpp
T
```

represents the type supplied or deduced for that instantiation.

Example:

```cpp
template <typename T>
T square(T value) {
    return value * value;
}
```

Calling:

```cpp
square(5)
```

can instantiate behavior with:

```text
T = int
```

Calling:

```cpp
square(2.5)
```

can use:

```text
T = double
```

---

## 5. `typename` versus `class`

For a basic type template parameter, these are generally equivalent:

```cpp
template <typename T>
```

and:

```cpp
template <class T>
```

Modern code commonly uses `typename` when the parameter represents an
arbitrary type because it communicates the intent clearly.

Do not confuse:

```cpp
template <class T>
```

with inheritance or the declaration of an ordinary concrete class.

Here `class` introduces a type template parameter.

---

## 6. Template argument deduction

Given:

```cpp
template <typename T>
T maximum(T a, T b);
```

and:

```cpp
maximum(10, 20);
```

the compiler can deduce:

```text
T = int
```

You usually do not have to write:

```cpp
maximum<int>(10, 20);
```

However, explicit template arguments are possible.

---

## 7. Explicit template arguments

Example:

```cpp
maximum<int>(10, 20);
maximum<double>(3.5, 8.2);
```

The values between `<` and `>` are template arguments.

This can be useful when deduction is impossible or when you
intentionally want to specify a template argument.

---

## 8. Deduction with different argument types

Consider:

```cpp
template <typename T>
T maximum(T a, T b);
```

Now call:

```cpp
maximum(10, 2.5);
```

One argument suggests:

```text
T = int
```

while the other suggests:

```text
T = double
```

For this simple template, deduction cannot choose one `T` that directly
matches both parameter deductions.

One solution is to use two template type parameters.

---

## 9. Multiple template parameters

Example:

```cpp
template <typename T, typename U>
void showPair(const T& first, const U& second) {
    cout << first << ' ' << second;
}
```

Usage:

```cpp
showPair(10, 3.5);
showPair(string("age"), 20);
```

Now the two argument types can differ.

---

## 10. Different return type

Sometimes an operation involving two types should have a result type
determined by the expression.

In C++17:

```cpp
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
```

Or C++14 and later can often simply use:

```cpp
template <typename T, typename U>
auto add(T a, U b) {
    return a + b;
}
```

The compiler deduces the return type from:

```cpp
a + b
```

Example:

```cpp
add(10, 2.5)
```

naturally produces the type of:

```cpp
int + double
```

which is `double`.

---

## 11. Dry run of function-template instantiation

Consider:

```cpp
template <typename T>
T twice(T value) {
    return value + value;
}
```

Call:

```cpp
twice(5);
```

Conceptually:

```text
Step 1:
Compiler sees argument type int.

Step 2:
T is deduced as int.

Step 3:
The template is instantiated for int.

Conceptual resulting function:

int twice(int value) {
    return value + value;
}

Step 4:
value = 5

Step 5:
5 + 5 = 10
```

The compiler does not literally have to perform textual replacement in
this exact way internally, but this is a useful beginner mental model.

---

## 12. Templates are compile-time checked

Templates are not an "accept absolutely anything" mechanism.

Suppose:

```cpp
template <typename T>
T square(T value) {
    return value * value;
}
```

The chosen type must support the operation used:

```cpp
value * value
```

If a type does not support multiplication in the required way, the
corresponding template use fails to compile.

Therefore templates are generic but still type checked.

---

## 13. Implicit requirements

Consider:

```cpp
template <typename T>
T maximum(const T& a, const T& b) {
    return a < b ? b : a;
}
```

This template implicitly requires `T` to support:

```cpp
a < b
```

in a form usable as the condition.

Before C++20 concepts, such requirements are often communicated by:

- documentation
- template implementation
- conventions
- advanced template techniques

C++20 introduced concepts, but this repository currently targets
C++17.

---

# Part II — Class Templates

## 14. Why class templates?

Suppose we create an integer container:

```cpp
class IntBox {
private:
    int value;
};
```

Then a double container:

```cpp
class DoubleBox {
private:
    double value;
};
```

The structure is nearly identical.

A class template lets the stored type be a parameter.

---

## 15. Basic class template

```cpp
template <typename T>
class Box {
private:
    T value;

public:
    Box(const T& value)
        : value(value) {
    }

    const T& get() const {
        return value;
    }
};
```

Usage:

```cpp
Box<int> a(10);
Box<double> b(3.14);
Box<string> c("DSA");
```

These are distinct class-template specializations.

---

## 16. Class-template syntax

This:

```cpp
Box<int>
```

means:

```text
Box instantiated with T = int
```

This:

```cpp
Box<string>
```

means:

```text
Box instantiated with T = string
```

Conceptually:

```text
Box<T>
├── Box<int>
├── Box<double>
└── Box<string>
```

Each specialization is a distinct type.

---

## 17. Class template member functions

Member functions can use the template parameter:

```cpp
template <typename T>
class Box {
private:
    T value;

public:
    void set(const T& value) {
        this->value = value;
    }

    const T& get() const {
        return value;
    }
};
```

For:

```cpp
Box<int>
```

these operations work with `int`.

For:

```cpp
Box<string>
```

they work with `string`.

---

## 18. Defining template members outside the class

Suppose:

```cpp
template <typename T>
class Box {
private:
    T value;

public:
    Box(const T& value);
    const T& get() const;
};
```

Definitions require repeating the template declaration:

```cpp
template <typename T>
Box<T>::Box(const T& value)
    : value(value) {
}
```

and:

```cpp
template <typename T>
const T& Box<T>::get() const {
    return value;
}
```

Notice both:

```text
template <typename T>
Box<T>::
```

---

## 19. Multiple parameters in class templates

Example:

```cpp
template <typename First, typename Second>
class Pair {
private:
    First first;
    Second second;
};
```

Usage:

```cpp
Pair<string, int>
Pair<int, double>
```

Different template parameters can represent different roles.

This idea appears heavily throughout the STL.

---

# Part III — Non-Type Template Parameters

## 20. Values can also be template parameters

A template parameter does not always have to represent a type.

Example:

```cpp
template <typename T, int Size>
class FixedArray {
private:
    T values[Size];
};
```

Usage:

```cpp
FixedArray<int, 5> a;
FixedArray<double, 10> b;
```

Here:

```text
T    -> type parameter
Size -> non-type template parameter
```

The size is known at compile time.

---

## 21. Why non-type parameters are useful

Suppose:

```cpp
FixedArray<int, 5>
```

and:

```cpp
FixedArray<int, 10>
```

These are different types.

The size becomes part of the type itself.

This is similar to the idea behind:

```cpp
std::array<T, N>
```

which you will study during the STL material.

---

## 22. Dry run of a class template

Given:

```cpp
Box<int> number(42);
```

Conceptually:

```text
T = int

Object:
+------------+
| value = 42 |
+------------+
```

Now:

```cpp
Box<string> word("DSA");
```

conceptually:

```text
T = string

Object:
+---------------+
| value = "DSA" |
+---------------+
```

The class structure is generic while each instantiated object has a
specific concrete type.

---

# Part IV — Overloading and Specialization

## 23. Function-template overloading

Templates can participate in normal function overloading.

Example:

```cpp
template <typename T>
void print(const T& value) {
    cout << "Generic: " << value;
}

void print(int value) {
    cout << "Integer: " << value;
}
```

For:

```cpp
print(10);
```

normal overload-resolution rules determine which candidate is best.

Templates do not disable ordinary overloading.

---

## 24. Full function-template specialization

A template may have an explicit specialization for a specific type.

Primary template:

```cpp
template <typename T>
void describe(const T&) {
    cout << "Generic\n";
}
```

Full specialization:

```cpp
template <>
void describe<string>(const string&) {
    cout << "String\n";
}
```

Now `string` receives specialized behavior.

For many function customization cases, ordinary overloads are often
simpler and more flexible than explicit function-template
specialization.

Still, you should recognize the syntax.

---

## 25. Class-template specialization

Class templates can also be specialized.

Primary template:

```cpp
template <typename T>
class Printer {
public:
    void print(const T& value) const {
        cout << value;
    }
};
```

Specialization:

```cpp
template <>
class Printer<bool> {
public:
    void print(bool value) const {
        cout << (value ? "true" : "false");
    }
};
```

`Printer<bool>` now has a different implementation from the primary
template.

---

## 26. Partial specialization preview

Class templates can also support partial specialization.

For example, advanced generic code can provide behavior for a family
of template arguments rather than one exact type.

Function templates cannot be partially specialized in the same way.

Partial specialization becomes more relevant in advanced template and
library programming.

At this stage, understand the distinction:

```text
full specialization:
exact template-argument pattern

partial specialization:
family of class-template argument patterns
```

---

## 27. Templates and references

Generic functions often avoid copying with references:

```cpp
template <typename T>
void print(const T& value) {
    cout << value;
}
```

For a read-only parameter:

```cpp
const T&
```

is common.

For a modifying operation:

```cpp
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

The references let the function modify the original objects.

---

## 28. Template swap dry run

Given:

```text
a = 10
b = 20
```

Call:

```cpp
swapValues(a, b);
```

with:

```text
T = int
```

Steps:

```text
temp = a
temp = 10

a = b
a = 20

b = temp
b = 10
```

Final:

```text
a = 20
b = 10
```

The same template may work for other assignable/copyable types.

---

## 29. Templates and overloaded operators

Suppose a generic function contains:

```cpp
a < b
```

Then the instantiated type needs a suitable `<`.

This connects templates directly with operator overloading.

For a custom type:

```cpp
class Score {
public:
    bool operator<(const Score&) const;
};
```

a generic `maximum` implementation using `<` can then operate on
`Score`.

This is one of the reasons operators are important in generic C++.

---

## 30. Templates and code generation

It is useful to imagine:

```cpp
maximum<int>
maximum<double>
```

as different instantiations.

Templates can therefore increase generated program code when many
different concrete specializations are instantiated.

This effect is sometimes called code bloat.

Modern compilers and linkers can optimize many cases, but template
instantiation is not literally "one runtime function handling every
possible type."

---

## 31. Templates are usually resolved at compile time

Templates are fundamentally different from runtime polymorphism.

Runtime polymorphism:

```text
base reference/pointer
virtual function
dynamic dispatch
```

Template polymorphism:

```text
type known during compilation
template instantiated
operations checked for that type
```

Comparison:

```text
Templates                Virtual functions
------------------------------------------------
compile-time mechanism   runtime dispatch mechanism
no base class required   inheritance normally involved
generic types            shared runtime interface
```

Both are useful forms of polymorphism.

---

## 32. Why template definitions usually live in headers

Imagine:

```cpp
// box.h
template <typename T>
class Box {
public:
    T get() const;
};
```

and the function definition exists only in a separate `.cpp`.

When another translation unit tries to instantiate:

```cpp
Box<int>
```

the compiler generally needs to see the template definition.

For this reason, template definitions are commonly kept:

- directly in header files
- or in implementation files included by headers

There are explicit-instantiation techniques, but they are beyond this
introductory lesson.

The dedicated namespaces/header-files lesson comes later.

---

## 33. Generic programming and DSA

Templates are extremely important in data structures.

Instead of writing:

```text
IntStack
DoubleStack
StringStack
```

we could eventually design:

```cpp
Stack<int>
Stack<double>
Stack<string>
```

Similarly:

```cpp
Node<int>
Node<string>

Tree<int>
Tree<long long>

Heap<int>
Heap<MyType>
```

Templates let the data-structure algorithm remain generic where the
operations it requires are supported.

---

## 34. Example: generic fixed stack

Conceptually:

```cpp
template <typename T, int Capacity>
class Stack {
private:
    T values[Capacity];
    int size = 0;

public:
    bool push(const T& value) {
        if (size == Capacity) {
            return false;
        }

        values[size++] = value;
        return true;
    }
};
```

Usage:

```cpp
Stack<int, 5>
Stack<string, 10>
```

The stack rules remain the same while the element type changes.

---

## 35. Do not make everything a template

Templates are useful when genuinely generic behavior exists.

Do not replace:

```cpp
void printStudent(const Student& student);
```

with a template merely because templates seem more advanced.

Templates can:

- make errors harder to read
- increase compile time
- increase generated code
- unnecessarily broaden an API

Use them when type-independent structure or behavior is meaningful.

---

## 36. Complexity

Templates do not automatically improve or worsen Big-O complexity.

A generic function:

```cpp
template <typename T>
T maximum(T a, T b)
```

still performs constant work:

```text
O(1)
```

A generic algorithm traversing `n` elements is still:

```text
O(n)
```

Template instantiation is primarily a compile-time mechanism.

The algorithm's operations determine runtime complexity.

---

## Complexity table

| Template operation | Runtime time | Extra runtime space |
|---|---:|---:|
| Generic maximum of 2 values | O(1) | O(1) |
| Generic swap | O(1)* | O(1)* |
| `Box<T>::get()` | O(1) | O(1) |
| Fixed-array index | O(1) | O(1) |
| Traverse n generic items | O(n) | O(1) auxiliary |
| Copy n generic items | O(n) | Depends |
| Search n generic items | O(n) | O(1) |

`*` assumes operations on `T` are treated as constant-time. For a
complex user-defined type, copying or assignment itself may have
non-constant complexity.

---

## Common interview and beginner mistakes

1. Copy-pasting the same function for many types instead of recognizing
   genuinely generic behavior.

2. Thinking `typename T` means any value will automatically work.

3. Forgetting that operations inside a template must be valid for the
   instantiated type.

4. Expecting one type parameter to deduce successfully from conflicting
   argument types.

5. Confusing `typename` with a runtime variable.

6. Forgetting `<T>` when referring to a class-template specialization.

7. Forgetting the template declaration when defining class-template
   members outside the class.

8. Thinking `Box<int>` and `Box<double>` are the same type.

9. Confusing runtime polymorphism with templates.

10. Assuming templates change the algorithm's Big-O complexity.

11. Returning references to local variables from templates.

12. Passing large generic objects by value unnecessarily.

13. Using explicit specialization when an ordinary overload is clearer.

14. Assuming function templates support partial specialization like
    class templates do.

15. Placing template definitions only in a `.cpp` and then encountering
    instantiation/linking problems elsewhere.

16. Forgetting that custom types may need overloaded operators for
    generic algorithms that use those operators.

17. Making code a template when there is no meaningful generic need.

---

## Practice questions and references

1. HackerRank — C++ Class Templates  
   https://www.hackerrank.com/challenges/c-class-templates/problem

2. HackerRank — Preprocessor Solution  
   https://www.hackerrank.com/challenges/preprocessor-solution/problem

3. GeeksforGeeks — Templates in C++  
   https://www.geeksforgeeks.org/templates-cpp/

4. GeeksforGeeks — Function Templates  
   https://www.geeksforgeeks.org/function-templates-in-cpp/

5. GeeksforGeeks — Class Templates  
   https://www.geeksforgeeks.org/class-templates-in-cpp/

The HackerRank preprocessor exercise is supplementary rather than a
template-specific problem. Prioritize the class-template challenge and
the exercises in this lesson.

---

## Revision checklist

Before moving on, make sure you can explain:

- why templates exist
- function templates
- `typename T`
- `typename` versus `class`
- deduction
- explicit template arguments
- multiple type parameters
- deduced return types
- class templates
- `Box<int>` versus `Box<double>`
- out-of-class template-member definitions
- non-type template parameters
- template instantiation
- operator requirements
- template overloading
- full specialization
- class specialization
- partial-specialization concept
- generic references
- templates versus runtime polymorphism
- why template definitions are usually visible in headers
- how templates apply to DSA

# What's Next

Continue to:

`01_C++__/26_EXCEPTION_HANDLING/`

The next lesson introduces `try`, `throw`, `catch`, exception objects,
stack unwinding, standard exceptions, exception safety, RAII
connections, and when exceptions should or should not be used.
