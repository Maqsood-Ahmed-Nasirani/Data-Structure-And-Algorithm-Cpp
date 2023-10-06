#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val): data(val), left(nullptr), right(nullptr) {}
};

//insert in BST
node* insertBST(node* root, int val) {

    if(root == nullptr)
        return new node(val);

    if(val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

//search in BST
node* serachInBST(node* root, int key) {

    if(root == nullptr)
        return nullptr;

    if(root->data == key)
        return root;
    
    if(root->data > key) 
        return serachInBST(root->left, key);
    
    return serachInBST(root->right, key);
}

node* inorderSucc(node* root) {
    node* curr = root;
    while(curr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

//delete in BST
node* deleteInBST(node* root, int key) {

    if(root == nullptr)
        return nullptr;
    
    if(key < root->data) {
        root->left = deleteInBST(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteInBST(root->right, key);
    } 
    else {
        if(root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }

    return root;
}


//print BST
void inorderPrint(node* root) {
    if(root == nullptr)
        return;

    inorderPrint(root->left);
    cout << root->data << ' ';
    inorderPrint(root->right);
}

int main(void)
{
    node* root = nullptr;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    inorderPrint(root);
    cout << '\n';

    if(serachInBST(root, 5) == nullptr)
        cout << "Key doesn't exist\n";
    else    
        cout << "Key exists\n";


    root = deleteInBST(root, 5);
    inorderPrint(root);

    return 0;
}