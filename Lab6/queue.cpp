#include <iostream>
using namespace std;

template <typename T>

class Queue{
private:
  T* data;
  int capacity;
  int head;
  int tail;
  int size;
public:
  Queue(int capacity) {
    this->capacity = capacity;
    data = new T[capacity];
    head = 0;
    tail = 0;
    size = 0;
  }

  void enqueue(T value) {
    if (size == capacity) {
      cout << "Queue is full" << endl;
      return;
    }
    data[tail] = value;
    tail++;
    size++;
  }

  T dequeue() {
    if (size == 0) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int value = data[head];
    head++;
    return value;
  }

  void print() {
    for (int i = head; i < tail; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Queue<int> q(5);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.print();
  q.enqueue(6);
  q.dequeue();
  q.dequeue();
  q.print();
  return 0;
}
