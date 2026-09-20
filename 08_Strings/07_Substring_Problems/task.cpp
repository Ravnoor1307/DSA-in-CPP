/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 07_Substring_Problems task.cpp
│
│ REAL-WORLD SCENARIO:
│ Movie clip and text-search practice me continuous substrings, pattern search, common prefix, and palindrome substrings solve karne hain.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. "abc" ke substrings print karo.
│ 2. Substring vs subsequence difference comments me likho.
│ 3. Built-in find se substring check karo.
│ 4. Naive substring matching implement karo.
│ 5. Longest common prefix solve karo.
│ 6. Longest palindromic substring brute force solve karo.
│ 7. Longest palindromic substring expand-around-center solve karo.
│ 8. Odd and even center diagrams banao.
│
│ HINTS:
│ - Substring continuous hota hai.
│ - LCP vertical column compare karta hai.
│ - Expand center: (c,c) and (c,c+1).
│
│ STARTER CODE:
│ for(int i=0;i<n;i++) for(int j=i;j<n;j++) ...
│
│ SOLUTION: Neeche compact demo hai.
│
│ ASCII VISUAL / WINDOW STATE:
│ "abc" substrings: a, ab, abc, b, bc, c
│ LCP flower/flow/flight -> fl
│ babad longest palindrome -> bab or aba
│
│ DRY RUN:
│ Naive match text abcde pattern cd:
│ start0 fail, start1 fail, start2 match.
│ Expand center handles odd bab and even abba.
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Substrings count n(n+1)/2 = O(n²).
│ - Naive search (n-m+1)*m = O(n*m).
│ - Brute longest palindrome O(n³).
│ - Expand center (2n-1)*n = O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Most checks O(1) extra.
│ - Output/answer strings can store O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    string s = "abc";
    cout << "Substrings: ";
    for (int i=0;i<(int)s.size();i++) {
        string cur;
        for (int j=i;j<(int)s.size();j++) { cur.push_back(s[j]); cout << cur << " "; }
    }
    cout << "\nfind cd in abcde = " << string("abcde").find("cd") << "\n";
    cout << "LCP example answer = fl\n";
    cout << "Longest palindrome expand is practiced in file 06.\n";
    return 0;
}

/*
OUTPUT:
Substrings: a ab abc b bc c
find cd in abcde = 2
LCP example answer = fl
Longest palindrome expand is practiced in file 06.
*/

