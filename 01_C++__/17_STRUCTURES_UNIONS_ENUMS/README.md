# Structures, Unions, and Enums in C++

Path:

`DSA_JOURNEY/01_C++__/17_STRUCTURES_UNIONS_ENUMS/`

## Prerequisites

You should already understand:

- primitive data types
- arrays and strings
- functions
- references and pointers
- dynamic memory
- scope and lifetime
- `const`

Until now, most variables stored one basic kind of value:

```cpp
int age;
double price;
char grade;
```

Real entities usually consist of several related values.

A student might have:

```text
name
age
score
```

A linked-list node might have:

```text
value
pointer to next node
```

A graph edge might have:

```text
destination
weight
```

C++ lets us define our own compound types.

---

# 1. Structure

A `struct` groups related data under one type.

Example:

```cpp
struct Student {
    string name;
    int age;
    double score;
};
```

This defines a new type:

```text
Student
```

We can create an object:

```cpp
Student student;
```

The object contains all three members.

Conceptually:

```text
Student
+------------------+
| name             |
+------------------+
| age              |
+------------------+
| score            |
+------------------+
```

---

# 2. Real-World Analogy

Think about a paper student record.

Instead of having unrelated pieces of paper:

```text
name = Ada
age = 20
score = 95.5
```

we put them in one record:

```text
STUDENT RECORD
----------------
Name:  Ada
Age:   20
Score: 95.5
```

A `struct` groups values that conceptually belong together.

---

# 3. Defining a Structure

Syntax:

```cpp
struct TypeName {
    member declarations
};
```

Example:

```cpp
struct Point {
    int x;
    int y;
};
```

Important:

The closing brace is followed by a semicolon:

```cpp
};
```

This is a common beginner mistake.

---

# 4. Creating Structure Objects

After:

```cpp
struct Point {
    int x;
    int y;
};
```

we can write:

```cpp
Point p;
```

`p` is an object of type:

```text
Point
```

Its members are:

```text
p.x
p.y
```

---

# 5. Member Access Operator .

For a normal object:

```cpp
Point p;
```

access members using:

```text
.
```

Example:

```cpp
p.x = 10;
p.y = 20;
```

Then:

```cpp
cout << p.x;
```

prints:

```text
10
```

The operator:

```text
.
```

is the member-access operator.

---

# 6. Initialization

Aggregate initialization:

```cpp
Point p{
    10,
    20
};
```

State:

```text
p.x = 10
p.y = 20
```

Structures that satisfy aggregate rules can be initialized this way.

Later, constructors give us richer initialization behavior.

---

# 7. Designated Initializers Are Not C++17

You may encounter C++20 code such as:

```cpp
Point p{
    .x = 10,
    .y = 20
};
```

This roadmap uses C++17.

Do not depend on C++20 designated initializers.

Use:

```cpp
Point p{10, 20};
```

for this course.

---

# 8. Default Member Initializers

Members can have defaults:

```cpp
struct Point {
    int x = 0;
    int y = 0;
};
```

Then:

```cpp
Point p;
```

uses these member initializers.

State:

```text
p.x = 0
p.y = 0
```

This can make structs safer by ensuring sensible initial values.

---

# 9. Value Initialization

Example:

```cpp
struct Point {
    int x;
    int y;
};

Point p{};
```

Aggregate/value initialization causes the members to be initialized appropriately, resulting in zero for these `int` members:

```text
x = 0
y = 0
```

Prefer intentional initialization rather than leaving fundamental members indeterminate.

---

# 10. Uninitialized Members

Potentially dangerous:

```cpp
struct Point {
    int x;
    int y;
};

Point p;
```

For an ordinary automatic object with no initialization/default member initializers, fundamental members such as `x` and `y` can remain indeterminate.

Do not read them before assigning values.

Better:

```cpp
Point p{};
```

or give default member initializers.

---

# 11. Structure Memory

A struct's members are stored as part of the struct object.

Example:

```cpp
struct Example {
    char c;
    int x;
};
```

You might expect:

```text
sizeof(char) + sizeof(int)
```

But `sizeof(Example)` may be larger because the implementation may insert padding for alignment.

This is important.

---

# 12. Padding

Suppose conceptually:

```text
char -> 1 byte
int  -> 4 bytes
```

An implementation might lay out:

```text
char c
padding
padding
padding
int x
```

giving:

```text
sizeof(Example) = 8
```

on a common platform.

The exact layout is implementation-dependent.

Do not assume a struct's size is simply the sum of member sizes.

---

# 13. Real-World Analogy for Padding

Imagine placing objects into fixed-width shelves.

A tiny object occupies only part of the first shelf section, but the next large object may need to start at a properly aligned boundary.

Empty spacing is left between them.

That unused spacing resembles padding.

Compilers add it to satisfy alignment requirements and support efficient/valid access on the target platform.

---

# 14. Member Order Can Affect Size

These may have different layouts/sizes on some implementations:

```cpp
struct A {
    char a;
    int b;
    char c;
};
```

and:

```cpp
struct B {
    int b;
    char a;
    char c;
};
```

Member ordering can affect padding.

Do not reorder members purely for size optimization unless it matters and you understand the semantic/readability tradeoffs.

---

# 15. sizeof a Struct

Use:

```cpp
cout << sizeof(Point);
```

Do not hard-code assumptions.

The result depends on:

- member types
- alignment
- padding
- target ABI/platform

This matters later when analyzing memory-heavy data structures.

---

# 16. Arrays of Structs

Example:

```cpp
Student students[3];
```

This creates three contiguous `Student` objects.

Access:

```cpp
students[0].name
students[1].score
```

This is useful for collections of records.

Later `vector<Student>` provides dynamic size.

---

# 17. Array of Structs Memory Model

Conceptually:

```text
students

+----------------+
| Student 0      |
| name/age/score |
+----------------+
| Student 1      |
| name/age/score |
+----------------+
| Student 2      |
| name/age/score |
+----------------+
```

The `Student` objects are contiguous as array elements.

Each `Student` internally contains its members according to its object layout.

---

# 18. Struct as Function Parameter by Value

Example:

```cpp
void move(Point p) {
    ++p.x;
}
```

Call:

```cpp
Point original{1, 2};

move(original);
```

Because `p` is passed by value, it is a copy.

After the call:

```text
original.x = 1
original.y = 2
```

This is the same pass-by-value rule you already learned.

---

# 19. Struct by Reference

To modify the caller's struct:

```cpp
void move(Point& p) {
    ++p.x;
}
```

Now:

```cpp
Point original{1, 2};

move(original);
```

can produce:

```text
original = {2, 2}
```

Reference parameter aliases the original object.

---

# 20. Struct by const Reference

For read-only functions:

```cpp
void printPoint(
    const Point& p
) {
    cout << p.x
         << ' '
         << p.y;
}
```

This avoids copying a potentially large struct while preventing mutation through `p`.

This is a very common modern C++ pattern.

---

# 21. Returning a Struct

Unlike a raw array, a struct can be returned by value naturally.

Example:

```cpp
Point makePoint(
    int x,
    int y
) {
    return Point{x, y};
}
```

Call:

```cpp
Point p =
    makePoint(10, 20);
```

State:

```text
p.x = 10
p.y = 20
```

Modern C++ makes returning objects by value efficient through copy elision and move semantics.

Do not fear returning structs by value.

---

# 22. Struct Copying

Example:

```cpp
Point a{1, 2};
Point b = a;
```

For simple value members:

```text
b.x = 1
b.y = 2
```

Then:

```cpp
b.x = 100;
```

does not change `a`.

Final:

```text
a = {1, 2}
b = {100, 2}
```

---

# 23. Memberwise Copy

For simple structs, default copying copies each member.

Example:

```cpp
struct Record {
    int x;
    double y;
};
```

Copy:

```cpp
Record b = a;
```

conceptually performs memberwise copying.

This becomes more subtle when a struct contains owning raw pointers.

---

# 24. Struct Containing a Raw Pointer

Example:

```cpp
struct Data {
    int* ptr;
};
```

Copy:

```cpp
Data a;
Data b = a;
```

copies the pointer value.

It does not automatically deep-copy the dynamically allocated `int`.

Thus:

```text
a.ptr
b.ptr
```

may point to the same object.

This is the shallow-copy issue from dynamic memory.

---

# 25. Ownership Problem

Suppose:

```cpp
struct Data {
    int* ptr;
};
```

and `ptr` owns dynamic memory.

Default copying can create:

```text
a.ptr ----+
          |
          v
       allocation
          ^
          |
b.ptr ----+
```

If both objects later try to delete it:

```text
double delete
```

This is why classes that manually own resources require careful copy/destruction behavior.

We will study this deeply in OOP.

---

# 26. Nested Structs

Structures can contain other structures.

Example:

```cpp
struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    string name;
    Date birthDate;
};
```

Access:

```cpp
student.birthDate.year
```

Member access can be chained.

---

# 27. Self-Referential Struct

A struct cannot directly contain a complete object of its own type:

```cpp
struct Node {
    int value;
    Node next; // INVALID
};
```

Why?

To determine `sizeof(Node)`, C++ would need `sizeof(Node next)`, which requires `sizeof(Node)`, forever.

Instead use an indirection:

```cpp
struct Node {
    int value;
    Node* next;
};
```

A pointer has known fixed storage independent of the size of the pointed-to complete object.

This pattern is foundational for linked lists.

---

# 28. Node Mental Model

```cpp
struct Node {
    int value;
    Node* next;
};
```

Conceptually:

```text
Node
+-------------+
| value = 10  |
+-------------+
| next -------+----> another Node
+-------------+
```

Or:

```text
next = nullptr
```

for the end of a list.

You will build this manually in the linked-list phase.

---

# 29. Dynamically Allocated Struct

Example:

```cpp
Node* node =
    new Node{
        10,
        nullptr
    };
```

Access:

```cpp
node->value
```

Cleanup:

```cpp
delete node;
node = nullptr;
```

This combines:

- structs
- pointers
- dynamic memory

It is exactly the foundation required for linked data structures.

---

# 30. Arrow Operator ->

Given pointer:

```cpp
Node* node;
```

access a member using:

```cpp
node->value
```

This is equivalent to:

```cpp
(*node).value
```

The parentheses matter because `.` binds more strongly than unary `*`.

Prefer:

```cpp
node->value
```

when accessing members through pointers.

---

# 31. Dot vs Arrow

Normal object:

```cpp
Point p;

p.x
```

Pointer:

```cpp
Point* ptr = &p;

ptr->x
```

Mental rule:

```text
object     -> .
pointer    -> ->
```

Although:

```cpp
(*ptr).x
```

also works.

---

# 32. nullptr and Struct Pointers

Wrong:

```cpp
Node* node = nullptr;

cout << node->value;
```

`node->value` requires dereferencing `node`.

Null pointer dereference is undefined behavior.

Check:

```cpp
if (node != nullptr) {
    cout << node->value;
}
```

---

# 33. struct vs class

In C++, `struct` and `class` are very similar.

The most important default difference:

```text
struct
members/inheritance default to public

class
members/inheritance default to private
```

Example:

```cpp
struct Point {
    int x;
};
```

`x` is public by default.

Later:

```cpp
class Point {
    int x;
};
```

`x` is private by default.

Both can have:

- methods
- constructors
- destructors
- access specifiers
- inheritance
- operators

---

# 34. Structs Can Have Functions

Example:

```cpp
struct Point {
    int x;
    int y;

    void print() const {
        cout << x
             << ' '
             << y;
    }
};
```

So C++ structs are much more powerful than "C structs."

However, methods/classes are taught systematically in the next OOP phase.

For this folder, structs primarily model data records.

---

# 35. Public Keyword

You can explicitly write:

```cpp
struct Point {
public:
    int x;
    int y;
};
```

But this is redundant because struct members are public by default.

Later access control becomes central to encapsulation.

---

# 36. typedef and struct — C vs C++

In C, you often see:

```c
typedef struct Point {
    int x;
    int y;
} Point;
```

In C++, after:

```cpp
struct Point {
    int x;
    int y;
};
```

you can directly write:

```cpp
Point p;
```

No `typedef` is necessary.

You may encounter C-style declarations in older/interop code.

---

# 37. Anonymous Structs

C++ supports some forms of unnamed/anonymous aggregate structures in certain contexts, but they are not important for beginner DSA.

Prefer named types:

```cpp
struct Point {
    int x;
    int y;
};
```

Named types improve readability and function interfaces.

---

# 38. Enumeration

An enumeration defines a type with a fixed set of named values.

Traditional enum:

```cpp
enum Direction {
    North,
    East,
    South,
    West
};
```

Now:

```cpp
Direction direction =
    North;
```

The named constants make state more meaningful than unexplained integers.

---

# 39. Why enum Exists

Without enum:

```cpp
int direction = 2;
```

What does `2` mean?

Maybe:

```text
north?
south?
left?
right?
```

With enum:

```cpp
Direction direction =
    South;
```

Intent is much clearer.

Real-world analogy:

Instead of saying:

```text
traffic state = 2
```

say:

```text
traffic state = Green
```

Named states prevent "magic number" confusion.

---

# 40. Traditional enum Values

By default:

```cpp
enum Direction {
    North,
    East,
    South,
    West
};
```

typically assigns consecutive underlying values beginning at zero:

```text
North = 0
East  = 1
South = 2
West  = 3
```

You can specify values:

```cpp
enum Status {
    Success = 0,
    Error = 100,
    Unknown = -1
};
```

---

# 41. Traditional enum Conversion

Unscoped enum values can implicitly convert to integral types.

Example:

```cpp
enum Direction {
    North,
    East
};

int value =
    East;
```

`value` is typically:

```text
1
```

This convenience can also weaken type safety.

Modern C++ often prefers:

```cpp
enum class
```

---

# 42. enum class

Scoped enumeration:

```cpp
enum class Direction {
    North,
    East,
    South,
    West
};
```

Use:

```cpp
Direction d =
    Direction::North;
```

Enumerator names remain inside the enum's scope:

```text
Direction::North
```

rather than injecting a plain `North` name into the surrounding scope.

---

# 43. Why enum class Is Safer

Consider:

```cpp
enum class Color {
    Red,
    Green
};

enum class Traffic {
    Red,
    Green
};
```

Both can safely contain:

```text
Red
Green
```

because names are scoped:

```text
Color::Red
Traffic::Red
```

They are also different types and do not implicitly convert to integers in ordinary use.

This prevents accidental mixing.

---

# 44. enum class and Integers

This does not implicitly work:

```cpp
enum class State {
    Off,
    On
};

int x =
    State::On; // error
```

Use explicit conversion if required:

```cpp
int x =
    static_cast<int>(
        State::On
    );
```

This explicitness is usually desirable.

---

# 45. Underlying Enum Type

You can specify:

```cpp
enum class Status : int {
    Ready,
    Running,
    Done
};
```

or another valid integral underlying type:

```cpp
enum class Small : unsigned char {
    A,
    B,
    C
};
```

For most DSA code, the default is fine unless storage or interoperability requirements matter.

---

# 46. switch With Enums

Enums work naturally with `switch`.

Example:

```cpp
enum class Direction {
    North,
    South
};

switch (direction) {
    case Direction::North:
        cout << "N";
        break;

    case Direction::South:
        cout << "S";
        break;
}
```

This makes state-machine style code expressive.

---

# 47. Invalid Enum Values

An enum variable's underlying representation does not automatically mean every arbitrary integer is a meaningful semantic state.

Avoid converting unchecked integers into enum types and then assuming they correspond to declared enumerators.

Validation matters.

---

# 48. Enum vs const int Constants

Older code may use:

```cpp
const int NORTH = 0;
const int SOUTH = 1;
```

An enum creates a dedicated type:

```cpp
enum class Direction {
    North,
    South
};
```

Benefits:

- groups related values
- improves readability
- stronger type checking
- prevents unrelated constants from mixing easily

---

# 49. Union

A union is a special type where non-static data members share storage.

Example:

```cpp
union Data {
    int integer;
    double decimal;
};
```

Unlike a struct, which conceptually allocates storage for all members, a union overlays members in the same storage region.

---

# 50. Struct vs Union Analogy

Struct:

Imagine a toolbox with separate compartments:

```text
+---------+---------+
| integer | decimal |
+---------+---------+
```

Both can exist simultaneously.

Union:

Imagine one reusable compartment:

```text
+-------------------+
| integer OR decimal|
+-------------------+
```

Different interpretations share the same storage.

Only one member is generally active at a time.

---

# 51. Union Size

A union must be large enough and suitably aligned for its largest member.

Example:

```cpp
union Data {
    char c;
    int i;
    double d;
};
```

Its size is at least enough for the largest member, potentially including alignment-related effects.

Do not assume exact sizes.

Use:

```cpp
sizeof(Data)
```

---

# 52. Active Union Member

Example:

```cpp
union Data {
    int integer;
    double decimal;
};

Data data;

data.integer = 42;
```

The active member becomes:

```text
integer
```

Then:

```cpp
cout << data.integer;
```

is valid.

If later:

```cpp
data.decimal = 3.14;
```

the active member becomes:

```text
decimal
```

You should then access:

```cpp
data.decimal
```

not assume `integer` still represents a live usable `int` value.

---

# 53. Reading Inactive Union Member

A common low-level mistake is:

```cpp
data.integer = 42;

cout << data.decimal;
```

Using a different inactive member to reinterpret object representation has strict language rules and is generally not a portable type-punning technique in C++.

Do not use unions casually to "inspect the bits as another type."

Later low-level alternatives include:

- `memcpy`
- `std::bit_cast` in C++20

This roadmap uses C++17, so `std::bit_cast` is not available.

---

# 54. Why Unions Exist

Use cases include:

- memory-sensitive tagged representations
- low-level hardware/protocol interfaces
- C interoperability
- implementing variant-like structures manually

But manual unions are error-prone because the programmer must know which member is active.

Modern C++ often prefers:

```cpp
std::variant
```

for safe tagged alternatives.

`std::variant` is not core DSA, but it is useful modern C++ knowledge.

---

# 55. Union With Non-Trivial Types

Unions can contain types with constructors/destructors, but lifetime management becomes significantly more complex.

Example involving:

```cpp
string
```

requires careful explicit construction/destruction management for union members.

Do not manually build such unions at this stage.

Use unions with simple trivially managed types while learning the concept.

---

# 56. Tagged Union

A safer manual pattern combines:

```text
enum tag
+
union storage
```

Example concept:

```cpp
enum class Type {
    Integer,
    Decimal
};

union Value {
    int integer;
    double decimal;
};

struct TaggedValue {
    Type type;
    Value value;
};
```

Now:

```text
type
```

records which union member should be considered active.

This is the basic idea behind a tagged union.

---

# 57. Tagged Union Mental Model

State:

```text
type = Integer

value.integer = 42
```

Meaning:

```text
read integer member
```

Later:

```text
type = Decimal

value.decimal = 3.14
```

Meaning:

```text
read decimal member
```

The enum acts like a label attached to shared storage.

The programmer must keep them synchronized.

---

# 58. std::variant Preview

Modern C++17 provides:

```cpp
std::variant<int, double>
```

which is a type-safe tagged union.

It manages which alternative is active.

This is generally safer than a raw union when several non-trivial types are involved.

However, learning raw unions helps you understand what problem `variant` solves.

---

# 59. Nested Data Models

Structs allow us to build increasingly rich models.

Example:

```cpp
struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;
};
```

Now:

```cpp
rectangle.topLeft.x
```

accesses nested state.

This composition approach becomes central to OOP and data structure design.

---

# 60. Struct Containing Array

Example:

```cpp
struct Student {
    string name;
    int marks[3];
};
```

Each `Student` contains its own raw array.

Access:

```cpp
student.marks[0]
```

Copying the struct copies the raw array member element-by-element as part of the struct copy operation.

This differs from attempting to assign one standalone raw array to another.

---

# 61. Struct Containing std::string

Example:

```cpp
struct Student {
    string name;
    int age;
};
```

`std::string` handles its own internal memory.

When the `Student` is copied, its `string` member follows `std::string` copy semantics.

This is much safer than manually storing:

```cpp
char*
```

as an owning field.

---

# 62. Struct and Dynamic Memory

A struct can be dynamically allocated:

```cpp
Student* student =
    new Student{
        "Ada",
        20
    };
```

Access:

```cpp
student->name
student->age
```

Cleanup:

```cpp
delete student;
student = nullptr;
```

Later smart pointers remove the need for manual cleanup.

---

# 63. Array of Dynamic Node Pointers

Conceptually later:

```cpp
Node* nodes[10]{};
```

This is an array of ten pointers.

Each pointer might point to a different dynamically allocated node.

This combines:

- arrays
- pointers
- structs
- dynamic memory

Graph/tree implementations use similar combinations extensively.

---

# 64. Self-Referential Structures Beyond Lists

Tree:

```cpp
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};
```

Graph adjacency node concept:

```cpp
struct Edge {
    int to;
    int weight;
};
```

Trie:

```text
node
+
child links
+
end marker
```

Custom types are the building blocks of nearly every advanced data structure.

---

# 65. Forward Declaration Preview

Sometimes two types need pointers/references to one another.

You can declare a type name before fully defining it:

```cpp
struct B;

struct A {
    B* b;
};

struct B {
    A* a;
};
```

A pointer can refer to an incomplete type because its own size does not depend on the complete pointed-to type.

But embedding:

```cpp
B b;
```

requires `B` to be complete at that point.

---

# 66. Incomplete Type

After:

```cpp
struct Node;
```

the compiler knows:

```text
Node is a type
```

but not yet:

```text
its size/layout/members
```

You can commonly declare:

```cpp
Node* ptr;
```

because pointer size does not require `sizeof(Node)`.

You cannot create:

```cpp
Node object;
```

until the type is complete.

---

# 67. Structure Alignment Preview

C++ objects have alignment requirements.

You can query:

```cpp
alignof(Type)
```

Example:

```cpp
cout << alignof(int);
```

and:

```cpp
cout << alignof(MyStruct);
```

Alignment determines valid address boundaries for objects and contributes to padding.

Exact values depend on implementation.

Low-level memory optimization sometimes considers:

```text
sizeof
alignof
member order
```

For normal DSA, correctness matters much more than packing structs aggressively.

---

# 68. Empty Struct Size

In C++, an empty struct still has nonzero size.

Example:

```cpp
struct Empty {};
```

Typically:

```cpp
sizeof(Empty) == 1
```

The standard requires distinct complete objects of the same type to be addressable distinctly in relevant cases, so an empty class object needs a size.

Do not rely on exactly 1 in every special context/layout scenario, but this is the normal observation.

---

# 69. Plain Data Type Design

A struct is useful when several values always travel together.

Instead of:

```cpp
void process(
    int x,
    int y,
    int weight,
    int id
);
```

we might define:

```cpp
struct Edge {
    int x;
    int y;
    int weight;
    int id;
};
```

Then:

```cpp
void process(
    const Edge& edge
);
```

This can make interfaces clearer and easier to extend.

---

# 70. Return Multiple Values Using Struct

Earlier we used output references.

Instead:

```cpp
struct DivisionResult {
    int quotient;
    int remainder;
};
```

Function:

```cpp
DivisionResult divide(
    int a,
    int b
) {
    return {
        a / b,
        a % b
    };
}
```

Call:

```cpp
DivisionResult result =
    divide(17, 5);
```

State:

```text
quotient = 3
remainder = 2
```

This often produces a cleaner interface than mutable output parameters.

---

# 71. Equality of Structs in C++17

For a custom struct:

```cpp
struct Point {
    int x;
    int y;
};
```

C++17 does not automatically generate:

```cpp
p1 == p2
```

merely because the members support equality.

You would define your own operator/function, or compare members manually.

C++20 introduced additional comparison-generation features, but this roadmap uses C++17.

Operator overloading is taught later.

---

# 72. Assignment of Structs

Unlike raw arrays, struct objects generally support memberwise assignment when their members are assignable.

Example:

```cpp
Point a{1, 2};
Point b{3, 4};

b = a;
```

Final:

```text
b.x = 1
b.y = 2
```

The compiler-generated assignment operates on members.

---

# 73. const Struct Object

Example:

```cpp
const Point p{
    10,
    20
};
```

You can read:

```cpp
cout << p.x;
```

but not modify:

```cpp
p.x = 50;
```

The object is const, so its non-mutable data members cannot be changed through ordinary access.

---

# 74. References to Members

Example:

```cpp
Point p{10, 20};

int& xReference =
    p.x;

xReference = 99;
```

Final:

```text
p.x = 99
```

A data member is itself an object and can participate in reference/pointer semantics.

---

# 75. Pointer to Member vs Pointer to Member Object

This advanced distinction exists:

```text
pointer to an object member
```

is different from:

```text
ordinary pointer storing address of one member in one object
```

C++ has special pointer-to-member syntax such as:

```cpp
int Point::*
```

This is not needed for normal DSA and is better studied with advanced OOP.

It is intentionally not used here.

---

# 76. Common Interview Mistakes

1. Forgetting the semicolon after a struct definition.

2. Using `->` on a normal object.

3. Using `.` on a pointer without dereferencing it.

4. Dereferencing a null struct pointer.

5. Leaving fundamental struct members uninitialized.

6. Assuming struct size equals sum of member sizes.

7. Hard-coding padding/alignment assumptions.

8. Assuming a self-referential struct can directly contain itself.

9. Forgetting that a self-link must use indirection such as `Node*`.

10. Passing large structs by value unintentionally.

11. Using mutable reference when const reference is enough.

12. Assuming struct assignment behaves like raw-array assignment.

13. Copying a struct with an owning raw pointer and accidentally creating shallow ownership.

14. Double-deleting a resource after shallow struct copying.

15. Confusing `struct` and `class` as completely different features in C++.

16. Forgetting that struct members are public by default.

17. Using magic integers instead of a meaningful enum.

18. Confusing traditional `enum` with `enum class`.

19. Expecting `enum class` to implicitly convert to `int`.

20. Forgetting to qualify scoped enumerators:

```cpp
Direction::North
```

21. Treating every arbitrary integer as a valid semantic enum state.

22. Assuming every union member exists independently.

23. Reading an inactive union member as a general type-punning technique.

24. Using unions with non-trivial objects without managing lifetimes correctly.

25. Forgetting which member of a manual tagged union is active.

26. Assuming exact `enum`, union, or struct memory sizes across platforms.

---

# 77. Complexity Table

For fixed-size structs with scalar members:

| Operation | Typical DSA Complexity |
|---|---:|
| Access member with `.` | O(1) |
| Access member with `->` | O(1) |
| Modify scalar member | O(1) |
| Copy fixed scalar-only struct | O(1) |
| Copy struct containing n-size dynamic member like string | member-dependent, often O(n) |
| Pass struct by reference | O(1) binding model |
| Enum comparison | O(1) |
| Enum switch | O(1) conceptual branch operation |
| Union scalar member access | O(1) |
| Traverse array of n structs | O(n) |
| Allocate one struct dynamically | allocator-dependent |
| Access nested fixed-depth members | O(1) |

Always consider the complexity of member types. A struct containing a `string` is not equivalent to a struct containing only two `int`s.

---

# 78. Practice Questions

1. GFG — Structures in C++  
   https://www.geeksforgeeks.org/structures-in-cpp/

2. GFG — Union in C++  
   https://www.geeksforgeeks.org/cpp-unions/

3. GFG — Enumeration in C++  
   https://www.geeksforgeeks.org/enumeration-in-cpp/

4. LeetCode 707 — Design Linked List  
   https://leetcode.com/problems/design-linked-list/

5. LeetCode 206 — Reverse Linked List  
   https://leetcode.com/problems/reverse-linked-list/

The linked-list problems are for later. Their `Node` representation will directly use the struct/pointer concepts from this lesson.

---

# 79. Final Mental Model

Struct:

```text
all members have their own storage in one object

Student
+---------+
| name    |
+---------+
| age     |
+---------+
| score   |
+---------+
```

Union:

```text
members share storage

+----------------+
| int OR double  |
+----------------+
```

Enum:

```text
named finite states

Direction::North
Direction::East
Direction::South
Direction::West
```

Self-referential node:

```text
Node
+----------+
| value    |
+----------+
| next ----+----> Node
+----------+
```

These custom types are the bridge from basic C++ syntax to real data structures.

---

# What's Next

`01_C++__/18_OOP_CLASSES_AND_OBJECTS/`

Next we begin object-oriented programming: classes, objects, access control, member functions, `this`, class invariants, encapsulation foundations, object layout concepts, and the practical relationship between C++ structs and classes.
