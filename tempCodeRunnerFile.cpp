#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Function to create a new Node
Node* NewNode(int data) {
    Node* node = new Node(data);
    return node;
}

//Function to create tree
Node* insert(Node* node, int data) {
    if(node == NULL) {
        return NewNode(data);
    }
    if(data < node->data) {
        node->left = insert(node->left, data); 
    }
    else if(data > node->data) {
        node->right = insert(node->right, data); 
    }
    return node;
}

// Function to perform preorder traversal
void preOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Function to perform inorder traversal
void inOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

// Function to perform postorder traversal
void postOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = NULL;
    int data;
    cout << "Enter the elements of the tree (enter -1 to stop): ";
    while(true) {
        cin >> data;
        if(data == -1) {
            break;
        }
        root = insert(root, data);
    }

    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << "\n";

    return 0;
}