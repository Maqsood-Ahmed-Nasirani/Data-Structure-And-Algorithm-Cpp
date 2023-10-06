#include <iostream>
using namespace std;


class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int search(int inorder[], int s, int e, int val) {
    for (int i = s; i <= e; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

node* buildTree(int postorder[], int inorder[], int s, int e) {
    static int idx = 4;

    if(s > e)
        return nullptr;

   int val = postorder[idx--];
   node* curr = new node(val);

   if(s == e)
        return curr;
    
    int pos = search(inorder, s, e, val);
    curr->right = buildTree(postorder, inorder, pos + 1, e);
    curr->left = buildTree(postorder, inorder, s, pos - 1);
    
    return curr;
}

void inorderPrint(node* root) {
    if (root == nullptr)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main(void) {
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    node* root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}
