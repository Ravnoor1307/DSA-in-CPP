/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 04_longest_common_prefix.cpp
│
│ REAL-WORLD SCENARIO:
│ Phone contacts me "flower", "flow", "flight" ka common starting label find karna hai. Vertical character comparison se prefix milta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. First string ko reference prefix maan lo.
│ 2. Character index c from 0 onwards compare karo across all strings.
│ 3. Koi string end ho gayi ya mismatch mila to stop.
│ 4. Matched chars answer me append karo.
│ 5. Example output "fl".
│
│ ASCII VISUAL / WINDOW STATE:
│ words:
│ flower
│ flow
│ flight
│
│ vertical comparison:
│ col0: f f f -> match add f
│ col1: l l l -> match add l
│ col2: o o i -> mismatch stop
│ LCP = "fl"
│
│ DRY RUN:
│ c=0: all f -> ans=f
│ c=1: all l -> ans=fl
│ c=2: flower has o, flight has i -> stop
│ return fl
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Let k strings and min length L.
│ - For each column up to L, compare k strings.
│ - Worst comparisons = k*L.
│ -> Time Complexity = O(k*L).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Answer prefix length at most L.
│ -> Extra Space Complexity = O(L).
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

string longestCommonPrefix(const vector<string>& words) {
    if (words.empty()) return "";
    string ans;
    for (int c = 0; c < (int)words[0].size(); c++) {
        char expected = words[0][c];
        for (int r = 1; r < (int)words.size(); r++) {
            if (c >= (int)words[r].size() || words[r][c] != expected) return ans;
        }
        ans.push_back(expected);
    }
    return ans;
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest common prefix = " << longestCommonPrefix(words) << "\n";
    return 0;
}

/*
OUTPUT:
Longest common prefix = fl
*/

