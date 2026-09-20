# Part_02_Complexity_Analysis — PROGRESS

## ✅ STATUS: **19 / 19 COMPLETE** 🎉

| | |
|---|---|
| Topic folders | **19 / 19** ✅ |
| `.cpp` files | **21** |
| `README.md` files | **19** |
| C++ lines | **8,186** |
| Markdown lines | **2,114** |
| Compile warnings (`-Wall -Wextra`) | **0** |
| Runtime errors | **0** |
| `.gitkeep` leftovers | **0** |

---

## Batch-wise Breakdown

### ✅ Batch 1 — folders 01–05

| # | Folder | Files | Real-world analogy |
|---|---|---|---|
| 01 | `Analyzing_an_Algorithm` | theory + priori + posteriori + README | Recipe padh kar time vs stopwatch + biryani |
| 02 | `Characteristics_of_an_Algorithm` | theory + README | Recipe ke 7 rules |
| 03 | `How_to_Write_an_Algorithm` | theory + README | Chai banane ki vidhi |
| 04 | `Best_Average_Worst_Case` | theory + README | Chaabi pehli jeb / auto wale ki kamai |
| 05 | `Time_Complexity` | theory + README | Haath se dhona vs washing machine |

**Verified:** priori `Max=9, Steps=5`; `2n−1` = 19/199/1999. Best 1 / avg 3 / worst 5 → `(n+1)/2`.

---

### ✅ Batch 2 — folders 06–10

| # | Folder | Real-world analogy | Key verified number |
|---|---|---|---|
| 06 | `Average_Case_Analysis` | Gaon + 1 zamindar | GALAT ₹5,05,000 vs SAHI ₹19,900 |
| 07 | `Worst_Case_Analysis` | Ambulance "max 20 min" | Insertion **0 shifts** best / 28 worst |
| 08 | `Binary_Search_Analysis` | Dictionary me MANGO | n=16 → **3 steps**; n=10,48,576 → **20** |
| 09 | `Plot_of_Functions` | Bijli bill 4 ghar | **1000n vs n² crossover at n=1000** |
| 10 | `Algorithmic_Complexities` | Shaadi ke card baantna | n=8 → 1/3/8/24/64/512/511/40320 |

---

### ✅ Batch 3 — folders 11–14

| # | Folder | Real-world analogy | Key verified number |
|---|---|---|---|
| 11 | `Time_Space_Trade_Off` | Chai saaman: store room vs kitchen dabba | fib(35): **2,98,60,703** calls vs memo **69** |
| 12 | `Space_Complexity` | Shaadi ka hall | n=10⁵ → O(n²) = **37.3 GB** |
| 13 | `Auxiliary_Space` | 10 kg aata + tarazu ka bartan | n=10⁶: Heap ~16 B, Merge 3 MB |
| 14 | `Common_Time_Complexities` | Doctor ka nabz dekhna | n=16 → triangle **120**, O(2ⁿ) **1,31,071** |

---

### ✅ Batch 4 — folders 15–19 **(NEW)**

| # | Folder | Real-world analogy | Key verified number |
|---|---|---|---|
| 15 | `Asymptotic_Notations` | **Bachche ki height** (n₀ = "18 saal ke baad") | `3n+5` teeno tarah verify: O(n), Ω(n), Θ(n) |
| 16 | `Big_Oh_Upper_Bound` | **Courier "zyada se zyada 3 din" = CHHAT** | `3n+5 ≤ 4n` from **n=5**; 2n² ka hissa n=1000 pe **99.9%** |
| 17 | `Big_Omega_Lower_Bound` | **300 km / 100 kmph = "kam se kam 3 ghante" = FARSH** | `3n ≤ 3n+5` ∀ n≥1; bubble 7 sorted vs 28 reverse |
| 18 | `Big_Theta_Tight_Bound` | **Train "4–5 ghante ke beech"** | selectionSort **28 = 28** (Θ milta hai); linear **1 vs 8** (nahi milta) |
| 19 | `Amortized_Analysis` | **Saalana recharge ₹3000 / 365 = ₹8 per day** | n=10⁶ amortized = **2.0486** → O(1) |

---

## 🔬 Batch 4 — Verified formula vs actual output

### 15 — `f(n) = 3n + 5` teeno notations

| n | 3n (Ω) | f(n) | 4n (O) | Θ ke beech? |
|---|---|---|---|---|
| 1 | 3 | 8 | 4 | ❌ |
| 3 | 9 | 14 | 12 | ❌ |
| **5** | **15** | **20** | **20** | ✅ ← n₀ |
| 1000 | 3000 | 3005 | 4000 | ✅ |

> Boundary row n=5 pe `15 ≤ 20 ≤ 20` — exact equality, n₀ yahin se.

### 16 — chhote terms kyun gayab hote hain (`2n²+3n+1`)

| n | 2n² ka hissa | 3n ka hissa | 1 ka hissa |
|---|---|---|---|
| 1 | 33.3% | 50.00% | 16.67% |
| 10 | 86.6% | 12.99% | 0.43% |
| 1000 | **99.9%** | 0.15% | 0.00% |

### 18 — Θ exist karta hai ya nahi (n=8)

| Algorithm | Sorted | Reverse / absent | Θ? |
|---|---|---|---|
| `findMax` | 7 | 7 | ✅ Θ(n) |
| `arraySum` | 8 | 8 | ✅ Θ(n) |
| `selectionSort` | **28** | **28** | ✅ Θ(n²) |
| `bubbleSort` | 7 | 28 | ❌ |
| `linearSearch` | 1 | 8 | ❌ |

### 19 — amortized push_back

| n | Resizes | Total copies | Total cost | **Amortized** |
|---|---|---|---|---|
| 10 | 4 | 15 | 25 | 2.50 |
| 1,000 | 10 | 1,023 | 2,023 | 2.02 |
| 10,00,000 | 20 | 10,48,575 | 20,48,575 | **2.05** |

**Doubling vs +1:**

| n | DOUBLE | +1 wala | Kitna bura |
|---|---|---|---|
| 100 | 127 | 4,950 | 38× |
| 5,000 | 8,191 | **1,24,97,500** | **1525×** |

---

## 🛠 Fixes applied in Batch 4

1. **Folder 15 emoji-in-`setw()`** — `"HAAN ✓"` / `"nahi ✗"` `setw()` ke andar the → columns 2 se skew ho rahe the. ASCII `HAAN` / `nahi` kar diya (same fix jo folder 13 me lagaya tha).
2. **Folder 16 percentage table** — hand-written `86.2% / 12.93%` actual `86.6% / 12.99%` se match nahi kar raha tha → real output paste kiya.
3. **Folder 19 copy-count mismatch** — n=10 pe program 15 copies dikhata hai, formula `n−1 = 9` nahi. Reconciling NOTE add kiya: capacity 2 ki power me jaati hai, isliye `copies = (next power of 2) − 1 < 2n` → amortized abhi bhi `< 3` → **O(1) nateeja nahi badalta**.
4. **Saare EXPECTED OUTPUT blocks** ab asli run se copy kiye gaye hain (hand-written nahi).

---

## 📌 Standing rules (agli baar bhi follow karne hain)

- ✅ Real-world analogy PEHLE, technical baad me — har file me
- ✅ `O(?)` bina calculation ke likhna FORBIDDEN
- ✅ Hinglish comments + loop ke andar iteration trace
- ✅ Emoji **kabhi bhi `setw()` ke andar nahi** — sirf README aur free-text `cout` me
- ✅ Program pehle RUN karo, phir real output EXPECTED OUTPUT block me paste karo
- ✅ `-Wall -Wextra` se compile, `timeout 90` ke saath run
- ✅ No practice-problems file

---

## ▶️ NEXT: `Part_01_Data_Structures_Basics` — 24 folders

Per `DEPTH_POLICY.md`:

| Depth | Count | Folders |
|---|---|---|
| **LIGHT** (intro only) | 12 | Arrays, 2D Array, Drawbacks, Linked List, Doubly LL, Self-Referential, Creating Node, malloc, Stack, Queue, Trees, Graphs |
| **FULL detail** | 11 | Data, Information, Data Type, Primitive, Non-Primitive, Abstract Data Type, Operations, Algorithm vs Program, Applications, Advantages, Interview Questions |
| **MEDIUM** (undecided) | 1 | `08_Row_Major_Column_Major_Order` — ⚠️ user se poochhna baaki hai |

**Batch plan:** 5 folders per batch → 5 batches (24 = 5+5+5+5+4).
