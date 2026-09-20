/*
═══════════════════════════════════════════════
 TASK SET — VARIABLES AND DATA TYPES
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
 You are a shopkeeper who needs to maintain records — product name, price,
 quantity, and whether the product is in stock. Each piece of information
 has a different type: name is text, price is decimal, quantity is whole
 number, stock status is true/false. Choosing the RIGHT data type for each
 field saves memory and prevents errors.

🧠 HOW TO SOLVE:
 Read each task carefully. Identify WHAT data to store, THEN pick the best
 data type. Use sizeof() to verify your choice. Think about edge cases —
 what if someone enters a very large number? What if they enter a character
 instead of a digit? Each task builds on the previous one.

 5 TASKS (EASY → HARD):

 ═══════════════════════════════════════════════
 TASK 1: SWAP TWO NUMBERS (no third variable)
 ═══════════════════════════════════════════════
 Statement:
   Take two integers from user and swap their values WITHOUT using a
   third variable. Print before and after.

 💡 HINT:
   Use arithmetic: a = a + b; b = a - b; a = a - b;
   Or use XOR: a = a ^ b; b = a ^ b; a = a ^ b;

 // TODO: Declare int a, b; read from user
 // TODO: Print "Before swap: a = ___, b = ___"
 // TODO: Swap using arithmetic or XOR
 // TODO: Print "After swap:  a = ___, b = ___"

 ═══════════════════════════════════════════════
 TASK 2: SIZE AND RANGE REPORT
 ═══════════════════════════════════════════════
 Statement:
   Print a TABLE showing each data type (bool, char, short, int, long,
   long long, float, double), its sizeof, and its min/max range.

 💡 HINT:
   Use cout with setw() for alignment. Include <climits> and <cfloat>.

 // TODO: Print header row with columns: Type, Size, Min, Max
 // TODO: For each type, print sizeof and range using INT_MIN/INT_MAX etc.
 // TODO: Format output neatly using setw()

 ═══════════════════════════════════════════════
 TASK 3: AREA OF CIRCLE
 ═══════════════════════════════════════════════
 Statement:
   Take radius as input. Print area using π = 3.14159.
   Use appropriate data type. Handle radius = 0 as edge case.

 💡 HINT:
   Use double for area (decimal result). Formula: area = π * r * r
   Edge case: radius 0 should print area = 0.

 // TODO: Declare double radius, area; const double PI = 3.14159;
 // TODO: Read radius from user
 // TODO: Calculate area = PI * radius * radius
 // TODO: Print area with message

 ═══════════════════════════════════════════════
 TASK 4: TEMPERATURE CONVERTER
 ═══════════════════════════════════════════════
 Statement:
   Take temperature in Celsius as float input. Convert to Fahrenheit.
   Formula: F = (C × 9/5) + 32. Print both values.
   Test with edge cases: 0°C, -40°C (where C == F), 100°C.

 💡 HINT:
   Use float. Be careful: 9/5 in integer division = 1. Use 9.0/5.0 instead.

 // TODO: Declare float celsius, fahrenheit
 // TODO: Read celsius
 // TODO: fahrenheit = (celsius * 9.0 / 5.0) + 32.0
 // TODO: Print both values formatted

 ═══════════════════════════════════════════════
 TASK 5: CHAR ARITHMETIC — Caesar Cipher
 ═══════════════════════════════════════════════
 Statement:
   Take a single character input from user. Shift it forward by 3 in the
   alphabet (a→d, x→a wrapping). Print the shifted character and its
   ASCII value. Edge case: 'z' shifted by 3 should wrap to 'c'.

 💡 HINT:
   ASCII: 'a'=97, 'z'=122. Use modulo 26 for wrapping.
   shifted = ((ch - 'a' + 3) % 26) + 'a';

 // TODO: Declare char ch; read from user
 // TODO: Check if lowercase, if so shift with wrap
 // TODO: Print original, shifted, and ASCII values

═══════════════════════════════════════════════
*/

// ==================== SOLUTIONS ====================
#include <iostream>
#include <climits>
#include <cfloat>
#include <iomanip>
using namespace std;

// -------- TASK 1: Swap Two Numbers --------
void task1_swap() {
    cout << "===== TASK 1: Swap Two Numbers =====" << endl;

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    // arithmetic swap trick — no temp variable needed
    a = a + b;    // a ab dono ka sum hai
    b = a - b;    // b me original a aa gaya
    a = a - b;    // a me original b aa gaya

    cout << "After swap:  a = " << a << ", b = " << b << endl;
    cout << endl;
}

// -------- TASK 2: Size and Range Report --------
void task2_size_report() {
    cout << "===== TASK 2: Size and Range Report =====" << endl;
    cout << left << setw(12) << "Type"
         << setw(8) << "Size(B)"
         << setw(25) << "Min"
         << setw(25) << "Max" << endl;
    cout << string(70, '-') << endl;

    cout << left << setw(12) << "bool"
         << setw(8) << sizeof(bool)
         << setw(25) << "0"
         << setw(25) << "1" << endl;

    cout << left << setw(12) << "char"
         << setw(8) << sizeof(char)
         << setw(25) << to_string(CHAR_MIN)
         << setw(25) << to_string(CHAR_MAX) << endl;

    cout << left << setw(12) << "short"
         << setw(8) << sizeof(short)
         << setw(25) << to_string(SHRT_MIN)
         << setw(25) << to_string(SHRT_MAX) << endl;

    cout << left << setw(12) << "int"
         << setw(8) << sizeof(int)
         << setw(25) << to_string(INT_MIN)
         << setw(25) << to_string(INT_MAX) << endl;

    cout << left << setw(12) << "long"
         << setw(8) << sizeof(long)
         << setw(25) << to_string(LONG_MIN)
         << setw(25) << to_string(LONG_MAX) << endl;

    cout << left << setw(12) << "long long"
         << setw(8) << sizeof(long long)
         << setw(25) << to_string(LLONG_MIN)
         << setw(25) << to_string(LLONG_MAX) << endl;

    cout << left << setw(12) << "float"
         << setw(8) << sizeof(float)
         << setw(25) << to_string(FLT_MIN)
         << setw(25) << to_string(FLT_MAX) << endl;

    cout << left << setw(12) << "double"
         << setw(8) << sizeof(double)
         << setw(25) << to_string(DBL_MIN)
         << setw(25) << to_string(DBL_MAX) << endl;

    cout << endl;
}

// -------- TASK 3: Area of Circle --------
void task3_area_circle() {
    cout << "===== TASK 3: Area of Circle =====" << endl;

    double radius;
    const double PI = 3.14159;

    cout << "Enter radius: ";
    cin >> radius;

    // edge case: negative radius invalid hai
    if (radius < 0) {
        cout << "Error: Radius cannot be negative!" << endl;
    } else {
        double area = PI * radius * radius;
        cout << "Area of circle = " << area << endl;
    }
    cout << endl;
}

// -------- TASK 4: Temperature Converter --------
void task4_temperature() {
    cout << "===== TASK 4: Temperature Converter =====" << endl;

    float celsius, fahrenheit;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // 9/5 integer division se 1 aata hai — isliye 9.0/5.0 use karo
    fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;

    cout << celsius << "°C = " << fahrenheit << "°F" << endl;

    // edge case check: -40 is where C == F
    if (celsius == -40.0f) {
        cout << "Special case: -40°C == -40°F (they are equal!)" << endl;
    }
    cout << endl;
}

// -------- TASK 5: Caesar Cipher --------
void task5_caesar_cipher() {
    cout << "===== TASK 5: Caesar Cipher (Shift +3) =====" << endl;

    char ch;
    cout << "Enter a lowercase letter: ";
    cin >> ch;

    // pehle check karo ki lowercase hai bhi ya nahi
    if (ch >= 'a' && ch <= 'z') {
        // wrap-around using modulo — 'z' + 3 should become 'c'
        char shifted = ((ch - 'a' + 3) % 26) + 'a';
        cout << "Original : " << ch << " (ASCII: " << (int)ch << ")" << endl;
        cout << "Shifted  : " << shifted << " (ASCII: " << (int)shifted << ")" << endl;
    } else if (ch >= 'A' && ch <= 'Z') {
        // uppercase version bhi handle kar lete hain
        char shifted = ((ch - 'A' + 3) % 26) + 'A';
        cout << "Original : " << ch << " (ASCII: " << (int)ch << ")" << endl;
        cout << "Shifted  : " << shifted << " (ASCII: " << (int)shifted << ")" << endl;
    } else {
        cout << "Error: Please enter a letter (a-z or A-Z)." << endl;
    }
    cout << endl;
}

int main() {
    task1_swap();
    task2_size_report();
    task3_area_circle();
    task4_temperature();
    task5_caesar_cipher();

    cout << "All tasks completed!" << endl;
    return 0;
}
