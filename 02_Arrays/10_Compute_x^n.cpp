/*
=======================================================================
 THEORY : Compute x^n (Binary Exponentiation / Fast Exponentiation)
=======================================================================
 1. WHAT IT DOES
    - Computes x raised to the power n for integer x and non-negative
      integer n in O(log n) multiplications instead of O(n).

 2. WHY NOT LINEAR EXPONENTIATION (the naive loop)
    The naive approach:
        result = 1
        for i = 1 to n:
            result = result * x
    does exactly n multiplications -> O(n) time.

    Why is O(n) bad here?
      a) n can be up to 10^9 (or larger). O(n) = 10^9 multiplications
         which is right at the edge of the ~10^8 ops/second budget.
      b) More importantly, the numbers themselves GROW with each
         multiplication. Computing x^n produces a number with O(n log x)
         digits. Multiplying such large numbers gets slower as they grow,
         so the true cost is far worse than O(n) arithmetic ops.
      c) If we need x^n mod m (common in competitive programming),
         the intermediate values can overflow long long, making the
         naive loop wrong even with 64-bit integers.
    Binary exponentiation solves ALL of these problems: fewer
    multiplications AND each one keeps the intermediate value manageable
    (especially with mod).

 3. THE KEY IDEA -- BINARY DECOMPOSITION
    Write n in binary:
        n = b_k 2^k + b_{k-1} 2^{k-1} + ... + b_1 2 + b_0

    Then:
        x^n = x^{b_k 2^k} * ... * x^{b_1 2} * x^{b_0}

    We can compute x^1, x^2, x^4, x^8, ... by repeated squaring
    (each step: square the previous value). That is only log2(n) steps.
    Then we multiply only the ones where b_i = 1 -- at most log2(n)
    terms. Total: O(log n) multiplications.

    Example: x=2, n=13 (binary 1101)
        2^1  = 2           (bit 0 is 1 -> multiply)
        2^2  = 4           (bit 1 is 0 -> skip)
        2^4  = 16          (bit 2 is 1 -> multiply)
        2^8  = 256         (bit 3 is 1 -> multiply)
        result = 2 * 16 * 256 = 8192 = 2^13

 4. ITERATIVE ALGORITHM (preferred -- O(1) space)
        long long power(long long x, long long n) {
            long long result = 1;
            while (n > 0) {
                if (n & 1)          // if current bit is 1
                    result = result * x;
                x = x * x;          // square the base
                n = n >> 1;         // shift n right (next bit)
            }
            return result;
        }

    Loop runs exactly floor(log2(n)) + 1 times = O(log n).
    Each iteration does at most 2 multiplications.

    MODULAR VERSION (most used in practice):
        long long power(long long x, long long n, long long mod) {
            long long result = 1;
            x %= mod;
            while (n > 0) {
                if (n & 1)
                    result = result * x % mod;
                x = x * x % mod;
                n >>= 1;
            }
            return result;
        }

 5. RECURSIVE ALGORITHM (easier to understand, uses O(log n) stack)
        long long power(long long x, long long n) {
            if (n == 0) return 1;
            if (n % 2 == 0) {
                long long half = power(x, n / 2);
                return half * half;
            } else {
                long long half = power(x, (n - 1) / 2);
                return x * half * half;
            }
        }

 6. COMPLEXITY
    Multiplications : O(log n)  (each bit of n is examined once)
    Space           : O(1) iterative, O(log n) recursive stack
    This is BEST POSSIBLE -- you must examine every bit of n at least once.

 7. HOW TO CALCULATE THE COMPLEXITY (step by step)
    Step A - Input size parameter is n (the exponent), NOT x.
    Step B - Dominant operation = multiplying two numbers (one step per bit).
    Step C - Number of bits in n = floor(log2(n)) + 1.
            Each bit requires at most 2 multiplications (square + possible
            multiply into result). Total multiplications <= 2 * log2(n).
    Step D - O(2 * log n) = O(log n). The bit shift n >>= 1 is O(1).
    Step E - Decision: at n = 10^9, linear needs 10^9 multiplies (TLE);
            binary exponentiation needs ~30 multiplies (instant).
            If mod is applied, each multiply stays O(1) as well.
    WHY LINEAR FAILS:
        n = 10^9:
        - Linear: 10^9 multiplies  -> TLE
        - Binary: ~30 multiplies   -> instant
    This is a perfect illustration of the "time limit budget" concept.

 8. EDGE CASES
    - n = 0: x^0 = 1 for any x (including x=0 by convention).
    - x = 0: 0^n = 0 for n > 0, 0^0 = 1.
    - x = 1: 1^n = 1 always.
    - n = 1: result = x (single multiplication, both approaches tie).
    - Overflow: without mod, x^n can overflow even long long quickly.
      Always use the modular version in competitive programming.

 9. WHEN TO USE
    - Modular exponentiation in competitive programming (x^n mod m).
    - Fast power in matrix exponentiation (compute A^n mod m).
    - Discrete math problems involving powers in prime fields.
    - Anywhere you see "power" + "large exponent" + "mod".
=======================================================================
*/

#include <iostream>
using namespace std;

// ----------------------------------------------------------------
// Approach 1: Iterative binary exponentiation (O(log n), O(1) space)
// ----------------------------------------------------------------
long long power_iterative(long long x, long long n)
{
    long long result = 1;
    while (n > 0)
    {
        if (n & 1)          // current bit is 1
            result *= x;
        x *= x;             // square the base
        n >>= 1;            // shift to next bit
    }
    return result;
}

// ----------------------------------------------------------------
// Approach 2: Recursive binary exponentiation (O(log n), O(log n) stack)
// ----------------------------------------------------------------
long long power_recursive(long long x, long long n)
{
    if (n == 0)
        return 1;

    long long half = power_recursive(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

// ----------------------------------------------------------------
// Approach 3: Naive linear exponentiation (O(n)) -- shown for comparison
// ----------------------------------------------------------------
long long power_linear(long long x, long long n)
{
    long long result = 1;
    for (long long i = 0; i < n; i++)
        result *= x;
    return result;
}

// ----------------------------------------------------------------
// Approach 4: Binary exponentiation with MOD (most practical version)
// ----------------------------------------------------------------
const long long MOD = 1e9 + 7;

long long power_mod(long long x, long long n)
{
    long long result = 1;
    x %= MOD;
    while (n > 0)
    {
        if (n & 1)
            result = result * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return result;
}

// ----------------------------------------------------------------
int main()
{
    cout << "===== BINARY EXPONENTIATION DEMO =====" << endl;

    // Basic comparisons (all three methods agree for small n)
    cout << "\n--- Small n: all methods agree ---" << endl;
    long long bases[] = {2, 3, 5, 7};
    long long exps[]  = {0, 1, 2, 5, 10};
    for (int b = 0; b < 4; b++)
        for (int e = 0; e < 5; e++)
        {
            long long x = bases[b], n = exps[e];
            cout << x << "^" << n
                 << "  iter=" << power_iterative(x, n)
                 << "  rec="  << power_recursive(x, n)
                 << "  lin=" << power_linear(x, n)
                 << endl;
        }

    // Why linear is slow: a moderately large exponent
    cout << "\n--- Why linear is slow ---" << endl;
    cout << "Computing 2^30 with all methods..." << endl;
    cout << "Linear method:     2^30 = " << power_linear(2, 30)
         << "  (30 multiplications)" << endl;
    cout << "Binary iterative:  2^30 = " << power_iterative(2, 30)
         << "  (5 loop iterations, ~9 multiplications: bits of 30 = 11110)" << endl;
    cout << "Binary recursive:  2^30 = " << power_recursive(2, 30)
         << "  (log2(30)~5 squaring levels)" << endl;

    // Modular exponentiation (used in competitive programming)
    cout << "\n--- Modular exponentiation ---" << endl;
    long long mod_cases[][2] = {{2, 10}, {3, 13}, {7, 222}, {123456789, 1000000007}};
    for (int i = 0; i < 4; i++)
        cout << mod_cases[i][0] << "^" << mod_cases[i][1]
             << " mod " << MOD
             << " = " << power_mod(mod_cases[i][0], mod_cases[i][1])
             << endl;

    // Large exponent demonstration
    cout << "\n--- Large exponent (where linear FAILS) ---" << endl;
    cout << "2^1000000 mod " << MOD << " = " << power_mod(2, 1000000) << endl;
    cout << "(linear method would need 1,000,000 multiplications -> TLE)"
         << endl;

    return 0;
}
