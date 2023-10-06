#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};


void zigZagTraversal(node* root) {

    if(root == nullptr)
        return;

    stack<node*> currLevel;
    stack<node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty()) {
        node* temp = currLevel.top();
        currLevel.pop();

        if(temp)
            cout << temp->data << ' ';

        if(leftToRight) {
            if(temp->left) {
                nextLevel.push(temp->left);
            }
            if(temp->right) {
                nextLevel.push(temp->right);
            }
        }
        else {
            if(temp->right) {
                nextLevel.push(temp->right);
            }
            if(temp->left) {
                nextLevel.push(temp->left);
            }
        }

        if(currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}


int main(void) {

    ios_base::sync_with_stdio(false);

    node* root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);

    zigZagTraversal(root);
}