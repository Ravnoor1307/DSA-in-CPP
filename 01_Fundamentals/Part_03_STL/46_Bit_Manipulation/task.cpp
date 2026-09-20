/*
═══════════════════════════════════════════════
 TASK SET — 46_Bit_Manipulation
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Servers store permissions as raw bits; a seat-map
is one int; the game player flags are bits. So every bit task is a real
bookkeeping job: check, set, clear, toggle, count, or find the loner.
🧠 HOW TO SOLVE: translate the action word into its bit-trick — "is it a
power of two?" → `x & (x-1)`; "count ones" → Kernighan / builtin_popcount;
"toggle" → `x ^ (1<<i)`; "clear" → `x & ~(1<<i)`. XOR for the unpaired
element. Always guard x>0 and mind the arithmetic of int (negative → 32
bits in two's complement).
═══════════════════════════════════════════════
*/

// ---------------- TASK 1: EASY — Is it a Power of Two? ----------------
// Sample: {1, 2, 3, 8, 16, 7, 0} — print true only for exact powers of 2.
// 💡 HINT: x>0 && (x & (x-1)) == 0 is the one-liner. 0 special-case it!
// ✏️ STARTER CODE:
//   #include <iostream>
//   using namespace std;
//   bool isPowerOfTwo(int x) {
//       // TODO: return the bit condition
//   }
//   int main() {
//       for (int v : {1, 2, 3, 8, 16, 7, 0})
//           cout << v << " -> " << (isPowerOfTwo(v) ? "yes" : "no") << "\n";
//   }

// ---------------- TASK 2: EASY-MEDIUM — Count Set Bits ----------------
// Sample: count the 1-bits of {5, 7, 15, 255} → 2, 3, 4, 8.
// 💡 HINT: Kernighan: while(x){ x &= x-1; cnt++; } — ek call = ek bit gaya.
//          __builtin_popcount bhi chalega.
// ✏️ STARTER CODE:
//   #include <iostream>
//   using namespace std;
//   int countBits(int x) {
//       int cnt = 0;
//       // TODO: har iteration lowest set bit hatao
//       return cnt;
//   }
//   int main() {
//       for (int v : {5, 7, 15, 255})
//           cout << v << " has " << countBits(v) << " set bits\n";
//   }

// ---------------- TASK 3: MEDIUM — Toggle the k-th Bit ----------------
// Sample: toggle bit 2 of 12 (1100) → 1000 = 8; toggle again → 12.
// Same call gives flip-flop on/off — the light-switch.
// 💡 HINT: return x ^ (1 << k);
// ✏️ STARTER CODE:
//   #include <iostream>
//   using namespace std;
//   int toggleBit(int x, int k) {
//       // TODO: XOR with mask 1<<k
//   }
//   int main() {
//       int n = 12;
//       n = toggleBit(n, 2);   // 8
//       cout << n << "\n";
//       n = toggleBit(n, 2);   // 12 waapas
//       cout << n << "\n";
//   }

// ---------------- TASK 4: MEDIUM-HARD — XOR Swap without temp ----------------
// Sample: a=9, b=4 → after swap a=4, b=9. No third variable, only ^.
// 💡 HINT: a ^= b; b ^= a; a ^= b;  — teen XOR ka dance.
// ✏️ STARTER CODE:
//   #include <iostream>
//   using namespace std;
//   int main() {
//       int a = 9, b = 4;
//       // TODO: swap using ONLY ^ (no temp)
//       cout << a << " " << b << "\n";
//   }

// ---------------- TASK 5: HARD — Find the Unique Number (XOR) ----------------
// Sample: {4, 1, 2, 1, 2} — every number appears twice except one;
// find the one that appears exactly once. Output 4.
// Complexity O(n) time, O(1) space.
// 💡 HINT: XOR the whole array — a^a cancels, the unpaired one survives.
// ✏️ STARTER CODE:
//   #include <iostream>
//   #include <vector>
//   using namespace std;
//   int main() {
//       vector<int> v = {4, 1, 2, 1, 2};
//       int ans = 0;
//       // TODO: for loop me sab XOR karo
//       cout << ans << "\n";
//   }

// ---------------- TASK 6: HARD — Toggle the k-th bit of a NUMBER
// (revisit) plus parity — count 1s, print ODD/EVEN ----------------
// Sample: {3(binary 11), 7(111), 8(1000), 10(1010)} → parity odd, odd,
// odd(?) 8 has one bit → ODD, 10 has two → EVEN.
// 💡 HINT: parity = popcount & 1. Kernighan loop se count karke %2.
// ✏️ STARTER CODE:
//   #include <iostream>
//   using namespace std;
//   int main() {
//       for (int v : {3, 7, 8, 10}) {
//           int cnt = 0, m = v;
//           while (m) { /* TODO: strip lowest bit */ }
//           cout << v << " bits=" << cnt
//                << (cnt % 2 ? " ODD" : " EVEN") << "\n";
//       }
//   }

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>

using namespace std;

// ---------- SOLUTION 1 ----------
// power of two — ek AND aur ek minus, O(1)
void sol1() {
    cout << "\n=== TASK 1 ===\n";
    auto isPow2 = [](int x) { return x > 0 && (x & (x - 1)) == 0; }; // 0 guard
    for (int v : {1, 2, 3, 8, 16, 7, 0})
        cout << v << " -> " << (isPow2(v) ? "yes" : "no") << "\n";
}

// ---------- SOLUTION 2 ----------
// Kernighan — utne hi iteration jitne set bits, worst 32
void sol2() {
    cout << "\n=== TASK 2 ===\n";
    auto countBits = [](int x) {
        int cnt = 0;
        while (x) { x &= (x - 1); ++cnt; }  // lowest 1-bit hatao
        return cnt;
    };
    for (int v : {5, 7, 15, 255})
        cout << v << " has " << countBits(v) << " set bits\n";
}

// ---------- SOLUTION 3 ----------
// toggle — XOR dengan mask, flips exactly one bit
void sol3() {
    cout << "\n=== TASK 3 ===\n";
    auto toggleBit = [](int x, int k) { return x ^ (1 << k); };
    int n = 12;
    n = toggleBit(n, 2);                 // 1100 ^ 0100 = 1000
    cout << "after toggle bit2 : " << n << "\n";
    n = toggleBit(n, 2);                 // 1000 ^ 0100 = 1100
    cout << "toggle waapas      : " << n << "\n";
}

// ---------- SOLUTION 4 ----------
// XOR swap — teen XOR, koi temp nahi, O(1)
void sol4() {
    cout << "\n=== TASK 4 ===\n";
    int a = 9, b = 4;
    a ^= b;  b ^= a;  a ^= b;            // a→a^b, b→(a^b)^b=a, a→(a^b)^a=b
    cout << "a=" << a << " b=" << b << "\n";
}

// ---------- SOLUTION 5 ----------
// single number — O(n) XOR fold, O(1) extra space
void sol5() {
    cout << "\n=== TASK 5 ===\n";
    vector<int> v = {4, 1, 2, 1, 2};
    int ans = 0;
    for (int x : v) ans ^= x;            // jodi cancel, akela bach gaya
    cout << "unique = " << ans << "\n";
}

// ---------- SOLUTION 6 ----------
// parity — Kernighan count % 2
void sol6() {
    cout << "\n=== TASK 6 ===\n";
    for (int v : {3, 7, 8, 10}) {
        int cnt = 0, m = v;
        while (m) { m &= (m - 1); ++cnt; }   // set bits count
        cout << v << " bits=" << cnt
             << (cnt % 2 ? " ODD" : " EVEN") << "\n";
    }
}

int main() {
    sol1();
    sol2();
    sol3();
    sol4();
    sol5();
    sol6();
    return 0;
}