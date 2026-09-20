# 45_Custom_Comparator — Telling sort() HOW to Order

- A comparator is a callable `bool cmp(a, b)` returning `true` exactly when `a` must come BEFORE `b`; the same one rule powers `sort`, `set`, and `priority_queue`.
- Written 3 ways: plain function, lambda (most common, can `[capture]` outside variables), or functor struct — containers (`set`, `priority_queue`) force the functor/`greater<T>` form because they store the comparator as a TYPE.
- Strict-weak contract: `cmp(a,a)` must be false, transitive, and not `<=` — breaking it is undefined behaviour (sort can loop forever).
- Ties are where ranking rules live: `if (a.marks != b.marks) return a.marks > b.marks; return a.name < b.name;`
- `priority_queue<T, vector<T>, greater<T>>` = min-heap (smallest served first); your own functor flips the comparison direction there.

## Real-world analogy
The admission merit list blue-print: sort by marks descending, and when two students tie, push the alphabetically-earlier name up. The canteen serves the cheapest dish first (min-heap keyed on price). The playlist orders by length then alphabet. One comparator per rule, one call per list.

```
merit order rule:  marks desc ──primary──►  name asc ──tie-break──►  sorted list
priority_queue:   "true when b should pop first" ⇒ a becomes lower priority ⇒ min-heap
```

## Files in this folder

| File | Purpose |
|---|---|
| `01_theory.cpp` | Pure concept + compile-ready demo: function/lambda/functor comparators, 3-way tie-break, pairs by second (tie first desc), strings by length, objects by field, lambda captures, custom min-heap via `greater` and via functor, `set<int,greater>`, stability test |
| `task.cpp` | 6 tasks easy→hard (marks-desc ranks, last-digit sort, custom priority_queue, pair two-key sort, string length sort, `std::merge` with comparator) + full solutions |

## Cheat sheet / syntax table

| Goal | Code |
|---|---|
| Descending ints (function) | `bool desc(int a,int b){return a>b;}` → `sort(v.b,v.e,desc)` |
| Descending ints (lambda) | `sort(v.b,v.e,[](int a,int b){return a>b;});` |
| Pairs by second asc | `return a.second < b.second;` |
| Pairs 2nd asc, 1st desc | `if(a.second!=b.second)return a.second<b.second; return a.first>b.first;` |
| Strings by length | `return a.size() < b.size();` |
| Objects by field | `return a.marks > b.marks;` (+ tie line) |
| Lambda with capture | `sort(v.b,v.e,[cap](a,b){...use cap...});` |
| Min-heap built-in | `priority_queue<int,vector<int>,greater<int>>` |
| Min-heap custom | `struct Cmp{bool operator()(Dish&a,Dish&b)const{return a.price>b.price;}};` |
| Set descending | `set<int, greater<int>> s;` |
| Merge sorted lists | `std::merge(aB,aE,cB,cE,out,comp)` — O(n) |

## Complexity — with the math

- **Time:** comparator replaces default `operator<` at identical cost O(1) per compare; the resulting sort is still Introsort with log n halving levels × O(n) work per level → **O(n log n)**. The containers that embed a comparator: set insert = red-black tree walk of height ≤ 2·log₂(n+1) → **O(log n)**; priority_queue push/pop = sift up/down through log n heap height → **O(log n)**; `std::merge` walks A then B once → **O(|A|+|B|)**.
- **Space:** sort is in-place → **O(1)** auxiliary (+ O(log n) Introsort recursion stack), comparator object O(1). set/heap store n nodes → O(n) for the data itself; functor object O(1).

## ⚠️ Common mistakes

- **Using `<=` instead of `<` in the comparator** → violates strict-weak ordering: `cmp(a,a)==true` breaks the contract → undefined behaviour, possible infinite loop.
- **Only comparing one field when the rule says two** → ties come out in arbitrary order; a rank list needs the full tie-break written explicitly.
- **`priority_queue` comparator direction** → the mental model flips; `greater<int>` means SMALLEST on top, and a custom `operator()` returning `a.price > b.price` makes the min-heap even when it feels backwards.
- **Passing a bare lambda to `set`/`priority_queue` template** → those need a TYPE; use `greater<int>` or a functor struct (or wrap with `decltype(lambda)`).
- **Plain `sort` stability** → duplicates keep NO guaranteed order; if original relative order of equals matters, use `stable_sort`.
- **Modifying a captured variable** in a comparator — capture by value `[cap]` to keep the decision deterministic.

## Interview Q&A

1. **What is a comparator and what must it obey?** A `bool(a,b)` callable saying "a first"; it must be a strict weak ordering — `cmp(a,a)` false, transitive, and no "≤" semantics — or sort gets undefined behaviour.
2. **Sort a vector of pairs by second then first desc?** Write the two-line body: primary `a.second < b.second`, tie `a.first > b.first`.
3. **How do you build a min-heap with `priority_queue`?** `priority_queue<int, vector<int>, greater<int>>` — the comparator type flips max-heap default. Custom struct returning `a.key > b.key` works the same for objects.
4. **Lambda with captures in a comparator — why?** To compare against a captured threshold/offset; capture `[x]` by value so the decision can't mutate under you.
5. **Stability: `sort` vs `stable_sort`?** Neither `sort` wrongly; plain sort makes no promise for equal keys, `stable_sort` keeps relative order (worst O(n log² n) ÷ O(n log n) with memory).
6. **`std::merge` with a comparator?** Both inputs must already satisfy that comparator; the output has it too, and the walk is O(A+B) — faster than re-sorting n log n.