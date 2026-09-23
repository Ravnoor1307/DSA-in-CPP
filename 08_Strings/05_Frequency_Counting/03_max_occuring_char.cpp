/*
═══════════════════════════════════════════════
 MAX OCCURRING CHARACTER
 ⏱️ TIME COMPLEXITY: O(n) — first scan counts n chars, second scan reads fixed 26 cells, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a voting booth, the letter that gets the highest number of votes wins. Build a
 frequency array and scan it to find the character with the maximum count.

 📖 THEORY:
 - Create a frequency array of 26 boxes.
 - Scan the string and fill the counts.
 - Scan the frequency array to find the maximum count and its character.
 - In a tie, the earliest alphabet can be chosen.
 - For lowercase strings, direct mapping ch - 'a' works.

 ASCII VISUAL / COUNT STATE:
 s="success"
 counts:
 c:2, e:1, s:3, u:1
 max = s with 3

 freq boxes:
 a b c d e ... s ... u
 0 0 2 0 1 ... 3 ... 1

 🧠 LOGIC — STEP BY STEP:
 Step 1: Create freq(26,0).
    WHY: 26 boxes hold counts for each letter.
 Step 2: Scan the string and fill counts.
    WHY: each char increments its own box.
 Step 3: Scan freq and track the max.
    WHY: the box with the largest value holds the winner.
 Step 4: Report the character of the max.
    WHY: char('a' + index) converts the index back to a letter.

 DRY RUN:
 scan success:
 s count1, u1, c1, c2, e1, s2, s3
 scan freq: max char s count3

 FLOW OF EXECUTION:
 input string -> fill 26 frequency boxes -> scan boxes for max -> print winner char

 TIME COMPLEXITY CALCULATION:
 - First scan n chars.
 - Second scan fixed 26 cells.
 - Total = n + 26.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Fixed 26 frequency cells.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "success";
    vector<int> freq(26, 0);
    for (char ch : s) if (ch >= 'a' && ch <= 'z') freq[ch - 'a']++;

    int bestIndex = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[bestIndex]) bestIndex = i;
    }
    cout << "Max occurring char = " << char('a' + bestIndex)
         << " with count " << freq[bestIndex] << "\n";
    return 0;
}

/*
OUTPUT:
Max occurring char = s with count 3
*/

