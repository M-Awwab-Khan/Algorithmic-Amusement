#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularQueue {
private:
    Node* head;
    Node* tail;
    int size;
    int capacity;

public:
    CircularQueue(int capacity) {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
        this->capacity = capacity;
    }

    void enqueue(int data) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
            return;
        }

        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;

        size--;
    }

    void print() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.print();

    queue.dequeue();
    queue.dequeue();
    queue.print();

    queue.enqueue(6);
    queue.enqueue(7);
    queue.print();

    return 0;
}
