# 22. Homogeneous vs Non-Homogeneous Data Structures

- A **homogeneous** structure stores only **one data type** — a classic example is an array of `int` marks.
- A **non-homogeneous** structure stores **fields of different types** in one record — a C++ `struct` with `int id`, `char name[20]`, `float marks`.
- An **array of structs** gives many mixed-type records (a whole student database) while staying index-accessible.
- Fields of a struct are accessed with the **dot operator** — `s[i].name`.
- Use arrays when every item is the same kind of value; use structs when one logical entity has multiple attributes (Student, Employee, Account).

**Real-world analogy:** A train berth with identical seats (homogeneous) vs a school admission register where every row mixes roll-number + name + marks (non-homogeneous).

## Files in this folder
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Concept, struct memory layout ASCII diagram, dry run, complexity + working demo |
| `task.cpp` | 6 graded tasks (easy→hard) with hints, starters, and full solutions |
| `README.md` | This summary, cheat sheet, common mistakes, interview Q&A |

## Cheat sheet / syntax
```cpp
struct Student {
    int id;
    char name[20];
    float marks;
};

Student s[3] = { {101, "Alice", 88.5}, {102, "Bob", 74.0}, {103, "Charlie", 91.25} };
s[0].id;        // -> 101
s[1].name;      // -> "Bob"
s[2].marks;     // -> 91.25
sizeof(Student); // total bytes (may include padding)
```

## Complexity comparison
| Operation (n records) | Homogeneous int array | Array of structs |
|-----------------------|----------------------|------------------|
| Traverse all items | O(n) | O(n) |
| Access one field | `arr[i]` O(1) | `s[i].field` O(1) |
| Search by value | O(n) linear | O(n) linear |
| Memory per item | `sizeof(int)` | `sizeof(Student)` (bigger) |

## ⚠️ Common mistakes
- Forgetting `.` — writing `s[i].id` correctly but `s[0,1]` style for two records.
- Reading `char name[20]` with `cin >> s[i].name` — fine for short names, but no spaces accepted.
- Assuming `sizeof(Student) == 4+20+4 = 28` — the compiler may add **padding**.
- Mixing types inside one plain array — impossible; that is exactly why structs exist.
- Sorting struct records but swapping only one field (id) — must swap the whole record.

## Interview Q&A
- **Q1:** What is a homogeneous data structure? — One that stores items of a single type, like an array of integers.
- **Q2:** What is a non-homogeneous structure? — One holding different types together, like a struct/class record.
- **Q3:** Can an array of structs be homogeneous? — The array itself is same-type (all Student), but each record mixes types internally.
- **Q4:** How is a struct field accessed in C++? — With the dot operator: `object.field`.
- **Q5:** Why padding? — The compiler aligns fields to memory-word boundaries for fast access; `sizeof` may exceed the logical sum.