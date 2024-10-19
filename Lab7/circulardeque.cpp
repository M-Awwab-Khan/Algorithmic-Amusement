#include <iostream>
using namespace std;

class MyCircularDeque {
    int *arr;
    int front, rear, size, capacity;
public:
    MyCircularDeque(int k) {
        capacity = k;
        arr = new int[k];
        front = 0;
        rear = -1;
        size = 0;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        size++;
    }

    void insertLast(int value) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void deleteLast() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    MyCircularDeque myCircularDeque(3);
    myCircularDeque.insertLast(1);
    myCircularDeque.insertLast(2);
    myCircularDeque.insertFront(3);
    myCircularDeque.insertFront(4); // the queue is full.
    cout << "Rear: " << myCircularDeque.getRear() << endl; // return 2
    cout << "Is the deck full: " << boolalpha << myCircularDeque.isFull() << endl; // return True
    myCircularDeque.deleteLast();
    myCircularDeque.insertFront(4);
    myCircularDeque.display();
    return 0;
}
