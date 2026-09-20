# std::pair — Two Values Glued Together

`std::pair<T1, T2>` is a tiny utility class that bundles exactly two values, reachable as `.first` and `.second`. You make one with the constructor, brace-init `{a, b}`, or `make_pair(a, b)` which deduces the types automatically. Pairs compare lexicographically — `.first` first, tying `.second` only on equal firsts — which is exactly the order `sort()` applies to a `vector<pair>`. Nested pairs `pair<pair<int,int>,int>` hold three values, and `tie()` unpacks pair members straight back into plain variables. Pairs are everywhere in DSA: coordinates, key-value records, range endpoints.

- Real-world analogy: the stapler at the sports-day scoring desk that keeps each runner's roll number and marks on one card, so the two facts can never drift apart.

## Files in this folder

| File            | Purpose                                                                 |
| --------------- | ----------------------------------------------------------------------- |
| `01_theory.cpp` | Pure theory: pair box ASCII diagram, make_pair, nested pair, lexicographic comparison, tie(), vector<pair> sorting + min_element demos, empty-vector edge. |
| `task.cpp`      | 6 tasks (easy → hard): zip two arrays, print only first, sort by second, find min-marks pair, filter pairs, closest coordinate point. |
| `README.md`     | This summary, cheat sheet, complexity derivation, mistakes, interview Q&A. |

## Cheat sheet / syntax table

| Snippet                                     | What it does                     | Time complexity |
| ------------------------------------------- | -------------------------------- | --------------- |
| `pair<int,int> p(4,9);`                     | Construct by types               | O(1) |
| `pair<int,int> p = {4,9};`                  | Brace initialize                 | O(1) |
| `auto p = make_pair(4,9);`                  | Type-deduced construction        | O(1) |
| `p.first` / `p.second`                      | Read the two parts               | O(1) |
| `p1 < p2`                                   | Lexicographic compare            | O(1) |
| `tie(a, b) = p;`                            | Unpack pair into variables       | O(1) |
| `pair<pair<int,int>,int> t = {{1,2},3};`    | Nested pair (three values)       | O(1) |
| `sort(v.begin(), v.end())`                  | Sort pairs by first then second  | O(n log n) |
| `min_element(v.begin(), v.end())`           | Smallest pair lexicographically  | O(n) |
| Custom lambda in sort/min_element           | Sort/compare by `.second` etc.   | same as base op |

## Complexity: time & space (with derivation)

- **Construction O(1)**: building a pair writes exactly 2 members; `make_pair` + copy is a fixed handful of assignments → constant → **O(1)**.
- **Comparison O(1)**: lexicographic compare touches `.first` once, and `.second` only when `.first`s tie → at most 2 field comparisons → constant → **O(1)**.
- **sort of n pairs O(n log n)**: sorting performs n·log₂(n) comparisons, each costing O(1) on a pair → n·log₂(n)·1 → **O(n log n)**.
- **min_element O(n)**: scans all n pairs performing one O(1) compare per pair → n steps → **O(n)**.
- **Space O(n)**: a pair stores 2 objects with no extra per-pair metadata; a vector of n pairs therefore holds 2n objects plus ~n·k bytes of padding → linear → **O(n)**.

## ⚠️ Common mistakes

- Forgetting `#include <utility>` (or `<iostream>` pulling it in) and getting "'pair' is not a member of 'std'".
- Comparing pairs with a custom comparator that ignores intended tie-breaks — default sort uses `.first` first, then `.second`; provide a lambda when the tie-break must differ.
- Dereferencing `min_element`/`max_element`/`find` without checking for `end()` — on an empty vector that read is undefined behaviour.
- Using `int` for distance computations like `dx*dx+dy*dy` on large coordinates — overflow; use `long long`.
- Reaching for nested pairs past 3 values — readability collapses; a small `struct` or `tuple` is clearer.
- Mixing up `.first`/`.second` when "which field is the key" matters (e.g. sorting by roll vs by marks gives totally different results).

## Interview Q&A

- **Q: What is std::pair and when do you reach for it?** A: A two-field bundle `(T1,T2)` used whenever two values must travel together — coordinates, (roll, marks), range (start,end). Past two values, prefer `tuple` or a struct.
- **Q: How does pair comparison (lexicographic) work?** A: Compare `.first`s; if equal, compare `.second`s; otherwise the pair with the smaller `.first` is smaller — never descending into `.second` unless the first ties.
- **Q: How do you sort a vector of pairs by the second value?** A: Provide a comparator lambda: `sort(v.begin(), v.end(), [](auto& a, auto& b){ return a.second < b.second; });`
- **Q: Difference between make_pair and braces?** A: `make_pair` deduces types automatically; brace-init `{a,b}` requires the target type to be known (or C++17 CTAD) — both create the same pair.
- **Q: What does tie() do?** A: It unpacks a pair/tuple into separate variables: `tie(a, b) = p;` assigns `a = p.first`, `b = p.second` in one line; use `tie(a, ignore)` to skip a field.
- **Q: Why is a pair O(1) to compare but O(n log n) to sort?** A: Each single comparison is constant (two fields max), while sorting n elements performs n·log₂(n) such constant compares → net O(n log n).