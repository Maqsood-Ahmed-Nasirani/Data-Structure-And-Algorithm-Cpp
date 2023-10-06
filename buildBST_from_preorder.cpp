#include <iostream>
#include <climits>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val): data(val), left(nullptr), right(nullptr) {}
};


node* constructBST(int preorder[], int* preorderIdx, int key, int min, int max, int n) {

    if(*preorderIdx >= n)
        return nullptr;

    node* root = nullptr;

    if(key > min && key < max) {
        root = new node(key);
        *preorderIdx += 1;

        if(*preorderIdx < n) {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if(*preorderIdx < n) {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
 
    }

    return root;
}

//print BST
void preorderPrint(node* root) {
    if(root == nullptr)
        return;

    cout << root->data << ' ';
    preorderPrint(root->left);
    preorderPrint(root->right);
}


int main(void)
{
    int preorder[] = {10, 2, 1, 13, 11};
    int preorderIdx = 0;

    node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, 5);

    preorderPrint(root);

    return 0;
}