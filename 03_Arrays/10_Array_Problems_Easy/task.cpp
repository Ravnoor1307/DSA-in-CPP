/*
═══════════════════════════════════════════════
 TASK SET — EASY ARRAY CLASSICS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: At a warehouse the stock items must be inspected:
is the list already sorted, remove the defective items (val), find the top-3
richest products, separate evens/odds into different bins, print the items
that lead all the rest (leaders), and figure out a one-time stock market
buy-sell profit.
🌧 NOTE: These are all "one pass + few variables" problems — O(n) time, O(1)
extra space. In an interview, recognize this pattern instantly: if the prompt
says "single pass / in-place / constant space", think of two pointers or a
running variable.
🧠 HOW TO SOLVE: The core of every problem is simple: (1) compare neighbours
(sorted), (2) copy values using a write pointer (remove), (3) shift a chain
of 3 variables (top3), (4) swap left/right two pointers (segregate), (5) scan
right to left keeping a max-so-far (leaders), (6) keep a min-so-far and update
best = price - min (maxProfit). Always take care of the empty/single-array
edge cases.
 5 tasks varying EASY→HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 1 — EASY: IS-SORTED CHECK               ║
  ╚═══════════════════════════════════════════════╝
  Array ascending sorted hai ya nahi — bool return karo.
  {1,2,2,3} → true, {3,2,1} → false, {} ya {9} → true.

  💡 HINT: Bas adjacent (neighbour) pairs compare karo — aur jese hi koi
          a[i] > a[i+1] dikhe, return false. Sahara: empty aur single size
          arrays ke liye loop hi nahi chalega to return true.

  ✏️ STARTER CODE:
  // bool isSorted(const vector<int>& a)
  // {
  //     for (int i = 1; i < (int)a.size(); ++i)
  //         if (___) return false;   // a[i] < a[i-1]?
  //     return true;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 2 — EASY: REMOVE ELEMENT IN-PLACE       ║
  ╚═══════════════════════════════════════════════╝
  Array me `val` ke saari occurrences IN-PLACE hatao aur nayi length return
  karo. {3,2,2,3}, val=3 → length 2, prefix {2,2}.

  💡 HINT: Two-pointer: `w` (write) aur `r` (read). r har element ko visit
          karta hai; agar a[r] != val, to a[w++] = a[r]. Jo value val ke
          barabar hai use write hi nahi karte — overwrite ho jayegi.

  ✏️ STARTER CODE:
  // int removeElement(vector<int>& a, int val)
  // {
  //     int w = 0;
  //     for (int r = 0; r < (int)a.size(); ++r)
  //         if (a[r] != val) ___;   // a[w++] = a[r];
  //     return w;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 3 — MEDIUM: THREE LARGEST DISTINCT      ║
  ╚═══════════════════════════════════════════════╝
  Array me se 3 sabse bade DISTINCT values return karo.
  {10,4,3,10,8} → {10,8,4}. (Duplicate 10 sirf ek baar count hoga.)

  💡 HINT: Teeno ko INT_MIN se start karo; har x ke liye pehle check karo ki
          wo already set me to nahi (distinct!), warna if-else chain se niche
          shift karo: x>first → first ko second, second ko third, x first.
          End me INT_MIN walon ko hata dena (kam distinct hain).

  ✏️ STARTER CODE:
  // vector<int> top3(const vector<int>& a)
  // {
  //     int f=INT_MIN, s=INT_MIN, t=INT_MIN;
  //     for (int x : a) {
  //         if (x==f || x==s || x==t) continue;   // distinct
  //         if (___) { t=s; s=f; f=x; }
  //         else if (___) { t=s; s=x; }
  //         else if (___) { t=x; }
  //     }
  //     ... INT_MIN wale drop karke vector return
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 4 — MEDIUM: LEADERS (RIGHT-TO-LEFT)     ║
  ╚═══════════════════════════════════════════════╝
  Leader = element jo apne RIGHT ke SAARE elements se bada ho. Last element
  hamesha leader. {16,17,4,3,5,2} → {17,5,2}.

  💡 HINT: Right se left scan karo, `mx` = ab tak ka max (right side ka).
          Agar a[i] > mx → leader, aur mx ko update karo. Result ko right-to-left
          collect hua, isliye end me reverse karke L→R order me print karo.

  ✏️ STARTER CODE:
  // vector<int> leaders(const vector<int>& a)
  // {
  //     vector<int> res; int mx = INT_MIN;
  //     for (int i = (int)a.size()-1; i >= 0; --i)
  //         if (___) { res.push_back(a[i]); mx = a[i]; }  // a[i] > mx
  //     reverse(res.begin(), res.end()); return res;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 5 — HARD: MAX PROFIT STOCK (ONE TRADE)  ║
  ╚═══════════════════════════════════════════════╝
  Ek buy + ek sell (buy kam dam, sell zyada) — max profit = a[j] - a[i], j>i.
  {7,1,5,3,6,4} → 5 (1 pe buy, 6 pe sell). Sirf ghatta price {5,4,3,2,1} → 0.

  💡 HINT: `mn` = aaj tak ka sabse sasta (minimum) price. Har price par
          best = max(best, price - mn). Brute me har (i,j) pair check karna
          O(n²) hoga — ye O(n)/O(1) wala tarika yeh hai. Socho: jo price aa
          raha hai usse bechne ka best buy hamesha usse PEHLE ka minimum hai.

  ✏️ STARTER CODE (optimal — the O(n) one):
  // int maxProfit(const vector<int>& p)
  // {
  //     int mn = INT_MAX, best = 0;
  //     for (int price : p) {
  //         mn = min(mn, price);
  //         best = max(best, ___);   // price - mn
  //     }
  //     return best;
  // }
  // BRUTE version (hint ke liye):
  // for i: for j=i+1: best = max(best, p[j]-p[i])   → O(n²)
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ---------- SOLUTION 1 — isSorted ----------
bool isSorted(const vector<int>& a) {
    for (int i = 1; i < (int)a.size(); ++i)
        if (a[i] < a[i-1]) return false;   // koi bhi descent sorted hata deta
    return true;                            // empty/single are sorted
}
// O(n) time, O(1) space — n-1 neighbour comparisons

// ---------- SOLUTION 2 — remove element in-place ----------
int removeElement(vector<int>& a, int val) {
    int w = 0;                              // write pointer — sada age
    for (int r = 0; r < (int)a.size(); ++r) // read pointer — koi bhi
        if (a[r] != val) a[w++] = a[r];     // keep only != val
    return w;                               // w = nayi length
}
// O(n) time, O(1) extra space (in-place)

// ---------- SOLUTION 3 — three largest distinct ----------
vector<int> top3(const vector<int>& a) {
    int f = INT_MIN, s = INT_MIN, t = INT_MIN;
    for (int x : a) {
        if (x == f || x == s || x == t) continue;  // distinct wala check
        if (x > f)        { t = s; s = f; f = x; } // shift chain down
        else if (x > s)   { t = s; s = x; }
        else if (x > t)   { t = x; }
    }
    vector<int> out;
    for (int v : {f, s, t}) if (v != INT_MIN) out.push_back(v); // sentinel drop
    return out;
}
// O(n) time, O(1) space

// ---------- SOLUTION 4 — leaders right-to-left ----------
vector<int> leaders(const vector<int>& a) {
    vector<int> res;
    int mx = INT_MIN;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (a[i] > mx) {                    // right side ke max se bada?
            res.push_back(a[i]);
            mx = a[i];                      // naye max so far
        }
    }
    reverse(res.begin(), res.end());        // L→R order me chahiye
    return res;
}
// O(n) time, O(d) output space (d = number of leaders, ≤ n)

// ---------- SOLUTION 5 — max profit one trade ----------
int maxProfitBrute(const vector<int>& p) {
    int best = 0, n = (int)p.size();
    for (int i = 0; i < n; ++i)             // buy
        for (int j = i + 1; j < n; ++j)     // sell
            best = max(best, p[j] - p[i]);
    return best;
}
// O(n²) time, O(1) space — Σ(i)(n-1-i) = n(n-1)/2

int maxProfitOpt(const vector<int>& p) {
    int mn = INT_MAX, best = 0;
    for (int price : p) {
        mn = min(mn, price);                // ab tak ka minimum (best buy)
        best = max(best, price - mn);       // aaj sell karke kitna profit
    }
    return best;
}
// O(n) time, O(1) space — single pass

int main() {
    vector<int> v1 = {1,2,2,3};
    cout << "isSorted {1,2,2,3} = " << (isSorted(v1) ? "true" : "false") << "\n";
    cout << "isSorted {3,2,1}   = " << (isSorted({3,2,1}) ? "true" : "false") << "\n";

    vector<int> v2 = {3,2,2,3};
    int len = removeElement(v2, 3);
    cout << "removeElement {3,2,2,3}, val=3 → newLen=" << len << "\n";

    vector<int> v3 = {10,4,3,10,8};
    vector<int> t3 = top3(v3);
    cout << "top3 {10,4,3,10,8} = {";
    for (size_t i = 0; i < t3.size(); ++i) cout << t3[i] << (i+1<t3.size()?", ":"");
    cout << "}\n";

    vector<int> v4 = {16,17,4,3,5,2};
    vector<int> l4 = leaders(v4);
    cout << "leaders {16,17,4,3,5,2} = {";
    for (size_t i = 0; i < l4.size(); ++i) cout << l4[i] << (i+1<l4.size()?", ":"");
    cout << "}\n";

    vector<int> v5 = {7,1,5,3,6,4};
    cout << "maxProfit {7,1,5,3,6,4} brute=" << maxProfitBrute(v5)
         << " opt=" << maxProfitOpt(v5) << "\n";
    cout << "maxProfit decreasing {5,4,3,2,1} = " << maxProfitOpt({5,4,3,2,1})
         << " (0 = koi profit nahi)\n";
    cout << "maxProfit single {7} = " << maxProfitOpt({7}) << "\n";

    return 0;
}