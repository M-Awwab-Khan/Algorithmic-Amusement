#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* lca(Node* root, Node* n1, Node* n2) {
    if (n1->data < root->data && n2->data < root->data) {
        return lca(root->left, n1, n2);
    }

    if (n1->data > root->data && n2->data > root->data) {
        return lca(root->right, n1, n2);
    }

    return root;
};

int main() {
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    Node* p= new Node(0);
    root->left->left = p;
    root->right->right = new Node(9);
    root->left->right = new Node(4);
    root->right->left= new Node(7);

    root->left->right->left = new Node(3);
    Node* q = new Node(5);
    root->left->right->right = q;

    Node* lca_result = lca(root, p, q);
    cout << "LCA of 5 and 0 is: " << lca_result->data << endl;

}
