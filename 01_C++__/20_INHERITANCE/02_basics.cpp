/*
Topic: Inheritance
File: 02_basics.cpp

Purpose:
Practice:
- public inheritance
- protected members
- base constructors
- inherited functions
- multilevel and hierarchical inheritance

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: EMPLOYEE BASE CLASS ==========

class Employee {
private:
    int employeeId;

protected:
    string name;

public:
    Employee(int employeeId, const string& name)
        : employeeId(employeeId), name(name) {
    }

    int getEmployeeId() const {
        return employeeId;
    }

    void showBasicInfo() const {
        cout << "Employee: "
             << name
             << ", id="
             << employeeId
             << '\n';
    }
};

// ========== SECTION 2: DERIVED CLASS ==========

class Developer : public Employee {
private:
    string language;

public:
    Developer(
        int employeeId,
        const string& name,
        const string& language
    )
        : Employee(employeeId, name),
          language(language) {
    }

    void showDeveloper() const {
        cout << name
             << " programs in "
             << language
             << ", id="
             << getEmployeeId()
             << '\n';
    }
};

// ========== SECTION 3: HIERARCHICAL INHERITANCE ==========

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(
        int employeeId,
        const string& name,
        int teamSize
    )
        : Employee(employeeId, name),
          teamSize(teamSize) {
    }

    void showManager() const {
        cout << name
             << " manages "
             << teamSize
             << " people\n";
    }
};

// ========== SECTION 4: MULTILEVEL INHERITANCE ==========

class SeniorDeveloper : public Developer {
private:
    int yearsOfExperience;

public:
    SeniorDeveloper(
        int employeeId,
        const string& name,
        const string& language,
        int years
    )
        : Developer(employeeId, name, language),
          yearsOfExperience(years) {
    }

    void showExperience() const {
        cout << name
             << " has "
             << yearsOfExperience
             << " years of experience\n";
    }
};

int main() {
    cout << "=== BASIC 1: DERIVED CLASS ===\n";

    Developer developer(101, "Asha", "C++");

    developer.showBasicInfo();
    developer.showDeveloper();

    cout << "\n=== BASIC 2: HIERARCHICAL INHERITANCE ===\n";

    Manager manager(201, "Ravi", 8);

    manager.showBasicInfo();
    manager.showManager();

    cout << "\n=== BASIC 3: MULTILEVEL INHERITANCE ===\n";

    SeniorDeveloper senior(
        301,
        "Mina",
        "C++",
        7
    );

    senior.showBasicInfo();
    senior.showDeveloper();
    senior.showExperience();

    cout << "\n=== BASIC 4: INHERITED PUBLIC FUNCTION ===\n";

    cout << "Senior employee ID = "
         << senior.getEmployeeId()
         << '\n';

    cout << "\nNext: 21_POLYMORPHISM\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: DERIVED CLASS ===
Employee: Asha, id=101
Asha programs in C++, id=101

=== BASIC 2: HIERARCHICAL INHERITANCE ===
Employee: Ravi, id=201
Ravi manages 8 people

=== BASIC 3: MULTILEVEL INHERITANCE ===
Employee: Mina, id=301
Mina programs in C++, id=301
Mina has 7 years of experience

=== BASIC 4: INHERITED PUBLIC FUNCTION ===
Senior employee ID = 301

Next: 21_POLYMORPHISM
*/
