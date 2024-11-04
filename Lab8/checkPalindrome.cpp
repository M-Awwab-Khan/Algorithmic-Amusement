#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

bool checkPalindrome(Node* list) {
    Node* slow = list;
    Node* fast = list;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* prev = nullptr;
    Node* curr = slow;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    Node* first = list;
    Node* second = prev;

    while (second) {
        if (first->data != second->data) {
            return false;
        }
        first = first->next;
        second = second->next;
    }

    return true;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << "Original list: ";
    printList(head);

    if (checkPalindrome(head)) {
        cout << "List is palindrome" << endl;
    } else {
        cout << "List is not palindrome" << endl;
    }

    return 0;
}
