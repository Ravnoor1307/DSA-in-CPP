/*
TOPIC: Strings and C-Strings
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


// ============================================================
// PROBLEM 1: COUNT TARGET CHARACTER
// ============================================================

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


// ============================================================
// PROBLEM 2: PALINDROME
// ============================================================

bool isPalindrome(
    const string& text
) {
    size_t left = 0;
    size_t right = text.size();

    // right represents one-past-the-end.
    //
    // This structure works naturally for an empty string.
    while (left < right) {

        --right;

        if (left >= right) {
            break;
        }

        if (text[left] != text[right]) {
            return false;
        }

        ++left;
    }

    return true;
}


// ============================================================
// PROBLEM 3: REVERSE
// ============================================================

void reverseString(
    string& text
) {
    if (text.empty()) {
        return;
    }

    size_t left = 0;
    size_t right = text.size() - 1;

    while (left < right) {

        char temp = text[left];

        text[left] = text[right];
        text[right] = temp;

        ++left;
        --right;
    }
}


// ============================================================
// PROBLEM 4: COUNT DIGITS
// ============================================================

int countDigits(
    const string& text
) {
    int count = 0;

    for (char c : text) {

        if (c >= '0' && c <= '9') {
            ++count;
        }
    }

    return count;
}


// ============================================================
// PROBLEM 5: MANUAL C-STRING LENGTH
// ============================================================

int cStringLength(
    const char text[]
) {
    int length = 0;

    while (text[length] != '\0') {
        ++length;
    }

    return length;
}


// ============================================================
// BONUS: LOWERCASE ENGLISH ANAGRAM CHECK
// ============================================================
//
// Assumption:
// every character is between 'a' and 'z'.

bool areLowercaseAnagrams(
    const string& first,
    const string& second
) {
    if (first.size() != second.size()) {
        return false;
    }

    int frequency[26]{};

    for (char c : first) {
        ++frequency[c - 'a'];
    }

    for (char c : second) {
        --frequency[c - 'a'];
    }

    for (int value : frequency) {

        if (value != 0) {
            return false;
        }
    }

    return true;
}


int main() {

    cout << boolalpha;


    // ========================================================
    // TEST 1
    // ========================================================

    cout << "=== PROBLEM 1: Character Count ===\n";

    cout << countCharacter(
                "banana",
                'a'
            )
         << "\n\n";


    // ========================================================
    // TEST 2
    // ========================================================

    cout << "=== PROBLEM 2: Palindrome ===\n";

    cout << "racecar = "
         << isPalindrome("racecar")
         << '\n';

    cout << "hello = "
         << isPalindrome("hello")
         << '\n';

    cout << "empty = "
         << isPalindrome("")
         << "\n\n";


    // ========================================================
    // TEST 3
    // ========================================================

    string text = "algorithm";

    reverseString(text);

    cout << "=== PROBLEM 3: Reverse ===\n";

    cout << text << "\n\n";


    // ========================================================
    // TEST 4
    // ========================================================

    cout << "=== PROBLEM 4: Digit Count ===\n";

    cout << countDigits("DSA2026")
         << "\n\n";


    // ========================================================
    // TEST 5
    // ========================================================

    char cString[] = "pointer";

    cout << "=== PROBLEM 5: C-String Length ===\n";

    cout << cStringLength(cString)
         << '\n';

    cout << "strlen agrees = "
         << strlen(cString)
         << "\n\n";


    // ========================================================
    // BONUS
    // ========================================================

    cout << "=== BONUS: Anagrams ===\n";

    cout << "listen/silent = "
         << areLowercaseAnagrams(
                "listen",
                "silent"
            )
         << '\n';

    cout << "hello/world = "
         << areLowercaseAnagrams(
                "hello",
                "world"
            )
         << '\n';

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Character Count ===
3

=== PROBLEM 2: Palindrome ===
racecar = true
hello = false
empty = true

=== PROBLEM 3: Reverse ===
mhtirogla

=== PROBLEM 4: Digit Count ===
4

=== PROBLEM 5: C-String Length ===
7
strlen agrees = 7

=== BONUS: Anagrams ===
listen/silent = true
hello/world = false


PRACTICE LINKS

1. LeetCode 344
https://leetcode.com/problems/reverse-string/

2. LeetCode 125
https://leetcode.com/problems/valid-palindrome/

3. LeetCode 242
https://leetcode.com/problems/valid-anagram/

4. GFG - C++ String
https://www.geeksforgeeks.org/cpp-string/

5. GFG - C-Strings
https://www.geeksforgeeks.org/c-strings/


WHAT'S NEXT:
01_C++__/14_POINTERS/
*/
