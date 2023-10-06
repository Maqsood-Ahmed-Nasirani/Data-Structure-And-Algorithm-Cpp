#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};

//check for binary search tree
bool isBST(node* root, node* min, node* max) {

    if(root == nullptr)
        return true;

    if(min != nullptr && root->data <= min->data)
        return false;

    if(max != nullptr && root->data <= max->data)
        return false;

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);    

    return leftValid && rightValid;

    
}

int main(void) {

    ios_base:: sync_with_stdio(false);

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    cout << (isBST(root, nullptr, nullptr) ? "Valid BST\n" : "Invalid BST\n");

    return 0;
}