# 13 — Auxiliary Space

## 📌 Summary (5 English lines)
- Auxiliary Space is the extra memory an algorithm uses **besides the input** it was given — scratch arrays, hash tables, recursion stack frames, and helper variables.
- Space Complexity = **Input Space + Auxiliary Space**.
- The total is usually reported as O(n), but the auxiliary part is the interesting answer the interviewer asks for.
- Recursion's auxiliary space is the **maximum stack depth**, not the total number of calls.
- The output the problem asks you to return is generally **not** counted; only the scratch space to build it is.

## 🌍 Real-World Analogy

**Khaana banaana n guests ke liye.** Guests khud (input) apni kursiyan lete hain. Recipe decide karti hai kitni **extra plates** chahiye:

| Recipe style | Extra gear (Auxiliary) |
|---|---|
| Wash & reuse one plate | O(1) — 1 plate |
| Fresh plate for everyone | O(n) — n plates |
| Note-on-fridge recursion | O(n) — n unfinished tickets (only the current pile counts!) |

```
Space Complexity = Input Space (guests) + Auxiliary Space (extra plates)
```

---

## 📂 Files

| File | Kya hai |
|---|---|
| `01_theory.cpp` | linear search (aux O(1)) vs copy array (aux O(n)) vs recursive sum (aux O(n) stack) with full input/aux/total accounting |
| `task.cpp` | 6 tasks: swap, iterative vs recursive sum, reverse, classification, recursive power, prefix-sum |

---

## 📐 Formulas / Cheat Sheet

```
Auxiliary Space = extra memory beside the input
Space Complexity = Input Space + Auxiliary Space
Recursion Aux   = stack depth (NOT total calls)
```

| Aux source | Class | Example |
|---|---|---|
| Temp variable(s) | O(1) | swap, two-pointer |
| New 1D array | O(n) | copy array, prefix sum |
| New n×n matrix | O(n²) | adjacency matrix |
| Recursion depth n | O(n) | plain recursion (sum, fib) |
| Recursion depth log n | O(log n) | halving recursion (binary search, fast power) |

---

## 📊 Complexity Comparison Table

| Function | Input | Auxiliary | Total | Time |
|---|---|---|---|---|
| `linearSearch` | O(n) | **O(1)** | O(n) | O(n) |
| `copyArray` | O(n) | **O(n)** | O(n) | O(n) |
| `sumRecursive` | O(n) | **O(n)** ⚠️ stack | O(n) | O(n) |
| `reverseInPlace` | O(n) | **O(1)** | O(n) | O(n) |
| `reverseNewArray` | O(n) | **O(n)** | O(n) | O(n) |
| `power(x,n)` recursive | O(1) | **O(log n)** | O(log n) | O(log n) |

---

## ⚠️ Common Mistakes

1. **Recursion ka space O(2ⁿ) likhna** — tree me 2ⁿ calls hain, par ek waqt me sirf depth frames → **O(n)**.
2. **Returned output ko auxiliary manna** — problem ne joh output maanga, wo count nahi hota; sirf scratch memory count hoti hai.
3. **Vector by value pass karna** — `f(vector<int> arr)` poori copy banaata hai → hidden **O(n)** aux. `&` lagao.
4. **Nested 2D matrix ko O(n) samajhna** — n×n = **O(n²)** cells.
5. **Input ko auxiliary bol dena** — given array pehle se thi; wo input space hai, kabhi extra nahi.

---

## 💬 Interview Q&A

**Q1:** *An algorithm takes an array of size n and uses a hash set of size n. What is its auxiliary space?*
**A:** O(n) — the hash set is extra memory the algorithm itself created. Input = O(n), Total = O(n + n) = O(n).

**Q2:** *A recursive function calls itself n/2 times, each call one level deep. Aux space?*
**A:** O(n/2) = O(n) — stack frames = maximum depth.

**Q3:** *Merge sort vs quick sort auxiliary space?*
**A:** Merge sort **O(n)** (temp merge array); quick sort **O(log n)** average (stack depth = levels).

**Q4:** *"Is the output array 'auxiliary'?"*
**A:** Usually no. Auxiliary = scratch used *internally*; the requested output is the return value, excluded by most definitions.

**Q5:** *Two-pointer palindrome checker — aux?*
**A:** O(1) — only two indices; no new structure.