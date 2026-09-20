/*
═══════════════════════════════════════════════
 STRING COMPARISON
 ⏱️ TIME COMPLEXITY: O(min(n,m)) — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Words in a dictionary are arranged in lexicographic order. String
 comparison works the same way: characters are compared from left to
 right, and the first difference decides the result.

 📖 THEORY:
 - `==` checks equality for a C++ string.
 - `strcmp(a,b)` compares C-strings; 0 means equal.
 - `s.compare(t)` returns 0 if equal, negative if s<t, positive if s>t.
 - Lexicographic means dictionary order.
 - The first different character decides the answer.

 ASCII DIAGRAM / MEMORY STATE:

 Compare "apple" vs "apricot":
 a == a, p == p, p vs r
 'p' < 'r' so "apple" < "apricot"

 strcmp trap:
 strcmp("cat","cat") = 0 -> equal
 not 1.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Walk both strings in parallel from index 0.
    WHY: The position-by-position walk mirrors dictionary ordering.
 Step 2: At the first differing position, compare those two characters.
    WHY: That single difference decides the order of the whole strings.
 Step 3: If all compared chars match, compare lengths.
    WHY: An equal prefix with different length has its own order; if
    everything matches, the result is equal (0).

 DRY RUN:
 s="apple", t="apricot"
 char0 a=a continue
 char1 p=p continue
 char2 p<r -> s<t
 compare result negative.

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - Worst case, an equal prefix of length n is compared.
 - Comparisons count up to min(n,m), plus a length decision.
 -> Time Complexity = O(min(n,m)).

 SPACE COMPLEXITY CALCULATION:
 - No extra string is needed.
 -> Extra Space Complexity = O(1).
═══════════════════════════════════════════════
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string a = "apple", b = "apricot";
    cout << boolalpha;
    cout << "a == b? " << (a == b) << "\n";
    cout << "a.compare(b) = " << a.compare(b) << " (negative means a<b)\n";

    char x[] = "cat";
    char y[] = "cat";
    cout << "strcmp(cat,cat) = " << strcmp(x, y) << " (0 means equal)\n";
    return 0;
}

/*
OUTPUT:
a == b? false
a.compare(b) = -2 (negative means a<b)
strcmp(cat,cat) = 0 (0 means equal)
*/

