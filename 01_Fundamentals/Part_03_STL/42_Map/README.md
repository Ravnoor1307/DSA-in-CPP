# 42. Map 🔴🔴 EXTRA-DEEP — *Part_03 STL 13/17* · ⭐⭐ 40% hashing problems

> **Ek line me:** `map` DSA ka sabse kaam aane wala container hai — par uska **`[]` sabse bada dhokebaaz**. Dono baatein saath yaad rakho.

---

## 📱 ANALOGY — MOBILE ki PHONEBOOK
**NAAM (key)** → **NUMBER (value)**. Hamesha **alphabetical**.

> `set` = sirf KEY · `map` = KEY + VALUE · **Andar dono me wahi RED-BLACK TREE** ⭐

```
Rahul, Amit, Priya, Zoya is kram me daale
-> nikle : Amit, Priya, Rahul, Zoya    ⭐ ALPHABETICAL
```

---

## ⭐⭐ Har element = `pair<const Key, Value>`

```
it->first  = KEY      it->second = VALUE

it->first = "z";   -> ❌ error: assignment of read-only member
```
> ⭐ **KEY `const` hai** — badal di to **tree ka kram toot jayega**. VALUE badal sakte ho ✓
> Isi liye `for (auto& [k, v] : m)` me `k` const, `v` nahi.

---

## ⭐⭐⭐ Daalne ke 5 tareeke

```cpp
m["a"] = 1;                    // sabse aasan
m.insert({"b", 2});            // purana NA badle ⭐
m.emplace("d", 4);             // jagah pe banata hai
m.insert_or_assign("e", 5);    // C++17, naam se saaf ⭐
```

### ⚠️ `[]` vs `insert` — BADA farak
```
t["x"]=10; t["x"]=20;              -> x = 20  ⭐ BADAL gaya
u.insert({x,10}); u.insert({x,20}) -> x = 10  ⚠️ NAHI badla!
```
> ⭐ `emplace` seedha map ke andar banata hai (ek copy bachi) · C++17 `try_emplace` value **banata hi nahi** agar key ho

---

## ⚠️⚠️⚠️ `m[key]` ka JAAL — 3 ROOP

**ROOP 1 — sirf PADHNE pe bhi entry ban jati hai**
```
m["Rahul"] = 90;     -> size = 1
int x = m["Priya"];  -> x = 0 , size = 2   ⚠️⚠️ ENTRY BAN GAYI!
```
> `operator[]` ka vaada: *"main tumhe REFERENCE dunga jispe likh sako"* — key nahi hai? **default value se bana deta hai**
> ✓ `m.count(k)` · `m.find(k)` · C++20 `m.contains(k)`

**ROOP 2 — `const map` pe `[]` chalta hi NAHI**
```
error: passing 'const std::map<...>' as 'this' argument discards qualifiers
```
> ✓ `m.at(k)` — const pe chalta hai, aur na mile to **exception**

**ROOP 3 — loop me galti se**
```
for (q : {5,6,7}) if (freq[q] > 0) ...   -> 3 BEKAAR entry ban gayi ⚠️
✓ if (freq.count(q) && freq[q] > 0)
```
> ⭐ **NIYAM: LIKHNE ko `[]`, PADHNE ko `count`/`find`**

---

## ⭐⭐⭐ FREQUENCY COUNTING — map ka #1 istemaal

```
"mississippi" -> i:4  m:1  p:2  s:4      ⭐ (aur SORTED output!)
Sabse zyada : 'i' (4 baar)      Pehla unique : m
```
> ⭐ `freq[c]++` chalta hai kyunki nayi key pe value **default 0** se banti hai

```
word freq : {cat:2, dog:1, the:3}
Frequency ke kram me : the(3) cat(2) dog(1)
```
> ⚠️ **Map ko VALUE se sort nahi kar sakte** (wo KEY se sorted hai) → `vector<pair>` me daal kar sort ⭐

---

## ⭐⭐ lower_bound / upper_bound

```
Events : 100=login, 250=click, 400=logout      time = 300
   agla event    : 400 (logout) ⭐
   pichhla event : 250 (click)  ⭐
```
> ⭐ *"Is time se just pehle/baad kya hua?"* — `unordered_map` me **namumkin**
> ⚠️ Wahi niyam: **MEMBER** `m.lower_bound()`, `std::` wala **O(n)** *(topic 40)*

---

## ⭐⭐ Iterate + erase

```cpp
for (const auto& [k, v] : m) ...      // ⭐⭐ sabse saaf (C++17)
for (auto& [k, v] : m) v *= 10;       // ⭐ value badalna
for (auto it = m.rbegin(); ...)       // ULTA

// loop me erase
for (auto it = m.begin(); it != m.end(); ) {
    if (...) it = m.erase(it);        // ⭐ naya iterator
    else ++it;
}
```
> ⚠️ `for (auto [k,v] : m)` bina `&` — har element ki **COPY** (string key me mehnga!)

---

## ⭐⭐⭐ Custom comparator + custom key

```cpp
map<string, int, greater<string>> m;        // ulta kram
map<Point, string> m;                       // struct key -- sirf operator< chahiye
map<pair<int,int>, int> pm;                 // ⭐ seedha chalta hai!
```
> ⚠️ `unordered_map<pair<int,int>, int>` **compile nahi hoga** (hash nahi hai — topic 41)
> ⚠️ `operator<` me **tie-breaker zaroori** — warna (1,2) aur (1,1) barabar mane jayenge

---

## ⭐⭐ MULTIMAP

```
Rahul -> 9876        Rahul -> 1234        Priya -> 5555
mm.count("Rahul") = 2 ⭐
```
> ⚠️⚠️ **`[]` HAI HI NAHI** — ek key ke kai value, `[]` kaunsi lautata?
> ✓ `equal_range("Rahul")` · `mm.erase("Rahul")` **SAARE** hatata hai

---

## ⭐⭐⭐ map vs unordered_map

5 lakh frequency count: **unordered_map ~7× tez**

| | map | unordered_map |
|---|---|---|
| find/insert | O(log n) | **O(1) avg** ⭐ |
| **WORST** | **O(log n)** ⭐ | O(n) ⚠️ |
| Kram | **SORTED** ⭐ | koi nahi |
| `lower_bound` | ✓ ⭐ | ❌ |
| Custom key | **sirf `<`** ⭐ | hash + `==` |

---

## ⭐⭐⭐ DSA me 6 CLASSIC

1. **FREQUENCY** — sabse zyada
2. **TWO SUM** (index ke saath) → `index (0,1)` ✓
3. **GROUP ANAGRAMS** — `sort(key)` → `[aet]: eat tea ate` ⭐ *(yahan `[]` ka "entry banana" faydemand hai!)*
4. **Sorted order** — `begin()` sabse chhoti key, `rbegin()` sabse badi
5. **Graph with named nodes** — `map<string, vector<string>>`
6. **PREFIX SUM + map** — subarray sum = k → **8** ✓
   > ⚠️ **`cnt[0] = 1` bhoolna** sabse common galti!

---

## ⚠️ 5 aur JAAL

1. **`[]` ki default value** — `int`→0, `string`→"", `vector`→khaali *(value ka default constructor chalta hai)*
2. Key badalna namumkin
3. `std::lower_bound` (O(n))
4. **Value se dhoondhna O(n)** → dono taraf chahiye to **DO map** rakho
5. Map ki **copy mehngi** (O(n)) → `const map&`

---

## COMPLEXITY

| Operation | map | unordered_map |
|---|---|---|
| `m[k]` / find / erase | **O(log n)** ⭐ | O(1) avg |
| **lower_bound** | **O(log n)** ⭐⭐ | ❌ |
| `begin()` | O(1) ⭐ | ❌ |
| memory/entry | ~48+ B | ~40+ B |

```
DERIVATION (m[k]++) : dhoondho O(log n) + insert O(log n) + ++ O(1) = O(log n)
   n baar -> O(n log n).  unordered_map me O(n) ⭐
```

---

## ❌ 10 GALTIYAN

1. ⚠️⚠️⚠️ `if (m[k] > 0)` — **entry ban jati hai!**
2. ⚠️⚠️ `const map` pe `[]`
3. ⚠️⚠️ `insert` ko value badalne wala samajhna
4. ⚠️⚠️ KEY badalna
5. ⚠️ `std::lower_bound`
6. ⚠️ map ko **value se sort** karne ki koshish
7. ⚠️ prefix-sum me **`cnt[0] = 1`** bhoolna
8. ⚠️ loop me `m.erase(it); ++it;`
9. ⚠️ map by value bhejna
10. ⚠️ `multimap` pe `[]`

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **PHONEBOOK** 📱 — key→value, KEY se sorted
2. ⭐⭐⭐ Har element **`pair<const Key, Value>`**
3. ⚠️⚠️⚠️ **`m[k]` sirf padhne pe bhi entry banata hai** (size 1→2 dekha!)
4. ⭐⭐ `insert` purani value **nahi** badalta
5. ⭐⭐⭐ **`freq[x]++`** — CP ki 40% problem
6. ⭐⭐ **`lower_bound`** map ki khaas taakat
7. ⭐⭐ Custom key: **sirf `operator<`** (hash nahi) → `map<pair<...>>` seedha
8. ⭐⭐⭐ Kram → map · lookup → unordered_map · **chhoti int key → vector**

---

**File:** `01_map_theory.cpp` (1,123 lines) · **0 warnings** · ASan+UBSan **clean**
