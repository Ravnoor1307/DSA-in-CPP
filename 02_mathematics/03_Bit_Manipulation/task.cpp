/*
═══════════════════════════════════════════════
 TASK SET — BIT MANIPULATION
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: You are building a tiny settings store that packs 8
flags into a single byte (dark mode ON, notifications ON, autoplay OFF...).
You must read one flag, flip another, tell how many flags are ON, and find the
one guest whose ID got duplicated mismatched at a party. All of it is just bit work.
🧠 HOW TO SOLVE: always think in masks — 1 << k isolates bit k. AND reads,
OR sets, XOR toggles/cancels, ~n flips. Even/odd → n & 1. Power of two → one set bit
→ (n & (n-1)) == 0. Duplicate cancelling → a ^ a = 0. Kernighan clears lowest set bit.
 5-6 tasks EASY → HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/
#include <iostream>
using namespace std;

// ---------------- SOLUTIONS ----------------

/* ---------- TASK (a): Check even/odd using (n & 1) ----------
   💡 HINT: sabse last bit (1's place) hi decide karti hai parity. 1 & n.
   ✏️ STARTER CODE:
      int n; cin >> n;
      if ( ______ ) cout << "Odd"; else cout << "Even";   // kya condition likhni hai?
*/
void task_a_evenOdd() {
    int n = 15;
    if (n & 1)
        cout << n << " is Odd (last bit is 1)\n";
    else
        cout << n << " is Even (last bit is 0)\n";
    // EXPLANATION: 1 = binary 0001. n & 1 sirf last bit chhodta hai.
    // 15 = 1111 → 1111 & 0001 = 0001 = 1 → Odd. 14 = 1110 & 0001 = 0 → Even.
}

/* ---------- TASK (b): Count set bits — naive loop + Kernighan trick ----------
   💡 HINT: naive har bit check karo (32 iters). Kernighan: n = n & (n-1)
          har iteration me lowest 1-bit clean kar deta hai, loop itni baar chalta
          hai jitne set bits hain.
   ✏️ STARTER CODE:
      int cnt = 0;
      while (n) { n = n & (n - 1); ______ ; }
*/
void task_b_countSetBits() {
    int n = 13;               // 1101 → 3 set bits
    int naive = 0;
    for (int i = 0; i < 32; ++i)
        if ((n >> i) & 1) ++naive;

    int kern = 0, m = n;
    while (m) {
        m = m & (m - 1);       // lowest 1-bit uda diya
        ++kern;
    }
    cout << "countSetBits(13): naive=" << naive << ", Kernighan=" << kern << "\n";
    // EXPLANATION: naïf 32 bit scan karta hai; Kernighan keval 3 iterations
    // (jab bit 3, 2, 0 clear hue). Har iteration ek set bit delete karti hai.
}

/* ---------- TASK (c): Power of two check ----------
   💡 HINT: power of 2 ka exactly ONE set bit hota hai (1=1, 2=10, 4=100, 8=1000).
          n-1 vo bit aur uske neeche sab flip kar deta hai → n & (n-1) = 0.
          0 ka dhyan rakhna: n > 0 zaroori.
   ✏️ STARTER CODE:
      return n > 0 && (n & (n - 1)) == ______;
*/
void task_c_powerOfTwo() {
    for (int n : {0, 1, 16, 18, 64})
        cout << "isPowerOfTwo(" << n << ") = "
             << (n > 0 && (n & (n - 1)) == 0) << "\n";
    // EXPLANATION: 16=10000, 15=01111 → 10000&01111=0 → true.
    // 18=10010, 17=10001 → 10010&10001=10000 ≠0 → false. 0 ko guard n>0 rokta hai.
}

/* ---------- TASK (d): Single non-repeating number in array (XOR) ----------
   💡 HINT: a ^ a = 0 aur a ^ 0 = a. Saare elements XOR karo —
          duplicate pairs cancel ho jayenge, sirf unique bachega.
   ✏️ STARTER CODE:
      int res = 0;
      for (int v : arr) res = res ______ v;   // XOR operator lagao
*/
void task_d_singleNumber() {
    int arr[] = {4, 1, 2, 1, 2};      // 4 unique hai (baaki pairs hain)
    int res = 0;
    for (int v : arr) {
        res ^= v;
        cout << "accumulate " << v << " → " << res << "\n";
    }
    cout << "Single number = " << res << "\n";
    // EXPLANATION: (1^1)=0 aur (2^2)=0 khud cancel ho gaye; res = 0^4 = 4.
    // O(n) time, O(1) extra space — hashmap nahi chahiye.
}

/* ---------- TASK (e): Swap two numbers without temp (XOR swap) ----------
   💡 HINT: teen XOR. x=x^y; y=x^y (=x); x=x^y (=y).
          Reversibility: (a^b)^b = a.
   ✏️ STARTER CODE:
      x = x ^ y;
      y = ______;
      x = ______;
*/
void task_e_xorSwap() {
    int x = 5, y = 9;
    cout << "Before: x=" << x << " y=" << y << "\n";
    x = x ^ y;        // x = 5^9 = 1100 (12)
    y = x ^ y;        // y = (5^9)^9 = 5 → x mil gaya
    x = x ^ y;        // x = (5^9)^5 = 9 → y mil gaya
    cout << "After : x=" << x << " y=" << y << "\n";
    // EXPLANATION: XOR reversible hai, samajhna 1100 ke saath:
    // x=0101, y=1001 → 0101^1001=1100; 1100^1001=0101(=5); 1100^0101=1001(=9).
}

/* ---------- TASK (f): Find rightmost set bit (lowest set bit) ----------
   💡 HINT: n & (-n) akele lowest 1-bit ko alag kar deta hai.
          (two's complement me -n = ~n + 1). Uska log2 ya loop se position batao.
   ✏️ STARTER CODE:
      int last = n & (-n);              // e.g. 12(1100) → 4(0100)
      int pos = 0; while ( ______ ) { ++pos; }
*/
void task_f_rightmostSetBit() {
    int n = 40;                       // 101000 → rightmost bit = 8 (1000), pos 3
    int last = n & (-n);
    int pos = 0, t = last;
    while (t > 1) { t >>= 1; ++pos; }
    cout << "n=40 (" << "101000) rightmost set bit = " << last
         << " at position " << pos << "\n";
    // EXPLANATION: 40 & -40 = 101000 & 011000 = 001000 = 8.
    // -n = ~n + 1 two's complement → n & -n uda kar rkh deta hai newt lowest 1.
}

/* ---------- TASK (g): Bits to change to convert a → b ----------
   💡 HINT: jahan bits alag hain wahi change karni padengi. XOR = "different place"
          detector. To phir sirf countSetBits(a ^ b) karo.
   ✏️ STARTER CODE:
      int diff = a ^ b;                // alag bits wali jagah par 1
      int cnt = 0; while (diff) { diff = diff & (diff - 1); cnt++; }
*/
void task_g_bitChangeCount() {
    int a = 29, b = 15;
    // 29 = 11101, 15 = 01111 → diff = 10010 → 2 bits change karni padengi
    int diff = a ^ b;
    int cnt = 0;
    while (diff) {
        diff = diff & (diff - 1);
        ++cnt;
    }
    cout << "Bits to flip to convert 29 to 15 = " << cnt << "\n";
    // EXPLANATION: XOR "differences" flag karta hai (29^15=10010=18, 2 set bits).
    // Kernighan count = 2. Kabhi bhi XOR ke set bits = number of differing bits.
}

int main() {
    task_a_evenOdd();
    task_b_countSetBits();
    task_c_powerOfTwo();
    task_d_singleNumber();
    task_e_xorSwap();
    task_f_rightmostSetBit();
    task_g_bitChangeCount();
    return 0;
}