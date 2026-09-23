/*
═══════════════════════════════════════════════
 PALINDROME NUMBER — STRING METHOD
 ⏱️ TIME COMPLEXITY: O(d) where d = number of digits — to_string creates d digits, two-pointer check compares floor(d/2) pairs, extra space O(d)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A car number plate reads "121" the same from left to right and right to left.
 Converting the number to a string makes the palindrome check straightforward.

 📖 THEORY:
 - Convert the number to a string with to_string(num).
 - Check the string by reverse/copy-compare or with two pointers.
 - A negative number is usually not treated as a palindrome because of the '-' sign.
 - 121 -> "121" is a palindrome.
 - 123 -> "123" is not a palindrome.

 ASCII VISUAL / POINTER STATE:
 num=121
 string="121"
 [1][2][1]
 L     R -> 1==1
 center 2 -> YES

 num=-121
 "-121" reverse "121-" -> NO

 🧠 LOGIC — STEP BY STEP:
 Step 1: If num < 0, return false.
    WHY: the negative sign makes the string read differently backwards.
 Step 2: Convert num to a string s.
    WHY: digit access with indices becomes trivial on a string.
 Step 3: Set left=0, right=s.size()-1.
    WHY: compare the outermost digit pair first.
 Step 4: While left<right, compare s[left] and s[right].
    WHY: symmetric digit pairs must all match.
 Step 5: On mismatch return false, else move pointers inward.
    WHY: any unequal pair means it is not a palindrome.

 DRY RUN:
 num=121
 s=to_string(121)="121"
 compare s[0] and s[2] -> 1==1
 stop center -> palindrome

 FLOW OF EXECUTION:
 input number -> to_string -> two-pointer compare digit pairs -> print result

 TIME COMPLEXITY CALCULATION:
 - to_string creates d digits where d is number of digits.
 - Two-pointer check compares floor(d/2) pairs.
 -> Time Complexity = O(d), d = digits count.

 SPACE COMPLEXITY CALCULATION:
 - String stores d digits.
 -> Extra Space Complexity = O(d).
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

bool isNumberPalindrome(int num) {
    if (num < 0) return false;
    string s = to_string(num);
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int num = 121;
    cout << num << " palindrome number? " << (isNumberPalindrome(num) ? "YES" : "NO") << "\n";
    cout << "123 palindrome number? " << (isNumberPalindrome(123) ? "YES" : "NO") << "\n";
    return 0;
}

/*
OUTPUT:
121 palindrome number? YES
123 palindrome number? NO
*/

