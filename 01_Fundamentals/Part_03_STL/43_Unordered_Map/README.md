# 43. Unordered Map 🔴🔴 EXTRA-DEEP — *Part_03 STL 14/17* · ⭐⭐ CP ka #2 container

> **Ek line me:** CP ka sabse kaam aane wala hathiyaar — par uske **3 kaante** hain: `[]` ka jaal, anti-hash attack, aur ye bhool jana ki **chhoti int key pe `vector` behtar hai**.

---

## 🆔 ANALOGY — AADHAAR DATABASE
Aadhaar number daalo → poori jankari **turant**. Hash se seedha record tak.

> `unordered_map` = `unordered_set` + VALUE. **Wahi hash table, wahi bucket, wahi collision** — bas ab bucket me `pair<const K, V>` ⭐

```
Rahul, Amit, Priya, Zoya -> koi ALPHABETICAL kram NAHI ⚠️
```
> Interface `map` jaisa **bilkul same** — sirf 2 farak: **kram nahi** aur **`lower_bound` nahi**

---

## ⭐⭐ Bucket ka naksha

```
bucket_count = 13 , load_factor = 0.62
Bucket   kitne   kaun-kaun
     2      1     15=v3
     5      2     5=v1  18=v4      <- COLLISION
um.bucket(20) = 7          ⭐ key kis bucket me hai
```

---

## ⭐⭐⭐ map vs unordered_map — 4 tarah se

10 lakh element ka frequency count:

| Container | relative |
|---|---|
| map | baseline |
| unordered_map | tez |
| **unordered_map + reserve** | **sabse tez** ⭐ |

**Memory:** map ~48+ B · unordered_map ~40+ B
**Kram:** map SORTED ⭐ · unordered koi nahi
**Worst:** map **O(log n)** ⭐ · unordered **O(n)** ⚠️

---

## ⚠️⚠️ `m[key]` ka JAAL — yahan bhi

```
m["a"] = 1;          -> size = 1
int x = m["zzz"];    -> x = 0 , size = 2   ⚠️⚠️ ENTRY BAN GAYI!
```

### ⭐⭐ 4 sahi tareeke — aur `find` sabse achha
```cpp
if (m.count(k)) use(m[k]);                            // ⚠️ DO lookup
auto it = m.find(k); if (it != m.end()) use(it->second);  // ⭐ EK lookup
```
**Naap kar:** 5 lakh lookup — `count + []` **3029 µs** vs `find` **1756 µs** ⭐

---

## ⭐⭐ reserve + max_load_factor

```
1 lakh insert bina reserve      -> 14 baar REHASH ⚠️
1 lakh insert reserve ke saath  ->  0 baar REHASH ⭐

max_load_factor(0.25) -> zyada bucket, chhoti chain ⭐
max_load_factor(4.0)  -> kam memory, lambi chain ⚠️
```

### ⭐⭐⭐ CP ka GOLDEN COMBO
```cpp
unordered_map<long long, int, SafeHash> m;
m.reserve(1 << 20);
m.max_load_factor(0.25);
```

---

## ⭐⭐⭐ Custom key

```cpp
unordered_map<pair<int,int>, string, PairHash> grid;   // hash + == chahiye
```
> ⚠️ Bina hash: `error: static assertion failed: hash function must be invocable`
> ⭐ `string` ka hash ready-made hai — par **O(len)** hai ⚠️
> ⭐⭐ **CP jugaad:** `long long key = (long long)x * 1000000LL + y;` → custom hash ki zarurat hi nahi!

---

## ⭐⭐ MEMOIZATION

```
fib(40) :  bina memo ~33 crore call  ->  memo se sirf 79 call ⭐
```

```cpp
auto it = memo.find(n);
if (it != memo.end()) return it->second;    // ⭐ ek lookup
```

> ⚠️⚠️ **`if (memo[n]) return memo[n];` GALAT hai** — do wajah:
> 1. har baar **entry ban jati** hai
> 2. **agar asli jawab 0 ho, to wo kaam hi nahi karega!** ⭐

---

## ⚠️⚠️⚠️ ANTI-HASH ATTACK (map pe bhi)

| | Time | Chain |
|---|---|---|
| NORMAL | **104 µs** | 1 |
| **ATTACK** | **42,946 µs** | **5000** ⚠️⚠️ |
| **SafeHash** | **112 µs** | **3** ⭐⭐ |

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
        return splitmix64(x + FIXED);
    }
};
```
> ⭐ `FIXED` **har run me alag** → attacker pehle se anti-test bana hi nahi sakta

---

## ⭐⭐⭐ DSA me 6 CLASSIC

**Frequency** ⭐⭐⭐ · **Two Sum O(n)** · **Subarray sum = k** *(prefix sum, `cnt[0]=1`!)* · **Group by key** *(`g[k].push_back(v)` — yahan `[]` faydemand)* · Graph with names · **Memoization**

---

## ⭐ unordered_multimap
Ek key ke kai value · **`[]` hai hi nahi** · `equal_range` use karo

---

## ⚠️⚠️ Kab `vector` HI behtar hai

10 lakh element, key **0..999**:

| | Time |
|---|---|
| unordered_map | **3664 µs** |
| **vector<int>** | **601 µs** ⭐⭐ |

### **vector 6× TEZ**
> `vf[x]++` me koi hash nahi, koi bucket nahi — **seedha `base + x*4`**, aur memory **lagataar**
> ⭐ **Key chhoti int hai? → `vector`.** Key bikhri (1, 10⁹, −5) → tab hash map ⭐

---

## COMPLEXITY

| Operation | Average | Worst |
|---|---|---|
| `m[k]` / find / insert | **O(1)** ⭐ | **O(n)** ⚠️ |
| rehash | — | O(n) |
| ghoomna | O(n + b) | |
| `lower_bound` | **❌** | |

---

## ❌ 10 GALTIYAN

1. ⚠️⚠️⚠️ CP me **bina SafeHash**
2. ⚠️⚠️ `if (m[k])` se check
3. ⚠️⚠️ memo me **`if (memo[n])`** — value 0 pe toot-ta hai!
4. ⚠️ `count` + `[]` (2 lookup)
5. ⚠️ kram pe bharosa
6. ⚠️ `reserve` na karna
7. ⚠️ **chhoti int key pe bhi map**
8. ⚠️ `operator==` bhoolna
9. ⚠️ loop me insert + iterator
10. ⚠️ `lower_bound` dhoondhna

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **AADHAAR DATABASE** 🆔 — hash se seedha, average O(1)
2. ⭐⭐ Wahi hash table (topic 41), bas `pair<const K,V>`
3. ⚠️⚠️ **`m[key]` ka jaal** — aur `find` se **1 lookup** (naapa)
4. ⚠️⚠️⚠️ **memo me `if (memo[n])` GALAT** — jawab 0 ho to fail
5. ⭐⭐ `reserve` + `max_load_factor` = rehashing khatam
6. ⭐⭐⭐ **ANTI-HASH ATTACK** — CP me **SafeHash hamesha**
7. ⭐⭐ Custom key: hash + `==`, ya **encode kar ke `long long`**
8. ⭐⭐⭐ **Chhoti int key → `vector`** (6× tez — naapa!)

---

**File:** `01_unordered_map_theory.cpp` (1,109 lines) · **0 warnings** · ASan+UBSan **clean**
