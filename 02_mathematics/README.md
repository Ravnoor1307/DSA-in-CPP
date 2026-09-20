# 02_mathematics — Mathematics for DSA

Complete mathematics-for-DSA module in C++. Every topic follows the strict notes format:
real-world scenario → English theory doc → step-by-step logic with WHY → ASCII visuals →
dry run → full complexity derivation → approach comparison. Inline code comments in
Hinglish, all code compile-ready.

## Folder Tree

```txt
02_mathematics/
├── 01_Numbers_Basics/
│   ├── 01_theory.cpp       → digit extraction, count/sum, reverse, palindrome, Armstrong
│   ├── task.cpp            → 5-6 tasks EASY→HARD with solutions
│   └── README.md
├── 02_Math_for_Complexity/
│   ├── 01_theory.cpp       → log intuition, log-digit trick, 2^n explosion, series → O(1)
│   ├── task.cpp
│   └── README.md
├── 03_Bit_Manipulation/
│   ├── 01_theory.cpp       → binary, & | ^ << >> ~, masks, Kernighan, XOR magic
│   ├── task.cpp
│   └── README.md
├── 04_Number_Theory/
│   ├── 01_theory.cpp       → prime, sieve, GCD/LCM, divisors, factorization, modulo
│   ├── task.cpp
│   └── README.md
├── 05_Binary_Exponentiation/
│   ├── 01_theory.cpp       → naive vs recursive/iterative fast power, mod-power
│   ├── task.cpp
│   └── README.md
├── 06_Combinatorics_Basics/
│   ├── 01_theory.cpp       → nPr/nCr, overflow, multiplicative nCr, Pascal DP
│   ├── task.cpp
│   └── README.md
└── 07_Math_Problems_Mixed/
    ├── 01_theory.cpp       → toolkit table + 3 full revision problems
    ├── task.cpp
    └── README.md
```

## Master comparison table

| Section | Main concepts | Key complexity ideas |
|---|---|---|
| 01_Numbers_Basics | digits, reverse, palindrome, Armstrong | digit loop `d` times → `O(d) = O(log n)` |
| 02_Math_for_Complexity | logs, growth, series formulas | halving → `O(log n)`, formulas → `O(1)` |
| 03_Bit_Manipulation | bits, masks, XOR, Kernighan | fixed 32-bit ops → `O(1)`, XOR pass → `O(n)` |
| 04_Number_Theory | prime, sieve, gcd, lcm, divisors, modulo | `O(√n)`, Euclid `O(log n)`, sieve `O(n log log n)` |
| 05_Binary_Exponentiation | naive vs fast power, mod power | exponent halving: `n/2^k = 1 → k = log₂n` |
| 06_Combinatorics_Basics | nPr, nCr, overflow, Pascal | multiplicative nCr `O(r)`, Pascal DP `O(R²)` |
| 07_Math_Problems_Mixed | revision problems | combines digits, gcd, sieve, XOR, fast pow |

## Must-remember formulas

```cpp
// Digits
lastDigit = n % 10;
n = n / 10;
reverse = reverse * 10 + lastDigit;
digitCount = floor(log10(n)) + 1;

// Logs / halving
n / 2^k = 1 -> k = log2(n)

// Bits
getBit    = (n >> k) & 1;
setBit    = n | (1 << k);
clearBit  = n & (~(1 << k));
toggleBit = n ^ (1 << k);
isPowerOfTwo = n > 0 && (n & (n - 1)) == 0;
singleNonRepeating = xor of all elements (a^a=0)

// Number theory
gcd(a,b) = gcd(b, a % b);          // Euclid
lcm(a,b) = (a / gcd(a,b)) * b;     // avoid overflow: divide first

// Modular arithmetic
(a+b)%m = ((a%m) + (b%m)) % m;
(a*b)%m = ((a%m) * (b%m)) % m;
(a-b)%m = ((a%m) - (b%m) + m) % m;

// Combinatorics
nPr = n! / (n-r)!;
nCr = n! / (r! * (n-r)!);
nCr = nC(n-r);
nCr multiplicative: product (n - i) / (i + 1) for i = 0..r-1
Pascal[i][j] = Pascal[i-1][j-1] + Pascal[i-1][j];

// Binary exponentiation (fast power, O(log b))
while (exp > 0) {
  if (exp & 1) ans = (ans * base) % m;
  base = (base * base) % m;
  exp >>= 1;
}
```

## Completion checklist

- Real-world scenario in every `01_theory.cpp`
- English doc blocks (theory/logic/scenario) + Hinglish inline code comments
- ASCII visual walkthroughs everywhere
- Dry run states included
- Complexity always derived step-by-step before stating Big-O (no bare `O(?)`)
- Compile-ready C++ (`g++ -std=c++17 -Wall`), edge cases handled
- `01_theory.cpp` contains no tasks; tasks live only in `task.cpp`
- `README.md` + `task.cpp` present in every section