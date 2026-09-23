/*
═══════════════════════════════════════════════
 ANAGRAM CHECK — APPROACH 2 (FREQUENCY ARRAY)
 ⏱️ TIME COMPLEXITY: O(n) — normalizing and frequency updates scan n chars, final fixed 26 scan, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A Scrabble counter has 26 boxes. Add the letters of LISTEN and subtract the letters
 of SILENT; if every box ends at zero, the words are anagrams.

 📖 THEORY:
 - Check equal length after normalization.
 - Initialize freq[26] to zero.
 - For each char of the first string: freq[ch-'a']++.
 - For each char of the second string: freq[ch-'a']--.
 - If all boxes are zero at the end, they are anagrams.
 - This is O(n) and is a very important frequency-array trick.

 ASCII VISUAL / COUNT STATE:
 LISTEN vs SILENT:
 listen adds: l,i,s,t,e,n
 silent subtracts: s,i,l,e,n,t

 Final freq array:
 a b c d e f ... i ... l ... n ... s t
 0 0 0 0 0 0 ... 0 ... 0 ... 0 ... 0 0
 all zero -> anagram

 🧠 LOGIC — STEP BY STEP:
 Step 1: Normalize both strings (keep letters, lowercase) and compare lengths.
    WHY: anagrams must have the exact same multiset of letters.
 Step 2: Initialize freq(26,0).
    WHY: one box per letter to track net balance.
 Step 3: Increment for the first string and decrement for the second in one loop.
    WHY: additions and subtractions cancel matching letters directly.
 Step 4: If any box is non-zero, return false.
    WHY: a non-zero box means some letter count differs.
 Step 5: Otherwise return true.
    WHY: all boxes zero means perfect cancellation.

 DRY RUN:
 add listen:
 l:+1, i:+1, s:+1, t:+1, e:+1, n:+1
 subtract silent:
 s:0, i:0, l:0, e:0, n:0, t:0
 all zero -> YES

 FLOW OF EXECUTION:
 input strings -> normalize -> length check -> net frequency +/- -> verify all zero -> print result

 TIME COMPLEXITY CALCULATION:
 - Normalize first string scans n chars.
 - Normalize second string scans n chars.
 - Frequency update scans n chars.
 - Final fixed 26 scan.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Fixed 26 array.
 -> Extra Space Complexity = O(1).
 APPROACH COMPARISON TABLE:
 Sort = arrange Scrabble tiles alphabetically, O(n log n) time/O(n) copy space.
 Freq array = 26 attendance boxes, O(n) time/O(1) space.
═══════════════════════════════════════════════
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

