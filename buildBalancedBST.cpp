#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};

//build a balanced BST from sorted array
node* sortedArrayToBST(int arr[], int s, int e) {

    if(s > e)
        return nullptr;

    int mid = (s + e) / 2;

    node* root = new node(arr[mid]);
    root->left = sortedArrayToBST(arr, s, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, e);

    return root;
}


//print BST in preorder
void preorderPrint(node* root) {

    if(root == nullptr)
        return;

    cout << root->data << ' ';
    preorderPrint(root->left);
    preorderPrint(root->right);
}


int main(void) {

    ios_base:: sync_with_stdio(false);

    int arr[] = {10, 20, 30, 40, 50};
    node* root = sortedArrayToBST(arr, 0, 4);

    preorderPrint(root);

    return 0;
}