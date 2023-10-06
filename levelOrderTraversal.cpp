#include <queue>
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val): data(val), left(nullptr), right(nullptr) {}
};

void printLevelOrder(node* root) {
    if(root == nullptr)
        return;
    
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        node* nd = q.front();
        q.pop();
        if(nd != nullptr) {
            cout << nd->data << " ";
            if(nd->left)
                q.push(nd->left);
            if(nd->right)
                q.push(nd->right);
        }
        else if(!q.empty()) {
            q.push(nullptr);
        }
    }
}

int main(void)
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    printLevelOrder(root);

    return 0;
}