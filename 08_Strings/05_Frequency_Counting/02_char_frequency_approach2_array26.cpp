/*
═══════════════════════════════════════════════
 CHARACTER FREQUENCY — APPROACH 2 (ARRAY OF 26)
 ⏱️ TIME COMPLEXITY: O(n) — single scan with O(1) index-and-increment per char, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 An alphabet attendance board has 26 fixed boxes, one for each letter from a to z.
 Counting each letter directly into its own box is the fastest approach.

 📖 THEORY:
 - Create `vector<int> freq(26,0)`.
 - For a lowercase character ch, index = ch - 'a'.
 - Increment freq[index]++.
 - Mapping trick: a->0, b->1, ..., z->25.
 - This array-indexing trick appears again in anagram checks and sliding-window
   problems, so it is worth mastering.

 ASCII VISUAL / COUNT STATE:
 s="banana"

 a b c d ... n ... z
 3 1 0 0 ... 2 ... 0

 Mapping:
 'a'-'a'=0
 'b'-'a'=1
 'n'-'a'=13

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create freq(26,0).
    WHY: 26 boxes for the English alphabet, initialized to 0.
 Step 2: For each char ch, compute index = ch - 'a'.
    WHY: subtracting the ASCII of 'a' maps a-z onto 0-25.
 Step 3: Increment freq[index].
    WHY: each occurrence of the character bumps its own box.
 Step 4: Output letters whose box is non-zero.
    WHY: only chars that actually appear show their count.

 DRY RUN:
 b -> index 1 -> freq[1]=1
 a -> index 0 -> freq[0]=1
 n -> index 13 -> freq[13]=1
 a -> freq[0]=2
 n -> freq[13]=2
 a -> freq[0]=3

 FLOW OF EXECUTION:
 input string -> map char to index 0-25 -> increment frequency -> print non-zero counts

 TIME COMPLEXITY CALCULATION:
 - Loop scans n characters once.
 - Each char direct index and increment = O(1).
 - Total operations proportional to n.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Frequency array has fixed 26 cells.
 -> Extra Space Complexity = O(26) = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "banana";
    vector<int> freq(26, 0);
    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') freq[ch - 'a']++; // array-indexing trick
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) cout << char('a' + i) << " -> " << freq[i] << "\n";
    }
    return 0;
}

/*
OUTPUT:
a -> 3
b -> 1
n -> 2
*/

