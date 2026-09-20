# Operations on Data Structures

## Summary
- **Traversal**: visit every element — O(n) for arrays/trees; O(V+E) for graphs.
- **Insertion**: array end O(1), array middle O(n) (shift), linked list front O(1), BST O(log n).
- **Deletion**: stack/queue O(1); array middle O(n) (shift left); BST O(log n).
- **Searching**: unsorted O(n), sorted array O(log n) binary search, hash table O(1) avg.
- **Sorting**: STL `sort()` averages O(n log n). **Merging** two sorted arrays is O(a+b) with two pointers.

## Real-World Analogy
A **class register**: look up a name (search), add a new student (insert), strike out a leaver (delete), reorder alphabetically (sort), and combine two sections' registers (merge). Everything you do to a list, you do to a data structure.

## Files in This Folder
| File              | Purpose                                                       |
|-------------------|---------------------------------------------------------------|
| `01_theory.cpp`   | Pure theory (all 6 operations with cost tables) + array demo: search → insert → delete with prints & edge cases |
| `task.cpp`        | 6 tasks EASY→HARD (find min, insert end, insert at index, delete by value, count occurrences, merge sorted arrays) with solutions |
| `README.md`       | This summary page                                             |

## Cheat Sheet / Syntax
```cpp
int searchArr(int a[], int n, int val){ for(int i=0;i<n;i++) if(a[i]==val) return i; return -1; }

void insertEnd(int a[], int &n, int val){ a[n]=val; n++; }

void insertAt(int a[], int &n, int idx, int val){ for(int i=n;i>idx;i--) a[i]=a[i-1]; a[idx]=val; n++; }

void deleteVal(int a[], int &n, int val){ /* find idx, then shift a[i]=a[i+1]; n--; */ }

// Merge two SORTED arrays: two pointers, take smaller each step.
```

## Complexity Comparison Table
| Operation  | Unsorted array | Sorted array   | Linked list | Balanced BST | Hash table |
|------------|----------------|----------------|-------------|--------------|------------|
| Search     | O(n)           | O(log n)       | O(n)        | O(log n)     | O(1) avg   |
| Insert     | O(1) end / O(n) mid | O(n) shift | O(1) given  | O(log n)     | O(1) avg   |
| Delete     | O(n)           | O(n)           | O(1) given  | O(log n)     | O(1) avg   |
| Sort       | O(n log n)     | already sorted | O(n log n)  | O(n) inorder | —          |
| Merge      | O(a+b)*        | O(a+b)         | O(a+b)      | O(a+b)       | —          |

\* after sorting both inputs.

## ⚠️ Common Mistakes
- Keeping `size` out of sync with actual elements — always update it in insert/delete.
- Shifting **forward** during insertion (left◀right) — overwrites data; shift from back first.
- Deleting with `delete` keyword on an array instead of shifting — arrays aren't `new`'d nodes.
- Forgetting that `int arr[5]` has capacity 5 — inserting beyond capacity writes out of bounds.
- Off-by-one in merge drain loops — drain fully with `while` until both pointers exhaust.

## Interview Q&A
- **Q:** Why is array search O(n) but hash search O(1)? **A:** Array must compare every element; hash maps the key directly to an index in one step (amortized, ignoring collisions).
- **Q:** Insert into the middle of an array? **A:** Shift every later element right — worst case O(n).
- **Q:** What makes merge O(a+b)? **A:** Two pointers advance over each element exactly once, picking the smaller — no rescanning.
- **Q:** Stack vs array insertion? **A:** Both can be O(1) at their "end"; the difference is array *middle* insertion costs O(n) whereas stack only ever uses its top.
- **Q:** Which structure keeps sort cheap? **A:** A balanced BST stays sorted after every insertion — retrieving in-order is O(n); re-sorting an array is O(n log n).