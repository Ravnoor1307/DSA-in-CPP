/*
═══════════════════════════════════════════════
 TASK SET — std::unordered_map
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A messaging app shows a user their first
    message that was sent EXACTLY once, an e-commerce catalog groups
    anagram product names together, and a finance ledger sums subarrays
    totalling exactly a bill amount. All three need key→value lookups in
    O(1) average with zero regard for sorted order — exactly what
    std::unordered_map gives.

 🧠 HOW TO SOLVE: Frequency → freq[x]++. First non-repeating → count
    first, then re-scan in order using freq[c]==1. Missing number → store
    all present values in the hash, then scan 1..n with count(). Two-sum →
    value→index map with the complement checked BEFORE insert. Subarray
    sum = k → prefix-sum map with cnt[0]=1 (do not forget!). Group
    anagrams → the sorted word as the group key. Read every statement
    carefully; a HINT is given, but try it yourself first.

 MODES/TOPICS COVERED:
  1. First non-repeating character
  2. Frequency of each value
  3. Missing number
  4. Two-sum: return the indices
  5. Subarray sum equals k
  6. Group anagrams
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ==================== TASK 1 (EASY) ====================
// problem: string me SABSE PEHLA character return karo jo exactly 1
// baar aaya ho (non-repeating). Agar koi nahi to '\0'.
char firstNonRepeating(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;             // pass 1: count O(1) avg each
    for (char c : s)                        // pass 2: original ORDER me check
        if (freq[c] == 1) return c;         // pehla jiska count 1 = answer
    return '\0';                             // koi non-repeating nahi
}

// ==================== TASK 2 (EASY) ====================
// problem: array diya hai; HAR value ki frequency print karo.
void printFrequency(const vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;            // O(1) avg per step
    for (const auto& e : freq)              // kram arbitrary — it's fine
        cout << e.first << " -> " << e.second << endl;
}

// ==================== TASK 3 (MEDIUM) ====================
// problem: [1..n] tak numbers hone chahiye; array me n-1 elements hain
// (ek missing). MISSING number find karo. e.g. {2,3,1,5}, n=5 → 4.
int findMissing(const vector<int>& arr, int n) {
    unordered_map<int, int> present;
    for (int x : arr) present[x] = 1;       // jo mila wo hash me daalo
    for (int i = 1; i <= n; ++i)            // 1 se n tak check
        if (!present.count(i)) return i;    // jo nahi mila = missing
    return -1;                               // unreachable — input valid hai to missing pakka milega
}

// ==================== TASK 4 (MEDIUM) ====================
// problem: TWO SUM — array + target; do INDICES return karo jinka sum
// target ho. O(n) required (unordered_map). Exactly 1 answer assume.
vector<int> twoSum(const vector<int>& arr, int target) {
    unordered_map<int, int> index;          // value → index (O(1) lookup)
    for (int i = 0; i < (int)arr.size(); ++i) {
        int need = target - arr[i];         // complement chahiye
        auto it = index.find(need);          // O(1) avg
        if (it != index.end()) return {it->second, i};
        index[arr[i]] = i;                  // check ke BAAD insert (no self-match)
    }
    return {};                               // nahi mila
}

// ==================== TASK 5 (MEDIUM-HARD) ====================
// problem: array + k diya hai. Kitne CONTINUOUS subarrays ka sum exactly
// k hai? e.g. {1,2,3}, k=3 → 2 (subarrays [1,2] aur [3]).
int subarraySumK(const vector<int>& arr, int k) {
    unordered_map<int, int> pref;           // prefix-sum → count of times seen
    pref[0] = 1;                            // khali subarray ka sum 0 — bhoolna mat! ⭐
    int sum = 0, ans = 0;
    for (int x : arr) {
        sum += x;                            // naya prefix sum
        auto it = pref.find(sum - k);        // kya (sum-k) pehle aa chuka?
        if (it != pref.end()) ans += it->second; // utni subarrays mil gayi
        pref[sum]++;                         // current prefix record
    }
    return ans;
}

// ==================== TASK 6 (HARD) ====================
// problem: words ki list diya hai; ANAGRAMS ko ek saath group karo.
// e.g. {"eat","tea","tan","ate","nat","bat"} →
//      {{eat,tea,ate},{tan,nat},{bat}} (order kisi bhi ho).
vector<vector<string>> groupAnagrams(const vector<string>& words) {
    unordered_map<string, vector<string>> groups; // sorted-word → bin
    for (const string& w : words) {
        string key = w;
        sort(key.begin(), key.end());        // "eat" → "aet" : same anagram bin
        groups[key].push_back(w);            // O(1) avg append
    }
    vector<vector<string>> res;
    for (const auto& e : groups) res.push_back(e.second); // bins collect (copy)
    return res;
}

int main() {
    cout << "=== TASK 1: first non-repeating character ===" << endl;
    cout << "firstNonRepeating(\"leetcode\") = " << firstNonRepeating("leetcode")
         << " (expect l)" << endl;
    cout << "firstNonRepeating(\"aabbcc\") = "
         << (firstNonRepeating("aabbcc") == '\0'
             ? "NONE (\\0)" : "found") << endl;

    cout << "\n=== TASK 2: frequency ===" << endl;
    printFrequency({1, 2, 2, 3, 3, 3});

    cout << "\n=== TASK 3: missing number ===" << endl;
    cout << "findMissing({2,3,1,5}, 5) = " << findMissing({2,3,1,5}, 5)
         << " (expect 4)" << endl;

    cout << "\n=== TASK 4: two sum ===" << endl;
    vector<int> p = twoSum({2, 7, 11, 15}, 9);
    cout << "twoSum({2,7,11,15}, 9) → indices " << p[0] << " " << p[1] << endl;

    cout << "\n=== TASK 5: subarray sum = k ===" << endl;
    cout << "subarraySumK({1,2,3}, 3) = " << subarraySumK({1,2,3}, 3)
         << " (expect 2)" << endl;
    cout << "subarraySumK({1,-1,0,1}, 0) = " << subarraySumK({1,-1,0,1}, 0)
         << " (expect 4)" << endl;

    cout << "\n=== TASK 6: group anagrams ===" << endl;
    vector<vector<string>> g = groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
    for (auto& grp : g) {
        for (string& w : grp) cout << w << " ";
        cout << endl;
    }

    return 0;
}

/* ------------------ EXPLANATION NOTES ------------------
TASK 1: Two passes: build freq O(n), scan original order O(n). Total
        O(n). Second pass original ORDER me hai — isliye "pehla" correct.
TASK 2: freq[x]++ — O(n) total average. Output arbitrary order — map ke
        liye likhte waqt koi sorted expectation mat rakho.
TASK 3: present map ka size n-1; scan 1..n takes O(n) extra → O(n) total.
TASK 4: value→index, complement find SE PEHLE insert — same element
        apne aap se pair nahi banata (edge: 2x margin par correct).
        O(n) average — yehi unordered_map ka main fayda over map.
TASK 5: prefix-sum trick: subarray(i..j) sum = pref[j]-pref[i-1].
        pref[0]=1 CRUCIAL hai — warna subarray jo index 0 se shuru hota
        hai count nahi hota. O(n) average.
TASK 6: Sorted word = canonical key for anagram. groups[key].push_back
        O(1) avg. Total O(n × L log L) (L = avg word length).
*/