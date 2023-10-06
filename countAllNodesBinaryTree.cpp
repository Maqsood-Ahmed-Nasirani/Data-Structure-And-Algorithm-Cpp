#include <iostream>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::string;


class node{
    public:
    int data;
    node* left;
    node* right;
  
    node(int val): data(val), left(nullptr), right(nullptr){}

};

int countNodes(node* root) {
    
    if(root == nullptr)
        return 0;
    
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(node* root) {
    if(root == nullptr)
        return 0;


    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int calcHeight(node* root) {

    if(root == nullptr) {
        return 0;
    }

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return ((lHeight > rHeight) ? rHeight: lHeight) + 1;
}

int calcDiameter(node* root) {

    if(root == nullptr)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiamter = calcDiameter(root->right);

    return std::max(currDiameter, std::max(lDiameter, rDiamter));
}

int calcDiameter(node* root, int* height) {

    if(root == nullptr) {
        *height = 0;
        return 0;
    }
    
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left, &lh);
    int rDiameter = calcDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;

    *height = std::max(lh, rh) + 1;

    return std::max(currDiameter, std::max(lDiameter, rDiameter));

}

void sumReplace(node* &root) {
    if(root == nullptr) 
        return;
    
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != nullptr)
        root->data += root->left->data;

    if(root->right != nullptr)  
        root->data += root->right->data;    
}

void preorder(node* root) {
    if(root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    
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

    cout << countNodes(root) << '\n';
    cout << sumNodes(root) << '\n';
    cout << calcHeight(root) << '\n';
    cout << calcDiameter(root) << '\n';
    int height = 0;
    cout << calcDiameter(root, &height) << '\n';

    preorder(root);
    cout << '\n';
    sumReplace(root);
    preorder(root);
    return 0;
}

/*
        1
        /\
      2     3
     /\     /\
    4  5   6  7
*/