/*
═══════════════════════════════════════════════
 TASK SET — PALINDROME PROBLEMS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A mirror-word practice session needs plots to check words,
    phrases, and numbers for palindromes. From a simple reverse-compare word check
    up to ignoring case, spaces, and punctuation, these tasks build the logic behind
    text validators and phrase checkers.

 🧠 HOW TO SOLVE: For words, reverse+compare or build the reverse manually; for
    the O(1) version use two pointers left/right that shrink toward the center.
    Use tolower and isalnum to ignore case, spaces, and punctuation. Convert a
    number with to_string and check the string (negatives are never palindromes —
    the '-' sign breaks the symmetry). Two pointers compare floor(n/2) pairs.

 MODES/TOPICS COVERED:
  1. Write a reverse + compare palindrome check
  2. Check by building the reversed string manually
  3. Two-pointer O(1) space palindrome check
  4. Draw the pointer dry run for MADAM and RACECAR in comments
  5. Ignore case and spaces: check "Nitin"
  6. Ignore punctuation phrase: "A man, a plan, a canal: Panama"
  7. Check number 121 using the string method
  8. Write the complexity comparison table

 HINTS:
 - Use tolower and isalnum.
 - Two pointers compare floor(n/2) pairs.
 - Negative numbers are not palindromes.

 STARTER CODE:
 bool isPal(string s){ int l=0,r=s.size()-1; }

 SOLUTION: A compiled demo is below.

 ASCII VISUAL / POINTER STATE:
 MADAM:
 [M][A][D][A][M]
  L           R -> match
     L     R    -> match
 center -> true

 DRY RUN:
 Nitin ignore case:
 n vs n, i vs i, center t -> true
 121 -> "121" -> true

 FLOW OF EXECUTION:
 input string -> scan/split/pointer movement -> build/modify answer -> print result

 TIME COMPLEXITY CALCULATION:
 - Reverse approaches O(n) time because reverse/compare scan n chars.
 - Two-pointer checks floor(n/2) pairs -> O(n).
 - Ignore spaces pointer moves <= n -> O(n).

 SPACE COMPLEXITY CALCULATION:
 - Two-pointer approaches O(1) extra.
 - Reverse and number-to-string use O(n)/O(d) extra.
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

bool isPal(const string& s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main() {
    cout << "MADAM -> " << (isPal("MADAM") ? "YES" : "NO") << "\n";
    string num = to_string(121);
    cout << "121 -> " << (isPal(num) ? "YES" : "NO") << "\n";
    cout << "Best basic approach: two pointers O(n) time and O(1) space.\n";
    return 0;
}

/*
OUTPUT:
MADAM -> YES
121 -> YES
Best basic approach: two pointers O(n) time and O(1) space.
*/

