/*
═══════════════════════════════════════════════
 46_Bit_Manipulation — &, |, ^, <<, >>, ~
 ⏱️ TIME COMPLEXITY: derive + state below. NEVER bare O(?).
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Every Linux file carries a permission triplet — rwx for owner, group,
 others — packed into a single 9-bit number. Enable "write" means set one
 bit; revoke it means clear one bit; check whether the owner may execute
 means test one bit. A railway ticket booking system uses a 32-bit int as
 a seat-map: bit i = 1 says seat i is booked, 0 says free — booking is one
 `|`, cancel is one `&~`. Games use a "flags" integer where bit 0 = isJump,
 bit 1 = isCrouch, bit 2 = isRun, so one byte stores eight on/off states
 that the physics engine reads in a single `&` check. These are the exact
 operations — bitwise AND/OR/XOR, shift, NOT, masking — that make any
 single on/off state cost 1 bit instead of 1 byte.

 📖 THEORY: (pure English, beginner-level)
 - A bit is 0 or 1. An int is 32 bits (on most compilers), indexed from
   0 (least significant, rightmost) to 31 (sign bit, leftmost). Example:
   decimal 12 = 8 + 4 = 1100₂.

   Binary of 12  (bit 3 = 1×8, bit 2 = 1×4, bit 1 = 0×2, bit 0 = 0×1):
        bit index   3  2  1  0
        value       8  4  2  1
        12         = 1  1  0  0   →   8+4 = 12 ✓

 - OPERATORS (bit-by-bit, not logical &&/||):
   *  AND  `a & b`  → 1 only when BOTH bits are 1. Used to CHECK/MASK.
   *  OR   `a | b`  → 1 when AT LEAST ONE bit is 1. Used to SET a bit.
   *  XOR  `a ^ b`  → 1 when the two bits DIFFER. Used to TOGGLE.
   *  NOT  `~a`     → flips every bit (0↔1). With mask → CLEAR a bit.
   *  SHIFT `a << k` → move all bits LEFT k slots, spill left bits out,
     zeroes fill the right → MULTIPLY by 2^k.
   *  SHIFT `a >> k` → move RIGHT k slots (logical shift fills 0 on top
     for unsigned) → DIVIDE by 2^k (floor).
 - MASKING pattern with the single-bit mask `1 << i`:
       skip  (x &  (1<<i)) != 0    or SET: x = x | (1<<i)
       CLEAR x = x & ~(1<<i)       TOGGLE: x = x ^ (1<<i)
   Read as: `1<<i` is a light-switch at position i; & reads it, | turns
   it on, &~ turns it off, ^ flips it.
 - XOR SUPERPOWERS: `a ^ a == 0`, `a ^ 0 == a`, so XOR is its own
   inverse: `(a^b)^b == a`. Swap without a temp: a^=b; b^=a; a^=b;
   (works only on distinct variables). Find unpaired number: XOR the
   whole array — pairs cancel, the loner remains.
 - COUNT SET BITS: `__builtin_popcount(x)` is a single CPU instruction
   (POPCNT) on modern x86 → O(1). Hand-written `while(x){ cnt += x&1;
   x >>= 1; }` loops 32 times. Brian Kernighan: `while(x){ x &= x-1;
   cnt++; }` — each iteration strips the lowest set bit → saves exactly
   popcount iterations.
 - POWER OF TWO check: `(x & (x-1)) == 0` — subtracting 1 turns
   "1000…0" into "0111…1", so the AND is 0 ONLY for one-bit numbers.
   0 is a special case (0 & -1 == 0) — check x>0 first.
 - When to use: compact flags/permissions, fast multiply/divide by 2^k,
   parity/finding single non-repeating element, memory-efficient
   presence-sets, game state packing.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Build the MASK `1<<i` for bit position i (0-indexed). WHY: the
         only bit that is 1 sits exactly at i, so AND/OR/XOR against x
         touches exactly that bit and nothing else.
 Step 2: CHECK → `(x & mask) != 0`. WHY: AND keeps bit i as-is and zeros
         everything else; the whole expression is non-zero iff bit i is 1.
 Step 3: SET → `x = x | mask`. WHY: OR forces bit i to 1; all other bits
         keep their value because 0 | bit = bit.
 Step 4: CLEAR → `x = x & ~mask`. WHY: ~mask has 0 exactly at i, so AND
         zeroes that bit and copies every other bit through.
 Step 5: TOGGLE → `x = x ^ mask`. WHY: XOR with 1 flips a bit, with 0
         leaves it — exactly the on/off switch behaviour wanted.
 Step 6: To test power-of-two, strip set bits, or count them, use the
         arithmetic identity `x & (x-1)` (removes lowest set bit) and
         reuse it. WHY: derived from how subtracting 1 borrows through
         trailing zeroes — one cheap operation replaces a loop.

 VISUAL WALKTHROUGH — set/check/toggle bit 2 of 12 = 1100₂:
   mask = 1<<2 = 0100₂ = 4

   check  12 & 4  =  1100 & 0100  = 0100(≠0) → bit 2 SET ✓
   clear  12 &~4  =  1100 & 1011  = 1000 = 8  (bit 2 cleared)
   toggle  8 ^ 4  =  1000 ^ 0100  = 1100 = 12 (waapas set)
   set    12 | 4  =  1100 | 0100  = 1100 = 12 (already set, same)

   isPowerOfTwo(8):  8 = 1000,  8-1 = 0111,  1000 & 0111 = 0000 → true
   isPowerOfTwo(6):  6 = 0110,  6-1 = 0101,  0110 & 0101 = 0100 → false

   XOR-pair cancellation:            XOR swap a=5(0101), b=3(0011):
   v = [3, 7, 3, 5, 7]                a=0101^0011=0110(6)
   XOR all: 3^7^3^5^7                 b=0110^0011=0101(5)
          = (3^3)^(7^7)^5            a=0110^0101=0011(3)
          = 0 ^ 0 ^ 5 = 5 ✓           → a=3, b=5 SWAPPED ✓

   right shift = divide by 2:          left shift = multiply by 2:
   14 = 1110  →  14>>1 = 0111 = 7      7 = 0111 → 7<<1 = 1110 = 14
   (drop the rightmost bit, all move right) (all move left, 0 comes in on the right)

 DRY RUN — demo with x=12 (1100₂), then edge cases:
   binary(12): loop bit 31..0 print 1/0 → ...00001100 bits 3,2 = 1
   isBitSet(12, 2) → (1100 & 0100)=0100 → true
   isBitSet(12, 0) → (1100 & 0001)=0000 → false
   setBit(12,0)    → 1100 | 0001 = 1101 = 13
   clearBit(12,2)  → 1100 & 1011 = 1000 = 8
   toggleBit(12,3) → 1100 ^ 1000 = 0100 = 4
   popcount(12)=2; popcount(-1)=32 (two's complement all-ones)
   isPowerOfTwo(0) → handled x>0 guard → false; (16)→ true
   shiftDemo: 7<<2 = 28 (×4 = 7×4);  28>>2 = 7 (÷4)
   xorSwap(5,3) → (3,5)

 TIME COMPLEXITY CALCULATION:
 - Single-bit check/set/clear/toggle: one &/|/^/~ on a fixed-width int —
   every bit is processed in parallel by the ALU → O(1) regardless of x.
 - Printing all bits: loop 32 iterations, each an O(1) shift+mask, and 32
   is FIXED by the type width (never grows with x) → O(1) effectively
   (more precisely O(number of bits) = O(32)).
 - __builtin_popcount: single CPU POPCNT instruction → O(1).
 - Hand-rolled popcount `while(x){x>>=1}`: one shift+mask per bit → at
   most 32 iterations → O(32) = O(1) fixed-width (or O(b) with b = bit
   length).
 - Kernighan `x &= x-1`: runs once per SET bit → O(popcount) ≤ O(32) = O(1).
 - isPowerOfTwo via x&(x-1): one subtraction + one AND → O(1).
 - XOR swap: three O(1) XORs → O(1).
 → Time Complexity = O(1) for every bit trick (fixed 32-bit word); a
   full scan is O(32) or O(b) where b is the number of bits, still
   constant for fixed-width ints.

 SPACE COMPLEXITY CALCULATION:
 - Bit tricks mutate a single int in registers — no array, no recursion →
   O(1) auxiliary space.
 - The parity/unique-number XOR solution needs no extra storage beyond
   one accumulator variable → O(1) beyond the input array itself.
 → Space Complexity = O(1) auxiliary for all operations; O(n) only to
   hold the problem's input array itself.

 APPROACH COMPARISON:
 ┌────────────────────────┬───────────────────────────────┬──────────────────────────────┐
 │ Task                   │ Naive / arithmetic            │ Bit trick                    │
 ├────────────────────────┼───────────────────────────────┼──────────────────────────────┤
 │ Check bit i            │ loop divide by 2 i times      │ (x & (1<<i)) != 0 — O(1)     │
 │ Multiply by 2^k        │ x * (1<<k) (still fine)       │ x << k — 1 ALU op            │
 │ Divide by 2^k          │ x / (1<<k)                    │ x >> k — 1 ALU op            │
 │ Count set bits         │ loop all 32 bits              │ __builtin_popcount O(1)      │
 │ Is power of two        │ loop / math log2 (floating!)  │ x>0 && (x&(x-1))==0 O(1)     │
 │ Swap two ints          │ temp variable (3 copies)      │ a^=b;b^=a;a^=b (no temp)     │
 │ Unique in array        │ hash-map O(n) space           │ XOR all — O(1) space         │
 └────────────────────────┴───────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
#include <vector>

using namespace std;

// binary representation print — bit 31 se 0 tak, type width ke hisaab se
void printBinary(int x) {
    cout << "   binary(" << x << ") = ";
    for (int i = 31; i >= 0; --i)          // fixed 32 bits, har bit O(1)
        cout << ((x >> i) & 1);            // ith bit alag karke dikhao
    cout << "\n";
}

bool isBitSet(int x, int i)  { return (x & (1 << i)) != 0; }
int  setBit(int x, int i)    { return x |  (1 << i); }
int  clearBit(int x, int i)  { return x & ~(1 << i); }   // ~ = sab flip
int  toggleBit(int x, int i) { return x ^  (1 << i); }

// hand-rolled count — har bar sahi bit shift karke dekho
int popcountManual(int x) {
    int cnt = 0;
    while (x) {              // 0 hone tak chalao (negative bhi isi me)
        cnt += (x & 1);      // last bit 1?
        x >>= 1;             // agla bit lane ko right shift
    }
    return cnt;
}

// Kernighan — har iteration ek set bit hata ta hai (x & x-1)
int popcountKernighan(int x) {
    int cnt = 0;
    while (x) { x &= (x - 1); ++cnt; }   // lowest set bit erase
    return cnt;
}

bool isPowerOfTwo(int x) {
    // 0 ka special case — 0 & -1 = 0 galat true de deta
    return x > 0 && (x & (x - 1)) == 0;
}

int main() {
    cout << "---- BIT REPRESENTATION ----\n";
    printBinary(12);         // 1100 — bit 3 + bit 2
    printBinary(7);          // 0111

    cout << "\n---- CHECK / SET / CLEAR / TOGGLE (x = 12, mask 1<<i) ----\n";
    cout << "isBitSet(12, 2)  : " << (isBitSet(12, 2) ? "true" : "false")
         << "   (1100 & 0100 != 0)\n";
    cout << "isBitSet(12, 0)  : " << (isBitSet(12, 0) ? "true" : "false")
         << "   (1100 & 0001 == 0)\n";
    cout << "setBit(12, 0)    : " << setBit(12, 0) << "\n";
    cout << "clearBit(12, 2)  : " << clearBit(12, 2) << "   (1100 & 1011 = 1000)\n";
    cout << "toggleBit(12, 3) : " << toggleBit(12, 3) << "   (1100 ^ 1000 = 0100)\n";

    cout << "\n---- COUNT SET BITS ----\n";
    cout << "popcountManual(12)   (hand loop): " << popcountManual(12) << "\n";
    cout << "popcountKernighan(12) (x&x-1)   : " << popcountKernighan(12) << "\n";
    cout << "__builtin_popcount(12)  [O(1) CPU]: "
         << __builtin_popcount(12) << "\n";
    cout << "popcount(-1)              [edge]: "
         << __builtin_popcount(-1) << "   (two's-complement sab bits 1)\n";

    cout << "\n---- POWER OF TWO ----\n";
    for (int v : {0, 1, 2, 8, 12, 16, 100}) {
        cout << "isPowerOfTwo(" << v << ") : "
             << (isPowerOfTwo(v) ? "true" : "false") << "\n";
    }

    cout << "\n---- LEFT/RIGHT SHIFT = ×/÷ by 2^k ----\n";
    cout << "7 << 2  = " << (7 << 2)  << "   (7 × 4)\n";
    cout << "28 >> 2 = " << (28 >> 2) << "   (28 ÷ 4)\n";

    cout << "\n---- XOR TRICKS ----\n";
    cout << "12 ^ 12 = " << (12 ^ 12) << "   (a^a=0)\n";
    cout << "12 ^ 0  = " << (12 ^ 0)  << "   (a^0=a)\n";

    // XOR swap — teen XOR, koi temp nahi
    int a = 5, b = 3;
    cout << "swap before: a=" << a << " b=" << b << "  ";
    a ^= b;  b ^= a;  a ^= b;            // Hinglish: har XOR ek stage
    cout << " after: a=" << a << " b=" << b << "\n";

    // unique number — pairs XOR hokar 0 ho jate, akela reh jata
    vector<int> arr = {3, 7, 3, 5, 7, 9, 5};
    int loner = 0;
    for (int x : arr) loner ^= x;        // same pairs cancel
    cout << "unique in {3,7,3,5,7,9,5} = " << loner << "\n";

    cout << "\n[EDGE] negative & 0\n";
    cout << "popcountManual(-1) : " << popcountManual(-1) << "\n";
    printBinary(0);                      // sab zero
    cout << "isBitSet(0, 5) : " << (isBitSet(0, 5) ? "true" : "false") << "\n";

    return 0;
}