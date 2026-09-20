# 36. Stack (STL) 🔴 EXTRA-DEEP — *Part_03 STL 7/17*

> **Ek line me:** Stack me sirf **5 function** hain — aur usi *"kam"* me uski taakat hai. **Kam option = kam galti = saaf code.**

---

## 🍽️ ANALOGY — THALIYON ka DHER
Nayi thali **sabse upar**, uthao bhi **sabse upar** wali. Beech wali chahiye? **Upar ki saari hatao.**

> **LIFO** = Last In, First Out. Aur ye zindagi me hota hai: **Back button** · **Ctrl+Z** · **function call stack** *(topic 19!)* · bracket matching

---

## ⭐ 5 operation — bas itne hi

| | Kya | Time |
|---|---|---|
| `push(x)` | upar rakho | O(1) ⭐ |
| `pop()` | upar wali hatao | O(1) ⭐ |
| `top()` | upar wali **dekho** | O(1) ⭐ |
| `empty()` / `size()` | | O(1) |

> Koi `[]`, koi loop, koi `begin()` **NAHI** ⭐

---

## ⭐⭐⭐ stack ek ADAPTER hai — SABOOT

```
sizeof(stack<int>) = 80        sizeof(deque<int>) = 80     Dono same ✓⭐
```

```cpp
template <class T, class Container = deque<T>>
class stack {
    Container c;                                  // ⭐ andar deque
public:
    void push(const T& x) { c.push_back(x); }     // ⭐ bas naam badla!
    void pop()            { c.pop_back(); }
    T& top()              { return c.back(); }
};
```

> ⭐⭐⭐ **Fayda kya?** `deque` me aap `dq[5]` kar sakte the, beech se erase kar sakte the. `stack` **wo sab band** kar deta hai — ab LIFO ka niyam **toot hi nahi sakta** *(topic 24)*.
> 🍽️ Dher pe **dhakkan** laga diya.
> ⭐ Aur ye **HAS-A** hai, IS-A nahi *(topic 25 — composition)*.

---

## ⭐⭐ Andar ka container badlo

```cpp
stack<int>                 // deque (default)
stack<int, vector<int>>    // ⭐ cache friendly
stack<int, list<int>>      // har push pe `new` ⚠️
```
> **Shart:** container `back()`, `push_back()`, `pop_back()`, `empty()`, `size()` de.
> ⚠️ `set` nahi chalega (`push_back` hai hi nahi).

---

## ⚠️⚠️ 3 JAAL

**1) `pop()` KUCH LAUTATA NAHI**
```cpp
int x = st.pop();   // ❌ error: void value not ignored as it ought to be
int x = st.top();   st.pop();     // ✓ do kadam
```
> ⭐ **Kyun aisa design?** Agar `pop()` value lautata: (1) copy banani padti, (2) **copy me exception aa gaya to element nikal bhi chuka aur mila bhi nahi** ⚠️ — isliye STL ne dono kaam **alag** kiye.

**2) Khaali pe `top()`/`pop()` = UB** — STL **check nahi karta** (`vector::at()` jaisa exception nahi). Hamesha `while (!st.empty())`

**3) Ghoom nahi sakte** — `for (x : st)` ❌. COPY bana kar khali karo, ya `vector` use karo.

---

## ⭐⭐⭐ CLASSIC 1 — Bracket matching

| Input | Sahi? |
|---|---|
| `({[]})` | HAAN ✓ |
| `(()` | NAHI ✗ (ant me stack khaali nahi) |
| `([)]` | NAHI ✗ (jodi galat) |
| `""` | HAAN ✓ |
| `)(` | NAHI ✗ (band aaya, stack khaali) |

> **3 tarah se galat** ho sakta hai — teeno handle karne padte hain. O(n) time, O(n) space.

---

## ⭐⭐⭐ CLASSIC 2 — Next Greater (MONOTONIC STACK)

```
Element :    4   5   2  25   7   8
Jawab   :    5  25  25  -1   8  -1        (-1 = koi bada nahi) ⭐
```

> **Brute force O(n²)** → **stack se O(n)** ⭐
> **Soch:** stack me wo **index** rakho jinka jawab nahi mila. Naya element aaye → stack ke upar jo sab **isse chhote** hain, unka jawab **yahi** hai.
> ⭐⭐ **Har element 1 baar ghusta, 1 baar nikalta → 2n → O(n)** (nested loop dikhne ke bawajood!)

**Isi pattern se:** Next Smaller · **Largest Rectangle in Histogram** ⭐ · Stock Span · **Trapping Rain Water** ⭐ · Daily Temperatures

---

## ⭐⭐⭐ CLASSIC 3 — Expression

```
postfix "2 3 4 * +"          = 14  ✓
postfix "5 1 2 + 4 * + 3 -"  = 14  ✓

infix -> postfix :
   a+b*c      ->  abc*+       (* ki priority zyada)
   (a+b)*c    ->  ab+c*       (bracket ne kram badla)
   a*(b+c)/d  ->  abc+*d/
```
> ⚠️ **Kram dhyan se:** `b = pop(); a = pop();` → `a op b` (warna `-` aur `/` **ulta** jawab denge!)
> ⭐⭐⭐ **Compiler asli me yahi karta hai** — aapka `2+3*4` pehle postfix banta hai, phir stack se calculate hota hai.

---

## ⭐⭐ CLASSIC 4 — Recursion → Stack

```
factRec(10)   = 3628800
factStack(10) = 3628800     Dono same ✓⭐

Iterative DFS : 0 2 4 1 3   ⭐ (recursion bina!)
```
> ⭐⭐ **Faayda:** topic 19 me dekha tha — stack 8 MB, ~262144 frame ki hadd. Khud ka stack **HEAP** pe hota hai → **crore element** aa sakte hain.

---

## ⭐⭐ stack vs vector — naap kar

1 crore push+pop: `stack` · `vector` · `stack<int,vector<int>>` — **teeno ka jawab same ✓**, time lagbhag barabar.

> ⭐⭐⭐ **To `stack` kyun? Speed ke liye NAHI — SAAFI ke liye:**
> 1. Padhne wala turant samajhta hai *"ye LIFO hai"*
> 2. Galti se `v[3]` likh hi **nahi** sakte
> 3. **Invariant compiler ke hawaale** *(topic 20/24)*
>
> ⚠️ CP me log `vector` use karte hain (debug me print karna hota hai) — wo bhi theek hai.

---

## ⭐ DSA me — 7 jagah + min-stack

Bracket · **Monotonic stack** ⭐⭐ · Expression · **Iterative DFS** · Undo/Back · Call stack · Backtracking

### ⭐⭐ Min-stack (`getMin()` bhi O(1)!)
```
push 5,2,8,1,9 -> top = 9 , min = 1
2 pop ke baad  -> top = 8 , min = 2   ⭐ (min wapas 2!)
```
> **Soch:** ek **dusra stack** jo sirf minimum track kare. Space O(n) extra, `getMin()` **O(1)** ⭐
> ⚠️ `<=` likhna (`<` nahi) — warna duplicate me bug!

---

## COMPLEXITY

| Operation | Time |
|---|---|
| push / pop / top / empty / size | **O(1)** ⭐ |
| ghoomna | ❌ hai hi nahi |

```
DERIVATION (Next Greater O(n)) :
  Dekhne me `while` andar `for` -> O(n²) lagta hai
  PAR har index MAX 1 baar push, MAX 1 baar pop
  KUL <= 2n -> O(n) ⭐  (AMORTIZED analysis)
```

---

## ❌ 10 GALTIYAN

1. ⚠️⚠️ `int x = st.pop();`
2. ⚠️⚠️ khaali pe `top()`/`pop()`
3. ⚠️⚠️ postfix me `a`/`b` ka kram ulta
4. ⚠️ `for (x : st)`
5. ⚠️ bracket me ant ka `empty()` check bhoolna
6. ⚠️ monotonic stack me **index ki jagah value** rakhna
7. ⚠️ `stack` ko naya DS samajhna (wo **adapter** hai)
8. ⚠️ CP me debug print na kar pana
9. ⚠️ gehri recursion ko stack se na badalna
10. ⚠️ min-stack me `<` (ki jagah `<=`)

---

## ⭐ 8 SEEKH

1. ⭐⭐⭐ **THALIYON ka DHER** — LIFO
2. ⭐⭐⭐ **ADAPTER hai** — `sizeof` se saabit kiya
3. ⭐⭐⭐ Fayda **speed nahi, SAAFI** — niyam toot hi nahi sakta
4. ⭐⭐ `pop()` kuch lautata nahi — **exception safety**
5. ⭐⭐ Khaali pe `top()` = UB (STL check nahi karta)
6. ⭐⭐⭐ **MONOTONIC STACK** — nested dikhta hai, **O(n)** hai
7. ⭐⭐ **Recursion khud ek stack hai**
8. ⭐⭐ `stack<int, vector<int>>` = saafi + speed

---

**File:** `01_stack_theory.cpp` (1,113 lines) · **0 warnings** · ASan+UBSan **clean**
