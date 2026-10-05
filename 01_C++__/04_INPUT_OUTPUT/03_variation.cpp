/*
TOPIC: Input and Output
FILE: 03_variation.cpp

Purpose:
Demonstrate important I/O variations:
- token input
- line input
- cin + getline
- character-level input
- formatting behavior

Compile:
    g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
    ./variation

Suggested input:
20
Ada Lovelace
C++
X
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int main() {

    // ========================================================
    // VARIATION 1: CIN + GETLINE
    // ========================================================
    //
    // Input example:
    //
    // 20
    // Ada Lovelace
    //
    // After cin >> age, the newline is still available.
    //
    // ignore() removes everything through that newline.

    int age{};
    string fullName;

    cin >> age;

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    getline(cin, fullName);

    cout << "=== VARIATION 1: cin + getline ===\n";

    cout << "Age = " << age << '\n';
    cout << "Name = " << fullName << "\n\n";


    // ========================================================
    // VARIATION 2: TOKEN INPUT
    // ========================================================
    //
    // >> reads one whitespace-delimited string token.

    string language;

    cin >> language;

    cout << "=== VARIATION 2: Token Input ===\n";

    cout << "Language = "
         << language
         << "\n\n";


    // ========================================================
    // VARIATION 3: FORMATTED CHAR INPUT
    // ========================================================
    //
    // cin >> c normally skips leading whitespace.

    char c{};

    cin >> c;

    cout << "=== VARIATION 3: char Input ===\n";

    cout << "Character = "
         << c
         << "\n\n";


    // ========================================================
    // VARIATION 4: PRECISION
    // ========================================================

    double number = 123.456789;

    cout << "=== VARIATION 4: Precision ===\n";

    cout << defaultfloat
         << setprecision(4)
         << number
         << '\n';

    cout << fixed
         << setprecision(4)
         << number
         << "\n\n";


    // ========================================================
    // VARIATION 5: SETW ONLY AFFECTS NEXT FIELD
    // ========================================================

    cout << "=== VARIATION 5: setw ===\n";

    cout << right
         << setw(6)
         << 10;

    // There is no setw here.
    cout << 20 << '\n';

    cout << setw(6)
         << 30
         << setw(6)
         << 40
         << "\n\n";


    // ========================================================
    // VARIATION 6: SETFILL
    // ========================================================

    cout << "=== VARIATION 6: setfill ===\n";

    cout << setfill('0')
         << setw(6)
         << 42
         << '\n';

    cout << setfill(' ');


    return 0;
}


/*
SUGGESTED INPUT

20
Ada Lovelace
C++
X


EXPECTED OUTPUT

=== VARIATION 1: cin + getline ===
Age = 20
Name = Ada Lovelace

=== VARIATION 2: Token Input ===
Language = C++

=== VARIATION 3: char Input ===
Character = X

=== VARIATION 4: Precision ===
123.5
123.4568

=== VARIATION 5: setw ===
    1020
    30    40

=== VARIATION 6: setfill ===
000042


WHAT'S NEXT:
01_C++__/05_OPERATORS/
*/
