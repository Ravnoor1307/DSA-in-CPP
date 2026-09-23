/*
═══════════════════════════════════════════════
 ISOMORPHIC STRINGS
 ⏱️ TIME COMPLEXITY: O(n) — loop over n positions with constant map checks, extra space O(1)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a cipher code, every original symbol must map consistently to one target symbol.
 If the mapping is one-to-one and consistent, the strings are isomorphic.

 📖 THEORY:
 - Both strings must have the same length.
 - Maintain an s char -> t char mapping.
 - A t char must not already be mapped from a different s char, so check the reverse
   mapping as well.
 - Validate consistency at every position.
 - Example egg -> add is true: e->a, g->d.

 ASCII VISUAL / WINDOW STATE:
 s="egg", t="add"
 e -> a
 g -> d
 next g -> d consistent
 true

 s="foo", t="bar"
 f->b, o->a, next o should a but gets r -> false

 🧠 LOGIC — STEP BY STEP:
 Step 1: If lengths differ, return false.
    WHY: a one-to-one mapping needs equal lengths.
 Step 2: Use two 256-size arrays mapST and mapTS, both -1.
    WHY: forward and reverse maps enforce a true bijection.
 Step 3: If both are unmapped, set mapST[a]=b and mapTS[b]=a.
    WHY: record the new pairing in both directions.
 Step 4: Else if either mapping disagrees, return false.
    WHY: an inconsistent mapping breaks isomorphism.
 Step 5: After the loop, return true.
    WHY: all positions were consistent.

 DRY RUN:
 egg/add:
 i0 e,a set maps
 i1 g,d set maps
 i2 g,d already consistent
 result YES

 FLOW OF EXECUTION:
 input strings -> length check -> forward/reverse map each pair -> detect inconsistency -> print result

 TIME COMPLEXITY CALCULATION:
 - Loop runs n positions.
 - Each position has constant map array checks.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Two arrays of size 256.
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

bool isIsomorphic(const string& s, const string& t) {
    if (s.size() != t.size()) return false;
    vector<int> mapST(256, -1), mapTS(256, -1);
    for (int i = 0; i < (int)s.size(); i++) {
        unsigned char a = s[i], b = t[i];
        if (mapST[a] == -1 && mapTS[b] == -1) {
            mapST[a] = b;
            mapTS[b] = a;
        } else if (mapST[a] != b || mapTS[b] != a) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << "egg/add isomorphic? " << isIsomorphic("egg", "add") << "\n";
    cout << "foo/bar isomorphic? " << isIsomorphic("foo", "bar") << "\n";
    return 0;
}

/*
OUTPUT:
egg/add isomorphic? true
foo/bar isomorphic? false
*/

