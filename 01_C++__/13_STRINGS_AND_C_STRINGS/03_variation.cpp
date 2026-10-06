/*
TOPIC: Strings and C-Strings
FILE: 03_variation.cpp

Purpose:
Explore:
- pass-by-value vs const/reference strings
- reserve vs resize
- reverse traversal
- string/numeric conversion
- C-string length
- content comparison
- mutable arrays vs literals

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 03_variation.cpp -o variation

Run:
    ./variation
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void modifyCopy(
    string text
) {
    if (!text.empty()) {
        text[0] = 'X';
    }

    cout << "inside copy = "
         << text << '\n';
}


void modifyReference(
    string& text
) {
    if (!text.empty()) {
        text[0] = 'Y';
    }
}


int manualCStringLength(
    const char text[]
) {
    int length = 0;

    while (text[length] != '\0') {
        ++length;
    }

    return length;
}


int main() {

    cout << boolalpha;


    // ========================================================
    // VARIATION 1: STRING COPY
    // ========================================================

    string original = "hello";

    cout << "=== VARIATION 1: Pass by Value ===\n";

    modifyCopy(original);

    cout << "caller = "
         << original << "\n\n";


    // ========================================================
    // VARIATION 2: STRING REFERENCE
    // ========================================================

    cout << "=== VARIATION 2: Pass by Reference ===\n";

    modifyReference(original);

    cout << "caller = "
         << original << "\n\n";


    // ========================================================
    // VARIATION 3: RESERVE
    // ========================================================

    string reserved;

    reserved.reserve(100);

    cout << "=== VARIATION 3: reserve ===\n";

    cout << "size = "
         << reserved.size()
         << '\n';

    cout << "capacity >= 100: "
         << (reserved.capacity() >= 100)
         << "\n\n";


    // ========================================================
    // VARIATION 4: RESIZE
    // ========================================================

    string resized = "abc";

    resized.resize(5, 'x');

    cout << "=== VARIATION 4: resize ===\n";

    cout << resized << '\n';

    cout << "size = "
         << resized.size()
         << "\n\n";


    // ========================================================
    // VARIATION 5: SAFE REVERSE INDEX LOOP
    // ========================================================

    string reverseText = "ABCDE";

    cout << "=== VARIATION 5: Reverse Traversal ===\n";

    for (size_t i = reverseText.size();
         i > 0;
         --i) {

        cout << reverseText[i - 1];
    }

    cout << "\n\n";


    // ========================================================
    // VARIATION 6: NUMERIC CONVERSION
    // ========================================================

    string numberText = "12345";

    int number =
        stoi(numberText);

    string again =
        to_string(number + 1);

    cout << "=== VARIATION 6: Conversion ===\n";

    cout << "number = "
         << number << '\n';

    cout << "next string = "
         << again << "\n\n";


    // ========================================================
    // VARIATION 7: MANUAL C-STRING LENGTH
    // ========================================================

    char cText[] = "hello";

    cout << "=== VARIATION 7: C-String Length ===\n";

    cout << "manual = "
         << manualCStringLength(cText)
         << '\n';

    cout << "strlen = "
         << strlen(cText)
         << "\n\n";


    // ========================================================
    // VARIATION 8: C-STRING CONTENT COMPARISON
    // ========================================================

    char first[] = "apple";
    char second[] = "apple";

    cout << "=== VARIATION 8: strcmp ===\n";

    cout << "equal content = "
         << (strcmp(first, second) == 0)
         << "\n\n";


    // ========================================================
    // VARIATION 9: MUTABLE ARRAY
    // ========================================================

    char mutableText[] = "hello";

    mutableText[0] = 'H';

    cout << "=== VARIATION 9: Mutable char[] ===\n";

    cout << mutableText << '\n';


    // A literal should be accessed as const:
    //
    // const char* literal = "hello";
    //
    // Do not attempt to modify its characters.

    return 0;
}


/*
EXPECTED OUTPUT

=== VARIATION 1: Pass by Value ===
inside copy = Xello
caller = hello

=== VARIATION 2: Pass by Reference ===
caller = Yello

=== VARIATION 3: reserve ===
size = 0
capacity >= 100: true

=== VARIATION 4: resize ===
abcxx
size = 5

=== VARIATION 5: Reverse Traversal ===
EDCBA

=== VARIATION 6: Conversion ===
number = 12345
next string = 12346

=== VARIATION 7: C-String Length ===
manual = 5
strlen = 5

=== VARIATION 8: strcmp ===
equal content = true

=== VARIATION 9: Mutable char[] ===
Hello

WHAT'S NEXT:
01_C++__/14_POINTERS/
*/
