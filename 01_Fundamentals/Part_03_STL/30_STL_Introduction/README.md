# Introduction to STL (Standard Template Library)

The STL is C++'s built-in toolkit of reusable containers, algorithms, iterators, functors, and adapters. It saves you from hand-writing data structures and sorting/searching logic, giving you tested, template-based, blazing-fast building blocks. Core idea: pick a container to store data, an iterator to move through it, and an algorithm such as `sort` or `find` to process it. Memory is managed automatically by the library, so you write far fewer bugs. Compile any STL code with modern C++ (`-std=c++17`) and it works out of the box.

- Real-world analogy: the STL is like a well-stocked stationery cupboard — boxes for storing data (containers), tools for arranging it (algorithms), a finger for pointing (iterators), and a stamp that always behaves the same (functors).

## Files in this folder

| File            | Purpose                                                                 |
| --------------- | ----------------------------------------------------------------------- |
| `01_theory.cpp` | Pure theory: STL component map, template idea, namespace std, demo with vector + sort + find, empty-container edge cases. |
| `task.cpp`      | 6 tasks (easy → hard): sort marks, find a name, sort-then-search, count occurrences, reverse a list, descending sort with `greater<int>()`. |
| `README.md`     | This summary, syntax cheat sheet, complexity derivation, mistakes, interview Q&A. |

## Cheat sheet / syntax table

| Code snippet                            | What it does                    | Time complexity |
| --------------------------------------- | ------------------------------- | --------------- |
| `vector<int> v;`                        | Create empty dynamic array      | O(1) per construction |
| `v.push_back(x)`                        | Append x at the end             | O(1) amortized |
| `sort(v.begin(), v.end())`              | Sort ascending                  | O(n log n) |
| `find(v.begin(), v.end(), key)`         | Linear search for key           | O(n) |
| `count(v.begin(), v.end(), x)`          | Count occurrences of x          | O(n) |
| `reverse(v.begin(), v.end())`           | Flip the whole range            | O(n) |
| `sort(b, e, greater<int>())`            | Sort descending via functor     | O(n log n) |
| `auto it = ...`                         | Let compiler infer the iterator type | O(1) |
| `it == v.end()`                         | Standard "not found" check      | O(1) |
| `for (int x : v)`                       | Range-based read loop           | O(n) over elements |

## Complexity: time & space (with derivation)

- **push_back O(1) amortized**: most pushes happen in O(1); a rare push doubles the array and copies all n elements. That one copy of size n pays for itself across the n pushes before the next doubling, so the average per push stays at about 2 operations → constant → **O(1) amortized**.
- **sort O(n log n)**: each pass over the data costs n comparisons to merge/split, and the data shrinks by half each round, giving log₂(n) rounds → n · log₂(n) → **O(n log n)**.
- **find / count O(n)**: worst case the target is the last element or absent, so all n slots get visited → n steps → **O(n)**.
- **reverse O(n)**: every element is moved once, total n swaps → **O(n)**.
- **Space O(n)**: a vector of n ints needs storage for ~n to ~2n elements; simplifying, c·n slots for a constant c ≈ 2 → **O(n)**.

## ⚠️ Common mistakes

- Dereferencing the result of `find()` without checking `it != v.end()` — a missing key returns `end()`, which points past the last element and must never be read.
- Forgetting `using namespace std;` (or `std::`) and getting compile errors for every STL name.
- Passing a raw array to `sort` without the proper `arr, arr + n` pair of iterators.
- Using `find()` on a huge list repeatedly — that is O(n) each time; prefer `set`/`unordered_set` for many lookups.
- Assuming `std::cout` prints containers directly — you must loop over elements yourself.
- Compiling without `-std=c++17` and wondering why nice STL functions fail.

## Interview Q&A

- **Q: What are the five components of STL?** A: Containers (store data), Iterators (move/point), Algorithms (process ranges: sort, find), Functors (function objects like `greater<int>`), Adapters (re-shape: `stack`, `priority_queue`, `back_inserter`).
- **Q: Why is STL considered "template based"?** A: One generic skeleton works for any type — `vector<int>`, `vector<string>`, `vector<Student>` share the same code; the compiler fills in the actual type.
- **Q: Name an algorithm that needs sorted data vs one that does not.** A: `binary_search` needs sorted data; `find` works on any order but is slower (O(n) vs O(log n)).
- **Q: What is a functor and why pass it to sort?** A: A functor is an object whose `operator()` makes it callable, e.g. `greater<int>()`; passing it changes the sort order (descending here).
- **Q: What happens if you sort an empty vector?** A: Nothing bad — `begin() == end()`, so the range is empty and sort becomes a no-op.