# Function Overloading (Compile-Time Polymorphism)

- Overloading means many functions share one name but have different parameter lists (different count or different types).
- The compiler picks the best matching version at compile time — zero runtime overhead, which is why it is called compile-time (static) polymorphism.
- The return type alone can never distinguish overloads; the name plus the parameter list must differ.
- Matching order is: exact match > type promotion > standard conversion > user-defined conversion; two equally good matches = ambiguity error, fixed with an explicit cast.
- Best suited for one logical operation offered with several argument shapes: print, area, min, add, greeting.

- Real-world analogy: One help-desk number routes your call to the right specialist based on what you describe — the compiler "routes" by the argument types you pass.

- Files in this folder:
  - `01_theory.cpp` — binding rules, ASCII dispatch diagram, ambiguity diagram, compile-ready demo (print ×3 types, add ×3 versions) with edge cases.
  - `task.cpp` — 7 tasks EASY→HARD (print, area circle/rect/square/triangle, min, add, greeting, ambiguity fix) + full solutions.

- Cheat sheet / syntax table:

  | Rule / Fact                            | Example                                  |
  |----------------------------------------|------------------------------------------|
  | same name + different params = OK      | `f(int)`, `f(double)`, `f(int,int)`      |
  | same name + return type only = ERROR   | `int f(int)` + `double f(int)` — refuses |
  | exact match wins first                 | `f(5)` → `f(int)`, not `f(double)`       |
  | ambiguity error                        | `foo(long)` + `foo(float)`; `foo(5)`     |
  | fix ambiguity with cast                | `foo((long)5)`                           |

- Complexity:
  - Overload resolution is done while compiling; a call compiles to one direct call: **O(1)** time, **O(1)** space per call.

- ⚠️ Common mistakes:
  - Overloading only on return type — the compiler rejects the program.
  - Passing a `float` where both `int` and `double` overloads exist → ambiguous.
  - Combining default arguments with overloads until two overloads become identical for some call.
  - Reusing a name for unrelated behaviour, which destroys overload clarity.

- Interview Q&A:
  - Q: Can overloading be based only on the return type? A: No — the call alone cannot tell the compiler which version you want.
  - Q: What is the resolution order? A: exact match → promotion → standard conversion → user-defined conversion.
  - Q: Why is overloading "compile-time" polymorphism? A: The correct version is chosen while compiling; no dispatch happens at runtime.
  - Q: When can `print(3.14f)` become ambiguous? A: A float can promote/demote in multiple ways; if both `int` and `double` versions exist it may be ambiguous.