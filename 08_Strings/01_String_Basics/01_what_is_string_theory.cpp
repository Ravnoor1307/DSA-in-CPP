/*
═══════════════════════════════════════════════
 WHAT IS A STRING
 ⏱️ TIME COMPLEXITY: length/traversal is O(n) — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 When you write your name, a line of letters is formed. In
 programming, a sequence of letters/characters is called a string.
 In a C-style string, a special null character '\0' marks the end of
 the text, so the program knows exactly where the string finishes.

 📖 THEORY:
 - A string is an ordered collection of characters.
 - A C-string is a char array that ends with the null character '\0'.
 - The null character tells functions where the string finishes.
 - The C++ string class manages length and memory automatically.
 - In modern C++, the string class is safer and easier to use, but the
   char[] basics are still important for interviews and exams.

 ASCII DIAGRAM / MEMORY STATE:

 C-string memory for "cat":
 index:  0    1    2    3
 box:  ['c']['a']['t']['\0']
                    └── null terminator: the string ends here

 C-string vs string intro:
 char name[] = "cat";     // manual array + '\0'
 string s = "cat";        // object, length automatic

 🧠 LOGIC — STEP BY STEP:
 Step 1: Treat a string as an ordered sequence of characters.
    WHY: Characters are stored one after another in memory, so every
    position maps to an exact index.
 Step 2: For a C-string, always end the array with '\0'.
    WHY: C-string functions scan forward and stop only when they see
    '\0'; without it they would keep reading past the data.
 Step 3: For the C++ string class, let the object track length/memory.
    WHY: The class stores the length internally, so the terminator does
    not have to be managed manually.

 ASCII DIAGRAM for "cat" again (memory boxes):
   ['c']['a']['t']['\0']     ← the null cell marks the end

 DRY RUN:
 char word[]="hi"
 memory: ['h']['i']['\0']
 strlen reads h -> i -> stops at \0, length=2
 string class s="hi" stores length internally; s.length() returns 2.

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - Printing/length for a C-string may scan until '\0'.
 - If there are n visible characters, the loop reads n chars and then the terminator.
 - Total checks = n+1.
 -> Time Complexity for length = O(n).

 SPACE COMPLEXITY CALCULATION:
 - A char array needs n+1 cells including '\0'.
 - The string class internally stores characters and metadata.
 -> Storage = O(n).
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
    char cstr[] = "cat";
    string cppStr = "cat";

    cout << "C-string visible text: " << cstr << "\n";
    cout << "Memory boxes: ";
    for (int i = 0; i < 4; i++) {
        if (cstr[i] == '\0') cout << "[\\0]";
        else cout << "[" << cstr[i] << "]";
    }
    cout << "\nC++ string text: " << cppStr << "\n";
    return 0;
}

/*
OUTPUT:
C-string visible text: cat
Memory boxes: [c][a][t][\0]
C++ string text: cat
*/

