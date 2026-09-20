/*
═══════════════════════════════════════════════
 TASK SET — C-Style Strings
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: An attendance app stores names as char arrays.
    Validating a password, reversing a word, checking a palindrome —
    every string task starts from manually walking the characters.
 🧠 HOW TO SOLVE: Always remember the '\0' terminator. Walk with an index
    or two pointers (left & right). Compare char-by-char.
 MODES/TOPICS COVERED:
   1. Manual Length
   2. Toggle Case
   3. Palindrome Check
   4. Word Count
   5. Reverse Words
   6. Remove Duplicates (In-Place)

 TASK 1 (EASY): Manual Length
    Write a function that returns the length of a C-string without strlen.
    Hint: Count until you hit '\0'.
    // STARTER CODE:
    // int myLength(const char* s) { int c=0; while(...) c++; return c; }

 TASK 2 (EASY): Toggle Case
    Convert lowercase to uppercase and vice-versa in a char array.
    Hint: 'a'-'A' = 32. Check with islower/isupper (cctype).
    // STARTER CODE:
    // void toggleCase(char s[]) { for(int i=0; s[i]!='\0'; i++) ... }

 TASK 3 (MEDIUM): Palindrome Check
    Check if a C-string reads the same forward and backward.
    Hint: Two pointers — left from start, right from end.
    // STARTER CODE:
    // bool isPalin(const char* s) { ... }

 TASK 4 (MEDIUM): Word Count
    Count the number of words in a sentence (separated by single spaces).
    Hint: Count transitions from space to non-space character.
    // STARTER CODE:
    // int countWords(const char* s) { int w=0; bool inWord=false; ... }

 TASK 5 (HARD): Reverse Words
    Reverse each word IN-PLACE keeping word order ("hi dog" → "ih god").
    Hint: When you hit a space, reverse the segment up to that point.
    // STARTER CODE:
    // void reverseWords(char s[]) { ... }

 TASK 6 (HARD): Remove Duplicates (In-Place)
    Remove consecutive duplicate characters ("aaabcc" → "abc").
    Hint: Write-pointer approach — slow index j overwrites fast index i.
    // STARTER CODE:
    // void removeDup(char s[]) { int j=1; for(int i=1; s[i]!='\0'; i++) ... }

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <cctype>   // islower, isupper, tolower, toupper
using namespace std;

// ═══════════════════════════════════════════
// TASK 1: Manual Length
// ═══════════════════════════════════════════
// while loop '\0' tak chalata hai, counter increment karta hai
int myLength(const char* s) {
    int c = 0;
    while (s[c] != '\0') c++;
    return c;
}

// ═══════════════════════════════════════════
// TASK 2: Toggle Case
// ═══════════════════════════════════════════
// ASCII difference upper/lower = 32. +32 small banata, -32 bada banata
void toggleCase(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (islower(s[i]))
            s[i] = toupper(s[i]);   // chhota → bada
        else if (isupper(s[i]))
            s[i] = tolower(s[i]);   // bada → chhota
        // space aur symbols ko touch nahi karte
    }
}

// ═══════════════════════════════════════════
// TASK 3: Palindrome Check
// ═══════════════════════════════════════════
// left-right dono ends se compare; koi mismatch = false
bool isPalin(const char* s) {
    int left = 0, right = myLength(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// ═══════════════════════════════════════════
// TASK 4: Word Count
// ═══════════════════════════════════════════
// inWord flag: space ke baad non-space aaya = naya word
int countWords(const char* s) {
    int w = 0;
    bool inWord = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            inWord = false;
        } else if (!inWord) {
            inWord = true;   // word shuru hua
            w++;
        }
    }
    return w;
}

// ═══════════════════════════════════════════
// TASK 5: Reverse Words (In-Place)
// ═══════════════════════════════════════════
// har word ke boundaries find karo (start..end), phir swap karo
void reverseWords(char s[]) {
    int n = myLength(s);
    int i = 0;
    while (i < n) {
        // space skip karo
        while (i < n && s[i] == ' ') i++;
        int start = i;
        // word ke end tak jao
        while (i < n && s[i] != ' ') i++;
        int end = i - 1;
        // is segment ko reverse karo
        int l = start, r = end;
        while (l < r) {
            char t = s[l]; s[l] = s[r]; s[r] = t;
            l++; r--;
        }
    }
}

// ═══════════════════════════════════════════
// TASK 6: Remove Consecutive Duplicates
// ═══════════════════════════════════════════
// write-pointer j: har unique char ko aage copy karta hai
void removeDup(char s[]) {
    if (s[0] == '\0') return;
    int j = 1;
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[j - 1]) {      // pichhle unique se alag hai?
            s[j] = s[i];             // copy karo
            j++;
        }
        // same hai to skip (i aage badhta rahega)
    }
    s[j] = '\0';                      // naya end marker
}

// ═══════════════════════════════════════════
// DRIVER
// ═══════════════════════════════════════════
int main() {

    // --- Task 1 ---
    cout << "=== TASK 1: Manual Length ===" << endl;
    cout << "myLength(\"hello\") = " << myLength("hello") << endl;
    cout << "myLength(\"\")     = " << myLength("") << endl;
    cout << endl;

    // --- Task 2 ---
    cout << "=== TASK 2: Toggle Case ===" << endl;
    char tog[64] = "Hello World 123!";
    cout << "Before: " << tog << endl;
    toggleCase(tog);
    cout << "After:  " << tog << endl;
    cout << endl;

    // --- Task 3 ---
    cout << "=== TASK 3: Palindrome ===" << endl;
    cout << "isPalin(\"racecar\") = " << (isPalin("racecar") ? "YES" : "NO") << endl;
    cout << "isPalin(\"hello\")   = " << (isPalin("hello") ? "YES" : "NO") << endl;
    cout << "isPalin(\"a\")       = " << (isPalin("a") ? "YES" : "NO") << endl;
    cout << endl;

    // --- Task 4 ---
    cout << "=== TASK 4: Word Count ===" << endl;
    cout << "countWords(\"the quick brown fox\") = " << countWords("the quick brown fox") << endl;
    cout << "countWords(\"\")                    = " << countWords("") << endl;
    cout << endl;

    // --- Task 5 ---
    cout << "=== TASK 5: Reverse Words ===" << endl;
    char sent[64] = "hi dog cat";
    cout << "Before: " << sent << endl;
    reverseWords(sent);
    cout << "After:  " << sent << endl;   // ih god tac
    cout << endl;

    // --- Task 6 ---
    cout << "=== TASK 6: Remove Duplicates ===" << endl;
    char dup[32] = "aaabccdeeff";
    cout << "Before: " << dup << endl;
    removeDup(dup);
    cout << "After:  " << dup << endl;   // abcdef
    cout << endl;

    // --- EDGE: Empty string in task 6 ---
    char empty[8] = "";
    removeDup(empty);
    cout << "RemoveDup on empty -> \"" << empty << "\"" << endl;

    return 0;
}