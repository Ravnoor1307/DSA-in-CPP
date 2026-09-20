/*
═══════════════════════════════════════════════
 TASK SET — STRUCTURES
═══════════════════════════════════════════════
🌍 REAL-WORLD SCENARIO: A company keeps employee records — each record
   (struct) bundles name, id, department, salary. The HR system computes
   the average salary, updates salaries with a pointer, and prints each
   record. Treat a struct like a PAPER FORM: you pass the form by value
   (a photocopy — changes don't affect the original) or by pointer
   (the original file in hand — edits apply immediately).

🧠 HOW TO SOLVE: Define struct with fields. Create objects, arrays of
   objects, pointers to objects. Use DOT (s.field) on a real object,
   ARROW (p->field) on a pointer. To compute average: sum salaries in a
   loop, divide by count. Pass arrays of structs to functions by pointer
   to avoid copying huge blocks.
═══════════════════════════════════════════════

TASK 1 (EASY): Employee Struct and Print
   Define struct Employee { int id; char name[30]; double salary; }.
   Create one employee, set fields, print them.
   // STARTER CODE:
   // struct Employee { int id; char name[30]; double salary; };
   // Employee e; e.id = 1001; strcpy(e.name, "Aman"); e.salary = 50000;
   // cout << e.id << " " << e.name << " " << e.salary << endl;

TASK 2 (MEDIUM): Array of Structs — Print All
   Create an array of 3 employees and print all with a loop.
   // STARTER CODE:
   // Employee team[3] = {{1,"A",1000},{2,"B",2000},{3,"C",3000}};
   // for (int i = 0; i < 3; i++) { ... team[i].id ... }

TASK 3 (MEDIUM): Average Salary
   Write double avgSalary(Employee team[], int n) that sums salaries
   and divides by n. Print the average.
   // STARTER CODE:
   // double avgSalary(Employee team[], int n) {
   //     double sum = 0;
   //     for (int i = 0; i < n; i++) sum += team[i].salary;
   //     return sum / n;
   // }

TASK 4 (MEDIUM): Struct as Parameter — by value vs by pointer
   Write printByValue(Employee e) — copies the whole struct; and
   giveBonus(Employee* e, double bonus) — adds bonus to salary via
   pointer (arrow operator). Show that by-value does NOT change the
   original, by-pointer DOES.
   // STARTER CODE:
   // void printByValue(Employee e) { cout << e.name << endl; }
   // void giveBonus(Employee* e, double b) { e->salary += b; }

TASK 5 (HARD): Highest Salary Employee
   Given an array of employees, find the index of the employee with the
   highest salary (modify via pointer). Print who earns the most.
   // STARTER CODE:
   // int idx = 0;
   // for (int i = 1; i < n; i++)
   //     if (team[i].salary > team[idx].salary) idx = i;
   // cout << team[idx].name << " " << team[idx].salary << endl;

TASK 6 (HARD): Nested Struct + Sorting by Salary (Selection Sort)
   Add a Date (day, month, year) INSIDE Employee (joining date). Sort the
   employee array by salary ascending using selection sort (swap whole
   structs), then print all with dates.
   // STARTER CODE:
   // struct Date { int d, m, y; };      // nested pehle define
   // struct Employee { int id; char name[30]; double salary; Date join; };
   // for (i...) for (j=i+1...) if (team[j].salary < team[i].salary) swap(team[i], team[j]);

═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
#include <iostream>
#include <cstring>
using namespace std;

struct Date {
    int d, m, y;
};

struct Employee {
    int id;
    char name[30];
    double salary;
    Date join;           // nested struct
};

// by value — poori struct copy hoti hai, original unchanged
void printByValue(Employee e) {
    cout << "  [by value] copy: " << e.name << " salary=" << e.salary << endl;
    e.salary = 0;        // sirf copy badlegi
}

// by pointer — arrow operator se asli struct badal sakta hai
void giveBonus(Employee *e, double bonus) {
    e->salary += bonus;  // e->salary == (*e).salary
    e->join.d = 1;       // nested member via pointer: e->join.d
}

// average salary
double avgSalary(Employee team[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += team[i].salary;   // dot operator
    return sum / n;
}

// print helper
void printEmployee(Employee &e) {
    cout << "   " << e.id << "  " << e.name << "  salary=" << e.salary
         << "  joined=" << e.join.d << "/" << e.join.m << "/" << e.join.y << endl;
}

int main() {
    cout << "=== TASK 1: Employee Struct and Print ===" << endl;
    {
        Employee e;
        e.id = 1001;
        strcpy(e.name, "Aman");
        e.salary = 50000;
        e.join.d = 12; e.join.m = 5; e.join.y = 2021;
        printEmployee(e);
    }
    cout << endl;

    cout << "=== TASK 2 & 5 & 6 setup: Array of Structs ===" << endl;
    Employee team[4] = {
        {1, "Aman",   40000, {12, 5, 2021}},
        {2, "Priya",  75000, {3,  1, 2019}},
        {3, "Rahul",  55000, {20, 9, 2022}},
        {4, "Sita",   60000, {15, 6, 2020}}
    };
    cout << "   Team records:\n";
    for (int i = 0; i < 4; i++) printEmployee(team[i]);
    cout << endl;

    cout << "=== TASK 3: Average Salary ===" << endl;
    double avg = avgSalary(team, 4);
    cout << "   Average salary = " << avg << endl << endl;

    cout << "=== TASK 4: by value vs by pointer ===" << endl;
    cout << "   Calling printByValue(team[0]):" << endl;
    printByValue(team[0]);
    cout << "   After by-value call, team[0].salary = " << team[0].salary
         << " (UNCHANGED — copy tha)\n";
    cout << "   Calling giveBonus(&team[0], 5000):" << endl;
    giveBonus(&team[0], 5000);
    cout << "   After by-pointer call, team[0].salary = " << team[0].salary
         << " (CHANGED — arrow operator)\n" << endl;

    cout << "=== TASK 5: Highest Salary (via pointer) ===" << endl;
    int idx = 0;
    for (int i = 1; i < 4; i++) {
        if (team[i].salary > team[idx].salary) idx = i;   // pointer index
    }
    cout << "   Highest earner: " << team[idx].name
         << " with " << team[idx].salary << endl;
    // modify through pointer
    Employee *top = &team[idx];
    top->salary = 99999;
    cout << "   Via pointer top->salary = " << top->salary << "  (team updated too)\n" << endl;

    cout << "=== TASK 6: Selection Sort by Salary (ascending) ===" << endl;
    for (int i = 0; i < 4; i++) {
        int minIdx = i;
        for (int j = i + 1; j < 4; j++)
            if (team[j].salary < team[minIdx].salary) minIdx = j;
        Employee temp = team[i];
        team[i] = team[minIdx];
        team[minIdx] = temp;
    }
    cout << "   Sorted (salary ascending):\n";
    for (int i = 0; i < 4; i++) printEmployee(team[i]);

    cout << "\nAll structure tasks done." << endl;
    return 0;
}