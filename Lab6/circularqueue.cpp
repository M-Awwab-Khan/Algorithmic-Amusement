#include <iostream>
using namespace std;

template <typename T>

class CircularQueue{
private:
  T* data;
  int capacity;
  int head;
  int tail;
  int size;
public:
CircularQueue(int capacity) {
  this->capacity = capacity;
  data = new T[capacity];
  head = 0;
  tail = 0;
  size = 0;
}

void enqueue(T value) {
  if (isFull()) {
    cout << "Queue is full" << endl;
    return;
  }
  data[tail] = value;
  tail = (tail + 1) % capacity;
  size++;
}

int dequeue() {
  if (size == 0) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  int value = data[head];
  head = (head + 1) % capacity;
  size--;
  return value;
}

T front() {
  if (size == 0) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  return data[head];
}

T rear() {
  if (size == 0) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  return data[(tail - 1 + capacity) % capacity];
}

bool isFull() {
  return size == capacity;
}

int length() {
  return size;
}

void display() {
  for (int i = 0; i < size; i++) {
    cout << data[(head + i) % capacity] << " ";
  }
  cout << endl;
}
};

int main() {
  CircularQueue<int> q(5);
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.display();
  q.enqueue(60);
  q.dequeue();
  q.dequeue();
  q.display();
  return 0;
}
