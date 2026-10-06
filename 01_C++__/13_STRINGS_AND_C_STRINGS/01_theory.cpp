/*
TOPIC: Strings and C-Strings

Covers:
- std::string
- length/size
- indexing
- traversal
- getline
- concatenation
- comparison
- find/substr
- push_back/pop_back
- reverse/palindrome logic
- const-reference parameters
- C-style strings
- null terminator
- strlen/strcmp
- char arrays vs string literals
- c_str()

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 01_theory.cpp -o theory

Run:
    ./theory
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


// ========== SECTION 1: STD::STRING ==========
//
// std::string is a Standard Library class representing
// a sequence of characters.
//
//     string text = "Hello";
//
// Unlike raw C-string buffers, it manages its own storage.


// ========== SECTION 2: SIZE AND INDEXING ==========
//
//     text.size()
//     text.length()
//
// both report the number of characters.
//
// Valid character indexes:
//
//     0 <= i < text.size()


// ========== SECTION 3: INPUT ==========
//
// Token:
//
//     cin >> text;
//
// Full line:
//
//     getline(cin, text);
//
// >> stops at whitespace.
// getline reads through the line delimiter.


// ========== SECTION 4: CONCATENATION ==========
//
//     string c = a + b;
//
// Append:
//
//     a += b;
//     a.push_back('!');


// ========== SECTION 5: COMPARISON ==========
//
// std::string supports:
//
//     == != < > <= >=
//
// Comparisons are lexicographical.


// ========== SECTION 6: FIND ==========
//
//     text.find("abc")
//
// returns a position if found.
//
// If absent:
//
//     string::npos


// ========== SECTION 7: SUBSTR ==========
//
//     text.substr(start, length)
//
// constructs a substring.


// ========== SECTION 8: STRING PARAMETERS ==========
//
// By value:
//
//     void f(string text)
//
// copies the string.
//
// Read-only reference:
//
//     void f(const string& text)
//
// avoids a full copy and prevents modification through text.


// ========== SECTION 9: C-STRING ==========
//
// C-string:
//
//     char word[] = "cat";
//
// Actual array:
//
//     'c' 'a' 't' '\0'
//
// '\0' terminates the string.


// ========== SECTION 10: SIZEOF VS STRLEN ==========
//
//     char word[] = "hello";
//
// sizeof(word):
//     6 bytes
//
// strlen(word):
//     5 characters
//
// strlen scans until '\0'.


// ========== SECTION 11: C-STRING COMPARISON ==========
//
// Do NOT use raw array/pointer == for text comparison.
//
// Use:
//
//     strcmp(a, b) == 0
//
// std::string does support content comparison with ==.


// ========== SECTION 12: STRING LITERAL ==========
//
// A string literal should be treated as immutable.
//
//     const char* ptr = "hello";
//
// If mutable storage is needed:
//
//     char text[] = "hello";


// ========== SECTION 13: C_STR ==========
//
//     string text = "hello";
//     const char* ptr = text.c_str();
//
// ptr refers to null-terminated storage managed by text.
//
// Do not delete ptr.
// Modifying text can invalidate previously obtained pointers.


bool isPalindrome(
    const string& text
);

int countCharacter(
    const string& text,
    char target
);

void printCString(
    const char text[]
);


int main() {

    cout << boolalpha;


    cout << "=== DEMO 1: std::string ===\n";

    string text = "Hello";

    cout << "text = "
         << text << '\n';

    cout << "size = "
         << text.size() << "\n\n";


    cout << "=== DEMO 2: Indexing ===\n";

    cout << "first = "
         << text[0] << '\n';

    cout << "last = "
         << text[text.size() - 1]
         << "\n\n";


    cout << "=== DEMO 3: Modification ===\n";

    text[0] = 'Y';

    cout << text << "\n\n";


    cout << "=== DEMO 4: Concatenation ===\n";

    string first = "Data";
    string second = "Structures";

    string combined =
        first + " " + second;

    cout << combined << '\n';

    combined += " and Algorithms";

    cout << combined << "\n\n";


    cout << "=== DEMO 5: push_back/pop_back ===\n";

    string letters = "DS";

    letters.push_back('A');

    cout << letters << '\n';

    letters.pop_back();

    cout << letters << "\n\n";


    cout << "=== DEMO 6: Comparison ===\n";

    string a = "apple";
    string b = "banana";

    cout << "apple < banana: "
         << (a < b) << '\n';

    cout << "apple == banana: "
         << (a == b) << "\n\n";


    cout << "=== DEMO 7: find ===\n";

    string fruit = "banana";

    size_t pos =
        fruit.find("ana");

    cout << "position = "
         << pos << '\n';

    cout << "xyz absent = "
         << (fruit.find("xyz") == string::npos)
         << "\n\n";


    cout << "=== DEMO 8: substr ===\n";

    string algorithm = "algorithm";

    cout << algorithm.substr(0, 4)
         << "\n\n";


    cout << "=== DEMO 9: Palindrome ===\n";

    cout << "level: "
         << isPalindrome("level")
         << '\n';

    cout << "hello: "
         << isPalindrome("hello")
         << "\n\n";


    cout << "=== DEMO 10: Character Count ===\n";

    cout << "a in banana = "
         << countCharacter(
                "banana",
                'a'
            )
         << "\n\n";


    cout << "=== DEMO 11: C-String ===\n";

    char word[] = "hello";

    printCString(word);

    cout << "sizeof(word) = "
         << sizeof(word) << '\n';

    cout << "strlen(word) = "
         << strlen(word)
         << "\n\n";


    cout << "=== DEMO 12: C-String Comparison ===\n";

    char c1[] = "cat";
    char c2[] = "cat";

    cout << "strcmp equal = "
         << (strcmp(c1, c2) == 0)
         << "\n\n";


    cout << "=== DEMO 13: Mutable char Array ===\n";

    char mutableText[] = "hello";

    mutableText[0] = 'H';

    cout << mutableText
         << "\n\n";


    cout << "=== DEMO 14: c_str() ===\n";

    string cppString = "C++";

    const char* cView =
        cppString.c_str();

    cout << cView << '\n';

    return 0;
}


bool isPalindrome(
    const string& text
) {
    int left = 0;

    int right =
        static_cast<int>(text.size()) - 1;

    while (left < right) {

        if (text[left] != text[right]) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}


int countCharacter(
    const string& text,
    char target
) {
    int count = 0;

    for (char c : text) {

        if (c == target) {
            ++count;
        }
    }

    return count;
}


void printCString(
    const char text[]
) {
    int i = 0;

    while (text[i] != '\0') {
        cout << text[i];
        ++i;
    }

    cout << '\n';
}


/*
EXPECTED OUTPUT

=== DEMO 1: std::string ===
text = Hello
size = 5

=== DEMO 2: Indexing ===
first = H
last = o

=== DEMO 3: Modification ===
Yello

=== DEMO 4: Concatenation ===
Data Structures
Data Structures and Algorithms

=== DEMO 5: push_back/pop_back ===
DSA
DS

=== DEMO 6: Comparison ===
apple < banana: true
apple == banana: false

=== DEMO 7: find ===
position = 1
xyz absent = true

=== DEMO 8: substr ===
algo

=== DEMO 9: Palindrome ===
level: true
hello: false

=== DEMO 10: Character Count ===
a in banana = 3

=== DEMO 11: C-String ===
hello
sizeof(word) = 6
strlen(word) = 5

=== DEMO 12: C-String Comparison ===
strcmp equal = true

=== DEMO 13: Mutable char Array ===
Hello

=== DEMO 14: c_str() ===
C++

WHAT'S NEXT:
01_C++__/14_POINTERS/
*/
