#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};

bool isIdentical(node* root1, node* root2) {

    if(root1 == nullptr && root2 == nullptr)
        return true;

    if(root1 == nullptr || root2 == nullptr)
        return false;

    bool cond1 = root1->data == root2->data;
    bool cond2 = isIdentical(root1->left, root2->left);
    bool cond3 = isIdentical(root1->right, root2->right);

    if(cond1 && cond2 && cond3)
        return true;
    else    
        return false;
}

int main(void) {

    node* root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);

    node* root2 = new node(2);
    root2->left = new node(1);
    root2->right = new node(3);

    cout << (isIdentical(root1, root2) ? "Both identical\n" : "Not identical\n");

    return 0;
}