#include <iostream>
#include <vector>

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
    vector<vector<int>> allPath;
    int target;
public:
    void findPath (TreeNode* node, vector<int> path, int sum) {
        if (!node) return;
        path.push_back(node->val);
        sum += node->val;
        if (!node->left && !node->right) {
            if (sum == target) {
                allPath.push_back(path);
            }
            return;
        }
        if (node->left) findPath(node->left, path, sum);
        if (node->right) findPath(node->right, path, sum);
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path = {};
        target = targetSum;
        findPath(root, path, 0);
        return allPath;
    }
};