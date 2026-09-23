/*
═══════════════════════════════════════════════
 FIRST NON-REPEATING CHARACTER — APPROACH 1 (NESTED)
 ⏱️ TIME COMPLEXITY: O(n²) worst — inner loop rescans the whole string for every character, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a queue, we must find the first unique token, but there is no helper counter.
 For every token the whole line must be scanned again to count its occurrences.

 📖 THEORY:
 - The outer loop chooses the current character.
 - The inner loop computes that character's total count.
 - The character whose count equals 1 appears first is the first non-repeating one.
 - Simple to write, but it is O(n²).
 - Fine for small strings and explanations; production prefers a frequency pass.

 ASCII VISUAL / COUNT STATE:
 s="swiss"
 i=0 s -> scan all, count 3 -> not unique
 i=1 w -> scan all, count 1 -> first non-repeating w
 Answer = w

 🧠 LOGIC — STEP BY STEP:
 Step 1: Outer loop over each index i.
    WHY: each character is a candidate in order of appearance.
 Step 2: Inner loop counts how many times s[i] occurs.
    WHY: the total count tells if the char repeats.
 Step 3: If count == 1, return s[i].
    WHY: first char in order with count 1 is the answer.
 Step 4: If none found, return '#'.
    WHY: a sentinel signalling no unique character exists.

 DRY RUN:
 Check s:
 compare s with s,w,i,s,s -> count3
 Check w:
 compare w with s,w,i,s,s -> count1 -> return w

 FLOW OF EXECUTION:
 input string -> pick char in order -> count all its occurrences -> first with count 1 -> print result

 TIME COMPLEXITY CALCULATION:
 - Outer loop can run n times.
 - Inner loop runs n times for each outer char.
 - Worst comparisons = n*n.
 -> Time Complexity = O(n²).

 SPACE COMPLEXITY CALCULATION:
 - No extra frequency array.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

char firstNonRepeatingNested(const string& s) {
    for (int i = 0; i < (int)s.size(); i++) {
        int count = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[i] == s[j]) count++;
        }
        if (count == 1) return s[i];
    }
    return '#';
}

int main() {
    string s = "swiss";
    cout << "First non-repeating = " << firstNonRepeatingNested(s) << "\n";
    return 0;
}

/*
OUTPUT:
First non-repeating = w
*/

