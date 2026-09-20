/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_palindrome_number_string.cpp
│
│ REAL-WORLD SCENARIO:
│ Car number plate 121 left-to-right and right-to-left same dikhta hai. Number ko string me convert karke palindrome check easy hota hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Number ko `to_string(num)` se string banao.
│ 2. String reverse/copy compare karo ya two pointers use karo.
│ 3. Negative number usually palindrome nahi maana jata because '-' sign.
│ 4. 121 -> "121" palindrome.
│ 5. 123 -> "123" not palindrome.
│
│ ASCII VISUAL / POINTER STATE:
│ num=121
│ string="121"
│ [1][2][1]
│ L     R -> 1==1
│ center 2 -> YES
│
│ num=-121
│ "-121" reverse "121-" -> NO
│
│ DRY RUN:
│ num=121
│ s=to_string(121)="121"
│ compare s[0] and s[2] -> 1==1
│ stop center -> palindrome
│
│ FLOW OF EXECUTION:
│ input string -> scan/split/pointer movement -> build/modify answer -> print result
│
│ COMPLEXITY CALCULATION:
│ - to_string creates d digits where d is number of digits.
│ - Two-pointer check compares floor(d/2) pairs.
│ -> Time Complexity = O(d), d = digits count.
│
│ SPACE COMPLEXITY CALCULATION:
│ - String stores d digits.
│ -> Extra Space Complexity = O(d).
└────────────────────────────────────────────────────────────┘
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

