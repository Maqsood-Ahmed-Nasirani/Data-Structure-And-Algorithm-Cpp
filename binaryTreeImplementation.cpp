#include <iostream>

using std::cin; using std::cout; using std::endl; using std::string; using std::max;


class node{
    public:
    int data;
    node* left;
    node* right;
  
    node(int val): data(val), left(nullptr), right(nullptr){}

};

void pre_order(node* root){
    if(root == nullptr)
        return;

    cout << root->data << " ";

    pre_order(root->left);
    pre_order(root->right);
}

void in_order(node* root){
    if(root == nullptr)
        return;

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void post_order(node* root){
    if(root == nullptr)
        return;
    
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
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

    cout << "Pre_order Traversal:\n";
    pre_order(root);
    cout << "\nIn_order Traversal:\n";
    in_order(root);
    cout << "\nPost_order Traversal:\n";
    post_order(root);

    return 0;
}

/*
        1
        /\
      2     3
     /\     /\
    4  5   6  7
*/