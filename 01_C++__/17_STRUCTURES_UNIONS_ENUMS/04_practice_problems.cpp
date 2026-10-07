/*
TOPIC: Structures, Unions, and Enums
FILE: 04_practice_problems.cpp

Compile:
    g++ -std=c++17 -Wall -Wextra -Wshadow -pedantic 04_practice_problems.cpp -o practice

Run:
    ./practice
*/

#include <iostream>
#include <string>

using namespace std;


// ============================================================
// PROBLEM 1: POINT
// ============================================================

struct Point {
    int x;
    int y;
};


long long squaredDistanceFromOrigin(
    const Point& point
) {
    return (
        1LL * point.x * point.x
        +
        1LL * point.y * point.y
    );
}


// ============================================================
// PROBLEM 2: STUDENT
// ============================================================

struct Student {
    string name;
    int marks[3];
};


int totalMarks(
    const Student& student
) {
    int total = 0;

    for (int mark : student.marks) {
        total += mark;
    }

    return total;
}


// ============================================================
// PROBLEM 3: MIN/MAX RESULT STRUCT
// ============================================================

struct MinMax {
    int minimum;
    int maximum;
};


MinMax findMinMax(
    const int values[],
    int n
) {
    MinMax result{
        values[0],
        values[0]
    };

    for (int i = 1; i < n; ++i) {

        if (values[i] <
            result.minimum) {

            result.minimum =
                values[i];
        }

        if (values[i] >
            result.maximum) {

            result.maximum =
                values[i];
        }
    }

    return result;
}


// ============================================================
// PROBLEM 4: ENUM STATE
// ============================================================

enum class TrafficLight {
    Red,
    Yellow,
    Green
};


const char* describeLight(
    TrafficLight light
) {
    switch (light) {

        case TrafficLight::Red:
            return "Stop";

        case TrafficLight::Yellow:
            return "Prepare";

        case TrafficLight::Green:
            return "Go";
    }

    return "Unknown";
}


// ============================================================
// PROBLEM 5: NODE
// ============================================================

struct Node {
    int value;
    Node* next;
};


int main() {

    // ========================================================
    // TEST 1
    // ========================================================

    Point point{
        3,
        4
    };

    cout << "=== PROBLEM 1: Point ===\n";

    cout << "squared distance = "
         << squaredDistanceFromOrigin(
                point
            )
         << "\n\n";


    // ========================================================
    // TEST 2
    // ========================================================

    Student student{
        "Ada",
        {
            90,
            80,
            100
        }
    };

    cout << "=== PROBLEM 2: Student ===\n";

    cout << student.name
         << " total = "
         << totalMarks(student)
         << "\n\n";


    // ========================================================
    // TEST 3
    // ========================================================

    int values[5] = {
        7,
        2,
        9,
        -1,
        5
    };

    MinMax answer =
        findMinMax(
            values,
            5
        );

    cout << "=== PROBLEM 3: Return Struct ===\n";

    cout << "min = "
         << answer.minimum
         << '\n';

    cout << "max = "
         << answer.maximum
         << "\n\n";


    // ========================================================
    // TEST 4
    // ========================================================

    cout << "=== PROBLEM 4: Enum State ===\n";

    TrafficLight light =
        TrafficLight::Green;

    cout << describeLight(light)
         << "\n\n";


    // ========================================================
    // TEST 5
    // ========================================================

    cout << "=== PROBLEM 5: Nodes ===\n";

    Node* first =
        new Node{
            10,
            nullptr
        };

    Node* second =
        new Node{
            20,
            nullptr
        };

    first->next =
        second;

    cout << first->value
         << " -> "
         << second->value
         << '\n';

    // Disconnect before cleanup to keep our mental state clear.
    first->next = nullptr;

    delete second;
    delete first;

    second = nullptr;
    first = nullptr;

    return 0;
}


/*
EXPECTED OUTPUT

=== PROBLEM 1: Point ===
squared distance = 25

=== PROBLEM 2: Student ===
Ada total = 270

=== PROBLEM 3: Return Struct ===
min = -1
max = 9

=== PROBLEM 4: Enum State ===
Go

=== PROBLEM 5: Nodes ===
10 -> 20


PRACTICE LINKS

1. GFG Structures in C++
https://www.geeksforgeeks.org/structures-in-cpp/

2. GFG Unions
https://www.geeksforgeeks.org/cpp-unions/

3. GFG Enumeration
https://www.geeksforgeeks.org/enumeration-in-cpp/

4. LeetCode 707
https://leetcode.com/problems/design-linked-list/

5. LeetCode 206
https://leetcode.com/problems/reverse-linked-list/


WHAT'S NEXT:
01_C++__/18_OOP_CLASSES_AND_OBJECTS/
*/
