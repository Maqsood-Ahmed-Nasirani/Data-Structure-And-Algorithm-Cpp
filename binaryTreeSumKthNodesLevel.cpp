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

int sumAtK(node* root, int k) {
    if(root == nullptr)
        return -1;
    
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    int level = 0;
    int sum = 0;
    while(!q.empty()) {
        node* nd = q.front();
        q.pop();
        if(nd != nullptr) {
            if(level == k) {
                sum += nd->data;
            }

            if(nd->left) {
                q.push(nd->left);
            }

            if(nd->right) 
                q.push(nd->right);
        }
        else if(!q.empty()) {
            q.push(nullptr);
            level++;
        }
    }
    return sum;
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

    cout << sumAtK(root, 2);
    return 0;
}