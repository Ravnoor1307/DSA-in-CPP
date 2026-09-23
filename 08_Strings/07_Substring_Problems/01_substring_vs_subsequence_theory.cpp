/*
═══════════════════════════════════════════════
 SUBSTRING VS SUBSEQUENCE — THEORY
 ⏱️ TIME COMPLEXITY: listing substrings O(n²) (printing chars O(n³)); listing subsequences O(2^n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a movie, a continuous scene is a substring, but a highlight reel may skip scenes
 in between — that is a subsequence. Substrings must be contiguous; subsequences keep
 order but may skip characters.

 📖 THEORY:
 - Substring = continuous characters.
 - Subsequence = order maintained, characters may be skipped.
 - "abc" substrings: a, b, c, ab, bc, abc.
 - "abc" subsequences: "", a, b, c, ab, ac, bc, abc.
 - Every substring is a subsequence, but not every subsequence is a substring.

 ASCII VISUAL / WINDOW STATE:
 s="abc"

 Substrings continuous:
 a, b, c, ab, bc, abc
 ac is NOT substring because b skipped.

 Subsequence tree:
                ""
             /       \
          take a    skip a
          /   \       /   \
       ab     a     b     ""
      ... choices for c ...
 subsequences include ac because b skip allowed.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Define substring as contiguous characters.
    WHY: no character may be skipped between the endpoints.
 Step 2: Define subsequence as order-preserving with skips allowed.
    WHY: characters can be dropped while keeping relative order.
 Step 3: Enumerate "abc" substrings: a,b,c,ab,bc,abc.
    WHY: every contiguous range forms one substring.
 Step 4: Enumerate "abc" subsequences including "" and ac.
    WHY: each character can be taken or skipped independently.
 Step 5: Note every substring is a subsequence but not vice versa.
    WHY: contiguity is a stricter condition than order preservation.

 DRY RUN:
 For "abc":
 substring loops:
 start0 -> a, ab, abc
 start1 -> b, bc
 start2 -> c
 subsequence choice each char take/skip gives 2^3 = 8.

 FLOW OF EXECUTION:
 input string(s) -> choose pattern/window/map -> update state -> return answer

 TIME COMPLEXITY CALCULATION:
 - Number of substrings: n choices start and up to n choices end = n(n+1)/2.
 -> Listing substrings count is O(n²), printing chars can make O(n³).
 - Number of subsequences: each char has 2 choices, so 2*2*... n times = 2^n.
 -> Listing subsequences = O(2^n).

 SPACE COMPLEXITY CALCULATION:
 - Storing all substrings/subsequences can take large space.
 - Demo lists only small examples.
 -> Extra Space Complexity depends on output size.
═══════════════════════════════════════════════
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
    cout << "Substrings of abc: ";
    for (int i = 0; i < (int)s.size(); i++) {
        string cur;
        for (int j = i; j < (int)s.size(); j++) {
            cur.push_back(s[j]);
            cout << cur << " ";
        }
    }
    cout << "\nSubsequence example: ac is valid subsequence but not substring.\n";
    return 0;
}

/*
OUTPUT:
Substrings of abc: a ab abc b bc c
Subsequence example: ac is valid subsequence but not substring.
*/

