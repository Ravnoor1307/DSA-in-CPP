/*
═══════════════════════════════════════════════
 INPUT AND OUTPUT (cin, cout, formatting)
 ⏱️ TIME COMPLEXITY: O(1) — fixed number of reads and prints.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you are filling out a railway reservation form on a computer
 terminal. The form shows labels (like cout printing prompts) and waits
 for YOU to type your name, age, and seat preference (like cin reading
 input). When you press Enter, the typed text lands in a temporary tray
 called the "input buffer". The program then takes pieces from that tray
 one by one. Finally, your ticket is printed with neat alignment — name
 in one column, age in another. This is EXACTLY how cin/cout work: cout
 shows output, cin reads from a shared buffer, and formatting (setw,
 setprecision) arranges the ticket nicely.

 📖 THEORY: (pure English, beginner-level)

 1) cout — CHARACTER OUTPUT STREAM:
    - cout << value;  pushes value to the console (standard output).
    - Multiple values can be chained: cout << a << " " << b;
    - Works left-to-right like a conveyor belt.

 2) cin — CHARACTER INPUT STREAM:
    - cin >> variable;  reads ONE token from the input buffer.
    - Stops at whitespace (space, tab, newline). Decimals: 3.14 42
      → 3.14 goes to first variable, 42 to second.
    - Multiple reads: cin >> a >> b >> c;  (reads three values in order)

 3) endl vs "\n" (IMPORTANT!)
    - endl inserts a newline AND FLUSHES the output buffer.
      (forces data to appear immediately — slower but safer for debugging)
    - "\n" just inserts a newline WITHOUT flushing — faster.
    - In competitive programming/performance code, prefer "\n".

 4) INPUT BUFFER — ASCII DIAGRAM:
    User types:  Raj  21  85.5  then presses Enter

    Hard disk / keyboard → INPUT BUFFER (RAM) →
    ┌──────────────────────────────────────────┐
    │  R  a  j  \n  2  1  \n  8  5  .  5  \n  │
    └──────────────────────────────────────────┘
        │cin>>name        │cin>>age   │cin>>marks
        │reads "Raj"      │reads 21   │reads 85.5
        ▼                 ▼           ▼
       name="Raj"       age=21    marks=85.5

    NOTE: \n characters are consumed/ignored as separators.
    PROBLEM: After cin >> age, a leftover \n may remain. If you then do
    getline(cin, str), getline reads THE EMPTY LINE. Fix: cin.ignore().

 5) FORMATTED OUTPUT (include <iomanip>):
    - setw(n)  → set field width: right-aligns value in n columns.
    - setfill('*') → fill empty columns with a character.
    - setprecision(n) → total significant digits (works differently).
    - fixed + setprecision(n) → exactly n digits after decimal point.
    - left / right manipulators → alignment.

 6) WHEN TO USE WHAT:
    - endl → debugging (immediate flush, few prints)
    - "\n" → fast output (many prints, loops, CP)
    - setw   → aligning tables/columns
    - fixed << setprecision(n) → money, marks, scientific data

 7) READING CHARACTERS / LINES:
    - cin >> ch  → reads single non-whitespace char
    - cin.ignore() → discards one char (usually leftover newline)
    - getline(cin, str) → reads a whole line INCLUDING spaces

 🧠 LOGIC — STEP BY STEP: (demo program)

 Step 1: Print prompt "Enter your name: " using cout.
   WHY: User needs guidance about what to type.

 Step 2: cin >> name reads the first token (no spaces allowed in name here).
   WHY: cin reads until whitespace.

 Step 3: Print prompt for age; cin >> age reads integer.
   WHY: Whitespace separates tokens in buffer; age is a single token.

 Step 4: Print prompt for marks; cin >> marks reads a double.
   WHY: Decimal values are single tokens too.

 Step 5: Show formatted output using setw, fixed, setprecision.
   WHY: Demonstration of column alignment for neat reports.

 Step 6: Demonstrate the input-buffer pitfall with getline + cin.ignore().
   WHY: Edge case beginners ALWAYS hit — leftover newline breaks getline.

 VISUAL WALKTHROUGH (formatted output):

 cout << setw(10) << left << "Name" << setw(5) << "Age" << endl;
 cout << setw(10) << left << name  << setw(5) << age  << endl;

 ┌──────────┬─────┐
 │ Name     │ Age │
 ├──────────┼─────┤
 │ Raj      │ 21  │
 ├──────────┼─────┤
 │ Simran   │ 24  │   ← setw(10) gives equal-width columns
 └──────────┴─────┘

 setprecision example:
   double m = 85.56789;
   fixed << setprecision(2) → 85.57  (rounded to 2 decimals)

 DRY RUN (demo with input: name=Raj, age=21, marks=85.56789):

 Step 1: cout prints "Enter your name: "
 Step 2: buffer has "Raj\n21\n85.56789\n"
         cin >> name  → name = "Raj"
 Step 3: cin >> age   → age = 21
 Step 4: cin >> marks → marks = 85.56789
 Step 5: Output:
      Name        : Raj
      Age         : 21
      Marks       : 85.57      (fixed setprecision(2))
      Marks(4dp)  : 85.5679    (fixed setprecision(4))

 TIME COMPLEXITY CALCULATION:
 - Each cin >> operation and each cout << operation is constant-time
   for fixed-size inputs (name ~O(len), but bounded to a small constant).
 - We perform a fixed number (≈10) of such operations.
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - We store name (string), age (int), marks (double) — constant memory.
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌──────────────────┬──────────────────┬──────────────────────────────┐
 │ Feature          │ endl             │ "\n"                         │
 ├──────────────────┼──────────────────┼──────────────────────────────┤
 │ Newline?         │ Yes              │ Yes                          │
 │ Flushes buffer?  │ Yes (slow)       │ No (fast)                    │
 │ Use case         │ Debugging, small │ Loops, bulk output,          │
 │                  │ output           │ competitive programming      │
 └──────────────────┴──────────────────┴──────────────────────────────┘

 ┌──────────────────┬────────────────────────────────────────────────┐
 │ setprecision(n) alone  │ fixed + setprecision(n)                  │
 ├──────────────────┼────────────────────────────────────────────────┤
 │ n = TOTAL digits │ n = digits AFTER decimal point                 │
 │ 85.5678 @ p(3)   │ 85.568 (3+2 digits total count)                │
 │ → 85.6           │ 85.568 (3 after decimal)                       │
 └──────────────────┴────────────────────────────────────────────────┘
*/

#include <iostream>
#include <iomanip>    // setw, setprecision, fixed, setfill, left
#include <string>     // string class
using namespace std;

int main() {
    cout << "========== INPUT / OUTPUT DEMO ==========" << endl;

    // -------- 1. READING MULTIPLE INPUTS --------
    string name;
    int age;
    double marks;

    cout << "\nEnter your name: ";
    cin >> name;                       // pehla token read hota hai

    cout << "Enter your age: ";
    cin >> age;                        // age integer

    cout << "Enter your marks (out of 100): ";
    cin >> marks;                      // marks double value

    // -------- 2. PLAIN OUTPUT --------
    cout << "\n--- Plain Output ---" << endl;
    cout << "Name = " << name << endl;
    cout << "Age = " << age << endl;
    cout << "Marks = " << marks << endl;

    // -------- 3. FORMATTED OUTPUT (setw) --------
    cout << "\n--- Formatted Table (setw) ---" << endl;
    cout << setw(12) << left << "Field" << setw(10) << "Value" << endl;
    cout << string(22, '-') << endl;
    cout << setw(12) << left << "Name"  << setw(10) << name << endl;
    cout << setw(12) << left << "Age"   << setw(10) << age << endl;
    cout << setw(12) << left << "Marks" << setw(10) << marks << endl;

    // -------- 4. setprecision + fixed (marks report) --------
    cout << "\n--- Precision Demo ---" << endl;
    cout << "Marks (2 dp)   : " << fixed << setprecision(2) << marks << endl;
    cout << "Marks (4 dp)   : " << fixed << setprecision(4) << marks << endl;
    cout << "Marks (default): " << setprecision(3) << marks << endl;

    // edge case: precise value jo double ke precision ko chuna lagaye
    double pi = 3.14159265358979323846;
    cout << "\nPi value (6 dp): " << fixed << setprecision(6) << pi << endl;
    cout << "Pi value default: " << pi << endl;

    // -------- 5. GCF: PERCENTAGE REPORT --------
    cout << "\n--- Percentage Report (fixed << setprecision) ---" << endl;
    double percentage = (marks / 100.0) * 100.0;
    cout << "Percentage : " << fixed << setprecision(2) << percentage << "%" << endl;

    // -------- 6. THE BUFFER PITFALL (edge case with getline) --------
    cout << "\n--- Buffer Pitfall Demo ---" << endl;

    // IMPORTANT: after cin >> age, a '\n' is still in the buffer.
    // getline would read that empty line! Fix = cin.ignore().
    cin.ignore();   // leftover newline discard kar rahe hain

    string full_address;
    cout << "Enter your full address (with spaces): ";
    getline(cin, full_address);   // poori line read hoti hai (spaces ke saath)
    cout << "Address: " << full_address << endl;

    // -------- 7. setfill demo --------
    cout << "\n--- setfill Demo ---" << endl;
    cout << setfill('*') << setw(12) << right << 12345 << endl;
    cout << setfill(' ') << setw(12) << right << 12345 << endl;

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}