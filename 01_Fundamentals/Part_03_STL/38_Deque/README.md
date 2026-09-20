# 38. Deque 🔴 EXTRA-DEEP — *Part_03 STL 9/17*

> **Ek line me:** `deque` wo container hai jiska naam **kam sunte** hain, par jo sabse zyada **chupke se** use hota hai — `stack` aur `queue` **dono andar se yahi hain**.

---

## 🚇 ANALOGY — METRO ka DABBA (dono taraf darwaze)

Purani bus (queue): aage se chadho, peechhe se utro. **Metro**: jahan se chaho.

```
push_front / pop_front  -> O(1) ⭐
push_back  / pop_back   -> O(1) ⭐
dq[i]                   -> O(1) ⭐⭐  (vector wala faayda BHI!)
```

> **deque = vector + list ka BEST of BOTH** — `[]` bhi, dono chhor bhi.

| Feature | vector | list | deque |
|---|---|---|---|
| `dq[i]` | ✓ | ❌ | **✓** ⭐ |
| `push_front` O(1) | ❌ | ✓ | **✓** ⭐ |
| lagataar memory | ✓ | ❌ | ❌ ⚠️ |
| `.data()` | ✓ | ❌ | **❌** ⚠️ |

---

## ⭐⭐⭐ ANDAR se — TUKDE (chunks)

```
MAP (pointer ka array) :
   [ptr] [ptr] [ptr] [ptr]
     |     |     |     |
  [....][....][....][....]   <- har CHUNK 512 byte
```

### Live saboot — 2000 element ke pate
```
index  128 pe TOOT : faasla   20 byte  ⚠️ (naya chunk!)
index  256 pe TOOT : faasla   68 byte  ⚠️
index  384 pe TOOT : faasla   20 byte  ⚠️
Kul 15 baar memory TOOTI  ->  har chunk me ~125 element
```

> ⭐⭐⭐ **THEEK 128 pe tooti** — GCC ka chunk = **512 byte = 128 int** ✓
> - `push_front`: pehle chunk me jagah? daal do. Warna **naya chunk** map ke aage — **purana data hilta hi nahi** → O(1) ⭐
> - `dq[i]`: pehle chunk nikalo, phir offset → **DO memory access** (vector me ek) ⚠️

---

## ⚠️ Memory ka sach

```
sizeof(deque<int>) = 80 byte (header)
⚠️⚠️ KHAALI deque bhi ek CHUNK (512 byte) turant le leti hai!
```
> ⚠️ `vector<deque<int>> adj(1000000)` → **~500 MB** kha jayegi!
> ⭐ Bahut si **chhoti** container chahiye → `vector<vector<int>>`

---

## ⭐⭐⭐ push_front — deque vs vector

**2 lakh baar aage se daalna:**

| | Time (µs) |
|---|---|
| `deque.push_front()` O(1) | **560** ⭐ |
| `vector.insert(begin)` O(n) | **1,740,918** ⚠️ |

### **deque 3105× TEZ** ⭐⭐

```
vector : 1+2+...+n = n(n+1)/2 = 20000100000 element khiske -> O(n²) ⚠️
deque  : har baar bas ek jagah -> O(n) KUL ⭐
```
> ⭐⭐⭐ **Yahi deque ki sabse badi jeet.** Dono chhor ka kaam ho → **deque** (vector nahi!)

---

## ⭐⭐ `dq[i]` kitna dheema?

2 crore element padhne me deque vector se **thoda** dheema — **dono O(1)**, par deque me **2 kadam** (map → chunk), vector me **1** (`base + i*4`).

> ⭐ Sirf index chahiye → **vector**. Dono chhor bhi → **deque**.

---

## ⚠️⚠️ 4 CHHUPE KHATRE

1. **`.data()` hai hi nahi** → `error: 'class std::deque<int>' has no member named 'data'` (memory lagataar nahi!)
2. **Ajeeb invalidation niyam:**
   ```
   d[2] ka reference liya, phir push_back + push_front
   ref = 3  ⭐ REFERENCE abhi bhi ZINDA!
   ⚠️ PAR ITERATOR toot jate hain -- ye farak yaad rakho
   ```
3. **Khaali deque ~512 byte** ⚠️
4. `shrink_to_fit` kaam karta hai, par **request** hai (guarantee nahi)

---

## ⭐⭐⭐ CLASSIC — SLIDING WINDOW MAXIMUM

```
Array : 1  3  -1  -3  5  3  6  7      k = 3
deque se (O(n))      : 3 3 5 5 6 7
brute force (O(n*k)) : 3 3 5 5 6 7     Dono same ✓⭐
```

**Do niyam:**
```cpp
while (!dq.empty() && dq.front() <= i-k)  dq.pop_front();   // window se bahar
while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();  // mujhse chhote bekaar
dq.push_back(i);
```
> ⭐ Deque me index **ghatte kram** me → `dq.front()` **hamesha maximum** ⭐
> **MONOTONIC DEQUE** — har index 1 baar ghusta, 1 baar nikalta → **O(n)**

> ⭐⭐⭐ **Yahan deque kyun, stack/queue kyun nahi?** Dono taraf se hatana padta hai: **aage se** purane index, **peechhe se** chhote element. Sirf deque dono O(1) me karta hai.

---

## ⭐⭐ CLASSIC — 0-1 BFS

```cpp
weight 0 -> dq.push_front(v)   ⭐ (distance badhta hi nahi -> pehle process)
weight 1 -> dq.push_back(v)
```
```
Graph : 0->1(w0), 0->2(w1), 1->3(w1), 2->3(w0)
Distance : 0:0  1:0  2:1  3:1        ⭐ 0 se 3 tak = 1 ✓
```
> **O(V+E)** — Dijkstra ke **O(E log V)** se tez! Ye trick **sirf deque** se mumkin hai.

---

## ⭐⭐ Palindrome + undo-redo

```
"madam" ✓  "level" ✓  "hello" ✗  "a" ✓  "" ✓      (dono chhor se milao)

undo history (LIMIT 3), 4 kaam kiye :
   [type B] [type C] [type D]      ⭐ "type A" apne aap nikla
```

---

## ⭐⭐⭐ deque vs vector vs list

| Kaam | vector | deque | list |
|---|---|---|---|
| `dq[i]` | O(1) ⭐⭐ | O(1) ⭐ | ❌ |
| push_front | O(n) ⚠️ | **O(1)** ⭐⭐ | O(1) ⭐⭐ |
| ghoomna (cache) | **sabse tez** ⭐ | thoda kam | sabse dheema ⚠️ |
| memory/int | 4 B ⭐ | ~4 B | 24 B ⚠️ |
| khaali container | **0 B** ⭐ | ~512 B ⚠️ | 0 B |
| `.data()` | ✓ ⭐ | ❌ | ❌ |
| **realloc pe copy** | **HAAN** ⚠️ | **NAHI** ⭐ | NAHI ⭐ |

### ⭐⭐ Live saboot — deque realloc pe copy nahi karti
```
5000 push_back ke baad :
   deque  me d[0] ka pata BADLA? NAHI ⭐ (wahi hai!)
   vector me v[0] ka pata BADLA? HAAN ⚠️
```
> ⭐ Isi liye **bade object** ki list me deque behtar — realloc pe saare object copy/move nahi hote.

---

## ⭐ DSA me

**Sliding Window Max** ⭐⭐⭐ · **0-1 BFS** ⭐⭐ · `stack` ka default · `queue` ka default · undo-redo · palindrome · taash ke patte

> ⭐⭐ Aap deque **pehle se** use kar rahe the — `stack<int>` aur `queue<int>` **dono andar se deque hain** *(topic 36/37 me sizeof se saabit kiya)*

---

## COMPLEXITY

| Operation | Time |
|---|---|
| `dq[i]` | O(1) ⭐ (par 2 access) |
| push/pop **dono chhor** | **O(1)** ⭐⭐ |
| insert/erase (beech) | O(n) ⚠️ |
| Sliding window max | **O(n)** ⭐ (brute O(n·k)) |
| 0-1 BFS | **O(V+E)** ⭐ |

```
push_front O(1) : pehle chunk me jagah -> daal do
                  nahi -> NAYA chunk, map me pointer jodo
                  purana data HILTA NAHI ⭐
```

---

## ❌ 10 GALTIYAN

1. ⚠️⚠️ `d.data()` (hai hi nahi)
2. ⚠️⚠️ bahut si **chhoti deque** (~512 B each!)
3. ⚠️ deque ko "lagataar memory" samajhna
4. ⚠️ `memcpy(dest, &d[0], n)` (tukde hain!)
5. ⚠️ sliding window me **value** rakhna (**index** chahiye)
6. ⚠️ window-bahar wale index hatana bhoolna
7. ⚠️ iterator/reference invalidation mila dena
8. ⚠️ sirf index ke liye deque (vector tez)
9. ⚠️ 0-1 BFS me weight 0 ko `push_back`
10. ⚠️ na jaanna ki stack/queue andar se deque hain

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **METRO ka DABBA** — `[]` bhi, push_front bhi
2. ⭐⭐⭐ Andar **TUKDE** — pate dekh kar confirm (theek 128 pe toota)
3. ⭐⭐⭐ push_front me **3105× jeet** (O(n) vs O(n²))
4. ⭐⭐ `dq[i]` me **2 memory access** — sirf index ho to vector
5. ⭐⭐ Khaali deque **~512 byte** ⚠️
6. ⭐⭐⭐ **Sliding Window Max** — yahan deque ke alawa kuch kaam nahi karta
7. ⭐⭐ **Realloc pe copy nahi** → reference zinda rehte hain
8. ⭐⭐⭐ `stack` + `queue` **dono andar se deque** — roz use kar rahe the!

---

**File:** `01_deque_theory.cpp` (1,016 lines) · **0 warnings** · ASan+UBSan **clean**
