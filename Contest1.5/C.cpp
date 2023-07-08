#include <iostream>

class Node {
public:
    Node() : data_(0), left_(nullptr), right_(nullptr) {
    }
    Node(int data) : data_(data), left_(nullptr), right_(nullptr) {
    }
    int data_;
    Node *left_;
    Node *right_;
};

class Tree {
public:
    Tree() : root_(nullptr) {
    }
    Tree(int data) {
        root_ = new Node(data);
    }
    ~Tree() {
        clearMemory(root_);
    }
    void clearMemory(Node *node) {
        if (node) {
            clearMemory(node->right_);
            clearMemory(node->left_);
            delete node;
        }
    }
    void insert(int value) {
        Node **current = &root_;
        while (*current) {
            Node &node = **current;
            if (value < node.data_) {
                current = &node.left_;
            } else if (value > node.data_) {
                current = &node.right_;
            } else {
                return;
            }
        }
        *current = new Node(value);
    }
    void detour() {
        temp(root_);
    }

    void temp(Node *node) {
        if (node == nullptr) {
            return;
        }
        temp(node->left_);
        std::cout << node->data_ << "\n";
        temp(node->right_);
    }
    size_t getHeight() {
        return getHeight(root_);
    }

    size_t getHeight(Node *root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(getHeight(root->left_), getHeight(root->right_)) + 1;
    }

private:
    Node *root_;
};

int main() {
    int temp;
    Tree tree;
    std::cin >> temp;
    while (temp != 0) {
        tree.insert(temp);
        std::cin >> temp;
    }
    tree.detour();
}