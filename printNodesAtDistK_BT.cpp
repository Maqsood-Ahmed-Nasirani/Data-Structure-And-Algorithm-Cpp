#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left, *right;
    node(int val): data(val), left(nullptr), right(nullptr) {} 
};

//case 1
void printSubtreeNodes(node* root, int k)  {
    if(root == nullptr || k < 0)
        return;

    if(k == 0) {
        cout << root->data << ' ';
        return;
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
    
}

//case 2
int printNodesAtK(node* root, node* target, int k) {
    if(root == nullptr)
        return -1;

    if(root == target) {
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtK(root->left, target, k);
    if(dl != -1) {
        if(dl + 1 == k) {
            cout << root->data << ' ';
        } else {
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;

    }

    int dr = printNodesAtK(root->right, target, k);
    if(dr != -1) {
        if(dr + 1 == k) {
            cout << root->data << ' ';
        } else {
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;

    }

    return -1;

}


int main(void) {

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    
    printNodesAtK(root, root->left, 1);

    return 0;
}