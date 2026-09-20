/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_anagram_check_approach2_freq_array.cpp
│
│ REAL-WORLD SCENARIO:
│ Scrabble counter me 26 boxes hain. LISTEN ke letters add karo aur SILENT ke letters subtract karo; agar all boxes zero, anagram hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Length same check karo after normalization.
│ 2. freq[26] zero initialize.
│ 3. First string ke chars ke liye freq[ch-'a']++.
│ 4. Second string ke chars ke liye freq[ch-'a']--.
│ 5. End me all zero -> anagram.
│ 6. This is O(n) and very important frequency-array trick.
│
│ ASCII VISUAL / COUNT STATE:
│ LISTEN vs SILENT:
│ listen adds: l,i,s,t,e,n
│ silent subtracts: s,i,l,e,n,t
│
│ Final freq array:
│ a b c d e f ... i ... l ... n ... s t
│ 0 0 0 0 0 0 ... 0 ... 0 ... 0 ... 0 0
│ all zero -> anagram
│
│ DRY RUN:
│ add listen:
│ l:+1, i:+1, s:+1, t:+1, e:+1, n:+1
│ subtract silent:
│ s:0, i:0, l:0, e:0, n:0, t:0
│ all zero -> YES
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Normalize first string scans n chars.
│ - Normalize second string scans n chars.
│ - Frequency update scans n chars.
│ - Final fixed 26 scan.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Fixed 26 array.
│ -> Extra Space Complexity = O(1).
│ APPROACH COMPARISON TABLE:
│ Sort = arrange Scrabble tiles alphabetically, O(n log n) time/O(n) copy space.
│ Freq array = 26 attendance boxes, O(n) time/O(1) space.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string normalizeLetters(string s) {
    string out;
    for (char ch : s) if (isalpha((unsigned char)ch)) out.push_back((char)tolower((unsigned char)ch));
    return out;
}

bool areAnagramsFreq(string a, string b) {
    a = normalizeLetters(a);
    b = normalizeLetters(b);
    if (a.size() != b.size()) return false;
    vector<int> freq(26, 0);
    for (int i = 0; i < (int)a.size(); i++) {
        freq[a[i] - 'a']++;
        freq[b[i] - 'a']--;
    }
    for (int value : freq) if (value != 0) return false;
    return true;
}

int main() {
    cout << "LISTEN and SILENT anagram? " << (areAnagramsFreq("LISTEN", "SILENT") ? "YES" : "NO") << "\n";
    cout << "Comparison: sort O(n log n), freq-array O(n).\n";
    return 0;
}

/*
OUTPUT:
LISTEN and SILENT anagram? YES
Comparison: sort O(n log n), freq-array O(n).
*/

