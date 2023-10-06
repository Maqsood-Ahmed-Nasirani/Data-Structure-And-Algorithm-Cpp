#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left, *right;
    node(int val): data(val), left(nullptr), right(nullptr) {} 
};

void flatten(node* root) {
    
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    if(root->left != nullptr) {
        flatten(root->left);

        node* temp = root->right;
        root->right = root->left; 
        root->left = nullptr;

        node* t = root->right;
        while(t->right != nullptr) {
            t = t->right;
        }

        t->right = temp;
    
    }

    flatten(root->right);
}

void inorderPrint(node* root) {
    if(root == nullptr)
        return;

    inorderPrint(root->left);
    cout << root->data << ' ';
    inorderPrint(root->right);
}

int main(void) {

    node* root = new node(4);
    root->left = new node(9);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    flatten(root);
    inorderPrint(root);
    
    return 0;
}