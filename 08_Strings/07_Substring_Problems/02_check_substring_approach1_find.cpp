/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 02_check_substring_approach1_find.cpp
│
│ REAL-WORLD SCENARIO:
│ Text editor me Ctrl+F search built-in hota hai. C++ string ka `find()` bhi pattern ko text ke andar dhundhta hai.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Text and pattern define karo.
│ 2. `text.find(pattern)` call karo.
│ 3. Agar result `string::npos` nahi hai to pattern found.
│ 4. Returned value first occurrence index hota hai.
│ 5. Built-in concise hai, interview me manual approach bhi aani chahiye.
│
│ ASCII VISUAL / WINDOW STATE:
│ text = "hello world"
│ pattern = "world"
│
│ index: 0 1 2 3 4 5 6 7 8 9 10
│ char:  h e l l o _ w o r l d
│                      ↑
│                    found at 6
│
│ DRY RUN:
│ find("world") starts scanning.
│ It finds w at index6 and confirms world.
│ returns 6.
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Library implementation may vary.
│ - Conceptually naive find can try n positions and compare m chars.
│ - Worst comparisons = n*m.
│ -> Time Complexity = O(n*m) worst conceptual.
│
│ SPACE COMPLEXITY CALCULATION:
│ - Built-in find uses no extra output storage.
│ -> Extra Space Complexity = O(1).
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
    string text = "hello world";
    string pattern = "world";
    size_t pos = text.find(pattern);
    if (pos != string::npos) cout << "Found at index " << pos << "\n";
    else cout << "Not found\n";
    return 0;
}

/*
OUTPUT:
Found at index 6
*/

