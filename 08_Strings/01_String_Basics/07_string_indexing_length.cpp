/*
═══════════════════════════════════════════════
 STRING INDEXING AND LENGTH
 ⏱️ TIME COMPLEXITY: length() O(1), traversal O(n) — derived below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Train coaches may be numbered visually starting at 1, but computers
 index starting at 0. A string's first character is at index 0, and the
 last character is at index length-1.

 📖 THEORY:
 - `s[i]` accesses the i-th character.
 - Indexing starts at 0.
 - `s.length()` and `s.size()` return the total number of characters.
 - The last valid index = length - 1.
 - An out-of-range index can be unsafe; `at()` provides bounds checking.

 ASCII DIAGRAM / MEMORY STATE:

 s = "hello"
 index:  0   1   2   3   4
 char:  [h] [e] [l] [l] [o]

 length = 5
 last index = 5 - 1 = 4
 s[0]='h', s[4]='o'

 🧠 LOGIC — STEP BY STEP:
 Step 1: Use s[i] to fetch the character at position i.
    WHY: string characters are stored contiguously, so any index is
    reached in one jump.
 Step 2: Start the loop at 0 and go up to length-1.
    WHY: The last legal position is one less than the length.
 Step 3: Use length()/size() to know how many times to iterate.
    WHY: The length is stored as metadata, so the loop bound is known
    instantly.

 DRY RUN:
 s="hello"
 s.length()=5
 loop i=0..4:
 i0 h, i1 e, i2 l, i3 l, i4 o
 i=5 would be invalid as a character index.

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - length() is O(1) typically.
 - Printing all characters runs the loop n times.
 -> Traversal Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - No extra array is used.
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
    string s = "hello";
    cout << "String: " << s << "\n";
    cout << "length=" << s.length() << ", size=" << s.size() << "\n";
    cout << "Index boxes:\n";
    for (int i = 0; i < (int)s.size(); i++) cout << "index " << i << " -> " << s[i] << "\n";
    cout << "Last valid index = " << s.length() - 1 << "\n";
    return 0;
}

/*
OUTPUT:
String: hello
length=5, size=5
Index boxes:
index 0 -> h
index 1 -> e
index 2 -> l
index 3 -> l
index 4 -> o
Last valid index = 4
*/

