#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularQueue {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    CircularQueue() {
        head = tail = nullptr;
    }

    void enqueue(T value) {
        Node<T>* temp = new Node<T>(value);
        if (head == nullptr) {
            head = tail = temp;
            tail->next = head;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
        } else if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            Node<T>* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
};

int main() {
    CircularQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.enqueue(40);
    queue.display();

    return 0;
}
