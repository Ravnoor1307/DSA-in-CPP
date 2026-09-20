/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_Recursion_on_Strings task.cpp
│
│ REAL-WORLD SCENARIO:
│ String recursion practice lab me reverse, vowels, palindrome, subsequences, and remove-char solve karna hai.
│
│ LOGIC (step-by-step, Hinglish):
│ TASKS (easy -> hard):
│ 1. Reverse string recursively.
│ 2. Count vowels recursively.
│ 3. Palindrome string recursive two pointers.
│ 4. Generate all subsequences of "abc".
│ 5. Remove all `a` from string recursively.
│ 6. TAKE/SKIP tree comments me draw karo.
│ 7. Complexity for 2^n subsequences calculate karo.
│
│ HINTS:
│ - Index reaches n => base.
│ - Palindrome: left>=right true.
│ - Subsequences: current+s[index] and current.
│ - Remove char: keep or skip current.
│
│ STARTER CODE:
│ void gen(int i,string cur){ if(i==n)return; }
│
│ SOLUTION: Neeche combined demo hai.
│
│ ASCII VISUAL / STRING STATE:
│ abc subsequence tree leaves include:
│ "", a, b, c, ab, ac, bc, abc
│
│ racecar pointers: r/r, a/a, c/c, center e.
│
│ DRY RUN:
│ reverse abc -> cba
│ vowels education -> 5
│ banana remove a -> bnn
│
│ FLOW OF EXECUTION:
│ input string -> recursive index/pointers -> base case -> build/return output
│
│ COMPLEXITY CALCULATION:
│ - Vowel/palindrome linear calls -> O(n).
│ - Subsequences 2 choices per char -> 2^n leaves; printing copies up to n each -> O(n*2^n).
│ - Simple reverse/remove with substr/concat can be O(n²).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Recursion stack O(n).
│ - Subsequence output O(n*2^n).
│ - Answer strings O(n).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool pal(const string& s,int l,int r){ return l>=r ? true : (s[l]==s[r] && pal(s,l+1,r-1)); }
void gen(const string& s,int i,string cur){ if(i==(int)s.size()){ if(!cur.empty()) cout<<cur<<" "; return; } gen(s,i+1,cur+s[i]); gen(s,i+1,cur); }

int main() {
    cout << "racecar palindrome? " << (pal("racecar",0,6) ? "YES" : "NO") << "\n";
    cout << "subsequences abc: "; gen("abc",0,""); cout << "\n";
    return 0;
}

/*
OUTPUT:
racecar palindrome? YES
subsequences abc: abc ab ac a bc b c
*/

