/*
═══════════════════════════════════════════════
 TASK SET — HOMOGENEOUS vs NON-HOMOGENEOUS DATA STRUCTURES
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A school office keeps every student's roll number, name
 and marks in ONE file each (struct = non-homogeneous record). The + list of all
 marks (homogeneous array) is used for quick averages. These tasks mix both ideas:
 single-type arrays for quick maths and arrays-of-struct for full records.
🧠 HOW TO SOLVE: Use struct + array of struct to hold mixed-type records; use a
 simple int/float array when all values share one type. Access fields with the
 dot operator '.'

 TASK 1 (EASY): Define struct Student { int id; char name[20]; float marks; }.
   Create an array of 3 students, fill it, print id / name / marks of each.
 💡 HINT: braces init: Student s[3] = { {1,"A",90}, ... };
 ✏️ STARTER CODE:
   struct Student { int id; char name[20]; float marks; };
   int main() {
       Student s[3] = { {101,"Alice",88.5}, {102,"Bob",74.0}, {103,"Charlie",91.25} };
       // TODO: print each record as  ID: ... Name: ... Marks: ...
       return 0;
   }

 TASK 2 (EASY): Extend task 1 — find and print the student with the SMALLEST
   marks (the weakest student).
 💡 HINT: keep a "topper-like" index of minimum while looping through all records.
 ✏️ STARTER CODE:
   // reuse struct and array
   // TODO: find index of student with minimum marks, print entire record
   // TODO: if marks equal, first record wins

 TASK 3 (MEDIUM): Compute the AVERAGE marks of all students and also count how
   many students scored ABOVE the average.
 💡 HINT: two passes — pass 1 sum marks for average, pass 2 count mark > avg.
 ✏️ STARTER CODE:
   // TODO: pass 1: sum all marks -> avg = sum/n
   // TODO: pass 2: count students with marks > avg, print count

 TASK 4 (MEDIUM): Sort the array of students by marks in DESCENDING order
   (bubble sort on structures).
 💡 HINT: when swapping, swap whole Student records (all fields together).
 ✏️ STARTER CODE:
   // TODO: bubble sort comparing s[j].marks > s[j+1].marks
   // TODO: after sorting, print rank list with names and marks

 TASK 5 (HARD): Read n students from the user (n <= 100). Input id, name, marks
   for each. Then print PASS (marks >= 40) or FAIL for every student and give the
   class average.
 💡 HINT: use a fixed array of size 100 and cap n at 100 (reasonable static use).
 ✏️ STARTER CODE:
   Student s[100];
   int n; cin >> n;             // assume n <= 100
   // TODO: fill fields using cin
   // TODO: for each print "Name — PASS/FAIL"; compute class average

 TASK 6 (HARD): "Mixed-type" problem — print a toppers report: for every student
   print grade by marks rule: >=90 'A', >=75 'B', >=60 'C', >=40 'D', else 'F'.
   Also store all marks in a homogeneous int array (marksList) and print the
   highest mark from that array (proves homogeneous vs non-homogeneous usage).
 💡 HINT: two structures: Student[] (records) and int[] (marks) — use both.
 ✏️ STARTER CODE:
   // TODO: grade function/condition per student
   // TODO: fill int marksList[3] from s[i].marks, find max in that int array

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------

#include <iostream>
using namespace std;

struct Student {
    int id;
    char name[20];
    float marks;
};

// ---------- SOLUTION TASK 1 ----------
void task1() {
    Student s[3] = {
        {101, "Alice",   88.5},
        {102, "Bob",     74.0},
        {103, "Charlie", 91.25}
    };
    for (int i = 0; i < 3; i++) {
        cout << "ID: " << s[i].id << " | Name: " << s[i].name
             << " | Marks: " << s[i].marks << "\n";
    }
}

// ---------- SOLUTION TASK 2 ----------
void task2() {
    Student s[3] = {
        {101, "Alice",   88.5},
        {102, "Bob",     74.0},
        {103, "Charlie", 91.25}
    };
    int minIdx = 0;                          // pehle man liya s[0] minimum hai
    for (int i = 1; i < 3; i++) {
        if (s[i].marks < s[minIdx].marks) minIdx = i;
    }
    cout << "Weakest: ID: " << s[minIdx].id << " " << s[minIdx].name
         << " with " << s[minIdx].marks << " marks\n";
}

// ---------- SOLUTION TASK 3 ----------
void task3() {
    Student s[3] = {
        {101, "Alice",   88.5},
        {102, "Bob",     74.0},
        {103, "Charlie", 91.25}
    };
    float sum = 0;
    for (int i = 0; i < 3; i++) sum += s[i].marks;   // pass 1: sum nikala
    float avg = sum / 3;

    int count = 0;
    for (int i = 0; i < 3; i++) if (s[i].marks > avg) count++;  // pass 2: count

    cout << "Average = " << avg << " | Students above average = " << count << "\n";
}

// ---------- SOLUTION TASK 4 ----------
void task4() {
    Student s[3] = {
        {101, "Alice",   88.5},
        {102, "Bob",     74.0},
        {103, "Charlie", 91.25}
    };
    // bubble sort — poora record ek saath swap hota hai
    for (int i = 0; i < 2; i++) {            // 3 elements -> 2 passes enough
        for (int j = 0; j < 2 - i; j++) {
            if (s[j].marks < s[j + 1].marks) {   // descending order
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    cout << "Rank list:\n";
    for (int i = 0; i < 3; i++) {
        cout << "  #" << i + 1 << " " << s[i].name << " (" << s[i].marks << ")\n";
    }
}

// ---------- SOLUTION TASK 5 ----------
void task5() {
    const int MAX = 100;
    Student s[MAX];
    int n;
    cout << "Number of students (<= " << MAX << "): ";
    cin >> n;
    if (n > MAX) { cout << "Too many!\n"; return; }

    float sum = 0;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": id name marks -> ";
        cin >> s[i].id >> s[i].name >> s[i].marks;
        sum += s[i].marks;
    }
    cout << "\nResults:\n";
    for (int i = 0; i < n; i++) {
        cout << "  " << s[i].name << " -> "
             << (s[i].marks >= 40 ? "PASS" : "FAIL") << "\n";
    }
    cout << "Class average = " << (sum / n) << "\n";
}

// ---------- SOLUTION TASK 6 ----------
void task6() {
    Student s[3] = {
        {101, "Alice",   88.5},
        {102, "Bob",     74.0},
        {103, "Charlie", 91.25}
    };
    int marksList[3];   // homogeneous int array — sirf marks

    cout << "Grade report:\n";
    for (int i = 0; i < 3; i++) {
        marksList[i] = (int)s[i].marks;   // non-homogeneous -> homogeneous copy
        char grade;
        if (s[i].marks >= 90) grade = 'A';
        else if (s[i].marks >= 75) grade = 'B';
        else if (s[i].marks >= 60) grade = 'C';
        else if (s[i].marks >= 40) grade = 'D';
        else grade = 'F';
        cout << "  " << s[i].name << " -> " << grade << "\n";
    }

    int maxMarks = marksList[0];
    for (int i = 1; i < 3; i++) if (marksList[i] > maxMarks) maxMarks = marksList[i];
    cout << "Highest mark (from homogeneous int array) = " << maxMarks << "\n";
}

int main() {
    cout << "===== TASK 1 =====\n"; task1();
    cout << "===== TASK 2 =====\n"; task2();
    cout << "===== TASK 3 =====\n"; task3();
    cout << "===== TASK 4 =====\n"; task4();
    cout << "===== TASK 5 =====\n"; task5();
    cout << "===== TASK 6 =====\n"; task6();
    return 0;
}