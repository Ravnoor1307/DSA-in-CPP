/*
═══════════════════════════════════════════════
 TASK SET — CREATING A NODE (SINGLY LINKED LIST)
═══════════════════════════════════════════════
 🌍 REAL-WORLD SCENARIO: You are building a playlist app where each song
   is a node — it stores the song name and points to the next song.
   Building nodes correctly is the foundation of every linked-list
   feature you will ever write (insert, delete, search).

 🧠 HOW TO SOLVE: Always draw the picture first. Write the struct, then
   a createNode() helper, then link next pointers. Traverse from head
   using a temp pointer until NULL. Never forget to delete nodes.

 MODES/TOPICS COVERED:
  1. Create ONE node and print its data + next
  2. Link THREE nodes by hand (no function)
  3. Count length of a list (traverse)
  4. Insert a new node at the FRONT
  5. Insert a new node at the END
  6. Search for a value in the list
  7. HARD: Delete a node by value
  8. HARD: Reverse the linked list
═══════════════════════════════════════════════
*/
// ---------------- SOLUTIONS ----------------
// NOTE: Each task below is solved fully. Compile the whole file to see all answers.
// Hinglish comments = code samjhao.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* insertAtFront(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;   // naya node purane head ko point kare
    return newNode;         // naya node ab head bana
}

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) return newNode;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;  // last node tak pahuncho
    }
    temp->next = newNode;   // last node ke baad jodo
    return head;
}

bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

Node* deleteNode(Node* head, int key) {
    if (head == nullptr) return head;
    if (head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;   // agla node bachao
        curr->next = prev;             // pointer ulta karo
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    cout << "==========================================" << endl;
    cout << " TASK SET — SINGLY LINKED LIST NODE" << endl;
    cout << "==========================================" << endl;

    // ---- TASK 1: Single node ----
    cout << "\n--- TASK 1: Single node create + print ---" << endl;
    Node* single = createNode(50);
    cout << "Data = " << single->data << ", Next = " << single->next << endl;
    delete single;
    cout << "Explanation: new Node ne memory di, data=50 set kiya, next=NULL." << endl;

    // ---- TASK 2: Link 3 nodes by hand ----
    cout << "\n--- TASK 2: Link three nodes ---" << endl;
    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;
    n1->data = 1; n2->data = 2; n3->data = 3;
    n1->next = n2; n2->next = n3; n3->next = nullptr;
    cout << "List: ";
    printList(n1);
    cout << "Explanation: har node ka next pointer agle node ko point karta hai." << endl;
    deleteList(n1);

    // ---- TASK 3: Length ----
    cout << "\n--- TASK 3: Count length ---" << endl;
    Node* head3 = createNode(10);
    head3 = insertAtEnd(head3, 20);
    head3 = insertAtEnd(head3, 30);
    head3 = insertAtEnd(head3, 40);
    printList(head3);
    cout << "Length = " << length(head3) << endl;
    cout << "Explanation: har node pe count++ karo jab tak NULL nahi milta." << endl;

    // ---- TASK 4: Insert at front ----
    cout << "\n--- TASK 4: Insert at front ---" << endl;
    Node* head4 = insertAtFront(head3, 5);
    printList(head4);
    cout << "Explanation: naya node head ke aage aaya, ab wo naya head hai." << endl;

    // ---- TASK 5: Insert at end ----
    cout << "\n--- TASK 5: Insert at end ---" << endl;
    head4 = insertAtEnd(head4, 100);
    printList(head4);
    cout << "Explanation: last node MILne par uske next me naya node joda." << endl;

    // ---- TASK 6: Search ----
    cout << "\n--- TASK 6: Search value ---" << endl;
    cout << "Search 30: " << (search(head4, 30) ? "FOUND" : "NOT FOUND") << endl;
    cout << "Search 999: " << (search(head4, 999) ? "FOUND" : "NOT FOUND") << endl;
    cout << "Explanation: har node se key compare karo, mil gaya to true." << endl;

    // ---- TASK 7: Delete by value ----
    cout << "\n--- TASK 7: Delete node with value 20 ---" << endl;
    head4 = deleteNode(head4, 20);
    printList(head4);
    cout << "Explanation: pehle wale node ka next badal kar wala node skip + delete." << endl;

    // ---- TASK 8: Reverse ----
    cout << "\n--- TASK 8: Reverse list ---" << endl;
    head4 = reverse(head4);
    printList(head4);
    cout << "Explanation: har node ka next pointer pichhle node pe point karo." << endl;

    deleteList(head4);
    cout << "\nAll tasks done! Memory cleaned." << endl;
    return 0;
}