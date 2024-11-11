#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Deque() {
        head = tail = nullptr;
    }

    void pushFront(T value) {
        Node<T>* temp = new Node<T>(value);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void pushBack(T value) {
        Node<T>* temp = new Node<T>(value);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    T popFront() {
        if (head == nullptr) {
            cout << "Deque is empty" << endl;
            return T();
        } else if (head == tail) {
            T value = head->data;
            delete head;
            head = tail = nullptr;
            return value;
        } else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            T value = temp->data;
            delete temp;
            return value;
        }
    }

    T popBack() {
        if (head == nullptr) {
            cout << "Deque is empty" << endl;
            return T();
        } else if (head == tail) {
            T value = head->data;
            delete head;
            head = tail = nullptr;
            return value;
        } else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            T value = temp->data;
            delete temp;
            return value;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Deque is empty" << endl;
        } else {
            Node<T>* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Deque<int> dq;
    dq.pushFront(10);
    dq.pushFront(20);
    dq.pushBack(30);
    dq.pushBack(40);

    dq.display();

    cout << dq.popFront() << endl;
    cout << dq.popBack() << endl;

    dq.display();
}
