#include <iostream>
#include <queue>

using std::cin; using std::cout; using std::endl; using std::string;


class node{
    public:
    int data;
    node* left;
    node* right;
  
    node(int val): data(val), left(nullptr), right(nullptr){}

};

int height(node* root) {

    if(root == nullptr)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return std::max(lh, rh) + 1;
}

bool isBalanced(node* root) {

    if(root == nullptr) {
        return true;
    }

    if(!isBalanced(root->left))
        return false;
    
    if(!isBalanced(root->right))
        return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1) {
        return true;
    }else{
        return false;
    }
}


bool isBalanced(node* root, int* height) {

    if(root == nullptr)
        return true;
    
    int lh = 0, rh = 0;

    if(!isBalanced(root->left, &lh))
        return false;

    if(!isBalanced(root->right, &rh))
        return false;

    *height = std::max(lh, rh) + 1;

    if(abs(lh - rh) <= 1)
        return true;
    else   
        return false;
}

void rightView(node* root) {

    if(root == nullptr)
        return;

    std::queue<node*>  q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        for(std::size_t i = 0; i < n; i++) {
            node* curr = q.front();
            q.pop();

            if(i == n - 1)
                cout << curr->data << " ";

            if(curr->left != nullptr)
                q.push(curr->left);

            if(curr->right != nullptr)
                q.push(curr->right);
        }
    }
}

void leftView(node* root) {

    if(root == nullptr)
        return;

    std::queue<node*>  q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        for(std::size_t i = 1; i <= n; i++) {
            node* curr = q.front();
            q.pop();

            if(i == 1)
                cout << curr->data << " ";

            if(curr->left != nullptr)
                q.push(curr->left);

            if(curr->right != nullptr)
                q.push(curr->right);
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

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->left->left = new node(3);

    cout << isBalanced(root) << '\n';
    cout << isBalanced(root2) << '\n';

    int height = 0;
    cout << isBalanced(root, &height) << '\n';
    cout << isBalanced(root2, &height) << '\n';

    rightView(root);
    cout << '\n';
    rightView(root2);
    cout << '\n';

    leftView(root);
    cout << '\n';
    leftView(root2);
    
    return 0;
}

/*
         1
        / \
      2     3
     / \   / \
    4   5  6  7
*/