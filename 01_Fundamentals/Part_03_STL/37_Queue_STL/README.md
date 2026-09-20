# 37. Queue (STL) 🔴 EXTRA-DEEP — *Part_03 STL 8/17*

> **Ek line me:** Queue **"insaaf"** ka data structure hai — jo pehle aaya, use pehle mauka. Aur isi insaaf ki wajah se **BFS shortest path** dhoondh pata hai.

---

## 🚌 ANALOGY — BUS STOP ki LINE
Naya banda **line ke peechhe**, chadhega **aage wala**.

> **FIFO** = First In, First Out
> 🍽️ **STACK**: upar se daalo, upar se nikalo (LIFO) ⟷ 🚌 **QUEUE**: peechhe lago, aage se niklo (FIFO)

---

## ⭐ 6 operation

`push(x)` peechhe · `pop()` aage se · **`front()`** · **`back()`** · `empty()` · `size()` — sab **O(1)**

> ⭐ Stack me sirf `top()` tha; yahan `front()` **aur** `back()` dono.

---

## ⭐⭐ queue bhi ADAPTER hai

```
sizeof(queue<int>) == sizeof(deque<int>)  ✓⭐

void push(const T& x) { c.push_back(x); }
void pop()            { c.pop_front(); }     // ⭐⭐ YAHI farak hai
```

> ⭐⭐⭐ **`pop_front` chahiye** — isi liye:
> ```
> queue<int, vector<int>> q;
> error: 'class std::vector<int>' has no member named 'pop_front'
> ```
> `vector` me `pop_front` hai hi nahi (wo O(n) hota). Queue ke liye sirf **`deque` ya `list`**.
> *(Stack me `push_back/pop_back` chahiye tha — isliye wahan vector chalta tha)*

---

## ⚠️⚠️ 3 JAAL

1. **`pop()` kuch lautata nahi** → `int x = q.front(); q.pop();`
2. **Khaali pe `front()` = UB** → `while (!q.empty())`
3. **Ghoom nahi sakte** → debug ke liye `deque` use karo

> ⚠️ **Aur sabse common:** BFS me **`visited` mark karna bhoolna** → infinite loop!
> ⭐ **Niyam:** node ko queue me **DAALTE waqt** visited karo, nikaalte waqt nahi.

---

## ⭐⭐⭐ ARRAY se queue — aur wo TOOT jati hai

```
cap 5 : 5 push, phir 3 pop  ->  size = 2
ab push(99) -> MANA KAR DIYA ⚠️⚠️

Array : [10][20][30][40][50]
                      ^        ^
                   front     rear (= cap)
Shuru ke 3 khaane BEKAAR pade hain!
```
> Queue me sirf **2 element** hain, phir bhi *"bhar gaya"*.

---

## ⭐⭐⭐ CIRCULAR QUEUE — MODULO ka jaadu

```
rear  = (front + size) % cap      <- push yahan
front = (front + 1) % cap         <- pop ke baad ⭐
```

```
5 push, 3 pop -> frontIdx = 3 , size = 2
push(99) -> HO GAYA ⭐  (index (3+2)%5 = 0 pe GHOOM kar gaya!)
push(88) -> HO GAYA ⭐
push(77) -> MANA ⭐ (ab SACH ME bhara)

Nikaalte hain : 40 50 99 88 77   ⭐ FIFO kram bilkul sahi!
```
> 🚌 Bus stop **gol** hai — aakhri banda ghoom kar shuruaat wali (khaali) jagah pe aa jata hai.
> ⭐ **Chalak baat:** maine `rear` variable rakha hi **nahi** — sirf `front` aur `size`. Warna "full" aur "empty" **dono** me `front == rear` ho jata hai *(topic 24: ek sach rakho)*.

---

## ⭐⭐⭐ CLASSIC — BFS

**Graph:**
```
BFS kram : 0 1 2 3 4 5
Distance : 0:0 1:1 2:1 3:2 4:2 5:2
```
> ⭐⭐⭐ **BFS SHORTEST PATH deta hai** (unweighted) — kyunki wo **level by level** chalta hai. **DFS ye guarantee nahi deta!**

**Grid (maze):**
```
.....         0  1  2  3  4
.###.         1  #  #  #  5
.....    ->   2  3  4  5  6
.###.         3  #  #  #  7
.....         4  5  6  7  8

(0,0) se (4,4) shortest = 8 kadam ⭐
```
> `queue<pair<int,int>>` + `dx[]/dy[]` — **grid BFS ka standard** ⭐

---

## ⭐⭐ CLASSIC — Level order (tree)

```
level : 1
level : 2 3
level : 4 5 6
```
```cpp
int levelSize = q.size();          // ⭐⭐ YAHI TRICK
for (int i = 0; i < levelSize; i++) { ... }
```
> ⚠️ `q.size()` ko **loop ki condition me mat likhna** — wo badalti rehti hai!

**Isi se:** Right/Left view · Zigzag · Max in each level · Tree height

---

## ⭐⭐⭐ 2 STACK se QUEUE (interview favourite)

```
push 10,20,30  ->  front = 10 ⭐ (sabse pehle aaya!)
pop = 10 , pop = 20 , push 40 , pop = 30 ⭐ , pop = 40
```
> **Soch:** `inSt` me push. `outSt` khaali ho to **saara maal ulta** kar ke daal do → LIFO **ULTA ho kar FIFO** ban gaya ⭐
> ⭐⭐⭐ **Complexity:** `pop` dekhne me O(n), par har element **sirf ek baar** shift hota hai → **amortized O(1)** *(wahi soch jo vector doubling aur monotonic stack me thi)*
> ⚠️ `shift()` **tabhi** karo jab `outSt` khaali ho!

---

## ⭐⭐ queue vs deque vs vector+index

1 crore push+pop — **teeno ka jawab same ✓**

### ⭐ CP ka jugaad — sabse tez
```cpp
vector<int> v; int head = 0;
push : v.push_back(x)
pop  : head++              // ⭐ hatao mat, bas AAGE badh jao!
front: v[head]
```
> ⭐ Memory **bilkul lagataar** (cache!) · ⚠️ memory wapas nahi milti — BFS me theek hai (har node ek hi baar), lambe program me nahi.

---

## ⭐ DSA me — 7 jagah

**BFS (graph)** ⭐⭐⭐ · **BFS (grid)** ⭐⭐ · **Level order** ⭐⭐ · Topological sort (Kahn) · **Multi-source BFS** ⭐ · 0-1 BFS (deque) · Scheduling

> ⭐⭐ **Multi-source BFS:** saare source **ek saath** queue me daal do → "har source se alag BFS" O(n·m) ka kaam **ek BFS** O(n) me!
> ⭐ **DFS → STACK** (gehrai) 🍽️ · **BFS → QUEUE** (chaudai) 🚌

---

## COMPLEXITY

| Operation | Time |
|---|---|
| push / pop / front / back | **O(1)** ⭐ |
| **BFS (graph)** | **O(V + E)** ⭐ |
| BFS (grid R×C) | O(R·C) |
| 2-stack queue pop | O(1) amortized ⭐ |

```
BFS O(V+E) : har node MAX 1 baar queue me (visited) -> O(V)
             har edge 2 baar dekhi jati hai -> O(E)
```

---

## ❌ 10 GALTIYAN

1. ⚠️⚠️ BFS me **visited bhoolna** → infinite loop
2. ⚠️⚠️ visited **nikaalte** waqt mark karna (**daalte** waqt karo!)
3. ⚠️⚠️ `int x = q.pop();`
4. ⚠️⚠️ khaali pe `front()`
5. ⚠️ level-order me `q.size()` condition me
6. ⚠️ `queue<int, vector<int>>`
7. ⚠️ simple array queue (jagah bekaar)
8. ⚠️ circular me full/empty ka farak (**`size` rakho**)
9. ⚠️ queue me ghoomna
10. ⚠️ **shortest path ke liye DFS** (BFS chahiye!)

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **BUS STOP ki LINE** — FIFO (stack se ulta)
2. ⭐⭐⭐ ADAPTER, par **`pop_front` chahiye** → vector nahi chalega
3. ⭐⭐⭐ Simple array queue **TOOT jati hai** (live dekha)
4. ⭐⭐⭐ **`rear = (front+size) % cap`** — modulo se array **gol**
5. ⭐⭐⭐ **BFS = shortest path** (DFS nahi deta!)
6. ⭐⭐ Level-order me **`q.size()` pehle le lo**
7. ⭐⭐⭐ **2 stack se queue** — amortized O(1)
8. ⭐⭐ CP me **`vector + head`** sabse tez

---

**File:** `01_queue_theory.cpp` (1,161 lines) · **0 warnings** · ASan+UBSan **clean**
