# Iterators — The Pointers of STL

An iterator is a generalized pointer that lets you walk through any container (`vector`, `list`, `map`, `set`, `deque`) with one uniform syntax: `begin()` marks the first element, `end()` marks one-past-the-last. You move with `++`/`--`, read/write with `*it`, jump arbitrary distances with `std::advance`, and walk backwards with `rbegin()`/`rend()`. Iterators come in five power categories — input, output, forward, bidirectional, random-access — and a stronger category can always stand in for a weaker one. Writing `auto it = v.begin()` avoids typing long iterator type names. All STL algorithms (`sort`, `find`, `count`, ...) are built on iterators, so learning them unlocks the whole library.

- Real-world analogy: the train conductor's pointing finger — he starts at coach one (begin), reads each coach (*it), steps forward (++), and after the last coach reaches the fence (end) where he stops; he can also walk the train from tail to head with reverse iterators.

## Files in this folder

| File            | Purpose                                                                 |
| --------------- | ----------------------------------------------------------------------- |
| `01_theory.cpp` | Pure theory: categories ladder ASCII, begin/end diagram, iterator vs index, advance, modify-via-iterator, reverse iteration, map iteration, const_iterator, empty-container edge. |
| `task.cpp`      | 6 tasks (easy → hard): print with iterators only, sum via iterator, replace all x with y, reverse print with rbegin/rend, advance ± steps, double every value in place. |
| `README.md`     | This summary, cheat sheet, complexity derivation, mistakes, interview Q&A. |

## Cheat sheet / syntax table

| Snippet                                        | What it does                         | Time complexity |
| ---------------------------------------------- | ------------------------------------ | --------------- |
| `auto it = v.begin()`                          | Iterator to first element            | O(1) |
| `v.end()`                                      | One-past-last (fence, never deref)   | O(1) |
| `*it`                                          | Read or write the element            | O(1) |
| `++it` / `--it`                                | Move forward / backward              | O(1) |
| `it1 == it2` / `it1 != it2`                    | Compare positions                    | O(1) |
| `advance(it, k)`                               | Move k steps (any category)          | vector O(1), list O(k) |
| `next(it, k)` / `prev(it, k)`                  | Get iterator k away without moving   | vector O(1), list O(k) |
| `v.rbegin()` / `v.rend()`                      | Reverse walk from the tail           | O(1) |
| `v.begin()` vs `v.cbegin()`                    | Writable vs read-only (const) view   | O(1) |
| `for (auto& x : v)`                            | Range-for sugar over iterators       | O(n) total |

## Complexity: time & space (with derivation)

- **`*it` / `++it` O(1)**: dereferencing is one memory read; advancing a vector (random-access) iterator is a single pointer bump — both constant work → **O(1)**.
- **`advance(it, k)` O(k)**: on random-access containers it is pointer arithmetic (constant), but on a bidirectional container (e.g. `list`) it must hop k nodes one by one → worst case k = n → **O(n)**.
- **Full traversal O(n)**: printing or summing n elements performs one O(1) dereference + one O(1) advance per element → n · O(1) → **O(n)**.
- **Reverse traversal O(n)**: `rbegin()`/`rend()` merely flip the direction — still n steps of constant work → **O(n)**.
- **Space O(1)**: an iterator holds just one position pointer/token; no copy of the container is created during iteration → **O(1)** per iterator (container itself remains O(n)).

## ⚠️ Common mistakes

- Dereferencing `end()` — it points past the last element; reading/writing it is undefined behaviour.
- Using `it++` in loops: fine, but `++it` avoids the temporary copy; be consistent.
- Letting iterators dangle: after `push_back` (past capacity), `insert`, or `erase`, old iterators may be invalid — recompute them.
- Assumming every container supports `it + k` / `it[n]` — only random-access (`vector`, `deque`) do; `list`/`set`/`map` need `advance`.
- Confusing `auto x : v` (copies each element, writes lost) with `auto& x : v` (modifies originals).
- Checking `it == end()` after `find` is fine, but `end()` for empty containers equals `begin()` — loops over empty data are safe, just make sure the body tolerates zero runs.

## Interview Q&A

- **Q: What are the 5 iterator categories and their power order?** A: input → output → forward → bidirectional → random-access. A stronger category satisfies every requirement of the weaker ones, so a `vector` iterator can be used anywhere.
- **Q: Iterator vs index — which is better?** A: Index (`v[i]`) works only on random-access containers and mixes bounds bugs; iterators work uniformly on every STL container and are what all algorithms consume. For raw speed on vectors either is O(1).
- **Q: How does rbegin/rend work?** A: `rbegin()` returns a reverse iterator pointing at the last element; its `++` moves toward the front; walking `for (it = rbegin(); it != rend(); ++it)` yields data in reverse order without copying.
- **Q: When does advance cost O(n)?** A: On a `std::list` the iterator must physically visit each intermediate node; on a `vector`/`deque` the jump is pure arithmetic, so `advance` is O(1) there.
- **Q: What breaks iterators?** A: Structural container changes — reallocation (push_back past capacity), insert, erase, clear — can invalidate outstanding iterators/pointers; never use an iterator across such an operation.