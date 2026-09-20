/*
═══════════════════════════════════════════════
 STRING CLASS METHODS — PART 1
 ⏱️ TIME COMPLEXITY: length O(1), find O(n*m) naive, substr O(len), replace O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a modern text editor, finding a word, replacing the selected text,
 and copying a portion are everyday actions. The C++ string class has
 these methods built in.

 📖 THEORY:
 - `length()` gives the total number of characters.
 - `substr(pos,len)` returns the selected part.
 - `find(pattern)` gives the first index of the pattern, else npos.
 - `replace(pos,len,newText)` replaces the text.
 - These methods help write safe and readable DSA code.

 ASCII DIAGRAM / MEMORY STATE:

 s = "hello world"
 index: 0 1 2 3 4 5 6 7 8 9 10
 char:  h e l l o _ w o r l d

 substr(6,5) -> "world"
 find("world") -> 6
 replace(6,5,"C++") -> "hello C++"

 🧠 LOGIC — STEP BY STEP:
 Step 1: Ask length() for the character count.
    WHY: The length is stored as metadata, so the answer is immediate.
 Step 2: Use substr(pos,len) to cut out a portion.
    WHY: A new string is built from the requested range.
 Step 3: Use find(pattern) to locate a substring.
    WHY: It reports the earliest index where the pattern fits.
 Step 4: Use replace(pos,len,newText) to overwrite a range.
    WHY: Characters in [pos, pos+len) are removed and newText goes there.

 DRY RUN:
 s="hello world"
 length=11
 pos=find("world")=6
 part=s.substr(6,5)="world"
 replace index 6 length 5 with C++ -> hello C++

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - length() is a metadata access, O(1) typical.
 - find may check positions one by one; worst n*m comparisons for the naive internal idea.
 - substr copies len characters -> O(len).
 - replace shifts/copies affected characters -> O(n) worst case.

 SPACE COMPLEXITY CALCULATION:
 - substr creates a new string of length len.
 - replace modifies the existing string and may reallocate.
 -> Extra Space Complexity = O(len) for substr.
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
    string s = "hello world";
    cout << "s = " << s << "\n";
    cout << "length = " << s.length() << "\n";
    string part = s.substr(6, 5);
    cout << "substr(6,5) = " << part << "\n";
    size_t pos = s.find("world");
    cout << "find(world) = " << pos << "\n";
    s.replace(pos, 5, "C++");
    cout << "after replace = " << s << "\n";
    return 0;
}

/*
OUTPUT:
s = hello world
length = 11
substr(6,5) = world
find(world) = 6
after replace = hello C++
*/

