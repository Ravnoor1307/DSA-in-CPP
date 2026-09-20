/*
═══════════════════════════════════════════════
 TASK SET — STRING BASICS
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: A practice lab gives you a name-board. You must
    declare strings, read them, index them, and compare the C-string and
    the C++ string representations side by side.

 🧠 HOW TO SOLVE: A compiled demo solution is given below. Declare a
    char[] with a literal, print its memory boxes (comparing s[i]=='\0'),
    note the strlen vs sizeof difference, reproduce the cin >> whitespace
    trap, read a full line with getline, then print length/size and every
    index of a string object. HINTS: last index = s.length()-1; full line
    needs getline.

 MODES/TOPICS COVERED:
  1. char s[]="hello" declaration + memory-box printing
  2. strlen vs sizeof difference
  3. Simulate cin >> with "hello world" and show the trap
  4. Read a full line with getline
  5. string length/size printing
  6. Print every index + derive the last-index formula
  7. char[] vs string comparison table (comment)
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
    char cstr[] = "hello";
    cout << "Memory: ";
    for (int i = 0; i < (int)sizeof(cstr); i++) {
        if (cstr[i] == '\0') cout << "[\\0]";
        else cout << "[" << cstr[i] << "]";
    }
    cout << "\nstrlen=" << strlen(cstr) << ", sizeof=" << sizeof(cstr) << "\n";

    istringstream input("hello world");
    char word[20];
    input >> word;
    cout << "cin trap word: " << word << "\n";

    string s = "hello";
    cout << "string length=" << s.length() << ", last index=" << s.length()-1 << "\n";
    return 0;
}

/*
OUTPUT:
Memory: [h][e][l][l][o][\0]
strlen=5, sizeof=6
cin trap word: hello
string length=5, last index=4
*/

