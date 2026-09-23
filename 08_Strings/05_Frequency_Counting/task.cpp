/*
═══════════════════════════════════════════════
 TASK SET — FREQUENCY COUNTING
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A voting-counter practice session needs character counts,
    the most frequent letter, the first unique character, and anagram checks. These
    tasks cover the counting patterns used in validators, word games, and data
    cleaning.

 🧠 HOW TO SOLVE: For each character map it to an index with `ch - 'a'` and bump a
    fixed 26-cell (or 256-cell) frequency array. Nested loops give O(n²) but need no
    extra space; the frequency array gives O(n). For anagrams, sort both strings or
    add one string's letters and subtract the other's, then confirm all boxes are
    zero. Normalize to lowercase before counting.

 MODES/TOPICS COVERED:
  1. Print character frequency with nested loops
  2. Print character frequency with freq[26] using `s[i]-'a'`
  3. Find the maximum occurring character
  4. Find the first non-repeating char in O(n²)
  5. Find the first non-repeating char with the two-pass freq method
  6. Implement anagram check with sorting
  7. Implement anagram check with a frequency array
  8. Draw the LISTEN vs SILENT frequency visual in comments

 HINTS:
 - Normalize to lowercase.
 - Do not use strcmp; use string comparison or frequency arrays.
 - An all-zero array means anagram.

 STARTER CODE:
 vector<int> freq(26,0); freq[ch-'a']++;

 SOLUTION: A compact demo is below.

 ASCII VISUAL / COUNT STATE:
 banana frequency:
 a:3 b:1 n:2

 LISTEN/SILENT:
 add listen, subtract silent -> all zeros

 DRY RUN:
 swiss:
 pass1 s:3,w:1,i:1
 pass2 first freq==1 is w

 FLOW OF EXECUTION:
 input string -> scan/build frequency/transform -> produce output

 TIME COMPLEXITY CALCULATION:
 - Frequency array scans n chars = O(n).
 - Nested approach scans n for each n = O(n²).
 - Sort approach O(n log n), n/2^k=1 -> k=log₂n.

 SPACE COMPLEXITY CALCULATION:
 - array26/ASCII freq fixed size -> O(1).
 - Sorting copied strings -> O(n).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool anagramFreq(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), [](unsigned char ch){ return (char)tolower(ch); });
    transform(b.begin(), b.end(), b.begin(), [](unsigned char ch){ return (char)tolower(ch); });
    if (a.size() != b.size()) return false;
    vector<int> freq(26,0);
    for (int i=0;i<(int)a.size();i++) { freq[a[i]-'a']++; freq[b[i]-'a']--; }
    for (int x: freq) if (x != 0) return false;
    return true;
}

int main() {
    string s = "banana";
    vector<int> freq(26,0);
    for (char ch : s) freq[ch-'a']++;
    cout << "a count=" << freq['a'-'a'] << ", b count=" << freq['b'-'a'] << ", n count=" << freq['n'-'a'] << "\n";
    cout << "LISTEN/SILENT anagram? " << (anagramFreq("listen", "silent") ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
a count=3, b count=1, n count=2
LISTEN/SILENT anagram? YES
*/

