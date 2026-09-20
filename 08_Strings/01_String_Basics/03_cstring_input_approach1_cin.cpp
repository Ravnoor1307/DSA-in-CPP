/*
═══════════════════════════════════════════════
 C-STRING INPUT — APPROACH 1: cin
 ⏱️ TIME COMPLEXITY: O(k) for a token of length k — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 In a form, the user types "hello world" into the name field, but a
 simple `cin >> s` stops at the first space. As a result, only "hello"
 is read and "world" is left behind — a classic trap.

 📖 THEORY:
 - `cin >> charArray` takes whitespace-delimited input.
 - Reading stops at space, tab, or newline.
 - From input "hello world", only "hello" is stored.
 - To avoid this trap, use `cin.getline()`.
 - A stringstream is used here to keep the demo deterministic.

 ASCII DIAGRAM / MEMORY STATE:

 Input buffer:
 h e l l o _ w o r l d
           ↑
        whitespace: cin stops here

 char s[20] after cin >> s:
 ['h']['e']['l']['l']['o']['\0'] ...
 the word "world" can stay in the buffer.

 🧠 LOGIC — STEP BY STEP:
 Step 1: Read characters from the stream using operator>>.
    WHY: operator>> reads until it hits whitespace, so it naturally
    grabs one token at a time.
 Step 2: Stop as soon as a space/tab/newline is seen.
    WHY: The delimiter itself is not stored; it signals that the token
    has ended.
 Step 3: Append '\0' automatically after the extracted characters.
    WHY: The array must be a valid C-string so functions like strlen
    and cout know where it ends.

 DRY RUN:
 simulated input = "hello world"
 stream >> s reads chars until space.
 s becomes "hello".
 Remaining token would be "world".

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - cin extraction copies characters until whitespace.
 - If the first word length is k, k chars are copied + the terminator.
 -> Time Complexity = O(k), where k is the first token length.

 SPACE COMPLEXITY CALCULATION:
 - char array capacity is fixed at 20.
 -> Space Complexity = O(capacity), logically O(k).
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
    istringstream input("hello world");
    char s[20];
    input >> s; // whitespace par stop ho jayega
    cout << "Using operator>> read: " << s << "\n";
    cout << "Trap: full line 'hello world' nahi aayi, sirf first word aaya.\n";
    return 0;
}

/*
OUTPUT:
Using operator>> read: hello
Trap: full line 'hello world' nahi aayi, sirf first word aaya.
*/

