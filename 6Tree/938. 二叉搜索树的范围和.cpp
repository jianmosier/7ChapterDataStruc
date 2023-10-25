#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
}; 

class Solution {
public:
    int findSum (TreeNode* node, int low, int high) {
        int sum = 0;
        if(node) {
            if (node->val <= high && node->val >= low) {
                sum += node->val;
            }
            sum += findSum(node->left, low, high) + findSum(node->right, low, high);
            return sum;
        }
        else return 0;
    }

};