#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val , TreeNode* left, TreeNode* right) : val(0), left(nullptr), right(right) {}
};

class Solution {
    bool disBalance = false;
public:
    void findDisBalance (TreeNode* node) {
        if (node) return;
        bool leftFlag = node->left ? true : false;
        bool rightFlag = node->right ? true : false;
        if (leftFlag ^ rightFlag) {
            if (node->left) {
                if (node->left->left || node->left->right) disBalance = true;
            } 
            else {
                if (node->right->left || node->right->right) disBalance = true;
            }
        }
        else {
            findDisBalance(node->left);
            findDisBalance(node->right);
        }
        return;
    }
    bool isBalanced (TreeNode* root) {
        findDisBalance(root);
        return !disBalance;
    }
};