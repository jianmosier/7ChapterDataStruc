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


class Solution {
    bool disBalance = false;

    int depth(TreeNode* node) {
        if (!node) return 0;

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        // 如果左右子树的高度差大于1，或者某个子树已经被标记为不平衡
        if (abs(leftDepth - rightDepth) > 1 || disBalance) {
            disBalance = true;
            return 0;  // 返回值在这里不重要，因为disBalance已经标记为true
        }

        return max(leftDepth, rightDepth) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        depth(root);
        return !disBalance;
    }
};

// 辅助函数，根据vector来构建二叉树
TreeNode* constructTree(const vector<int>& nums, int index = 0) {
    if (index >= nums.size() || nums[index] == -1) return nullptr;

    TreeNode* root = new TreeNode(nums[index]);
    root->left = constructTree(nums, 2 * index + 1);
    root->right = constructTree(nums, 2 * index + 2);

    return root;
}

// 辅助函数，销毁二叉树
void destroyTree(TreeNode* root) {
    if (!root) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Test case 1: [3,9,20,-1,-1,15,7]
    vector<int> testcase1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* tree1 = constructTree(testcase1);
    assert(solution.isBalanced(tree1) == true);
    destroyTree(tree1);

    // Test case 2: [1,2,2,3,3,-1,-1,4,4]
    vector<int> testcase2 = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    TreeNode* tree2 = constructTree(testcase2);
    assert(solution.isBalanced(tree2) == false);
    destroyTree(tree2);

    cout << "All test cases pass." << endl;

    return 0;
}