#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class Awwab_Lab03 {
private:
    int capacity;
    T* stack;
    int top_index;

public:
    Awwab_Lab03(int n) : capacity(n), top_index(-1) {
        stack = new T[n];
    }

    ~Awwab_Lab03() {
        delete[] stack;
    }

    void push(T element) {
        if (top_index + 1 == capacity) {
            resize();
        }
        stack[++top_index] = element;
    }

    T pop() {
        if (top_index == -1) {
            throw runtime_error("Stack is empty");
        }
        return stack[top_index--];
    }

    T peek() const {
        if (top_index == -1) {
            throw runtime_error("Stack is empty");
        }
        return stack[top_index];
    }

    bool isEmpty() const {
        return top_index == -1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << std::endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top_index; i >= 0; --i) {
            std::cout << stack[i] << " ";
        }
        cout << endl;
    }

    int size() const {
        return top_index + 1;
    }

    void resize() {
        int newCapacity = capacity * 2;
        T* newStack = new T[newCapacity];
        for (int i = 0; i <= top_index; ++i) {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
        capacity = newCapacity;
    }

    bool operator==(const Awwab_Lab03 &other) {
        if (other.top_index != top_index)
            return false;
        for (int i = 0; i <= other.top_index; ++i) {
            if (this->stack[i] != other.stack[i]) {
                return false;
            }
        }
        return true;
    }

    bool equalText(string t1, string t2) {
        Awwab_Lab03<char> stack1(t1.size());
        Awwab_Lab03<char> stack2(t2.size());

        for ( char ch : t1) {
            if (ch != '#') {
                stack1.push(ch);
            }
            else {
                stack1.pop();
            }
        }

        for ( char ch : t2) {
            if (ch != '#') {
                stack2.push(ch);
            }
            else {
                stack2.pop();
            }
        }
        return (stack1 == stack2);
    }
};

int main() {
    try {
        string text1;
        cout << "Enter text 1: ";
        cin >> text1;

        string text2;
        cout << "Enter text 2: ";
        cin >> text2;


        Awwab_Lab03<char> stack(100);
        cout << "Are they equal? " << boolalpha << stack.equalText(text1, text2) << endl;

    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
