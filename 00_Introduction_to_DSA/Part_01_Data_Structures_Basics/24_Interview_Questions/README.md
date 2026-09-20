# 24. Interview Questions — DSA Basics Revision

- This folder is a quick revision kit: 15 crisp interview Q&As plus code that proves you can implement basics on the spot.
- Core vocabulary: data structure, linear vs non-linear, stack (LIFO), queue (FIFO), recursion, in-place, stable sort.
- Big-O levels every beginner must recognise: O(1), O(log n), O(n), O(n²).
- The working demo implements **linear search** — the classic "are you code-ready?" question — returning the index or -1.
- Tasks drill array searching, counting, min/max, in-place reverse, second largest, and a menu-driven app.

**Real-world analogy:** A general knowledge quiz is useless unless you can also write the answer; these files pair the questions (theory) with the answers you must be able to produce in code (tasks).

## Files in this folder
| File | Purpose |
|------|---------|
| `01_theory.cpp` | 15-topic interview Q&A revision + linear search demo with dry run & complexity |
| `task.cpp` | 7 code-drill tasks (search, count, min/max, reverse, second-largest, menu app) |
| `README.md` | This summary, cheat sheet, common mistakes, quick-fire Q&A |

## Cheat sheet / syntax
```cpp
// linear search — O(n) time, O(1) space
for (int i = 0; i < n; i++) if (arr[i] == key) return i;
return -1;

// count occurrences
int c = 0; for (int i = 0; i < n; i++) if (arr[i] == key) c++;

// in-place reverse (two pointers)
int l = 0, r = n - 1; while (l < r) { swap(arr[l], arr[r]); l++; r--; }

// second largest (single pass)
int mx = INT_MIN, sec = INT_MIN;
for (i...) { if (arr[i] > mx) { sec = mx; mx = arr[i]; }
             else if (arr[i] > sec && arr[i] != mx) sec = arr[i]; }
```

## Complexity comparison (basics you must state in interviews)
| Operation | Complexity | Requirement |
|-----------|------------|-------------|
| Index access in array | O(1) | contiguous memory |
| Linear search | O(n) | none (unsorted ok) |
| Binary search | O(log n) | MUST be sorted |
| Bubble sort | O(n²) | none |
| Merge sort | O(n log n) | extra O(n) space |

## ⚠️ Common mistakes
- Returning early in "count occurrences" tasks — only "find first" returns early.
- Forgetting the `-1` not-found convention when searching.
- Reversing an array into a second array instead of **in-place** (costs O(n) space).
- Second-largest done by sorting — ok but wasteful; interviewer wants the single-pass trick.
- Not handling edge cases: empty array, single element, key absent, duplicates.
- Using `arr[i] != mx` in the second-largest check so duplicates don't count twice.

## Quick-fire Interview Q&A
- **Q1:** What is a data structure? — An organised format for storing and accessing data (array, stack, tree, ...).
- **Q2:** Array vs linked list? — Contiguous fixed-size O(1) index vs node-based dynamic O(n) search.
- **Q3:** Stack vs queue? — LIFO vs FIFO.
- **Q4:** What is time complexity? — How runtime grows with input size, in Big-O.
- **Q5:** Linear vs binary search? — O(n) any data vs O(log n) sorted-only.
- **Q6:** What is an in-place algorithm? — Uses only O(1) extra space.
- **Q7:** What is recursion? — A function calling itself with a base case that stops it.
- **Q8:** Why structs exist? — To bundle different types (int + char[] + float) into one non-homogeneous record.