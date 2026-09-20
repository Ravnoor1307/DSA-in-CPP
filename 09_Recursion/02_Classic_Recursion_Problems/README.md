# 02_Classic_Recursion_Problems

## Real-world analogy summary

Classic recursion problems repeated smaller work par based hain: factorial arrangements, Fibonacci rabbit growth, digit extraction, power multiplication, and bookshelf reverse.

## Approach comparison table

| Problem | Approach | Formula / idea | Calculation | Time | Space |
|---|---|---|---:|---:|---:|
| Factorial | loop | multiply 1..n | n iterations | O(n) | O(1) |
| Factorial | recursion | `n*fact(n-1)` | n calls | O(n) | O(n) stack |
| Fibonacci | loop | keep previous two | n-1 iterations | O(n) | O(1) |
| Fibonacci | naive recursion | `fib(n-1)+fib(n-2)` | call tree up to 2^n | O(2^n) | O(n) stack |
| Fibonacci | memoization | store computed states | n states once | O(n) | O(n) |
| Sum digits | recursion | `n%10 + f(n/10)` | digit count d | O(d)=O(log n) | O(d) |
| Power | simple recursion | `a * power(a,n-1)` | n+1 calls | O(n) | O(n) |
| Reverse array | recursive two pointers | swap ends then inner | floor(n/2) swaps | O(n) | O(n) stack |

## Key formulas

```text
fact(n) = n * fact(n-1), fact(0)=1
fib(n) = fib(n-1) + fib(n-2), fib(0)=0, fib(1)=1
sumDigits(n) = n%10 + sumDigits(n/10)
power(a,n) = a * power(a,n-1), power(a,0)=1
reverse(arr,l,r): swap arr[l], arr[r], recurse l+1,r-1
```

## Fibonacci O(2^n) intuition

```text
Each non-base call creates 2 calls.
Level 0: 1
Level 1: 2
Level 2: 4
...
Level n: 2^n
Total = 1+2+4+...+2^n = O(2^n)
```

## Common mistakes

1. Factorial base case `n==0` ignore karna.
2. Fibonacci naive recursion ko O(n) bolna.
3. Memoization array initialize `-1` se na karna.
4. Sum digits me `n/10` smaller problem bhoolna.
5. Power simple recursion ko binary exponentiation samajhna.
6. Reverse array recursive base `left>=right` miss karna.

## Interview questions

1. fact(4) call stack journey draw karo.
2. Fibonacci recursion tree fib(5) ke liye draw karo.
3. Fibonacci memoization repeated calls kaise remove karta hai?
4. Sum of digits recursion formula kya hai?
5. Recursive reverse array two-pointer dry run karo.
