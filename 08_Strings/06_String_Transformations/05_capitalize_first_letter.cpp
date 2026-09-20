/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 05_capitalize_first_letter.cpp
│
│ REAL-WORLD SCENARIO:
│ Document editor title case feature me "hello world" ko "Hello World" banana hai. Har word ke first letter ko uppercase karna hoga.
│
│ LOGIC (step-by-step, Hinglish):
│ 1. Start of word track karo using `newWord` flag.
│ 2. Agar current char alphabet and newWord true hai, uppercase karo.
│ 3. Non-space char ke baad newWord=false.
│ 4. Space ke baad newWord=true.
│ 5. Baaki letters lowercase optionally kar sakte hain; yahan first letter capitalize focus hai.
│
│ ASCII VISUAL / COUNT STATE:
│ s="hello world from dsa"
│ h is new word -> H
│ e/l/l/o same word
│ space -> next char new word
│ w -> W
│ result: Hello World From Dsa
│
│ DRY RUN:
│ h newWord -> H
│ chars ello keep
│ space -> newWord true
│ w -> W
│ rest keep
│
│ FLOW OF EXECUTION:
│ input string -> scan/build frequency/transform -> produce output
│
│ COMPLEXITY CALCULATION:
│ - Loop visits n chars once.
│ - Each char constant checks/conversion.
│ -> Time Complexity = O(n).
│
│ SPACE COMPLEXITY CALCULATION:
│ - In-place modification.
│ -> Extra Space Complexity = O(1).
└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s = "hello world from dsa";
    bool newWord = true;
    for (char& ch : s) {
        if (ch == ' ') {
            newWord = true;
        } else {
            if (newWord) ch = (char)toupper((unsigned char)ch);
            newWord = false;
        }
    }
    cout << "Capitalized = " << s << "\n";
    return 0;
}

/*
OUTPUT:
Capitalized = Hello World From Dsa
*/

