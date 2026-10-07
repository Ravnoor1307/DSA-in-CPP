/*
Topic: Abstraction and Encapsulation
File: 02_basics.cpp

Purpose:
Practice:
- private state
- class invariants
- meaningful public operations
- const queries
- implementation hiding

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 02_basics.cpp -o basics

Run:
./basics
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: TEMPERATURE ==========

class Temperature {
private:
    double celsius = 0.0;

public:
    bool setCelsius(double value) {
        if (value < -273.15) {
            return false;
        }

        celsius = value;
        return true;
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32.0;
    }
};

// ========== SECTION 2: COUNTER ==========

class Counter {
private:
    int value = 0;

public:
    void increment() {
        ++value;
    }

    bool decrement() {
        if (value == 0) {
            return false;
        }

        --value;
        return true;
    }

    int getValue() const {
        return value;
    }
};

// ========== SECTION 3: INVENTORY ITEM ==========

class InventoryItem {
private:
    string name;
    int quantity;

public:
    InventoryItem(
        const string& name,
        int quantity
    )
        : name(name),
          quantity(quantity >= 0 ? quantity : 0) {
    }

    bool addStock(int amount) {
        if (amount <= 0) {
            return false;
        }

        quantity += amount;
        return true;
    }

    bool sell(int amount) {
        if (amount <= 0 || amount > quantity) {
            return false;
        }

        quantity -= amount;
        return true;
    }

    void display() const {
        cout << name
             << ": "
             << quantity
             << " units\n";
    }
};

// ========== SECTION 4: RANGE ==========

class Range {
private:
    int low;
    int high;

public:
    Range(int first, int second)
        : low(first <= second ? first : second),
          high(first <= second ? second : first) {
    }

    bool contains(int value) const {
        return value >= low && value <= high;
    }

    int length() const {
        return high - low;
    }
};

int main() {
    cout << boolalpha;

    cout << "=== BASIC 1: TEMPERATURE ===\n";

    Temperature temperature;

    cout << "Set 25 C: "
         << temperature.setCelsius(25) << '\n';

    cout << "Celsius = "
         << temperature.getCelsius() << '\n';

    cout << "Fahrenheit = "
         << temperature.getFahrenheit() << '\n';

    cout << "Set -500 C: "
         << temperature.setCelsius(-500) << '\n';

    cout << "\n=== BASIC 2: COUNTER ===\n";

    Counter counter;

    cout << "Decrement zero: "
         << counter.decrement() << '\n';

    counter.increment();
    counter.increment();

    cout << "Value = "
         << counter.getValue() << '\n';

    cout << "\n=== BASIC 3: INVENTORY ===\n";

    InventoryItem item("Keyboard", 10);

    item.addStock(5);

    cout << "Sell 4: "
         << item.sell(4) << '\n';

    cout << "Sell 100: "
         << item.sell(100) << '\n';

    item.display();

    cout << "\n=== BASIC 4: RANGE ABSTRACTION ===\n";

    Range range(10, 20);

    cout << "Contains 15? "
         << range.contains(15) << '\n';

    cout << "Contains 25? "
         << range.contains(25) << '\n';

    cout << "Range length = "
         << range.length() << '\n';

    cout << "\nNext: 23_STATIC_CONST_FRIEND\n";

    return 0;
}

/*
Expected output:

=== BASIC 1: TEMPERATURE ===
Set 25 C: true
Celsius = 25
Fahrenheit = 77
Set -500 C: false

=== BASIC 2: COUNTER ===
Decrement zero: false
Value = 2

=== BASIC 3: INVENTORY ===
Sell 4: true
Sell 100: false
Keyboard: 11 units

=== BASIC 4: RANGE ABSTRACTION ===
Contains 15? true
Contains 25? false
Range length = 10

Next: 23_STATIC_CONST_FRIEND
*/
