/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_remove_char_recursive.cpp
│
│ REAL-WORLD SCENARIO:
│ Clean-up bot sentence se sab `a` characters hata raha hai. Recursion current character decide karta hai: keep ya skip, then rest process.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Function removeChar(s,index,target).
│ 2. Base case: index == n return empty string.
│ 3. Recursively get answer for rest string.
│ 4. If current char target hai, skip it.
│ 5. Otherwise current + rest return karo.
│
│ ASCII VISUAL / STRING STATE:
│ s="banana", target='a'
│ b keep
│ a skip
│ n keep
│ a skip
│ n keep
│ a skip
│ result "bnn"
│
│ DRY RUN:
│ remove index0 b -> keep b + remove rest
│ index1 a -> skip
│ index2 n -> keep
│ index3 a -> skip
│ index4 n -> keep
│ index5 a -> skip
│ base -> empty, unwind builds bnn
│
│ FLOW OF EXECUTION:
│ input string -> recursive index/pointers -> base case -> build/return output
│
│ COMPLEXITY CALCULATION:
│ - There are n+1 recursive calls.
│ - String concatenation in this simple version can copy characters repeatedly.
│ - Conceptually each char decision once = O(n), but returned-string concatenation can be O(n²) in simple implementation.
│ -> Time Complexity = O(n²) for this direct string-return version.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Stack depth n.
│ - Output string up to n chars plus temporaries.
│ -> Space Complexity = O(n²) temporaries in simple version, O(n) output logically.
│ APPROACH COMPARISON TABLE:
│ Return new string = cleaning note by rebuilding papers, simple but can be O(n²).
│ Pass answer by reference = cleaning in one output basket, O(n) time/O(n) output.
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string removeCharRec(const string& s, int index, char target) {
    if (index == (int)s.size()) return "";
    string rest = removeCharRec(s, index + 1, target);
    if (s[index] == target) return rest;
    return string(1, s[index]) + rest;
}

int main() {
    cout << "banana without a = " << removeCharRec("banana", 0, 'a') << "\n";
    cout << "Comparison: build-answer-by-reference can make this O(n).\n";
    return 0;
}

/*
OUTPUT:
banana without a = bnn
Comparison: build-answer-by-reference can make this O(n).
*/

