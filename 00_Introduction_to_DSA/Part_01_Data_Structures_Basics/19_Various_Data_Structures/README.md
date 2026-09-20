# Various Data Structures — Overview

## Summary
- **Stack** (LIFO): push/pop at top — undo, recursion, back-button.
- **Queue** (FIFO): add at back, remove at front — printer jobs, BFS.
- **Linked List**: nodes chained by pointers — fast insert/delete at known spot, playlists.
- **BST**: sorted tree (left < node < right) — fast directional search, dictionaries.
- **Heap**: min/max always at root — priority queues, Dijkstra.
- **Hash table**: key → index via hash — near O(1) lookups, caches.
- **Graph**: nodes + edges — routes, social networks.
- **Trie**: character tree sharing prefixes — autocomplete, spell check.

## Real-World Analogy
A household moving-box stack (stack), a ticket line (queue), a phone-book (hash/map), a challenge tree in a game (tree/decision tree). Every daily "container with rules" is a data structure.

## Files in This Folder
| File              | Purpose                                                       |
|-------------------|---------------------------------------------------------------|
| `01_theory.cpp`   | Pure theory (all 8 DS in context, one-liner each) + STL demo: `vector` and `map` |
| `task.cpp`        | 6 tasks EASY→HARD (identify DS, stack LIFO, queue FIFO, map lookup, vector max, stack palindrome) with solutions |
| `README.md`       | This summary page                                             |

## Cheat Sheet / Syntax
```cpp
#include <stack>    stack<int> s;      s.push(x); s.top(); s.pop(); s.empty();
#include <queue>    queue<int> q;      q.push(x); q.front(); q.pop(); q.empty();
#include <map>      map<string,int> m; m["k"]=v; m.find("k"); it->first, it->second;
#include <vector>   vector<int> v;     v.push_back(x); v[i]; v.size(); v.empty();
```

## Complexity Comparison Table
| DS               | Access        | Insert        | Delete       | Use when...                |
|------------------|---------------|---------------|--------------|----------------------------|
| Stack            | top O(1)      | push O(1)     | pop O(1)     | LIFO, undo                 |
| Queue            | front O(1)    | enqueue O(1)  | dequeue O(1) | FIFO, scheduling           |
| Linked list      | search O(n)   | O(1)*         | O(1)*        | known node, playlists      |
| BST (balanced)   | O(log n)      | O(log n)      | O(log n)     | sorted + search            |
| Heap             | min/max O(1)  | O(log n)      | O(log n)     | always want min/max        |
| Hash table       | O(1) avg      | O(1) avg      | O(1) avg     | lookup by key              |
| Graph (matrix)   | O(V²) space   | edge O(1)     | —            | relationships              |
| Trie             | O(len) prefix | O(len)        | O(len)       | autocomplete               |

*at a known/inserted position.

## ⚠️ Common Mistakes
- Getting LIFO/FIFO backwards — draw the container before answering.
- `pop()` on an **empty** stack/queue → crash; always check `empty()` first.
- Accessing `m["missing"]` inserts a default 0 — use `find()` when you only want a lookup.
- Forgetting `v.size()` returns `size_t`; cast to `int` to avoid comparison warnings.
- Using `front()` vs `top()`: queues use `front()`, stacks use `top()`.

## Interview Q&A
- **Q:** Stack or queue for "undo"? **A:** Stack — last action undone first (LIFO).
- **Q:** How does a hash table get O(1)? **A:** Hash function maps a key straight to an index; **collisions** can degrade it to O(n) worst case.
- **Q:** Difference between vector and map? **A:** Vector = dynamic index-based list (insertion order); map = sorted key→value pairs (log n lookups).
- **Q:** Where is a heap used in real life? **A:** Priority queues — the OS scheduler runs the process with highest priority first.
- **Q:** What makes a trie better than a set of strings? **A:** Tries share common prefixes, so prefix searches (autocomplete) run in O(length) instead of scanning all words.