/*
═══════════════════════════════════════════════
 PRIMITIVE DATA STRUCTURE
 (int + float, char, double, bool, long, void)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A shop stores each product differently: quantity as a whole number
 (int), price as a decimal (float), category as one letter (char),
 "in stock" as a yes/no flag (bool). Each container has a fixed size —
 a cup cannot hold 2 litres and a jug cannot be squeezed into a cup.
 Primitive data types are exactly these fixed-size containers cooked
 into the language and the hardware. Choosing the right one decides how
 much memory you consume and how accurate your numbers are — the
 difference between 3.14 (float) and 3.14159265358979 (double).

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: A PRIMITIVE DATA STRUCTURE is a basic data type that the
   programming language provides directly. It holds a single value of a
   fixed size and is directly supported by the CPU's hardware — the CPU
   has instructions that operate on these types natively.
 - key points / properties:
   • Holds exactly ONE value at a time.
   • Fixed memory size (int is 4 bytes, char is 1 byte, etc.).
   • No user-defined methods can be added to a primitive.
   • int family: whole numbers (int, short, long, long long).
   • Floating family: real numbers with a decimal point (float, double).
   • char stores ONE character (1 byte, ASCII code internally).
   • bool stores true/false — internally 0 (false) or 1 (true).
   • void means "no value" — used for function return types, not variables.
   • Danger points: integer overflow (wraps around) and floating-point
     precision loss (0.1 + 0.2 ≠ 0.3 exactly!).

   Typical sizes & ranges (64-bit systems):
   ┌────────────┬────────────┬──────────────────────────┬──────────────────────┐
   │ Type       │ Size       │ Range                    │ Use when...          │
   ├────────────┼────────────┼──────────────────────────┼──────────────────────┤
   │ bool       │ 1 byte     │ true / false             │ flags, conditions    │
   │ char       │ 1 byte     │ -128 to 127 (signed)     │ single letters/codes │
   │ short      │ 2 bytes    │ -32768 to 32767          │ small counters       │
   │ int        │ 4 bytes    │ about -2.1e9 to 2.1e9    │ everyday counting    │
   │ long       │ 8 bytes    │ about -9.2e18 to 9.2e18  │ big numbers          │
   │            │ (Linux)    │ (Windows/MinGW has       │                     │
   │            │ 4 (MinGW)  │ 4-byte long ≈ same as int)│                    │
   │ long long  │ 8 bytes    │ same as long on 64-bit   │ very big numbers     │
   │ float      │ 4 bytes    │ ±3.4e38 (7 digit prec.)  │ quick decimals       │
   │ double     │ 8 bytes    │ ±1.7e308 (15 prec.)      │ accurate decimals    │
   │ void       │ —          │ no value                 │ return type only     │
   └────────────┴────────────┴──────────────────────────┴──────────────────────┘
 - when to use:
   • Count of items → int (or long if it can grow huge).
   • Price / measurement / percentage → double (float loses precision).
   • Single letter / ASCII code → char.
   • Yes/No, ON/OFF, valid/invalid → bool.
   • Function that returns nothing → void.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Print sizeof() of each primitive type.
         WHY: sizeof computes size in bytes at compile time — it shows
         exactly how much memory each primitive container claims.
 Step 2: Print the min/max range of int, char and the float family.
         WHY: Knowledge of ranges prevents overflow bugs; INT_MAX tells
         you the container's walls before you hit them.
 Step 3: Wrap an unsigned integer, to show what overflow does.
         WHY: When a container overflows, the value wraps around
         (max + 1 → 0 for unsigned). Seeing the wrap makes the limit real.
 Step 4: Add 0.1f and 0.2f with high precision display.
         WHY: Float stores approximate binary fractions; printing more
         digits reveals the stored inaccuracy (precision trap), which is
         why money should never be float.
 Step 5: Show bool's conversion rule (any non-zero → true).
         WHY: C++ treats 0 as false and any non-zero number as true;
         this subtle rule explains many "unexpected" if() results.

 VISUAL WALKTHROUGH: (fixed-size memory boxes)

   Addresses grow right →    low address                    high address
                            ┌──────────────────────────┐
   int (4 bytes)           │ 0x2A  | 0x00 |0x00 |0x00  │  42 stored in 4 bytes
                            └──────────────────────────┘
                            ┌──────┐
   char (1 byte)           │ 0x41 │   'A' (ASCII 65)
                            └──────┘
                            ┌────────────────────────────────────┐
   double (8 bytes)        │ sign | exponent | ... | mantissa ...│  3.14 ≈ 8 bytes
                            └────────────────────────────────────┘
                            ┌──────┐
   bool (1 byte)           │ 0x01 │   true (=1), false (=0)
                            └──────┘
   Overflow wrap:   max → 255 (1 byte) → +1 → 0 (wraps to other wall)

 DRY RUN: (full trace of the demo below)
   Sizes print (this MinGW/Windows compile — note long = 4, the Windows
   convention; on 64-bit Linux long = 8):
     sizeof(int)=4, sizeof(char)=1, sizeof(float)=4,
     sizeof(double)=8, sizeof(bool)=1, sizeof(long)=4

   Ranges print:
     int   : INT_MIN to INT_MAX  →  -2147483648 to 2147483647
     char  : -128 to 127
     float : FLT_MIN to FLT_MAX
     double: DBL_MIN to DBL_MAX

   Overflow edge case:
     unsigned int big = UINT_MAX (=4294967295)
     big + 1     → 0          (wrap-around: largest becomes smallest)
     10 * big    → 4294967286 (10×big mod 2^32 = 42949672950 − 9×4294967296)

   Precision edge case:
     0.1f + 0.2f → 0.30000001192092895508   (float error ~1.2e-8)
     0.1  + 0.2  → 0.30000000000000004441   (double error ~4.4e-17)
     Both differ from the true 0.3 — proof that float/double are approximate.

   Bool edge case:
     bool flag = 5  → prints true   (any non-zero converts to true)

 TIME COMPLEXITY CALCULATION:
   - Each sizeof() call resolves at compile time            → 1 step each
   - Each cout print of a fixed value                       → 1 step each
   - Overflow and precision arithmetic are single hardware
     instructions (addition/multiplication performed once)  → 1 step each
   - Total work is a FIXED number of steps regardless of input size — 
     there is no loop over user-provided data, so the step count is a
     small constant c (approx 15-20 operations here).
 → Time Complexity = O(1)   (constant time — no dependence on input size)

 SPACE COMPLEXITY CALCULATION:
   - Variables used: big (4 bytes), flag (1 byte), f (4 bytes),
     d (8 bytes), plus a few literals computed by the compiler
   - All sizes are compile-time constants, independent of any input
   - No array, no dynamic allocation
   - Total memory used ≈ handful of bytes (constant)
 → Space Complexity = O(1)   (constant space — fixed, tiny footprint)

 APPROACH COMPARISON: (memories of the primitive family)
 ┌────────────────────┬─────────────────────────────────────────────────────────┐
 │ Type               │ Character / use                                         │
 ├────────────────────┼─────────────────────────────────────────────────────────┤
 │ char / bool        │ 1 byte, smallest — flags and single characters          │
 │ short / int        │ whole numbers — counters, indexes, array sizes          │
 │ long / long long   │ bigger whole numbers — population, big computations     │
 │ float              │ 4-byte decimal — fast but only ~7 accurate digits       │
 │ double             │ 8-byte decimal — the default for money/applied math     │
 │ void               │ "nothing" — return type for functions with no value     │
 └────────────────────┴─────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <limits>
using namespace std;

int main() {
    cout << "=== Size (bytes) of each primitive type ===\n";
    cout << "sizeof(int)    = " << sizeof(int)    << " bytes\n";
    cout << "sizeof(char)   = " << sizeof(char)   << " bytes\n";
    cout << "sizeof(float)  = " << sizeof(float)  << " bytes\n";
    cout << "sizeof(double) = " << sizeof(double) << " bytes\n";
    cout << "sizeof(bool)   = " << sizeof(bool)   << " bytes\n";
    cout << "sizeof(long)   = " << sizeof(long)   << " bytes\n";

    cout << "\n=== Range of each primitive family ===\n";
    cout << "int    : " << INT_MIN << " to " << INT_MAX << "\n";
    cout << "char   : " << (int)CHAR_MIN << " to " << (int)CHAR_MAX << " (signed char)\n";
    cout << "float  : " << FLT_MIN << " to " << FLT_MAX << "\n";
    cout << "double : " << DBL_MIN << " to " << DBL_MAX << "\n";

    cout << "\n=== Edge case 1: integer overflow (wrap-around) ===\n";
    unsigned int big = numeric_limits<unsigned int>::max();   // 4294967295
    cout << "UINT_MAX     = " << big << "\n";
    cout << "UINT_MAX + 1 = " << big + 1 << "   (wrap ho gaya → 0)\n";
    cout << "10 * UINT_MAX = " << 10u * big << "   (overflow mod 2^32)\n";

    cout << "\n=== Edge case 2: floating-point precision loss ===\n";
    cout << setprecision(20);   // chhupa hua precision dikhane ke liye
    float fsum = 0.1f + 0.2f;
    double dsum = 0.1 + 0.2;
    cout << "0.1f + 0.2f (float)  = " << fsum << "\n";
    cout << "0.1  + 0.2  (double) = " << dsum << "\n";

    cout << "\n=== Edge case 3: bool conversion rule ===\n";
    bool flag = 5;               // koi bhi non-zero → true
    cout << "bool flag = 5  →  " << (flag ? "true" : "false") << "\n";
    bool zero = 0;               // sirf 0 false hota hai
    cout << "bool zero = 0  →  " << (zero ? "true" : "false") << "\n";

    return 0;
}