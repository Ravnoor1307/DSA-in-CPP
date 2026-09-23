/*
═══════════════════════════════════════════════
 LONGEST COMMON PREFIX
 ⏱️ TIME COMPLEXITY: O(k*L) — k strings compared column by column up to min length L, extra space O(L)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In phone contacts, find the common starting label of "flower", "flow", and "flight".
 Comparing characters vertically, column by column, reveals the shared prefix.

 📖 THEORY:
 - Treat the first string as the reference prefix.
 - Compare character index c from 0 onward across all strings.
 - Stop when any string ends or a mismatch appears.
 - Append each matched character to the answer.
 - Example output is "fl".

 ASCII VISUAL / WINDOW STATE:
 words:
 flower
 flow
 flight

 vertical comparison:
 col0: f f f -> match add f
 col1: l l l -> match add l
 col2: o o i -> mismatch stop
 LCP = "fl"

 🧠 LOGIC — STEP BY STEP:
 Step 1: If the list is empty, return "".
    WHY: there is no prefix to compute.
 Step 2: For each column c, read expected = words[0][c].
    WHY: the first word defines the candidate characters.
 Step 3: Compare every other word at column c.
    WHY: all words must share the character at that column.
 Step 4: If a word is shorter or differs, return the answer so far.
    WHY: the common prefix ends at the first break.
 Step 5: Otherwise append the matched character and continue.
    WHY: the shared prefix extends by one.

 DRY RUN:
 c=0: all f -> ans=f
 c=1: all l -> ans=fl
 c=2: flower has o, flight has i -> stop
 return fl

 FLOW OF EXECUTION:
 input word list -> take first word as prefix -> compare column by column -> stop on mismatch/short word -> print prefix

 TIME COMPLEXITY CALCULATION:
 - Let k strings and min length L.
 - For each column up to L, compare k strings.
 - Worst comparisons = k*L.
 -> Time Complexity = O(k*L).

 SPACE COMPLEXITY CALCULATION:
 - Answer prefix length at most L.
 -> Extra Space Complexity = O(L).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

string longestCommonPrefix(const vector<string>& words) {
    if (words.empty()) return "";
    string ans;
    for (int c = 0; c < (int)words[0].size(); c++) {
        char expected = words[0][c];
        for (int r = 1; r < (int)words.size(); r++) {
            if (c >= (int)words[r].size() || words[r][c] != expected) return ans;
        }
        ans.push_back(expected);
    }
    return ans;
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest common prefix = " << longestCommonPrefix(words) << "\n";
    return 0;
}

/*
OUTPUT:
Longest common prefix = fl
*/

