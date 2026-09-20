/*
═══════════════════════════════════════════════
 HOMOGENEOUS vs NON-HOMOGENEOUS DATA STRUCTURES
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Think of a train berth where every seat is the same style and colour — all
 identical items, that is HOMOGENEOUS. Now open a school admission register:
 each student row has a roll number (whole number), a name (text) and marks
 (decimal value). Each row mixes DIFFERENT kinds of data together — that is a
 NON-HOMOGENEOUS record. A classroom of identical desks vs. a file where each
 student has many different fields.

 📖 THEORY: (pure English, beginner-level)
 - Definition:
   * HOMOGENEOUS structure stores ONLY ONE data type — e.g. an array of int,
     an array of char, a list of floats.
   * NON-HOMOGENEOUS structure stores items of DIFFERENT types together — e.g.
     a C++ struct that has an int, a char array and a float in one record.
 - Arrays are the classic homogeneous structure: int marks[5] = all ints.
 - Struct/class (C++) combine several fields of different types -> each record
   is non-homogeneous, but an ARRAY OF such structs is a list of full records.
 - A struct is like a small suitcase with compartments: one for id (int), one
   for name (char[]), one for marks (float).
 - When to use:
   * homogeneous array -> simple ordered list of same-type values (marks of a
     subject, list of prices).
   * non-homogeneous struct -> one logical entity with multiple attributes
     (a Student, an Employee, a Bank Account).

 VISUAL WALKTHROUGH — memory layout of struct Student:

   struct Student {
     int    id;      // 4 bytes
     char   name[20];// 20 bytes
     float  marks;   // 4 bytes
   };

   Address layout (int = 4 bytes assumed):
   +--------+------------------------+--------+
   | id(4B) |        name(20B)        | marks  |
   | 101    |   "Alice\0..........."  | 88.5   |
   +--------+------------------------+--------+
   step  0     4                     24   28 bytes
   (compiler may add padding so sizeof may be > 28)

   Array of 3 structs -> three such blocks side by side:
   +--------+------------------------+--------+ +--------+...
   |  s[0]  |          s[0].name      | marks  | |  s[1]  |
   +--------+------------------------+--------+ +--------+...

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Define the struct with all needed fields.
         WHY: a struct is a blueprint for one composite record.
 Step 2: Create an array of that struct type (e.g. Student s[3]).
         WHY: we want MANY records of the same blueprint.
 Step 3: Use the dot operator '.' to reach each field (s[i].id, s[i].name).
         WHY: the dot operator selects a member inside a given record.
 Step 4: Iterate with a for loop over all records and print every field.
         WHY: the loop gives O(n) traversal of all records.

 DRY RUN: (demo below)
   s[0] = {101, "Alice",   88.5 }
   s[1] = {102, "Bob",     74.0 }
   s[2] = {103, "Charlie", 91.25}
   Loop i=0: print ID:101 | Name:Alice    | Marks:88.5
   Loop i=1: print ID:102 | Name:Bob      | Marks:74
   Loop i=2: print ID:103 | Name:Charlie  | Marks:91.25
   Each iteration does constant work -> total time grows linearly with 3 records.

 TIME COMPLEXITY CALCULATION:
 - Printing / scanning n records with a single for loop:
   Each record costs O(1) (fixed fields). For n records:
   total = 1 + 1 + ... + 1 (n times)  => n steps.
   → Time Complexity = O(n)

 SPACE COMPLEXITY CALCULATION:
 - Each record uses a fixed amount of memory = sizeof(Student).
   For n records: n * sizeof(Student) bytes.
   → Space Complexity = O(n)

 APPROACH COMPARISON:
 ┌───────────────────────┬──────────────────────────────┬──────────────────────────────┐
 │ Aspect                │ Homogeneous (array of int)   │ Non-homogeneous (struct)     │
 ├───────────────────────┼──────────────────────────────┼──────────────────────────────┤
 │ Data types inside     │ Only ONE type                │ Multiple types (id,name,marks)│
 │ Logical meaning       │ list of similar values       │ one record with many fields  │
 │ Access                │ arr[i]                       │ s[i].fieldName               │
 │ Use case              │ marks[], prices[], scores[]  │ Student, Employee, Account   │
 └───────────────────────┴──────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
using namespace std;

struct Student {
    int id;          // int: homogeneous field? nahi — poora struct mixed types hai
    char name[20];   // char array field
    float marks;     // float field
};

int main() {
    // array of structs = 3 records, har record me alag-alag data types
    Student s[3] = {
        {101, "Alice",   88.5 },
        {102, "Bob",     74.0 },
        {103, "Charlie", 91.25}
    };

    cout << "Student records (non-homogeneous: int + char[] + float):\n";
    for (int i = 0; i < 3; i++) {
        cout << "  ID: " << s[i].id
             << " | Name: " << s[i].name
             << " | Marks: " << s[i].marks << "\n";
    }

    cout << "\nsizeof(Student) = " << sizeof(Student)
         << " bytes (could include padding)\n";

    // edge case: homogeneous array of same-type ints for comparison
    int marks[3] = {88, 92, 75};   // sirf ints -> homogeneous
    cout << "\nHomogeneous int array marks[3]: ";
    for (int i = 0; i < 3; i++) cout << marks[i] << " ";
    cout << "\n(one type only -> homogeneous)\n";
    return 0;
}