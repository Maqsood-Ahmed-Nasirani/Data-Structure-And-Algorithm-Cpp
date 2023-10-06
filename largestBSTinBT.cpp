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


class Info {
    public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(node* root) {

    if(root == nullptr)
        return {0, INT_MIN, INT_MAX, 0, true};

    if(root->left == nullptr && root->right == nullptr) {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data) {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}


int main(void) {

    ios_base::sync_with_stdio(false);

    node* root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout << "Largest BST in BT: " << largestBSTinBT(root).ans << '\n';

    return 0;
}