/*
═══════════════════════════════════════════════
 TASK SET — HARD ARRAY CLASSICS
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: Data-center repair limit k ke saath longest uptime
find karna (max consecutive ones), sports team ke player numbers ka longest
ranks-run (longest consecutive seq), dictionary ka next word (next permutation),
camera rotation (rotate matrix), aur matrix ko spiral order me padhna (spiral
print). Ye un problems hai jinme brute sochne ke baad hi O(n)/O(n²) wala
"insight" samajh aata hai.
🧠 HOW TO SOLVE: Har task ka ek hi core hai: (1) maxOnesK — sliding window zero
count k + shrink; (2) longestConsecutive — unordered_set + sirf run-starts
stretch karo; (3) nextPermutation — rightmost ascent pivot + rightmost greater
swap + suffix reverse; (4) rotate — transpose + reverse rows; (5) spiral — 4
boundaries (top, bottom, left, right) ko kaato
 5 tasks varying EASY→HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 1 — EASY: MAX CONSECUTIVE ONES          ║
  ╚═══════════════════════════════════════════════╝
  Binary array me at most k zeros flip karne ke baad longest run of 1s.
  {1,1,0,1,1,0,1,1,1} k=1 → 6.

  💡 HINT: Sliding window [l..r]. Ek `zeros` counter rakho. r ko badhao; agar
          zeros > k to l aage badhao jab tak ek zero window se bahar na ho jaye.
          best = max(best, r-l+1). Har index at most 2 baar move hota hai.

  ✏️ STARTER CODE:
  // int maxConsecutiveOnesK(const vector<int>& a, int k)
  // {
  //     int l=0, zeros=0, best=0;
  //     for (int r=0; r<(int)a.size(); ++r) {
  //         if (a[r]==0) ___;         // zeros++
  //         while (zeros > k) {
  //             if (a[l]==0) ___;     // zeros--
  //             ++l;
  //         }
  //         best = max(best, ___);    // r-l+1
  //     }
  //     return best;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 2 — MEDIUM: LONGEST CONSECUTIVE HASH    ║
  ╚═══════════════════════════════════════════════╝
  Unsorted array me longest consecutive sequence. Hash-set approach chahiye.
  {100,4,200,1,3,2} → 4 (1,2,3,4). O(n) avg time.

  💡 HINT: unordered_set<int> me sab dalo. Har x ke liye sirf tab stretch karo
          jab s.count(x-1) != 1 — matlab x ek run ka START hai. Uski len ko
          while s.count(x+len) len++ karke badhao. Non-starts ko skip karo.

  ✏️ STARTER CODE:
  // int longestConsecutiveHash(const vector<int>& a)
  // {
  //     unordered_set<int> s(a.begin(), a.end());
  //     int best = 0;
  //     for (int x : s) {
  //         if (s.count(x-1)) ___;   // continue — start nahi
  //         int len = 1;
  //         while (___) { ++len; }   // s.count(x+len)
  //         best = max(best, len);
  //     }
  //     return best;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 3 — MEDIUM: NEXT PERMUTATION            ║
  ╚═══════════════════════════════════════════════╝
  Lexicographically next arrangement; agar koi nahi to sorted ascending.
  {1,3,5,4,2} → {1,4,2,3,5}. In-place.

  💡 HINT: (a) right se left jab tak a[i] >= a[i+1]; pivot = a[i]. (b) right se
          woh j jisme a[j] > a[i] (rightmost greater), swap. (c) i+1 se end
          reverse. Pivot nahi mila → poora reverse (descending = last perm).

  ✏️ STARTER CODE:
  // void nextPermutation(vector<int>& a)
  // {
  //     int n=(int)a.size(), i=n-2;
  //     while (i>=0 && ___) --i;              // a[i] >= a[i+1]
  //     if (i<0) { reverse(a.begin(), a.end()); return; }
  //     int j=n-1;
  //     while (a[j] <= a[i]) --j;
  //     swap(___, ___);                        // a[i], a[j]
  //     reverse(a.begin() + i + 1, a.end());
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 4 — MEDIUM: ROTATE MATRIX BY 90         ║
  ╚═══════════════════════════════════════════════╝
  n×n matrix ko clockwise 90° ghumao IN-PLACE.
  3×3 wala input galat output nahi hona chahiye:
  1 2 3        7 4 1
  4 5 6   →    8 5 2
  7 8 9        9 6 3

  💡 HINT: Pehle TRANSPOSE karo (i<j par swap m[i][j], m[j][i]), phir har row
          ko reverse karo. Is combination se hi clockwise rotation ban ti hai.

  ✏️ STARTER CODE:
  // void rotateMatrix(vector<vector<int>>& m)
  // {
  //     int n=(int)m.size();
  //     for (int i=0; i<n; ++i)
  //         for (int j=i+1; j<n; ++j)
  //             ___;                   // swap(m[i][j], m[j][i])
  //     for (auto& row : m)
  //         ___(row.begin(), row.end());   // reverse
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 5 — HARD: SPIRAL ORDER MATRIX          ║
  ╚═══════════════════════════════════════════════╝
  Matrix ko SPIRAL (bahar se andar, clockwise) order me print karo.
  1  2  3  4
  5  6  7  8    →   1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
  9 10 11 12
 13 14 15 16

  💡 HINT: 4 boundaries rakho: top,bottom,left,right. Har loop me left→right
          (top row), top→bottom (right col), right→left (bottom row) (agar
          top<=bottom), bottom→top (left col) (agar left<=right). Har barr
          boundary ko kaato. Jab tak top<=bottom && left<=right.

  ✏️ STARTER CODE:
  // void spiralPrint(const vector<vector<int>>& m)
  // {
  //     int top=0, bottom=(int)m.size()-1;
  //     int left=0, right=(int)m[0].size()-1;
  //     while (top <= bottom && left <= right) {
  //         for (int c=left; c<=right; ++c) cout << m[top][c] << " "; ++top;
  //         for (int r=top; r<=bottom; ++r) cout << m[r][right] << " "; --right;
  //         if (top<=bottom) { for (int c=right; c>=left; --c) cout << m[bottom][c] << " "; --bottom; }
  //         if (left<=right) { for (int r=bottom; r>=top; --r) cout << m[r][left] << " "; ++left; }
  //     }
  // }
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// ---------- SOLUTION 1 — max consecutive ones (k flips) ----------
int maxConsecutiveOnesK(const vector<int>& a, int k) {
    int l = 0, zeros = 0, best = 0;
    for (int r = 0; r < (int)a.size(); ++r) {
        if (a[r] == 0) ++zeros;
        while (zeros > k) {                  // window me k se zyada zero
            if (a[l] == 0) --zeros;          // endo se zero bahar nikalo
            ++l;
        }
        best = max(best, r - l + 1);
    }
    return best;
}
// O(n) time, O(1) space — l aur r milake ≤ 2n moves

// ---------- SOLUTION 2 — longest consecutive sequence (hash) ----------
int longestConsecutiveHash(const vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;        // x start nahi hai → skip
        int len = 1;
        while (s.count(x + len)) ++len;      // aage stretch karo
        best = max(best, len);
    }
    return best;
}
// O(n) avg time, O(n) space — total stretch work ≤ n

// ---------- SOLUTION 3 — next permutation ----------
void nextPermutation(vector<int>& a) {
    int n = (int)a.size();
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i+1]) --i;    // rightmost pivot jahan ascent hai
    if (i < 0) { reverse(a.begin(), a.end()); return; }  // sab desc → sorted
    int j = n - 1;
    while (a[j] <= a[i]) --j;                // rightmost greater than pivot
    swap(a[i], a[j]);
    reverse(a.begin() + i + 1, a.end());     // decreasing tail ko ascending
}
// O(n) time, O(1) space

// ---------- SOLUTION 4 — rotate matrix 90° ----------
void rotateMatrix(vector<vector<int>>& m) {
    int n = (int)m.size();
    for (int i = 0; i < n; ++i)              // STEP 1: transpose
        for (int j = i + 1; j < n; ++j)
            swap(m[i][j], m[j][i]);
    for (auto& row : m) reverse(row.begin(), row.end());  // STEP 2: reverse rows
}
// O(n²) time, O(1) space

// ---------- SOLUTION 5 — spiral order matrix ----------
void spiralPrint(const vector<vector<int>>& m) {
    if (m.empty()) return;
    int top = 0, bottom = (int)m.size() - 1;
    int left = 0, right = (int)m[0].size() - 1;
    while (top <= bottom && left <= right) {
        for (int c = left; c <= right; ++c) cout << m[top][c] << " "; ++top;
        for (int r = top; r <= bottom; ++r) cout << m[r][right] << " "; --right;
        if (top <= bottom) {
            for (int c = right; c >= left; --c) cout << m[bottom][c] << " "; --bottom;
        }
        if (left <= right) {
            for (int r = bottom; r >= top; --r) cout << m[r][left] << " "; ++left;
        }
    }
    cout << "\n";
}
// O(n*m) time, O(1) space

int main() {
    cout << "TASK1 maxConsecutiveOnesK {1,1,0,1,1,0,1,1,1} k=1 → "
         << maxConsecutiveOnesK({1,1,0,1,1,0,1,1,1}, 1) << "\n";   // 6
    cout << "TASK1 no-flip k=0 on same → "
         << maxConsecutiveOnesK({1,1,0,1,1,0,1,1,1}, 0) << "\n";   // longest run of raw 1s

    cout << "TASK2 longestConsecutiveHash {100,4,200,1,3,2} → "
         << longestConsecutiveHash({100,4,200,1,3,2}) << "\n";     // 4
    cout << "TASK2 single {5} → " << longestConsecutiveHash({5}) << "\n";
    cout << "TASK2 empty {} → " << longestConsecutiveHash({}) << "\n";

    vector<int> np = {1,3,5,4,2};
    nextPermutation(np);
    cout << "TASK3 nextPermutation {1,3,5,4,2} → {";
    for (int i = 0; i < (int)np.size(); ++i) cout << np[i] << (i+1<(int)np.size()?", ":" ");
    cout << "}\n";                                                   // 1,4,2,3,5
    vector<int> last = {3,2,1};
    nextPermutation(last);
    cout << "TASK3 last perm {3,2,1} → {";
    for (int i = 0; i < (int)last.size(); ++i) cout << last[i] << (i+1<(int)last.size()?", ":" ");
    cout << "} (sorted)\n";                                          // 1,2,3

    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(m);
    cout << "TASK4 rotate 3x3: expected 741/852/963\n";
    for (auto& row : m) { for (int v : row) cout << v << " "; cout << "\n"; }

    vector<vector<int>> m5 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout << "TASK5 spiral 4x4 → ";
    spiralPrint(m5);                                                 // 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

    return 0;
}