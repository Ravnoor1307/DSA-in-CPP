# Number Theory

Number Theory is the math of integers behind cryptography, hashing, and competitive programming: primality testing, listing primes, gcd/lcm, divisors, prime factorization, and modular arithmetic. The single idea that unlocks the whole chapter is the factor-pair rule — if n = a·b, then at least one of a, b is ≤ √n, which is exactly why most loops here stop at √n instead of n. Sieve of Eratosthenes reuses that marking idea to list all primes ≤ n in O(n log log n), while Euclid's gcd shrinks the pair (a,b) down to (b, a%b) in O(log min(a,b)) steps. Modular arithmetic keeps huge intermediate products small, provided you remember that C++ `%` can be negative and needs a `+m` fix. Master these primitives and harder topics (modular inverse, Euler's totient, RSA) become natural extensions.

**Real-world analogy:** imagine a padlock whose key is made of two giant prime numbers. How fast your browser, bank, and chat app encrypt and decrypt everything depends on how fast software can answer "is this big number prime?", "list all primes in this range?", and "split this product back into its factors?" — the exact three operations in this folder.

## Files
| File | Purpose |
|------|---------|
| `01_theory.cpp` | Pure concept + working demo: prime check naive vs √n, sieve with marked-boolean printing, gcd (naive + Euclid recursive + iterative), lcm, divisors (binary naive + pair loop), prime factorization of 84, modular arithmetic with m=7 and the negative-`%` fix. No tasks. |
| `task.cpp` | 7 tasks (easy → hard) with hints, starter code, full solved code, and hinglish-commented explanations: count divisors, is-prime (√n), lcm(4,6), sieve primes ≤ n, gcd of array, count primes in range, count prime factors. |
| `README.md` | This file: summary, analogy, formulas, complexity table, common mistakes, interview Q&A. |

## Cheat sheet
```
prime check:      is n < 2 -> false; loop i=2..√n, if n%i==0 -> false
factor-pair rule: n = a*b  =>  min(a,b) <= √n    (loop gate: i*i <= n, write i <= n/i)
sieve:            composite[p*p..] marked for every prime p (start at p*p, step p)
gcd (Euclid):     gcd(a,b) = gcd(b, a%b);  gcd(x,0) = x
lcm:              lcm(a,b) = a / gcd(a,b) * b        (divide FIRST, avoid overflow)
gcd of array:     g = v[0];  g = gcd(g, v[i])  for i = 1..n-1
divisors:         for d=1..√n: if n%d==0 print d, and n/d when d != n/d
factorization:    strip 2s;  for f=3..√n step 2 strip f;  leftover n>1 is prime
mod add/mul:      (a+b)%m = (a%m + b%m)%m     (a*b)%m = (a%m * b%m)%m
mod sub:          (a-b)%m = ((a%m - b%m) % m + m) % m      // +m fixes C++ negative %
```

## Complexity table (derived)
| Algorithm | Time | Space | Why |
|-----------|------|-------|-----|
| isPrime naive | O(n) | O(1) | loop from 2 to n/2, ~n checks |
| isPrime √n | O(√n) | O(1) | factor pairs (a,b) with a·b=n; both > √n impossible, one factor ≤ √n |
| Sieve of Eratosthenes | O(n log log n) | O(n) | Σ n/p over primes p ≤ n = n·log log n (Mertens); bool array of size n |
| gcd naive | O(min(a,b)) | O(1) | tries every d = 1..min |
| gcd Euclid (rec/iter) | O(log min(a,b)) | O(log min) rec stack / O(1) iter | remainder < b each step, sizes halve every ~2 steps (Fibonacci worst case) |
| lcm via gcd | O(log min(a,b)) | O(1) | one Euclid gcd + O(1) multiply |
| divisors naive | O(n) | O(1) | loop 1..n |
| divisors pair loop | O(√n) | O(1) | pairs (d, n/d) found at d ≤ √n |
| factorization trial division | O(√n) worst | O(1) | after stripping 2, odd f ≤ √n; leftover n>1 is prime |
| modular +, −, * | O(1) | O(1) | constant work on two ints |

## ⚠️ Common mistakes
- **Forgetting 0, 1**: neither is prime; `isPrime` must return false for `n < 2`.
- **Looping to n instead of √n**: for a single primality/divisor test that is purely wasted work — factor pairs mirror at √n.
- **`i*i <= n` overflow**: for big `n`, `i*i` may overflow `int`; write `i <= n / i`.
- **Sieve starting from `2*p` instead of `p*p`**: smaller multiples are already marked by smaller primes; starting at `p*p` saves work (same marked result).
- **`lcm` overflow**: `a * b / gcd` can overflow; always divide first: `a / gcd(a,b) * b`.
- **Trusting C++ `%` with negatives**: `-3 % 7 == -3`. For modular subtraction/negative operands, apply `+m` then `%m`.
- **Not stripping 2 first in trial factorization**: the loop doubles the work on even numbers; handle 2, then only odd `f`.
- **Forgetting the leftover prime in factorization**: after the loop, `n > 1` is a prime factor that must be counted.

## Interview Q&A
**Q: Why do we only need to check divisors up to √n to test primality?**
A: Every composite n factors as n = a·b. If both a > √n and b > √n, then a·b > n, contradiction. So at least one factor of every pair is ≤ √n, and a divisor search only needs to probe i = 2..√n.

**Q: Why is the sieve O(n log log n) and not O(n√n)?**
A: Each prime p marks its multiples once, so the total work is n/p summed over primes ≤ n: n(1/2 + 1/3 + 1/5 + ...) = n·log log n. No number is re-marked, unlike re-testing every number individually.

**Q: Why does Euclid's algorithm terminate and stay correct?**
A: Correctness: the divisor set of (a,b) equals the divisor set of (b, a%b) (a = q·b + r, so anything dividing b and r also divides a, and vice versa), so the gcd never changes. Termination: a%b < b, so the pair strictly shrinks and eventually reaches (gcd, 0); gcd(x,0) = x. Worst case is consecutive Fibonacci numbers, giving O(log min(a,b)) steps.

**Q: How do I compute lcm without overflow?**
A: Use `a / gcd(a,b) * b` — divide before multiplying, because `a * b` may overflow while `a / gcd` is always an exact integer.

**Q: How do I handle negative numbers in modular arithmetic in C++?**
A: C++ `%` keeps the sign of the dividend (`-3 % 7 == -3`). Map into 0..m-1 by adding `m` and taking `%m` again: `((x % m) + m) % m`. For subtraction use `((a%m - b%m) % m + m) % m`.

**Q: Given 84, list the prime factors with multiplicity — what's the order of steps?**
A: Strip 2 while divisible (2,2, n=21), then odd factors from 3: while f·f ≤ n test (3, n=7). Stop when f·f > 7; leftover 7 > 1 is prime. Result: 2²·3·7 → 4 factors.