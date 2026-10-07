# 30 — Smart Pointers and RAII

## Learning goals

This lesson connects object lifetime, destructors, exceptions, and
dynamic memory into modern C++ resource management.

By the end, you should understand:

- resource ownership
- owning versus non-owning pointers
- RAII
- why raw `new`/`delete` is fragile
- `std::unique_ptr`
- `std::make_unique`
- exclusive ownership
- transferring ownership with `std::move`
- `get()`, `release()`, and `reset()`
- custom deleters
- `std::shared_ptr`
- `std::make_shared`
- reference counting
- `use_count()`
- shared ownership
- `std::weak_ptr`
- `lock()`
- `expired()`
- shared-pointer cycles
- breaking cycles with `weak_ptr`
- smart pointers and polymorphism
- exception safety
- RAII beyond memory
- why smart pointers are not always needed
- choosing between automatic objects, `unique_ptr`, `shared_ptr`,
  `weak_ptr`, and raw non-owning pointers

---

## 1. The real problem is ownership

You already know how to allocate dynamic memory:

```cpp
int* value = new int(42);

delete value;
```

The syntax itself is not the difficult part.

The important question is:

```text
Who owns the allocation?
```

Ownership means responsibility for eventually releasing a resource.

If the program cannot answer that clearly, memory-management bugs become
likely.

---

## 2. Raw owning pointers are fragile

Consider:

```cpp
void work() {
    int* data = new int[100];

    riskyOperation();

    delete[] data;
}
```

If `riskyOperation()` throws, normal execution skips:

```cpp
delete[] data;
```

The allocation can leak.

There are other risks:

- early `return`
- forgetting `delete`
- using the wrong `delete[]`
- deleting twice
- copying an owning pointer
- unclear responsibility

Modern C++ prefers resource ownership tied to object lifetime.

---

## 3. What is RAII?

RAII means:

```text
Resource Acquisition Is Initialization
```

The name is historical, but the central idea is:

```text
Tie resource lifetime to object lifetime.
```

Conceptually:

```text
RAII object constructed
       |
       +---- acquires/owns resource
       |
       v
resource is usable
       |
       v
scope ends / exception occurs
       |
       v
RAII object destructor
       |
       +---- releases resource
```

This makes cleanup automatic.

---

## 4. Real-world analogy

Imagine checking a coat into a managed locker.

The locker token represents responsibility for the coat.

When the token's management lifetime ends, the process knows how to
return or clean up the resource.

Compare that with leaving the coat somewhere and writing:

```text
Remember to retrieve this manually later.
```

RAII replaces fragile "remember later" cleanup with lifetime-based
cleanup.

---

## 5. RAII is broader than memory

RAII can manage:

- dynamic memory
- files
- mutex locks
- sockets
- database resources
- temporary state
- operating-system handles

A destructor performs cleanup when the managing object's lifetime ends.

Smart pointers are RAII objects specifically for pointer ownership.

---

# Part I — `std::unique_ptr`

## 6. Exclusive ownership

A `std::unique_ptr<T>` represents exclusive ownership of a dynamically
managed `T`.

Example:

```cpp
std::unique_ptr<int> value =
    std::make_unique<int>(42);
```

When `value` is destroyed, its owned integer is automatically deleted.

No explicit:

```cpp
delete
```

is needed.

---

## 7. Prefer `make_unique`

Instead of:

```cpp
std::unique_ptr<int> p(new int(42));
```

prefer:

```cpp
auto p = std::make_unique<int>(42);
```

Benefits include:

- shorter syntax
- clearer ownership intent
- safer composition in more complicated expressions
- no exposed raw `new`

`make_unique` is the normal modern C++ choice when directly creating an
object for unique ownership.

---

## 8. Dereferencing a unique pointer

Smart pointers provide pointer-like operations:

```cpp
auto number = std::make_unique<int>(42);

std::cout << *number;
```

For an object:

```cpp
auto player = std::make_unique<Player>();

player->show();
```

The syntax resembles raw pointers, but ownership cleanup is automatic.

---

## 9. Unique pointers cannot be copied

This is intentionally forbidden:

```cpp
auto first = std::make_unique<int>(10);

// auto second = first; // ERROR
```

Why?

If both pointers claimed exclusive ownership, who should delete the
object?

Copying would contradict uniqueness.

---

## 10. Ownership can be transferred

A unique pointer can be moved:

```cpp
auto first = std::make_unique<int>(10);

auto second = std::move(first);
```

Conceptually:

```text
Before:

first --------> [10]
second         does not exist

After move:

first --------> nullptr
second -------> [10]
```

The resource itself does not need to be copied.

Ownership is transferred.

Move semantics receive deeper treatment in the next lesson.

---

## 11. Dry run: unique ownership

Start:

```cpp
auto owner = std::make_unique<int>(50);
```

State:

```text
owner ----> [50]
```

Then:

```cpp
auto newOwner = std::move(owner);
```

State:

```text
owner -------> null
newOwner ----> [50]
```

At scope exit:

```text
newOwner destroyed
      |
      v
[50] deleted automatically
```

`owner` no longer owns the allocation.

---

## 12. Checking a smart pointer

Smart pointers can be tested:

```cpp
if (pointer) {
    std::cout << *pointer;
}
```

An empty `unique_ptr` evaluates as false.

After moving from one:

```cpp
auto second = std::move(first);

if (!first) {
    // first no longer owns an object
}
```

---

## 13. `get()`

`get()` returns the stored raw pointer:

```cpp
int* raw = pointer.get();
```

This does not transfer ownership.

Conceptually:

```text
unique_ptr owner ----+
                     |
                     v
                   [42]
                     ^
                     |
raw observer --------+
```

The smart pointer still owns the object.

Do not manually:

```cpp
delete raw;
```

while the smart pointer still owns it.

That would cause invalid ownership and potentially double deletion.

---

## 14. Raw pointers can be non-owning observers

Raw pointers are not automatically bad.

This is a valid use:

```cpp
void print(const Player* player) {
    if (player) {
        player->show();
    }
}
```

If the function merely observes an object and does not own it, a raw
pointer can communicate optional non-owning access.

The main problem is raw pointers used for unclear ownership.

---

## 15. `reset()`

A unique pointer can replace or release its current object:

```cpp
pointer.reset();
```

Afterward:

```text
owned object destroyed
pointer becomes empty
```

It can also take ownership of another raw allocation:

```cpp
pointer.reset(new int(20));
```

But when creating a fresh object, `make_unique` is generally clearer.

---

## 16. `release()`

`release()` gives up ownership without deleting the object:

```cpp
int* raw = pointer.release();
```

Afterward:

```text
pointer is empty
raw now points to still-live allocation
```

You are now responsible for arranging cleanup:

```cpp
delete raw;
```

This is an advanced escape hatch commonly used for interoperability with
APIs that take ownership.

Do not use `release()` merely to avoid understanding ownership.

---

## 17. `reset()` versus `release()`

Important difference:

```text
reset():
releases ownership AND destroys current object

release():
releases ownership WITHOUT destroying current object
```

After `release()`, somebody else must own or eventually destroy the
resource.

---

# Part II — `std::shared_ptr`

## 18. Shared ownership

Sometimes several independent owners genuinely need to keep one object
alive.

C++ provides:

```cpp
std::shared_ptr<T>
```

Example:

```cpp
auto first = std::make_shared<int>(42);
auto second = first;
```

Both smart pointers share ownership.

Conceptually:

```text
first -------+
             |
             v
           [42]
             ^
             |
second ------+

owner count = 2
```

The object is destroyed when the last shared owner goes away.

---

## 19. `make_shared`

Prefer:

```cpp
auto pointer =
    std::make_shared<Player>();
```

over manually writing:

```cpp
std::shared_ptr<Player>(
    new Player()
);
```

`make_shared` is concise and commonly permits efficient allocation of
the object and control information.

---

## 20. Reference counting

A typical shared ownership implementation tracks how many shared owners
exist.

Example:

```cpp
auto a = std::make_shared<int>(10);
```

Conceptual strong count:

```text
1
```

Then:

```cpp
auto b = a;
```

Count:

```text
2
```

Then `b` dies:

```text
1
```

Then `a` dies:

```text
0
```

The managed object is destroyed.

---

## 21. `use_count()`

For learning and diagnostics:

```cpp
pointer.use_count()
```

reports how many `shared_ptr` owners participate in the same ownership
group.

Do not usually design program synchronization or core correctness around
precise `use_count()` checks.

The count can change and is primarily an ownership implementation
property.

---

## 22. Shared ownership has a cost

Compared with `unique_ptr`, a `shared_ptr` typically requires:

- reference-counting control data
- updates to ownership counts
- an additional shared control structure
- more complex lifetime management

Use it because ownership really is shared, not because it appears more
powerful.

Default to simpler ownership where possible.

---

# Part III — `std::weak_ptr`

## 23. The shared ownership cycle problem

Suppose two objects own each other with shared pointers:

```text
A ----shared----> B
^                 |
|                 |
+-----shared------+
```

Even after all outside owners disappear:

```text
A keeps B alive
B keeps A alive
```

Their shared counts may never reach zero.

The objects leak through a reference cycle.

---

## 24. Breaking cycles

One relationship can be non-owning:

```text
A ----shared----> B
^                 |
|                 |
+------weak-------+
```

A `std::weak_ptr<T>` observes an object managed by shared ownership but
does not contribute to the strong ownership count.

This is its most famous purpose.

---

## 25. Creating a weak pointer

Example:

```cpp
auto shared = std::make_shared<int>(42);

std::weak_ptr<int> weak = shared;
```

`weak` does not keep the integer alive by itself.

If `shared` is destroyed and no other strong owners remain, the integer
can be destroyed even though `weak` still exists.

---

## 26. `lock()`

You cannot simply dereference a `weak_ptr`.

Instead:

```cpp
if (auto shared = weak.lock()) {
    std::cout << *shared;
}
```

`lock()` attempts to create a temporary `shared_ptr`.

If the object still exists:

```text
lock() -> non-empty shared_ptr
```

If it has expired:

```text
lock() -> empty shared_ptr
```

This prevents unsafe access to a destroyed object.

---

## 27. `expired()`

A weak pointer can be queried:

```cpp
weak.expired()
```

However, when you actually need to access the object, prefer attempting:

```cpp
auto shared = weak.lock();
```

and checking the resulting shared pointer.

That combines the validity check with acquisition of temporary strong
ownership.

---

## 28. Dry run: weak pointer

Start:

```text
shared owner count = 1
weak observer exists
```

Destroy the shared owner:

```text
strong owner count = 0
managed object destroyed
weak observer remains
```

Then:

```cpp
weak.lock()
```

returns an empty `shared_ptr`.

The weak observer knows the ownership group has expired without keeping
the managed object alive.

---

# Part IV — RAII and Exceptions

## 29. Raw allocation with an exception

Fragile code:

```cpp
int* data = new int(42);

mightThrow();

delete data;
```

If `mightThrow()` throws:

```text
delete data
```

is skipped.

Potential leak.

---

## 30. `unique_ptr` during unwinding

Better:

```cpp
auto data =
    std::make_unique<int>(42);

mightThrow();
```

If an exception occurs:

```text
stack unwinding
      |
destroy unique_ptr
      |
delete managed int
```

Cleanup is connected to object lifetime rather than a manually reached
line of code.

---

## 31. RAII works on normal returns too

Consider:

```cpp
void work() {
    Resource resource;

    if (something) {
        return;
    }
}
```

The destructor still runs when leaving scope through the early return.

RAII handles:

```text
normal scope exit
early return
exception unwinding
```

with the same lifetime rule.

---

## 32. A custom RAII class

You can build a simple owner:

```cpp
class IntOwner {
private:
    int* pointer;

public:
    explicit IntOwner(int value)
        : pointer(new int(value)) {
    }

    ~IntOwner() {
        delete pointer;
    }
};
```

But as learned earlier, raw-resource ownership introduces copy/move
design problems.

Modern code should usually reuse existing RAII types such as
`unique_ptr` rather than reinventing resource ownership.

---

## 33. RAII beyond pointers

File-management concept:

```text
File object constructed
-> file opened

File object destroyed
-> file closed
```

Mutex lock concept:

```text
Lock guard constructed
-> mutex locked

Lock guard destroyed
-> mutex unlocked
```

C++ libraries use RAII pervasively because it makes resource lifetime
compositional and exception-safe.

---

# Part V — Smart Pointers and Polymorphism

## 34. Unique ownership of a derived object

Suppose:

```cpp
class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof";
    }
};
```

Then:

```cpp
std::unique_ptr<Animal> animal =
    std::make_unique<Dog>();
```

can own a `Dog` through a base smart pointer.

Calling:

```cpp
animal->speak();
```

uses virtual dispatch.

The virtual base destructor ensures destruction through the base
interface is correct.

---

## 35. Dynamic collections of polymorphic objects

Later, with STL:

```cpp
std::vector<std::unique_ptr<Animal>>
```

is a common way to store polymorphic objects without slicing.

Why not:

```cpp
std::vector<Animal>
```

?

An abstract base cannot be instantiated, and base-value storage would
also conflict with preserving derived polymorphic identity.

Owning pointers let each complete derived object live independently.

---

# Part VI — Custom Deleters

## 36. Why custom deleters exist

Not every resource is released with plain:

```cpp
delete
```

An API may require:

```text
specialClose(resource)
```

instead.

Smart pointers can use a custom deleter.

Simple demonstration:

```cpp
auto deleter = [](int* pointer) {
    std::cout << "Custom delete\n";
    delete pointer;
};

std::unique_ptr<int, decltype(deleter)>
    pointer(new int(42), deleter);
```

When `pointer` dies, the custom deleter runs.

---

## 37. Deleters are part of unique_ptr's type

For:

```cpp
std::unique_ptr<T, Deleter>
```

the deleter type is part of the smart pointer's type.

This helps unique ownership remain efficient and statically configured.

`shared_ptr` handles deleters differently through its control block.

You do not need the implementation details yet, but recognize that the
two pointer types have different designs.

---

# Part VII — Choosing the Right Ownership Tool

## 38. Prefer automatic objects when possible

Do not use dynamic allocation merely because smart pointers exist.

Instead of:

```cpp
auto value = std::make_unique<int>(42);
```

when no dynamic lifetime is required, simply write:

```cpp
int value = 42;
```

Automatic values are simpler.

---

## 39. Practical hierarchy

A useful default decision process is:

```text
Can object live directly by value?
    -> store it directly

Need dynamic exclusive ownership?
    -> unique_ptr

Need genuine shared ownership?
    -> shared_ptr

Need non-owning observation of shared ownership?
    -> weak_ptr

Need simple non-owning access with externally guaranteed lifetime?
    -> pointer/reference may be appropriate
```

This is a guideline rather than a universal rule.

---

## 40. Ownership versus access

These are different ideas.

A function may access an object without owning it:

```cpp
void print(const Player& player);
```

A pointer may observe an object without owning it:

```cpp
Player* observer;
```

Ownership answers:

```text
Who controls lifetime?
```

Access answers:

```text
Who can currently use the object?
```

Confusing these concepts leads to overuse of `shared_ptr`.

---

# Part VIII — Common DSA Applications

## 41. Linked structures

You may eventually model ownership such as:

```text
node -> next node
```

using `unique_ptr` when ownership is naturally hierarchical.

However, educational linked-list implementations often begin with raw
pointers because they make the node links and allocation mechanics
visible.

Both models are worth understanding.

Do not mechanically convert every DSA pointer into `shared_ptr`.

---

## 42. Trees

A tree has a natural ownership hierarchy:

```text
parent owns child nodes
```

This can map naturally to:

```cpp
std::unique_ptr<Node> left;
std::unique_ptr<Node> right;
```

A non-owning parent pointer, if needed, might remain raw.

This makes the direction of ownership explicit.

---

## 43. Graphs are different

Graph relationships are often not ownership relationships.

Nodes may point to many other nodes, creating cycles.

Using `shared_ptr` for every graph edge can create complex ownership
cycles and unnecessary reference-counting overhead.

Often a graph container owns all nodes while edges are represented by:

```text
indices
IDs
non-owning references/pointers
```

Ownership design should reflect the structure, not merely pointer
syntax.

---

## Complexity table

Smart-pointer operations are usually constant-time with respect to the
number of managed objects, though destruction invokes the managed
object's own destructor.

| Operation | Typical time | Notes |
|---|---:|---|
| `make_unique<T>` | O(1)* | allocation + construction |
| Dereference `unique_ptr` | O(1) | like pointer access |
| Move `unique_ptr` | O(1) | transfers ownership |
| `unique_ptr::reset()` | O(1)* | plus destruction |
| `unique_ptr::get()` | O(1) | no ownership transfer |
| `unique_ptr::release()` | O(1) | no deletion |
| Copy `shared_ptr` | O(1) | increments strong count |
| Destroy `shared_ptr` | O(1)* | may destroy object |
| `shared_ptr::use_count()` | O(1) typical | diagnostic ownership count |
| Construct `weak_ptr` | O(1) | no strong ownership |
| `weak_ptr::lock()` | O(1) typical | attempts strong ownership |

`*` The managed object's constructor/destructor and allocator may have
their own complexity.

---

## Common interview and beginner mistakes

1. Assuming every raw pointer is bad.

2. Using raw `new`/`delete` when automatic objects or smart pointers
   would express ownership better.

3. Trying to copy a `unique_ptr`.

4. Forgetting `std::move` when transferring unique ownership.

5. Dereferencing a moved-from or empty smart pointer.

6. Calling `delete` on the pointer returned by `unique_ptr::get()`.

7. Calling `release()` and then forgetting to transfer or perform
   cleanup.

8. Confusing `release()` with `reset()`.

9. Using `shared_ptr` when ownership is actually unique.

10. Treating `use_count()` as general application logic.

11. Creating a cycle of `shared_ptr`s.

12. Thinking `weak_ptr` owns the object.

13. Dereferencing a `weak_ptr` directly instead of using `lock()`.

14. Assuming smart pointers prevent all dangling references.

15. Returning a raw observer to an object whose smart owner is about to
    die.

16. Using smart pointers where an ordinary stack object is simpler.

17. Forgetting a virtual destructor in a polymorphic base intended for
    ownership through the base type.

18. Believing RAII applies only to memory.

19. Converting every DSA edge/link into shared ownership without
    considering actual ownership semantics.

---

## Practice questions and references

1. cppreference — `std::unique_ptr`  
   https://en.cppreference.com/w/cpp/memory/unique_ptr

2. cppreference — `std::shared_ptr`  
   https://en.cppreference.com/w/cpp/memory/shared_ptr

3. cppreference — `std::weak_ptr`  
   https://en.cppreference.com/w/cpp/memory/weak_ptr

4. GeeksforGeeks — Smart Pointers in C++  
   https://www.geeksforgeeks.org/smart-pointers-cpp/

5. GeeksforGeeks — RAII  
   https://www.geeksforgeeks.org/resource-acquisition-is-initialization/

---

## Revision checklist

Before continuing, make sure you can explain:

- ownership
- owning versus observing pointers
- RAII
- why exceptions make manual cleanup fragile
- `unique_ptr`
- `make_unique`
- unique ownership
- moving a `unique_ptr`
- `get()`
- `reset()`
- `release()`
- `shared_ptr`
- `make_shared`
- reference counting
- `use_count()`
- shared ownership cycles
- `weak_ptr`
- `lock()`
- `expired()`
- custom deleters
- polymorphic smart-pointer ownership
- why smart pointers are unnecessary for ordinary value objects
- why graphs do not imply shared ownership

# What's Next

Continue to:

`01_C++__/31_MOVE_SEMANTICS_BASICS/`

The next lesson explains lvalues and rvalues, move constructors, move
assignment, `std::move`, moved-from objects, copy versus move behavior,
the Rule of Five, and why move semantics make resource-owning types and
containers efficient.
