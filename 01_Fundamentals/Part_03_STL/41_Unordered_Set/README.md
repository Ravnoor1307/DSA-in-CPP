# 41. Unordered Set 🔴 EXTRA-DEEP — *Part_03 STL 12/17*

> **Ek line me:** Hash table ka **O(1) ek VAADA hai, GUARANTEE nahi.** Wo tab tak sach hai jab tak aapka hash achha hai — isi liye samajhdaar programmer **custom hash** likhta hai.

---

## 🗄️ ANALOGY — SCHOOL ke LOCKER
*"Locker number = roll % 500"* — roll 1247 → locker 247. **Ek hisaab, seedha pahunch gaye** — O(1) ⭐

> ⚠️ Par 1247 % 500 = 247 **aur** 747 % 500 = 247 → **COLLISION!**

---

## ⭐⭐⭐ Andar — BUCKET + CHAIN

```
bucket 0 : -> [ ]
bucket 1 : -> [ 8 ] -> [ 15 ]      <- COLLISION (chaining)
bucket 2 : -> [ 23 ]
```
1. `hash(x)` → bada number  2. `% bucket_count` → bucket  3. chain me dhoondho

```
hash<int>{}(42) = 42        ⭐ GCC me hash<int> IDENTITY hai!
```
> ⭐ Ye tez hai, **par isi wajah se ATTACK aasan hai** ⚠️

---

## ⭐⭐ LOAD FACTOR + REHASHING

```
Element   bucket_count   load_factor
      1        13            0.08   ⚠️ REHASH
     14        29            0.48   ⚠️ REHASH
     30        59            0.51   ⚠️ REHASH
     60       127            0.47   ⚠️ REHASH
    128       257            0.50   ⚠️ REHASH
```
> **REHASH O(n)** — saare element ka hash **dobara**. Aur **SAARE ITERATOR mar jate hain** ⚠️
> *(`set` me aisa nahi hota!)* — par **reference/pointer zinda rehte hain** (ajeeb par sach)

**`reserve(n)`** se saari rehashing bach jati hai ⭐

---

## ⭐⭐⭐ set vs unordered_set

5 lakh element: **unordered_set ~20× tez**

| | set | unordered_set |
|---|---|---|
| Andar | red-black tree | **hash table** |
| find (avg) | O(log n) | **O(1)** ⭐ |
| find (**WORST**) | **O(log n)** ⭐ | **O(n)** ⚠️ |
| Kram | **SORTED** ⭐ | koi nahi |
| `lower_bound` | ✓ ⭐ | **❌** |
| Iterator invalidation | sirf mita hua ⭐ | **rehash pe SAB** ⚠️ |
| Custom type | sirf `<` | **hash + `==`** |

---

## ⚠️⚠️⚠️ ANTI-HASH ATTACK — maine khud kar ke dikhaya

GCC me `hash<int>` identity hai, bucket count prime hota hai. **Saare element us prime ke multiple daal do:**

| | Time | **Sabse lambi chain** |
|---|---|---|
| NORMAL (1,2,3...) | **164 µs** | **1** |
| **ATTACK** | **44,966 µs** | **5000** ⚠️⚠️ |
| **SafeHash** | **195 µs** | **2** ⭐⭐ |

### **274× dheema — O(1) sach me O(n) ban gaya!**

```cpp
struct SafeHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED);        // ⭐ har RUN me alag salt!
    }
};
```
> ⭐ Attacker ko pata hi nahi ki **is run me salt kya hai** → attack bekaar
> ⚠️ Codeforces pe log **isi tareeke se hack** karte hain — custom hash **aadat** bana lo

---

## ⚠️⚠️ 5 JAAL

1. **Koi kram nahi** — aur wo har run/compiler pe badal sakta hai
2. **Rehash pe iterator marte hain** — loop me insert = UB ⚠️
3. **Worst case O(n)** (upar)
4. **Custom type seedha nahi** — `unordered_set<pair<int,int>>` → `error: hash function must be invocable`
   *(`set<pair<int,int>>` chal jata hai — `<` hai, hash nahi!)*
5. **Chhote data me `set` behtar** (hash ka setup kharcha)

---

## ⭐⭐⭐ Custom type ka HASH

```cpp
struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        size_t h1 = hash<int>{}(p.first), h2 = hash<int>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));   // ⭐ boost wala
    }
};
```
> ⚠️ **Seedha `h1 ^ h2` MAT karo** — `{1,2}` aur `{2,1}` ka hash **same** ho jayega (XOR symmetric!)
> ⭐ **CP jugaad:** `long long key = (long long)x * 1000000 + y;` → custom hash ki zarurat hi nahi

---

## ⭐⭐ DSA me 5 CLASSIC

1. **Duplicate dhoondho** O(n) — `if (!dekha.insert(x).second)`
2. **TWO SUM** O(n) — brute force O(n²) tha
3. **Longest Consecutive Sequence** O(n) — ⭐ *chalaki:* sirf us `x` se shuru karo **jiska `x-1` nahi hai** → `{100,4,200,1,3,2}` = **4**
4. Graph **visited** (jab node number bada ho)
5. Cycle detection — `unordered_set<Node*>`

---

## COMPLEXITY

| Operation | Average | Worst |
|---|---|---|
| insert/erase/find | **O(1)** ⭐ | **O(n)** ⚠️ |
| rehash | — | O(n) ⚠️ |
| ghoomna | **O(n + b)** | b = bucket count |
| memory/int | ~32-40 B | |

> ⚠️ **O(n+b)**: agar 10 lakh reserve kiya aur 10 element daale, to ghoomna **10 lakh kadam** lega!

---

## ❌ 10 GALTIYAN

1. ⚠️⚠️⚠️ CP me **bina custom hash** ke
2. ⚠️⚠️ ghoomne ke **kram pe bharosa**
3. ⚠️⚠️ loop me insert + iterator (rehash!)
4. ⚠️ `lower_bound` dhoondhna
5. ⚠️ `operator==` bhoolna
6. ⚠️ `h1 ^ h2` (symmetric!)
7. ⚠️ `reserve` na karna
8. ⚠️ chhote data me bhi unordered
9. ⚠️ bada reserve + kam element (ghoomna dheema)
10. ⚠️ **worst case O(n) bhool jana**

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **LOCKER** 🗄️ — hash se seedha jagah
2. ⭐⭐⭐ **BUCKET + CHAIN** (live naksha dekha)
3. ⭐⭐ **Collision hoti hi hai** — load factor pe nazar
4. ⭐⭐ **Rehash O(n)** + iterator marte hain → `reserve`
5. ⭐⭐⭐ **Worst case SACH ME hota hai** — khud attack kar ke dikhaya (chain 5000!)
6. ⭐⭐⭐ Bachav = **random salt wala custom hash**
7. ⭐⭐ Custom type: **hash + `==`** (set ko sirf `<`)
8. ⭐⭐⭐ Kram/lower_bound → `set` · lookup → `unordered_set` · **chhoti int key → `vector<bool>`**

---

**File:** `01_unordered_set_theory.cpp` (1,134 lines) · **0 warnings** · ASan+UBSan **clean**
