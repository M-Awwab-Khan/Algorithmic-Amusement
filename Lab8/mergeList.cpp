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

Node* mergeList(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeList(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeList(l1, l2->next);
        return l2;
    }
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
    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(4);

    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Node* mergedList = mergeList(l1, l2);

    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
