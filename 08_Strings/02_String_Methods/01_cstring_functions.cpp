/*
═══════════════════════════════════════════════
 C-STRING FUNCTIONS
 ⏱️ TIME COMPLEXITY: strlen O(n), strcpy O(n), strcat O(d+s), strcmp O(n)
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 An old C library toolkit has ready-made tools for strings: measuring
 length, copying, joining, and comparing. These are the `cstring`
 functions that every C/C++ program can call.

 📖 THEORY:
 - `strlen(s)` counts visible chars until '\0'.
 - `strcpy(dest, src)` copies the source including '\0'.
 - `strcat(dest, src)` attaches src to the end of dest.
 - `strcmp(a,b)` does a lexicographic comparison.
 - Important trap: strcmp returns 0 when the strings are equal.

 ASCII DIAGRAM / MEMORY STATE:

 strlen("cat"):
 [c][a][t][\0] -> count 3

 strcpy(dest,"hi"):
 dest becomes [h][i][\0]

 strcat("hi","!"):
 [h][i][!][\0]

 strcmp("abc","abc") = 0  <-- equal means zero

 🧠 LOGIC — STEP BY STEP:
 Step 1: Call strlen to count characters up to '\0'.
    WHY: The terminator is the stopping signal; counting stops there.
 Step 2: Call strcpy to copy every source char plus '\0'.
    WHY: The destination must become a fully valid C-string too.
 Step 3: Call strcat by first locating dest's end, then copying src.
    WHY: Joining works by writing the source right after the terminator.
 Step 4: Call strcmp to compare character by character.
    WHY: A lexicographic result tells order; 0 means equal, not 1.

 DRY RUN:
 a="hello", b="hello"
 strlen(a)=5
 strcpy(copy,a) -> copy="hello"
 strcat(copy,"!") -> "hello!"
 strcmp(a,b)=0 -> equal

 FLOW OF EXECUTION:
 input/create string -> inspect characters -> apply method/loop -> print result

 TIME COMPLEXITY CALCULATION:
 - strlen scans n chars -> O(n).
 - strcpy copies n chars + terminator -> O(n).
 - strcat first finds the end of dest (d), then copies source (s) -> O(d+s).
 - strcmp compares until mismatch or end; worst case n chars -> O(n).

 SPACE COMPLEXITY CALCULATION:
 - Functions use destination buffers supplied by the programmer.
 - Extra variables are constant.
 -> Extra Space Complexity = O(1); destination storage depends on capacity.
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
    char a[30] = "hello";
    char b[30] = "hello";
    char copy[30];

    cout << "strlen(a) = " << strlen(a) << "\n";
    strcpy(copy, a);
    cout << "After strcpy copy = " << copy << "\n";
    strcat(copy, "!");
    cout << "After strcat copy = " << copy << "\n";
    cout << "strcmp(a,b) = " << strcmp(a, b) << " (0 means equal)\n";
    return 0;
}

/*
OUTPUT:
strlen(a) = 5
After strcpy copy = hello
After strcat copy = hello!
strcmp(a,b) = 0 (0 means equal)
*/

