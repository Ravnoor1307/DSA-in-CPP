# 35. List 🔴 EXTRA-DEEP — *Part_03 STL 6/17*

> **Ek line me:** `list` **kitaab me sabse tez** dikhti hai, aur **asli machine pe aksar sabse dheemi** nikalti hai. Ye topic isliye zaroori hai — taaki aap complexity ke peechhe **andhe na bhaago**.

---

## 🚃 ANALOGY — TRAIN ke DABBE
Cinema row (vector) me beech me baithna = **sab khiskao**. Train me = **2 kadi kholo, dabba lagao**.

```
NULL <- [10] <-> [20] <-> [30] -> NULL      (doubly linked)
```

### ⚠️⚠️ Ek BADI imaandaar baat
Kitaab: *"list me insert O(1), to list tez hai"* — **ASLIYAT: list aksar vector se DHEEMI hai!**
1. Us jagah tak **pahunchne** me O(n)
2. Har node **alag memory** → cache miss
3. Har int pe **2 pointer** (24 byte vs 4!)

---

## ⭐⭐ Memory

```
Har node : [ prev 8 | data 4 | next 8 ] + padding = ~24 byte PER INT ⚠️
1 lakh int : vector 0.38 MB  vs  list 2.29 MB  (6 GUNA!)
```
> 🚃 Dabbe jude hue hain (pointer se), par ek **lambi patri pe lagataar** khade hon — ye **guarantee nahi**.

---

## ⭐⭐⭐ insert O(1) — par SHART ke saath

```cpp
advance(it, 2);      // ⚠️ ye O(n) hai!
l.insert(it, 99);    // ⭐ ye O(1) hai
```
> ⭐⭐ **Iterator PEHLE SE hai → O(1)** · **Dhoondhna pada → KUL O(n)**
> ⚠️ Aur vector me bhi search O(n) + shift O(n) = O(n) — **dono O(n)**, par vector cache-friendly!

---

## ⭐⭐ list ke KHAAS function (vector me nahi)

```
remove(1)        -> saare 1 ude          (vector me erase-remove likhna padta)
unique()         -> sirf LAGATAAR duplicate ⚠️ (aakhri 1 bacha raha!)
sort() reverse() -> apne
merge(d2)        -> d2 KHAALI ho gayi ⭐ (data CHURA liya, koi copy nahi)
remove_if(pred)
```
> ⚠️ `unique` se pehle **`sort`** karo, warna saare duplicate nahi hatenge.

---

## ⭐⭐⭐ SPLICE — list ka asli hathiyaar

```
10 lakh element jodne me :
   list.splice()   :        543 ns   ⭐ (O(1)!)
   vector.insert() :  4,229,563 ns   ⚠️ (O(n) copy)
```

### **~7,800× farak** — kyunki **ek bhi element copy nahi hua**
> 🚃 5 dabbe kaat kar doosri train me jod diye — **dabbe uthane nahi pade, bas kadiyan badli** ⭐

---

## ⭐⭐ list ka apna sort kyun

```
sort(l.begin(), l.end());  -> ❌ error: no match for 'operator-'
l.sort();                  -> ✓
```
> `list::sort` = **MERGE SORT** — use random access chahiye hi nahi, aur wo sirf **pointer** badalta hai (koi copy nahi). O(n log n) guaranteed + **stable**.

---

## ⚠️ Jo list me HAI HI NAHI

`l[5]` · `l.at()` · `it+5` · `it1<it2` · `l.data()` · `sort(l.begin(),...)` · `capacity()` · `reserve()`

**Jo list me HAI, vector me nahi:** `push_front`/`pop_front` · **`splice`** ⭐⭐ · `remove`/`remove_if` · `unique`/`merge` · `sort`

---

## ⭐⭐⭐ 4 ASLI BENCHMARK

| # | Kaam | Natija |
|---|---|---|
| 1 | **Ghoomna** (30 lakh) | **vector ~5× TEZ** ⭐ (dono O(n)!) |
| 2 | **push_back** (10 lakh) | **vector tez** (list me har element pe `new`) |
| 3 | **Aage se daalna** | **⭐ LIST JEET GAYI** (O(n²) vs O(n)) |
| 4 | **Beech me insert** | vector **2180 µs** vs list **46139 µs** |

### ⚠️⚠️ #4 ka natija: **VECTOR 21× JEET GAYA** — jabki theory kehti hai list tez honi chahiye!

> ⭐⭐⭐ **Wajah:** list ka insert O(1) hai, **par wahan tak pahunchna O(n)** — aur wo walk **cache miss** se bhara hai. Vector ka shift bhi O(n) hai, par wo lagataar memory pe **`memmove`** hai, jo CPU **bahut tezi** se karta hai.

---

## ⭐⭐ forward_list

| | list | forward_list |
|---|---|---|
| Memory/int | ~24 B | **~16 B** ⭐ |
| `push_back` | ✓ | **❌ NAHI** ⚠️ |
| `size()` | ✓ O(1) | **❌ NAHI** ⚠️ |
| insert | `insert()` | **`insert_after()`** ⭐ |

> `insert_after` kyun? Singly list me **pichhle node tak pahunch hi nahi sakte**.

---

## ⭐⭐⭐ list SACH ME kab behtar

1. ⭐⭐⭐ **SPLICE chahiye** (O(1) me poora hissa)
2. ⭐⭐ **Iterator/pointer ZINDA rehne chahiye** — `list` me 100 insert ke baad bhi `*it = 20` ✓
3. ⭐ Object **bahut bada** + bahut shuffle

**Kahan MAT karo:** sirf ghoomna · index chahiye · memory bachani · *"insert O(1) hai"* ke bharose

---

## ⭐ DSA me — LRU CACHE

```
use(1),use(2),use(3) -> cache : 3=30 2=20 1=10
use(1) dobara        -> cache : 1=11 3=30 2=20   ⭐ (1 wapas FRONT pe)
use(4) (cap full)    -> NIKALA : 2=20            ⭐ (sabse purana)
```
> ⭐⭐⭐ Ye **sirf list se** ban sakta hai: (1) `erase`/`splice` O(1), (2) **iterator zinda rehta hai** (map me store kar sakte hain!)

---

## COMPLEXITY

| Operation | list | vector |
|---|---|---|
| `l[i]` | ❌ | O(1) ⭐ |
| push/pop **front** | **O(1)** ⭐⭐ | O(n) ⚠️ |
| insert (iterator hai) | **O(1)** ⭐⭐ | O(n) |
| insert (dhoondhna) | O(n) ⚠️ | O(n) |
| **splice** | **O(1)** ⭐⭐⭐ | ❌ |
| memory/int | ~24 B ⚠️ | **4 B** ⭐ |

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **TRAIN ke DABBE** — jodna aasan, par 50ve tak **paidal**
2. ⭐⭐⭐ **"insert O(1)" ADHOORA SACH** — iterator pehle se ho tabhi
3. ⭐⭐⭐ Naap kar dekha: beech me insert me bhi **vector 21× jeeta**
4. ⭐⭐⭐ Asli superpower = **SPLICE** (543 ns vs 42 lakh ns)
5. ⭐⭐ Dusri = **iterator zinda rehte hain**
6. ⭐⭐ Memory **6 guna** zyada ⚠️
7. ⭐⭐ `list::sort` = merge sort (isi liye `std::sort` chalta nahi)
8. ⭐⭐⭐ **`vector` se shuru karo** — splice ya "iterator zinda" chahiye tabhi list

---

**File:** `01_list_theory.cpp` (1,105 lines) · **0 warnings** · ASan+UBSan **clean**
