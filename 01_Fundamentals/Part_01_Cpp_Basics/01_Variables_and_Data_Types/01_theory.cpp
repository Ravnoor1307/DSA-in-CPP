/*
═══════════════════════════════════════════════
 VARIABLES AND DATA TYPES
 ⏱️ TIME COMPLEXITY: O(1) — all operations are constant-time assignments and prints.
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine you walk into a hotel and the receptionist gives you a room key.
 The ROOM NUMBER on the key is like a variable name — it points to ONE specific
 room. The ROOM ITSELF is the memory location. Different room types (single,
 double, suite) are like different data types — they determine how much space
 you get and what you can store inside. You cannot store a king-sized bed in
 a single room (overflow!) and you should not store just a toothbrush in a
 suite (waste of space!). Choosing the right room type = choosing the right
 data type. This is the foundation of ALL programming — without variables you
 cannot store, retrieve, or manipulate ANY data.

 📖 THEORY: (pure English, beginner-level)

 1) WHAT IS A VARIABLE?
    - A variable is a NAMED container in memory that stores a value.
    - When you write: int age = 21;
      → "age"  = variable name (identifier)
      → 21     = value stored
      → int    = data type (tells compiler HOW MUCH memory to allocate)

 2) DATA TYPES AND THEIR SIZES (on most modern compilers):
    ┌──────────────┬──────────┬──────────────────────────────────────────┐
    │ Data Type    │ Size     │ Range                                    │
    ├──────────────┼──────────┼──────────────────────────────────────────┤
    │ bool         │ 1 byte   │ false (0) or true (1)                    │
    │ char         │ 1 byte   │ -128 to 127  (ASCII)                     │
    │ short        │ 2 bytes  │ -32,768 to 32,767                        │
    │ int          │ 4 bytes  │ -2,147,483,648 to 2,147,483,647          │
    │ long         │ 4 bytes  │ same as int (on Windows/MSVC)            │
    │ long long    │ 8 bytes  │ -9.2e18 to 9.2e18                        │
    │ float        │ 4 bytes  │ ~6-7 decimal digits precision             │
    │ double       │ 8 bytes  │ ~15-16 decimal digits precision           │
    └──────────────┴──────────┴──────────────────────────────────────────┘

 3) DECLARATION vs INITIALIZATION:
    - Declaration:  int x;        → compiler reserves memory, value is GARBAGE
    - Initialization: int x = 10; → memory reserved AND filled with 10
    - Multiple declaration: int a = 1, b = 2, c = 3;

 4) ASCII MEMORY DIAGRAM:
    When you write:
      int    a = 65;      // 4 bytes
      char   b = 'A';     // 1 byte
      float  c = 3.14f;   // 4 bytes

    Memory (simplified):
    ┌──────────────────────────────────────────────────────┐
    │ Address   │ Variable │ Type   │ Size │ Value         │
    ├──────────────────────────────────────────────────────┤
    │ 0x1000    │ a        │ int    │ 4B   │ 00000041      │
    │ 0x1004    │ b        │ char   │ 1B   │ 41            │
    │ 0x1005    │ c        │ float  │ 4B   │ 4048F5C3(hex) │
    └──────────────────────────────────────────────────────┘
    Note: 'A' has ASCII value 65 = 0x41 in hex.

 5) TYPE MODIFIERS:
    - signed   → can hold negative AND positive (default for int)
    - unsigned → only positive (doubles the positive range)
    - short    → smaller version
    - long     → can be larger (platform dependent)

 6) WHEN TO USE WHAT:
    - int      → whole numbers within ~2 billion (most common)
    - long long → very large integers (counts, large sums)
    - float    → decimal when 6-7 digit precision is enough
    - double   → decimal when high precision is needed (default choice)
    - char     → single characters, ASCII operations
    - bool     → true/false flags, conditions

 🧠 LOGIC — STEP BY STEP:

 Step 1: Include iostream for input/output.
   WHY: cout and sizeof require this header.

 Step 2: Declare variables of each type in main().
   WHY: We need to show size, range, and behavior of each type.

 Step 3: Use sizeof operator to print size of each variable.
   WHY: sizeof returns the number of bytes a type occupies — confirms our table.

 Step 4: Print minimum and maximum values using <climits> and <cfloat>.
   WHY: Shows exact ranges the compiler supports.

 Step 5: Demonstrate ASCII relationship between char and int.
   WHY: Characters are stored as integers internally — important concept.

 Step 6: Show arithmetic overflow as an edge case.
   WHY: Beginners must understand what happens when a value exceeds the type's range.

 VISUAL WALKTHROUGH:

  Declaration: int x = 42;
  ┌────────────────────────────────────────┐
  │ Step 1: Compiler sees "int" → allocates│
  │         4 bytes at some address.        │
  │ Step 2: Compiler sees "= 42" → stores  │
  │         42 in those 4 bytes.            │
  │ Step 3: Name "x" maps to that address. │
  └────────────────────────────────────────┘

  ASCII of 'A' = 65, 'a' = 97, '0' = 48
  ┌────────────────────────────────────────┐
  │  char ch = 'A';  → stored as 65 (int) │
  │  int  num = ch;  → num becomes 65      │
  │  char ch2 = 66;  → ch2 becomes 'B'     │
  └────────────────────────────────────────┘

 DRY RUN (demo program output for key variables):

  sizeof(int)    → 4
  sizeof(char)   → 1
  sizeof(float)  → 4
  sizeof(double) → 8
  sizeof(bool)   → 1
  sizeof(long long) → 8

  CHAR 'A' = 65 in decimal = 01000001 in binary
  CHAR 'a' = 97
  CHAR '0' = 48

  int max  = 2147483647
  int max + 1 = -2147483648  (OVERFLOW wraps around!)

 TIME COMPLEXITY CALCULATION:
 - All operations are: declarations (1 step each), sizeof (1 step),
   value prints (1 step each), one overflow demonstration (1 step).
 - Total steps = constant (about 15-20 print statements).
 → Time Complexity = O(1)

 SPACE COMPLEXITY CALCULATION:
 - We declare about 10-12 variables of various types.
 - Total memory = sum of sizes of all declared variables (constant).
 → Space Complexity = O(1)

 APPROACH COMPARISON:
 ┌─────────────────────┬──────────────────────────┬──────────────────────────┐
 │ Aspect              │ int                      │ long long                │
 ├─────────────────────┼──────────────────────────┼──────────────────────────┤
 │ Size                │ 4 bytes                  │ 8 bytes                  │
 │ Max Value           │ ~2.1 billion             │ ~9.2 × 10^18            │
 │ Memory Efficient?   │ Yes (for small numbers)  │ No (wastes 4 bytes       │
 │                     │                          │  if value fits in int)   │
 │ When to Use         │ Counters, indices,       │ Large sums, factorials,  │
 │                     │ everyday calculations    │ competitive programming  │
 └─────────────────────┴──────────────────────────┴──────────────────────────┘

 ┌─────────────────────┬──────────────────────────┬──────────────────────────┐
 │ Aspect              │ float                    │ double                   │
 ├─────────────────────┼──────────────────────────┼──────────────────────────┤
 │ Size                │ 4 bytes                  │ 8 bytes                  │
 │ Precision           │ ~6-7 digits              │ ~15-16 digits            │
 │ Use Case            │ Graphics, games          │ Scientific computing,    │
 │                     │ (less precision OK)      │ financial (more precise) │
 └─────────────────────┴──────────────────────────┴──────────────────────────┘
*/

#include <iostream>
#include <climits>   // INT_MAX, INT_MIN, LLONG_MAX etc.
#include <cfloat>    // FLT_MAX, DBL_MAX etc.
using namespace std;

int main() {
    cout << "========== VARIABLE & DATA TYPES DEMO ==========" << endl;

    // -------- 1. DECLARATION AND INITIALIZATION --------
    int age = 21;                    // integer: whole number
    char grade = 'A';                // single character
    float pi = 3.14f;                // 3.14 as float (f suffix)
    double precise_pi = 3.141592653589793; // double has more precision
    bool is_student = true;          // true or false
    long long big_number = 9876543210LL; // large integer

    cout << "\n--- Declared Values ---" << endl;
    cout << "age         = " << age << endl;
    cout << "grade       = " << grade << endl;
    cout << "pi (float)  = " << pi << endl;
    cout << "pi (double) = " << precise_pi << endl;
    cout << "is_student  = " << is_student << endl;       // prints 1 for true
    cout << "big_number  = " << big_number << endl;

    // -------- 2. SIZEOF — HOW MANY BYTES? --------
    cout << "\n--- Sizes (in bytes) ---" << endl;
    cout << "bool        : " << sizeof(bool) << " byte" << endl;
    cout << "char        : " << sizeof(char) << " byte" << endl;
    cout << "short       : " << sizeof(short) << " bytes" << endl;
    cout << "int         : " << sizeof(int) << " bytes" << endl;
    cout << "long        : " << sizeof(long) << " bytes" << endl;
    cout << "long long   : " << sizeof(long long) << " bytes" << endl;
    cout << "float       : " << sizeof(float) << " bytes" << endl;
    cout << "double      : " << sizeof(double) << " bytes" << endl;

    // -------- 3. RANGES FROM CLIMITS / CFLOAT --------
    cout << "\n--- Ranges ---" << endl;
    cout << "int min     : " << INT_MIN << endl;
    cout << "int max     : " << INT_MAX << endl;
    cout << "long long min: " << LLONG_MIN << endl;
    cout << "long long max: " << LLONG_MAX << endl;
    cout << "float max   : " << FLT_MAX << endl;
    cout << "double max  : " << DBL_MAX << endl;

    // -------- 4. UNSIGNED — ONLY POSITIVE --------
    unsigned int positive_only = 4294967295U; // max unsigned int (4 bytes)
    cout << "\n--- Unsigned ---" << endl;
    cout << "unsigned int max : " << positive_only << endl;

    // -------- 5. CHAR AND ASCII --------
    cout << "\n--- Char & ASCII ---" << endl;
    char ch = 'A';
    cout << "char 'A' as int : " << (int)ch << endl;   // 65
    cout << "char 'a' as int : " << (int)'a' << endl;  // 97
    cout << "char '0' as int : " << (int)'0' << endl;  // 48
    cout << "char 66 as char : " << (char)66 << endl;   // 'B'

    // -------- 6. ARITHMETIC AND OVERFLOW EDGE CASE --------
    cout << "\n--- Overflow Demo (edge case) ---" << endl;
    int max_int = INT_MAX;       // 2147483647
    cout << "INT_MAX        = " << max_int << endl;
    cout << "INT_MAX + 1    = " << max_int + 1 << endl; // wraps to -2147483648
    // ye wrap-around bahut common bug hai — hamesha check karo!

    // -------- 7. FLOAT PRECISION EDGE CASE --------
    cout << "\n--- Float Precision Edge Case ---" << endl;
    float f = 1.0f / 3.0f;
    double d = 1.0 / 3.0;
    cout << "float  1/3 = " << f << endl;   // 0.333333
    cout << "double 1/3 = " << d << endl;   // 0.333333333333333
    // float me precision kam hai — isliye scientific me double use hota hai

    // -------- 8. BOOLEAN PRINTING --------
    cout << "\n--- Bool ---" << endl;
    bool flag_true = true;
    bool flag_false = false;
    cout << "true  as int: " << flag_true << endl;   // 1
    cout << "false as int: " << flag_false << endl;  // 0
    // Note: non-zero values are treated as true in conditions

    cout << "\n========== DEMO COMPLETE ==========" << endl;
    return 0;
}
