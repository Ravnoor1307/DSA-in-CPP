/*
┌────────────────────────────────────────────────────────────┐
│ FILE: 03_custom_comparator_pq.cpp
│
│ REAL-WORLD SCENARIO:
│ Hospital patients objects hain: name, severity, arrival time. Higher severity first; severity same ho to earlier arrival first. Custom comparator ye priority rule define karta hai.
│
│ VISUAL / DRY RUN:
│ Patient object:
│ {name, severity, arrival}
│
│ Priority rules:
│ 1. Higher severity first.
│ 2. If severity same, smaller arrival number first.
│
│ Patients:
│ A severity5 arrival1
│ B severity9 arrival2
│ C severity9 arrival3
│ D severity4 arrival4
│
│ Pop order:
│ B (severity9 earlier)
│ C (severity9 later)
│ A
│ D

│
│ COMPLEXITY CALCULATION:
│ priority_queue comparator is used during heap push/pop.
│ push: O(log n) comparisons.
│ pop: O(log n) comparisons.
│ top: O(1).
│ Comparator itself checks at most two fields -> O(1).
│ Space = O(n) for stored objects.

└────────────────────────────────────────────────────────────┘
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <iomanip>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrival;
};

struct PatientCompare {
    bool operator()(const Patient& a, const Patient& b) const {
        if (a.severity != b.severity) return a.severity < b.severity; // Higher severity top.
        return a.arrival > b.arrival; // Same severity: earlier arrival top.
    }
};

int main() {
    priority_queue<Patient, vector<Patient>, PatientCompare> pq;
    pq.push({"Asha", 5, 1});
    pq.push({"Bharat", 9, 2});
    pq.push({"Charu", 9, 3});
    pq.push({"Deep", 4, 4});

    cout << "Treatment order:\n";
    while (!pq.empty()) {
        Patient p = pq.top(); pq.pop();
        cout << p.name << " severity=" << p.severity << " arrival=" << p.arrival << "\n";
    }
    return 0;
}

/*
OUTPUT:
Treatment order:
Bharat severity=9 arrival=2
Charu severity=9 arrival=3
Asha severity=5 arrival=1
Deep severity=4 arrival=4
*/

