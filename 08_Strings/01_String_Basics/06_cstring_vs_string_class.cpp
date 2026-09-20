/*
═══════════════════════════════════════════════
 C-STRING vs STRING CLASS
 ⏱️ TIME COMPLEXITY: strlen O(n), string length O(1), copy O(n) — derived below
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 An old landline directory used fixed-size forms, while a modern
 phonebook handles names of any length. The char[] array is the old
 fixed style; the string class is the modern flexible style.

 📖 THEORY:
 - char[] is a manual array; '\0' is required at the end.
 - The string class is an object; it manages length and memory internally.
 - char[] is useful for low-level APIs, embedded systems, and legacy C code.
 - string is recommended for normal C++ DSA/interview code.
 - char[] can overflow if the buffer is too small.

 ASCII DIAGRAM / MEMORY STATE:

 MASTER TABLE:
 +----------------+----------------------+------------------------+
 | Feature        | char[] C-string      | string class           |
 +----------------+----------------------+------------------------+
 | End marker     | needs '\0'           | internal management    |
 | Size           | fixed/manual         | dynamic-like object    |
 | Functions      | strlen/strcpy/...    | length/find/substr/... |
 | Safety         | buffer risk          | safer                  |
 | Use            | C/low-level          | modern C++ DSA        |
 +----------------+----------------------+------------------------+

 🧠 LOGIC — STEP BY STEP:
 Step 1: Choose char[] when C-style/low-level or legacy code is involved.
    WHY: These APIs expect a raw array ending in '\0'.
 Step 2: Choose string for general C++ DSA work.
    WHY: It auto-manages the buffer, records length, and is safer.
 Step 3: Mind the buffer when using char[].
    WHY: Characters beyond the reserved cells overwrite other memory,
    which is a safety risk string avoids.

 DRY RUN:
 char a[6]="hello" has 6 cells including '\0'.
 string b="hello" length() returns 5.
 If "!" is appended, string can manage growth; char array needs enough capacity.

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - char[] strlen scans n chars -> O(n).
 - string length() is a fixed metadata access -> O(1) typically.
 - Copying either representation of n chars costs n assignments.
 -> Copy Time Complexity = O(n).

 SPACE COMPLEXITY CALCULATION:
 - Both store n characters logically.
 - char[] often needs a fixed capacity; string may reserve capacity.
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
    char cstr[20] = "hello";
    string cppStr = "hello";
    cout << "char[]: " << cstr << ", strlen=" << strlen(cstr) << "\n";
    cppStr += "!";
    cout << "string: " << cppStr << ", length=" << cppStr.length() << "\n";
    cout << "Use string for modern C++ DSA; use char[] for C-style/low-level APIs.\n";
    return 0;
}

/*
OUTPUT:
char[]: hello, strlen=5
string: hello!, length=6
Use string for modern C++ DSA; use char[] for C-style/low-level APIs.
*/

