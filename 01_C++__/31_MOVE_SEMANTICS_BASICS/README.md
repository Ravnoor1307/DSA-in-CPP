# 31 — Move Semantics Basics

## Learning goals

Move semantics lets C++ transfer resources from objects that no longer
need them instead of performing expensive deep copies.

By the end of this lesson, you should understand:

- lvalues and rvalues at a practical level
- lvalue references
- rvalue references
- `T&&`
- why move semantics exists
- copy construction versus move construction
- copy assignment versus move assignment
- `std::move`
- why `std::move` does not itself move data
- moved-from objects
- valid but unspecified state
- self-move considerations
- the Rule of Three
- the Rule of Five
- the Rule of Zero
- `noexcept` move operations
- moving `std::string`
- moving `std::vector`
- moving `std::unique_ptr`
- returning objects by value
- copy elision
- why `std::move` on a local return value can be counterproductive
- when moving is useful in DSA and containers

This is a foundational lesson. Perfect forwarding and advanced
reference-collapsing rules are outside the scope of this folder.

---

## 1. The problem move semantics solves

Suppose an object owns a large dynamic array:

```text
source
 |
 v
+----------------------+
| pointer ------------ | ------> [many integers]
| size                 |
+----------------------+
```

If we copy it, a correct deep copy may require:

1. allocating new storage
2. copying every element
3. maintaining two independent allocations

For `n` elements, this can cost O(n).

But what if the source is a temporary object that is about to die?

Creating another full copy can be wasteful.

Instead, we can transfer ownership of its existing resource.

That is the central motivation for move semantics.

---

## 2. Copy versus move analogy

Imagine moving house.

Copy semantics would resemble:

```text
Buy an identical second set of furniture.
Copy every possession.
Keep both houses fully furnished.
```

Move semantics resembles:

```text
Transfer the existing furniture to the new owner/location.
The old house no longer owns it.
```

A move transfers a resource when duplicating it is unnecessary.

---

# Part I — Value categories

## 3. Practical meaning of lvalue

A beginner-friendly mental model:

An lvalue usually represents an object with an identity that you can
refer to again.

Example:

```cpp
int value = 10;
```

The expression:

```cpp
value
```

is an lvalue.

It names an existing object.

You can take its address:

```cpp
&value
```

---

## 4. Practical meaning of rvalue

An rvalue often represents a temporary value or value whose resources
may be eligible for reuse.

Examples:

```cpp
42
a + b
std::string("temporary")
```

The complete C++ value-category system is more detailed than
"lvalue versus rvalue," but this simplified model is sufficient for
understanding basic move semantics.

---

## 5. Lvalue references

You already know:

```cpp
int value = 10;
int& reference = value;
```

`reference` is an lvalue reference.

It normally binds to an lvalue.

---

## 6. Rvalue references

C++11 introduced rvalue references:

```cpp
int&& reference = 10;
```

Syntax:

```text
T&&
```

An rvalue reference can bind to an rvalue.

For resource-managing classes, this lets us provide overloads that
recognize objects whose resources may be transferred.

---

## 7. Named rvalue-reference variables are lvalue expressions

This is a famous C++ detail.

Suppose:

```cpp
Widget&& value = Widget();
```

The variable's declared type is an rvalue reference.

But the expression:

```cpp
value
```

has a name and is itself an lvalue expression.

Therefore inside a move constructor:

```cpp
Buffer(Buffer&& other)
```

the expression:

```cpp
other
```

is an lvalue.

This is one reason `std::move(other.member)` is often needed when
moving member objects.

---

# Part II — Copy and Move Construction

## 8. Copy constructor

You learned copy construction earlier:

```cpp
Type(const Type& other);
```

It initializes a new object from an existing object while preserving
the source.

For a resource-owning class, this often means deep copying.

---

## 9. Move constructor

A move constructor has the usual form:

```cpp
Type(Type&& other);
```

Instead of duplicating a resource, it may transfer it.

Example idea:

```cpp
Buffer(Buffer&& other) noexcept
    : data(other.data),
      size(other.size) {
    other.data = nullptr;
    other.size = 0;
}
```

The destination takes the pointer.

The source relinquishes ownership.

---

## 10. Dry run: move constructor

Suppose:

```text
source.data ----> [10, 20, 30]
source.size = 3
```

Now:

```cpp
Buffer destination(std::move(source));
```

Step 1:

```text
destination.data = source.data
```

State:

```text
destination.data --+
                   |
                   v
             [10, 20, 30]
                   ^
                   |
source.data -------+
```

Temporarily both pointers hold the same address.

Step 2:

```cpp
source.data = nullptr;
source.size = 0;
```

Final:

```text
destination.data ----> [10, 20, 30]
destination.size = 3

source.data = nullptr
source.size = 0
```

Only the destination owns the allocation.

No three-element copy occurred.

---

## 11. Why the source must relinquish ownership

Suppose we transferred the pointer but forgot:

```cpp
other.data = nullptr;
```

Then:

```text
source.data --------+
                    |
                    v
                  memory
                    ^
                    |
destination.data ---+
```

Both destructors would later call:

```cpp
delete[] data;
```

on the same allocation.

That would be undefined behavior.

A move operation must leave ownership relationships valid.

---

# Part III — `std::move`

## 12. What `std::move` actually does

This is crucial:

```cpp
std::move(object)
```

does not itself transfer resources.

At a high level, it casts its argument to an rvalue-like expression,
allowing move-aware overload resolution.

Example:

```cpp
Buffer b = std::move(a);
```

`std::move(a)` makes `a` eligible to bind to:

```cpp
Buffer(Buffer&&)
```

The move constructor performs the actual transfer.

---

## 13. `std::move` can still result in copying

If a type has no usable move operation, this:

```cpp
T b = std::move(a);
```

may still call a copy operation if that is the viable overload.

Therefore never think:

```text
std::move == guaranteed resource transfer
```

Better mental model:

```text
std::move says:
"Treat this object as eligible to be moved from."
```

---

## 14. Include `<utility>`

`std::move` is declared in:

```cpp
#include <utility>
```

Do not rely on another header accidentally making it available.

---

# Part IV — Move Assignment

## 15. Copy assignment

Copy assignment modifies an already-existing object:

```cpp
destination = source;
```

Typical signature:

```cpp
Type& operator=(const Type& other);
```

A resource owner may need to release or replace its current resource and
then copy the source.

---

## 16. Move assignment

Move assignment typically has this form:

```cpp
Type& operator=(Type&& other) noexcept;
```

Conceptually:

```text
destination already owns resource A
source owns resource B

move assignment:
1. release destination's A
2. take source's B
3. empty source
```

Afterward:

```text
destination owns B
source owns nothing
A has been released
```

---

## 17. Dry run: move assignment

Before:

```text
destination ----> [1, 2]
source ---------> [7, 8, 9]
```

Operation:

```cpp
destination = std::move(source);
```

Step 1:

```text
delete destination's old [1, 2]
```

Step 2:

```text
destination takes pointer to [7, 8, 9]
```

Step 3:

```text
source pointer becomes nullptr
source size becomes 0
```

Final:

```text
destination ----> [7, 8, 9]
source ---------> null
```

---

# Part V — Moved-From Objects

## 18. What state is a moved-from object in?

For standard-library objects, unless a stronger post-move guarantee is
documented, moved-from objects are generally valid but in an
unspecified state.

"Valid" means operations with no unmet preconditions remain safe, such
as assigning a new value or destroying the object.

"Unspecified" means you should not assume a particular old/new content.

Example:

```cpp
std::string first = "hello";
std::string second = std::move(first);
```

Do not write an algorithm that assumes:

```cpp
first.empty()
```

must be true.

It often is empty in implementations, but the generic rule is not to
depend on unspecified moved-from contents unless the type documents a
specific guarantee.

---

## 19. Our own moved-from states

For a custom class, we can deliberately choose a known valid state:

```cpp
other.data = nullptr;
other.size = 0;
```

Then our own class contract may document the moved-from state as empty.

The standard-library's general "valid but unspecified" rule is broader.

---

## 20. Reusing a moved-from object

This is often fine:

```cpp
std::string a = "hello";
std::string b = std::move(a);

a = "new value";
```

Assignment establishes a new known value.

Likewise, destruction of a moved-from object must remain valid.

---

# Part VI — Rule of Three, Five, and Zero

## 21. Rule of Three

Before move semantics, a resource-owning class that needed one of these
often needed all three:

```text
destructor
copy constructor
copy assignment operator
```

Why?

If a class manually owns a resource, default copying may duplicate only
the handle/pointer rather than the resource.

This is called the Rule of Three.

---

## 22. Rule of Five

Modern C++ adds:

```text
move constructor
move assignment operator
```

Therefore the relevant resource-management set becomes:

```text
1. destructor
2. copy constructor
3. copy assignment
4. move constructor
5. move assignment
```

This is the Rule of Five.

It is a design guideline rather than a magical compiler rule.

---

## 23. Rule of Zero

The better goal is often the Rule of Zero:

```text
Design your class so it does not manually manage raw resources.
```

Use members that already manage themselves:

```cpp
std::string
std::vector
std::unique_ptr
```

Then your class may need to write none of the five custom operations.

Example:

```cpp
class Student {
private:
    std::string name;
    std::vector<int> marks;
};
```

The member types already know how to copy, move, and destroy
themselves.

Rule of Zero is a major modern C++ design principle.

---

# Part VII — `noexcept`

## 24. Why move operations often use `noexcept`

Move constructors frequently look like:

```cpp
Type(Type&& other) noexcept;
```

Why does this matter?

Standard containers sometimes need to relocate elements.

If moving an element could throw, preserving strong exception-safety
guarantees can become difficult.

For some types and operations, a standard container may prefer copying
instead of moving when the move constructor is not known to be
non-throwing.

Therefore:

```text
correct noexcept move operations
```

can help containers use moves safely and efficiently.

---

## 25. Do not write `noexcept` dishonestly

If a function marked:

```cpp
noexcept
```

allows an exception to escape, the program calls:

```cpp
std::terminate()
```

Only declare a move operation `noexcept` when its implementation
actually satisfies that promise.

Moving a raw pointer and integer size is naturally non-throwing.

Moving arbitrary member objects may depend on those members.

---

# Part VIII — Standard Library Moves

## 26. Moving `std::string`

Example:

```cpp
std::string source = "large text";
std::string destination = std::move(source);
```

A string implementation may transfer internal dynamically allocated
storage instead of copying each character.

Afterward:

```text
destination contains the transferred value
source remains valid but its contents should not be assumed unless
documented
```

---

## 27. Moving `std::vector`

A vector can own a dynamically allocated element buffer.

Copy:

```cpp
std::vector<int> b = a;
```

conceptually needs a second independent sequence.

Move:

```cpp
std::vector<int> b = std::move(a);
```

can often transfer the buffer-management state.

Conceptually:

```text
Before:

a ----> [1,2,3,4,...]

After move:

b ----> [1,2,3,4,...]
a ----> valid moved-from state
```

This can turn an otherwise element-wise transfer into a much cheaper
ownership transfer in common allocator situations.

Precise standard complexity can depend on the specific operation and
allocator conditions, especially for assignment.

---

## 28. Moving `unique_ptr`

You already used:

```cpp
auto second = std::move(first);
```

with `unique_ptr`.

This is one of the clearest examples of move-only ownership.

Copying a `unique_ptr` is forbidden.

Moving transfers its exclusive ownership.

---

# Part IX — Returning Objects

## 29. Return by value is often efficient

Consider:

```cpp
std::string makeMessage() {
    std::string message = "hello";
    return message;
}
```

Modern C++ can efficiently return objects by value through:

- copy elision
- moves when needed

Do not automatically return pointers merely to avoid imagined copies.

Return-by-value is an important modern C++ style.

---

## 30. Copy elision

Sometimes C++ constructs the final result directly rather than first
constructing one object and then copying/moving it.

Example:

```cpp
Widget makeWidget() {
    return Widget();
}
```

In C++17, certain prvalue cases have guaranteed copy-elision semantics.

Named local return optimization (NRVO), such as:

```cpp
Widget makeWidget() {
    Widget value;
    return value;
}
```

is a common permitted optimization but is not universally guaranteed in
every possible case.

---

## 31. Avoid unnecessary `std::move` on local return

A common beginner mistake:

```cpp
Widget makeWidget() {
    Widget value;
    return std::move(value);
}
```

This can prevent NRVO.

Usually write:

```cpp
return value;
```

The language/compiler can apply copy elision or move from the eligible
local when appropriate.

Do not force `std::move` into every return statement.

---

# Part X — `const` and Moving

## 32. Moving from const often copies

Suppose a normal move constructor requires:

```cpp
Type(Type&&);
```

Now:

```cpp
const Type source;
Type destination = std::move(source);
```

`std::move(source)` is effectively const-qualified.

A normal:

```cpp
Type&&
```

cannot bind in a way that permits modifying a const source.

A copy constructor such as:

```cpp
Type(const Type&)
```

may therefore be selected.

Why?

Moving usually needs to modify the source's ownership state.

Const says the source cannot be modified.

---

## 33. Practical rule

Do not make an object `const` if you intend later to transfer its
resources through ordinary move semantics.

This:

```cpp
const std::string value = ...;
```

communicates that `value` will not be modified.

Moving resources out normally conflicts with that promise.

---

# Part XI — Self-Move

## 34. Self-move assignment

Artificial code can do:

```cpp
object = std::move(object);
```

A naive move-assignment operator may release the resource and then try
to take it from the same now-modified object.

Production types should follow the requirements appropriate to their
interfaces, and simple custom educational implementations often guard:

```cpp
if (this != &other) {
    ...
}
```

Self-move is uncommon in ordinary beginner code, but knowing it exists
helps when implementing ownership types.

---

# Part XII — Move Semantics in DSA

## 35. Why DSA programmers should care

Move semantics matters when working with:

- vectors of large objects
- strings
- returned containers
- heap/tree nodes with ownership
- smart pointers
- temporary algorithm states
- custom data structures
- priority queues and STL containers

You rarely need to manually write move operations for ordinary contest
structs.

But understanding moves explains why modern C++ can pass and return
large resource-owning values efficiently.

---

## 36. Complexity comparison

For a custom dynamic buffer with `n` elements:

```text
Deep copy:
allocate n-element buffer
copy n elements
Time: O(n)
Additional owned storage: O(n)

Move:
transfer pointer + size
clear source ownership
Time: O(1)
Additional element storage: O(1)
```

This O(1) move assumes the resource can be transferred by fixed-size
metadata and that allocator/resource constraints permit it.

Not every move operation is automatically O(1).

A type's move implementation determines the complexity.

---

## Complexity table

| Operation | Typical simple resource-owner time | Extra space |
|---|---:|---:|
| Copy fixed primitive | O(1) | O(1) |
| Move fixed primitive | O(1) | O(1) |
| Deep-copy n-element buffer | O(n) | O(n) |
| Move pointer-owned buffer | O(1) | O(1) |
| Move `unique_ptr` | O(1) | O(1) |
| `std::move` cast itself | O(1) conceptual | O(1) |
| Destroy moved-from empty custom buffer | O(1) | O(1) |
| Move construction of typical vector storage | Often O(1)* | O(1)* |
| Copy vector of n elements | O(n) | O(n) |

`*` Exact guarantees can depend on operation and allocator-related
conditions. Never assume every user-defined move is O(1).

---

## Common interview and beginner mistakes

1. Saying `std::move` physically moves an object.

2. Believing an rvalue reference automatically transfers ownership.

3. Forgetting that a named rvalue-reference parameter is an lvalue
   expression.

4. Using a moved-from standard object while assuming its old contents.

5. Forgetting to clear raw ownership from the source in a custom move
   constructor.

6. Causing double deletion after a move.

7. Forgetting to release destination's old resource during move
   assignment.

8. Ignoring self-assignment/self-move considerations in custom resource
   code.

9. Writing a destructor but relying on unsafe compiler-generated copying
   for a raw resource owner.

10. Memorizing the Rule of Five while ignoring the preferable Rule of
    Zero.

11. Marking a potentially throwing operation `noexcept`.

12. Forgetting `noexcept` where a genuinely non-throwing move benefits
    container behavior.

13. Writing:

```cpp
return std::move(local);
```

without understanding that it can inhibit NRVO.

14. Assuming every move is O(1).

15. Attempting to move from a const object and expecting an ordinary
    destructive move.

16. Writing custom copy/move operations when standard RAII members can
    manage the resource automatically.

---

## Practice questions and references

1. cppreference — Move constructors  
   https://en.cppreference.com/w/cpp/language/move_constructor

2. cppreference — Move assignment  
   https://en.cppreference.com/w/cpp/language/move_assignment

3. cppreference — `std::move`  
   https://en.cppreference.com/w/cpp/utility/move

4. GeeksforGeeks — Move Constructors in C++  
   https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/

5. GeeksforGeeks — Rule of Five in C++  
   https://www.geeksforgeeks.org/rule-of-five-in-cpp/

---

## Revision checklist

Before moving on, make sure you can explain:

- practical lvalue versus rvalue
- lvalue reference
- rvalue reference
- `T&&`
- copy constructor
- move constructor
- copy assignment
- move assignment
- `std::move`
- why `std::move` is a cast rather than a physical move
- moved-from states
- source ownership reset
- Rule of Three
- Rule of Five
- Rule of Zero
- `noexcept`
- moving `unique_ptr`
- moving strings/vectors
- return-by-value
- copy elision
- NRVO
- why `return std::move(local)` is usually undesirable
- const interaction with moving
- move complexity

# What's Next

Continue to:

`01_C++__/32_STL_BASICS/`

The next lesson introduces the Standard Template Library model:
containers, iterators, algorithms, function objects, sequence versus
associative containers, iterator ranges, common container operations,
and how the STL connects templates, lambdas, and generic algorithms.
