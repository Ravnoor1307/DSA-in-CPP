/*
═══════════════════════════════════════════════
 TASK SET — FREQUENCY COUNTING
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: At a voting booth every candidate's votes must be
counted; the candidate who appears the most times wins (max frequency), and
the one who appears only once is unusual (non-repeating). This same problem
shows up online in "most purchased item" and "rarest visitor" reports.
🧠 HOW TO SOLVE: Treat the element as the key and the count as its value.
unordered_map builds all counts in one pass (O(1) average per insert); then
for each query run one more pass over the map or the original array — total
O(n). Always check the empty-array edge case first.
 5 tasks varying EASY→HARD. Each: TASK n + 💡 HINT + ✏️ STARTER CODE (// only or words)
═══════════════════════════════════════════════
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 1 — EASY:  FREQUENCY OF EACH ELEMENT    ║
  ╚═══════════════════════════════════════════════╝
  Har distinct element ko print karo "value -> count" format mein.

  💡 HINT: unordered_map<int,int> le lo. For loop se har x ke liye
          mp[x]++ karo. End mein map iterate karke print.

  ✏️ STARTER CODE:
  // void printFreq(const vector<int>& a)
  // {
  //     unordered_map<int,int> mp;
  //     for (int x : a) ___;       // count increment
  //     for (auto& p : mp) ___;    // p.first, p.second print
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 2 — EASY:  MAXIMUM FREQUENCY ELEMENT    ║
  ╚═══════════════════════════════════════════════╝
  Jo element sabse zyada baar aaya hai, us element ka value return karo.
  {1,2,2,3,1,2} → answer 2 (3 baar aaya).

  💡 HINT: Counts map mein hain. Map iterate karke max count track karo;
          bestVal aur bestCnt do variables chahiye. phir return bestVal.

  ✏️ STARTER CODE:
  // int maxFreqElement(const vector<int>& a)
  // {
  //     unordered_map<int,int> mp;
  //     for (int x : a) ___;
  //     int bestVal = -1, bestCnt = -1;
  //     for (auto& p : mp)
  //         if (___) { ___; ___; }   // compare p.second with bestCnt
  //     return bestVal;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 3 — MEDIUM:  MINIMUM FREQUENCY ELEMENT  ║
  ╚═══════════════════════════════════════════════╝
  Jo element sabse KAM baar aaya hai wo return karo.
  {1,2,2,3,1,2} → answer 3 (sirf 1 baar aaya).
  Tie mein koi bhi valid hai. Empty array → -1.

  💡 HINT: Task 2 jaise hi, bas comparison `<` karo. Initial bestCnt ko
          infinity (ya kisi bade number, jaise a.size()+1) se set karo.

  ✏️ STARTER CODE:
  // int minFreqElement(const vector<int>& a)
  // {
  //     if (a.empty()) return -1;
  //     unordered_map<int,int> mp;
  //     for (int x : a) ___;
  //     int bestVal = -1, bestCnt = INT_MAX;
  //     for (auto& p : mp)
  //         if (___) { ___; }
  //     return bestVal;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 4 — MEDIUM:  FIRST NON-REPEATING ELEMENT║
  ╚═══════════════════════════════════════════════╝
  Array mein sabse pehle aane wala element jiska frequency exactly 1 ho,
  use return karo. {1,2,2,3,1,2} → answer 3. Koi nahi → -1.

  💡 HINT: Pehle counts banao (pass 1). Phir ORIGINAL ARRAY order mein scan
          karke sabse pehla aisa x return karo jisse mp[x]==1. Array ka order
          hi "first" ko define karta hai — map order use mat karna.

  ✏️ STARTER CODE:
  // int firstNonRepeating(const vector<int>& a)
  // {
  //     unordered_map<int,int> mp;
  //     for (int x : a) ___;
  //     for (int x : a)
  //         if (___) return x;    // mp[x] == 1 ?
  //     return -1;
  // }
*/

/*
  ╔═══════════════════════════════════════════════╗
  ║  TASK 5 — HARD:  TWO ELEMENTS APPEARING ONCE  ║
  ╚═══════════════════════════════════════════════╝
  Array mein sab elements exactly 2 baar aate hain, SIRF do elements ek baar.
  Un do elements ko kisi bhi order mein return karo.
  {4,1,2,1,2,5} → {4,5} (4 aur 5 sirf ek-ek baar).

  💡 HINT (approach 1): Count map se check karo — jiska count==1 wo answer.
  💡 HINT (XOR trick, space O(1)): Saare elements ka XOR karo → xorAll =
          a^b. Phir xorAll ka koi bhi set bit nikal kar usse do groups banao;
          har group ka XOR ek number de dega. Ye classic interview trick hai.

  ✏️ STARTER CODE (map approach — simple):
  // vector<int> twoSingles(const vector<int>& a)
  // {
  //     unordered_map<int,int> mp;
  //     for (int x : a) ___;
  //     vector<int> ans;
  //     for (auto& p : mp)
  //         if (___) ans.push_back(p.first);   // count == 1
  //     return ans;
  // }
*/

// ---------------- SOLUTIONS ----------------

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// ---------- SOLUTION 1 — freq of each element ----------
void printFreq(const vector<int>& a) {
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;                  // count build — O(n) total
    for (auto& p : mp)                        // table walk — O(d), d=distinct
        cout << p.first << " -> " << p.second << "\n";
}
// Time: O(n) avg (n inserts + d walk) | Space: O(d)

// ---------- SOLUTION 2 — max frequency element ----------
int maxFreqElement(const vector<int>& a) {
    if (a.empty()) return -1;                 // edge case: koi element nahi
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    int bestVal = -1, bestCnt = -1;
    for (auto& p : mp) {
        if (p.second > bestCnt) {             // naya max mila
            bestCnt = p.second;
            bestVal = p.first;
        }
    }
    return bestVal;
}
// Time: O(n) avg | Space: O(d) — single table walk enough

// ---------- SOLUTION 3 — min frequency element ----------
int minFreqElement(const vector<int>& a) {
    if (a.empty()) return -1;
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    int bestVal = -1, bestCnt = INT_MAX;      // infinity se start karo
    for (auto& p : mp) {
        if (p.second < bestCnt) {             // chhota count mila
            bestCnt = p.second;
            bestVal = p.first;
        }
    }
    return bestVal;
}
// Time: O(n) avg | Space: O(d)

// ---------- SOLUTION 4 — first non-repeating ----------
int firstNonRepeating(const vector<int>& a) {
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;                  // PASS 1: counts table
    for (int x : a) {                         // PASS 2: original order me
        if (mp[x] == 1) return x;             // leftmost unique value
    }
    return -1;                                // sab repeat hota hai
}
// Time: O(n) avg (2 passes) | Space: O(d)

// ---------- SOLUTION 5 — two elements appearing once ----------
// Approach A: simple — hashmap se count==1 wale chun lo
vector<int> twoSinglesMap(const vector<int>& a) {
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    vector<int> ans;
    for (auto& p : mp)
        if (p.second == 1) ans.push_back(p.first);
    return ans;
}
// Time: O(n) avg | Space: O(n) — easy to write, interview-safe

// Approach B: XOR trick — O(n) time, O(1) space (classic hard version)
vector<int> twoSinglesXOR(const vector<int>& a) {
    int xr = 0;
    for (int x : a) xr ^= x;                // pura array XOR = a ^ b
    int mask = xr & (-xr);                  // rightmost set bit
    int grp1 = 0, grp2 = 0;
    for (int x : a) {
        if (x & mask) grp1 ^= x;            // bit set → group 1 (ek number milega)
        else          grp2 ^= x;            // bit unset → group 2 (doosra number)
    }
    return {grp1, grp2};
}
// Time: O(n) | Space: O(1) — eklauta space-efficient tarika

void show(const vector<int>& v, const string& name) {
    cout << name << " = {";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    cout << "}\n";
}

int main() {
    vector<int> a = {1,2,2,3,1,2};
    cout << "TASK 1 result:\n";
    printFreq(a);                                   // 1->2, 2->3, 3->1

    cout << "\nTASK 2 maxFreqElement({1,2,2,3,1,2}) = "
         << maxFreqElement(a) << "\n";              // 2

    cout << "TASK 3 minFreqElement({1,2,2,3,1,2}) = "
         << minFreqElement(a) << "\n";              // 3

    cout << "TASK 4 firstNonRepeating({1,2,2,3,1,2}) = "
         << firstNonRepeating(a) << "\n";           // 3

    vector<int> t5 = {4,1,2,1,2,5};
    show(twoSinglesMap(t5),  "TASK 5 (map)  twoSingles");
    show(twoSinglesXOR(t5),  "TASK 5 (XOR)  twoSingles");   // {4,5} ya {5,4}

    cout << "\nEdge: empty maxFreq = " << maxFreqElement({}) << "\n";
    cout << "Edge: non-reap missing = " << firstNonRepeating({5,5,5}) << "\n";
    return 0;
}