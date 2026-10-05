/*
TOPIC: Input and Output

Covers:
- cin
- cout
- >> extraction
- << insertion
- Multiple values
- Whitespace behavior
- char input
- getline preview
- cin.ignore
- Output formatting
- fixed/setprecision
- setw/setfill
- cerr
- Buffering
- Fast I/O
- Stream states

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 01_theory.cpp -o theory

Run:
    ./theory

This lecture expects input.

Suggested input:
42 3.5 Z
Ada_Lovelace
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;


// ========== SECTION 1: STANDARD INPUT AND OUTPUT ==========
//
// cin:
//     standard input stream
//
// cout:
//     standard output stream
//
// Input:
//
//     cin >> variable;
//
// Output:
//
//     cout << value;


// ========== SECTION 2: EXTRACTION OPERATOR >> ==========
//
// Example:
//
//     int age;
//     cin >> age;
//
// If input is:
//
//     20
//
// then age becomes 20.


// ========== SECTION 3: MULTIPLE VALUES ==========
//
// Extraction can be chained:
//
//     cin >> a >> b >> c;
//
// For formatted input, whitespace normally separates values.
//
// These can all work:
//
//     10 20 30
//
//     10
//     20
//     30


// ========== SECTION 4: TYPE DIRECTS PARSING ==========
//
// int:
//
//     cin >> integer;
//
// expects textual input that can be parsed as an integer.
//
// double:
//
//     cin >> decimal;
//
// parses floating-point input.
//
// char:
//
//     cin >> character;
//
// formatted char extraction normally skips leading whitespace.


// ========== SECTION 5: STRINGS AND WHITESPACE ==========
//
// This:
//
//     cin >> word;
//
// reads a whitespace-delimited token.
//
// getline:
//
//     getline(cin, line);
//
// reads through the line delimiter.
//
// Full string theory comes later.


// ========== SECTION 6: CIN >> THEN GETLINE ==========
//
// A classic issue:
//
//     cin >> age;
//     getline(cin, name);
//
// After formatted extraction, the newline can remain.
//
// A robust common solution:
//
//     cin.ignore(
//         numeric_limits<streamsize>::max(),
//         '\n'
//     );
//
//     getline(cin, name);


// ========== SECTION 7: OUTPUT FORMATTING ==========
//
// <iomanip> provides formatting tools.
//
// Example:
//
//     cout << fixed << setprecision(2);
//
// This prints floating-point values with two digits after
// the decimal point under fixed formatting.


// ========== SECTION 8: SETPRECISION ==========
//
// Without fixed:
//
//     setprecision(n)
//
// typically controls significant digits in default format.
//
// With fixed:
//
//     fixed << setprecision(n)
//
// n controls digits after the decimal point.


// ========== SECTION 9: SETW AND SETFILL ==========
//
// setw:
//
//     cout << setw(5) << 42;
//
// specifies a minimum field width for the next insertion.
//
// setfill:
//
//     cout << setfill('0')
//          << setw(4)
//          << 7;
//
// produces:
//
//     0007


// ========== SECTION 10: NEWLINE VS ENDL ==========
//
// '\n':
//
//     newline
//
// endl:
//
//     newline + flush
//
// For ordinary batch-style DSA:
//
//     '\n'
//
// is generally preferred.


// ========== SECTION 11: FAST I/O ==========
//
// Competitive programming often uses:
//
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
// The first disables C/C++ stream synchronization.
//
// The second unties cin from cout.
//
// Once synchronization is disabled, avoid casually mixing
// cin/cout with scanf/printf.


// ========== SECTION 12: STREAM FAILURE ==========
//
// Input can fail.
//
// Example:
//
//     int value;
//     cin >> value;
//
// If the next input is not a valid integer representation,
// the stream can enter a fail state.
//
// Later, conditions can test:
//
//     if (cin >> value) { ... }


// ========== SECTION 13: STANDARD ERROR ==========
//
// cerr is normally used for diagnostics.
//
//     cerr << "debug\n";
//
// Online-judge answer output should normally go to cout.
//
// Debugging text must not contaminate expected stdout.


// ========== SECTION 14: BUFFERING ==========
//
// I/O can be expensive.
//
// Streams and the OS may buffer data so that many small
// operations can be handled more efficiently.
//
// endl forces a flush.
//
// Excessive flushing can hurt performance.


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== DEMO 1: Reading Multiple Types ===\n";
    cout << "Provide: integer decimal character\n";

    int integerValue{};
    double decimalValue{};
    char characterValue{};

    cin >> integerValue
        >> decimalValue
        >> characterValue;

    cout << "Integer = "
         << integerValue << '\n';

    cout << "Decimal = "
         << decimalValue << '\n';

    cout << "Character = "
         << characterValue << "\n\n";


    cout << "=== DEMO 2: Whitespace-Delimited Token ===\n";
    cout << "Provide one word/token:\n";

    string word;

    cin >> word;

    cout << "Token = "
         << word << "\n\n";


    cout << "=== DEMO 3: fixed + setprecision ===\n";

    double pi = 3.141592653589793;

    cout << fixed
         << setprecision(2);

    cout << "pi to 2 decimal places = "
         << pi << '\n';

    cout << setprecision(4);

    cout << "pi to 4 decimal places = "
         << pi << "\n\n";


    cout << "=== DEMO 4: setw ===\n";

    cout << right;

    cout << setw(8) << 10 << '\n';
    cout << setw(8) << 500 << '\n';
    cout << setw(8) << 9000 << "\n\n";


    cout << "=== DEMO 5: setfill ===\n";

    cout << setfill('0')
         << setw(5)
         << 42
         << '\n';

    // Restore the normal fill character.
    cout << setfill(' ');

    cout << '\n';


    cout << "=== DEMO 6: Formatting Does Not Change Value ===\n";

    double value = 9.87654;

    cout << fixed
         << setprecision(2)
         << value
         << '\n';

    cout << setprecision(5)
         << value
         << "\n\n";


    cout << "=== DEMO 7: bool Output Formatting ===\n";

    bool ready = true;

    cout << noboolalpha;
    cout << "Default: " << ready << '\n';

    cout << boolalpha;
    cout << "boolalpha: " << ready << '\n';

    cout << noboolalpha;

    return 0;
}


/*
EXPECTED OUTPUT

Using suggested input:

42 3.5 Z
Ada_Lovelace

Output:

=== DEMO 1: Reading Multiple Types ===
Provide: integer decimal character
Integer = 42
Decimal = 3.5
Character = Z

=== DEMO 2: Whitespace-Delimited Token ===
Provide one word/token:
Token = Ada_Lovelace

=== DEMO 3: fixed + setprecision ===
pi to 2 decimal places = 3.14
pi to 4 decimal places = 3.1416

=== DEMO 4: setw ===
      10
     500
    9000

=== DEMO 5: setfill ===
00042

=== DEMO 6: Formatting Does Not Change Value ===
9.88
9.87654

=== DEMO 7: bool Output Formatting ===
Default: 1
boolalpha: true


NOTE:
The instructional "Provide..." text is included because this is a
runnable lecture. In normal online-judge submissions, do not print
prompts unless the problem explicitly requires them.

WHAT'S NEXT:
01_C++__/05_OPERATORS/
*/
