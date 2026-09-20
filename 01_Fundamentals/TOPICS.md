# 01_Fundamentals — Topics Tree

**Total: 46 subfolders** · 3 parts me bata hua

> Ye folder DSA ki **NEEV** hai. Yahan C++ ke wo saare tools seekhenge jo `03_Array` se lekar `15_Dynamic_Programming` tak har jagah kaam aayenge.

---

## 📁 Structure

```
01_Fundamentals/
├── TOPICS.md                      <- ye file
├── DEPTH_POLICY.md                <- LIGHT vs DETAILED rules
├── setup_01_subfolders.bat        <- 46 subfolders banane wali script (CRLF, idempotent)
│
├── Part_01_Cpp_Basics/            (19 folders)
│   ├── 01_Variables_and_Data_Types
│   ├── 02_Input_Output
│   ├── 03_Operators
│   ├── 04_Conditional_Statements
│   ├── 05_Loops
│   ├── 06_Patterns_using_Loops
│   ├── 07_Functions
│   ├── 08_Function_Overloading
│   ├── 09_Scope_and_Memory
│   ├── 10_Arrays_1D
│   ├── 11_2D_Arrays
│   ├── 12_Strings
│   ├── 13_string_Class
│   ├── 14_Pointers                ⭐
│   ├── 15_Pointers_with_Arrays    ⭐
│   ├── 16_References              ⭐
│   ├── 17_Dynamic_Memory_Allocation ⭐
│   ├── 18_Structures              ⭐
│   └── 19_Recursion_Basics        ⭐
│
├── Part_02_OOPs/                  (10 folders)
│   ├── 20_Classes_and_Objects
│   ├── 21_Access_Modifiers
│   ├── 22_Constructors
│   ├── 23_Destructors
│   ├── 24_Encapsulation
│   ├── 25_Inheritance
│   ├── 26_Polymorphism
│   ├── 27_Abstraction
│   ├── 28_Static_Members_and_this_Pointer
│   └── 29_Friend_Functions
│
└── Part_03_STL/                   (17 folders)
    ├── 30_STL_Introduction
    ├── 31_Vector
    ├── 32_2D_Vector
    ├── 33_Pair
    ├── 34_Iterators
    ├── 35_List
    ├── 36_Stack_STL
    ├── 37_Queue_STL
    ├── 38_Deque
    ├── 39_Priority_Queue          ⭐
    ├── 40_Set
    ├── 41_Unordered_Set
    ├── 42_Map                     ⭐
    ├── 43_Unordered_Map           ⭐
    ├── 44_STL_Algorithms
    ├── 45_Custom_Comparator       ⭐
    └── 46_Bit_Manipulation
```

---

## 🔄 Naming decisions (raw topic → folder name)

| # | Aapka raw topic | Folder name | Kyun badla |
|---|---|---|---|
| 1 | Variables & Data Types | `01_Variables_and_Data_Types` | `&` → `and` (Windows-safe) |
| 2 | Input Output (cin, cout, fast I/O) | `02_Input_Output` | bracket hataya |
| 9 | Scope & Memory | `09_Scope_and_Memory` | `&` → `and` |
| 10 | Arrays (1D) | `10_Arrays_1D` | bracket hataya |
| 11 | 2D Arrays | `11_2D_Arrays` | as-is |
| 13 | string Class | `13_string_Class` | lowercase `string` jaan-boojh kar (C++ ka type hai) |
| 15 | Pointers with Arrays & Functions | `15_Pointers_with_Arrays` | chhota kiya, functions andar cover hoga |
| 20 | Classes & Objects | `20_Classes_and_Objects` | `&` → `and` |
| 28 | Static Members & this Pointer | `28_Static_Members_and_this_Pointer` | `&` → `and` |
| 36 | Stack (STL) | `36_Stack_STL` | bracket hataya |
| 37 | Queue (STL) | `37_Queue_STL` | bracket hataya |
| 40 | Set & Unordered_Set | `40_Set` + `41_Unordered_Set` | ⚠️ **ALAG kiye** — niche note dekho |
| 41 | Map & Unordered_Map | `42_Map` + `43_Unordered_Map` | ⚠️ **ALAG kiye** — niche note dekho |
| 43 | Sorting with Custom Comparator | `45_Custom_Comparator` | chhota kiya |
| 44 | Bitset & Basic Bit Manipulation | `46_Bit_Manipulation` | bitset andar cover hoga |

### ⚠️ Set/Map ko alag karne ka faisla

Aapki **numbered list** me ye combined the (`40. Set & Unordered_Set`), par aapki **`TOPICS:` line** me alag-alag the, aur aapne khud **"46 topics"** likha tha.

`TOPICS:` line ko follow kiya → **46 folders**.

Ye technically behtar bhi hai: `set` (Red-Black tree, O(log n), sorted) aur `unordered_set` (hash, O(1), unordered) **alag data structures** hain — inka comparison hi interview ka sawaal hai. Alag folder me har ek ko poora space milega, aur dono ke README me ek-dusre ka comparison table hoga.

> Agar aap combined chahte the to bol dena — merge kar dunga (46 → 44).

---

## ⭐ Star topics — DSA me kahan kaam aayenge

| Topic | Folder | DSA me kahan |
|---|---|---|
| **Pointers** | 14, 15 | Linked List, Trees, Graphs — poora game isi pe |
| **References** | 16 | Function me array/vector pass karna (copy bachana) |
| **Dynamic Memory** | 17 | `new Node()` — node creation |
| **Structures** | 18 | `struct Node` banana |
| **Recursion** | 19 | Trees, Graphs, Sorting, DP — sab isi pe |
| **Priority Queue** | 39 | Heap, Dijkstra, Greedy, Top-K |
| **Map / Unordered_Map** | 42, 43 | Frequency counting, hashing problems |
| **Custom Comparator** | 45 | Custom sorting — interview favourite |

---

## 📦 Batch plan (5 batches — aapki suggestion ke hisaab se, thoda adjust)

| Batch | Folders | Topics | Kya hai |
|---|---|---|---|
| **1** | 01–09 | 9 | C++ Basics — variables se scope tak |
| **2** | 10–13 | 4 | Arrays & Strings |
| **3** | 14–19 | 6 | ⭐ **Pointers → Recursion (CRITICAL)** |
| **4** | 20–29 | 10 | OOPs |
| **5** | 30–46 | 17 | 🔥 STL |

> ⚠️ Batch 5 me 17 folders hain — ye bahut bada hai. Main ise **5a (30–38)** aur **5b (39–46)** me tod dunga, warna quality gir jayegi.

---

## 📄 File pattern (har subfolder me)

```
01_<topic>_theory.cpp              <- concept + real-world + working demo
02_<topic>_bruteforce_approach.cpp <- agar approach-based topic ho
03_<topic>_best_approach.cpp       <- agar better approach exist kare
README.md                          <- hamesha LAST
```

Theory-only topics (jaise `01_Variables_and_Data_Types`) me sirf `01_..._theory.cpp` + `README.md` hoga.
Approach-wale topics (jaise `06_Patterns_using_Loops`, `19_Recursion_Basics`, `46_Bit_Manipulation`) me multiple approach files aayengi.

**NO practice-problems file** — concept + approaches only.
