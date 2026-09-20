/*
═══════════════════════════════════════════════
 DATA STRUCTURE
═══════════════════════════════════════════════

 🌍 REAL-WORLD SCENARIO:
 Imagine a classroom register where each student's name and marks are
 scattered on random pages with no fixed order. Finding one student's
 marks means flipping every page — slow and messy. Now imagine a neatly
 ruled register with one box per student: name printed on the left and
 marks in the right column. Same information, but now a teacher can find,
 update or add a student in seconds. This second register is a good data
 structure: a disciplined way to store data plus the rules to use it
 quickly. Every app you use — phone contacts, bank records, maps — hides
 a data structure inside.

 📖 THEORY: (pure English, formal, beginner-level, "what is X")
 - definition: A DATA STRUCTURE is a way of organizing and storing data
   on a computer so that it can be used efficiently. It defines BOTH
   how the data is laid out in memory AND the set of operations
   (insert, delete, search, update, traverse) that can be performed on it.
 - key points / properties:
   • A data structure is not just "divided storage" — it ships with
     standard operations (add, remove, find, sort).
   • Data structures have TRAITS — time complexity, space complexity,
     whether order is preserved, whether duplicates are allowed.
   • Data Structure + Algorithm = Program. The structure holds data well;
     the algorithm drives the operations.
   • There is no "best" structure; each one is best for a specific job
     (search-heavy vs insert-heavy vs memory-tight).
   • Arrays, linked lists, stacks, queues, trees and graphs are all
     different data structures with different strengths.
 - when to use:
   • Use an array/vector when you need fast indexed access by position.
   • Use a linked list when the data grows/shrinks frequently (fast insert).
   • Use a stack for LIFO needs (undo, function calls).
   • Use a queue for FIFO needs (ticketing, printing jobs).
   • Use a tree/graph when data has hierarchy or relationships.
   Choosing the right structure is the bridge between having data and
   getting information from it efficiently.

 🧠 LOGIC — STEP BY STEP: (pure English)
 Step 1: Define a struct Student with two fields — name and marks.
         WHY: The struct wraps related facts into ONE logical unit so a
         single array can hold every student together (structure follows data).
 Step 2: Place all records into an array of Student.
         WHY: The array keeps records contiguous in memory, so a loop can
         reach each one by a plain index in constant time.
 Step 3: Print every record to show the stored layout.
         WHY: Traversal is the most basic operation every data structure
         must support; it proves the data is readable.
 Step 4: Search for a name using linear search.
         WHY: Search is the #1 real operation; the structure must keep
         records reachable fast. Duplicate names are an edge case — we
         stop at the first match.
 Step 5: Update one record (add bonus marks) and compute the average.
         WHY: Update and aggregation are typical operations; together
         they show a data structure is a home for BOTH data and actions.

 VISUAL WALKTHROUGH: (array of Student records — one unit per student)

   int top part = marks array        name array (old bad way: 2 parallel arrays)
   ┌────┬────┬────┬────┐             ┌──────┬──────┬──────┬──────┐
   │ 45 │ 78 │ 90 │ 33 │             │ Aman │ Riya │ Kabir│ Riya │
   └────┴────┴────┴────┘             └──────┴──────┴──────┴──────┘
                          ↓ better ↓
   array of struct (data + meaning together)
   ┌─────────┬─────────┬─────────┬─────────┐
   │  Aman 45 │ Riya 78 │Kabir 90 │ Riya 33 │   ← one box per student
   └─────────┴─────────┴─────────┴─────────┘
     index 0    index 1     index 2    index 3
                    │  search("Riya")
                    ▼  linear: index 0 no → index 1 yes → STOP
                 found at index 1 (marks 78)

 DRY RUN: (full trace of the demo below)
   Records : students[4] = {Aman:45, Riya:78, Kabir:90, Riya:33}, key="Riya"

   STEP 1 — traversal print loop:
     i=0 → "0: Aman -> 45 marks"
     i=1 → "1: Riya -> 78 marks"
     i=2 → "2: Kabir -> 90 marks"
     i=3 → "3: Riya -> 33 marks"

   STEP 2 — linear search for "Riya":
     i=0 → Aman == Riya? No
     i=1 → Riya == Riya? Yes → found = 1, break (stop at the first match)

   STEP 3 — update: students[0].marks += 5  → Aman: 45 → 50

   STEP 4 — sum loop: 50 + 78 + 90 + 33 = 251 → average = 251 / 4 = 62.75

 TIME COMPLEXITY CALCULATION:
   - Print loop visits all n records                 → n steps
   - Search loop: best case 1 step, worst n steps
     (if the element is at the end, all records get compared) → up to n steps
   - Update of one record (index access)             → 1 step
   - Sum loop visits all n records                   → n steps
   - Total worst case ≈ n + n + 1 + n + c = 3n + c
 → Time Complexity = O(n)   (linear search: every record is touched once)

 SPACE COMPLEXITY CALCULATION:
   - Array students holds n records (each = string + int) → n units
   - Scalar variables (key, found, sum, i, average)        → ~5 constant units
   - No copy of the whole array is created during operations
   - Total = n + 5
 → Space Complexity = O(n)

 APPROACH COMPARISON: (no data structure vs data structure)
 ┌──────────────────────┬─────────────────────────────┬──────────────────────────────┐
 │ Aspect               │ Parallel arrays (no DS)     │ Array of struct (with DS)     │
 ├──────────────────────┼─────────────────────────────┼──────────────────────────────┤
 │ Data of one student  │ Scattered in 2+ arrays      │ One single box (unit)         │
 │ Finding a student    │ Must manage indexes in both │ One search loop, one record   │
 │ Adding a field       │ Edit every parallel array   │ Add one field to the struct   │
 │ Meaning of index i   │ "marks[i] belongs to who?"  │ students[i] is self-contained │
 │ Bug risk             │ High (index mismatch)       │ Low (data is bundled)         │
 └──────────────────────┴─────────────────────────────┴──────────────────────────────┘
*/

#include <iostream>
#include <string>
using namespace std;

// struct = user-defined data structure — ek student ki saari jaankari ek sath
struct Student {
    string name;
    int marks;
};

int main() {
    // array of structs — 4 students ek hi logical unit me store hain
    Student students[4] = {
        {"Aman", 45},
        {"Riya", 78},
        {"Kabir", 90},
        {"Riya", 33}    // duplicate name — edge case intentionally rakha hai
    };

    cout << "=== Data structure in action: array of Student records ===\n";
    for (int i = 0; i < 4; i++) {
        cout << i << ": " << students[i].name << " -> "
             << students[i].marks << " marks\n";
    }

    // linear search — array ko index 0 se check karte jao
    string key = "Riya";
    int found = -1;
    for (int i = 0; i < 4; i++) {
        if (students[i].name == key) {
            found = i;
            break;      // pehla match milte hi ruk jao (duplicate edge case)
        }
    }

    if (found == -1) {
        cout << "\n'" << key << "' not found in records.\n";
    } else {
        cout << "\n'" << key << "' found at index " << found
             << " with marks " << students[found].marks << "\n";
    }

    // update operation — Aman ko bonus marks de do
    students[0].marks += 5;
    cout << "After bonus: Aman marks = " << students[0].marks << "\n";

    // aggregate operation — class average
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += students[i].marks;
    }
    cout << "Class average = " << (double)sum / 4 << "\n";

    return 0;
}