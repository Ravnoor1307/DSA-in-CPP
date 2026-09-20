/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 01_isomorphic_strings.cpp
│
│ REAL-WORLD SCENARIO:
│ Cipher code me har original symbol consistently ek target symbol me map hona chahiye. Agar mapping one-to-one consistent hai, strings isomorphic hain.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Two strings same length honi chahiye.
│ 2. s char -> t char mapping maintain karo.
│ 3. t char already kisi aur s char se mapped na ho, isliye reverse mapping bhi check karo.
│ 4. Har position par consistency validate karo.
│ 5. Example egg -> add true: e->a, g->d.
│
│ ASCII VISUAL / WINDOW STATE:
│ s="egg", t="add"
│ e -> a
│ g -> d
│ next g -> d consistent
│ true
│
│ s="foo", t="bar"
│ f->b, o->a, next o should a but gets r -> false
│
│ DRY RUN:
│ egg/add:
│ i0 e,a set maps
│ i1 g,d set maps
│ i2 g,d already consistent
│ result YES
│
│ FLOW OF EXECUTION:
│ input string(s) -> choose pattern/window/map -> update state -> return answer
│
│ COMPLEXITY CALCULATION:
│ - Loop runs n positions.
│ - Each position has constant map array checks.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - Two arrays of size 256.
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

