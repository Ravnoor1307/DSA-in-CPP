/*
═══════════════════════════════════════════════
 FIRST NON-REPEATING CHARACTER — APPROACH 2 (FREQUENCY, TWO-PASS)
 ⏱️ TIME COMPLEXITY: O(n) — pass 1 builds counts over n chars, pass 2 scans up to n chars, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In class attendance, first build the total-frequency register, then walk the line
 to find the first student whose count is 1. This is the two-pass frequency method.

 📖 THEORY:
 - PASS 1: build a frequency array/map from the whole string.
 - PASS 2: scan the original string left to right.
 - Return the first character whose freq == 1.
 - The second pass walks the original string so the order of first occurrence is kept.
 - For lowercase-only input a 26-cell array is enough; here a fixed 256-cell array
   covers full ASCII.

 ASCII VISUAL / COUNT STATE:
 s="swiss"
 PASS 1 counts:
 s:3, w:1, i:1
 PASS 2:
 s freq3 skip
 w freq1 -> answer w

 🧠 LOGIC — STEP BY STEP:
 Step 1 (PASS 1): Loop over the string and increment freq[ch].
    WHY: after this pass every character knows its total count.
 Step 2 (PASS 2): Loop over the string again.
    WHY: walking the original order finds the first unique char.
 Step 3: If freq[ch] == 1, return ch.
    WHY: the first such character seen is the first non-repeating.
 Step 4: If none found, return '#'.
    WHY: sentinel for "no unique character".

 DRY RUN:
 pass1: s,w,i,s,s counts build.
 pass2: index0 s not unique; index1 w unique -> return.

 FLOW OF EXECUTION:
 input string -> pass 1 fill frequencies -> pass 2 first char with count 1 -> print result

 TIME COMPLEXITY CALCULATION:
 - PASS 1 scans n chars.
 - PASS 2 scans up to n chars.
 - Total scans = 2n.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Fixed 256 frequency array used for ASCII.
 -> Extra Space Complexity = O(256) = O(1).
 APPROACH COMPARISON TABLE:
 Nested = ask every student by rescanning full line, O(n²) time/O(1) space.
 Frequency = make attendance register then one scan, O(n) time/O(1) ASCII space.
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

char firstNonRepeatingFreq(const string& s) {
    vector<int> freq(256, 0);
    for (unsigned char ch : s) freq[ch]++;
    for (unsigned char ch : s) {
        if (freq[ch] == 1) return (char)ch;
    }
    return '#';
}

int main() {
    string s = "swiss";
    cout << "First non-repeating using freq = " << firstNonRepeatingFreq(s) << "\n";
    cout << "Comparison: nested O(n^2), freq two-pass O(n).\n";
    return 0;
}

/*
OUTPUT:
First non-repeating using freq = w
Comparison: nested O(n^2), freq two-pass O(n).
*/

