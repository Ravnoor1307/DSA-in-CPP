/*
═══════════════════════════════════════════════
 ANAGRAM CHECK — APPROACH 1 (SORTING)
 ⏱️ TIME COMPLEXITY: O(n log n) — sorting n chars dominates, comparing sorted strings scans n chars, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Scrabble tiles of LISTEN and SILENT are built from the same letters. After sorting,
 the letters fall into the same order, so a simple equality check proves the anagram.

 📖 THEORY:
 - Both strings must have equal length.
 - Both strings can be lowered/normalized first.
 - Sort both strings.
 - If the sorted strings are equal, they are anagrams.
 - The sorting approach is simple but costs O(n log n).

 ASCII VISUAL / COUNT STATE:
 LISTEN -> lowercase listen -> sort eilnst
 SILENT -> lowercase silent -> sort eilnst
 Same sorted result -> anagram

 Tile boxes after sorting:
 [e][i][l][n][s][t]
 [e][i][l][n][s][t]

 🧠 LOGIC — STEP BY STEP:
 Step 1: Normalize both strings (keep letters, convert to lowercase).
    WHY: the check must ignore case and non-letter characters.
 Step 2: If the lengths differ, return false.
    WHY: anagrams use exactly the same characters, so counts must match.
 Step 3: Sort both strings.
    WHY: sorting rearranges letters into the same canonical order.
 Step 4: Return sorted a == sorted b.
    WHY: equality proves identical letter multisets.

 DRY RUN:
 s1=listen, s2=silent
 sort s1 -> eilnst
 sort s2 -> eilnst
 compare equal -> true

 FLOW OF EXECUTION:
 input strings -> lowercase + keep letters -> check length -> sort both -> compare sorted results -> print result

 TIME COMPLEXITY CALCULATION:
 - Sorting n characters costs O(n log n).
 - Log idea in sort: divide groups; n/2^k=1 -> k=log₂n.
 - Comparing sorted strings scans n chars.
 -> Total Time Complexity = O(n log n).

 SPACE COMPLEXITY CALCULATION:
 - Sorting string copies use O(n) because parameters are copied in this demo.
 -> Extra Space Complexity = O(n).
═══════════════════════════════════════════════
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

