/*
═══════════════════════════════════════════════
 C-STRING DECLARATION AND INITIALIZATION
 ⏱️ TIME COMPLEXITY: strlen() is O(n) — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 A greeting board displays the word "hello". In a C-string, the
 compiler automatically adds a hidden null terminator at the very end,
 so the board (the string) knows exactly where it ends without anyone
 measuring it by hand.

 📖 THEORY:
 - `char s[] = "hello";` creates 6 cells, not 5.
 - h, e, l, l, o are the visible characters.
 - The last cell is the '\0' terminator.
 - `sizeof(s)` gives the total cells/bytes of the char array.
 - `strlen(s)` gives the visible length; it does NOT count the terminator.

 ASCII DIAGRAM / MEMORY STATE:

 char s[] = "hello"

 index:  0    1    2    3    4     5
       ['h']['e']['l']['l']['o']['\0']

 strlen = 5
 sizeof = 6 bytes because char size is 1 and the null is included

 🧠 LOGIC — STEP BY STEP:
 Step 1: Declare the array with the string literal "hello".
    WHY: The compiler reads the literal and knows exactly how many
    characters it holds.
 Step 2: Let the compiler place each character into consecutive cells.
    WHY: Consecutive cells let functions locate every character by
    walking one index at a time.
 Step 3: Let the compiler append '\0' after the last character.
    WHY: strlen counts forward until '\0'; the terminator is the
    stopping signal, which is why 6 cells are needed for 5 letters.

 DRY RUN:
 Compiler sees "hello".
 It stores h at 0, e at 1, l at 2, l at 3, o at 4.
 It appends '\0' at 5.
 strlen scans 5 visible chars then stops.

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - strlen scans h, e, l, l, o, then '\0'.
 - Visible chars n=5, checks n+1=6.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - The array stores n+1 chars.
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
    char s[] = "hello"; // compiler null char automatically add karta hai
    cout << "Text: " << s << "\n";
    cout << "strlen(s) = " << strlen(s) << "\n";
    cout << "sizeof(s) = " << sizeof(s) << "\n";
    cout << "Memory boxes: ";
    for (int i = 0; i < (int)sizeof(s); i++) {
        if (s[i] == '\0') cout << "[\\0]";
        else cout << "[" << s[i] << "]";
    }
    cout << "\n";
    return 0;
}

/*
OUTPUT:
Text: hello
strlen(s) = 5
sizeof(s) = 6
Memory boxes: [h][e][l][l][o][\0]
*/

