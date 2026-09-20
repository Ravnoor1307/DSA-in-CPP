# 39. Priority Queue 🔴🔴 EXTRA-DEEP — *Part_03 STL 10/17* · ⭐⭐ Dijkstra/Greedy ki neev

> **Ek line me:** Heap ek **chalak jugaad** hai — poora sort karne ki zarurat hi nahi, bas *"sabse bada upar"* ka niyam rakho. Isi ek samjhaute se **O(n log n) ka kaam O(log n)** me ho jata hai.

---

## 🏥 ANALOGY — HOSPITAL ka EMERGENCY

Normal OPD me **line** (queue). Emergency me? Heart attack wala **abhi aaya → sabse pehle**; bukhaar wala 2 ghante se baitha → ruko.

| | Kaun pehle |
|---|---|
| 🚌 QUEUE | jo **pehle aaya** (FIFO) |
| 🍽️ STACK | jo **baad me aaya** (LIFO) |
| 🏥 **PRIORITY QUEUE** | jo **sabse zaruri** hai ⭐ |

```
push 30,10,50,20,40  ->  nikla : 50 40 30 20 10   ⭐ khud kram laga diya
```
> ⚠️ Par ye **poora sorted NAHI** rakhta — sirf `top()` ki guarantee.

---

## ⭐⭐⭐ HEAP — vector me chhupa hua PED

```
parent(i) = (i-1)/2        left(i) = 2i+1        right(i) = 2i+2
```
> Pointer ki **zarurat hi nahi** — rishta **hisaab se** nikal aata hai *(topic 11 ka `i*C+j`)*

```
vector : [50, 40, 30, 10, 20, 15, 25]

              50            <- index 0
           /      \
         40        30       <- 1, 2
        /  \      /  \
      10    20  15    25    <- 3,4,5,6

index 5 (15) ka parent = (5-1)/2 = 2 -> 30 ✓
```

> ⭐⭐⭐ **Niyam:** har **parent apne child se bada** (max-heap me). Bas itna hi!
> ⚠️⚠️ **Ye SORTED NAHI hai** — 10, 20, 15, 25 me koi kram nahi. Sirf **upar-neeche** ka rishta pakka, **baayein-daayein** ka nahi.
> ⭐ Isi **"kam niyam"** ki wajah se heap tez hai.

---

## ⭐⭐⭐ push — SIFT UP

```
push(45) :
  1. END me daala : [50, 40, 30, 10, 20, 45]   index 5, parent 2 -> 30
  2. 45 > 30 ? HAAN -> SWAP : [50, 40, 45, 10, 20, 30]   ab parent 0 -> 50
  3. 45 > 50 ? NAHI -> RUK ⭐
```
> **Sirf 2 kadam** — kyunki ped ki unchai **log(n)** hai. 10 lakh element = **~20 kadam** ⭐

---

## ⭐⭐⭐ pop — SIFT DOWN

```
pop() :
  1. ⚠️ 50 seedha nikalein? PED me GADHA ho jayega!
  2. ⭐ AAKHRI element upar lao : [30, 40, 45, 10, 20]
  3. 30 ke child 40, 45 -> bada 45 -> SWAP : [45, 40, 30, 10, 20]
  4. RUK ⭐
```
> ⭐⭐ Saara maal nikaalo → **sorted** aata hai. **Yahi HEAP SORT hai** — n × O(log n) = **O(n log n)**, space **O(1)**.

---

## ⭐⭐ MIN-heap ke 3 tareeke

```cpp
priority_queue<int, vector<int>, greater<int>> pq;   // ⭐ teeno argument zaroori!
pq.push(-x);  ... -pq.top()                          // ⭐ CP jugaad (⚠️ INT_MIN pe toot-ta hai)
auto cmp = [](int a,int b){ return a>b; };  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```

### ⚠️⚠️ Comparator ka ULTA logic
```
less<int>    (default) -> MAX heap ⭐
greater<int>           -> MIN heap ⭐
```
> ⭐ **Samajhne ka tareeka:** comparator batata hai *"kaun PEECHHE jayega"*. `less` = "chhota peechhe" → bada upar → MAX.
> **Yaani `sort` se ULTA kaam karta hai.**

---

## ⭐⭐⭐ pair + custom comparator

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
pq.push({cost, node});     // ⭐ cost PEHLE!
```
> ⚠️⚠️ **Dijkstra me `{cost, node}`, `{node, cost}` NAHI** — warna node se compare hone lagega! *(topic 33 ka lexicographic)*

```cpp
struct TaskCompare {
    bool operator()(const Task& a, const Task& b) const { return a.priority < b.priority; }
};
```
```
[10] server down!     <- sabse baad me aaya, par PEHLE nikla ⭐
[ 5] meeting
[ 2] email likho
[ 1] chai peeyo
```

---

## ⚠️⚠️ 5 JAAL

1. **Default MAX hai**, min nahi
2. **Comparator ka logic ULTA** (`less` → max)
3. **`top()` ke alawa kuch nahi dikhta** — `pq[1]` ❌, `for(x:pq)` ❌ → copy bana kar khali karo
4. ⚠️⚠️ **Element badalna namumkin** — Dijkstra me "decrease key" hai hi nahi!
   ⭐ **Jugaad:** naya daal do, nikalte waqt `if (d > dist[u]) continue;` — **lazy deletion**
5. Khaali pe `top()` = UB

---

## ⭐⭐⭐ KHUD ka heap — STL se milaya

```cpp
void push(int x) { h.push_back(x); siftUp(h.size()-1); }
void pop() { h[0] = h.back(); h.pop_back(); siftDown(0); }
int top() const { return h[0]; }
```
```
Input     : 23 7 91 4 56 12 88 3 45 67 1 99
Mera heap : 99 91 88 67 56 45 23 12 7 4 3 1
STL ka pq : 99 91 88 67 56 45 23 12 7 4 3 1

DONO ka natija BILKUL same? HAAN ✓⭐⭐
```
> ⭐⭐⭐ **~20 line me STL jaisa heap.** Ab koi jaadu nahi bacha. *(Interview: "heap implement karo" ka jawab yahi)*

---

## ⭐⭐ make_heap — O(n), n log n NAHI!

```
30 lakh element ka heap :
   ek-ek push  O(n log n)
   make_heap   O(n)          ->  2.25x TEZ ⭐
is_heap check : VALID HEAP ✓
```

```
n/2 node (patte) : 0 kadam | n/4 : 1 | n/8 : 2 ...
KUL = n*(1/4 + 2/8 + 3/16 + ...) = O(n) ⭐
Zyadatar node NEECHE hain -- unhe hilna hi nahi padta!
```
> ⭐⭐⭐ Saara data pehle se ho → **`priority_queue<int> pq(v.begin(), v.end());`** (O(n))

---

## ⭐⭐⭐ 3 CLASSIC

**1) TOP-K largest** — `{3,1,5,12,2,11,8,7}`, k=3 → **12 11 8** ✓
> ⭐⭐⭐ **"K sabse BADE" ke liye MIN-heap!** Size k rakho, naya aaye to **sabse chhota** nikalo. **O(n log k)**

**2) K-way merge** — 3 sorted list → `1 2 3 5 6 7 9 10 11` ✓ · **O(N log k)**

**3) DIJKSTRA**
```
Graph : 0-1(4), 0-2(1), 1-2(2), 1-3(1), 2-3(5)
Distance from 0 :  0:0  1:3  2:1  3:4

⭐ 0 se 1 tak SEEDHA 4 hai, par 0->2(1)->1(2) = 3 ✓
```
> **3 niyam:** `{cost,node}` · **min-heap** · `if (d > dist[u]) continue;` — **teeno zaroori**

---

## ⭐⭐ pq vs sort vs nth_element

30 lakh me se top 100 — **teeno ka jawab same ✓**

| Tareeka | Complexity | Kab |
|---|---|---|
| `priority_queue` | O(n log k) | **STREAMING** data ⭐ |
| `sort` | O(n log n) | poora kram chahiye |
| **`nth_element`** | **O(n)** ⭐⭐ | saara data pehle se ho |

> `nth_element` poora sort **nahi** karta — bas k-th jagah sahi karta hai (**quickselect**).

---

## ⭐ DSA me + Median in stream

**Dijkstra** ⭐⭐⭐ · **Prim's MST** · **Top-K** ⭐⭐⭐ · K-way merge · Huffman · **Median in stream** ⭐⭐ · A* · scheduling

```
Stream : 5(med=5) 15(med=10) 1(med=5) 3(med=4) 8(med=5)
```
> ⭐ **DO heap**: `lo` = chhota aadha (max-heap), `hi` = bada aadha (min-heap). Median hamesha inke **top** pe. Insert O(log n), median **O(1)** ⭐

---

## COMPLEXITY

| Operation | Time |
|---|---|
| `push` / `pop` | **O(log n)** ⭐ |
| **`top()`** | **O(1)** ⭐⭐ |
| **`pq(v.begin(), v.end())`** | **O(n)** ⭐⭐ (make_heap!) |
| n baar push | O(n log n) ⚠️ |
| Top-K (min-heap k) | **O(n log k)** ⭐ |
| `nth_element` | **O(n)** ⭐⭐ |
| Dijkstra | O((V+E) log V) |
| element dhoondhna | ❌ hai hi nahi |

---

## ❌ 10 GALTIYAN

1. ⚠️⚠️ `priority_queue<int>` ko **min-heap** samajhna
2. ⚠️⚠️ comparator ka **ulta logic**
3. ⚠️⚠️ min-heap me sirf **2 template argument**
4. ⚠️⚠️ Dijkstra me **`{node, cost}`**
5. ⚠️⚠️ **stale check bhoolna**
6. ⚠️ Top-K me **max-heap** use karna
7. ⚠️ khaali pe `top()`
8. ⚠️ pq me element dhoondhna/badalna
9. ⚠️ saara data hone pe bhi **ek-ek push**
10. ⚠️ `-x` jugaad me **INT_MIN** bhoolna

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **EMERGENCY WARD** 🏥 — line nahi, priority
2. ⭐⭐⭐ Andar `vector` me **PED** — `(i-1)/2`, `2i+1`, `2i+2`
3. ⭐⭐⭐ **Heap SORTED NAHI** — sirf parent>child. Isi "kam niyam" se O(log n)
4. ⭐⭐ push = **sift-up**, pop = aakhri upar + **sift-down**
5. ⭐⭐⭐ Default **MAX**; comparator `sort` se **ULTA**
6. ⭐⭐⭐ Top-K ke liye **ULTA heap** (K bade → MIN-heap)
7. ⭐⭐ **`make_heap` O(n)** hai (n log n nahi!)
8. ⭐⭐⭐ Dijkstra ke **3 niyam**: `{cost,node}` · min-heap · stale check

---

**File:** `01_priority_queue_theory.cpp` (1,300 lines) · **0 warnings** · ASan+UBSan **clean**
