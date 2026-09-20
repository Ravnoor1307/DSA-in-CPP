/*
═══════════════════════════════════════════════
 STRING CLASS BASICS
 ⏱️ TIME COMPLEXITY: length() O(1), append of m chars O(m) — derived below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Modern contact apps store names of variable length. The C++ `string`
 class manages memory automatically, so there is no manual null
 terminator to worry about — names of any length just work.

 📖 THEORY:
 - `#include <string>` provides the C++ string class.
 - `string s = "hello";` is simple initialization.
 - `s.length()` and `s.size()` give the length.
 - append, indexing, and comparison are directly available.
 - Memory management is handled internally by the class.

 ASCII DIAGRAM / MEMORY STATE:

 string object conceptual view:
 s = "hello"
 characters: [h][e][l][l][o]
 length: 5
 capacity: implementation dependent

 The programmer does not need to place '\0' manually.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Declare a string object with an initializer.
    WHY: The class builds an internal buffer and records the length.
 Step 2: Use s += or append() to add text.
    WHY: The class grows the buffer as needed and keeps the length in sync.
 Step 3: Read length()/size() for the character count.
    WHY: The count is stored as metadata, which is why it is returned in
    constant time.

 DRY RUN:
 string s="hello"
 s += " world" -> "hello world"
 s.length() -> 11
 s[1] -> 'e'

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - length() is usually constant time in a modern C++ string.
 - Appending m chars copies/appends m chars.
 -> Append Time Complexity = O(m).

 SPACE COMPLEXITY CALCULATION:
 - The string stores n characters.
 -> Space Complexity = O(n).
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
    string s = "hello"; // modern C++ way
    cout << "Initial string: " << s << "\n";
    s += " world";
    cout << "After append: " << s << "\n";
    cout << "length = " << s.length() << ", size = " << s.size() << "\n";
    cout << "s[1] = " << s[1] << "\n";
    return 0;
}

/*
OUTPUT:
Initial string: hello
After append: hello world
length = 11, size = 11
s[1] = e
*/

