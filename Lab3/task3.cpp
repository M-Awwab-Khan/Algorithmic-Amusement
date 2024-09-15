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

    string reverseString(string input) {
        Awwab_Lab03<char> temp(input.size());
        for (char ch: input) {
            temp.push(ch);
        }
        string reversed = "";
        while (!temp.isEmpty()) {
            reversed += temp.pop();
        }
        return reversed;
    }

    bool isPalindrome(string s) {
        return s == reverseString(s);
    }
};

int main() {
    try {
        string input;
        cout << "Enter string to check for palindrome: ";
        cin >> input;

        Awwab_Lab03<char> stack(input.size());
        cout << "Is your string palindrome? " << boolalpha << stack.isPalindrome(input) << endl;

    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
