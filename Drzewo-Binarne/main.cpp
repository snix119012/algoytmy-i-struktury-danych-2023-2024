#include <iostream>
using namespace std;
template <typename T>
class Tree {
public:
    T data;
    Tree* left;
    Tree* right;
    Tree(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    Tree<T>* root;

    void destroy(Tree<T>* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    void addElement(Tree<T>*& node, T value) {
        if (node == nullptr) {
            node = new Tree<T>(value);
        } else {
            if (value < node->data) {
                addElement(node->left, value);
            } else {
                addElement(node->right, value);
            }
        }
    }

    void preorderTraversal(Tree<T>* node) {
        if (node != nullptr) {
            cout << node->data << " - ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void inorderTraversal(Tree<T>* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " - ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(Tree<T>* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " - ";
        }
    }

public:
    BinaryTree() : root(nullptr) {
        addElement(root, 10.11);
        addElement(root, 20.22);
        addElement(root, 90.11);
        addElement(root, 40.32);
        addElement(root, 50.00);
        addElement(root, 60.11);
    }

    ~BinaryTree() {
        destroy(root);
    }

    void preorderTraversal() {
        preorderTraversal(root);
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }

    void postorderTraversal() {
        postorderTraversal(root);
    }
};

int main() {
    BinaryTree<double> tree;
    cout << "\n Preorder: ";
    tree.preorderTraversal();
    cout << "\n Inorder: ";
    tree.inorderTraversal();
    cout << "\n Postorder: ";
    tree.postorderTraversal();
    return 0;
}
