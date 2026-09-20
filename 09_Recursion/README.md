# 09_Recursion

## Module goal

Recursion ko **Russian nesting dolls** ki tarah samjho. Har doll ke andar ek chhoti doll hoti hai, jab tak sabse chhoti doll na mil jaye. Programming me recursion bhi same problem ka **smaller version** call karta hai.

```text
openDoll(3)
   ↓
openDoll(2)
   ↓
openDoll(1)  <- base case: stop
   ↑
return back upward
```

## Definition

```text
Recursion = function jo khud ko call kare
```

Har recursive function ke 2 parts mandatory:

```text
1. Base Case       -> rukna kahan hai?
2. Recursive Case  -> smaller same problem kya hai?
```

---

## Folder tree

```text
09_Recursion/
├── README.md
├── 01_Recursion_Intro/
│   ├── 01_what_is_recursion_theory.cpp
│   ├── 02_how_call_stack_works.cpp
│   ├── 03_first_recursion_program.cpp
│   ├── 04_print_n_to_1.cpp
│   ├── 05_base_case_importance.cpp
│   ├── 06_recursion_vs_iteration.cpp
│   ├── README.md
│   └── task.cpp
├── 02_Classic_Recursion_Problems/
│   ├── 01_factorial_approach1_loop.cpp
│   ├── 02_factorial_approach2_recursive.cpp
│   ├── 03_fibonacci_approach1_loop.cpp
│   ├── 04_fibonacci_approach2_recursive.cpp
│   ├── 05_fibonacci_approach3_memoization.cpp
│   ├── 06_sum_of_digits_recursive.cpp
│   ├── 07_power_recursive.cpp
│   ├── 08_reverse_array_recursive.cpp
│   ├── README.md
│   └── task.cpp
├── 03_Recursion_on_Numbers/
│   ├── 01_count_digits_recursive.cpp
│   ├── 02_palindrome_check_recursive.cpp
│   ├── 03_gcd_euclidean_recursive.cpp
│   ├── 04_print_all_divisors_recursive.cpp
│   ├── 05_sum_1_to_n_tail_recursion.cpp
│   ├── 06_josephus_problem.cpp
│   ├── README.md
│   └── task.cpp
├── 04_Recursion_on_Strings/
│   ├── 01_string_reverse_recursive.cpp
│   ├── 02_vowel_count_recursive.cpp
│   ├── 03_palindrome_string_recursive.cpp
│   ├── 04_generate_all_subsequences.cpp
│   ├── 05_remove_char_recursive.cpp
│   ├── README.md
│   └── task.cpp
└── 05_Advanced_Recursion_Patterns/
    ├── 01_tower_of_hanoi.cpp
    ├── 02_print_all_permutations.cpp
    ├── 03_staircase_paths.cpp
    ├── 04_recursive_binary_search.cpp
    ├── 05_flood_fill_intro.cpp
    ├── README.md
    └── task.cpp
```

---

## Recursion tree padhna seekho

Recursion tree me har node ek function call hoti hai. Neeche jaana means new recursive call; upar aana means return/unwind.

### Example: factorial

```text
fact(4)
  ↓ needs 4 * fact(3)
fact(3)
  ↓ needs 3 * fact(2)
fact(2)
  ↓ needs 2 * fact(1)
fact(1) = 1 base
  ↑
fact(2) = 2 * 1 = 2
  ↑
fact(3) = 3 * 2 = 6
  ↑
fact(4) = 4 * 6 = 24
```

### Example: Fibonacci repeated calls

```text
                 fib(5)
              /          \
          fib(4)          fib(3)
        /      \         /      \
    fib(3)   fib(2)   fib(2)   fib(1)
    /   \     /   \    /   \
 fib(2) fib(1) ... repeated calls ...
```

Important observation:

```text
fib(3) repeated
fib(2) repeated
```

Memoization repeated calls ko array me stored answer se avoid karta hai.

---

## Call stack cheat sheet

```text
fact(3) call stack PUSH:

TOP  [fact(1), n=1]  <- base
     [fact(2), n=2]
BOT  [fact(3), n=3]

Unwind:
fact(1) returns 1
fact(2) returns 2*1 = 2
fact(3) returns 3*2 = 6
```

Har recursive call ka apna stack frame hota hai:

```text
frame stores: parameters + local variables + return address
```

---

## Recursion formula sheet

```text
Factorial:
fact(n) = n * fact(n-1), fact(0)=1 or fact(1)=1

Fibonacci:
fib(n) = fib(n-1) + fib(n-2), fib(0)=0, fib(1)=1

Sum digits:
sumDigits(n) = n%10 + sumDigits(n/10)

Power simple:
power(a,n) = a * power(a,n-1), power(a,0)=1

Count digits:
countDigits(n) = 1 + countDigits(n/10)

GCD Euclidean:
gcd(a,b) = gcd(b, a%b), gcd(a,0)=a

Tail recursion sum:
sumTail(n, acc) = sumTail(n-1, acc+n)

Josephus zero-index:
J(n,k) = (J(n-1,k) + k) % n, J(1,k)=0

String palindrome:
isPal(l,r) = s[l]==s[r] && isPal(l+1,r-1)

Subsequence generation:
each char -> TAKE or SKIP

Tower of Hanoi:
T(n) = 2*T(n-1) + 1 = 2^n - 1 moves

Staircase paths:
ways(n) = ways(n-1) + ways(n-2)

Recursive binary search:
range -> half range each call

Flood fill:
paint current -> recurse up/down/left/right
```

---

## Master approach comparison table

| Topic | Real-world analogy | Recursive idea | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Recursion intro | Russian dolls | smaller same problem | n levels | O(n) | O(n) stack |
| Print 1 to n | roll-call after smaller group | call first, print later | n+1 calls | O(n) | O(n) |
| Print n to 1 | countdown lift | print first, call later | n+1 calls | O(n) | O(n) |
| Loop sum | cashier same notebook | iteration | n loop iterations | O(n) | O(1) |
| Recursive sum | assistant chain | `n + sum(n-1)` | n+1 calls | O(n) | O(n) |
| Factorial loop | arrange boxes iteratively | multiply 1..n | n multiplications | O(n) | O(1) |
| Factorial recursion | n! = n*(n-1)! | smaller factorial | n calls | O(n) | O(n) |
| Fibonacci loop | rabbit monthly register | previous two values | n-1 iterations | O(n) | O(1) |
| Fibonacci naive | branching family tree | two recursive calls | up to 2^n nodes | O(2^n) | O(n) |
| Fibonacci memo | diary of answers | store states | n states once | O(n) | O(n) |
| Sum digits | remove last digit | `n/10` | d digits | O(d)=O(log n) | O(d) |
| Power simple | multiply copies | reduce exponent by 1 | n+1 calls | O(n) | O(n) |
| Reverse array | swap bookshelf ends | recurse inner array | floor(n/2) swaps | O(n) | O(n) |
| Count digits | bank number shrink | divide by 10 | d calls | O(log n) | O(log n) |
| GCD Euclidean | equal groups | remainder recursion | log-like calls | O(log min(a,b)) | O(log min(a,b)) |
| Print divisors | factor chart | current+1 check | n checks | O(n) | O(n) |
| Tail sum | running total carry | recursive call last | n+1 calls | O(n) | O(n) stack unless optimized |
| Josephus | circle elimination | shrink circle | n calls | O(n) | O(n) |
| String reverse simple | reverse name board | reverse(rest)+first | substr copies sum n² | O(n²) | O(n²) temp |
| Vowel count | teacher letter check | current + rest | n+1 calls | O(n) | O(n) |
| String palindrome | mirror word | compare ends | floor(n/2) calls | O(n) | O(n) |
| Subsequences | take/skip treasure | 2 choices per char | 2^n leaves, n output | O(n*2^n) | O(n*2^n) output |
| Remove char | clean-up bot | keep/skip current | n calls, concat cost | O(n²) simple | O(n²) temp |
| Tower of Hanoi | 3 rods puzzle | move n-1, disk, n-1 | 2^n-1 moves | O(2^n) | O(n) |
| Permutations | arrange friends | choose/swap/undo | n! outputs * n print | O(n*n!) | O(n) stack |
| Staircase paths | 1/2 step jumps | fib recurrence | 2-branch tree | O(2^n) naive | O(n) |
| Recursive binary search | dictionary half discard | search half | n/2^k=1 | O(log n) | O(log n) |
| Flood fill | paint bucket | 4-direction DFS | each cell once | O(R*C) | O(R*C) worst |

---

## Important complexity derivations

### Linear recursion

If problem reduces by 1:

```text
n -> n-1 -> n-2 -> ... -> 0
number of calls = n+1
Time = O(n)
Stack = O(n)
```

### Digit recursion

If number divides by 10:

```text
n -> n/10 -> n/100 -> ... -> 0
number of calls = number of digits d
d = floor(log10(n)) + 1
Time = O(log n)
```

### Binary search recursion

```text
size after k calls = n / 2^k
stop when size = 1
n / 2^k = 1
n = 2^k
k = log₂n
Time = O(log n)
```

### Naive Fibonacci recursion

```text
Each non-base call creates 2 calls.
level 0 -> 1 call
level 1 -> 2 calls
level 2 -> 4 calls
...
level n -> 2^n calls
Total = 1 + 2 + 4 + ... + 2^n = O(2^n)
```

### Subsequence recursion

```text
Each character has 2 choices: TAKE or SKIP
Total leaves = 2 * 2 * ... n times = 2^n
If printing each subsequence of length up to n:
Time = O(n * 2^n)
```

### Permutations

```text
n choices for first position
(n-1) choices for second
(n-2) choices for third
...
1 choice last
Total outputs = n!
If each output prints n chars:
Time = O(n * n!)
```

### Tower of Hanoi

```text
T(n) = 2*T(n-1) + 1
T(1) = 1
T(2) = 3
T(3) = 7
T(4) = 15
Pattern = 2^n - 1
Time = O(2^n)
```

---

## Section-wise roadmap

### 01_Recursion_Intro

- Russian nesting dolls analogy.
- Definition: function calling itself.
- Base case and recursive case.
- Call stack PUSH/POP visual.
- Print 1 to n and n to 1 order magic.
- No base case = stack overflow visual.
- Recursion vs iteration master table.

### 02_Classic_Recursion_Problems

- Factorial loop and recursion.
- fact(4) complete call stack journey.
- Fibonacci loop, naive recursion, memoization.
- fib(5) recursion tree and repeated calls.
- Sum of digits using `n%10 + f(n/10)`.
- Power simple recursion.
- Reverse array recursive two-pointers.

### 03_Recursion_on_Numbers

- Count digits recursively.
- Palindrome check recursive two-pointers.
- GCD Euclidean recursion: `gcd(48,18)->gcd(18,12)->gcd(12,6)->gcd(6,0)`.
- Print all divisors recursively.
- Tail recursion concept.
- Josephus circle elimination problem.

### 04_Recursion_on_Strings

- String reverse recursion.
- Vowel count recursion.
- Palindrome string recursion.
- Generate all subsequences with TAKE/SKIP tree.
- Remove character recursively.

### 05_Advanced_Recursion_Patterns

- Tower of Hanoi with n=3 complete 7 moves.
- Permutations of `abc` using swap tree and backtracking undo.
- Staircase paths: Fibonacci in disguise.
- Recursive binary search.
- Flood fill intro: 2D recursion and graphs preview.

---

## Common mistakes checklist

1. Base case bhoolna.
2. Recursive case me problem smaller na banana.
3. Base case wrong value return karna.
4. Print before recursive call vs after recursive call order confuse karna.
5. Recursive function ke har call ki local variable copy hoti hai ye ignore karna.
6. Recursion time batakar stack space skip karna.
7. Naive Fibonacci ko O(n) bolna.
8. Memoization me repeated computed answer store na karna.
9. Sum digits me `n%10` and `n/10` swap/skip karna.
10. GCD base `b==0` miss karna.
11. Tail recursion ko C++ me guaranteed optimized assume karna.
12. Josephus zero-index answer ko directly one-index problem me return karna.
13. String palindrome recursion me `left>=right` base case miss karna.
14. Subsequences me TAKE and SKIP dono branches na banana.
15. Permutations me swap back/undo bhoolna.
16. Binary search me mid calculation ya sorted condition ignore karna.
17. Flood fill me boundary check grid access ke baad karna.
18. Flood fill me oldColor==newColor handle na karna.
19. Tower of Hanoi me helper and destination rods wrong pass karna.
20. Complexity me loop/call count calculation na dikhana.

---

## Interview question bank

1. Recursion kya hota hai?
2. Base case and recursive case explain karo.
3. Russian dolls analogy se recursion samjhao.
4. Call stack fact(3) ke liye draw karo.
5. Har recursive call ke stack frame me kya store hota hai?
6. Print 1 to n recursively kaise karoge?
7. Print n to 1 recursively kaise karoge?
8. Print before call and call before print ka output difference kya hai?
9. No base case se stack overflow kyun hota hai?
10. Recursion vs iteration compare karo.
11. Factorial loop and recursion compare karo.
12. fact(4) complete dry run karo.
13. Fibonacci naive recursion O(2^n) kyun hai?
14. fib(5) recursion tree draw karo.
15. Memoization repeated Fibonacci calls kaise avoid karta hai?
16. Sum of digits recursive formula kya hai?
17. Power simple recursion and binary exponentiation preview difference kya hai?
18. Reverse array recursively using two pointers explain karo.
19. Count digits recursively ka formula kya hai?
20. Recursive palindrome number/string check explain karo.
21. gcd(48,18) Euclidean recursion dry run karo.
22. Print all divisors recursively ka base case kya hai?
23. Tail recursion kya hota hai?
24. C++ tail call optimization guarantee karta hai kya?
25. Josephus problem recurrence kya hai?
26. Josephus n=5,k=2 survivor find karo.
27. String reverse recursive logic explain karo.
28. Vowel count recursion ka base case kya hai?
29. "abc" subsequences take/skip tree draw karo.
30. Total subsequences 2^n kyun hote hain?
31. Remove character recursively ka keep/skip logic kya hai?
32. Tower of Hanoi rules kya hain?
33. Tower of Hanoi n=3 ke 7 moves likho.
34. Hanoi moves formula 2^n-1 kaise aata hai?
35. Permutations of abc using swap/backtracking print karo.
36. Backtracking me undo/swap back kyun important hai?
37. Staircase paths Fibonacci in disguise kyun hai?
38. Recursive binary search O(log n) prove karo.
39. Flood fill 2D recursion ka base condition kya hai?
40. Flood fill graphs/DFS preview kaise hai?

---

## How to study this module

1. Pehle `01_Recursion_Intro` me call stack diagrams manually draw karo.
2. Factorial and print order examples ko copy me trace karo.
3. Fibonacci naive recursion tree zaroor draw karo — repeated calls ka pain yahin samajh aata hai.
4. Memoization file run karke same calls avoided ka idea samjho.
5. Number recursion me GCD and Josephus formulas revise karo.
6. String recursion me TAKE/SKIP subsequence tree draw karo.
7. Advanced section me Hanoi, permutations, staircase, binary search, flood fill ko pattern-wise compare karo.
8. Har subfolder ka `task.cpp` pehle khud solve karo, phir lesson files se compare karo.
