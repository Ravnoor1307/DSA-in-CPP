/*
═══════════════════════════════════════════════
 TASKS — PLOTTING COMMON FUNCTIONS / GROWTH OF FUNCTIONS
═══════════════════════════════════════════════

 THEORY RECAP (use it to guide your solutions):
   Growth hierarchy:  1 < log₂n < n < n log₂n < n² < n³ < 2ⁿ < n!
   The ordering strictly holds only for SUFFICIENTLY LARGE n.
   Task 1 checks this against ACTUAL values at a given n.
   Task 2 finds exactly where the hierarchy is "true".
   Task 3 practises the overflow-aware printing used in the theory demo.

   Two ground rules for all tasks:
     (a) Work with long long (not int) to survive 32-bit overflow.
     (b) Guard factorial and 2ⁿ — print overflow markers, never garbage.

──────────────────────────────────────────
 TASK 1 — ORDER THE 8 FUNCTIONS AT A GIVEN n
──────────────────────────────────────────
 Problem:
   Read an integer n from the user. Compute the actual values of
   1, log₂n, n, n·log₂n, n², n³, 2ⁿ, n! at that n, then sort and
   print them from SMALLEST to LARGEST. If any value overflows a
   long long, print it as "+inf" and place it last (it is huge).

 💡 HINT: sorting by raw values overflows at n=21 (n!) and n=63 (2ⁿ).
          Sort instead by a log-scale key log₂(value) — monotonic and
          overflow-free — and only RE-COMPUTE exact values for display.

 ✏️ STARTER CODE:
   #include <iostream>
   #include <string>
   using namespace std;
   int main() {
       long long n;
       cout << "enter n: ";
       cin >> n;
       // yahan compute karo: log2n, n, nlogn, n2, n3, 2^n, n!
       // phir sort karke print karo smallest → largest
       return 0;
   }

──────────────────────────────────────────
 TASK 2 — FIND THE CROSSOVER POINT 2ⁿ vs n³ (and n! vs 2ⁿ)
──────────────────────────────────────────
 Problem:
   For small n, n³ can be BIGGER than 2ⁿ (e.g. n=10: 1000 > 1024? no —
   1024 > 1000 already! try n=2,4,8,10,12,16). Find the SMALLEST n≥1
   such that 2ⁿ > n³. After that, find the smallest n such that
   n! > 2ⁿ (classical race between exponential and factorial).

 💡 HINT: iterate n upward from 1; compare with long double to avoid
          overflow: 2ⁿ and n! both reach astronomic scale fast. Use
          pow(2.0, n) vs pow(n, 3.0) or log-based comparisons.

 ✏️ STARTER CODE:
   #include <iostream>
   #include <cmath>
   using namespace std;
   int main() {
       // crossover loop for 2^n > n^3
       for (int n = 1; ; n++) {
           // double lhs = pow(2, n); double rhs = pow(n, 3);
           // jab tak lhs <= rhs, loop badhaate jao
           // jab lhs > rhs → print n aur break
       }
       return 0;
   }

──────────────────────────────────────────
 TASK 3 — EXTENDED VALUE TABLE UP TO n = 64
──────────────────────────────────────────
 Problem:
   Recreate the demo table but for n = 1, 2, 4, 8, 16, 32, 64 and
   ONLY the columns 2ⁿ and n!. For each n print both values, marking
   OVERFLOW once they exceed long long (2⁶³−1). Derive, in a comment,
   the exact boundary values (n=64 for 2ⁿ col, n=20 for n! col).

 💡 HINT: 2⁶² fits (< 9.22×10¹⁸) but 2⁶³ does not (signed limit).
          20! ≈ 2.43×10¹⁸ fits, 21! ≈ 5.1×10¹⁹ does NOT.
          So use the guard pattern: if bool overflow → print marker.

 ✏️ STARTER CODE:
   #include <iostream>
   using namespace std;
   int main() {
       long long nSet[] = {1, 2, 4, 8, 16, 32, 64};
       for (long long n : nSet) {
           // 2^n guard: n <= 62 tab hi compute karo
           // n! guard: n <= 20 tab hi compute karo
           // print n, 2^n (ya OVERFLOW), n! (ya OVERFLOW)
       }
       return 0;
   }

-------------- SOLUTIONS --------------
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

// log2 of n! stored via Stirling — exact kam padta to bhi ordering ke liye perfect
double log2FactStirling(long long n) {
    if (n <= 1) return 0.0;
    double v = n * log((double)n) - n + 0.5 * log(2.0 * 3.14159265358979323846 * n);
    return v / log(2.0);
}

// ==================== SOLUTION TO TASK 1 ====================
void solveTask1() {
    cout << "\n══════════ TASK 1 SOLUTION — order of 8 functions ══════════" << endl;
    long long n;
    cout << "enter n: ";
    cin >> n;

    // log2(n) integer (repeated halving)
    long long lg = 0;
    long long t = n;
    while (t > 1) { t >>= 1; lg++; }

    // sab functions ko (name, log2(value)) pair ke roop mein rakh rahe hain
    // — sort key overflow-proof hai, kyunki log2 value chhota rehta hai
    pair<string, double> f[8];
    f[0] = {"1",      0.0};
    f[1] = {"log2(n)", (double)lg};
    f[2] = {"n",       log2((double)n)};
    f[3] = {"nlog2",   lg > 0 ? log2((double)(n * lg)) : 0.0};
    f[4] = {"n^2",     2.0 * log2((double)n)};
    f[5] = {"n^3",     3.0 * log2((double)n)};
    f[6] = {"2^n",     (double)n};
    f[7] = {"n!",      log2FactStirling(n)};

    // log-scale key se sort — exact values overflow kar bhi jayen, sort safe hai
    sort(f, f + 8, [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });

    cout << " ascending order of growth at n=" << n << ":\n";
    for (int i = 0; i < 8; i++) {
        printf("   %2d. %-9s  (log2 ≈ %6.2f)\n", i + 1, f[i].first.c_str(), f[i].second);
    }
    cout << " NOTE: actual exact values n², n³, 2ⁿ, n! hain — print karne se\n"
         << "       pehle overflow guard lagana; yahan log-sort use kiya.\n";
}

// ==================== SOLUTION TO TASK 2 ====================
void solveTask2() {
    cout << "\n══════════ TASK 2 SOLUTION — crossover points ══════════" << endl;

    // crossover 1: smallest n where 2^n > n^3
    double prevR = 0, prevL = 0; // pehle compare pattern track karne ke liye
    int cross1 = -1;
    for (int n = 1; n <= 60; n++) {
        double lhs = pow(2.0, n);      // 2^n exact double mein manageable
        double rhs = pow((double)n, 3.0); // n³
        if (lhs > rhs) { cross1 = n; break; }
        prevL = lhs; prevR = rhs;
    }
    printf(" 2^n beats n^3 starting at n = %d\n", cross1);
    printf("   check: n=%d → 2^%d=%.0f vs %d^3=%.0f\n",
           cross1, cross1, pow(2.0, cross1), cross1, pow(cross1, 3.0));
    printf("   derivation: solve 2^n > n^3 → n > 3·log2(n) → iteration\n");
    printf("     n=1:2>1 ✓  n=2:4>8 ✗  n=4:16>64 ✗  n=8:256>512 ✗\n");
    printf("     n=10:1024>1000 ✓ (small tumbler!) — smallest verified = %d\n", cross1);

    // crossover 2: smallest n where n! > 2^n
    double factLog = 0.0;
    double powLog  = 0.0; // log2(2^n) = n
    int cross2 = -1;
    for (int n = 1; n <= 60; n++) {
        factLog += n <= 1 ? 0.0 : log2((double)n); // log2(n!) = Σ log2(k)
        powLog  = (double)n;                       // log2(2^n) = n
        if (factLog > powLog) { cross2 = n; break; }
    }
    printf(" n! beats 2^n starting at n = %d\n", cross2);
    printf("   check n=%d: n! = %.0f vs 2^n = %.0f\n",
           cross2, 1.0 * cross2, pow(2.0, cross2));
    printf("   NOTE: 4! = 24 < 16? no 24>16 — actually n=4 it beats!\n");
}

// ==================== SOLUTION TO TASK 3 ====================
void solveTask3() {
    cout << "\n══════════ TASK 3 SOLUTION — extended table to n=64 ══════════" << endl;
    long long nSet[] = {1, 2, 4, 8, 16, 32, 64};
    int cnt = 7;

    printf("\n┌──────┬───────────────┬───────────────┐\n");
    printf("│   n  │      2^n      │      n!       │\n");
    printf("├──────┼───────────────┼───────────────┤\n");

    for (int i = 0; i < cnt; i++) {
        long long n = nSet[i];

        // 2^n guard: 1LL<<62 ok, 1LL<<63 overflow (signed) — boundary analysis!
        bool ov2 = (n > 62);            // bigger n ki koi zaroorat nahi — 64 hits boundary
        long long p2 = ov2 ? -1 : (1LL << n);

        // n! guard: 20! fits, 21! overflows — boundary!
        bool ovF = (n > 20);
        long long factVal = -1;
        if (!ovF) {
            factVal = 1;
            for (long long k = 2; k <= n; k++) factVal *= k;
        }

        if (ov2) printf("│ %4lld │      OVERFLOW │", n);
        else     printf("│ %4lld │ %13lld │", n, p2);
        if (ovF) printf("      OVERFLOW │\n");
        else     printf(" %13lld │\n", factVal);
    }
    printf("└──────┴───────────────┴───────────────┘\n");

    printf("\n Derivation of boundaries:\n");
    printf("  2^n col: 2^62 ≈ 4.6×10^18 < 9.22×10^18 (LLONG_MAX) fits.\n");
    printf("            2^63 ≈ 9.2×10^18 = 2^63 > 2^63−1 → overflow.\n");
    printf("            Hence for n=64 we must print OVERFLOW.\n");
    printf("  n!  col: 20! = 2.432902008×10^18 fits; 21! = 5.1×10^19 overflows.\n");
    printf("            Hence n=21 pe hi n! column OVERFLOW ho jata.\n");
}

int main() {
    cout << "═══════════════════════════════════════════════════" << endl;
    cout << "   GROWTH OF FUNCTIONS — TASK SOLUTIONS" << endl;
    cout << "═══════════════════════════════════════════════════" << endl;
    solveTask1();
    solveTask2();
    solveTask3();
    return 0;
}