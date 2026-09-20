/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_Frequency_Counting task.cpp
│
│ REAL-WORLD SCENARIO:
│ Voting counter practice me tumhe letters count, max letter, first unique, and anagram checks solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Nested loop se char frequency print karo.
│ 2. freq[26] using `s[i]-'a'` se char frequency print karo.
│ 3. Max occurring character find karo.
│ 4. First non-repeating char O(n²) se find karo.
│ 5. First non-repeating char two-pass freq se find karo.
│ 6. Anagram check sorting se implement karo.
│ 7. Anagram check frequency array se implement karo.
│ 8. LISTEN vs SILENT ka frequency visual comments me draw karo.
│
│ HINTS:
│ - lowercase normalize karo.
│ - strcmp nahi; string comparison or freq arrays use karo.
│ - all zero array means anagram.
│
│ STARTER CODE:
│ vector<int> freq(26,0); freq[ch-'a']++;
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / COUNT STATE:
│ banana frequency:
│ a:3 b:1 n:2
│
│ LISTEN/SILENT:
│ add listen, subtract silent -> all zeros
│
│ DRY RUN:
│ swiss:
│ pass1 s:3,w:1,i:1
│ pass2 first freq==1 is w
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Frequency array scans n chars = O(n).
│ - Nested approach scans n for each n = O(n²).
│ - Sort approach O(n log n), n/2^k=1 -> k=log₂n.
│
│ SPACE COMPLEXITY CALCULATION:
│ - array26/ASCII freq fixed size -> O(1).
│ - Sorting copied strings -> O(n).
└────────────────────────────────────────────────────────────┘
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

