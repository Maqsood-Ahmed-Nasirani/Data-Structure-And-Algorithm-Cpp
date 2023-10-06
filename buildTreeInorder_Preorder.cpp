#include <iostream>

using std::cin; using std::cout; using std::endl; using std::string;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int search(int inorder[], int s, int e, int curr) {
    for (int i = s; i <= e; i++) {
        if (inorder[i] == curr) {
            return i;
        }
    }
    return -1;
}

node* buildTree(int preorder[], int inorder[], int s, int e) {
    static int idx = 0;

    if (s > e) {
        return nullptr;
    }

    int curr = preorder[idx++];
    node* root = new node(curr);

    if (s == e) {
        return root;
    }

    int pos = search(inorder, s, e, curr);
    root->left = buildTree(preorder, inorder, s, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, e);

    return root;
}

void inorderPrint(node* root) {
    if (root == nullptr)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main(void) {
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}
