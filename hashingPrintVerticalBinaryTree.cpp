#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct node {
    int key;
    node* left;
    node* right;
};

node* newNode(int key) {
    node* root = new node;
    root->key = key;
    root->left = root->right = nullptr;
    return root;
}

void getVerticalOrder(node* root, int hdis, map<int, vector<int>>& mp);

int main(void) {
    ios_base::sync_with_stdio(false);

    node* root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->left->right = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);

    map<int, vector<int>> mp;

    int hdis = 0;

    getVerticalOrder(root, hdis, mp);

    map<int, vector<int>>::iterator it;
    for (it = mp.begin(); it != mp.end(); ++it) {
        for (int i = 0; i < (it->second).size(); i++) {
            cout << (it->second)[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void getVerticalOrder(node* root, int hdis, map<int, vector<int>>& mp) {
    if (root == nullptr)
        return;

    mp[hdis].push_back(root->key);

    getVerticalOrder(root->left, hdis - 1, mp);
    getVerticalOrder(root->right, hdis + 1, mp);
}
