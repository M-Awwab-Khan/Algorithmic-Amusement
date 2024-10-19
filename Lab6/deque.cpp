#include <iostream>
using namespace std;

class Deque {
    int front, rear, size, capacity;
    int *arr;
    
public:
    
    Deque(int n) {
        front = 0;
        rear = 0;
        size = 0;
        capacity = n;
        arr = new int[capacity];
    }

    void insertFront(int x) {
        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        size++;
    }

    void insertRear(int x) {
        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % capacity;
        size++;
    }

    void deleteFront() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void deleteRear() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (size == 0) {
            cout << "Deque is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);
    dq.insertFront(1);
    dq.insertFront(2);
    dq.insertRear(3);
    dq.insertRear(4);
    dq.display();
    dq.deleteFront();
    dq.deleteRear();
 
    dq.display();
    cout << "Size: " << dq.getSize() << endl;
    cout << "Is empty: " << boolalpha << dq.isEmpty() << endl;
    return 0;
}
