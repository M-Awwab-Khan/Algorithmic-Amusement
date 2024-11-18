#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

int findSum(Node* root) {
    if (!root) return 0;
    return root->data + findSum(root->left) + findSum(root->right);
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->right->right = new Node(9);
    root->left->right = new Node(4);
    root->right->left= new Node(7);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    cout << "Sum of this BST is: " << findSum(root) << endl;
}
