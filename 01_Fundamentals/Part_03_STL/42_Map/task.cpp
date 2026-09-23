/*
═══════════════════════════════════════════════
 TASK SET — std::map
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A news website wants a report of how many
    times each word appears in an article (in alphabetical order), a
    class teacher needs the highest-scoring subject, and a delivery app
    must find two orders whose costs sum exactly to a budget coupon.
    std::map keeps every (name → value) pair sorted by key, which makes
    frequency reports, lookups, and value-sorting all natural.

 🧠 HOW TO SOLVE: Frequency problems → freq[key]++ (the map sorts
    itself). Two-sum → store value→index in the map, then search for the
    complement. "Highest frequency" → iterate the map and track the max
    count. Distinct count → size() of the map. Sort by value → the map is
    sorted by KEY, so copy into a vector<pair> and sort by value instead.
    Read every statement carefully; a HINT is given, but try it yourself
    first.

 MODES/TOPICS COVERED:
  1. Word frequency (sorted by key)
  2. Highest frequency word
  3. Count distinct elements
  4. Two-sum: return the indices
  5. Sort a map by value
  6. Majority element
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

// ==================== TASK 1 (EASY) ====================
// problem: sentence diya hai (spaces se separated words). Har WORD ki
// frequency print karo — SORTED order me (map by key).
void wordFrequency(const string& sentence) {
    map<string, int> freq;                 // word → count
    stringstream ss(sentence);              // words alag karne ke liye
    string word;
    while (ss >> word) freq[word]++;        // [] nayi key → 0, phir ++
    for (const auto& e : freq)              // sorted (alphabetical) output
        cout << e.first << " -> " << e.second << endl;
}

// ==================== TASK 2 (EASY) ====================
// problem: words ki list me sabse ZYADA baar aane wala word batao.
string highestFrequencyWord(const vector<string>& words) {
    map<string, int> freq;
    for (const string& w : words) freq[w]++;
    string best;
    int bestCnt = 0;
    for (const auto& e : freq)              // map sorted — tie me chhoti key jeeti
        if (e.second > bestCnt) { best = e.first; bestCnt = e.second; }
    return best;
}

// ==================== TASK 3 (EASY) ====================
// problem: array me kitne DISTINCT elements hain? (value repeat ho
// sakti hai, count karna hai kitne alag-alag values hain).
int countDistinct(const vector<int>& arr) {
    map<int, int> m;
    for (int x : arr) m[x]++;               // count se matlab nahi, kitni distinct KEYS hain
    return (int)m.size();                   // size = distinct keys kitni
}

// ==================== TASK 4 (MEDIUM) ====================
// problem: TWO SUM — array + target. Do INDICES return karo jinke
// values ka sum target ho. (Ek saja assumption: exactly 1 answer hai.)
vector<int> twoSum(const vector<int>& arr, int target) {
    map<int, int> index;                    // value → jahan mila (index)
    for (int i = 0; i < (int)arr.size(); ++i) {
        int need = target - arr[i];         // kitna partner chahiye
        auto it = index.find(need);          // O(log n)
        if (it != index.end())              // partner mil gaya?
            return {it->second, i};          // uska pehla index + naya index
        index[arr[i]] = i;                   // current ko record (late insert = no self-match)
    }
    return {};                               // nahi mila
}

// ==================== TASK 5 (MEDIUM-HARD) ====================
// problem: map given hai; usse VALUE ke hisaab se sort karke return
// karo. Yaad rakho: map khud KEY se sorted hai — value se nahi!
vector<pair<string, int>> sortMapByValue(const map<string, int>& m) {
    vector<pair<string, int>> v(m.begin(), m.end());   // copy — map key-sorted order me
    sort(v.begin(), v.end(),
         [](const auto& a, const auto& b) { return a.second < b.second; }); // value chhota → bada
    return v;
}

// ==================== TASK 6 (HARD) ====================
// problem: array diya hai; element jo n/2 se ZYADA baar aata hai
// (majority element) return karo, warna -1.
int majorityElement(const vector<int>& arr) {
    map<int, int> freq;
    for (int x : arr) freq[x]++;             // O(n log n)
    for (const auto& e : freq)
        if (e.second > (int)arr.size() / 2) return e.first; // majority condition
    return -1;
}

int main() {
    cout << "=== TASK 1: word frequency (sorted) ===" << endl;
    wordFrequency("the cat sat on the mat");

    cout << "\n=== TASK 2: highest frequency word ===" << endl;
    cout << highestFrequencyWord({"cat", "dog", "cat", "bird", "cat", "dog"}) << endl;

    cout << "\n=== TASK 3: count distinct ===" << endl;
    cout << "countDistinct({7,7,7,1,2,2,3}) = "
         << countDistinct({7,7,7,1,2,2,3}) << endl;

    cout << "\n=== TASK 4: two sum indices ===" << endl;
    vector<int> p = twoSum({2, 7, 11, 15}, 9);
    cout << "indices: " << p[0] << " " << p[1] << "  (2 + 7 = 9)" << endl;

    cout << "\n=== TASK 5: sort map by value ===" << endl;
    map<string, int> m = {{"Rahul", 90}, {"Amit", 70}, {"Priya", 80}};
    for (auto& e : sortMapByValue(m))
        cout << e.first << ":" << e.second << " ";
    cout << endl;

    cout << "\n=== TASK 6: majority element ===" << endl;
    cout << "majorityElement({3,3,4,2,3,3}) = " << majorityElement({3,3,4,2,3,3}) << endl;
    cout << "majorityElement({1,2,3,4}) = " << majorityElement({1,2,3,4}) << " (-1 = none)" << endl;

    return 0;
}

/* ------------------ EXPLANATION NOTES ------------------
TASK 1: stringstream words peekhar hi alag kar deta hai. freq[word]++
        har word O(log k), nahi badla kyunki sorted output milta hai.
TASK 2: Frequency builder O(n log n); iterate karke max count. Tie-break
        sorted order me pehli key jitni.
TASK 3: size() of map = number of distinct keys. Edge: empty → 0.
TASK 4: value→index done. Pehle check (find), phir insert — isse
        "same index itself" self-match nahi hota. O(n log n).
        NOTE: duplicate values ho to last index overwrite hoga — the
        pair indices abhi bhi valid hain (sorted-key property ka fayda).
TASK 5: map KEY-se-sorted rehta hai. value-sort karne ke liye copy +
        custom comparator. Stable: equal values key-order me rehte hain.
TASK 6: Frequency + check cnt > n/2. O(n log n). Interview me improved
        Boyer-Moore O(n) bhi bata dena — par count verify zaroor karo.
*/