/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_string_reverse_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Name board ko ulta padhna hai. Recursive idea: first character ko baad me lagao, baaki string ko recursively reverse kar do.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Base case: empty string or length 1, same return.
│ 2. Recursive case: reverse(s.substr(1)) + s[0].
│ 3. Pehla char end me chala jata hai.
│ 4. Smaller problem length n-1 ka hota hai.
│ 5. This is easy to understand, but substr copies can cost extra.
│
│ ASCII VISUAL / STRING STATE:
│ s="abc"
│ reverse("abc") = reverse("bc") + 'a'
│ reverse("bc")  = reverse("c") + 'b'
│ reverse("c")   = "c"
│ unwind: "c"+b="cb", "cb"+a="cba"
│
│ DRY RUN:
│ abc -> bc -> c base
│ return c
│ add b -> cb
│ add a -> cba
│
│ FLOW OF EXECUTION:
│ input string -> recursive index/pointers -> base case -> build/return output
│
│ COMPLEXITY CALCULATION:
│ - There are n recursive calls.
│ - In this simple substr version, each substr may copy remaining chars.
│ - Copy cost roughly n + (n-1) + ... + 1 = n(n+1)/2.
│ -> Time Complexity = O(n²) with substr copying.
│ - Pointer/index version can be O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack depth n.
│ - New strings created during substr/concatenation.
│ -> Space Complexity = O(n²) temporary in simple version, O(n) answer logically.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string reverseRecursive(string s) {
    if (s.size() <= 1) return s;
    return reverseRecursive(s.substr(1)) + s[0];
}

int main() {
    cout << "reverse(abc) = " << reverseRecursive("abc") << "\n";
    return 0;
}

/*
OUTPUT:
reverse(abc) = cba
*/

