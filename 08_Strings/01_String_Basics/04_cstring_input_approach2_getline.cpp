/*
═══════════════════════════════════════════════
 C-STRING INPUT — APPROACH 2: getline
 ⏱️ TIME COMPLEXITY: O(n) for a line of length n — full derivation below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 An address form needs the full line "Model Town Ludhiana" as one value.
 `operator>>` would stop at the first space, but `getline` keeps reading
 past spaces until it reaches the end of the line.

 📖 THEORY:
 - For a C-string, `cin.getline(charArray, size)` is used.
 - For a C++ string, `getline(cin, s)` is used.
 - Both read the full line up to (and excluding) the newline.
 - A C-string version needs the buffer size.
 - The string class lets memory grow/manage itself automatically.

 ASCII DIAGRAM / MEMORY STATE:

 Input line:
 h e l l o _ w o r l d \n
 getline reads until newline:
 ['h']['e']['l']['l']['o'][' ']['w']['o']['r']['l']['d']['\0']

 string class getline:
 s = "hello world"

 🧠 LOGIC — STEP BY STEP:
 Step 1: Call getline with the destination and the buffer size (C-string).
    WHY: The size prevents writing past the end of the array.
 Step 2: Read characters one by one until the newline is met.
    WHY: The newline marks the natural end of the user's full input.
 Step 3: For a C++ string, pass the stream and the string object.
    WHY: The string class grows internally, so no size is needed.

 DRY RUN:
 cin.getline(cstr, 30) reads hello world.
 getline(stream, cppStr) also reads hello world.
 Both preserve the spaces inside the line.

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - getline scans characters until newline or the buffer limit.
 - If the line has n chars, it reads n chars and the delimiter.
 -> Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - A C-string uses a fixed buffer capacity.
 - A string stores n chars.
 -> Space Complexity = O(n) logical storage.
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
    istringstream input1("hello world\n");
    char cstr[30];
    input1.getline(cstr, 30);
    cout << "cin.getline style read: " << cstr << "\n";

    istringstream input2("Model Town Ludhiana\n");
    string line;
    getline(input2, line);
    cout << "getline(string) read: " << line << "\n";
    return 0;
}

/*
OUTPUT:
cin.getline style read: hello world
getline(string) read: Model Town Ludhiana
*/

