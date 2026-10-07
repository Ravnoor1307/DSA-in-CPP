/*
Topic: Exception Handling
File: 03_variation.cpp

Purpose:
Explore:
- custom exception types
- exception inheritance
- catch ordering
- rethrowing
- stack unwinding
- noexcept

Compile:
g++ -std=c++17 -Wall -Wextra -pedantic 03_variation.cpp -o variation

Run:
./variation
*/

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ========== SECTION 1: CUSTOM EXCEPTION HIERARCHY ==========

class AppError : public runtime_error {
public:
    explicit AppError(const string& message)
        : runtime_error(message) {
    }
};

class ValidationError : public AppError {
public:
    explicit ValidationError(const string& message)
        : AppError(message) {
    }
};

void validateScore(int score) {
    if (score < 0 || score > 100) {
        throw ValidationError(
            "score must be between 0 and 100"
        );
    }
}

// ========== SECTION 2: STACK UNWINDING ==========

class Guard {
private:
    string name;

public:
    explicit Guard(const string& name)
        : name(name) {
        cout << "Acquire "
             << name << '\n';
    }

    ~Guard() {
        cout << "Release "
             << name << '\n';
    }
};

void deepOperation() {
    Guard deep("deep-resource");

    throw AppError(
        "deep operation failed"
    );
}

void middleOperation() {
    Guard middle("middle-resource");

    deepOperation();
}

// ========== SECTION 3: LOG AND RETHROW ==========

void loggedOperation() {
    try {
        validateScore(150);
    }
    catch (const ValidationError& error) {
        cout << "Logger saw: "
             << error.what() << '\n';

        throw;
    }
}

// ========== SECTION 4: noexcept ==========

int absoluteValue(int value) noexcept {
    return value < 0 ? -value : value;
}

int main() {
    cout << "=== VARIATION 1: SPECIFIC BEFORE GENERAL ===\n";

    try {
        validateScore(200);
    }
    catch (const ValidationError& error) {
        cout << "ValidationError: "
             << error.what() << '\n';
    }
    catch (const AppError& error) {
        cout << "AppError: "
             << error.what() << '\n';
    }
    catch (const exception& error) {
        cout << "std::exception: "
             << error.what() << '\n';
    }

    cout << "\n=== VARIATION 2: STACK UNWINDING ===\n";

    try {
        middleOperation();
    }
    catch (const AppError& error) {
        cout << "Caught after unwinding: "
             << error.what() << '\n';
    }

    cout << "\n=== VARIATION 3: RETHROW ===\n";

    try {
        loggedOperation();
    }
    catch (const AppError& error) {
        cout << "Final handler: "
             << error.what() << '\n';
    }

    cout << "\n=== VARIATION 4: noexcept ===\n";

    cout << "absoluteValue(-12) = "
         << absoluteValue(-12) << '\n';

    cout << boolalpha;

    cout << "Function call is noexcept? "
         << noexcept(absoluteValue(-12))
         << '\n';

    cout << "\n=== VARIATION 5: CATCH-ALL ===\n";

    try {
        throw string("non-standard exception object");
    }
    catch (const exception& error) {
        cout << "Standard exception: "
             << error.what() << '\n';
    }
    catch (...) {
        cout << "Catch-all handled the exception\n";
    }

    cout << "\nNext: 27_NAMESPACES_AND_HEADER_FILES\n";

    return 0;
}

/*
Expected output:

=== VARIATION 1: SPECIFIC BEFORE GENERAL ===
ValidationError: score must be between 0 and 100

=== VARIATION 2: STACK UNWINDING ===
Acquire middle-resource
Acquire deep-resource
Release deep-resource
Release middle-resource
Caught after unwinding: deep operation failed

=== VARIATION 3: RETHROW ===
Logger saw: score must be between 0 and 100
Final handler: score must be between 0 and 100

=== VARIATION 4: noexcept ===
absoluteValue(-12) = 12
Function call is noexcept? true

=== VARIATION 5: CATCH-ALL ===
Catch-all handled the exception

Next: 27_NAMESPACES_AND_HEADER_FILES
*/
