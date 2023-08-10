#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val , TreeNode* left, TreeNode* right) : val(0), left(nullptr), right(right) {}
};

class solution {
    bool isBalance = true;
    int depth(TreeNode* node) {
        if (!node) return 0;
        int leftDepth = (node->left) ? depth(node->left) : 0;
        int rightDepth = (node->right) ? depth(node->right) : 0;
        if (abs(leftDepth - rightDepth) > 1) {
            isBalance = false;
        }
        return max(leftDepth, rightDepth) + 1;
    }
};