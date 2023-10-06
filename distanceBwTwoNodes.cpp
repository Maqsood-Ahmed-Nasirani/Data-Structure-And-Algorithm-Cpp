#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};

node* LCA(node* root, int n1, int n2) {
    if(root == nullptr) 
        return nullptr;
    
    if(root->data == n1 || root->data == n2)    
        return root;
    
    node* left = LCA(root->left, n1, n2);
    node* right = LCA(root->right, n1, n2);

    if(left != nullptr && right != nullptr) {
        return root;
    }
    if(left == nullptr && right == nullptr) {
        return root;
    }

    if(left != nullptr)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
}

int findDist(node* root, int k, int dist) {
    if(root == nullptr)
        return -1;

    if(root->data == k) 
        return dist;

    int left = findDist(root->left, k, dist + 1);
    if(left != -1)
        return left;

    return findDist(root->right, k, dist + 1);
}

int distBtwNodes(node* root, int n1, int n2) {
    node* lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    
    // string name;
    // cout << "Enter name: \n";// << flush; // Use flush to immediately display the prompt
    // cin >> name;
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    cout << distBtwNodes(root, 4, 5) << '\n';

    return 0;
}
