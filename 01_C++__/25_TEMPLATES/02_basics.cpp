/*
Topic: Templates
File: 02_basics.cpp

Purpose:
Practice basic function and class templates.

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: GENERIC MINIMUM ==========

template <typename T>
T minimum(const T& a, const T& b) {
    return b < a ? b : a;
}

// ========== SECTION 2: GENERIC SQUARE ==========

template <typename T>
T square(const T& value) {
    return value * value;
}

// ========== SECTION 3: GENERIC ARRAY PRINT ==========

template <typename T>
void printArray(const T values[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << values[i];

        if (i + 1 < size) {
            cout << ' ';
        }
    }

    cout << '\n';
}

// ========== SECTION 4: GENERIC PAIR CLASS ==========

template <typename First, typename Second>
class SimplePair {
private:
    First first;
    Second second;

public:
    SimplePair(
        const First& first,
        const Second& second
    )
        : first(first), second(second) {
    }

    const First& getFirst() const {
        return first;
    }

    const Second& getSecond() const {
        return second;
    }
};

// ========== SECTION 5: FIXED HOLDER ==========

template <typename T, int Count>
class Holder {
private:
    T values[Count] = {};

public:
    int size() const {
        return Count;
    }

    void set(int index, const T& value) {
        if (index >= 0 && index < Count) {
            values[index] = value;
        }
    }

    const T& get(int index) const {
        return values[index];
    }
};

int main() {
    cout << "=== BASIC 1: MINIMUM ===\n";

    cout << minimum(10, 3) << '\n';
    cout << minimum(7.5, 9.2) << '\n';

    cout << "\n=== BASIC 2: SQUARE ===\n";

    cout << "square(6) = "
         << square(6) << '\n';

    cout << "square(2.5) = "
         << square(2.5) << '\n';

    cout << "\n=== BASIC 3: GENERIC ARRAY ===\n";

    int numbers[] = {1, 2, 3, 4};
    string words[] = {"C++", "DSA", "Templates"};

    printArray(numbers, 4);
    printArray(words, 3);

    cout << "\n=== BASIC 4: GENERIC PAIR ===\n";

    SimplePair<string, int> student(
        "Asha",
        92
    );

    cout << student.getFirst()
         << " -> "
         << student.getSecond()
         << '\n';

    cout << "\n=== BASIC 5: NON-TYPE PARAMETER ===\n";

    Holder<int, 3> holder;

    holder.set(0, 10);
    holder.set(1, 20);
    holder.set(2, 30);

    cout << "Size = "
         << holder.size() << '\n';

    cout << holder.get(0) << ' '
         << holder.get(1) << ' '
         << holder.get(2) << '\n';

    cout << "\nNext: 26_EXCEPTION_HANDLING\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: MINIMUM ===
3
7.5

=== BASIC 2: SQUARE ===
square(6) = 36
square(2.5) = 6.25

=== BASIC 3: GENERIC ARRAY ===
1 2 3 4
C++ DSA Templates

=== BASIC 4: GENERIC PAIR ===
Asha -> 92

=== BASIC 5: NON-TYPE PARAMETER ===
Size = 3
10 20 30

Next: 26_EXCEPTION_HANDLING
*/
