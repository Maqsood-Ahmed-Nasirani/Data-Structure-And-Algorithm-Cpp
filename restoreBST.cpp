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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void calcPointers(node* root, node** first, node** mid, node** last, node** prev) {

    if(root == nullptr)
        return;
    
    calcPointers(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data) {

        if(!*first) {
            *first = *prev;
            *mid = root;
        }
        else {
            *last = root;
        }
    }
    *prev = root;

    calcPointers(root->right, first, mid, last, prev); 
}


void restoreBST(node* root) {
    node* first = nullptr, *mid = nullptr, *last = nullptr, *prev = nullptr;

    calcPointers(root, &first, &mid, &last, &prev);

    //case 1
    if(first && last)
        swap(&(first->data), &(last->data));
    else if(first && mid)
        swap(&(first->data), &(mid->data));
}

void inorderPrint(node* root) {

    if(root == nullptr)
        return;

    inorderPrint(root->left);
    cout << root->data << ' ';
    inorderPrint(root->right);
}

int main(void) {

    ios_base::sync_with_stdio(false);

    node* root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);

    inorderPrint(root);
    cout << '\n';

    restoreBST(root);

    inorderPrint(root);
    cout << '\n';

    return 0;
}