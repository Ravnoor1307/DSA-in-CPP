# 01_Fundamentals — Depth Policy

> Ye folder DSA ki **NEEV** hai. Yahan **sab kuch DETAILED** hoga.
> `00_Introduction_to_DSA` me jo cheezein LIGHT rakhi thi, unka **asli implementation** yahan aayega.

---

## 🟢 SAB DETAILED — koi LIGHT topic nahi

`00_Introduction_to_DSA` me DEPTH_POLICY ne 12 topics LIGHT rakhe the (Arrays, Linked List, Stack, Queue, Trees, Graphs...) kyunki wo **introduction** folder tha.

**Yahan ulta hai.** Ye foundation folder hai — agar yahan kachcha reh gaya to aage `06_Linked_List/` me pointer samajh nahi aayenge. Isliye:

| Part | Folders | Depth |
|---|---|---|
| Part_01 C++ Basics | 01–19 | 🟢 **DETAILED** |
| Part_02 OOPs | 20–29 | 🟢 **DETAILED** |
| Part_03 STL | 30–46 | 🟢 **DETAILED** |

---

## ⭐⭐ EXTRA-DEEP topics (inme sabse zyada mehnat)

Ye wo topics hain jinpe **poora DSA khada hai**. Inme normal DETAILED se bhi **zyada** depth chahiye — memory diagram, address print karke proof, common bugs ka live demo:

| Folder | Kyun extra-deep | Aage kahan kaam aayega |
|---|---|---|
| `14_Pointers` | Har DS ki neev | Linked List, Tree, Graph |
| `15_Pointers_with_Arrays` | `arr` = `&arr[0]` ka rishta | Array passing, pointer arithmetic |
| `16_References` | copy vs reference = TLE vs AC | `vector<int>&` pass karna |
| `17_Dynamic_Memory_Allocation` | `new Node()` | Har node-based DS |
| `18_Structures` | `struct Node` | Linked List, Tree |
| `19_Recursion_Basics` | call stack visualize karna | Tree, Graph, DP, Backtracking |
| `26_Polymorphism` | vtable, virtual | Interview favourite |
| `39_Priority_Queue` | heap ka andar ka kaam | Dijkstra, Top-K, Greedy |
| `42_Map` / `43_Unordered_Map` | frequency counting | 40% hashing problems |
| `45_Custom_Comparator` | lambda + comparator ka logic | Custom sorting |

**In folders me compulsory:**
- Memory diagram (ASCII art)
- **Asli addresses print** karke proof (jaise folder 00 me kiya tha)
- Kam se kam 1 **common bug ka live demo** (dangling pointer, shallow copy, etc.)
- Dry run

---

## 📄 File pattern

### Theory-only topics
```
01_<topic>_theory.cpp
README.md
```
Misaal: `01_Variables_and_Data_Types`, `21_Access_Modifiers`, `30_STL_Introduction`

### Approach-based topics
```
01_<topic>_theory.cpp
02_<topic>_bruteforce_approach.cpp
03_<topic>_better_approach.cpp      (agar exist kare)
04_<topic>_best_approach.cpp
README.md                            <- hamesha LAST
```
Misaal: `06_Patterns_using_Loops`, `19_Recursion_Basics`, `44_STL_Algorithms`, `46_Bit_Manipulation`

**NO practice-problems file.** Concept + approaches only.

---

## ⚠️ GOLDEN RULE (har file me, bina exception)

**REAL-WORLD SCENARIO PEHLE, PHIR TECHNICAL EXPLANATION.**

Bina real-life example ke koi bhi concept explain nahi hoga — na theory file me, na approach file me, na README me.

**Is folder ke liye analogy guidelines:**

| Concept | Analogy ka style |
|---|---|
| Variable | dabba jisme naam likha hai |
| Data type | dabbe ka size (matchbox vs bori) |
| Pointer | parchi jisme ghar ka **pata** likha hai |
| Reference | usi ghar ka **doosra naam** (urf) |
| `new`/`delete` | plot kiraye pe lena / khali karna |
| Class | **naksha** · Object = us naksha se bana **ghar** |
| Constructor | ghar banne pe **grih-pravesh** |
| Destructor | ghar todte waqt **saaman nikalna** |
| Inheritance | **baap ki property** bete ko milna |
| Polymorphism | ek hi shabd, alag matlab ("bank" = paisa/nadi kinara) |
| Vector | **pandal** (bada ho sakta hai) |
| Map | **register** jisme naam ke saamne number |
| Priority Queue | **hospital emergency** |

> Folder 00 me use hui analogies ke saath **consistent** rehna hai. Jo analogy wahan use hui, wahi yahan bhi (jaise stack = plates ka dher, queue = bus stop line, pandal = dynamic).

---

## ⚠️ COMPLEXITY RULE

Khaali `O(n)` likhna **FORBIDDEN**. Hamesha calculation dikhani hai:

```
// TIME COMPLEXITY CALCULATION:
// - Outer loop: n baar chalega
// - Inner loop: har outer iteration me n baar
// - Total = n × n = n²
// → Time Complexity = O(n²)
```

Log-based ke liye:
```
// n/2^k = 1  ->  n = 2^k  ->  k = log2(n)
// → O(log n)
```

---

## ⚠️ IN-CODE RULES (folder 00 se seekhe hue traps)

Ye sab folder 00 ke 45 files likhte waqt **actually hue** the. Repeat nahi karne:

1. ✅ Hinglish comments **har important line** pe + loop ke andar iteration trace
2. ✅ **Emoji kabhi `setw()` ke andar nahi** — multi-byte hote hain, columns tedhe ho jaate hain. Sirf README aur free-text `cout` me.
3. ✅ Comment block ke andar `*/` **kabhi mat likho** (nested comment bug)
4. ✅ `//` comment ki line **kabhi `\` pe khatam na ho** — line continuation ban jayegi, agli line kha jayegi
5. ✅ Timing demo me `nanoseconds` + `REPEAT` + `sink`, aur **`sink` ko program ke ANT me print karo** (warna `-O2` poore loop delete kar deta hai)
6. ✅ Benchmark me har iteration pe **alag input** do (warna `-O2` loop-invariant hoist kar deta hai)
7. ✅ Program **pehle RUN karo**, phir `[PLACEHOLDER]` ki jagah **real output** paste karo
8. ✅ Machine-dependent values (address, timing) pe **disclaimer** likho
9. ✅ `-Wall -Wextra` pe **0 warning** — ye bar hai
10. ✅ Output agar lesson ke khilaf jaye to program ko **khud detect** karke explain karna chahiye

---

## 🎯 Is folder ka MAKSAD

Folder 01 khatam hone ke baad student:

- `int* p = &x;` dekh kar **ghabraye nahi**
- `struct Node { int data; Node* next; };` **khud likh sake**
- Recursion ka **call stack kaagaz pe draw** kar sake
- `vector`, `map`, `priority_queue` **bina Google ke** use kar sake
- Custom comparator se sorting **khud likh sake**
- OOPs ke sawaalon ka **interview me jawab** de sake

**Tabhi `03_Array/` aur uske aage ka safar aasan hoga.**
