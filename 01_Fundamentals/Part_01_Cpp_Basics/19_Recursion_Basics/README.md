# 19. Recursion Basics

> **Ek line me:** "Bade sawaal ko chhote waise hi sawaal me todo, aur sabse chhote ka jawab seedha bata do." Recursion = ek function khud ko call karta hai, har call pe problem chhoti hoti hai, ek base case pe rukta hai aur jawab wapas bubble karta hai. Tree, Graph, Backtracking, D&C, DP — sab isi pe khade hain.

A recursive function calls itself with a SMALLER version of the same problem until it hits a BASE CASE. Each call pushes a frame onto the call stack; when the base case returns, all frames unwind, propagating answers back up. Without a base case → infinite recursion → stack overflow → crash.

- **Real-world analogy:** Russian dolls — open the big doll, inside is a smaller one, and inside that a smaller one... down to the tiniest doll (BASE CASE), then you close them back up in reverse order. Or the cinema-row question: person 5 asks person 4, who asks person 3... person 1 knows the answer (base case), and it travels BACK up: 2, 3, 4, 5.
- **Files in this folder:**
  - `01_theory.cpp` — recursion theory with call-stack ASCII, factorial & fibonacci traces, recursion tree for fib(5), direct vs indirect recursion demo, stack-overflow danger, negative-input guards.
  - `task.cpp` — 6 tasks EASY→HARD (sumN, power, gcd, countDigits, fib with trace, recursive binary search) with full solutions.
  - `README.md` — this cheat sheet.
- **Cheat sheet / syntax:**

```
RECIPE:
  1. BASE CASE kya hai?        -> n==0, n==1, lo>hi, root==nullptr
  2. Sawaal chhota kaise?      -> n-1, n/2, a%b, mid±1
  3. Chhote jawab se bada?     -> n * fact(n-1), 1 + count(n/10)
  4. Same sawaal do baar?      -> MEMOIZATION (dag zero O(2^n) → O(n))

Common outputs:
  fact(5)   = 5*4*3*2*1 = 120
  fib(5)    = 5   fib(0)=0, fib(1)=1, fib(n)=fib(n-1)+fib(n-2)
  sumN(5)   = 1+2+3+4+5 = 15
  gcd(48,18)= 6   (gcd(a,b)=gcd(b,a%b))
  2^10      = 1024
```

- **Complexity:**

```
FACTORIAL : T(n) = T(n-1) + O(1) ; unroll -> n×O(1) => O(n) time, O(n) stack space
FIBONACCI : T(n) = T(n-1) + T(n-2) + O(1) ; tree me ~2^n nodes => O(2^n) time
            stack depth abhi bhi n => O(n) space   (time ve bekaar repeats)
BIN SEARCH: n/2^k = 1 -> k = log2(n) => O(log n) time, O(log n) stack
MEMO FIB  : har n ek baar -> O(n) time, O(n) space   (307,126× faster at n=40!)
```

- ⚠️ **Common mistakes:**
  1. **Base case bhoolna** → infinite recursion → stack overflow crash (SIGSEGV — verified: signal 139 / 11).
  2. Stack space ko complexity me na ginna — every call costs O(frame) memory.
  3. Bada n (> 10⁶) pe recursion — 8 MB stack bhar jata hai; loop likho.
  4. Recursive function me bada local `int arr[1000]` — frame phoolta hai, depth girta hai.
  5. `return` bhoolna — function undefined value lauta hai.
  6. Naive fibonacci likh dena jab memoization possible hai — always memo "same subproblem".
  7. Tail-call optimization pe bharosa na karo — guaranteed nahi hai; `-O1` pe wahi code crash hua.
- **Interview Q&A:**
  - *Q: Recursion vs iteration?* — A: Iteration: O(1) space. Recursion: O(depth) stack space but naturals for trees/graphs/backtracking/divide-&-conquer.
  - *Q: Why is naive fib O(2ⁿ)?* — A: T(n)=T(n-1)+T(n-2)+O(1); tree doubles each level → ~2ⁿ nodes, and fib(3)/fib(2) re-computed many times. Memo makes it O(n).
  - *Q: What happens without a base case?* — A: Frames pile until the 8 MB stack is full → stack overflow → crash.
  - *Q: What is direct vs indirect recursion?* — A: Direct: A calls A. Indirect: A calls B, B calls A.
  - *Q: When do we use recursion in DSA?* — A: Tree traversal, Graph DFS, Backtracking (N-queens, Sudoku), Merge/Quick sort, DP (memoized top-down).