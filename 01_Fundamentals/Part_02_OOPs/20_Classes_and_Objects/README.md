# 20 — Classes and Objects

- A **class** is a reusable blueprint (user-defined type) that binds **data members** with **member functions (methods)** in one template.
- An **object** is a concrete instance of a class; every object owns its **own copy** of the data members.
- By default, class members are **private**; `struct` members are **public**. Both can hold data + methods.
- **Constructor basics:** a special function with the class name, no return type, runs automatically at object creation.
- Methods are stored **once** in the code segment and shared by all objects; each call secretly passes the object's address (`this`).

- **Real-world analogy:** the class is the master *blueprint* of a car; the objects are the thousands of cars stamped out from that one blueprint.

- **Files in this folder**
  | file | purpose |
  |------|---------|
  | `01_theory.cpp` | concept notes + ASCII diagrams (blueprint vs car, memory layout) + compile-ready demo with edge cases (empty class size) |
  | `task.cpp` | 6 tasks (easy→hard) with scenario, hints, starter code + full solved code |
  | `README.md` | this summary, cheat sheet, complexity, mistakes, interview Q&A |

- **Cheat sheet / syntax**
  | action | syntax |
  |--------|--------|
  | define a class | `class Student { private: ... public: ... };` |
  | create object(s) | `Student s1, s2;` |
  | call a method | `s1.setData("Rahul", 92.5);` |
  | setter / getter | `void setX(int x);` / `int getX() const;` |
  | class vs struct | only the *default* access differs (private vs public) |
  | empty class | `class Empty {};` → `sizeof == 1` (never 0) |

- **Complexity**
  - Time: each method runs a fixed number of statements (2 assignments in `setData`, 2 prints in `display`, no loops) → **O(1)**.
  - Space: `sizeof(Student)` ≈ 40 bytes fixed per object → **O(1)** per object; methods are a single shared copy, not duplicated per object.

- **⚠️ Common mistakes**
  - Forgetting the **semicolon** after the class closing brace.
  - Accessing **private** members from `main()` → compile error; always go through public methods.
  - Thinking objects share data — they do **not**; only methods are shared.
  - Expecting an empty class to have size **0** — compilers give it **1 byte** so distinct objects get distinct addresses.

- **Interview Q&A**
  - *Q: Difference between class and object?* A: class = blueprint/type (no memory); object = instance with real memory.
  - *Q: Default access specifier of class vs struct?* A: class → private; struct → public.
  - *Q: Where are methods stored?* A: one copy in the code segment, shared by all objects.
  - *Q: Can a class have a size of 0?* A: No; compilers enforce at least 1 byte.