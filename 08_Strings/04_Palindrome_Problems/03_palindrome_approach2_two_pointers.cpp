/*
═══════════════════════════════════════════════
 PALINDROME CHECK — APPROACH 2 (TWO POINTERS)
 ⏱️ TIME COMPLEXITY: O(n) — up to floor(n/2) pointer-pair comparisons, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In "MADAM", compare from both ends: M with M, A with A, until the pointers meet at
 the center D. This two-pointer walk validates a palindrome in a single pass without
 making any copy.

 📖 THEORY:
 - Start with left=0 and right=n-1.
 - While left<right, compare s[left] and s[right].
 - On mismatch -> return false; on match -> left++ and right--.
 - When the pointers meet or cross, every pair matched -> palindrome true.
 - No extra string is created, so space is O(1).
 - Starter input for the demo: "MADAM".

 ASCII VISUAL / POINTER STATE:
 MADAM:
 [M][A][D][A][M]
  L           R   M==M -> move
     L     R      A==A -> move
        L         stop -> YES

 RACECAR:
 R==R, A==A, C==C, center E -> YES

 🧠 LOGIC — STEP BY STEP:
 Step 1: Set left=0, right=n-1.
    WHY: the two ends are the first pair to compare.
 Step 2: While left<right, compare s[left] and s[right].
    WHY: each iteration checks one symmetric pair of characters.
 Step 3: On mismatch, return false.
    WHY: one unequal symmetric pair means it is not a palindrome.
 Step 4: On match, move left++ and right--.
    WHY: the pointers shrink inward toward the center.
 Step 5: When pointers meet/cross, return true.
    WHY: every symmetric pair matched, so the whole string is symmetric.

 DRY RUN:
 s=madam
 step1 left0 right4 M==M
 step2 left1 right3 A==A
 step3 left2 right2 stop
 answer YES

 FLOW OF EXECUTION:
 input string -> left=0 right=n-1 -> compare ends while left<right -> move pointers inward -> print result

 TIME COMPLEXITY CALCULATION:
 - At each step two characters checked.
 - Pointer pair checks = floor(n/2).
 - floor(n/2) grows linearly with n.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Only left and right variables.
 -> Extra Space Complexity = O(1).
 APPROACH COMPARISON TABLE:
 Reverse compare = mirror photo copy, O(n) time/O(n) space.
 Manual reverse = build reverse board, O(n) time/O(n) space.
 Two pointers = compare from both doors, O(n) time/O(1) space.
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindromeTwoPointers(const string& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        cout << "compare " << s[left] << " and " << s[right] << "\n";
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "MADAM";
    cout << s << " palindrome? " << (isPalindromeTwoPointers(s) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
compare M and M
compare A and A
MADAM palindrome? YES
*/

