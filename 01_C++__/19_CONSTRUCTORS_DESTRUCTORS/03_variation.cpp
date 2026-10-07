/*
Topic: Constructors and Destructors
File: 03_variation.cpp

Purpose:
Explore:
- declaration-order initialization
- reference members
- arrays of objects
- dynamic object arrays
- copy construction
- construction versus assignment

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: INITIALIZATION ORDER ==========

class OrderDemo {
private:
    int first;
    int second;

public:
    OrderDemo()
        : first(10),
          second(first + 5) {
    }

    void show() const {
        cout << "first = " << first
             << ", second = " << second << '\n';
    }
};

// ========== SECTION 2: REFERENCE MEMBER ==========

class RefHolder {
private:
    int& value;

public:
    RefHolder(int& value)
        : value(value) {
    }

    void add(int amount) {
        value += amount;
    }
};

// ========== SECTION 3: ARRAY LIFETIME ==========

class Item {
private:
    int id = 0;

public:
    Item() {
        cout << "Item default constructor\n";
    }

    void setId(int value) {
        id = value;
    }

    int getId() const {
        return id;
    }

    ~Item() {
        cout << "Item destructor for id " << id << '\n';
    }
};

// ========== SECTION 4: COPY CONSTRUCTION ==========

class Value {
private:
    int number;

public:
    Value()
        : number(0) {
        cout << "Value default constructed\n";
    }

    Value(int number)
        : number(number) {
        cout << "Value constructed with " << number << '\n';
    }

    Value(const Value& other)
        : number(other.number) {
        cout << "Value copy constructed\n";
    }

    void set(int value) {
        number = value;
    }

    int get() const {
        return number;
    }
};

int main() {
    cout << "=== VARIATION 1: INITIALIZATION ORDER ===\n";

    OrderDemo order;
    order.show();

    cout << "\n=== VARIATION 2: REFERENCE MEMBER ===\n";

    int external = 20;

    RefHolder holder(external);
    holder.add(5);

    cout << "External value = " << external << '\n';

    cout << "\n=== VARIATION 3: ARRAY OF OBJECTS ===\n";

    {
        Item items[3];

        items[0].setId(1);
        items[1].setId(2);
        items[2].setId(3);

        cout << "Array is ready\n";
    }

    cout << "\n=== VARIATION 4: DYNAMIC ARRAY ===\n";

    Item* dynamicItems = new Item[2];

    dynamicItems[0].setId(10);
    dynamicItems[1].setId(20);

    cout << "Deleting array\n";

    delete[] dynamicItems;
    dynamicItems = nullptr;

    cout << "\n=== VARIATION 5: COPY CONSTRUCTION ===\n";

    Value original(50);

    // A new object is initialized from original.
    Value copy = original;

    copy.set(80);

    cout << "Original = " << original.get() << '\n';
    cout << "Copy = " << copy.get() << '\n';

    cout << "\n=== VARIATION 6: CONSTRUCTION VS ASSIGNMENT ===\n";

    Value source(7);

    // Construction:
    Value constructed = source;

    // Default construction happens first.
    Value assigned;

    // Then compiler-generated copy assignment modifies
    // an already-existing object.
    assigned = source;

    cout << "Constructed value = "
         << constructed.get() << '\n';

    cout << "Assigned value = "
         << assigned.get() << '\n';

    cout << "\nNext: 20_INHERITANCE\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: INITIALIZATION ORDER ===
first = 10, second = 15

=== VARIATION 2: REFERENCE MEMBER ===
External value = 25

=== VARIATION 3: ARRAY OF OBJECTS ===
Item default constructor
Item default constructor
Item default constructor
Array is ready
Item destructor for id 3
Item destructor for id 2
Item destructor for id 1

=== VARIATION 4: DYNAMIC ARRAY ===
Item default constructor
Item default constructor
Deleting array
Item destructor for id 20
Item destructor for id 10

=== VARIATION 5: COPY CONSTRUCTION ===
Value constructed with 50
Value copy constructed
Original = 50
Copy = 80

=== VARIATION 6: CONSTRUCTION VS ASSIGNMENT ===
Value constructed with 7
Value copy constructed
Value default constructed
Constructed value = 7
Assigned value = 7

Next: 20_INHERITANCE
*/
