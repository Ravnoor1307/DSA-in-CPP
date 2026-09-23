/*
═══════════════════════════════════════════════
 CHECK SUBSTRING — APPROACH 1 (BUILT-IN find)
 ⏱️ TIME COMPLEXITY: O(n*m) worst conceptual — naive find can try n positions and compare m chars, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A text editor has a built-in Ctrl+F search. C++'s string `find()` also locates a
 pattern inside the text.

 📖 THEORY:
 - Define the text and the pattern.
 - Call `text.find(pattern)`.
 - If the result is not `string::npos`, the pattern was found.
 - The returned value is the index of the first occurrence.
 - The built-in is concise, but a manual approach should also be known for interviews.

 ASCII VISUAL / WINDOW STATE:
 text = "hello world"
 pattern = "world"

 index: 0 1 2 3 4 5 6 7 8 9 10
 char:  h e l l o _ w o r l d
                      ↑
                    found at 6

 🧠 LOGIC — STEP BY STEP:
 Step 1: Define text and pattern.
    WHY: the search needs a haystack and a needle.
 Step 2: Call text.find(pattern).
    WHY: find returns the starting index of the first match or npos.
 Step 3: If pos != string::npos, print the index; else print not found.
    WHY: npos is the sentinel for "no match".

 DRY RUN:
 find("world") starts scanning.
 It finds w at index6 and confirms world.
 returns 6.

 FLOW OF EXECUTION:
 input strings -> call find(pattern) -> check npos -> print index or not found

 TIME COMPLEXITY CALCULATION:
 - Library implementation may vary.
 - Conceptually naive find can try n positions and compare m chars.
 - Worst comparisons = n*m.
 -> Time Complexity = O(n*m) worst conceptual.

 SPACE COMPLEXITY CALCULATION:
 - Built-in find uses no extra output storage.
 -> Extra Space Complexity = O(1).
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

