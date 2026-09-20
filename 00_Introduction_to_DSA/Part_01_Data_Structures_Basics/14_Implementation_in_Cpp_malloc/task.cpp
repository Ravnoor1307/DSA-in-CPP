/*
═══════════════════════════════════════════════
 TASK SET — MALLOC vs NEW in C++
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: You are setting up a new game console. One way
   to get storage (malloc) leaves it raw and empty. Another way (new)
   automatically sets up the system folders. In C++, choosing the wrong
   one can crash your program. These tasks teach you to pick correctly!

 🧠 HOW TO SOLVE: malloc returns void* (cast needed) and NEVER calls
   constructors. new returns a typed pointer and DOES call constructors.
   Always match malloc→free and new→delete. For arrays: new[]→delete[].

 MODES/TOPICS COVERED:
  1. Allocate an int with BOTH malloc and new, print both
  2. Allocate an array of 5 ints with malloc, fill, print, free
  3. Allocate an array of 5 ints with new[], fill, print, delete[]
  4. Allocate a Node with malloc vs new — show constructor skip
  5. Write a helper that safely allocates a Node (new)
  6. Demonstrate the "garbage value" problem with malloc
  7. HARD: Show why mixing new/free breaks — build a small demo
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
// NOTE: Each task below is solved fully. Compile the whole file.
// Hinglish comments = code samjhao.

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
        cout << "  [Node constructor CAllED]" << endl;
    }

    ~Node() {
        cout << "  [Node destructor CAllED for data=" << data << "]" << endl;
    }
};

Node* safeCreateNode(int value) {
    Node* n = new Node;          // constructor chalega
    n->data = value;
    n->next = nullptr;
    return n;
}

int main() {
    cout << "==========================================" << endl;
    cout << " TASK SET — MALLOC vs NEW" << endl;
    cout << "==========================================" << endl;

    // ---- TASK 1: int via both ----
    cout << "\n--- TASK 1: int via malloc and new ---" << endl;
    int* mPtr = (int*)malloc(sizeof(int));
    *mPtr = 42;
    int* nPtr = new int;
    *nPtr = 99;
    cout << "malloc: " << *mPtr << " | new: " << *nPtr << endl;
    cout << "malloc ko cast karna pada, new ko nahi." << endl;
    free(mPtr);
    delete nPtr;

    // ---- TASK 2: malloc array of 5 ints ----
    cout << "\n--- TASK 2: int array of 5 via malloc ---" << endl;
    int* mArr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) mArr[i] = (i + 1) * 10;
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << mArr[i] << " ";
    cout << endl;
    free(mArr);
    cout << "Size manually diya: 5 * sizeof(int). Free se sirf bytes choti." << endl;

    // ---- TASK 3: new[] array of 5 ints ----
    cout << "\n--- TASK 3: int array of 5 via new[] ---" << endl;
    int* nArr = new int[5];
    for (int i = 0; i < 5; i++) nArr[i] = (i + 1) * 100;
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << nArr[i] << " ";
    cout << endl;
    delete[] nArr;
    cout << "IMPORTANT: new[] ka saathi sirf delete[] hai, delete nahi!" << endl;

    // ---- TASK 4: Node via malloc vs new ----
    cout << "\n--- TASK 4: Node via malloc vs new ---" << endl;
    cout << "malloc Node:" << endl;
    Node* mNode = (Node*)malloc(sizeof(Node));
    cout << "  Constructor NOT called. data= " << mNode->data
         << "(garbage/junk ho sakta hai)" << endl;
    mNode->data = 7;
    mNode->next = nullptr;
    free(mNode);
    cout << "new Node:" << endl;
    Node* nNode = new Node;
    nNode->data = 7;
    nNode->next = nullptr;
    delete nNode;

    // ---- TASK 5: Safe helper ----
    cout << "\n--- TASK 5: safeCreateNode helper ---" << endl;
    Node* a = safeCreateNode(10);
    Node* b = safeCreateNode(20);
    a->next = b;
    cout << "List: " << a->data << " -> " << a->next->data << endl;
    delete a;
    delete b;

    // ---- TASK 6: Garbage value demo ----
    cout << "\n--- TASK 6: Uninitialized malloc value ---" << endl;
    int* raw = (int*)malloc(sizeof(int));
    cout << "Uninitialized: " << *raw << " (predictable NAHI hai — GARBAGE)" << endl;
    *raw = 555;
    cout << "After assign: " << *raw << endl;
    free(raw);

    // ---- TASK 7: HARD — wrong pairing (concept demo) ----
    cout << "\n--- TASK 7: Why mixing breaks ---" << endl;
    cout << "Rule: malloc↔free, new↔delete, new[]↔delete[]." << endl;
    cout << "Mixing (e.g. new then free) = UNDEFINED BEHAVIOR, crashes possible." << endl;
    cout << "Kyunki wahan match nahi hota, destructor skip ho jaata hai aur memory graphs garbad ho sakti hai." << endl;

    cout << "\nAll tasks done! Correct pairing = safe code." << endl;
    return 0;
}