/*
═══════════════════════════════════════════════
 STRING COMPRESSION (RUN-LENGTH)
 ⏱️ TIME COMPLEXITY: O(n) — loop from index 1 to n-1 runs n-1 times with constant work, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a warehouse inventory, identical items are grouped consecutively. Writing "aaabbc"
 as "a3b2c1" gives a compact count format.

 📖 THEORY:
 - Track the current character and its count.
 - While the next char is the same, increment the count.
 - When the char changes, append the current char + its count to the answer.
 - Remember to append the final group at the end.
 - Edge case: a single char "a" becomes "a1".

 ASCII VISUAL / COUNT STATE:
 s="aaabbc"
 groups:
 aaa -> a3
 bb  -> b2
 c   -> c1
 result = a3b2c1

 Pointer visual:
 [a][a][a][b][b][c]
  count 1 2 3 flush a3, count b...

 🧠 LOGIC — STEP BY STEP:
 Step 1: If the string is empty, return "".
    WHY: avoids indexing into an empty string.
 Step 2: Initialize current = s[0] and count = 1.
    WHY: the first run starts at the first character.
 Step 3: From i=1 to n-1: if s[i] == current, count++.
    WHY: the run continues, so extend its length.
 Step 4: Else append current + count, then reset to the new char with count 1.
    WHY: the run ended, so emit it and begin the next run.
 Step 5: After the loop, append the last group.
    WHY: the final run has no following change to trigger the flush.

 DRY RUN:
 i=1 a same count2
 i=2 a same count3
 i=3 b different -> append a3, reset b1
 i=4 b same count2
 i=5 c different -> append b2, reset c1
 end append c1

 FLOW OF EXECUTION:
 input string -> track current run -> on change append char+count -> append last group -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop from index 1 to n-1 runs n-1 times.
 - Each iteration constant compare/increment/append group.
 - Total characters processed n.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Compressed answer can store up to about 2n chars (e.g., a1b1c1).
 -> Extra Space Complexity = O(n).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string compressString(const string& s) {
    if (s.empty()) return "";
    string ans;
    char current = s[0];
    int count = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == current) count++;
        else {
            ans.push_back(current);
            ans += to_string(count);
            current = s[i];
            count = 1;
        }
    }
    ans.push_back(current);
    ans += to_string(count);
    return ans;
}

int main() {
    cout << "aaabbc -> " << compressString("aaabbc") << "\n";
    cout << "a -> " << compressString("a") << "\n";
    return 0;
}

/*
OUTPUT:
aaabbc -> a3b2c1
a -> a1
*/

