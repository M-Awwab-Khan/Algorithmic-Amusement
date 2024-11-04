// implement stack using linked list
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        this->top = nullptr;
        this->size = 0;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek() {
        if (size == 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    stack.pop();
    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    stack.pop();
    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    stack.pop();
    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    return 0;
}
