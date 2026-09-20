/*
═══════════════════════════════════════════════
 TASK SET — INPUT AND OUTPUT
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO:
 The school admin office needs to generate student report cards. They collect
 data (name, roll number, marks in 3 subjects) and print a nicely formatted
 card. Reading data correctly and printing it in aligned columns is exactly
 what these tasks practice.

🧠 HOW TO SOLVE:
 Always read input FIRST into correct data types, then format output using
 setw / fixed / setprecision. Remember: cin stops at whitespace, getline
 reads full lines, and leftover '\n' in the buffer breaks getline.

 5 TASKS (EASY → HARD):

 ═══════════════════════════════════════════════
 TASK 1: READ AND PRINT THREE NUMBERS
 ═══════════════════════════════════════════════
 Statement:
   Read three integers a, b, c. Print them one per line.
   Then print their sum and average (average formatted to 2 decimals).

 💡 HINT:
   Sum = a+b+c; Average = sum / 3.0  (use 3.0, NOT 3).
   Format average with fixed << setprecision(2).

 // TODO: Declare int a, b, c
 // TODO: cin >> a >> b >> c
 // TODO: Print each number on its own line
 // TODO: Print sum and average (fixed, setprecision(2))

 ═══════════════════════════════════════════════
 TASK 2: PERSONAL DETAIL FORM
 ═══════════════════════════════════════════════
 Statement:
   Read first name (string, no spaces), age (int), and height in cm
   (double). Print all in a formatted 3-column table with headers,
   using setw.

 💡 HINT:
   Use left manipulator and setw(n). Headers: Name | Age | Height.

 // TODO: Read firstName, age, height
 // TODO: Print table header using setw
 // TODO: Print each row aligned (setw(12) etc.)

 ═══════════════════════════════════════════════
 TASK 3: BOOK DEPOSIT — FIXED DEPOSIT INTEREST REPORT
 ═══════════════════════════════════════════════
 Statement:
   Read principal amount (double), rate % (double), and time in years
   (int). Print simple interest and total amount with 2 decimal places.

 💡 HINT:
   SI = (P × R × T) / 100. Output with fixed << setprecision(2).
   Edge case: P=0 → 0 output; rate negative → reject.

 // TODO: Read P, R, T
 // TODO: Validate (P < 0 or R < 0 → print error)
 // TODO: Calculate SI = (P * R * T) / 100.0
 // TODO: Print SI and total (P + SI) formatted to 2 dp

 ═══════════════════════════════════════════════
 TASK 4: EMOJI/BANNER PRINTER WITH SETFILL
 ═══════════════════════════════════════════════
 Statement:
   Read a word from user. Print it inside a decorative banner:
     ***********
     *  Hello  *
     ***********
   Use setfill and setw to center the word.

 💡 HINT:
   border width = word length + 4. Print border, then
   "* " + word + " *", then border again. Or use setw tricks.

 // TODO: Read a word
 // TODO: Compute border length = word.length() + 4
 // TODO: Print top border with setfill('*')
 // TODO: Print middle line with the word
 // TODO: Print bottom border

 ═══════════════════════════════════════════════
 TASK 5: STUDENT REPORT CARD GENERATOR
 ═══════════════════════════════════════════════
 Statement:
   Read: name (with spaces! → use getline), roll number (int),
   marks in 3 subjects (doubles). Compute total & percentage.
   Print a complete formatted report card with borders and alignment.

 💡 HINT:
   Use cin.ignore() after reading roll to remove '\n' before getline.
   Print each row with setw for a neat table-like card.

 // TODO: cin.ignore() after numeric input, then getline for name
 // TODO: Read 3 subject marks
 // TODO: total = sum; percentage = total / 3.0
 // TODO: Print report card with aligned borders (setw, setfill, left/right)

═══════════════════════════════════════════════
*/

// ==================== SOLUTIONS ====================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// -------- TASK 1: Read and Print Three Numbers --------
void task1_three_numbers() {
    cout << "===== TASK 1: Three Numbers =====" << endl;

    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;   // ek saath 3 values read kar sakte hain

    cout << "Numbers:" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    int sum = a + b + c;
    // 3.0 se divide — warna integer division hojati (average galt)
    double avg = sum / 3.0;

    cout << "Sum     = " << sum << endl;
    cout << "Average = " << fixed << setprecision(2) << avg << endl;
    cout << endl;
}

// -------- TASK 2: Personal Detail Form --------
void task2_personal_form() {
    cout << "===== TASK 2: Personal Detail Form =====" << endl;

    string firstName;
    int age;
    double height;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter height (cm): ";
    cin >> height;

    // table header aur rows — setw se column alignment perfect hoti hai
    cout << "\n" << left
         << setw(12) << "Name"
         << setw(8) << "Age"
         << setw(12) << "Height(cm)"
         << endl;
    cout << string(32, '-') << endl;
    cout << left
         << setw(12) << firstName
         << setw(8) << age
         << setw(12) << fixed << setprecision(1) << height
         << endl;
    cout << endl;
}

// -------- TASK 3: Simple Interest Calculator --------
void task3_interest() {
    cout << "===== TASK 3: Simple Interest =====" << endl;

    double P, R;
    int T;

    cout << "Enter Principal (P): ";
    cin >> P;
    cout << "Enter Rate (R %): ";
    cin >> R;
    cout << "Enter Time (T years): ";
    cin >> T;

    // edge case validation
    if (P < 0 || R < 0) {
        cout << "Error: Principal and Rate cannot be negative!" << endl;
    } else {
        double si = (P * R * T) / 100.0;
        double total = P + si;

        cout << fixed << setprecision(2);
        cout << "Simple Interest = " << si << endl;
        cout << "Total Amount    = " << total << endl;
    }
    cout << endl;
}

// -------- TASK 4: Decorative Banner --------
void task4_banner() {
    cout << "===== TASK 4: Decorative Banner =====" << endl;

    string word;
    cout << "Enter a word: ";
    cin >> word;

    int border_len = word.length() + 4;   // '*' ke liye 2 + spaces 2

    cout << setfill('*') << setw(border_len) << "" << endl;   // top border
    cout << setfill(' ') << "* " << word << " *" << endl;      // middle line
    cout << setfill('*') << setw(border_len) << "" << endl;   // bottom border

    // setfill reset — agle kaam me '*' na chalu rahe
    cout << setfill(' ');
    cout << endl;
}

// -------- TASK 5: Report Card Generator --------
void task5_report_card() {
    cout << "===== TASK 5: Student Report Card =====" << endl;

    string name;
    int roll;
    double m1, m2, m3;

    cout << "Enter roll number: ";
    cin >> roll;

    // cin.ignore() zaruari — otherwise getline empty line read kar lega!
    cin.ignore();

    cout << "Enter full name: ";
    getline(cin, name);

    cout << "Enter marks in Subject 1: ";
    cin >> m1;
    cout << "Enter marks in Subject 2: ";
    cin >> m2;
    cout << "Enter marks in Subject 3: ";
    cin >> m3;

    double total = m1 + m2 + m3;
    double percentage = total / 3.0;

    // ---- REPORT CARD PRINTING ----
    cout << setfill('-') << setw(40) << "" << endl;
    cout << setfill(' ') << setw(20) << right << "REPORT CARD" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << setfill(' ');

    cout << left << setw(20) << "Student Name"   << ": " << name
         << setw(10) << "" << "Roll: " << roll << endl;
    cout << left << setw(20) << "Subject 1"      << ": " << fixed
         << setprecision(2) << m1 << endl;
    cout << left << setw(20) << "Subject 2"      << ": " << m2 << endl;
    cout << left << setw(20) << "Subject 3"      << ": " << m3 << endl;
    cout << left << setw(20) << "Total Marks"    << ": " << total << endl;
    cout << left << setw(20) << "Percentage"     << ": " << percentage << "%"
         << endl;

    cout << setfill('-') << setw(40) << "" << endl;
    cout << setfill(' ');
    cout << endl;
}

int main() {
    task1_three_numbers();
    task2_personal_form();
    task3_interest();
    task4_banner();
    task5_report_card();

    cout << "All tasks completed!" << endl;
    return 0;
}