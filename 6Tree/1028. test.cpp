#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//定义二叉树的数据结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};

class Solution {
public:
    TreeNode* recoverFromPreOrder(string S) {
        stack<TreeNode*> path;      //使用栈来存储路径节点
        int pos = 0;                //当前处理到字符串的哪个位置
        while (pos < S.size()) {
            int level = 0;          //当前节点的深度（根节点深度为0）
            // 通过连续的 ‘-’计算深度
            while (S[pos] == '-') {
                ++level;
                ++pos;
            }
            // 计算当前节点的值
            int value = 0;
            while (pos < S.size() && isdigit(S[pos])) {
                value = value * 10 + (S[pos] - '0');
                ++pos;
            }
            // 创建当前节点
            TreeNode* node = new TreeNode(value);
            // 如果当前节点的深度等于栈的大小，说明当前节点是前一个节点的左子节点
            if (level == path.size()) {
                if (!path.empty()) {
                    path.top()->left = node;
                }
            }
            else {
                // 如果当前节点不是子节点，则他是某个祖先节点的右子节点
                // 我们需要向上移动，找到这个祖先节点
                while (level != path.size()) {
                    path.pop();
                }
                path.top()->right = node;
            }
            // 将当前节点添加到路径中
            path.push(node);
        }
        // 找到根节点（栈底元素）
        while (path.size() > 1) {
            path.pop();
        }
        return path.top();
    }

};

// 辅助函数，用于比较两棵树是否相等
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;  // 都为空指针
    if (!p || !q) return false;  // 一个为空指针，一个非空
    if (p->val != q->val) return false;  // 值不相等

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// 辅助函数，用于释放树的内存
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;  // 后序遍历位置删除当前节点
}

void testFunction() {
    Solution solution;

    // 定义测试用例
    vector<pair<string, TreeNode*>> testCases = {
        {"1-2--3--4-5--6--7", new TreeNode(1)}  // 根据实际情况构造正确的树
        // ... 可以添加更多测试用例
    };

    // 构造正确的树结构
    // 例如，对于 {"1-2--3--4-5--6--7", new TreeNode(1)}，我们需要手动构造正确的树
    testCases[0].second->left = new TreeNode(2);
    testCases[0].second->right = new TreeNode(5);
    testCases[0].second->left->left = new TreeNode(3);
    testCases[0].second->left->right = new TreeNode(4);
    testCases[0].second->right->left = new TreeNode(6);
    testCases[0].second->right->right = new TreeNode(7);

    // 开始测试
    for (auto& testCase : testCases) {
        TreeNode* recovered = solution.recoverFromPreOrder(testCase.first);
        if (!isSameTree(recovered, testCase.second)) {
            std::cout << "Test failed for case: " << testCase.first << std::endl;
        } else {
            std::cout << "Test passed for case: " << testCase.first << std::endl;
        }

        // 释放内存
        deleteTree(recovered);
        deleteTree(testCase.second);
    }
}

int main() {
    testFunction();
    return 0;
}

