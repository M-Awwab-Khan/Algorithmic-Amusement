#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void concatenate(DoublyLinkedList& other) {
        if (!other.head) return;

        if (!head) {
            head = other.head;
            tail = other.tail;
        } else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList L;
    DoublyLinkedList M;

    for (int i = 2; i <= 10; i += 2) {
        L.append(i);
    }

    for (int i = 1; i < 10; i += 2) {
        M.append(i);
    }

    cout << "List L (Even elements): ";
    L.display();
    cout << "List M (Odd elements): ";
    M.display();

    DoublyLinkedList N = L;
    N.concatenate(M);

    cout << "List N (Concatenation of L and M): ";
    N.display();

    return 0;
}
