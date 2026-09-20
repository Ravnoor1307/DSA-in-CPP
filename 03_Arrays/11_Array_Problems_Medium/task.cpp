/*
═══════════════════════════════════════════════
 TASK SET — MEDIUM ARRAY CLASSICS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Three kinds of questions: (1) which stretch gave the
maximum profit (Kadane), (2) did any element appear more than half the times
(Moore's voting), (3) how much water is trapped between the buildings
(rainwater). These three teach the pattern: "first think brute force, then
give the O(n) insight".
🧠 HOW TO SOLVE: Kadane — `cur=max(x,cur+x)` and `best=max(best,cur)`.
Moore's — one pass makes the candidates cancel each other out, a second pass
verifies (majority must beat n/2). Rainwater — `water[i]=min(L,R)-h[i]`
defines it: keep L and R with prefix arrays or two pointers. TASK 5 (circular)
joins Kadane with wrap-around: answer = max(kadaneNormal, total -
kadaneMinSubarray).
 5 tasks varying EASY→HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 1 — EASY: KADANE SUM ONLY               ║
  ╚═══════════════════════════════════════════════╝
  Max subarray sum return karo. {-2,1,-3,4,-1,2,1,-5,4} → 6.
  All-negative {-3,-1,-2} → -1 (max single element, 0 NAHI).

  💡 HINT: Do variables: cur (ending-at-i best) aur best (global). Har x par:
          cur = max(x, cur+x); best = max(best, cur). All-negative ke liye
          cur ko 0 reset mat karo — max(x, cur+x) form rakho.

  ✏️ STARTER CODE:
  // int kadane(const vector<int>& a)
  // {
  //     int cur = 0, best = INT_MIN;
  //     for (int x : a) {
  //         cur = max(x, ___);   // cur + x
  //         best = max(best, cur);
  //     }
  //     return best;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 2 — MEDIUM: KADANE WITH PRINT           ║
  ╚═══════════════════════════════════════════════╝
  Sum ke saath-saath best subarray ke START aur END indices bhi batane hain.
  {-2,1,-3,4,-1,2,1,-5,4} → sum 6, subarray {4,-1,2,1}.

  💡 HINT: Kadane me jahan cur restart hota hai (cur==x wala case), wahan
          naya start = i. Jahan best update hota hai, wahan end = i parse
          karo. Palat ke start/end print karne ke liye slice print karo.

  ✏️ STARTER CODE:
  // range kadaneWithRange(const vector<int>& a)
  // {
  //     int cur=0, best=INT_MIN, s=0, bestS=0, bestE=0;
  //     for (int i=0; i<(int)a.size(); ++i) {
  //         if (cur + a[i] < a[i]) { cur = a[i]; s = i; }  // restart
  //         else cur += a[i];
  //         if (cur > best) { best = cur; bestS = s; bestE = i; }
  //     }
  //     // print a[bestS..bestE]
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 3 — MEDIUM: MAJORITY VERIFY             ║
  ╚═══════════════════════════════════════════════╝
  Majority element (count > n/2) return karo; nosirf — -1. Kadi requirement:
  TWO passes — pehla vote-cancel se candidate nikalo, dusra count karke verify.

  💡 HINT: Pass1: votes==0 → cand=x,votes=1; x==cand → votes++ warna votes--.
          Pass2: cand ko puri array me count karo; agar > n/2 to return cand,
          otherwise -1. Pass 2 BINA bhi candidate aata hai — isliye verify
          compulsory hai.

  ✏️ STARTER CODE:
  // int majorityElement(const vector<int>& a)
  // {
  //     int cand=0, votes=0;
  //     for (int x : a) {
  //         if (votes==0) { ___; ___; }   // cand=x, votes=1
  //         else if (x==cand) ___;        // votes++
  //         else ___;                     // votes--
  //     }
  //     int cnt=0;
  //     for (int x : a) if (x==cand) ___; // cnt++
  //     return cnt > (int)a.size()/2 ? cand : -1;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 4 — MEDIUM: RAINWATER TWO-POINTER      ║
  ╚═══════════════════════════════════════════════╝
  Trapped water total do-pointer approach se nikalo — O(n) time, O(1) space.
  {4,2,0,3,2,5} → 9.

  💡 HINT: l=0, r=n-1, lmax=rmax=0. Jab lmax<=rmax → us cell ka cap lmax hai:
          lmax=max(lmax,h[l]); water+=lmax-h[l]; l++. Nahi to r side. Reason:
          chhota cap hi constrain karta hai; chhota side ka cap decide karo.

  ✏️ STARTER CODE:
  // int trapWater(const vector<int>& h)
  // {
  //     int n=(int)h.size(), l=0, r=n-1, lmax=0, rmax=0, water=0;
  //     while (l<=r) {
  //         if (lmax <= rmax) {
  //             lmax = max(lmax, h[l]);
  //             water += ___; // lmax - h[l]
  //             ++l;
  //         } else {
  //             rmax = max(rmax, h[r]);
  //             water += ___; // rmax - h[r]
  //             --r;
  //         }
  //     }
  //     return water;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 5 — HARD: MAX CIRCULAR SUBARRAY         ║
  ╚═══════════════════════════════════════════════╝
  Subarray ko circular (wrap-around allowed) samjho. Max sum return karo.
  {8,-1,3,4} → 15 (8,-1,3,4 sab = 14; ya wrap 8+? nahi... sab = 14). Try
  {5,-3,5} → answer 10 hoga: ya to {5,-3,5}=7, ya wrap = 7... actually
  {5,-3,5} circular: possible subarrays: poles {5}=5,{-3},{5},{5,-3}=2,{5},
  {5,-3,5}=7, wrap {5,5}=10 → 10.

  💡 HINT: Circular max = max(lineKadane, total - minSubarrayKadane). Agar
          SAB negative ho to total - minSubarray = 0 galat dega — us case me
          sirf lineKadane return karo. Do Kadane versions — ek max, ek min.

  ✏️ STARTER CODE:
  // int maxCircular(const vector<int>& a)
  // {
  //     int n = (int)a.size();
  //     // if (n==0) return 0;  edge
  //     int maxKadane = kadaneNormal(a);      // TASK 1 ka function
  //     int minKadane = kadaneMin(a);         // min subarray (reverse of kadane)
  //     int total = sum(a);
  //     if (total == minKadane) return maxKadane;  // all-negative guard
  //     return max(maxKadane, total - minKadane);
  // }
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ---------- SOLUTION 1 — Kadane sum only ----------
int kadane(const vector<int>& a) {
    int cur = 0, best = INT_MIN;
    for (int x : a) {
        cur = max(x, cur + x);    // restart kare ya extend kare
        best = max(best, cur);
    }
    return best;
}
// O(n) time, O(1) space

// ---------- SOLUTION 2 — Kadane with range ----------
void kadaneWithRange(const vector<int>& a) {
    if (a.empty()) return;
    int cur = 0, best = INT_MIN;
    int s = 0, bestS = 0, bestE = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (cur + a[i] < a[i]) { cur = a[i]; s = i; }   // purani tail bekar → reset
        else cur += a[i];
        if (cur > best) { best = cur; bestS = s; bestE = i; }
    }
    cout << "  best sum = " << best << ", subarray = {";
    for (int i = bestS; i <= bestE; ++i) cout << a[i] << (i<bestE ? ", " : "");
    cout << "}\n";
}

// ---------- SOLUTION 3 — majority verifying ----------
int majorityElement(const vector<int>& a) {
    if (a.empty()) return -1;
    int cand = 0, votes = 0;
    for (int x : a) {
        if (votes == 0)      { cand = x; votes = 1; }
        else if (x == cand)  ++votes;
        else                 --votes;
    }
    int cnt = 0;
    for (int x : a) if (x == cand) ++cnt;
    return cnt > (int)a.size() / 2 ? cand : -1;   // pass-2 proof mandatory
}
// O(n) time, O(1) space

// ---------- SOLUTION 4 — rainwater two-pointer ----------
int trapWater(const vector<int>& h) {
    int n = (int)h.size();
    int l = 0, r = n - 1, lmax = 0, rmax = 0, water = 0;
    while (l <= r) {
        if (lmax <= rmax) {                    // left cap decisive
            lmax = max(lmax, h[l]);
            water += lmax - h[l];
            ++l;
        } else {                               // right cap decisive
            rmax = max(rmax, h[r]);
            water += rmax - h[r];
            --r;
        }
    }
    return water;
}
// O(n) time, O(1) space

// ---------- SOLUTION 5 — max circular subarray ----------
int kadaneMin(const vector<int>& a) {           // min subarray = reverse kadane
    int cur = 0, best = INT_MAX;
    for (int x : a) {
        cur = min(x, cur + x);
        best = min(best, cur);
    }
    return best;
}
int maxCircular(const vector<int>& a) {
    if (a.empty()) return 0;
    int maxK = kadane(a);
    int total = 0;
    for (int x : a) total += x;
    int minK = kadaneMin(a);
    if (total == minK) return maxK;             // all-negative guard
    return max(maxK, total - minK);             // wrap = total - minSubarray
}

int main() {
    vector<int> k = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "TASK1 kadane = " << kadane(k) << "\n";          // 6
    cout << "TASK1 all-neg {-3,-1,-2} = " << kadane({-3,-1,-2}) << "\n"; // -1

    cout << "TASK2 kadaneWithRange:\n";
    kadaneWithRange(k);                                      // 6, {4,-1,2,1}

    cout << "TASK3 majority {2,2,1,1,1,2,2} = "
         << majorityElement({2,2,1,1,1,2,2}) << "\n";        // 2
    cout << "TASK3 no-majority {1,2,3} = " << majorityElement({1,2,3}) << "\n"; // -1

    cout << "TASK4 trapWater {4,2,0,3,2,5} = "
         << trapWater({4,2,0,3,2,5}) << "\n";                // 9

    cout << "TASK5 maxCircular {5,-3,5} = " << maxCircular({5,-3,5}) << "\n";   // 10
    cout << "TASK5 maxCircular all-neg {-2,-3,-1} = " << maxCircular({-2,-3,-1}) << "\n"; // -1
    return 0;
}