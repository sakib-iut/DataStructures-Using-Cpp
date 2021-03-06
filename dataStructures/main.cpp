#include<iostream>
/***
 * Binary Search Tree (BST)
 * A binary tree in which for each node, value of all the nodes
 * in left subtree is lesser or equal and value of all the nodes
 * in right subtree is greater
 */
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int data);

Node *getNewNode(int data);

bool search(Node *root, int i);

int findMin(Node *root);

int findMax(Node *root);

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 2);
    cout << search(root, 3) << endl;
    cout << findMin(root) << endl;
    cout << findMax(root) << endl;
    return 0;
}

int findMax(Node *root) {
    if (root == NULL) return -1;
    if (root->right == NULL)return root->data;
    return findMax(root->right);
}

int findMin(Node *root) {
    if (root == NULL) return -1;
    if (root->left == NULL)return root->data;
    return findMin(root->left);
}

bool search(Node *root, int data) {
    if (root == NULL)return false;
    if (root->data == data) return true;
    if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);

}

Node *insert(Node *root, int data) {
    Node *node = getNewNode(data);
    if (root == NULL) {
        return node;
    }
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;


}

Node *getNewNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
