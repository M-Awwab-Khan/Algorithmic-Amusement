#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->value == val) return true;
        return search(node->left, val) || search(node->right, val);
    }

    void preOrderTraversal(Node* node) {
        if (!node) return;
        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node) {
        if (!node) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }

    bool isSymmetric(Node* left, Node* right) {
        if (!left && !right) return true;
        if (!left || !right || left->value != right->value) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isMirror() {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(2);
    tree.root->left->left = new Node(3);
    tree.root->left->right = new Node(4);
    tree.root->right->left = new Node(4);
    tree.root->right->right = new Node(3);
    cout << boolalpha;
    cout << "Search for 3: " << tree.search(tree.root, 3) << endl;
    cout << "Pre-order Traversal: "; tree.preOrderTraversal(tree.root); cout << endl;
    cout << "Post-order Traversal: "; tree.postOrderTraversal(tree.root); cout << endl;
    cout << "Is the tree symmetric? " << tree.isMirror() << endl;

    return 0;
}
