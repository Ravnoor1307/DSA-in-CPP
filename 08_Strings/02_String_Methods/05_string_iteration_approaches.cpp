/*
═══════════════════════════════════════════════
 STRING ITERATION APPROACHES
 ⏱️ TIME COMPLEXITY: O(n) for all three approaches — derived below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A name board can be inspected in three ways: by index number, by
 visiting the letters directly, or by walking a pointer/iterator. C++
 gives the same three common ways to iterate over a string.

 📖 THEORY:
 - Index loop: best when a position is needed.
 - Range-for: clean for simple read-only character traversal.
 - Iterator: useful for STL style and generic algorithms.
 - All three visit each character exactly once.
 - Choose according to the use case.

 ASCII DIAGRAM / MEMORY STATE:

 s="abc"

 Index loop:
 i=0 -> a, i=1 -> b, i=2 -> c

 Range-for:
 ch=a, ch=b, ch=c

 Iterator:
 it->a, it->b, it->c

 Comparison:
 index = position access
 range = simplest
 iterator = STL generic

 🧠 LOGIC — STEP BY STEP:
 Step 1: Use an index loop when the position of each char matters.
    WHY: The array-like access s[i] gives both the char and its index.
 Step 2: Use range-for for plain read-only scanning.
    WHY: The compiler hides the index/iterator details, giving clean code.
 Step 3: Use an iterator for STL-style/generic algorithms.
    WHY: Iterators plug into standard functions such as sort and find.

 DRY RUN:
 s="abc"
 all approaches output a b c.
 Each character exactly once visited.
 Total visits = 3.

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - Index loop runs n times.
 - Range-for runs n times.
 - Iterator loop runs n times.
 -> Time Complexity = O(n) for all.

 SPACE COMPLEXITY CALCULATION:
 - Only a loop variable/index/iterator is used.
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
    string s = "abc";
    cout << "Index loop: ";
    for (int i = 0; i < (int)s.size(); i++) cout << s[i] << " ";
    cout << "\nRange-for: ";
    for (char ch : s) cout << ch << " ";
    cout << "\nIterator: ";
    for (string::iterator it = s.begin(); it != s.end(); ++it) cout << *it << " ";
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Index loop: a b c
Range-for: a b c
Iterator: a b c
*/

