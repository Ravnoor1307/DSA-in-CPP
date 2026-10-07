/*
Topic: Abstraction and Encapsulation
File: 03_variation.cpp

Purpose:
Explore:
- behavior-oriented interfaces
- avoiding unrestricted setters
- abstract interfaces
- composition
- changing hidden representation
- mutable representation exposure risks

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <iostream>
#include <string>

using namespace std;

// ========== SECTION 1: BEHAVIOR OVER RAW SETTERS ==========

class Wallet {
private:
    int money = 0;

public:
    bool addMoney(int amount) {
        if (amount <= 0) {
            return false;
        }

        money += amount;
        return true;
    }

    bool spend(int amount) {
        if (amount <= 0 || amount > money) {
            return false;
        }

        money -= amount;
        return true;
    }

    int moneyAvailable() const {
        return money;
    }
};

// ========== SECTION 2: HIDDEN REPRESENTATION ==========
//
// The public abstraction is "duration in total seconds".
// Internally we store minutes and seconds.

class Duration {
private:
    int minutes = 0;
    int seconds = 0;

public:
    explicit Duration(int totalSeconds) {
        if (totalSeconds > 0) {
            minutes = totalSeconds / 60;
            seconds = totalSeconds % 60;
        }
    }

    int totalSeconds() const {
        return minutes * 60 + seconds;
    }

    void display() const {
        cout << minutes
             << "m "
             << seconds
             << "s\n";
    }
};

// ========== SECTION 3: INTERFACE ABSTRACTION ==========

class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;

    virtual ~Switchable() = default;
};

class Lamp : public Switchable {
private:
    bool on = false;

public:
    void turnOn() override {
        on = true;
    }

    void turnOff() override {
        on = false;
    }

    bool isOn() const override {
        return on;
    }
};

void activate(Switchable& device) {
    device.turnOn();
}

// ========== SECTION 4: COMPOSITION ==========

class Logger {
public:
    void log(const string& message) const {
        cout << "[LOG] " << message << '\n';
    }
};

class Service {
private:
    Logger logger;

public:
    void run() const {
        logger.log("Service started");
        cout << "Service performing work\n";
    }
};

// ========== SECTION 5: CONTROLLED ARRAY ACCESS ==========

class Scores {
private:
    int values[3] = {0, 0, 0};

public:
    bool setScore(int index, int value) {
        if (index < 0 || index >= 3) {
            return false;
        }

        if (value < 0 || value > 100) {
            return false;
        }

        values[index] = value;
        return true;
    }

    bool getScore(int index, int& result) const {
        if (index < 0 || index >= 3) {
            return false;
        }

        result = values[index];
        return true;
    }

    int total() const {
        return values[0] + values[1] + values[2];
    }
};

int main() {
    cout << boolalpha;

    cout << "=== VARIATION 1: MEANINGFUL BEHAVIOR ===\n";

    Wallet wallet;

    wallet.addMoney(500);

    cout << "Spend 200: "
         << wallet.spend(200) << '\n';

    cout << "Spend 400: "
         << wallet.spend(400) << '\n';

    cout << "Money left = "
         << wallet.moneyAvailable() << '\n';

    cout << "\n=== VARIATION 2: HIDDEN REPRESENTATION ===\n";

    Duration duration(125);

    duration.display();

    cout << "Total seconds = "
         << duration.totalSeconds() << '\n';

    cout << "\n=== VARIATION 3: ABSTRACT INTERFACE ===\n";

    Lamp lamp;

    activate(lamp);

    cout << "Lamp on? "
         << lamp.isOn() << '\n';

    lamp.turnOff();

    cout << "Lamp on? "
         << lamp.isOn() << '\n';

    cout << "\n=== VARIATION 4: COMPOSITION ===\n";

    Service service;
    service.run();

    cout << "\n=== VARIATION 5: CONTROLLED ARRAY ACCESS ===\n";

    Scores scores;

    cout << "Set score[0] to 90: "
         << scores.setScore(0, 90) << '\n';

    cout << "Set score[1] to 80: "
         << scores.setScore(1, 80) << '\n';

    cout << "Set score[2] to 110: "
         << scores.setScore(2, 110) << '\n';

    cout << "Total = "
         << scores.total() << '\n';

    cout << "\nNext: 23_STATIC_CONST_FRIEND\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: MEANINGFUL BEHAVIOR ===
Spend 200: true
Spend 400: false
Money left = 300

=== VARIATION 2: HIDDEN REPRESENTATION ===
2m 5s
Total seconds = 125

=== VARIATION 3: ABSTRACT INTERFACE ===
Lamp on? true
Lamp on? false

=== VARIATION 4: COMPOSITION ===
[LOG] Service started
Service performing work

=== VARIATION 5: CONTROLLED ARRAY ACCESS ===
Set score[0] to 90: true
Set score[1] to 80: true
Set score[2] to 110: false
Total = 170

Next: 23_STATIC_CONST_FRIEND
*/
