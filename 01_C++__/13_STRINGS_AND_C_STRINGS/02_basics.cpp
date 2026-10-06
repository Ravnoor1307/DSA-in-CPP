/*
TOPIC: Strings and C-Strings
FILE: 02_basics.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 02_basics.cpp -o basics

Run:
    ./basics
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main() {

    // ========================================================
    // BASIC 1: CREATE STRING
    // ========================================================

    string text = "DSA";

    cout << "=== BASIC 1: string ===\n";

    cout << text << '\n';
    cout << "length = "
         << text.length()
         << "\n\n";


    // ========================================================
    // BASIC 2: INDEX
    // ========================================================

    cout << "=== BASIC 2: Indexing ===\n";

    for (size_t i = 0;
         i < text.size();
         ++i) {

        cout << i
             << " -> "
             << text[i]
             << '\n';
    }

    cout << '\n';


    // ========================================================
    // BASIC 3: MODIFY
    // ========================================================

    string word = "cat";

    word[0] = 'b';

    cout << "=== BASIC 3: Modify ===\n";

    cout << word << "\n\n";


    // ========================================================
    // BASIC 4: APPEND
    // ========================================================

    string course = "Data";

    course += " Structures";
    course.push_back('!');

    cout << "=== BASIC 4: Append ===\n";

    cout << course << "\n\n";


    // ========================================================
    // BASIC 5: RANGE LOOP
    // ========================================================

    cout << "=== BASIC 5: Traverse ===\n";

    for (char c : course) {
        cout << c << ' ';
    }

    cout << "\n\n";


    // ========================================================
    // BASIC 6: FIND
    // ========================================================

    string sentence =
        "learn data structures";

    cout << "=== BASIC 6: find ===\n";

    size_t position =
        sentence.find("data");

    cout << "position = "
         << position
         << "\n\n";


    // ========================================================
    // BASIC 7: C-STRING
    // ========================================================

    char cString[] = "DSA";

    cout << "=== BASIC 7: C-String ===\n";

    cout << cString << '\n';

    cout << "strlen = "
         << strlen(cString)
         << '\n';

    cout << "sizeof = "
         << sizeof(cString)
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== BASIC 1: string ===
DSA
length = 3

=== BASIC 2: Indexing ===
0 -> D
1 -> S
2 -> A

=== BASIC 3: Modify ===
bat

=== BASIC 4: Append ===
Data Structures!

=== BASIC 5: Traverse ===
D a t a   S t r u c t u r e s !

=== BASIC 6: find ===
position = 6

=== BASIC 7: C-String ===
DSA
strlen = 3
sizeof = 4

WHAT'S NEXT:
01_C++__/14_POINTERS/
*/
