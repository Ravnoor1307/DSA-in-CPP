#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    int pinCode;
};

struct Employee {
    string name;
    Address ad;      // nested struct — ek struct ke andar dusra struct
};


// ---------------- TASK 6: nested struct ----------------
void sol_task6() {
    Employee e;
    e.name = "Rohit";
    e.ad.city = "Indore";
    e.ad.pinCode = 452001;               // dot ke andar dot — nested access

    cout << "   " << e.name << " lives in " << e.ad.city
         << ", PIN " << e.ad.pinCode << "\n";
}


int main() {
    cout << "TASK 6:\n"; sol_task6();
    return 0;
}