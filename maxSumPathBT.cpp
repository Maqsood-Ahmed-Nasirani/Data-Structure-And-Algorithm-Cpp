#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class node {
public:
    int data;
    node* left, *right;
    node(int val): data(val), left(nullptr), right(nullptr) {} 
};

int maxSumPathUtil(node* root, int &ans) {
    if(root == nullptr)
        return 0;

    int left = maxSumPathUtil(root->left, ans);
    int right = maxSumPathUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), 
                        max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;
}

int maxSumPath(node* root) {
    int ans = INT_MIN;
    maxSumPathUtil(root, ans);

    return ans;
}

int main(void) {

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    cout << maxSumPath(root) << '\n';


    return 0;
}