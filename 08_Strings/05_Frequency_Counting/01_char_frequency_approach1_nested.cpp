/*
═══════════════════════════════════════════════
 CHARACTER FREQUENCY — APPROACH 1 (NESTED LOOPS)
 ⏱️ TIME COMPLEXITY: O(n²) worst — inner loop rescans the full string for every outer character, extra space O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A class monitor counts how many times each letter appears in every student's name,
 but he re-scans the whole register from the start for each letter. The nested
 approach is simple to write but slow.

 📖 THEORY:
 - Use a visited array so the same character is not counted twice.
 - The outer loop picks each character of the string.
 - The inner loop re-scans the entire string counting that character's occurrences.
 - Already visited characters are skipped, so each distinct char is printed once.
 - Worst case: for every one of the n characters the inner loop scans n positions.

 ASCII VISUAL / COUNT STATE:
 s="banana"
 Outer b -> scan all -> count 1
 Outer a -> scan all -> count 3
 Outer n -> scan all -> count 2
 Later a/n visited -> skip

 Visual counts:
 b:1, a:3, n:2

 🧠 LOGIC — STEP BY STEP:
 Step 1: Allocate a visited array of size n, all false.
    WHY: it records which positions have already been counted.
 Step 2: Outer loop chooses each index i.
    WHY: each unvisited position starts a new character count.
 Step 3: If visited[i] is true, skip it.
    WHY: that character was already counted under its first occurrence.
 Step 4: Inner loop j scans the whole string and counts matches.
    WHY: every occurrence of s[i] anywhere in the string must be found.
 Step 5: Mark every counted position visited.
    WHY: later duplicate starts are ignored.

 DRY RUN:
 i=0 b: j=0..5 count=1
 i=1 a: j=0..5 count=3
 i=2 n: j=0..5 count=2
 i=3 a visited skip
 i=4 n visited skip
 i=5 a visited skip

 FLOW OF EXECUTION:
 input string -> outer loop picks char -> inner loop counts matches -> mark visited -> print counts

 TIME COMPLEXITY CALCULATION:
 - Outer loop runs n times.
 - Inner loop can run n times for each outer character.
 - Worst comparisons = n*n = n².
 -> Time Complexity = O(n²).

 SPACE COMPLEXITY CALCULATION:
 - visited array size n.
 -> Extra Space Complexity = O(n).
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
    int n = s.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] == s[j]) {
                count++;
                visited[j] = true;
            }
        }
        cout << s[i] << " -> " << count << "\n";
    }
    return 0;
}

/*
OUTPUT:
b -> 1
a -> 3
n -> 2
*/

