#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};
// Awwab Lab 11
class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->value) node->left = insert(node->left, val);
        else if (val > node->value) node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->value == val) return true;
        if (val < node->value) return search(node->left, val);
        else return search(node->right, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void inOrderTraversal(Node* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }

    void preOrderTraversal(Node* node) {
        if (!node) return;
        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void preOrderTraversal() {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal(Node* node) {
        if (!node) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }

    void postOrderTraversal() {
        postOrderTraversal(root);
        cout << endl;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* remove(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->value) node->left = remove(node->left, val);
        else if (val > node->value) node->right = remove(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    void remove(int val) {
        root = remove(root, val);
    }
};

int main() {
    //test preroder and post order traversals
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    cout << "Pre-order Traversal: "; tree.preOrderTraversal(); cout << endl;
    cout << "Post-order Traversal: "; tree.postOrderTraversal(); cout << endl;

}
