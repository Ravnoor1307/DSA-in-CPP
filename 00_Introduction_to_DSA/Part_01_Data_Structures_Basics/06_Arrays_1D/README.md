# 06 — Arrays (1D) — Introduction

- An array is a contiguous block of same-type values stored in memory, accessed through a zero-based index.
- Random access `arr[i]` is constant time because the address is computed as `base + i * sizeof(type)`.
- Size is fixed at compile time for a static array; capacity and "filled count" must be tracked separately.
- Core operations: traverse (O(n)), access (O(1)), insert-end (O(1)), insert-middle (O(n)), delete (O(n)).
- Arrays shine for fixed-size, same-type collections that need fast index access (marks, scores, tokens).

## 🌍 Real-World Analogy

**Railway coach ke fixed compartments:**

- Har dabbe ka number fixed hota hai (0, 1, 2, ...) — yahi **index** hai.
- Compartment 5 ka pata turant milta hai — **O(1) access**.
- Seat no. batao → passenger ka naam turant — pigeonhole principle jaisa.
- Beech me naya dabba jodna ho to saare dabbe shift karne padte hain — **insert-middle O(n)**.

> *Coach me dabbe reserved hain; beech me dabba ghusana = sabko right shift.*

## 📂 Files in this folder

| File | Purpose |
|---|---|
| `01_theory.cpp` | 1D array ka live demo: traverse, access, insert@end, insert@middle (shift), size/edge-cases |
| `task.cpp` | 7 tasks EASY→HARD: traverse → sum → max+index → reverse → linear search → insert → delete |

## 📌 Cheat Sheet / Formulas

```
Address of arr[i]  : base + i * sizeof(type)          // O(1) random access
Size from compiler : n = sizeof(arr) / sizeof(arr[0]) // total capacity
Insert at pos p    : for (i = n; i > p; i--) arr[i] = arr[i-1];   then arr[p] = val; n++;
Delete at pos p    : for (i = p; i < n-1; i++) arr[i] = arr[i+1]; then n--;
Reverse in place   : i from 0..n/2: swap(arr[i], arr[n-1-i])
Linear search      : loop, if (arr[i]==x) return i;  else return -1
```

## ⏱ Complexity at a glance

| Operation | Step Count | Complexity |
|---|---|---|
| Access `arr[i]` | 1 mult + 1 add | f(n) = 1 → **O(1)** |
| Traverse n elements | loop n baar | f(n) = n → **O(n)** |
| Insert at end (capacity ho) | 1 assignment | f(n) = 1 → **O(1)** |
| Insert at middle | (n−p) shifts, worst n | f(n) = n → **O(n)** |
| Delete at middle | (n−p−1) shifts, worst n | f(n) = n → **O(n)** |
| Search (linear) | n comparisons | f(n) = n → **O(n)** |
| Storage of n ints | n × 4 bytes | f(n) = n → **O(n)** |

## ⚠️ Common Mistakes

1. **Out-of-bounds access** — `arr[-1]` ya `arr[n]` kabhi error nahi dikhata, silent UB (galat value / crash) deta hai. Hamesha bounds check.
2. **Capacity vs filled count mix** — `arr[10]` me 5 values; loop `i < 10` chalao to 5 garbage printed. Track `n` alag se.
3. **Insert ke time aage se shift** — `arr[i]=arr[i-1]` ko aage (i=0) se shuru kiya to value overwrite ho jati hai. Always **right shift = peeche se**.
4. **Delete me size na ghataana** — element hata kar bhi n wahi chhod diya to poora array print hota hai repeat.
5. **Reverse me full array swap** — `swap(arr[i], arr[n-1-i])` poori range me kiya to array wapas original aa jata hai. Sirf `i < n/2`.
6. **`sizeof(arr)` ko pointer me use karna** — function me paas hua `arr` pointer hai; `sizeof(arr)/sizeof(arr[0])` wahan galat answer deta hai. Size alag pass karo.

## 🤝 Interview Q&A

**Q1. Array ka random access O(1) kaise?**
Kyunki address formula `base + i*size` hai — koi search nahi, sirf ek multiplication aur addition.

**Q2. Insert-middle O(n) kyu?**
Kyunki position ke baad ke saare elements ko ek-ek shift karna padta hai; worst case first position → n shifts.

**Q3. Static vs dynamic array?**
Static: `int arr[10]` — size compile-time fixed. Dynamic: `new int[n]` / `vector<int>` — runtime me size allocate hota hai.

**Q4. Array me -1 index kyu nahi?**
C++ me indexing 0-based hai; negative ya >= n index memory ke bahar ka address points karta hai — undefined behaviour.

**Q5. delete kaise kaam karta hai?**
Element hatane ke baad uske right ke sabhi elements ek step left khisak jate hain aur `n` ek kam ho jata hai — "value" wakayi delete nahi hoti, bas khud ki jagah overwrite ho jati hai.

**Q6. Array sorted nahi hai, element dhundna?**
Linear search O(n). Array sorted ho to binary search O(log n) use kar sakte ho.