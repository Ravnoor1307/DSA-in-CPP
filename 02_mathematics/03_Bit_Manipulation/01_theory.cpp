/*
═══════════════════════════════════════════════
 BIT MANIPULATION
 ⏱️ TIME COMPLEXITY: fixed-width (32-bit) loops are O(1);
     Kernighan runs O(number of set bits) ≤ 32 → O(1);
     XOR pass over n elements → O(n).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a bank of 32 light switches wired side by side. Each switch is one "bit".
 Some switches are ON (1), some are OFF (0), and every integer in your computer is
 just a pattern of these switches. Bit manipulation is the art of flicking only the
 switch you care about: "is the 3rd light on?", "turn the 5th light off", "which row
 of lights has an odd count?". Permission systems (rwx for owner/group/others), chess
 engines, image compression (bitplanes), and IP address math all run on these tricks,
 because one CPU instruction can flip, test, or combine 32 switches at once.

 📖 THEORY: (pure English, beginner-level)
 - Definition: bit manipulation = directly working with the binary (base-2) pattern of
   an integer using operators: & (AND), | (OR), ^ (XOR), << (shift left), >> (shift right),
   ~ (NOT/complement).
 - Key points / properties:
   * AND (&): 1 only when BOTH bits are 1.  (n & 1) == 1 means n is odd.
   * OR  (|): 1 when AT LEAST one bit is 1.
   * XOR (^): 1 when bits DIFFER. a ^ a == 0, a ^ 0 == a, a ^ b ^ a == b.
     XOR is reversible and self-cancelling — the heart of every "find the unique element" puzzle.
   * NOT (~): flips every bit (also flips the sign bit → two's complement).
   * << k : shifts bits left by k; each shift left multiplies by 2.
   * >> k : shifts bits right by k; each shift right divides by 2 (floor).
   * Masks: 1 << k is a single ON bit at position k. Combine with &, |, ^ to
     read or modify that one k-th bit while leaving the rest untouched.
 - ASCII diagram — 12 stored as 32 bits, showing only the lowest 4:

   n = 12   →   1 1 0 0          (16's 8 4 2 1: 8+4 = 12 ✓)
   bit pos       3 2 1 0

   Mask 1<<3 = 1000, 1<<2 = 0100, 1<<1 = 0010, 1<<0 = 0001

   XOR truth table:
      A ^ B | OUT
     -------+-----
      0  0  |  0
      0  1  |  1
      1  0  |  1
      1  1  |  0     ← self-cancel: A ^ A = 0

 - When to use: space/number puzzles (single unique element, two unique elements),
   fast multipication/division by powers of 2, flags & permission bits, toggling state,
   counting bits, and any problem that mentions "binary", "bit", "power of two".

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: CONVERT TO BINARY STRING.
         WHY: humans read base-10, computers store base-2. Loop from bit 31 down to 0
         and print '1' if (n >> i) & 1 else '0'. Shifting then AND-ing isolates one bit.

 Step 2: OPERATORS ON CONCRETE VALUES.
         WHY: memorized tables are useless until you can trace 7 & 3 = 3 step by step.

 Step 3: GET / SET / CLEAR / TOGGLE k-th BIT using mask = 1 << k.
         WHY: masks are the vocabulary of bit manipulation.
           GET    → (n >> k) & 1            read bit
           SET    → n | (1 << k)            force bit to 1
           CLEAR  → n & ~(1 << k)           force bit to 0
           TOGGLE → n ^ (1 << k)            flip bit

 Step 4: COUNT SET BITS — naive vs Kernighan.
         WHY: naive checks all 32 bits; Kernighan's n = n & (n-1) clears the lowest
         set bit each time, so loop runs only as many times as there are 1-bits.

 Step 5: POWER OF TWO check → n > 0 && (n & (n-1)) == 0.
         WHY: powers of two have EXACTLY one set bit. n-1 flips that bit and everything
         below; AND-ing gives 0 only for powers of two.

 Step 6: XOR MAGIC — single number and swap.
         WHY: a ^ a = 0 cancels duplicates; a ^ b ^ a = b "walks" a value through.

 VISUAL WALKTHROUGH: (bit flip of n=12)
   n     = 1100      target: TOGGLE bit 1
   mask  = 0010      (1 << 1)
   XOR   = 1110      ← bit 1 flipped ON  (was 0, now 1)  → 14
   then CLEAR bit 0:
   n     = 1110
   mask  = 0001      → ~mask = 1111...1110
   AND   = 1110      ← bit 0 forced to 0

   Kernighan on n = 12 (1100):
   1100 & 1011 = 1000   → one set bit cleared ✓
   1000 & 0111 = 0000   → another cleared ✓   → 2 iterations = 2 set bits

 DRY RUN: (trace on n = 12 with k = 2)
   binary of 12 = 1100
   (12 >> 2) & 1 = (0011) & 1 = 1   → GET bit 2 = 1
   12 | (1 << 2) = 1100 | 0100 = 1100 → SET bit 2 (already 1, unchanged) = 12
   12 & ~(1 << 2) = 1100 & 1011 = 1000 → CLEAR bit 2 = 8
   12 ^ (1 << 2) = 1100 ^ 0100 = 1000 → TOGGLE bit 2 = 8
   countSetBits(12): naive = 2 (checks 32 bits), Kernighan = 2 (2 iterations)
   isPowerOfTwo(12): 12 > 0 && (1100 & 1011=1000)!=0 → false ✓

 TIME COMPLEXITY CALCULATION:
 - toBinaryString: loops bits 31→0, that is 32 constant-time steps.
 - get/set/clear/toggle kth bit: single mask + single operator → O(1).
 - countSetBits naive: 32 iterations, each O(1) → 32 = O(1) for fixed 32-bit int.
 - countSetBits Kernighan: one iteration per set bit, at most 32 → O(popcount) ≤ 32 = O(1).
 - isPowerOfTwo: one AND + comparisons → O(1).
 - singleNumber (XOR pass): n elements, each a constant-time XOR → n steps.
 - xorSwap: three XORs, zero temp → O(1).
 → Time Complexity = O(1) for bit tricks; O(n) for the single-pass XOR over array.

 SPACE COMPLEXITY CALCULATION:
 - toBinaryString builds an output string of fixed 32 chars → O(1) (ignoring the string buffer).
 - singleNumber uses ONE running int variable regardless of array size → O(1) extra.
 - If asked, storing the input array itself is O(n), but all algorithms here add no
   per-element storage; no hashmap, no recursion, no stack.
 → Space Complexity = O(1) extra apart from the O(n) input array.

 APPROACH COMPARISON:
 ┌─────────────────────────────────────────────────┬──────────────────────────┬───────────────────────────────┐
 │ Task / Approach                                 │ Time                     │ Space (extra)                 │
 ├─────────────────────────────────────────────────┼──────────────────────────┼───────────────────────────────┤
 │ Count set bits — naive 32-iter loop             │ O(32) = O(1)             │ O(1)                          │
 │ Count set bits — Kernighan n&(n-1)              │ O(popcount) ≤ O(32)=O(1) │ O(1)                          │
 │ Count set bits — builtin popcount               │ O(1) hardware instruction│ O(1)                          │
 │ Single unique in array — XOR scan               │ O(n)                     │ O(1)                          │
 │ Single unique in array — hashmap counting       │ O(n)                     │ O(n)                          │
 │ Swap — temp variable                            │ O(1)  (1 temp var)       │ O(1) temp                     │
 │ Swap — XOR (no temp)                            │ O(1)  (no extra var)     │ O(1)                          │
 └─────────────────────────────────────────────────┴──────────────────────────┴───────────────────────────────┘
*/
#include <iostream>
#include <string>
using namespace std;

// helper: convert integer to binary string (fixed 8 bits shown for readability)
string toBinary8(int n) {
    string s;
    for (int i = 7; i >= 0; --i)          // 8 bits enough for demo numbers
        s += (n >> i) & 1 ? '1' : '0';    // sharpen: (n>>i)&1 isolates bit i
    return s;
}

int getBit(int n, int k)         { return (n >> k) & 1; }
int setBit(int n, int k)         { return n | (1 << k); }
int clearBit(int n, int k)       { return n & ~(1 << k); }
int toggleBit(int n, int k)      { return n ^ (1 << k); }

int countSetBitsNaive(int n) {
    int cnt = 0;
    for (int i = 0; i < 32; ++i)          // har bit ki bajao, 32 baar
        if ((n >> i) & 1) ++cnt;
    return cnt;
}

int countSetBitsKernighan(int n) {
    int cnt = 0;
    while (n) {                            // jab tak bits baaki hain
        n = n & (n - 1);                   // lowest 1-bit hatao
        ++cnt;
    }
    return cnt;
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;    // power of 2 → exactly one set bit
}

int singleNumber(int arr[], int size) {
    int res = 0;
    for (int i = 0; i < size; ++i)
        res ^= arr[i];                     // duplicate pair kabhi bhi XOR=0
    return res;
}

int main() {
    // ---------- 1) Binary representation via loop ----------
    cout << "--- Binary representation (loop) ---\n";
    int nums[] = {0, 1, 5, 12, 16};
    for (int x : nums)
        cout << x << " = " << toBinary8(x) << "\n";

    // ASCII / character note: har char ka ek integer (ASCII) code hota hai
    cout << "'A' ASCII = " << int('A')
         << " → binary " << toBinary8(int('A')) << "\n\n";

    // ---------- 2) Bitwise operators on concrete values ----------
    cout << "--- Bitwise operators (& | ^ << >> ~) ---\n";
    int a = 12, b = 10;
    cout << "a=" << a << " (" << toBinary8(a) << (a & 1 ? " odd" : " even") << "), "
         << "b=" << b << " (" << toBinary8(b) << ")\n";
    cout << "a & b  = " << (a & b)  << " " << toBinary8(a & b)  << "\n";
    cout << "a | b  = " << (a | b)  << " " << toBinary8(a | b)  << "\n";
    cout << "a ^ b  = " << (a ^ b)  << " " << toBinary8(a ^ b)  << "\n";
    cout << "a << 2 = " << (a << 2) << " " << toBinary8(a << 2) << "   (12*4=48)\n";
    cout << "a >> 1 = " << (a >> 1) << " " << toBinary8(a >> 1) << "   (12/2=6)\n";
    cout << "~(0)   = " << (~0) << "      (sab bits flip; -1 due to two's complement)\n";
    cout << "~12    = " << (~12) << "\n\n";

    // ---------- 3) Even / Odd via & ----------
    cout << "--- Even/Odd using (n & 1) ---\n";
    for (int x : {0, 3, 7, 14, 100})
        cout << x << (x & 1 ? " → Odd" : " → Even") << "\n";
    cout << "\n";

    // ---------- 4) Get / Set / Clear / Toggle kth bit on 12 (1100) ----------
    cout << "--- Get/Set/Clear/Toggle bit on 12 = " << toBinary8(12) << " ---\n";
    cout << "getBit(12, 2)   = " << getBit(12, 2)      << "\n";
    cout << "getBit(12, 0)   = " << getBit(12, 0)      << "\n";
    cout << "setBit(12, 0)   = " << setBit(12, 0)      << " " << toBinary8(setBit(12, 0))   << "\n";
    cout << "clearBit(12, 2) = " << clearBit(12, 2)    << " " << toBinary8(clearBit(12, 2)) << "\n";
    cout << "toggleBit(12,1) = " << toggleBit(12, 1)   << " " << toBinary8(toggleBit(12, 1)) << "\n";
    cout << "toggleBit(12,3) = " << toggleBit(12, 3)   << " " << toBinary8(toggleBit(12, 3)) << "\n\n";

    // ---------- 5) Count set bits: naive vs Kernighan ----------
    cout << "--- Count set bits of 12 & 255 ---\n";
    cout << "countSetBitsNaive(12)     = " << countSetBitsNaive(12)     << "\n";
    cout << "countSetBitsKernighan(12) = " << countSetBitsKernighan(12) << "\n";
    cout << "countSetBitsKernighan(255)= " << countSetBitsKernighan(255) << "  (8 bits on)\n\n";

    // ---------- 6) Power of two check ----------
    cout << "--- isPowerOfTwo ---\n";
    for (int x : {0, 1, 16, 18})
        cout << "isPowerOfTwo(" << x << ") = " << (isPowerOfTwo(x) ? "true" : "false") << "\n";
    cout << "\n";

    // ---------- 7) XOR magic: single non-repeating number ----------
    cout << "--- singleNumber in {1,2,3,2,1} ---\n";
    int arr[] = {1, 2, 3, 2, 1};
    cout << "Unique element = " << singleNumber(arr, 5) << "\n\n";

    // ---------- 8) XOR swap without temp ----------
    cout << "--- XOR swap (5, 9) ---\n";
    int x = 5, y = 9;
    cout << "Before: x=" << x << " y=" << y << "\n";
    x = x ^ y;              // x me dono ka mix
    y = x ^ y;              // y = (x^y)^y = x
    x = x ^ y;              // x = (x^y)^x = y
    cout << "After : x=" << x << " y=" << y << "\n\n";

    // ---------- Edge cases ----------
    cout << "--- Edge cases ---\n";
    cout << "0 binary = " << toBinary8(0) << ", countSetBits = 0\n";
    cout << "n>0 guard: isPowerOfTwo(0) = " << (isPowerOfTwo(0) ? "true" : "false")
         << " (0 has 0 bits → fail by design)\n";
    cout << "Note: negative numbers use two's complement in C++ — "
            "right shift on negative is implementation-defined (usually arithmetic), "
            "so count-set-bits/1<<31 loops need unsigned int for full safety.\n";
    // overflow guard: 1 << 31 wraps type; mul by 2 via << also overflows silently
    cout << "Overflow guard: (16 << 1) = " << (16 << 1)
         << " but for big ints << can wrap past int range silently.\n";
    return 0;
}