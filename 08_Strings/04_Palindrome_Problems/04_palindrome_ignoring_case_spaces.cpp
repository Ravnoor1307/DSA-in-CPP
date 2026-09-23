/*
═══════════════════════════════════════════════
 PALINDROME CHECK — IGNORING CASE AND SPACES
 ⏱️ TIME COMPLEXITY: O(n) — left and right pointers each move across the string at most once, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 The famous phrase "A man, a plan, a canal: Panama" becomes a palindrome when
 spaces and case are ignored. Only letters/digits are compared, so punctuation
 and blank spaces are just skipped.

 📖 THEORY:
 - Use left/right pointers moving toward each other.
 - Skip every non-alphanumeric character (spaces, punctuation).
 - Compare the lowercase versions of both characters.
 - Mismatch -> return false; match -> keep going.
 - Pointers meet/cross -> return true.
 - Works for names like "Nitin" and phrase-style palindromes.

 ASCII VISUAL / POINTER STATE:
 "Nitin"
 N vs n -> lowercase n==n
 i vs i -> yes
 t center -> YES

 "A man a plan"
 spaces skip:
 A ... a compare lowercase
 only alphanumeric characters considered.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Place left at index 0 and right at index n-1.
    WHY: the outermost characters are compared first.
 Step 2: Advance left while it points at a non-alphanumeric char.
    WHY: spaces and punctuation are ignored entirely.
 Step 3: Move right back while it points at a non-alphanumeric char.
    WHY: the right side skips the same junk before comparing.
 Step 4: Compare both characters after converting to lowercase.
    WHY: case differences ('N' vs 'n') are ignored.
 Step 5: On mismatch return false, else move pointers inward.
    WHY: a single unequal pair breaks the palindrome.
 Step 6: When left crosses right, return true.
    WHY: every meaningful pair matched.

 DRY RUN:
 s="Nitin"
 left N, right n -> tolower both n match
 left i, right i match
 center t stop -> YES

 FLOW OF EXECUTION:
 input string -> skip non-alphanumerics from left/right -> compare lowercase chars -> move pointers inward -> print result

 TIME COMPLEXITY CALCULATION:
 - left and right each move across string at most once.
 - Total pointer moves <= n.
 - Each move constant checks.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Only two pointers and chars.
 -> Extra Space Complexity = O(1).
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

bool validPalindromeClean(const string& s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum((unsigned char)s[left])) left++;
        while (left < right && !isalnum((unsigned char)s[right])) right--;
        char a = (char)tolower((unsigned char)s[left]);
        char b = (char)tolower((unsigned char)s[right]);
        cout << "compare " << a << " and " << b << "\n";
        if (a != b) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s1 = "Nitin";
    string s2 = "A man, a plan, a canal: Panama";
    cout << s1 << " -> " << (validPalindromeClean(s1) ? "YES" : "NO") << "\n";
    cout << "Phrase -> " << (validPalindromeClean(s2) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
compare n and n
compare i and i
Nitin -> YES
compare a and a
compare m and m
compare a and a
compare n and n
compare a and a
compare p and p
compare l and l
compare a and a
compare n and n
compare a and a
Phrase -> YES
*/

