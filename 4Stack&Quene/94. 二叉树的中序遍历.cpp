#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> vec;
public:
    void middleLook (TreeNode* root) {
        if(!root) return;
        if(root->left) middleLook(root->left);
        vec.push_back(root->val);
        if(root->right) middleLook(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        middleLook(root);
        return vec;
    }
};

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Expected output: 1 3 2
    for (int val : result) {
        cout << val << " ";
    }

    // Clean up the dynamically allocated nodes
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
