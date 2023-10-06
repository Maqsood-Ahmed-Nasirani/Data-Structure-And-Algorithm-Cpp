#include <iostream>
#include <vector>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};


vector<node*> constructTrees(int start, int end) {
    vector<node*> trees;

    if(start > end) {
        trees.push_back(nullptr);
        return trees;
    }
    

    for(int i = start; i <= end; ++i) {
        vector<node*> leftSubtrees = constructTrees(start, i - 1);
        vector<node*> rightSubtrees = constructTrees(i + 1, end);

        for(int j = 0; j < leftSubtrees.size(); ++j) {
            node* left = leftSubtrees[j];

            for(int k = 0; k < rightSubtrees.size(); ++k) {
                node* right = rightSubtrees[k];

                node* nd = new node(i);

                nd->left = left;
                nd->right = right;

                trees.push_back(nd);
            }
        }
    }

    return trees;
}


void preorderPrint(node* root) {

    if(root == nullptr)
        return;

    cout << root->data << ' ';
    preorderPrint(root->left);
    preorderPrint(root->right);
}


int catalan(int n) {

    if(n <= 1) 
        return 1;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += catalan(i) * catalan(n - 1 - i);
    }
    return ans;
}

int main(void) {

    ios_base:: sync_with_stdio(false);

    // for(int i = 0; i < 10; i++)
    //     cout << catalan(i) << '\n';

    vector<node*> totalTrees = constructTrees(1, 3);

    for(int i = 0; i < totalTrees.size(); i++) {
        cout << (i + 1) << ": ";
        preorderPrint(totalTrees[i]);
        cout << '\n';
    }

    return 0;
}