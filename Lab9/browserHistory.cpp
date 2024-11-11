#include <iostream>
using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string value) : url(value), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;

    public:
    BrowserHistory(string homepage) : head(new Node(homepage)), tail(head) {}

    void visit(string url) {
        Node* newNode = new Node(url);

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    string back(int steps) {
        while (steps-- && tail->prev) {
            tail = tail->prev;
        }
        return tail->url;
    }

    string forward(int steps) {
        while (steps-- && tail->next) {
            tail = tail->next;
        }
        return tail->url;
    }
};

int main() {
    BrowserHistory history("https://leetcode.com");
    history.visit("https://google.com");
    history.visit("https://facebook.com");
    cout << history.back(1) << endl;
    cout << history.back(1) << endl;
    cout << history.forward(1) << endl;
    history.visit("https://youtube.com");
    cout << history.forward(2) << endl;
    cout << history.back(2) << endl;
    cout << history.back(7) << endl;
    return 0;
}
