#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left, *right;
    node(int val): data(val), left(nullptr), right(nullptr) {} 
};

bool getPath(node* root, int key, vector<int> &path) {

    if(root == nullptr)
        return false;

    path.push_back(root->data);
        
    if(root->data == key)
        return true;

    if(getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;

    path.pop_back();
    return false;

}


int LCA(node* root, int n1, int n2) {
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)) 
        return -1;

    int pc;

    for(pc = 0; pc < path1.size() && path2.size(); pc++) {
        if(path1[pc] != path2[pc])
            break;
    }

    return path1[pc - 1];
}


node* LCA2(node* root, int n1, int n2) {

    if(root == nullptr)
        return nullptr;
    
    if(root->data == n1 || root->data == n2)
        return root;

    node* leftLCA = LCA2(root->left, n2, n1);
    node* rightLCA = LCA2(root->right, n2, n1);

    if(leftLCA && rightLCA)
        return root;

    if(leftLCA != nullptr)
        return leftLCA;
    
    return rightLCA;
}

int main(void) {

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);

    int n1 = 7, n2 = 6;
    int lca = LCA(root, n1, n2);


    if(lca != -1)
        cout << "LCA: " << lca << '\n';
    else 
        cout << "Lca doesn't exist\n";

    node* lca2 = LCA2(root, n1, n2);
    
    if(lca2 != nullptr)
        cout << "LCA: " << lca2->data<< '\n';
    else 
        cout << "Lca doesn't exist\n";

    return 0;
}