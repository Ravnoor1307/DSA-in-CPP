/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 06_anagram_check_approach1_sort.cpp
│
│ REAL-WORLD SCENARIO:
│ Scrabble tiles LISTEN and SILENT same letters se bane hain. Sorting se letters same order me aa jaate hain, then compare easy hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Dono strings ka length same hona chahiye.
│ 2. Dono strings lowercase/normalize kar sakte hain.
│ 3. Sort both strings.
│ 4. Sorted strings equal -> anagram.
│ 5. Sorting approach simple hai but O(n log n).
│
│ ASCII VISUAL / COUNT STATE:
│ LISTEN -> lowercase listen -> sort eilnst
│ SILENT -> lowercase silent -> sort eilnst
│ Same sorted result -> anagram
│
│ Tile boxes after sorting:
│ [e][i][l][n][s][t]
│ [e][i][l][n][s][t]
│
│ DRY RUN:
│ s1=listen, s2=silent
│ sort s1 -> eilnst
│ sort s2 -> eilnst
│ compare equal -> true
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Sorting n characters costs O(n log n).
│ - Log idea in sort: divide groups; n/2^k=1 -> k=log₂n.
│ - Comparing sorted strings scans n chars.
│ -> Total Time Complexity = O(n log n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Sorting string copies use O(n) because parameters are copied in this demo.
│ -> Extra Space Complexity = O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string lowerOnlyLetters(string s) {
    string out;
    for (char ch : s) if (isalpha((unsigned char)ch)) out.push_back((char)tolower((unsigned char)ch));
    return out;
}

bool areAnagramsSort(string a, string b) {
    a = lowerOnlyLetters(a);
    b = lowerOnlyLetters(b);
    if (a.size() != b.size()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << "sorted a=" << a << ", sorted b=" << b << "\n";
    return a == b;
}

int main() {
    cout << "LISTEN and SILENT anagram? " << (areAnagramsSort("LISTEN", "SILENT") ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
LISTEN and SILENT anagram? sorted a=eilnst, sorted b=eilnst
YES
*/

